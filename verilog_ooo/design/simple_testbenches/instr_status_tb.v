// =============================================================================
// instr_status_tb - self-checking unit test for instr_status.v
//
// Rows are addressed by their index (ist_idx, plan.md D1). Peeks at internal
// arrays (valid_arr, pc_arr, stage_arr, ...) by hierarchy.
//
// Covers: reset; ds_ist_idx names the lowest free row and dispatch writes the
// decoded fields there; buffer_full after NUM_BUFFER_ROWS dispatches; issue
// select marks a row IS; issue marks a row EX and the read port returns that
// row's fields; select and issue of different rows in one cycle; the
// writeback read port returns a row's opcode; writeback by ist_idx clears
// only that row; same-cycle dispatch + writeback keeps the
// count right; freed rows are reused; two rows with the same PC are told
// apart by ist_idx.
// =============================================================================
`timescale 1ns/1ps
module instr_status_tb;
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

  localparam ROWS = 6;
  localparam FUW  = 3;
  localparam DS = 2'h0, IS = 2'h1, EX = 2'h2, WB = 2'h3;  // stage codes (as in instr_status.v)

  reg clock = 0, reset = 1;
  reg ds_en = 0;
  reg [31:0] ds_pc = 0;
  reg [6:0]  ds_opcode = 0;
  reg [2:0]  ds_funct3 = 0;
  reg [6:0]  ds_funct7 = 0;
  reg [31:0] ds_imm = 0;
  reg [4:0]  ds_shamt = 0, ds_rs1 = 0, ds_rs2 = 0, ds_rd = 0;
  reg [FUW-1:0] ds_fu_id = 0;
  wire buffer_full;
  wire [2:0] ds_ist_idx;
  reg iss_sel_valid = 0;
  reg [2:0] iss_sel_ist_idx = 0;
  reg iss_valid = 0;
  reg [2:0] iss_ist_idx = 0;
  wire [6:0]  iss_opcode;
  wire [2:0]  iss_funct3;
  wire [6:0]  iss_funct7;
  wire [31:0] iss_imm;
  wire [4:0]  iss_shamt;
  reg wb_en = 0;
  reg [2:0] wb_ist_idx = 0;
  wire [6:0] wb_opcode;    // writeback read port

  instr_status #(.NUM_BUFFER_ROWS(ROWS), .NUM_FU(6), .FUW(FUW)) dut (
    .clock(clock), .reset(reset),
    .ds_en(ds_en), .ds_pc(ds_pc), .ds_opcode(ds_opcode), .ds_funct3(ds_funct3),
    .ds_funct7(ds_funct7), .ds_imm(ds_imm), .ds_shamt(ds_shamt),
    .ds_rs1(ds_rs1), .ds_rs2(ds_rs2), .ds_rd(ds_rd), .ds_fu_id(ds_fu_id),
    .buffer_full(buffer_full), .ds_ist_idx(ds_ist_idx),
    .iss_sel_valid(iss_sel_valid), .iss_sel_ist_idx(iss_sel_ist_idx),
    .iss_valid(iss_valid), .iss_ist_idx(iss_ist_idx),
    .iss_opcode(iss_opcode), .iss_funct3(iss_funct3),
    .iss_funct7(iss_funct7), .iss_imm(iss_imm), .iss_shamt(iss_shamt),
    .wb_en(wb_en), .wb_ist_idx(wb_ist_idx), .wb_opcode(wb_opcode)
  );

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Drive dispatch inputs for one instruction; fields derived from `key` so they are checkable
  task set_ds(input [31:0] pc, input [7:0] key); begin
    ds_pc = pc; ds_opcode = 7'h33 ^ key[6:0]; ds_funct3 = key[2:0]; ds_funct7 = {key[3:0], 3'b101};
    ds_imm = {24'hA5A5_00, key}; ds_shamt = key[4:0]; ds_rs1 = key[4:0] + 1;
    ds_rs2 = key[4:0] + 2; ds_rd = key[4:0] + 3; ds_fu_id = 3'd5;
  end endtask

  // Dispatch one instruction; returns the row it was written to
  task dispatch(input [31:0] pc, input [7:0] key, output [2:0] row); begin
    set_ds(pc, key); row = ds_ist_idx; ds_en = 1; tick; ds_en = 0;
  end endtask

  function integer count_valid(input dummy);
    integer k;  // row loop counter
    begin
      count_valid = 0;
      for (k = 0; k < ROWS; k = k + 1) if (dut.valid_arr[k]) count_valid = count_valid + 1;
    end
  endfunction

  integer i;           // loop counter
  reg [2:0] row;       // row returned by the last dispatch
  reg [2:0] row_a, row_b;  // rows used in the multi-row checks
  initial begin
    tick; tick; reset = 0; tick;
    `CHECK(buffer_full, 1'b0, "not full after reset")
    `CHECK(count_valid(0), 0, "no valid rows after reset")

    // --- fill the buffer; ds_ist_idx predicts the allocated row, fields stored there
    for (i = 0; i < ROWS; i = i + 1) begin
      `CHECK(buffer_full, 1'b0, "not full before dispatch")
      `CHECK(ds_ist_idx, i[2:0], "ds_ist_idx = lowest free row")
      dispatch(32'h0100_0000 + 4*i, 8'h10 + i, row);
      `CHECK(row, i[2:0], "dispatch row = ds_ist_idx")
      `CHECK(dut.valid_arr[i], 1'b1, "row valid after dispatch")
      `CHECK(dut.pc_arr[i], 32'h0100_0000 + 4*i, "pc stored in row ds_ist_idx")
      `CHECK(dut.stage_arr[i], DS, "new row stage = DS")
    end
    `CHECK(buffer_full, 1'b1, "full after NUM_BUFFER_ROWS dispatches")
    `CHECK(count_valid(0), ROWS, "all rows valid")

    // --- stored fields (row 2)
    set_ds(32'h0100_0008, 8'h12);
    `CHECK(dut.opcode_arr[2], ds_opcode, "opcode stored")
    `CHECK(dut.func3_arr[2],  ds_funct3, "funct3 stored")
    `CHECK(dut.func7_arr[2],  ds_funct7, "funct7 stored")
    `CHECK(dut.imm_arr[2],    ds_imm,    "imm stored")
    `CHECK(dut.shamt_arr[2],  ds_shamt,  "shamt stored")
    `CHECK(dut.rd_arr[2],     ds_rd,     "rd stored")
    `CHECK(dut.rs1_arr[2],    ds_rs1,    "rs1 stored")
    `CHECK(dut.rs2_arr[2],    ds_rs2,    "rs2 stored")
    `CHECK(dut.fu_arr[2],     ds_fu_id,  "fu id stored")

    // --- select row 2 -> IS
    iss_sel_valid = 1; iss_sel_ist_idx = 2; tick; iss_sel_valid = 0;
    `CHECK(dut.stage_arr[2], IS, "selected row stage = IS")
    `CHECK(dut.stage_arr[3], DS, "other rows unchanged by select")

    // --- issue row 2 (-> EX, read port) while row 4 is selected in the same cycle
    iss_valid = 1; iss_ist_idx = 2;
    iss_sel_valid = 1; iss_sel_ist_idx = 4;
    #1;
    set_ds(32'h0100_0008, 8'h12);
    `CHECK(iss_opcode, ds_opcode, "read port opcode of row 2")
    `CHECK(iss_funct3, ds_funct3, "read port funct3 of row 2")
    `CHECK(iss_funct7, ds_funct7, "read port funct7 of row 2")
    `CHECK(iss_imm,    ds_imm,    "read port imm of row 2")
    `CHECK(iss_shamt,  ds_shamt,  "read port shamt of row 2")
    tick; iss_valid = 0; iss_sel_valid = 0;
    `CHECK(dut.stage_arr[2], EX, "issued row stage = EX")
    `CHECK(dut.stage_arr[4], IS, "row selected in the issue cycle = IS")

    // --- read port follows iss_ist_idx combinationally
    iss_ist_idx = 5; #1;
    set_ds(32'h0100_0014, 8'h15);
    `CHECK(iss_imm, ds_imm, "read port imm of row 5")

    // --- writeback read port returns the opcode of row wb_ist_idx
    wb_ist_idx = 5; #1;
    set_ds(32'h0100_0014, 8'h15);
    `CHECK(wb_opcode, ds_opcode, "writeback read port opcode of row 5")
    wb_ist_idx = 2; #1;
    set_ds(32'h0100_0008, 8'h12);
    `CHECK(wb_opcode, ds_opcode, "writeback read port opcode of row 2")

    // --- writeback clears only that row
    wb_en = 1; wb_ist_idx = 2; tick; wb_en = 0;
    `CHECK(dut.valid_arr[2], 1'b0, "row 2 cleared by writeback")
    `CHECK(dut.stage_arr[2], WB, "written-back row stage = WB")
    `CHECK(count_valid(0), ROWS - 1, "ROWS-1 valid after writeback")
    `CHECK(buffer_full, 1'b0, "not full after one writeback")
    `CHECK(ds_ist_idx, 3'd2, "ds_ist_idx points at the freed row")

    // --- same-cycle dispatch (into row 2) + writeback (row 0): count unchanged
    set_ds(32'h0100_0100, 8'h20); ds_en = 1;
    wb_en = 1; wb_ist_idx = 0;
    tick; ds_en = 0; wb_en = 0;
    `CHECK(dut.valid_arr[2], 1'b1, "same-cycle dispatch allocated row 2")
    `CHECK(dut.pc_arr[2], 32'h0100_0100, "row 2 holds the new pc")
    `CHECK(dut.valid_arr[0], 1'b0, "same-cycle writeback cleared row 0")
    `CHECK(count_valid(0), ROWS - 1, "count unchanged by dispatch+writeback")

    // --- freed row reused; buffer full again
    `CHECK(ds_ist_idx, 3'd0, "next dispatch goes to freed row 0")
    dispatch(32'h0100_0104, 8'h21, row);
    `CHECK(row, 3'd0, "freed row 0 reused")
    `CHECK(buffer_full, 1'b1, "full again after reusing freed row")

    // --- two in-flight instructions with the same PC: ist_idx tells them apart
    wb_en = 1; wb_ist_idx = 1; tick; wb_ist_idx = 3; tick; wb_en = 0;
    dispatch(32'h0100_0200, 8'h30, row_a);
    dispatch(32'h0100_0200, 8'h31, row_b);
    `CHECK(row_a != row_b, 1'b1, "same-pc instructions get different rows")
    wb_en = 1; wb_ist_idx = row_a; tick; wb_en = 0;
    `CHECK(dut.valid_arr[row_a], 1'b0, "writeback of first same-pc row clears it")
    `CHECK(dut.valid_arr[row_b], 1'b1, "second same-pc row untouched")

    `TB_FINISH
  end
endmodule
