// =============================================================================
// Testbench: alu_mult8_tb
// Description: Instantiates `alu` with IDATAW=ODATAW=8 to exercise the
//              internal array_mult unit at DATAW=8 through the ALU's
//              multicyc_sel=1 MUL path (rather than driving array_mult
//              directly, as array_mult_tb.v does at the default DATAW=32).
//
//              Checks:
//                - 8-bit signed MUL results (low 8 bits of the product,
//                  matching the array_mult truncation semantics) for
//                  positive/negative/zero/overflow/INT_MIN cases.
//                - busy latency scales to DATAW+1 = 9 cycles (vs. 33 at
//                  DATAW=32), confirming the parameterization in alu.v
//                  (array_mult #(.DATAW(IDATAW))) actually takes effect.
//
// Usage:
//   iverilog -o alu_mult8_tb alu_mult8_tb.v alu.v array_mult.v && vvp alu_mult8_tb
// =============================================================================
`timescale 1ns/1ps

module alu_mult8_tb;

  localparam DATAW = 8;
  localparam [3:0] MUL = 4'd11;

  reg               clk;
  reg               rst;
  reg  signed [DATAW-1:0] idata1;
  reg  signed [DATAW-1:0] idata2;
  reg  [3:0]        alu_sel;
  reg               multicyc_sel;
  reg               mult_start_pulse;
  reg               mult_hold;
  wire              mult_busy;
  wire signed [DATAW-1:0] odata;

  alu #(
    .IDATAW(DATAW),
    .ODATAW(DATAW)
  ) dut (
    .clock           (clk),
    .reset           (rst),
    .idata1          (idata1),
    .idata2          (idata2),
    .alu_sel         (alu_sel),
    .multicyc_sel    (multicyc_sel),
    .mult_start_pulse(mult_start_pulse),
    .mult_hold       (mult_hold),
    .mult_busy       (mult_busy),
    .odata           (odata)
  );

  initial clk = 0;
  always #5 clk = ~clk;

  integer pass_count;
  integer fail_count;

  // -----------------------------------------------------------------------
  // Task: run_mul
  //   Drives one MUL through the ALU's multicycle path, waits for
  //   completion, checks result vs expected, and checks busy latency
  //   equals DATAW+1 cycles.
  // -----------------------------------------------------------------------
  task run_mul;
    input signed [DATAW-1:0] a;
    input signed [DATAW-1:0] b;
    input signed [DATAW-1:0] expected;
    input [127:0] label;
    integer timeout;
    integer busy_cycles;
    begin
      alu_sel      = MUL;
      multicyc_sel = 1'b1;
      idata1       = a;
      idata2       = b;
      mult_hold    = 1'b1;

      // One-cycle start pulse
      @(negedge clk); mult_start_pulse = 1'b1;
      @(negedge clk); mult_start_pulse = 1'b0;

      // Wait for busy to assert
      timeout = 200;
      while (!mult_busy && timeout > 0) begin @(negedge clk); timeout = timeout - 1; end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy  [%s]", label);
        fail_count = fail_count + 1;
        mult_hold = 0; disable run_mul;
      end

      // Count cycles busy stays high
      busy_cycles = 0;
      timeout = 200;
      while (mult_busy && timeout > 0) begin
        @(negedge clk);
        busy_cycles = busy_cycles + 1;
        timeout = timeout - 1;
      end
      if (timeout == 0) begin
        $display("TIMEOUT waiting for busy-low  [%s]", label);
        fail_count = fail_count + 1;
        mult_hold = 0; disable run_mul;
      end

      // One extra edge: result is registered on the same edge busy falls,
      // so sample it one negedge later (mirrors array_mult_tb.v).
      @(negedge clk);
      mult_hold = 1'b0;
      @(negedge clk);

      if (odata === expected && busy_cycles == DATAW + 1) begin
        $display("PASS  [%s]  %0d * %0d = %0d  (busy %0d cyc)",
                 label, a, b, $signed(odata), busy_cycles);
        pass_count = pass_count + 1;
      end else begin
        $display("FAIL  [%s]  %0d * %0d : got %0d (busy %0d cyc), expected %0d (busy %0d cyc)",
                 label, a, b, $signed(odata), busy_cycles, $signed(expected), DATAW + 1);
        fail_count = fail_count + 1;
      end

      repeat(3) @(negedge clk);
    end
  endtask

  initial begin
    $dumpfile("alu_mult8_tb.vcd");
    $dumpvars(0, alu_mult8_tb);
    pass_count = 0;
    fail_count = 0;

    rst = 1'b1; mult_start_pulse = 1'b0; mult_hold = 1'b0;
    alu_sel = MUL; multicyc_sel = 1'b1; idata1 = 0; idata2 = 0;
    repeat(4) @(negedge clk);
    rst = 1'b0;
    repeat(2) @(negedge clk);

    // Basic positive
    run_mul(  8'sd6,   8'sd7,   8'sd42,  "6x7=42       ");
    run_mul(  8'sd1,   8'sd1,   8'sd1,   "1x1=1        ");

    // Zero operand
    run_mul(  8'sd0,   8'sd99,  8'sd0,   "0xa=0        ");
    run_mul(  8'sd99,  8'sd0,   8'sd0,   "ax0=0        ");

    // Signed (negative)
    run_mul( -8'sd1,   8'sd1,  -8'sd1,   "-1x1=-1      ");
    run_mul( -8'sd1,  -8'sd1,   8'sd1,   "-1x-1=1      ");
    run_mul( -8'sd6,   8'sd7,  -8'sd42,  "-6x7=-42     ");
    run_mul(  8'sd6,  -8'sd7,  -8'sd42,  "6x-7=-42     ");
    run_mul( -8'sd6,  -8'sd7,   8'sd42,  "-6x-7=42     ");

    // Overflow: 100*2=200 -> low 8 bits 0xC8 = -56 signed
    run_mul(  8'sd100, 8'sd2,  -8'sd56,  "100x2 lo8    ");
    // 127*127=16129 -> low 8 bits 0x01 = 1
    run_mul(  8'sd127, 8'sd127, 8'sd1,   "127x127 lo8  ");

    // INT_MIN (8-bit: -128) edge cases, exercises the MSB subtract path
    run_mul( -8'sd128, 8'sd1,  -8'sd128, "INT_MIN*1    ");
    run_mul( -8'sd128, -8'sd1, -8'sd128, "INT_MIN*-1   ");
    run_mul( -8'sd128, 8'sd0,   8'sd0,   "INT_MIN*0    ");

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
