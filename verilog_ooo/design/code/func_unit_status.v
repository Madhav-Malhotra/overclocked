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
    input  iss_en,               // iss = issue: pd.v allows a row to be issued this cycle (no stall required)
    // input [FUW-1:0] iss_fu_id, // actual functional unit id
    // output reg [FUW-1:0]   iss_fu_id,     // functional unit id of the issuing row (valid when iss_instr_found)
    output     [DATAW-1:0] iss_pc,        // PC of the issuing instruction (key into instr_status)
    output     [ADDRW-1:0] iss_rs1,       // drive register_file read addresses with these
    output     [ADDRW-1:0] iss_rs2,
    input [DATAW-1:0] iss_rs1_data,       // get values from regfile
    input [DATAW-1:0] iss_rs2_data,
    output                 issued,   // instr has been/is ready to be issued
    

    input wb_en,
    input [FUW-1:0] wb_tag_clear,
    input [DATAW-1:0] wb_data,

    input [NUM_FU-1:0] busy,   // connect to the FUs to get their real-time statuses (1 = FU in use)
    output reg iss_tag_found,  // RAW hazard found, cannot issue
    output reg iss_instr_found // found an instruction to issue in IS, the pc, rs1 and rs2 values are valid 
                               // (for getting data from regfile and updating instr_status table)
    // output w_complete
    // output busy_out,
    
);

// Declare reg arrays to hold the statuses for each row/functional unit
reg [DATAW-1:0] pc_arr [NUM_FU-1:0];
reg [NUM_FU-1:0] busy_arr;
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

reg [FUW-1:0] iss_row_index; // used for IS row lookup

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
reg done_is;


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

        // In issue stage 
            // Find the next instruction to issue: the row holds a dispatched instruction (busy_arr == 1)
            // that has not issued yet, its FU is not in use (busy == 0), and it has no tags
        done_is = 1'b0;
        iss_instr_found <= 0;  // iss_* are registered: they describe the row found last cycle
        iss_fu_id <= NONE;
        iss_tag_found <= 0;

        if(iss_en) begin 
            for(i = 0; i < NUM_FU; i = i + 1) begin 
                if(busy_arr[i] && !issued_arr[i] && !busy[i] && !done_is) begin // found potential candidate
                    // check for RAW
                    if(rs1_tag_arr[i] == 0 && rs2_tag_arr[i] == 0) begin // if no RAW, initiate a read from the reg file
                        // the reg file data arrives the cycle after iss_rs1/iss_rs2 are driven,
                        // so it is muxed in pd.v rather than copied into rs*_data_arr here
                        iss_row_index = i[FUW-1:0]; // iss_pc/iss_rs1/iss_rs2 are read from this row (assigns below)
                        iss_fu_id = i[FUW-1:0] + 1; // fu_id = row index + 1 (0 is NONE)
                        iss_instr_found = 1; // mark it as a valid issue (for updating instr_status)
                        issued_arr[i] = 1;
                        done_is = 1'b1;
                    end else begin
                        iss_tag_found = 1; // this candidate is waiting on a producer (RAW)
                    end
                end  
            end 

            // these can be non-blocking since its the last part of IS
            if(issued[iss_row_index]) begin 
                rs1_data_arr[iss_row_index] <= rs1_fwd_arr[iss_row_index] ? rs1_data_arr[iss_row_index] : iss_rs1_data;
                rs2_data_arr[iss_row_index] <= rs2_fwd_arr[iss_row_index] ? rs2_data_arr[iss_row_index] : iss_rs2_data;
            end
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
        end
    end
end

// In issue stage --> values of the found row (valid while iss_instr_found is high).
// The RF is read with iss_rs1/iss_rs2, so its data (and the operand mux in pd.v) is ready next cycle.
assign iss_pc           = pc_arr[iss_row_index]; // instr_status
assign iss_rs1          = rs1_arr[iss_row_index]; // getting data from regfile
assign iss_rs2          = rs2_arr[iss_row_index]; // getting data from regfile
// assign iss_rs1_fwd      = rs1_fwd_arr[iss_row_index];
// assign iss_rs2_fwd      = rs2_fwd_arr[iss_row_index];
// assign iss_rs1_fwd_data = rs1_data_arr[iss_row_index];
// assign iss_rs2_fwd_data = rs2_data_arr[iss_row_index];
assign issued           = issued_arr[iss_row_index]; // issue is valid (we found an instruction to issue!)




endmodule
