// =============================================================================
// Module:      reg_status_table
// Description: Table with 32 entries, used to keep track of which FU is generating which output. Basically a hash table in hardware. 
// Inputs:      clock        - clock
//              ds_write_enable - enables write to addr_rd on rising edge
//              ds_reg_id_in    - input used to address the table
//              ds_fu_id_in     - written to table at address ds_reg_id_in
// Outputs:     ds_fu_id_out    - read value of table at address ds_reg_id_in (registered)
// =============================================================================

module reg_status_table #(
    parameter DATAW = 32,
    parameter ADDRW  =  $clog2(DATAW),
    parameter NUM_REGS  =  32,

    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 2,
    parameter FUW = $clog2(NUM_ALU + NUM_MULTICYCLE_MULT + NUM_LOAD_STORE + 1 + 1) // + 1 for branch_comparator + 1 for N/A
)(
    input clock, 
    input reset,
    input [ADDRW-1:0] ds_check_rd, // check for WAW in dispatch
    input [ADDRW-1:0] ds_check_rs1, // DS get the tags (if applicable)
    input [ADDRW-1:0] ds_check_rs2, // DS get the tags (if applicable)


    input ds_write_enable,         // used in Dispatch stage
    input [ADDRW-1:0] ds_reg_id_in,
    input [FUW-1:0] ds_fu_id_in,
    input wb_clear_enable,         // used in Writeback stage
    input [ADDRW-1:0] wb_clear_id,

    output [FUW-1:0] ds_fu_id_out,
    output [FUW-1:0] ds_fu_id_out_rs1,
    output [FUW-1:0] ds_fu_id_out_rs2


);

// (* ram_style = "block" *) reg [FUW-1:0] regs [0:NUM_REGS-1];
reg [FUW-1:0] regs [0:NUM_REGS-1];
integer i;

initial begin
    for (i = 0; i < NUM_REGS; i = i + 1) begin
        regs[i] = 0; // <-- hardocded functional id, 0 means empty
    end
end

localparam CLEAR = 0;

// ====================
// READ/WRITE LOGIC
// ====================
always @(posedge clock) begin
    if (reset) begin
        for (i = 0; i < NUM_REGS; i = i + 1) begin
            regs[i] <= CLEAR;
        end
    end else begin
        if (wb_clear_enable) regs[wb_clear_id] <= CLEAR;

        if (ds_write_enable) regs[ds_reg_id_in] <= ds_fu_id_in; // if clearing and writing to same reg, do the clear and then write (in same cycle)
    end
end

assign ds_fu_id_out = regs[ds_check_rd];
assign ds_fu_id_out_rs1 = regs[ds_check_rs1];
assign ds_fu_id_out_rs2 = regs[ds_check_rs2];

endmodule