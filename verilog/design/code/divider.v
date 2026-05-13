// =============================================================================
// Module:      divider
// Description: 10-operation arithmetic logic unit for RV32I.
//              Supports ADD, SUB, shifts (SLL/SRL/SRA), logical (XOR/OR/AND),
//              comparisons (SLT/SLTU), and NOP (pass-through idata2 for LUI).
// Inputs:      idata1, idata2 - 32-bit operands
//              alu_sel        - 4-bit operation selector
// Outputs:     odata          - 32-bit result
// =============================================================================
module alu #(
    parameter IDATAW = 32,
    parameter ODATAW = 32
)(
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    input div_sel,
    output reg signed [ODATAW-1:0] odata
);


// ====================
// COMBINATIONAL LOGIC
// ====================
always @(*) begin
    odata = 0;

    if(div_sel) begin 

        

    end

end

endmodule