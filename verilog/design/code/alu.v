module alu #(
    parameter IDATAW = 32,
    parameter ODATAW = 32
)(
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    input [3:0] alu_sel,
    output reg signed [ODATAW-1:0] odata
);

// ALU sel definitions
localparam ADD = 4'd0;
localparam SUB = 4'd1;
localparam SLL = 4'd2;
localparam SRL = 4'd3;
localparam SRA = 4'd4;
localparam SLT = 4'd5;
localparam SLTU = 4'd6;
localparam XOR = 4'd7;
localparam OR = 4'd8;
localparam AND = 4'd9;
localparam NOP = 4'd10;

reg [ODATAW-1:0] mask;

always @(*) begin
    odata = 0;
    mask = 0;

    case (alu_sel)
        ADD: odata = idata1 + idata2;
        SUB: odata = idata1 - idata2;
        XOR: odata = idata1 ^ idata2;
        OR: odata = idata1 | idata2;
        AND: odata = idata1 & idata2;
        // Adjusted this to not output 0 so we can use NOP to pass imm for LUI
        NOP: odata = idata2;
        SLL: odata = idata1 << idata2[4:0];
        SRL: odata = $unsigned(idata1) >> idata2[4:0];
        SRA: begin
            // Manual arithmetic right shift
            odata = $unsigned(idata1) >> idata2[4:0];
            // If negative, fill the upper bits with 1s
            if (idata1[IDATAW-1]) begin
                mask = ~({ODATAW{1'b1}} >> idata2[4:0]);
                odata = odata | mask;
            end
        end
        SLT: odata = (idata1 < idata2) ? 1 : 0;
        SLTU: odata = ($unsigned(idata1) < $unsigned(idata2)) ? 1 : 0;
        default: odata = 0;
    endcase
end

endmodule