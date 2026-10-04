// =============================================================================
// Module:      reg_status_table
// Description: Table with 32 entries, used to keep track of which FU is generating which output. Basically a hash table in hardware. 
// Inputs:      clock        - clock
//              write_enable - enables write to addr_rd on rising edge
//              reg_id_in    - input used to address the table
//              fu_id_in     - written to table at address reg_id_in
// Outputs:     fu_id_out    - read value of table at address reg_id_in (registered)
// =============================================================================

module reg_status_table #(
    parameter DATAW = 32,
    parameter ADDRW  =  $clog2(DATAW),
    parameter NUM_REGS  =  32,

    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 1,
    parameter FUW = $clog2(NUM_ALU + NUM_MULTICYCLE_MULT + NUM_LOAD_STORE + 1 + 1) // + 1 for branch_comparator + 1 for N/A
)(
    input clock, 
    input reset,
    input [ADDRW-1:0] reg_id_in,
    input [FUW-1:0] fu_id_in,
    input write_enable,         // used in Dispatch stage
    input clear_enable,         // used in Writeback stage
    input [ADDRQ-1:0] clear_id,
    output [FUW-1:0] fu_id_out
);

(* ram_style = "block" *) reg [FUW-1:0] regs [0:NUM_REGS-1];
reg [FUW-1:0] fu_id_out_r;

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

    if (clear_enable) regs[clear_id] <= CLEAR;

    if (write_enable) regs[reg_id_in] <= fu_id_in; // if clearing and writing to same reg, do the clear and then write (in same cycle)  

    fu_id_out_r <= regs[reg_id_out];
end

assign fu_id_out = fu_id_out_r;

endmodule