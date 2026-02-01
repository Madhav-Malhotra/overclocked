module writeback #(
    parameter DATAW = 32
)
(
    input [DATAW-1:0] alu,
    input [DATAW-1:0] pc4,
    input [DATAW-1:0] mem,
    input [1:0] wb_sel,
    output [DATAW-1:0] wb_data
);

// WB sel definitions (taken from control_signals.v)
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;

assign wb_data = (wb_sel == WB_MEM) ? mem :
                 (wb_sel == WB_ALU) ? alu :
                 (wb_sel == WB_PC4) ? pc4 :
                 32'b0; 

endmodule