// =============================================================================
// Module:      alu
// Description: Arithmetic logic unit for RV32I, used as the ALU functional
//              unit of the OoO core (FU ids 5 and 6; pd.v instantiates two).
//              Supports ADD, SUB, shifts (SLL/SRL/SRA), logical (XOR/OR/AND),
//              comparisons (SLT/SLTU), NOP (pass-through idata2 for LUI), and
//              DIV/DIVU (for division by zero, following risc-v conventions of
//              setting output to MAX_INT/-1).
//
//              OoO differences from verilog/design/code/alu.v:
//              - No MUL: multiply always runs on the MCM functional unit,
//                array_mult.v (plan.md D7), so there is no multicyc_sel /
//                mult_* interface.
//              - One cycle: odata is computed in the issue cycle and
//                registered into result, held (result_valid) until writeback
//                takes it (plan.md D3).
// Inputs:      clock, reset
//              ex_valid       - an instruction is issued to this FU this cycle
//              idata1, idata2 - 32-bit operands (selected in pd.v by a_sel/b_sel)
//              alu_sel        - 4-bit operation selector (control_signals.v)
//              wb_ready       - writeback takes this FU's result this cycle
// Outputs:     fu_ready       - FU can accept an instruction (holds none)
//              result_valid   - result computed, waiting for writeback
//              result         - the result
// =============================================================================
module alu #(
    parameter IDATAW = 32,
    parameter ODATAW = 32
)(
    input                          clock,
    input                          reset,

    // ====================
    // Issue -> FU (ready/valid)
    // ====================
    input                          ex_valid,
    input signed [IDATAW-1:0]      idata1,
    input signed [IDATAW-1:0]      idata2,
    input [3:0]                    alu_sel,
    output                         fu_ready,

    // ====================
    // FU -> writeback (ready/valid)
    // ====================
    output reg                     result_valid,
    output reg [ODATAW-1:0]        result,
    input                          wb_ready
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
// 4'd11 was MUL; multiply is handled only by the MCM functional unit (plan.md D7)
localparam DIV = 4'd12;
localparam DIVU = 4'd13;

reg [ODATAW-1:0] mask;

// ====================
// COMBINATIONAL LOGIC
// ====================
reg signed [ODATAW-1:0] odata;   // result of the issuing instruction

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
         /* RISC-V M-Extension Instructions */
        // MUL is not here: it runs on the MCM functional unit (array_mult.v, plan.md D7)
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

// ====================
// RESULT REGISTER (held until writeback)
// ====================
always @(posedge clock) begin
    if (reset) begin
        result_valid <= 1'b0;
        result       <= {ODATAW{1'b0}};
    end else begin
        if (wb_ready) result_valid <= 1'b0;
        if (ex_valid) begin
            result_valid <= 1'b1;
            result       <= odata;
        end
    end
end

assign fu_ready = !result_valid;

endmodule
