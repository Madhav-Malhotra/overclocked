// =============================================================================
// Module:      alu
// Description: Arithmetic logic unit for RV32I.
//              Supports ADD, SUB, shifts (SLL/SRL/SRA), logical (XOR/OR/AND),
//              comparisons (SLT/SLTU), NOP (pass-through idata2 for LUI),
//              MUL (low 32b product), and DIV/DIVU (for division by zero, following
//              risc-v conventions of setting output to MAX_INT/-1).
// Inputs:      idata1, idata2 - 32-bit operands
//              alu_sel        - 4-bit operation selector
//              multicyc_sel        - 0: single-cycle multiply (* operator)
//                               1: multicycle selected; MUL result comes from
//                                  array_mult in pd.v, so ALU outputs 0 as placeholder
// Outputs:     odata          - 32-bit result
// =============================================================================
module alu #(
    parameter IDATAW = 32,
    parameter ODATAW = 32
)(
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    input [3:0] alu_sel,
    input multicyc_sel,
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
localparam MUL  = 4'd11;
localparam DIV = 4'd12;
localparam DIVU = 4'd13;

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

        /* RISC-V M-Extension: ALU */ 
        // multicyc_sel=0: single-cycle multiply via * operator.
        // multicyc_sel=1: multicycle selected; result comes from array_mult in pd.v,
        //            ALU outputs 0 as a deterministic placeholder.
        MUL:  odata = multicyc_sel ? 32'd0 : ($signed(idata1) * $signed(idata2));
        DIV: begin // division by zero --> follow risc-v convention of setting to MAX_INT/-1
            if (idata2 == 32'h0) begin
                odata = 32'hFFFFFFFF; // Division by zero --> set to -1
            end else if (idata1 == 32'h80000000 && idata2 == 32'hFFFFFFFF) begin
                odata = 32'h80000000; // specifically handle INT_MIN / -1 overflow case (by default verilator triggers an overflow)
            end else begin
                odata = $signed($signed(idata1) / $signed(idata2)); // force cast division result to signed
            end
        end
        DIVU: begin
            odata = (idata2 == 'h0) ? 32'hFFFFFFFF : $unsigned(idata1) / $unsigned(idata2); // division by zero --> set to MAX_INT
        end 
        default: odata = 0;
    endcase
end

endmodule