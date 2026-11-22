// =============================================================================
// array_mult_tb - self-checking unit test for array_mult.v (the MCM
// functional unit)
//
// Each case issues one MUL, waits for result_valid and checks the low 32 bits
// of the product, the latency (fixed: MCM_LATENCY cycles from the issue cycle
// to the first cycle result_valid is high), that fu_ready stays low from issue
// until writeback, that the result is held until wb_ready, and that operands
// changing after the issue cycle do not affect the product.
// Covers: small, zero, negative x positive, negative x negative, INT_MIN x -1,
// -1 x -1, large operands; back-to-back MULs after each writeback.
// =============================================================================
`timescale 1ns/1ps
module array_mult_tb;
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

  localparam MCM_LATENCY = 34;  // issue cycle -> result_valid: 1 (start) + 32 (accumulate) + 1 (result latch)

  reg clock = 0, reset = 1;
  reg        iss_valid = 0;
  reg [31:0] iss_op1 = 0, iss_op2 = 0;
  reg        wb_ready = 0;
  wire       fu_ready, result_valid;
  wire [31:0] result;

  array_mult dut (
    .clock(clock), .reset(reset),
    .ex_valid(iss_valid), .op_a(iss_op1), .op_b(iss_op2),
    .fu_ready(fu_ready), .result_valid(result_valid), .result(result), .wb_ready(wb_ready));

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Issue a*b, check latency/product/hold, then let writeback take it
  task mul(input [31:0] a, input [31:0] b, input [255:0] msg);
    reg [63:0] product;      // reference product
    integer cycles;          // cycles from the issue cycle until result_valid
    begin
      product = a * b;
      `CHECK(fu_ready, 1'b1, "MCM ready before issue")
      iss_op1 = a; iss_op2 = b; iss_valid = 1; tick; iss_valid = 0;
      iss_op1 = 32'hDEAD_BEEF; iss_op2 = 32'h1357_9BDF;    // operands are latched at issue
      cycles = 1;
      while (!result_valid && cycles < 100) begin
        `CHECK(fu_ready, 1'b0, "MCM not ready while the MUL is in flight")
        tick; cycles = cycles + 1;
      end
      `CHECK(cycles, MCM_LATENCY, "MUL latency")
      `CHECK(result, product[31:0], msg)
      `CHECK(fu_ready, 1'b0, "MCM not ready while it holds a result")
      tick; tick;
      `CHECK(result_valid, 1'b1, "product held until writeback")
      `CHECK(result, product[31:0], "product value held until writeback")
      wb_ready = 1; tick; wb_ready = 0;
      `CHECK(result_valid, 1'b0, "result_valid cleared by wb_ready")
    end
  endtask

  initial begin
    tick; tick; reset = 0; tick;
    `CHECK(result_valid, 1'b0, "no result after reset")
    mul(32'd5,         32'd7,         "5 * 7");
    mul(32'd0,         32'h1234_5678, "0 * x");
    mul(32'hFFFF_FFFD, 32'd7,         "-3 * 7");
    mul(32'd7,         32'hFFFF_FFFD, "7 * -3");
    mul(32'hFFFF_FFFD, 32'hFFFF_FFF9, "-3 * -7");
    mul(32'h8000_0000, 32'hFFFF_FFFF, "INT_MIN * -1 (low bits)");
    mul(32'hFFFF_FFFF, 32'hFFFF_FFFF, "-1 * -1");
    mul(32'h1234_5678, 32'h9ABC_DEF0, "large operands (low 32 bits)");
    mul(32'h0110_0000, 32'h0000_0010, "sp-like * 16");
    `TB_FINISH
  end
endmodule
