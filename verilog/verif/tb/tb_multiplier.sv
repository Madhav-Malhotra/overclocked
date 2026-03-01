module tb_multiplier;

  // DUT signals
  reg         clk;
  reg         rst_n;
  reg  [31:0] rs1_data;
  reg  [31:0] rs2_data;
  reg         is_signed_a;
  reg         is_signed_b;
  wire [63:0] rd_data;

  // DUT
  fu_multiplier #(.WIDTH(32)) dut (
    .clk(clk),
    .rst_n(rst_n),
    .rs1_data(rs1_data),
    .rs2_data(rs2_data),
    .is_signed_a(is_signed_a),
    .is_signed_b(is_signed_b),
    .rd_data(rd_data)
  );

  // Counters
  integer pass_count = 0;
  integer fail_count = 0;
  integer test_num = 0;

  // Check task — verifies the full 64-bit result
  task check(
    input [31:0] a,
    input [31:0] b,
    input        sa,
    input        sb,
    input [63:0] expected,
    input [63:0] mask  // which bits to check (all 1s = check all)
  );
    begin
      rs1_data = a;
      rs2_data = b;
      is_signed_a = sa;
      is_signed_b = sb;
      #1;
      test_num = test_num + 1;
      if ((rd_data & mask) === (expected & mask)) begin
        pass_count = pass_count + 1;
        $display("  [%0d] PASS: %08h * %08h (sa=%0b sb=%0b) = %016h",
                 test_num, a, b, sa, sb, rd_data);
      end else begin
        fail_count = fail_count + 1;
        $display("  [%0d] FAIL: %08h * %08h (sa=%0b sb=%0b) = %016h, expected %016h",
                 test_num, a, b, sa, sb, rd_data, expected);
      end
    end
  endtask

  // Convenience: check full 64 bits
  task check_full(
    input [31:0] a,
    input [31:0] b,
    input        sa,
    input        sb,
    input [63:0] expected
  );
    check(a, b, sa, sb, expected, 64'hFFFFFFFF_FFFFFFFF);
  endtask

  // Convenience: check only low 32 bits (MUL)
  task check_lo(
    input [31:0] a,
    input [31:0] b,
    input        sa,
    input        sb,
    input [31:0] expected
  );
    check(a, b, sa, sb, {32'h0, expected}, 64'h00000000_FFFFFFFF);
  endtask

  // Convenience: check only high 32 bits (MULH/MULHSU/MULHU)
  task check_hi(
    input [31:0] a,
    input [31:0] b,
    input        sa,
    input        sb,
    input [31:0] expected
  );
    check(a, b, sa, sb, {expected, 32'h0}, 64'hFFFFFFFF_00000000);
  endtask

  initial begin
    clk = 0;
    rst_n = 1;
    rs1_data = 0;
    rs2_data = 0;
    is_signed_a = 0;
    is_signed_b = 0;

    // ===== MUL (low 32 bits, unsigned multiply is fine) =====
    $display("--- MUL (low 32 bits) ---");
    check_lo(32'h0,        32'h0,        0, 0, 32'h0);         // 0*0 = 0
    check_lo(32'h1,        32'h1,        0, 0, 32'h1);         // 1*1 = 1
    check_lo(32'h3,        32'h7,        0, 0, 32'd21);        // 3*7 = 21
    check_lo(32'd13,       32'd11,       0, 0, 32'd143);       // 13*11 = 143
    check_lo(32'hFFFFFFFF, 32'hFFFFFFFF, 0, 0, 32'h1);         // low bits of (-1)*(-1)
    check_lo(32'hFFFFFFFA, 32'h3,        0, 0, 32'hFFFFFFEE);  // low bits of (-6)*3
    check_lo(32'h80000000, 32'h0,        0, 0, 32'h0);         // anything*0 = 0
    check_lo(32'h80000000, 32'h1,        0, 0, 32'h80000000);  // x*1 = x
    check_lo(32'h80000000, 32'h2,        0, 0, 32'h0);         // overflow wraps

    // ===== MULH (high 32 bits, signed*signed) =====
    $display("--- MULH (high 32 bits, signed*signed) ---");
    check_hi(32'h0,        32'h0,        1, 1, 32'h0);          // 0*0
    check_hi(32'h1,        32'h1,        1, 1, 32'h0);          // 1*1
    check_hi(32'h3,        32'h7,        1, 1, 32'h0);          // 3*7 fits in 32 bits
    check_hi(32'hFFFFFFFF, 32'hFFFFFFFF, 1, 1, 32'h0);          // (-1)*(-1) = 1, high=0
    check_hi(32'h7FFFFFFF, 32'h2,        1, 1, 32'h0);          // 0x7FFFFFFF*2 = 0xFFFFFFFE, high=0
    check_hi(32'h80000000, 32'h2,        1, 1, 32'hFFFFFFFF);   // (-2^31)*2 = -2^32, high=-1
    check_hi(32'h80000000, 32'h80000000, 1, 1, 32'h40000000);   // (-2^31)*(-2^31) = 2^62
    check_hi(32'hFFFFFFFF, 32'h7FFFFFFF, 1, 1, 32'hFFFFFFFF);   // (-1)*0x7FFFFFFF, high=-1

    // ===== MULHSU (high 32 bits, signed*unsigned) =====
    $display("--- MULHSU (high 32 bits, signed*unsigned) ---");
    check_hi(32'h0,        32'h0,        1, 0, 32'h0);
    check_hi(32'h1,        32'h1,        1, 0, 32'h0);
    check_hi(32'hFFFFFFFF, 32'h1,        1, 0, 32'hFFFFFFFF);   // (-1)*1 = -1, high=0xFFFFFFFF
    check_hi(32'h1,        32'hFFFFFFFF, 1, 0, 32'h0);          // 1*0xFFFFFFFF, high=0
    check_hi(32'h80000000, 32'h2,        1, 0, 32'hFFFFFFFF);   // (-2^31)*2, high=-1
    check_hi(32'hFFFFFFFF, 32'hFFFFFFFF, 1, 0, 32'hFFFFFFFF);   // (-1)*0xFFFFFFFF, high=-1

    // ===== MULHU (high 32 bits, unsigned*unsigned) =====
    $display("--- MULHU (high 32 bits, unsigned*unsigned) ---");
    check_hi(32'h0,        32'h0,        0, 0, 32'h0);
    check_hi(32'h1,        32'h1,        0, 0, 32'h0);
    check_hi(32'hFFFFFFFF, 32'hFFFFFFFF, 0, 0, 32'hFFFFFFFE);   // (2^32-1)^2 high
    check_hi(32'hFFFFFFFF, 32'h1,        0, 0, 32'h0);
    check_hi(32'h80000000, 32'h2,        0, 0, 32'h1);          // 0x80000000*2 = 0x100000000

    // ===== Full 64-bit checks =====
    $display("--- Full 64-bit verification ---");
    check_full(32'h3, 32'h7, 0, 0, 64'h00000000_00000015);      // 3*7=21
    check_full(32'hFFFFFFFF, 32'hFFFFFFFF, 1, 1, 64'h00000000_00000001); // (-1)*(-1)=1
    check_full(32'hFFFFFFFF, 32'hFFFFFFFF, 0, 0, 64'hFFFFFFFE_00000001); // unsigned max^2

    // Summary
    $display("");
    $display("==========================================");
    $display("Multiplier TB: %0d passed, %0d failed out of %0d tests",
             pass_count, fail_count, test_num);
    $display("==========================================");
    if (fail_count > 0)
      $fatal(1, "FAIL");
    else
      $finish;
  end

endmodule
