// =============================================================================
// Module:      writeback
// Description: Selects the data written back to the register file.
//              Chooses between ALU result, memory load data, and PC+4 (for JAL/JALR).
// Inputs:      alu    - result from the ALU
//              mem    - data read from data memory (already sign/zero-extended)
//              pc4    - PC+4 value from the memory stage
//              wb_sel - 2-bit selector: WB_MEM=0, WB_ALU=1, WB_PC4=2
// Outputs:     wb_data - value written to the register file
// =============================================================================
module writeback #(
    parameter DATAW = 32
)
(
    input [DATAW-1:0] alu,
    input [DATAW-1:0] pc4,
    input [DATAW-1:0] mem,
    input [1:0] wb_sel,
    output [DATAW-1:0] wb_data,

    //way 2
    input [DATAW-1:0] alu_2,
    input [DATAW-1:0] pc4_2,
    input [DATAW-1:0] mem_2,
    input [1:0] wb_sel_2,
    output [DATAW-1:0] wb_data_2
);

// WB sel definitions (taken from control_signals.v)
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;

// way 1
assign wb_data = (wb_sel == WB_MEM) ? mem :
                 (wb_sel == WB_ALU) ? alu :
                 (wb_sel == WB_PC4) ? pc4 :
                 32'b0;

// way 2 
assign wb_data_2 = (wb_sel_2 == WB_MEM) ? mem_2 :
                 (wb_sel_2 == WB_ALU) ? alu_2 :
                 (wb_sel_2 == WB_PC4) ? pc4_2 :
                 32'b0;

endmodule