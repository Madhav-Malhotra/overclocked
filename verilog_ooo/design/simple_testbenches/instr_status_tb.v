// =============================================================================
// instr_status_tb - self-checking unit test for instr_status.v
//
// Targets the CURRENT interface (rows keyed by PC). Phase 2 (plan.md task 2.2)
// re-keys the table by row index (ist_idx); update this TB in the same change.
// Peeks at internal arrays (valid_arr, pc_arr, stage_arr, ...) by hierarchy.
//
// Covers: reset; allocation of decoded fields; buffer_full after
// NUM_BUFFER_ROWS dispatches; issue marks stage IS; writeback clears the row;
// same-cycle dispatch + writeback keeps the count right; freed rows are reused;
// ds_ist_idx names the row the next dispatch lands in.
// =============================================================================
`timescale 1ns/1ps
module instr_status_tb;
  `include "tb_common.vh"

  localparam ROWS = 6;
  localparam FUW  = 3;
  localparam IS   = 2'h1;

  reg clock = 0, reset = 1;
  reg ds_en = 0;
  reg [31:0] ds_pc = 0;
  reg [6:0]  ds_opcode = 0;
  reg [2:0]  ds_funct3 = 0;
  reg [6:0]  ds_funct7 = 0;
  reg [31:0] ds_imm = 0;
  reg [4:0]  ds_shamt = 0, ds_rs1 = 0, ds_rs2 = 0, ds_rd = 0;
  reg [FUW-1:0] ds_fu_id = 0;
  reg iss_en = 0;
  reg [31:0] iss_pc = 0;
  reg wb_en = 0;
  reg [31:0] wb_pc = 0;
  wire buffer_full;
  wire [2:0] ds_ist_idx;

  instr_status #(.NUM_BUFFER_ROWS(ROWS), .NUM_FU(6), .FUW(FUW)) dut (
    .clock(clock), .reset(reset),
    .ds_en(ds_en), .ds_pc(ds_pc), .ds_opcode(ds_opcode), .ds_funct3(ds_funct3),
    .ds_funct7(ds_funct7), .ds_imm(ds_imm), .ds_shamt(ds_shamt),
    .ds_rs1(ds_rs1), .ds_rs2(ds_rs2), .ds_rd(ds_rd), .ds_fu_id(ds_fu_id),
    .iss_en(iss_en), .iss_pc(iss_pc),
    .wb_en(wb_en), .wb_pc(wb_pc),
    .buffer_full(buffer_full),
    .ds_ist_idx(ds_ist_idx)
  );

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Drive dispatch inputs for one instruction (fields derived from pc so they are checkable)
  task set_ds(input [31:0] pc); begin
    ds_pc = pc; ds_opcode = 7'h33; ds_funct3 = pc[4:2]; ds_funct7 = 7'h20;
    ds_imm = pc ^ 32'hA5A5_0000; ds_shamt = pc[6:2]; ds_rs1 = pc[6:2] + 1;
    ds_rs2 = pc[6:2] + 2; ds_rd = pc[6:2] + 3; ds_fu_id = 3'd5;
  end endtask

  task dispatch(input [31:0] pc); begin
    set_ds(pc); ds_en = 1; tick; ds_en = 0;
  end endtask

  // Row index currently holding a valid entry with this pc, or -1
  function integer find_row(input [31:0] pc);
    integer k;  // row loop counter
    begin
      find_row = -1;
      for (k = 0; k < ROWS; k = k + 1)
        if (dut.valid_arr[k] && dut.pc_arr[k] == pc && find_row == -1) find_row = k;
    end
  endfunction

  function integer count_valid(input dummy);
    integer k;  // row loop counter
    begin
      count_valid = 0;
      for (k = 0; k < ROWS; k = k + 1) if (dut.valid_arr[k]) count_valid = count_valid + 1;
    end
  endfunction

  integer i;    // loop counter
  integer row;  // table row holding the instruction under test
  initial begin
    tick; tick; reset = 0; tick;
    `CHECK(buffer_full, 1'b0, "not full after reset")
    `CHECK(count_valid(0), 0, "no valid rows after reset")

    // --- fill the buffer; ds_ist_idx predicts the allocated row
    for (i = 0; i < ROWS; i = i + 1) begin
      `CHECK(buffer_full, 1'b0, "not full before dispatch")
      `CHECK(ds_ist_idx, i[2:0], "ds_ist_idx = lowest free row")
      dispatch(32'h0100_0000 + 4*i);
      `CHECK(find_row(32'h0100_0000 + 4*i), i, "dispatch landed in predicted row")
    end
    `CHECK(buffer_full, 1'b1, "full after NUM_BUFFER_ROWS dispatches")
    `CHECK(count_valid(0), ROWS, "all rows valid")

    // --- stored fields
    row = find_row(32'h0100_0008);
    `CHECK(row >= 0, 1'b1, "pc 0x01000008 present")
    if (row >= 0) begin
      set_ds(32'h0100_0008);
      `CHECK(dut.opcode_arr[row], ds_opcode, "opcode stored")
      `CHECK(dut.func3_arr[row],  ds_funct3, "funct3 stored")
      `CHECK(dut.func7_arr[row],  ds_funct7, "funct7 stored")
      `CHECK(dut.imm_arr[row],    ds_imm,    "imm stored")
      `CHECK(dut.rd_arr[row],     ds_rd,     "rd stored")
      `CHECK(dut.rs1_arr[row],    ds_rs1,    "rs1 stored")
      `CHECK(dut.rs2_arr[row],    ds_rs2,    "rs2 stored")
      `CHECK(dut.fu_arr[row],     ds_fu_id,  "fu id stored")
    end

    // --- issue marks stage IS
    iss_en = 1; iss_pc = 32'h0100_0008; tick; iss_en = 0;
    if (row >= 0) `CHECK(dut.stage_arr[row], IS, "issued row stage = IS")

    // --- writeback clears that row
    wb_en = 1; wb_pc = 32'h0100_0008; tick; wb_en = 0;
    `CHECK(find_row(32'h0100_0008), -1, "row cleared by writeback")
    `CHECK(buffer_full, 1'b0, "not full after one writeback")
    `CHECK(count_valid(0), ROWS - 1, "ROWS-1 valid after writeback")
    `CHECK(ds_ist_idx, row[2:0], "ds_ist_idx points at the freed row")

    // --- same-cycle dispatch + writeback: count unchanged
    set_ds(32'h0100_0100); ds_en = 1;
    wb_en = 1; wb_pc = 32'h0100_0000;
    tick; ds_en = 0; wb_en = 0;
    `CHECK(find_row(32'h0100_0100) >= 0, 1'b1, "same-cycle dispatch allocated")
    `CHECK(find_row(32'h0100_0000), -1, "same-cycle writeback cleared")
    `CHECK(count_valid(0), ROWS - 1, "count unchanged by dispatch+writeback")
    `CHECK(buffer_full, 1'b0, "still not full")

    // --- freed row reused; buffer full again
    dispatch(32'h0100_0104);
    `CHECK(buffer_full, 1'b1, "full again after reusing freed row")
    `CHECK(find_row(32'h0100_0104) >= 0, 1'b1, "freed row reused")

    `TB_FINISH
  end
endmodule
