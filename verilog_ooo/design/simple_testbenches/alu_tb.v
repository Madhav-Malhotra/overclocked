// =============================================================================
// alu_tb - self-checking unit test for alu.v (the ALU functional unit)
//
// Each case issues one operation (alu_sel + operands) for one cycle
// (ex_valid) and checks that result_valid rises with the right result, that
// the result does not follow the operand inputs afterwards, that it is held
// (fu_ready low) until wb_ready, and that result_valid clears after it.
// Covers: every selector (ADD..AND, NOP for LUI, DIV, DIVU) including DIV/DIVU
// edge cases (divide by zero, INT_MIN / -1, negative operands); the old MUL
// selector 11 returns 0 (multiply is only on array_mult, plan.md D7).
// The opcode -> alu_sel / operand-select decode is tested in
// control_signals_tb.
// =============================================================================
`timescale 1ns/1ps
module alu_tb;
  // ====================
  // Self-checking helpers (each TB carries its own copy; no shared include files)
  // Usage:  `CHECK(actual, expected, "message")   ...   `TB_FINISH
  // ====================
  integer tb_errors = 0;  // number of failed CHECKs
  integer tb_checks = 0;  // number of CHECKs run

`define CHECK(act, exp, msg) \
  begin \
    tb_checks = tb_checks + 1; \
    if ((act) !== (exp)) begin \
      tb_errors = tb_errors + 1; \
      $display("  FAIL @%0t: %s: got %0h, expected %0h", $time, msg, (act), (exp)); \
    end \
  end

`define TB_FINISH \
  begin \
    if (tb_errors == 0) $display("PASS: %m (%0d checks)", tb_checks); \
    else begin \
      $display("FAIL: %m (%0d of %0d checks failed)", tb_errors, tb_checks); \
      $fatal(1); \
    end \
    $finish; \
  end

  localparam ADD = 0, SUB = 1, SLL = 2, SRL = 3, SRA = 4, SLT = 5, SLTU = 6,
             XOR = 7, OR = 8, AND = 9, NOP = 10, OLD_MUL = 11, DIV = 12, DIVU = 13;  // alu_sel (as in alu.v)

  reg clock = 0, reset = 1;
  reg        ex_valid = 0;
  reg [31:0] idata1 = 0, idata2 = 0;
  reg [3:0]  alu_sel = 0;
  reg        wb_ready = 0;
  wire       fu_ready, result_valid;
  wire [31:0] result;

  alu dut (
    .clock(clock), .reset(reset),
    .ex_valid(ex_valid), .idata1(idata1), .idata2(idata2), .alu_sel(alu_sel),
    .fu_ready(fu_ready), .result_valid(result_valid), .result(result), .wb_ready(wb_ready));

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Issue one operation, check its result, then let writeback take it
  task run(input [3:0] sel, input [31:0] a, input [31:0] b, input [31:0] expected, input [255:0] msg);
    begin
      `CHECK(fu_ready, 1'b1, "FU ready before issue")
      alu_sel = sel; idata1 = a; idata2 = b;
      ex_valid = 1; tick; ex_valid = 0;
      idata1 = 32'hDEAD_BEEF; idata2 = 32'hDEAD_BEEF;   // result must not follow the inputs afterwards
      `CHECK(result_valid, 1'b1, msg)
      `CHECK(result, expected, msg)
      `CHECK(fu_ready, 1'b0, "FU not ready while it holds a result")
      tick;
      `CHECK(result_valid, 1'b1, "result held until writeback")
      `CHECK(result, expected, "result value held until writeback")
      wb_ready = 1; tick; wb_ready = 0;
      `CHECK(result_valid, 1'b0, "result_valid cleared by wb_ready")
    end
  endtask

  initial begin
    tick; tick; reset = 0; tick;
    `CHECK(result_valid, 1'b0, "no result after reset")

    run(ADD,     32'd5,         32'd7,         32'd12,        "ADD");
    run(SUB,     32'd5,         32'd7,         32'hFFFF_FFFE, "SUB");
    run(SLL,     32'h1,         32'd31,        32'h8000_0000, "SLL");
    run(SRL,     32'h8000_0000, 32'd4,         32'h0800_0000, "SRL");
    run(SRA,     32'h8000_0000, 32'd4,         32'hF800_0000, "SRA");
    run(SLT,     32'hFFFF_FFFF, 32'd1,         32'd1,         "SLT signed");
    run(SLTU,    32'hFFFF_FFFF, 32'd1,         32'd0,         "SLTU unsigned");
    run(XOR,     32'hF0F0_F0F0, 32'hFF00_FF00, 32'h0FF0_0FF0, "XOR");
    run(OR,      32'hF0F0_F0F0, 32'h0F0F_0F0F, 32'hFFFF_FFFF, "OR");
    run(AND,     32'hF0F0_F0F0, 32'hFF00_FF00, 32'hF000_F000, "AND");
    run(NOP,     32'hDEAD,      32'h1234_5000, 32'h1234_5000, "NOP passes idata2 (LUI)");
    run(DIV,     32'hFFFF_FFF9, 32'd2,         32'hFFFF_FFFD, "DIV -7/2 = -3 (truncates)");
    run(DIV,     32'd7,         32'd0,         32'hFFFF_FFFF, "DIV by zero = -1");
    run(DIV,     32'h8000_0000, 32'hFFFF_FFFF, 32'h8000_0000, "DIV INT_MIN/-1 = INT_MIN");
    run(DIVU,    32'hFFFF_FFFE, 32'd2,         32'h7FFF_FFFF, "DIVU unsigned");
    run(DIVU,    32'd7,         32'd0,         32'hFFFF_FFFF, "DIVU by zero = all ones");
    run(OLD_MUL, 32'd6,         32'd7,         32'd0,         "old MUL selector returns 0 (no ALU multiply)");

    `TB_FINISH
  end
endmodule
