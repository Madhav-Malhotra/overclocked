// =============================================================================
// Module:      functional_unit_status
// Description: Functional Unit Status Table for the scoreboard. One row per FU
//              slot (row index = FU id - 1; FU id 0 means NONE). A row is
//              reserved at dispatch and released at writeback. It holds the
//              instruction PC, source register numbers, pending producer tags,
//              captured operand values, and an `issued` flag.
//
//              Issue (current form; plan.md Phase 2 / task 2.4 redefines it):
//                cycle N   : combinational select of the first ready row
//                            (reserved, not issued, FU not busy, no tags)
//                edge  N   : iss_row_index / iss_fu_id / iss_instr_found
//                            registered; row marked issued
//                cycle N+1 : iss_rs1/iss_rs2 (from iss_row_index) drive the
//                            register file read address
//                edge  N+1 : register file registers the read data
//                edge  N+2 : read data captured into the row (rf_capture_*)
//                            unless the value was already forwarded from a
//                            writeback
// =============================================================================
module functional_unit_status #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 1,
    parameter NUM_FU = NUM_ALU + NUM_MULTICYCLE_MULT + 2*NUM_LOAD_STORE + 1, // + 1 for branch_comparator
    parameter FUW = $clog2(NUM_FU + 1) // + 1 for None
)(
    input clock,
    input reset,

    // Check for WAW in dispatch
    input [FUW-1:0] ds_fu_type,
    output reg [FUW-1:0] ds_assigned_fu_id,

    // Populate row in dispatch
    input ds_en,
    input [FUW-1:0] ds_fu_id, // actual functional unit id
    input [DATAW-1:0] ds_pc,
    input [ADDRW-1:0] ds_rs1,
    input [ADDRW-1:0] ds_rs2,
    input [ADDRW-1:0] ds_rd,
    input [FUW-1:0] ds_rs1_tag,
    input [FUW-1:0] ds_rs2_tag,

    // Locate ready-to-issue row in IS, copy over values from regfile and update instr_status
    input  iss_en,                        // pd.v allows a row to be issued this cycle
    output reg [FUW-1:0]   iss_fu_id,     // FU id of the row issued at the last edge (NONE if none)
    output     [DATAW-1:0] iss_pc,        // PC of that row (key into instr_status)
    output     [ADDRW-1:0] iss_rs1,       // drive register_file read addresses with these
    output     [ADDRW-1:0] iss_rs2,
    input [DATAW-1:0] iss_rs1_data,       // registered read data from the regfile
    input [DATAW-1:0] iss_rs2_data,
    output                 issued,        // row at iss_row_index has issued


    input wb_en,
    input [FUW-1:0] wb_tag_clear,
    input [DATAW-1:0] wb_data,

    input [NUM_FU-1:0] busy,   // connect to the FUs to get their real-time statuses (1 = FU in use)
    output reg iss_tag_found,  // some otherwise-ready row is waiting on a producer tag (RAW)
    output reg iss_instr_found // pulse: a row issued at the last edge; iss_pc/iss_rs1/iss_rs2/iss_fu_id are valid
);

// Declare reg arrays to hold the statuses for each row/functional unit
reg [DATAW-1:0] pc_arr [NUM_FU-1:0];
reg [NUM_FU-1:0] busy_arr;     // row reserved (dispatch -> writeback)
reg [ADDRW-1:0] rs1_arr [NUM_FU-1:0];
reg [ADDRW-1:0] rs2_arr [NUM_FU-1:0];

reg [DATAW-1:0] rs1_data_arr [NUM_FU-1:0];
reg [DATAW-1:0] rs2_data_arr [NUM_FU-1:0];

reg [FUW-1:0] rs1_tag_arr [NUM_FU-1:0];
reg [FUW-1:0] rs2_tag_arr [NUM_FU-1:0];

reg [NUM_FU-1:0] issued_arr;   // row has issued (read its operands)
reg [NUM_FU-1:0] rs1_fwd_arr;  // rs1 value was captured from a WB broadcast (else read the RF)
reg [NUM_FU-1:0] rs2_fwd_arr;

// Row indexes
wire [FUW-1:0] ds_row_index = ds_fu_id - 1; // since 0 is N/A for the fu_id
wire [FUW-1:0] wb_row_index = wb_tag_clear - 1;

reg [FUW-1:0] iss_row_index;   // row issued at the last edge (drives iss_pc/iss_rs1/iss_rs2)

// Register-file read capture: the RF registers data one edge after iss_rs1/iss_rs2 are driven
reg           rf_capture_valid; // the RF read data arriving this cycle belongs to an issued row
reg [FUW-1:0] rf_capture_row;   // which row that RF read data is for

/* DS checks for structurual hazards */
// available FU types
localparam NONE = 0;
localparam BRANCH = 1;
localparam MCM = 2;
localparam LOAD = 3;
localparam STORE = 4;
localparam ALU = 5;
localparam ALU_2 = 6; // id for second ALU

// Output the assigned functional_unit_id for the instruction to dispatch (a row will then be populated for it)
always @(*) begin
    if(reset) ds_assigned_fu_id = 0;
    else begin
        case(ds_fu_type)
            BRANCH: ds_assigned_fu_id = (busy_arr[BRANCH - 1] == 0) ? BRANCH : 0;
            MCM: ds_assigned_fu_id = (busy_arr[MCM - 1] == 0) ? MCM : 0;
            LOAD: ds_assigned_fu_id = (busy_arr[LOAD - 1] == 0) ? LOAD : 0;
            STORE: ds_assigned_fu_id = (busy_arr[STORE - 1] == 0) ? STORE : 0;
            ALU: ds_assigned_fu_id = (busy_arr[ALU - 1] == 0) ? ALU :
                                     (busy_arr[ALU_2 - 1] == 0) ? ALU_2  : 0;
            default: ds_assigned_fu_id = 0;
        endcase
    end
end


integer i;

// ====================
// ISSUE SELECT (combinational)
// ====================
// First row (lowest index) that is reserved, not yet issued, whose FU is not
// busy, and which has no pending producer tags. Fixed row priority for now;
// plan.md task 2.4a replaces this with smallest-PC selection.
reg           ready_row_found;    // at least one row can issue this cycle
reg [FUW-1:0] ready_row_idx;      // lowest-index row that can issue
reg           row_waiting_on_tag; // some row would be ready except for a pending producer tag (RAW)

always @(*) begin
    ready_row_found    = 1'b0;
    ready_row_idx      = {FUW{1'b0}};
    row_waiting_on_tag = 1'b0;
    for (i = NUM_FU - 1; i >= 0; i = i - 1) begin // highest to lowest: the lowest ready row wins
        if (busy_arr[i] && !issued_arr[i] && !busy[i]) begin
            if (rs1_tag_arr[i] == NONE && rs2_tag_arr[i] == NONE) begin
                ready_row_found = 1'b1;
                ready_row_idx   = i[FUW-1:0];
            end else begin
                row_waiting_on_tag = 1'b1;
            end
        end
    end
end

wire issue_now = iss_en && ready_row_found; // a row issues at this clock edge

// ====================
// TABLE UPDATES (non-blocking only)
// ====================
// Row stays busy from dispatch until writeback (cleared in the wb_en block below)
always @(posedge clock) begin
    if (reset) begin
        busy_arr <= 0; // just set everything to not busy
        issued_arr <= 0;
        rs1_fwd_arr <= 0;
        rs2_fwd_arr <= 0;
        iss_instr_found <= 0;
        iss_fu_id <= NONE;
        iss_row_index <= 0;
        iss_tag_found <= 0;
        rf_capture_valid <= 0;
        rf_capture_row <= 0;
        for(i = 0; i < NUM_FU; i = i + 1) begin
            rs1_tag_arr[i] <= 0;
            rs2_tag_arr[i] <= 0;
        end
    end else begin
        // In writeback stage --> clear the tags for any FUs waiting on it, and free the writing row
        if(wb_en) begin
            for(i = 0; i < NUM_FU; i = i + 1) begin
                if(rs1_tag_arr[i] == wb_tag_clear) begin
                    rs1_tag_arr[i] <= 0;
                    rs1_data_arr[i] <= wb_data;
                    rs1_fwd_arr[i] <= 1;
                end

                if(rs2_tag_arr[i] == wb_tag_clear) begin
                    rs2_tag_arr[i] <= 0;
                    rs2_data_arr[i] <= wb_data;
                    rs2_fwd_arr[i] <= 1;
                end
            end
            if(wb_tag_clear != NONE) busy_arr[wb_row_index] <= 0;  // tag 0 would index row -1
        end

        // In issue stage: register the selected row (outputs valid next cycle)
        iss_instr_found <= issue_now;
        iss_fu_id       <= issue_now ? ready_row_idx + 1'b1 : NONE; // fu_id = row index + 1 (0 is NONE)
        iss_tag_found   <= iss_en && row_waiting_on_tag;
        if (issue_now) begin
            iss_row_index             <= ready_row_idx;
            issued_arr[ready_row_idx] <= 1'b1;
        end

        // Operand capture: iss_rs1/iss_rs2 were driven last cycle (iss_instr_found),
        // so the RF data registered at that edge belongs to rf_capture_row.
        rf_capture_valid <= iss_instr_found;
        rf_capture_row   <= iss_row_index;
        if (rf_capture_valid) begin
            if (!rs1_fwd_arr[rf_capture_row]) rs1_data_arr[rf_capture_row] <= iss_rs1_data;
            if (!rs2_fwd_arr[rf_capture_row]) rs2_data_arr[rf_capture_row] <= iss_rs2_data;
        end

        // In dispatch stage --> write new row (if not busy)
        if(ds_en && !busy_arr[ds_row_index]) begin
            pc_arr[ds_row_index] <= ds_pc;
            busy_arr[ds_row_index] <= 1;
            rs1_arr[ds_row_index] <= ds_rs1;
            rs2_arr[ds_row_index] <= ds_rs2;
            rs1_tag_arr[ds_row_index] <= ds_rs1_tag;
            rs2_tag_arr[ds_row_index] <= ds_rs2_tag;
            issued_arr[ds_row_index] <= 0;
            rs1_fwd_arr[ds_row_index] <= 0;   // no stale forwarded value from the row's previous instruction
            rs2_fwd_arr[ds_row_index] <= 0;
        end
    end
end

// Values of the row issued at the last edge (valid while iss_instr_found is high).
// The RF is read with iss_rs1/iss_rs2; its data is captured into the row one edge later.
assign iss_pc           = pc_arr[iss_row_index]; // instr_status
assign iss_rs1          = rs1_arr[iss_row_index]; // getting data from regfile
assign iss_rs2          = rs2_arr[iss_row_index]; // getting data from regfile
assign issued           = issued_arr[iss_row_index];

endmodule
