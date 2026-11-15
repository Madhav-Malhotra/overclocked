// =============================================================================
// decoder_tb - self-checking unit test for decoder.v FU classification
//
// Covers the routing decided in plan.md D7/D7a:
//   MUL -> MCM; DIV/DIVU -> ALU;
//   plus every other instruction class (ALU, imm ALU, LUI/AUIPC, load, store,
//   branch, JAL/JALR, ECALL, FENCE) and the x0 source/destination rules.
// =============================================================================
`timescale 1ns/1ps
module decoder_tb;
  `include "tb_common.vh"

  localparam NONE = 0, BRANCH = 1, MCM = 2, LOAD = 3, STORE = 4, ALU = 5;

  reg  [31:0] instr = 0;
  wire [6:0]  opcode, funct7;
  wire [4:0]  rd, rs1, rs2, shamt;
  wire [2:0]  funct3;
  wire [31:0] imm;
  wire is_u, is_j, is_i, uses_rs1, uses_rs2, writes_rd;
  wire [2:0] fu_id;

  decoder #(.FUW(3)) dut (
    .instr(instr), .opcode(opcode), .addr_rd(rd), .addr_rs1(rs1), .addr_rs2(rs2),
    .funct3(funct3), .funct7(funct7), .imm(imm), .shamt(shamt),
    .is_u_type_w(is_u), .is_j_type_w(is_j), .is_i_type_w(is_i),
    .uses_rs1(uses_rs1), .uses_rs2(uses_rs2), .writes_rd(writes_rd), .fu_id(fu_id)
  );

  // Builds an R-type instruction word: funct7 rs2 rs1 funct3 rd opcode
  function [31:0] r(input [6:0] f7, input [4:0] s2, input [4:0] s1, input [2:0] f3, input [4:0] d);
    r = {f7, s2, s1, f3, d, 7'b0110011};
  endfunction

  task expect_fu(input [31:0] in, input [2:0] exp, input [255:0] name); begin
    instr = in; #1;
    `CHECK(fu_id, exp, name)
  end endtask

  initial begin
    // --- M extension routing (D7/D7a)
    expect_fu(r(7'h01, 5'd2, 5'd1, 3'b000, 5'd3), MCM,  "MUL -> MCM");
    expect_fu(r(7'h01, 5'd2, 5'd1, 3'b100, 5'd3), ALU,  "DIV -> ALU");
    expect_fu(r(7'h01, 5'd2, 5'd1, 3'b101, 5'd3), ALU,  "DIVU -> ALU");

    // --- RV32I classes
    expect_fu(r(7'h00, 5'd2, 5'd1, 3'b000, 5'd3), ALU,   "ADD -> ALU");
    expect_fu(r(7'h20, 5'd2, 5'd1, 3'b000, 5'd3), ALU,   "SUB -> ALU");
    expect_fu(32'h00500093,                       ALU,   "ADDI -> ALU");
    expect_fu(32'h123450b7,                       ALU,   "LUI -> ALU");
    expect_fu(32'h00000397,                       ALU,   "AUIPC -> ALU");
    expect_fu(32'h0006a703,                       LOAD,  "LW -> LOAD");
    expect_fu(32'h00e6a023,                       STORE, "SW -> STORE");
    expect_fu(32'h00208663,                       BRANCH,"BEQ -> BRANCH");
    expect_fu(32'h0080006f,                       BRANCH,"JAL -> BRANCH");
    expect_fu(32'h000080e7,                       BRANCH,"JALR -> BRANCH");
    expect_fu(32'h00000073,                       ALU,   "ECALL -> ALU");
    expect_fu(32'h0ff0000f,                       NONE,  "FENCE -> NONE");

    // --- x0 rules: never a dependency, never a destination
    instr = r(7'h00, 5'd0, 5'd0, 3'b000, 5'd0); #1;
    `CHECK(uses_rs1, 1'b0, "rs1 = x0 is not a dependency")
    `CHECK(uses_rs2, 1'b0, "rs2 = x0 is not a dependency")
    `CHECK(writes_rd, 1'b0, "rd = x0 is not written")
    instr = r(7'h01, 5'd2, 5'd1, 3'b000, 5'd3); #1;
    `CHECK(uses_rs1 && uses_rs2 && writes_rd, 1'b1, "MUL uses rs1, rs2 and writes rd")

    `TB_FINISH
  end
endmodule
