// =============================================================================
// reg_status_table_tb - self-checking unit test for reg_status_table.v
//
// Covers: reset clears every entry; dispatch write maps rd -> producer FU id;
// combinational rd/rs1/rs2 lookups; writeback clear; same-cycle clear + write
// of the same register (the dispatch write must win).
// =============================================================================
`timescale 1ns/1ps
module reg_status_table_tb;
  `include "tb_common.vh"

  localparam FUW = 3;

  reg clock = 0, reset = 1;
  reg [4:0] ds_check_rd = 0, ds_check_rs1 = 0, ds_check_rs2 = 0;
  reg ds_write_enable = 0;
  reg [4:0] ds_reg_id_in = 0;
  reg [FUW-1:0] ds_fu_id_in = 0;
  reg wb_clear_enable = 0;
  reg [4:0] wb_clear_id = 0;
  wire [FUW-1:0] ds_fu_id_out, ds_fu_id_out_rs1, ds_fu_id_out_rs2;

  reg_status_table #(.FUW(FUW), .NUM_LOAD_STORE(1)) dut (
    .clock(clock), .reset(reset),
    .ds_check_rd(ds_check_rd), .ds_check_rs1(ds_check_rs1), .ds_check_rs2(ds_check_rs2),
    .ds_write_enable(ds_write_enable), .ds_reg_id_in(ds_reg_id_in), .ds_fu_id_in(ds_fu_id_in),
    .wb_clear_enable(wb_clear_enable), .wb_clear_id(wb_clear_id),
    .ds_fu_id_out(ds_fu_id_out), .ds_fu_id_out_rs1(ds_fu_id_out_rs1), .ds_fu_id_out_rs2(ds_fu_id_out_rs2)
  );

  always #5 clock = ~clock;

  task tick; begin @(posedge clock); #1; end endtask

  task dispatch(input [4:0] rd, input [FUW-1:0] fu); begin
    ds_write_enable = 1; ds_reg_id_in = rd; ds_fu_id_in = fu; tick; ds_write_enable = 0;
  end endtask

  task wb_clear(input [4:0] rd); begin
    wb_clear_enable = 1; wb_clear_id = rd; tick; wb_clear_enable = 0;
  end endtask

  integer r;
  initial begin
    // --- reset clears all entries
    tick; tick; reset = 0; tick;
    for (r = 0; r < 32; r = r + 1) begin
      ds_check_rd = r; #1;
      `CHECK(ds_fu_id_out, 0, "entry clear after reset")
    end

    // --- dispatch writes, lookups on all three ports
    dispatch(5'd3, 3'd5);   // x3 <- ALU
    dispatch(5'd7, 3'd2);   // x7 <- MCM
    ds_check_rd = 3; ds_check_rs1 = 7; ds_check_rs2 = 4; #1;
    `CHECK(ds_fu_id_out,     5, "rd lookup x3 -> ALU")
    `CHECK(ds_fu_id_out_rs1, 2, "rs1 lookup x7 -> MCM")
    `CHECK(ds_fu_id_out_rs2, 0, "rs2 lookup x4 -> none")

    // --- writeback clear
    wb_clear(5'd3);
    ds_check_rd = 3; #1;
    `CHECK(ds_fu_id_out, 0, "x3 cleared by writeback")
    ds_check_rd = 7; #1;
    `CHECK(ds_fu_id_out, 2, "x7 untouched by x3 clear")

    // --- same-cycle clear (old producer) + dispatch write (new producer): write wins
    ds_write_enable = 1; ds_reg_id_in = 7; ds_fu_id_in = 6;
    wb_clear_enable = 1; wb_clear_id = 7;
    tick;
    ds_write_enable = 0; wb_clear_enable = 0;
    ds_check_rd = 7; #1;
    `CHECK(ds_fu_id_out, 6, "same-cycle clear+write: new producer kept")

    // --- reset mid-run clears again
    reset = 1; tick; reset = 0; #1;
    ds_check_rd = 7; #1;
    `CHECK(ds_fu_id_out, 0, "reset clears x7")

    `TB_FINISH
  end
endmodule
