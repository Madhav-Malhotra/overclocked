// =============================================================================
// Module:      functional_unit_status
// Description: Functional Unit Status Table for the scoreboard. One row per FU
//              slot (row index = FU id - 1; FU id 0 means NONE). A row is
//              reserved at dispatch and released at writeback. It holds the
//              instruction identity (ist_idx), PC, source/destination register
//              numbers, pending producer tags, forwarded operand values and an
//              `issued` flag.
//
//              Issue pipeline (plan.md task 2.4), one issue per cycle:
//                cycle N   : select (comb) - the smallest-PC row that is
//                            reserved, not issued, its FU ready, has no
//                            pending tags and is not held back by memory
//                            order (D6, below) (min_pc_select, D2). Its rs1/rs2
//                            numbers drive the register-file read addresses.
//                edge  N   : RF latches the read data; the row is marked
//                            issued; iss_valid/iss_row_idx registered.
//                cycle N+1 : issue - the iss_* outputs carry the row's
//                            fu_id, ist_idx, pc, rd, writes_rd, op1 and op2 to
//                            its FU. Each operand is the value forwarded from
//                            a writeback broadcast if one was captured, else
//                            the RF read data.
//              Back-to-back issue works: the issue of N overlaps the select
//              of N+1.
//
//              No RF write->read bypass is needed: a writeback in cycle N can
//              not be the producer of a source of the row selected in N (that
//              row would still hold the producer's tag), and a younger writer
//              of a source register (WAR) is held at WB until the reader has
//              issued (plan.md D4), so the RF read at edge N is never stale.
//
// Inputs:      ds_*          - dispatch: FU class (ds_fu_type) and the fields
//                              written into row ds_fu_id-1 when ds_en is high
//              fu_ready      - per-FU ready: 1 = the FU can accept an instruction
//              iss_rf_rs*_data - RF read data (registered, for the row selected
//                              in the previous cycle)
//              wb_en, wb_tag, wb_data - writeback broadcast: wake up waiting
//                              operands and release row wb_tag-1
// Outputs:     ds_assigned_fu_id - free FU slot for the dispatching class (NONE if none)
//              iss_sel_valid, iss_sel_ist_idx - row selected this cycle (for instr_status)
//              iss_rf_rs1, iss_rf_rs2         - RF read addresses for the selected row
//              iss_*                   - the row issuing to its FU this cycle
// =============================================================================
module functional_unit_status #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 1,
    parameter NUM_FU = NUM_ALU + NUM_MULTICYCLE_MULT + 2*NUM_LOAD_STORE + 1, // + 1 for branch_comparator
    parameter FUW = $clog2(NUM_FU + 1), // + 1 for None
    parameter IST_W = 3                 // width of an instr_status row index (ist_idx)
)(
    input clock,
    input reset,

    // ====================
    // Dispatch
    // ====================
    input  [FUW-1:0]   ds_fu_type,          // decoded FU class (ALU means either ALU slot)
    output reg [FUW-1:0] ds_assigned_fu_id, // free slot for that class, NONE if all reserved
    input              ds_en,
    input  [FUW-1:0]   ds_fu_id,            // slot being written (= ds_assigned_fu_id)
    input  [DATAW-1:0] ds_pc,
    input  [IST_W-1:0] ds_ist_idx,
    input  [ADDRW-1:0] ds_rs1,
    input  [ADDRW-1:0] ds_rs2,
    input              ds_uses_rs1,
    input              ds_uses_rs2,
    input  [ADDRW-1:0] ds_rd,
    input              ds_writes_rd,
    input  [FUW-1:0]   ds_rs1_tag,          // producer FU of rs1 (NONE = read the RF)
    input  [FUW-1:0]   ds_rs2_tag,

    // ====================
    // Issue select (cycle N)
    // ====================
    input  [NUM_FU-1:0] fu_ready,           // ready/valid: 1 = FU (id = bit + 1) can accept an instruction
    output              iss_sel_valid,      // a row is selected this cycle
    output [IST_W-1:0]  iss_sel_ist_idx,    // its instr_status row
    output [ADDRW-1:0]  iss_rf_rs1,         // register-file read addresses for the selected row
    output [ADDRW-1:0]  iss_rf_rs2,

    // ====================
    // Issue (cycle N+1)
    // ====================
    input  [DATAW-1:0]  iss_rf_rs1_data,    // registered RF read data (addresses from cycle N)
    input  [DATAW-1:0]  iss_rf_rs2_data,
    output reg          iss_valid,          // ready/valid: the iss_* outputs hold an instruction for FU iss_fu_id
                                            // (that FU's fu_ready was checked when the row was selected)
    output [FUW-1:0]    iss_fu_id,          // FU the issuing instruction executes on
    output [IST_W-1:0]  iss_ist_idx,        // its instr_status row (instruction identity, D1)
    output [DATAW-1:0]  iss_pc,             // its PC
    output [ADDRW-1:0]  iss_rd,             // its destination register number
    output              iss_writes_rd,      // it writes rd at writeback
    output [DATAW-1:0]  iss_op1,            // rs1 value (forwarded or read from the RF)
    output [DATAW-1:0]  iss_op2,            // rs2 value (forwarded or read from the RF)

    // ====================
    // Writeback broadcast
    // ====================
    input              wb_en,               // an instruction writes back this cycle
    input  [FUW-1:0]   wb_tag,              // FU id writing back (never NONE when wb_en)
    input  [DATAW-1:0] wb_data              // its result, broadcast to waiting operands
);

// FU ids (same values in decoder.v and pd.v; 0 = NONE = no FU / no pending producer)
localparam NONE   = 0;
localparam BRANCH = 1;
localparam MCM    = 2;
localparam LOAD   = 3;
localparam STORE  = 4;
localparam ALU    = 5;
localparam ALU_2  = 6;  // second ALU, used when ALU is reserved

// ====================
// ROW STATE
// ====================
reg [NUM_FU-1:0] busy_arr;     // row reserved (dispatch -> writeback)
reg [NUM_FU-1:0] issued_arr;   // row has been selected; its operands were read at that edge
reg [IST_W-1:0] ist_idx_arr [NUM_FU-1:0];  // instr_status row of the instruction (D1 identity)
reg [DATAW-1:0] pc_arr [NUM_FU-1:0];       // instruction PC (issue/WB priority, D2)

reg [ADDRW-1:0] rs1_arr [NUM_FU-1:0];      // source register 1 number (RF read address at issue)
reg [ADDRW-1:0] rs2_arr [NUM_FU-1:0];      // source register 2 number
reg [NUM_FU-1:0] uses_rs1_arr;             // rs1 is a real source (for the WAR check, D4)
reg [NUM_FU-1:0] uses_rs2_arr;             // rs2 is a real source (for the WAR check, D4)
reg [ADDRW-1:0] rd_arr [NUM_FU-1:0];       // destination register number (WB and WAR check)
reg [NUM_FU-1:0] writes_rd_arr;            // instruction writes rd at WB

reg [FUW-1:0] rs1_tag_arr [NUM_FU-1:0];    // pending producer FU of rs1 (NONE = ready)
reg [FUW-1:0] rs2_tag_arr [NUM_FU-1:0];    // pending producer FU of rs2 (NONE = ready)

reg [NUM_FU-1:0] rs1_fwd_arr;              // rs1 value was captured from a WB broadcast (else read the RF)
reg [NUM_FU-1:0] rs2_fwd_arr;              // rs2 value was captured from a WB broadcast
reg [DATAW-1:0] rs1_fwd_data_arr [NUM_FU-1:0];  // captured broadcast value for rs1 (valid when rs1_fwd_arr)
reg [DATAW-1:0] rs2_fwd_data_arr [NUM_FU-1:0];  // captured broadcast value for rs2 (valid when rs2_fwd_arr)

// Row indexes (row = FU id - 1, since FU id 0 is NONE)
wire [FUW-1:0] ds_row_index = ds_fu_id - 1; // row the dispatching instruction is written to
wire [FUW-1:0] wb_row_index = wb_tag - 1;   // row released by the writeback

reg [FUW-1:0] iss_row_idx;        // row selected at the last edge; it issues this cycle (valid with iss_valid)

integer i;

// ====================
// DISPATCH: FU SLOT ASSIGNMENT
// ====================
// Free slot for the dispatching instruction's class; the first ALU is preferred.
always @(*) begin
    case(ds_fu_type)
        BRANCH: ds_assigned_fu_id = (busy_arr[BRANCH - 1] == 0) ? BRANCH : NONE;
        MCM:    ds_assigned_fu_id = (busy_arr[MCM - 1] == 0) ? MCM : NONE;
        LOAD:   ds_assigned_fu_id = (busy_arr[LOAD - 1] == 0) ? LOAD : NONE;
        STORE:  ds_assigned_fu_id = (busy_arr[STORE - 1] == 0) ? STORE : NONE;
        ALU:    ds_assigned_fu_id = (busy_arr[ALU - 1] == 0) ? ALU :
                                    (busy_arr[ALU_2 - 1] == 0) ? ALU_2 : NONE;
        default: ds_assigned_fu_id = NONE;
    endcase
end

// ====================
// ISSUE SELECT (combinational)
// ====================
// A row can issue when it is reserved, not yet issued, its FU is ready,
// neither source waits on a producer tag, and memory order allows it (D6).
// Among those, the smallest PC wins.
//
// Memory order (plan.md D6): stores write memory in Execute, so a load may not
// issue while an older (smaller-PC) store is reserved and has not issued
// (memory RAW), and a store may not issue while an older load is reserved and
// has not issued (memory WAR). `issued_arr` is the "executed" bit: the load and
// store FUs have the same timing (two EX cycles: address, then memory), so a
// row selected in cycle N accesses memory in N+2, while the younger access
// (selected in N+1 at the earliest) reaches memory in N+3 - after the older
// one.
// Store -> store order is automatic (one store FU, reserved until writeback).
reg [NUM_FU-1:0]       row_can_issue; // row i can issue this cycle
wire [NUM_FU*DATAW-1:0] row_pc_flat; // pc_arr flattened for min_pc_select
wire [FUW-1:0]          issue_sel_row; // row selected for issue this cycle (valid with iss_sel_valid)

wire store_older_than_load = pc_arr[STORE-1] < pc_arr[LOAD-1];  // the reserved store precedes the reserved load (D2: PC order)
wire load_waits_for_store  = busy_arr[STORE-1] && !issued_arr[STORE-1] && store_older_than_load;   // memory RAW
wire store_waits_for_load  = busy_arr[LOAD-1]  && !issued_arr[LOAD-1]  && !store_older_than_load;  // memory WAR

always @(*) begin
    for (i = 0; i < NUM_FU; i = i + 1) begin
        row_can_issue[i] = busy_arr[i] && !issued_arr[i] && fu_ready[i] &&
                           rs1_tag_arr[i] == NONE && rs2_tag_arr[i] == NONE;
    end
    if (load_waits_for_store) row_can_issue[LOAD-1]  = 1'b0;
    if (store_waits_for_load) row_can_issue[STORE-1] = 1'b0;
end

genvar g;
generate
    for (g = 0; g < NUM_FU; g = g + 1) begin : flatten_pc
        assign row_pc_flat[g*DATAW +: DATAW] = pc_arr[g];
    end
endgenerate

min_pc_select #(
    .N(NUM_FU),
    .DATAW(DATAW),
    .IDXW(FUW)
) issue_select (
    .valid(row_can_issue),
    .pc(row_pc_flat),
    .min_pc_valid(iss_sel_valid),
    .min_pc_idx(issue_sel_row),
    .min_pc_onehot()
);

assign iss_sel_ist_idx = ist_idx_arr[issue_sel_row];
assign iss_rf_rs1      = rs1_arr[issue_sel_row];
assign iss_rf_rs2      = rs2_arr[issue_sel_row];

// ====================
// TABLE UPDATES (non-blocking only)
// ====================
// Order matters only for a row that is both broadcast to and dispatched into in
// one cycle (a free row with a stale tag): the dispatch write comes last and wins.
always @(posedge clock) begin
    if (reset) begin
        busy_arr <= 0; // just set everything to not busy
        issued_arr <= 0;
        rs1_fwd_arr <= 0;
        rs2_fwd_arr <= 0;
        iss_valid <= 0;
        iss_row_idx <= 0;
        for(i = 0; i < NUM_FU; i = i + 1) begin
            rs1_tag_arr[i] <= NONE;
            rs2_tag_arr[i] <= NONE;
        end
    end else begin
        // Writeback: wake up operands waiting on this producer, release its row
        if(wb_en) begin
            for(i = 0; i < NUM_FU; i = i + 1) begin
                if(rs1_tag_arr[i] == wb_tag) begin
                    rs1_tag_arr[i] <= NONE;
                    rs1_fwd_data_arr[i] <= wb_data;
                    rs1_fwd_arr[i] <= 1;
                end

                if(rs2_tag_arr[i] == wb_tag) begin
                    rs2_tag_arr[i] <= NONE;
                    rs2_fwd_data_arr[i] <= wb_data;
                    rs2_fwd_arr[i] <= 1;
                end
            end
            busy_arr[wb_row_index] <= 0;
        end

        // Issue select -> issue next cycle
        iss_valid    <= iss_sel_valid;
        iss_row_idx       <= issue_sel_row;
        if (iss_sel_valid) issued_arr[issue_sel_row] <= 1'b1;

        // Dispatch: write the new row
        if (ds_en) begin
            busy_arr[ds_row_index] <= 1;
            issued_arr[ds_row_index] <= 0;
            ist_idx_arr[ds_row_index] <= ds_ist_idx;
            pc_arr[ds_row_index] <= ds_pc;
            rs1_arr[ds_row_index] <= ds_rs1;
            rs2_arr[ds_row_index] <= ds_rs2;
            uses_rs1_arr[ds_row_index] <= ds_uses_rs1;
            uses_rs2_arr[ds_row_index] <= ds_uses_rs2;
            rd_arr[ds_row_index] <= ds_rd;
            writes_rd_arr[ds_row_index] <= ds_writes_rd;
            rs1_tag_arr[ds_row_index] <= ds_rs1_tag;
            rs2_tag_arr[ds_row_index] <= ds_rs2_tag;
            rs1_fwd_arr[ds_row_index] <= 0;   // no stale forwarded value from the row's previous instruction
            rs2_fwd_arr[ds_row_index] <= 0;
        end
    end
end

// ====================
// ISSUE OUTPUTS (cycle N+1)
// ====================
assign iss_fu_id     = iss_row_idx + 1'b1;   // fu_id = row index + 1 (0 is NONE)
assign iss_ist_idx   = ist_idx_arr[iss_row_idx];
assign iss_pc        = pc_arr[iss_row_idx];
assign iss_rd        = rd_arr[iss_row_idx];
assign iss_writes_rd = writes_rd_arr[iss_row_idx];
assign iss_op1       = rs1_fwd_arr[iss_row_idx] ? rs1_fwd_data_arr[iss_row_idx] : iss_rf_rs1_data;
assign iss_op2       = rs2_fwd_arr[iss_row_idx] ? rs2_fwd_data_arr[iss_row_idx] : iss_rf_rs2_data;

endmodule
