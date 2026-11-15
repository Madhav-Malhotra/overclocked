// =============================================================================
// alu_tb - self-checking unit test for alu.v
//
// Covers every selector, including DIV/DIVU edge cases (divide by zero,
// INT_MIN / -1), and checks that the removed MUL selector (4'd11) produces 0:
// multiplication is only done by the MCM unit (plan.md D7).
// =============================================================================
`timescale 1ns/1ps
module alu_tb;
  `include "tb_common.vh"

  localparam ADD = 0, SUB = 1, SLL = 2, SRL = 3, SRA = 4, SLT = 5, SLTU = 6,
             XOR = 7, OR = 8, AND = 9, NOP = 10, OLD_MUL = 11, DIV = 12, DIVU = 13;

  reg  signed [31:0] a = 0, b = 0;
  reg  [3:0] sel = 0;
  wire signed [31:0] y;

  alu dut (.idata1(a), .idata2(b), .alu_sel(sel), .odata(y));

  task op(input [3:0] s, input [31:0] x1, input [31:0] x2, input [31:0] exp, input [255:0] name);
    begin
      sel = s; a = x1; b = x2; #1;
      `CHECK(y, exp, name)
    end
  endtask

  initial begin
    op(ADD,  32'd5,        32'd7,        32'd12,       "ADD");
    op(SUB,  32'd5,        32'd7,        32'hfffffffe, "SUB");
    op(SLL,  32'h1,        32'd31,       32'h80000000, "SLL");
    op(SRL,  32'h80000000, 32'd4,        32'h08000000, "SRL");
    op(SRA,  32'h80000000, 32'd4,        32'hf8000000, "SRA");
    op(SLT,  32'hffffffff, 32'd1,        32'd1,        "SLT signed");
    op(SLTU, 32'hffffffff, 32'd1,        32'd0,        "SLTU unsigned");
    op(XOR,  32'hf0f0f0f0, 32'hff00ff00, 32'h0ff00ff0, "XOR");
    op(OR,   32'hf0f0f0f0, 32'h0f0f0f0f, 32'hffffffff, "OR");
    op(AND,  32'hf0f0f0f0, 32'hff00ff00, 32'hf000f000, "AND");
    op(NOP,  32'hdead,     32'h12345000, 32'h12345000, "NOP passes idata2 (LUI)");
    op(OLD_MUL, 32'd6,     32'd7,        32'd0,        "selector 11 (old MUL) no longer multiplies");
    op(DIV,  32'hfffffff9, 32'd2,        32'hfffffffd, "DIV -7/2 = -3 (truncates)");
    op(DIV,  32'd7,        32'd0,        32'hffffffff, "DIV by zero = -1");
    op(DIV,  32'h80000000, 32'hffffffff, 32'h80000000, "DIV INT_MIN/-1 = INT_MIN");
    op(DIVU, 32'hfffffffe, 32'd2,        32'h7fffffff, "DIVU unsigned");
    op(DIVU, 32'd7,        32'd0,        32'hffffffff, "DIVU by zero = all ones");
    `TB_FINISH
  end
endmodule
