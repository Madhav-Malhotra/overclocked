module tb_divider;

  // DUT signals
  reg         clk;
  reg         rst_n;
  reg  [31:0] rs1_data;
  reg  [31:0] rs2_data;
  reg         is_signed;
  wire [31:0] quotient;
  wire [31:0] remainder;

  // DUT
  fu_divider #(.WIDTH(32)) dut (
    .clk(clk),
    .rst_n(rst_n),
    .rs1_data(rs1_data),
    .rs2_data(rs2_data),
    .is_signed(is_signed),
    .quotient(quotient),
    .remainder(remainder)
  );

  // Counters
  integer pass_count = 0;
  integer fail_count = 0;
  integer test_num = 0;

  // Check task — verifies both quotient and remainder
  task check(
    input [31:0] dividend,
    input [31:0] divisor,
    input        sgn,
    input [31:0] exp_quot,
    input [31:0] exp_rem
  );
    begin
      rs1_data = dividend;
      rs2_data = divisor;
      is_signed = sgn;
      #1;
      test_num = test_num + 1;
      if (quotient === exp_quot && remainder === exp_rem) begin
        pass_count = pass_count + 1;
        $display("  [%0d] PASS: %08h / %08h (signed=%0b) => q=%08h r=%08h",
                 test_num, dividend, divisor, sgn, quotient, remainder);
      end else begin
        fail_count = fail_count + 1;
        if (quotient !== exp_quot)
          $display("  [%0d] FAIL: %08h / %08h (signed=%0b) => q=%08h (expected %08h), r=%08h",
                   test_num, dividend, divisor, sgn, quotient, exp_quot, remainder);
        if (remainder !== exp_rem)
          $display("  [%0d] FAIL: %08h %% %08h (signed=%0b) => r=%08h (expected %08h), q=%08h",
                   test_num, dividend, divisor, sgn, remainder, exp_rem, quotient);
      end
    end
  endtask

  initial begin
    clk = 0;
    rst_n = 1;
    rs1_data = 0;
    rs2_data = 0;
    is_signed = 0;

    // ===== DIVU / REMU (unsigned) =====
    $display("--- DIVU / REMU (unsigned) ---");
    check(32'd20,        32'd6,         0, 32'd3,         32'd2);          // 20/6=3 r2
    check(32'd1,         32'd1,         0, 32'd1,         32'd0);          // 1/1=1 r0
    check(32'd0,         32'd1,         0, 32'd0,         32'd0);          // 0/1=0 r0
    check(32'd7,         32'd2,         0, 32'd3,         32'd1);          // 7/2=3 r1
    check(32'hFFFFFFFE,  32'd2,         0, 32'h7FFFFFFF,  32'd0);          // large unsigned
    check(32'h80000000,  32'd1,         0, 32'h80000000,  32'd0);          // 0x80000000/1
    check(32'h80000000,  32'd2,         0, 32'h40000000,  32'd0);          // 0x80000000/2
    check(32'h80000000,  32'd3,         0, 32'h2AAAAAAA,  32'd2);          // 0x80000000/3
    check(32'hFFFFFFFF,  32'hFFFFFFFF,  0, 32'd1,         32'd0);          // max/max = 1 r0
    check(32'hFFFFFFFE,  32'hFFFFFFFF,  0, 32'd0,         32'hFFFFFFFE);   // (max-1)/max = 0 r(max-1)

    // ===== DIVU / REMU: division by zero =====
    $display("--- DIVU / REMU: division by zero ---");
    check(32'd20,        32'd0,         0, 32'hFFFFFFFF,  32'd20);         // spec: quot=all 1s, rem=dividend
    check(32'd0,         32'd0,         0, 32'hFFFFFFFF,  32'd0);          // 0/0
    check(32'hDEADBEEF,  32'd0,         0, 32'hFFFFFFFF,  32'hDEADBEEF);   // large/0

    // ===== DIV / REM (signed, positive operands) =====
    $display("--- DIV / REM (signed, positive) ---");
    check(32'd20,        32'd6,         1, 32'd3,         32'd2);          // 20/6=3 r2
    check(32'd1,         32'd1,         1, 32'd1,         32'd0);
    check(32'd0,         32'd1,         1, 32'd0,         32'd0);
    check(32'd7,         32'd2,         1, 32'd3,         32'd1);

    // ===== DIV / REM (signed, negative dividend) =====
    $display("--- DIV / REM (signed, negative dividend) ---");
    // -20 / 6 = -3 remainder -2 (remainder has sign of dividend)
    check(32'hFFFFFFEC,  32'd6,         1, 32'hFFFFFFFD,  32'hFFFFFFFE);
    // -1 / 1 = -1 remainder 0
    check(32'hFFFFFFFF,  32'd1,         1, 32'hFFFFFFFF,  32'd0);
    // -7 / 2 = -3 remainder -1
    check(32'hFFFFFFF9,  32'd2,         1, 32'hFFFFFFFD,  32'hFFFFFFFF);

    // ===== DIV / REM (signed, negative divisor) =====
    $display("--- DIV / REM (signed, negative divisor) ---");
    // 20 / -6 = -3 remainder 2 (remainder has sign of dividend)
    check(32'd20,        32'hFFFFFFFA,  1, 32'hFFFFFFFD,  32'd2);
    // 1 / -1 = -1 remainder 0
    check(32'd1,         32'hFFFFFFFF,  1, 32'hFFFFFFFF,  32'd0);

    // ===== DIV / REM (signed, both negative) =====
    $display("--- DIV / REM (signed, both negative) ---");
    // -20 / -6 = 3 remainder -2
    check(32'hFFFFFFEC,  32'hFFFFFFFA,  1, 32'd3,         32'hFFFFFFFE);
    // -1 / -1 = 1 remainder 0
    check(32'hFFFFFFFF,  32'hFFFFFFFF,  1, 32'd1,         32'd0);

    // ===== DIV / REM: division by zero (signed) =====
    $display("--- DIV / REM: division by zero (signed) ---");
    check(32'd20,        32'd0,         1, 32'hFFFFFFFF,  32'd20);
    check(32'hFFFFFFEC,  32'd0,         1, 32'hFFFFFFFF,  32'hFFFFFFEC);   // -20/0: rem=-20

    // ===== DIV / REM: signed overflow =====
    $display("--- DIV / REM: signed overflow ---");
    // -2^31 / -1 = -2^31 (overflow), remainder = 0
    check(32'h80000000,  32'hFFFFFFFF,  1, 32'h80000000,  32'd0);

    // Summary
    $display("");
    $display("==========================================");
    $display("Divider TB: %0d passed, %0d failed out of %0d tests",
             pass_count, fail_count, test_num);
    $display("==========================================");
    if (fail_count > 0)
      $fatal(1, "FAIL");
    else
      $finish;
  end

endmodule
