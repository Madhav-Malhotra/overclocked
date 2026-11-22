// =============================================================================
// min_pc_select_tb - self-checking unit test for min_pc_select.v
//
// Compares the selector against a behavioural reference (linear scan for the
// smallest PC among valid inputs, lowest index on a tie) for directed cases
// and random valid masks / full-width PCs. Two instances: N = 6 (the FU table
// size) and N = 5 (not a power of two, exercises the padding leaves).
// =============================================================================
`timescale 1ns/1ps
module min_pc_select_tb;
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

  localparam DATAW = 32;

  // ---- N = 6 instance (inputs driven by the TB, outputs checked against ref_sel)
  reg  [5:0]        valid6 = 0;
  reg  [6*DATAW-1:0] pc6   = 0;
  wire              min_pc_valid6;
  wire [2:0]        min_pc_idx6;
  wire [5:0]        min_pc_onehot6;
  min_pc_select #(.N(6), .DATAW(DATAW)) dut6 (
    .valid(valid6), .pc(pc6), .min_pc_valid(min_pc_valid6), .min_pc_idx(min_pc_idx6), .min_pc_onehot(min_pc_onehot6));

  // ---- N = 5 instance (same, non-power-of-two size)
  reg  [4:0]        valid5 = 0;
  reg  [5*DATAW-1:0] pc5   = 0;
  wire              min_pc_valid5;
  wire [2:0]        min_pc_idx5;
  wire [4:0]        min_pc_onehot5;
  min_pc_select #(.N(5), .DATAW(DATAW)) dut5 (
    .valid(valid5), .pc(pc5), .min_pc_valid(min_pc_valid5), .min_pc_idx(min_pc_idx5), .min_pc_onehot(min_pc_onehot5));

  // Reference: index of the smallest valid PC (lowest index on a tie), -1 if none
  function integer ref_sel(input integer n, input [6*DATAW-1:0] pcs, input [5:0] v);
    integer k;  // candidate loop counter
    begin
      ref_sel = -1;
      for (k = 0; k < n; k = k + 1)
        if (v[k] && (ref_sel == -1 || pcs[k*DATAW +: DATAW] < pcs[ref_sel*DATAW +: DATAW]))
          ref_sel = k;
    end
  endfunction

  // Check both outputs of the N = 6 instance against the reference
  task check6(input [255:0] msg);
    integer r;  // reference index
    begin
      #1;
      r = ref_sel(6, pc6, valid6);
      `CHECK(min_pc_valid6, (r >= 0), msg)
      if (r >= 0) begin
        `CHECK(min_pc_idx6, r[2:0], msg)
        `CHECK(min_pc_onehot6, 6'b1 << r, msg)
      end else begin
        `CHECK(min_pc_onehot6, 6'b0, msg)
      end
    end
  endtask

  task check5(input [255:0] msg);
    integer r;  // reference index
    begin
      #1;
      r = ref_sel(5, {{DATAW{1'b0}}, pc5}, {1'b0, valid5});
      `CHECK(min_pc_valid5, (r >= 0), msg)
      if (r >= 0) begin
        `CHECK(min_pc_idx5, r[2:0], msg)
        `CHECK(min_pc_onehot5, 5'b1 << r, msg)
      end else begin
        `CHECK(min_pc_onehot5, 5'b0, msg)
      end
    end
  endtask

  integer t, k;  // trial / candidate loop counters
  initial begin
    // --- directed (N = 6)
    pc6 = {32'h0100_0014, 32'h0100_0010, 32'h0100_000c, 32'h0100_0008, 32'h0100_0004, 32'h0100_0000};
    valid6 = 6'b000000; check6("none valid");
    valid6 = 6'b111111; check6("all valid: row 0 has smallest pc");
    valid6 = 6'b100000; check6("only last row valid");
    valid6 = 6'b101010; check6("odd rows valid");
    // smallest PC in the highest row; an invalid row with an even smaller PC must lose
    pc6 = {32'h0000_0010, 32'h0000_0020, 32'h0000_0030, 32'h0000_0040, 32'h0000_0050, 32'h0000_0001};
    valid6 = 6'b111110; check6("invalid row with smallest pc loses");
    // PCs differ only in the top bit (full-width compare, no truncation)
    pc6 = {32'h8000_0000, 32'h8000_0000, 32'h8000_0000, 32'h8000_0000, 32'h0000_0000, 32'h8000_0000};
    valid6 = 6'b111111; check6("top-bit-only difference");
    // tie -> lower index
    pc6 = {6{32'h0100_0040}};
    valid6 = 6'b011100; check6("tie breaks to lower index");

    // --- random (N = 6 and N = 5)
    for (t = 0; t < 2000; t = t + 1) begin
      for (k = 0; k < 6; k = k + 1) begin
        // mix close PCs (same region) and arbitrary 32-bit PCs
        pc6[k*DATAW +: DATAW] = (t % 2) ? $random : (32'h0100_0000 + (($random & 32'h3f) << 2));
      end
      valid6 = $random;
      check6("random N=6");
      pc5 = pc6[5*DATAW-1:0];
      valid5 = valid6[4:0];
      check5("random N=5");
    end

    `TB_FINISH
  end
endmodule
