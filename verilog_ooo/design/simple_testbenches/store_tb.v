// =============================================================================
// store_tb - self-checking unit test for store.v (the store functional unit,
// with dmemory.v)
//
// Hands stores to the FU (ex_valid, the issue cycle) and checks the timing:
// nothing is written in the issue cycle or in EX cycle 1 (address); in EX
// cycle 2 (memory) dmem_w_en is high at the effective address (idata1 +
// idata2) with the store_data; the write lands at the end of that cycle, so
// the data is in memory in the next cycle (plan.md D6), also through the
// dmemory read port; only the addressed bytes change; result_valid marks the
// store done (result 0) and is held (fu_ready low) until wb_ready.
// Covers: SW, SB, SH, positive and negative offsets, sb into a word read back
// as a word (partial overlap).
// =============================================================================
`timescale 1ns/1ps
module store_tb;
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
  localparam SB = 3'b000, SH = 3'b001, SW = 3'b010;  // funct3

  reg clock = 0, reset = 1;
  reg        ex_valid = 0;
  reg [31:0] idata1 = 0, idata2 = 0, store_data = 0, pc = 0;
  reg [2:0]  funct3 = 0;
  reg        wb_ready = 0;
  wire       fu_ready, result_valid;
  wire [31:0] result;
  wire        dmem_w_en;
  wire [31:0] dmem_w_pc, dmem_w_address, dmem_w_data;
  wire [1:0]  dmem_w_access_size;
  reg  [31:0] rd_address = BASE;   // TB-driven dmemory read port (checks the written data)
  wire [31:0] rd_data;

  store dut (
    .clock(clock), .reset(reset),
    .ex_valid(ex_valid), .idata1(idata1), .idata2(idata2), .store_data(store_data), .pc(pc),
    .funct3(funct3), .fu_ready(fu_ready),
    .dmem_w_en(dmem_w_en), .dmem_w_pc(dmem_w_pc), .dmem_w_access_size(dmem_w_access_size),
    .dmem_w_address(dmem_w_address), .dmem_w_data(dmem_w_data),
    .result_valid(result_valid), .result(result), .wb_ready(wb_ready));

  dmemory dmem (
    .clock(clock),
    .r_en(1'b1), .r_pc(32'hFFFF_FFFF), .r_access_size(2'd2), .r_address(rd_address),
    .w_en(dmem_w_en), .w_pc(dmem_w_pc), .w_access_size(dmem_w_access_size),
    .w_address(dmem_w_address), .w_data_in(dmem_w_data),
    .r_data_out(rd_data));

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Word currently in memory at absolute address `a` (little-endian)
  function [31:0] mem_word(input [31:0] a);
    begin
      mem_word = {dmem.mem[a - BASE + 3], dmem.mem[a - BASE + 2], dmem.mem[a - BASE + 1], dmem.mem[a - BASE]};
    end
  endfunction

  // Hand a store to the FU; after its memory cycle the word at `check_addr` must be `word_after`
  task do_store(input [31:0] base, input [31:0] offset, input [2:0] f3, input [31:0] data,
                input [31:0] check_addr, input [31:0] word_after, input [255:0] msg);
    reg [31:0] word_before;  // word at check_addr before the store
    begin
      `CHECK(fu_ready, 1'b1, "store FU ready before issue")
      word_before = mem_word(check_addr);
      idata1 = base; idata2 = offset; store_data = data; pc = 32'h0100_0100; funct3 = f3;
      ex_valid = 1; #1;
      `CHECK(dmem_w_en, 1'b0, "issue cycle: no memory write")
      tick; ex_valid = 0;
      idata1 = 32'hDEAD_BEEF; store_data = 32'hDEAD_BEEF; funct3 = 3'b111;   // registered inputs must be used
      `CHECK(dmem_w_en, 1'b0, "EX cycle 1 (address): no memory write")
      `CHECK(fu_ready, 1'b0, "store FU not ready in its address cycle")
      tick;
      `CHECK(dmem_w_en, 1'b1, "EX cycle 2 (memory): write enabled")
      `CHECK(dmem_w_address, base + offset, "EX cycle 2: effective address = idata1 + idata2")
      `CHECK(mem_word(check_addr), word_before, "write not landed during the memory cycle")
      `CHECK(fu_ready, 1'b0, "store FU not ready in its memory cycle")
      tick;
      `CHECK(dmem_w_en, 1'b0, "write only in the memory cycle")
      `CHECK(mem_word(check_addr), word_after, msg)
      rd_address = check_addr; #1;
      `CHECK(rd_data, word_after, "written data visible through the read port")
      `CHECK(result_valid, 1'b1, "store done after its memory cycle")
      `CHECK(result, 32'd0, "store has no register result")
      `CHECK(fu_ready, 1'b0, "store FU not ready until writeback")
      wb_ready = 1; tick; wb_ready = 0;
      `CHECK(result_valid, 1'b0, "result_valid cleared by wb_ready")
    end
  endtask

  integer k;  // byte loop counter
  initial begin
    #1;
    for (k = 32'h200; k < 32'h210; k = k + 1) dmem.mem[k] = 8'h00;   // words used below start at 0
    tick; tick; reset = 0; tick;
    `CHECK(result_valid, 1'b0, "no store done after reset")

    do_store(BASE + 32'h200, 32'd0,         SW, 32'hCAFE_F00D, BASE + 32'h200, 32'hCAFE_F00D, "SW");
    do_store(BASE + 32'h200, 32'd1,         SB, 32'h1234_56AB, BASE + 32'h200, 32'hCAFE_AB0D, "SB byte 1 (partial word)");
    do_store(BASE + 32'h200, 32'd2,         SH, 32'hFFFF_BEEF, BASE + 32'h200, 32'hBEEF_AB0D, "SH upper half");
    do_store(BASE + 32'h208, 32'hFFFF_FFFC, SW, 32'h0102_0304, BASE + 32'h204, 32'h0102_0304, "SW negative offset");
    do_store(BASE + 32'h204, 32'd3,         SB, 32'h0000_00EE, BASE + 32'h204, 32'hEE02_0304, "SB byte 3");
    `CHECK(mem_word(BASE + 32'h200), 32'hBEEF_AB0D, "earlier word unaffected by later stores")
    `CHECK(mem_word(BASE + 32'h208), 32'h0000_0000, "next word unaffected")

    `TB_FINISH
  end
endmodule
