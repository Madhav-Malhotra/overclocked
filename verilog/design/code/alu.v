// =============================================================================
// Module:      alu
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
    input [3:0] alu_sel,
    output reg signed [ODATAW-1:0] odata
);

// ====================
// OPERATION ENCODING
// ====================
localparam ADD  = 4'd0;
localparam SUB  = 4'd1;
localparam SLL  = 4'd2;
localparam SRL  = 4'd3;
localparam SRA  = 4'd4;
localparam SLT  = 4'd5;
localparam SLTU = 4'd6;
localparam XOR  = 4'd7;
localparam OR   = 4'd8;
localparam AND  = 4'd9;
// Pass idata2 through unchanged; used by LUI which needs imm with no addend
localparam NOP  = 4'd10;

reg [ODATAW-1:0] mask;

// ====================
// COMBINATIONAL LOGIC
// ====================
always @(*) begin
    odata = 0;
    mask = 0;

    case (alu_sel)
        ADD:  odata = idata1 + idata2;
        SUB:  odata = idata1 - idata2;
        XOR:  odata = idata1 ^ idata2;
        OR:   odata = idata1 | idata2;
        AND:  odata = idata1 & idata2;
        // NOP used to pass imm for LUI. Don't output 0
        NOP:  odata = idata2;
        SLL:  odata = idata1 << idata2[4:0];
        SRL:  odata = $unsigned(idata1) >> idata2[4:0];
        SRA: begin
            // Manual arithmetic right shift
            odata = $unsigned(idata1) >> idata2[4:0];
            // If negative, fill the upper bits with 1s
            if (idata1[IDATAW-1]) begin
                mask = ~({ODATAW{1'b1}} >> idata2[4:0]);
                odata = odata | mask;
            end
        end
        SLT:  odata = (idata1 < idata2) ? 1 : 0;
        SLTU: odata = ($unsigned(idata1) < $unsigned(idata2)) ? 1 : 0;
        default: odata = 0;
    endcase
end

endmodule