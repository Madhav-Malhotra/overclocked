// =============================================================================
// branch_comp_tb - self-checking unit test for branch_comp.v (the branch
// functional unit, with control_signals.v as connected in pd.v)
//
// Gives each branch/jump to the FU (ex_valid = EX cycle 1) with the
// operands pd.v gives it (idata1/idata2 = rs1/rs2 values, target_in1/
// target_in2 from the a_sel/b_sel mux) and checks the timing - EX cycle 1 (address): the target adder;
// EX cycle 2 (compare): cmp_opcode/cmp_funct3 present the instruction to
// control_signals and rs1 and rs2 are compared - then that taken and
// target are registered (result_valid) and held (fu_ready low) until wb_ready.
// Covers: BEQ/BNE/BLT/BGE/BLTU/BGEU taken and not taken (signed vs unsigned
// with a negative operand), negative branch offset, JAL (always taken,
// pc + imm), JALR (always taken, (rs1 + imm) with bit 0 cleared).
// =============================================================================
`timescale 1ns/1ps
module branch_comp_tb;
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

  localparam OP_BRANCH = 7'h63, OP_JAL = 7'h6F, OP_JALR = 7'h67;               // opcodes
  localparam BEQ = 3'h0, BNE = 3'h1, BLT = 3'h4, BGE = 3'h5, BLTU = 3'h6, BGEU = 3'h7;  // funct3
  localparam REG = 2'b00;                                                      // a_sel / b_sel REG

  reg clock = 0, reset = 1;
  reg        ex_valid = 0;
  reg [31:0] rs1_data = 0, rs2_data = 0, imm = 0, pc = 0;
  reg [6:0]  opcode = 0;
  reg [2:0]  funct3 = 0;
  reg        wb_ready = 0;
  wire       fu_ready, result_valid, taken;
  wire [31:0] target;
  wire [6:0] cmp_opcode;
  wire [2:0] cmp_funct3;
  wire       br_un, br_eq, br_lt, br_taken, pc_sel;
  wire [1:0] a_sel, b_sel, wb_sel;
  wire [3:0] alu_sel;
  wire       reg_wen;
  // ALU input mux as in pd.v (a_sel/b_sel decoded for the issuing instruction)
  wire [31:0] target_in1 = (a_sel == REG) ? rs1_data : pc;
  wire [31:0] target_in2 = (b_sel == REG) ? rs2_data : imm;

  control_signals ctrl (
    .reset(reset), .iss_opcode(opcode), .iss_funct3(funct3), .iss_funct7(7'h00),
    .cmp_opcode(cmp_opcode), .cmp_funct3(cmp_funct3), .br_eq(br_eq), .br_lt(br_lt),
    .wb_opcode(7'h00), .wb_rd(5'd0),
    .br_taken(br_taken), .pc_sel(pc_sel), .br_un(br_un),
    .a_sel(a_sel), .b_sel(b_sel), .alu_sel(alu_sel), .reg_wen(reg_wen), .wb_sel(wb_sel));

  branch_comp dut (
    .clock(clock), .reset(reset),
    .ex_valid(ex_valid), .idata1(rs1_data), .idata2(rs2_data), .target_in1(target_in1), .target_in2(target_in2),
    .opcode(opcode), .funct3(funct3), .fu_ready(fu_ready),
    .cmp_opcode(cmp_opcode), .cmp_funct3(cmp_funct3), .br_un(br_un), .br_eq(br_eq), .br_lt(br_lt),
    .br_taken(br_taken),
    .result_valid(result_valid), .taken(taken), .target(target), .wb_ready(wb_ready));

  always #5 clock = ~clock;
  task tick; begin @(posedge clock); #1; end endtask

  // Hand one branch/jump to the FU, check timing and outcome, then writeback takes it
  task run(input [6:0] op, input [2:0] f3, input [31:0] a, input [31:0] b, input [31:0] offset,
           input [31:0] at_pc, input exp_taken, input [31:0] exp_target, input [255:0] msg);
    begin
      `CHECK(fu_ready, 1'b1, "branch FU ready before issue")
      opcode = op; funct3 = f3; rs1_data = a; rs2_data = b; imm = offset; pc = at_pc;
      ex_valid = 1; #1;
      `CHECK(result_valid, 1'b0, "EX cycle 1 (address): no outcome yet")
      tick; ex_valid = 0;
      opcode = 7'h33; rs1_data = 32'hDEAD_BEEF; rs2_data = 32'h0; pc = 32'h0;   // registered values must be used
      `CHECK(fu_ready, 1'b0, "branch FU not ready in its compare cycle")
      `CHECK(cmp_opcode, op, "EX cycle 2 (compare): instruction presented to control_signals")
      `CHECK(cmp_funct3, f3, "EX cycle 2 (compare): funct3 presented to control_signals")
      `CHECK(result_valid, 1'b0, "EX cycle 2 (compare): no outcome yet")
      tick;
      `CHECK(result_valid, 1'b1, "outcome valid after the compare cycle")
      `CHECK(taken, exp_taken, msg)
      `CHECK(target, exp_target, msg)
      `CHECK(fu_ready, 1'b0, "branch FU not ready while it holds an outcome")
      tick;
      `CHECK(taken, exp_taken, "outcome held until writeback")
      wb_ready = 1; tick; wb_ready = 0;
      `CHECK(result_valid, 1'b0, "result_valid cleared by wb_ready")
    end
  endtask

  initial begin
    tick; tick; reset = 0; tick;
    `CHECK(result_valid, 1'b0, "no outcome after reset")

    // --- conditional branches (target = pc + imm)
    run(OP_BRANCH, BEQ,  32'd5,         32'd5,  32'h10,        32'h0100_0100, 1, 32'h0100_0110, "BEQ taken");
    run(OP_BRANCH, BEQ,  32'd5,         32'd6,  32'h10,        32'h0100_0100, 0, 32'h0100_0110, "BEQ not taken");
    run(OP_BRANCH, BNE,  32'd5,         32'd6,  32'h10,        32'h0100_0100, 1, 32'h0100_0110, "BNE taken");
    run(OP_BRANCH, BNE,  32'd5,         32'd5,  32'h10,        32'h0100_0100, 0, 32'h0100_0110, "BNE not taken");
    run(OP_BRANCH, BLT,  32'hFFFF_FFFF, 32'd1,  32'hFFFF_FFF8, 32'h0100_0100, 1, 32'h0100_00F8, "BLT taken (-1 < 1), negative offset");
    run(OP_BRANCH, BLT,  32'd1,         32'hFFFF_FFFF, 32'h8,  32'h0100_0100, 0, 32'h0100_0108, "BLT not taken (1 !< -1)");
    run(OP_BRANCH, BGE,  32'd1,         32'hFFFF_FFFF, 32'h8,  32'h0100_0100, 1, 32'h0100_0108, "BGE taken (1 >= -1)");
    run(OP_BRANCH, BGE,  32'hFFFF_FFFF, 32'd1,  32'h8,         32'h0100_0100, 0, 32'h0100_0108, "BGE not taken");
    run(OP_BRANCH, BLTU, 32'd1,         32'hFFFF_FFFF, 32'h8,  32'h0100_0100, 1, 32'h0100_0108, "BLTU taken (1 < 0xffffffff)");
    run(OP_BRANCH, BLTU, 32'hFFFF_FFFF, 32'd1,  32'h8,         32'h0100_0100, 0, 32'h0100_0108, "BLTU not taken");
    run(OP_BRANCH, BGEU, 32'hFFFF_FFFF, 32'd1,  32'h8,         32'h0100_0100, 1, 32'h0100_0108, "BGEU taken");
    run(OP_BRANCH, BGEU, 32'd1,         32'hFFFF_FFFF, 32'h8,  32'h0100_0100, 0, 32'h0100_0108, "BGEU not taken");

    // --- jumps: always taken
    run(OP_JAL,  3'h0, 32'h1234,      32'h0,  32'h0000_0800, 32'h0100_0040, 1, 32'h0100_0840, "JAL target = pc + imm");
    run(OP_JALR, 3'h0, 32'h0100_0201, 32'h0,  32'h0000_0004, 32'h0100_0040, 1, 32'h0100_0204, "JALR target = (rs1 + imm) & ~1");

    `TB_FINISH
  end
endmodule
