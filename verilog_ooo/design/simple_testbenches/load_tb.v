// =============================================================================
// load_tb - self-checking unit test for load.v (the load functional unit,
// with dmemory.v)
//
// Preloads data memory bytes through the hierarchy, then hands loads to the
// FU (ex_valid, the issue cycle) and checks the timing: nothing is read in the
// issue cycle or in EX cycle 1 (address); in EX cycle 2 (memory) dmem_r_en is
// high at the effective address (idata1 + idata2); in the next cycle the
// size-selected, sign/zero-extended value is registered (result_valid) and
// held (fu_ready low) until wb_ready; it does not change when memory changes
// afterwards.
// Covers: LW, LB/LBU (negative byte), LH/LHU (negative half), every byte
// position, positive and negative offsets.
// =============================================================================
`timescale 1ns/1ps
module load_tb;
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

  localparam BASE = 32'h0100_0000;   // dmemory base address
  localparam LB = 3'b000, LH = 3'b001, LW = 3'b010, LBU = 3'b100, LHU = 3'b101;  // funct3

  reg clock = 0, reset = 1;
  reg        ex_valid = 0;
  reg [31:0] idata1 = 0, idata2 = 0, pc = 0;
  reg [2:0]  funct3 = 0;
  reg        wb_ready = 0;
  wire       fu_ready, result_valid;
  wire [31:0] result;
  wire        dmem_r_en;
  wire [31:0] dmem_r_pc, dmem_r_address, dmem_r_data;
  wire [1:0]  dmem_r_access_size;

  load dut (
    .clock(clock), .reset(reset),
    .ex_valid(ex_valid), .idata1(idata1), .idata2(idata2), .pc(pc), .funct3(funct3), .fu_ready(fu_ready),
    .dmem_r_en(dmem_r_en), .dmem_r_pc(dmem_r_pc), .dmem_r_access_size(dmem_r_access_size),
    .dmem_r_address(dmem_r_address), .dmem_r_data(dmem_r_data),
    .result_valid(result_valid), .result(result), .wb_ready(wb_ready));

  dmemory dmem (
    .clock(clock),
    .r_en(dmem_r_en), .r_pc(dmem_r_pc), .r_access_size(dmem_r_access_size), .r_address(dmem_r_address),
    .w_en(1'b0), .w_pc(32'b0), .w_access_size(2'b0), .w_address(BASE), .w_data_in(32'b0),
    .r_data_out(dmem_r_data));

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Hand a load of base + offset to the FU, check timing and value, then writeback takes it
  task do_load(input [31:0] base, input [31:0] offset, input [2:0] f3, input [31:0] expected, input [255:0] msg);
    begin
      `CHECK(fu_ready, 1'b1, "load FU ready before issue")
      idata1 = base; idata2 = offset; pc = 32'h0100_0200; funct3 = f3;
      ex_valid = 1; #1;
      `CHECK(dmem_r_en, 1'b0, "issue cycle: no memory read")
      tick; ex_valid = 0;
      idata1 = 32'hDEAD_BEEF; idata2 = 32'h0; funct3 = 3'b111;   // registered inputs must be used
      `CHECK(dmem_r_en, 1'b0, "EX cycle 1 (address): no memory read")
      `CHECK(fu_ready, 1'b0, "load FU not ready in its address cycle")
      tick;
      `CHECK(dmem_r_en, 1'b1, "EX cycle 2 (memory): read enabled")
      `CHECK(dmem_r_address, base + offset, "EX cycle 2: effective address = idata1 + idata2")
      `CHECK(result_valid, 1'b0, "no result yet in the memory cycle")
      `CHECK(fu_ready, 1'b0, "load FU not ready in its memory cycle")
      tick;
      `CHECK(dmem_r_en, 1'b0, "read only in the memory cycle")
      `CHECK(result_valid, 1'b1, msg)
      `CHECK(result, expected, msg)
      `CHECK(fu_ready, 1'b0, "load FU not ready while it holds a value")
      tick;
      `CHECK(result, expected, "loaded value held until writeback")
      wb_ready = 1; tick; wb_ready = 0;
      `CHECK(result_valid, 1'b0, "result_valid cleared by wb_ready")
    end
  endtask

  initial begin
    // word at BASE+0x100 = 0x80FF017F (bytes 7F 01 FF 80), word at +0x104 = 0x12345678
    #1;
    dmem.mem[32'h100] = 8'h7F; dmem.mem[32'h101] = 8'h01; dmem.mem[32'h102] = 8'hFF; dmem.mem[32'h103] = 8'h80;
    dmem.mem[32'h104] = 8'h78; dmem.mem[32'h105] = 8'h56; dmem.mem[32'h106] = 8'h34; dmem.mem[32'h107] = 8'h12;
    tick; tick; reset = 0; tick;
    `CHECK(result_valid, 1'b0, "no result after reset")

    do_load(BASE + 32'h100, 32'd0,         LW,  32'h80FF_017F, "LW");
    do_load(BASE + 32'h108, 32'hFFFF_FFFC, LW,  32'h1234_5678, "LW negative offset");
    do_load(BASE + 32'h100, 32'd0,         LB,  32'h0000_007F, "LB positive byte 0");
    do_load(BASE + 32'h100, 32'd1,         LB,  32'h0000_0001, "LB byte 1");
    do_load(BASE + 32'h100, 32'd2,         LB,  32'hFFFF_FFFF, "LB negative byte 2");
    do_load(BASE + 32'h100, 32'd3,         LB,  32'hFFFF_FF80, "LB negative byte 3");
    do_load(BASE + 32'h100, 32'd3,         LBU, 32'h0000_0080, "LBU byte 3");
    do_load(BASE + 32'h100, 32'd0,         LH,  32'h0000_017F, "LH positive half");
    do_load(BASE + 32'h100, 32'd2,         LH,  32'hFFFF_80FF, "LH negative half");
    do_load(BASE + 32'h100, 32'd2,         LHU, 32'h0000_80FF, "LHU");
    do_load(BASE + 32'h104, 32'd1,         LBU, 32'h0000_0056, "LBU byte 1 of second word");

    // --- held value does not follow a later memory change
    idata1 = BASE + 32'h104; idata2 = 0; funct3 = LW;
    ex_valid = 1; tick; ex_valid = 0; tick; tick;
    `CHECK(result, 32'h1234_5678, "loaded before the change")
    dmem.mem[32'h104] = 8'h00;
    tick;
    `CHECK(result, 32'h1234_5678, "held value unchanged by a later memory change")

    `TB_FINISH
  end
endmodule
