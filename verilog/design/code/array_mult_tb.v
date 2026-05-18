// =============================================================================
// Testbench: array_mult_tb
// Description: Standalone unit tests for the array_mult module.
//              Tests basic positive, signed, zero-operand, and INT_MIN edge cases.
//              Does NOT require the full pipeline; drives array_mult directly.
//
// Usage (Icarus Verilog example):
//   iverilog -o array_mult_tb array_mult_tb.v array_mult.v
//   vvp array_mult_tb
// =============================================================================
`timescale 1ns/1ps

module array_mult_tb;

  // -------------------------
  // DUT signals
  // -------------------------
  reg         clk;
  reg         rst;
  reg         start;
  reg         hold;
  reg  [31:0] op_a;
  reg  [31:0] op_b;
  wire [31:0] result;
  wire        busy;

  // -------------------------
  // Instantiate DUT
  // -------------------------
  array_mult #(.DATAW(32)) dut (
    .clock      (clk),
    .reset      (rst),
    .start_pulse(start),
    .hold       (hold),
    .op_a       (op_a),
    .op_b       (op_b),
    .result     (result),
    .busy       (busy)
  );

  // -------------------------
  // Clock: 10 ns period
  // -------------------------
  initial clk = 0;
  always #5 clk = ~clk;

  // -------------------------
  // Test tracking
  // -------------------------
  integer pass_count;
  integer fail_count;

  // -------------------------
  // Task: run_mul
  //   Drives a single multiply, waits for completion,
  //   then checks result against expected.
  // -------------------------
  task run_mul;
    input signed [31:0] a;
    input signed [31:0] b;
    input signed [31:0] expected;
    input [127:0] label;   // up to 16 ASCII chars for display
    integer timeout;
    begin
      // Set operands and assert hold (simulates pipeline holding EX on a MUL)
      op_a  = a;
      op_b  = b;
      hold  = 1'b1;

      // One-cycle start pulse
      @(negedge clk);
      start = 1'b1;
      @(negedge clk);
      start = 1'b0;

      // Wait for busy to go high (should happen next cycle)
      timeout = 200;
      while (!busy && timeout > 0) begin
        @(negedge clk);
        timeout = timeout - 1;
      end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy on test: %s", label);
        fail_count = fail_count + 1;
        hold = 0;
        disable run_mul;
      end

      // Wait for busy to fall
      timeout = 200;
      while (busy && timeout > 0) begin
        @(negedge clk);
        timeout = timeout - 1;
      end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy-low on test: %s", label);
        fail_count = fail_count + 1;
        hold = 0;
        disable run_mul;
      end

      // One extra cycle: result register is written on the same edge busy falls,
      // so we need one more negedge to sample it reliably.
      @(negedge clk);

      // Drop hold (tells array_mult the instruction left EX)
      hold = 1'b0;
      @(negedge clk);

      // Check
      if (result === expected) begin
        $display("PASS  [%s]  %0d * %0d = %0d", label, $signed(a), $signed(b), $signed(result));
        pass_count = pass_count + 1;
      end else begin
        $display("FAIL  [%s]  %0d * %0d : got %0d, expected %0d",
                 label, $signed(a), $signed(b), $signed(result), $signed(expected));
        fail_count = fail_count + 1;
      end

      // Idle gap between tests
      repeat(3) @(negedge clk);
    end
  endtask

  // -------------------------
  // Main test sequence
  // -------------------------
  initial begin
    $dumpfile("array_mult_tb.vcd");  // name of the waveform output file
    $dumpvars(0, array_mult_tb);     // dump all signals in this module and below
    pass_count = 0;
    fail_count = 0;

    // Reset
    rst   = 1'b1;
    start = 1'b0;
    hold  = 1'b0;
    op_a  = 32'd0;
    op_b  = 32'd0;
    repeat(4) @(negedge clk);
    rst = 1'b0;
    repeat(2) @(negedge clk);

    // --------------------------------------------------
    // Basic positive cases
    // --------------------------------------------------
    run_mul(32'd6,   32'd7,   32'd42,          "6x7=42        ");
    run_mul(32'd1,   32'd1,   32'd1,           "1x1=1         ");
    run_mul(32'd100, 32'd200, 32'd20000,       "100x200=20000 ");

    // --------------------------------------------------
    // Zero operand cases
    // --------------------------------------------------
    run_mul(32'd0,   32'd999, 32'd0,           "0xa=0         ");
    run_mul(32'd999, 32'd0,   32'd0,           "ax0=0         ");
    run_mul(32'd0,   32'd0,   32'd0,           "0x0=0         ");

    // --------------------------------------------------
    // Signed (negative) cases
    // --------------------------------------------------
    run_mul(-32'sd1,  32'd1,   -32'sd1,        "-1x1=-1       ");
    run_mul(-32'sd1,  -32'sd1,  32'sd1,        "-1x-1=1       ");
    run_mul(-32'sd6,   32'sd7, -32'sd42,       "-6x7=-42      ");
    run_mul( 32'sd6,  -32'sd7, -32'sd42,       "6x-7=-42      ");
    run_mul(-32'sd6,  -32'sd7,  32'sd42,       "-6x-7=42      ");

    // --------------------------------------------------
    // Large values (low 32 bits of product)
    // --------------------------------------------------
    // 65536 * 65536 = 2^32 → low 32 bits = 0
    run_mul(32'd65536,  32'd65536,  32'd0,     "65536^2 lo32  ");
    // 0x7FFFFFFF * 2 = 0xFFFFFFFE (low 32 bits)
    run_mul(32'h7FFFFFFF, 32'd2, 32'hFFFFFFFE, "MAX_POS*2     ");

    // --------------------------------------------------
    // INT_MIN edge case (exercises abs33 33-bit path)
    // --------------------------------------------------
    // INT_MIN * 1 = INT_MIN (low 32 bits)
    run_mul(32'h80000000, 32'sd1,  32'h80000000, "INT_MIN*1     ");
    // INT_MIN * -1 = INT_MIN (overflow wraps in 32-bit two's complement)
    run_mul(32'h80000000, -32'sd1, 32'h80000000, "INT_MIN*-1    ");
    // INT_MIN * 0 = 0
    run_mul(32'h80000000, 32'd0,   32'd0,         "INT_MIN*0     ");

    // --------------------------------------------------
    // Summary
    // --------------------------------------------------
    $display("-------------------------------");
    $display("Results: %0d passed, %0d failed", pass_count, fail_count);
    if (fail_count == 0)
      $display("ALL TESTS PASSED");
    else
      $display("SOME TESTS FAILED");
    $display("-------------------------------");
    $finish;
  end

  // -------------------------
  // Timeout watchdog
  // -------------------------
  initial begin
    #100000;
    $display("WATCHDOG TIMEOUT: simulation ran too long");
    $finish;
  end

endmodule