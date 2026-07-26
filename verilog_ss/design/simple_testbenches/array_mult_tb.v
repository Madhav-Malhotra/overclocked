// =============================================================================
// Testbench: array_mult_tb
// Description: Standalone unit tests for the array_mult module.
//              Covers positive, negative, zero, large-value, and INT_MIN cases.
//              Drives array_mult directly — no pipeline required.
//
// Usage (Icarus Verilog):
//   iverilog -o array_mult_tb array_mult_tb.v array_mult.v && vvp array_mult_tb
// =============================================================================
`timescale 1ns/1ps

module array_mult_tb;

  reg         clk;
  reg         rst;
  reg         start;
  reg         hold;
  reg  [31:0] op_a;
  reg  [31:0] op_b;
  wire [31:0] result;
  wire        busy;

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

  initial clk = 0;
  always #5 clk = ~clk;

  integer pass_count;
  integer fail_count;

  // -----------------------------------------------------------------------
  // Task: run_mul
  //   Drives one multiply, waits for completion, checks result vs expected.
  // -----------------------------------------------------------------------
  task run_mul;
    input signed [31:0] a;
    input signed [31:0] b;
    input signed [31:0] expected;
    input [127:0] label;
    integer timeout;
    begin
      op_a = a;
      op_b = b;
      hold = 1'b1;

      // One-cycle start pulse
      @(negedge clk); start = 1'b1;
      @(negedge clk); start = 1'b0;

      // Wait for busy to assert
      timeout = 200;
      while (!busy && timeout > 0) begin @(negedge clk); timeout = timeout - 1; end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy  [%s]", label);
        fail_count = fail_count + 1;
        hold = 0; disable run_mul;
      end

      // Wait for busy to deassert
      timeout = 200;
      while (busy && timeout > 0) begin @(negedge clk); timeout = timeout - 1; end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy-low  [%s]", label);
        fail_count = fail_count + 1;
        hold = 0; disable run_mul;
      end

      // One extra edge: result is registered on the same edge busy falls,
      // so sample it one negedge later.
      @(negedge clk);
      hold = 1'b0;
      @(negedge clk);

      if (result === expected) begin
        $display("PASS  [%s]  %0d * %0d = %0d", label, $signed(a), $signed(b), $signed(result));
        pass_count = pass_count + 1;
      end else begin
        $display("FAIL  [%s]  %0d * %0d : got %0d, expected %0d",
                 label, $signed(a), $signed(b), $signed(result), $signed(expected));
        fail_count = fail_count + 1;
      end

      repeat(3) @(negedge clk);
    end
  endtask

  initial begin
    $dumpfile("array_mult_tb.vcd");
    $dumpvars(0, array_mult_tb);
    pass_count = 0;
    fail_count = 0;

    rst = 1'b1; start = 1'b0; hold = 1'b0; op_a = 0; op_b = 0;
    repeat(4) @(negedge clk);
    rst = 1'b0;
    repeat(2) @(negedge clk);

    // Basic positive
    run_mul( 32'd6,   32'd7,   32'd42,           "6x7=42        ");
    run_mul( 32'd1,   32'd1,   32'd1,            "1x1=1         ");
    run_mul( 32'd100, 32'd200, 32'd20000,        "100x200=20000 ");

    // Zero operand
    run_mul( 32'd0,   32'd999, 32'd0,            "0xa=0         ");
    run_mul( 32'd999, 32'd0,   32'd0,            "ax0=0         ");
    run_mul( 32'd0,   32'd0,   32'd0,            "0x0=0         ");

    // Signed (negative)
    run_mul(-32'sd1,  32'sd1,  -32'sd1,          "-1x1=-1       ");
    run_mul(-32'sd1, -32'sd1,   32'sd1,          "-1x-1=1       ");
    run_mul(-32'sd6,  32'sd7,  -32'sd42,         "-6x7=-42      ");
    run_mul( 32'sd6, -32'sd7,  -32'sd42,         "6x-7=-42      ");
    run_mul(-32'sd6, -32'sd7,   32'sd42,         "-6x-7=42      ");

    // Large values (low 32 bits of product)
    run_mul(32'd65536,    32'd65536,    32'd0,         "65536^2 lo32  ");
    run_mul(32'h7FFFFFFF, 32'd2,        32'hFFFFFFFE,  "MAX_POS*2     ");

    // INT_MIN edge cases (exercises the MSB subtract path)
    run_mul(32'h80000000, 32'sd1,  32'h80000000, "INT_MIN*1     ");
    run_mul(32'h80000000, -32'sd1, 32'h80000000, "INT_MIN*-1    ");
    run_mul(32'h80000000, 32'd0,   32'd0,         "INT_MIN*0     ");

    $display("-------------------------------");
    $display("Results: %0d passed, %0d failed", pass_count, fail_count);
    if (fail_count == 0) $display("ALL TESTS PASSED");
    else                 $display("SOME TESTS FAILED");
    $display("-------------------------------");
    $finish;
  end

  initial begin
    #100000;
    $display("WATCHDOG TIMEOUT");
    $finish;
  end

endmodule
