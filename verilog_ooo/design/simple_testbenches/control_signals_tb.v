// =============================================================================
// control_signals_tb - self-checking unit test for control_signals.v
//
// Execute controls (issuing instruction): alu_sel, a_sel, b_sel for every
// instruction class the ALU executes - R-type and I-type ALU ops (incl.
// SUB/SRA/SRAI via funct7), LUI, AUIPC, DIV/DIVU, ECALL (ADD of zeros, D8) -
// and the PC/IMM selects for branches, JAL, JALR, loads, stores.
// Branch controls (instruction in the branch FU's compare cycle): br_un for
// BLTU/BGEU only; br_taken / pc_sel for every B-type condition with the
// comparator results that make it taken and not taken; JAL/JALR always taken;
// non-branch instructions never taken.
// Writeback controls (instruction writing back): reg_wen and wb_sel for
// ALU, load, store, branch, JAL/JALR, ECALL, writes to x0, and reset.
// =============================================================================
`timescale 1ns/1ps
module control_signals_tb;
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

  localparam ADD = 0, SUB = 1, SLL = 2, SRL = 3, SRA = 4, SLT = 5, SLTU = 6,
             XOR = 7, OR = 8, AND = 9, NOP = 10, DIV = 12, DIVU = 13;   // alu_sel (as in alu.v)
  localparam REG = 2'b00, PC = 2'b01, IMM = 2'b01;                      // a_sel / b_sel
  localparam WB_MEM = 2'd0, WB_ALU = 2'd1, WB_PC4 = 2'd2;               // wb_sel
  localparam OP_R = 7'h33, OP_I = 7'h13, OP_LUI = 7'h37, OP_AUIPC = 7'h17, OP_ECALL = 7'h73,
             OP_LOAD = 7'h03, OP_STORE = 7'h23, OP_BRANCH = 7'h63, OP_JAL = 7'h6F, OP_JALR = 7'h67;  // opcodes

  reg        reset = 0;
  reg [6:0]  iss_opcode = 0;
  reg [2:0]  iss_funct3 = 0;
  reg [6:0]  iss_funct7 = 0;
  reg [6:0]  wb_opcode = 0;
  reg [4:0]  wb_rd = 0;
  reg [6:0]  cmp_opcode = 0;    // branch FU compare-cycle instruction
  reg [2:0]  cmp_funct3 = 0;
  reg        br_eq = 0, br_lt = 0;
  wire [1:0] a_sel, b_sel, wb_sel;
  wire [3:0] alu_sel;
  wire       reg_wen, br_taken, pc_sel, br_un;

  control_signals dut (
    .reset(reset), .iss_opcode(iss_opcode), .iss_funct3(iss_funct3), .iss_funct7(iss_funct7),
    .cmp_opcode(cmp_opcode), .cmp_funct3(cmp_funct3), .br_eq(br_eq), .br_lt(br_lt),
    .wb_opcode(wb_opcode), .wb_rd(wb_rd),
    .br_taken(br_taken), .pc_sel(pc_sel), .br_un(br_un),
    .a_sel(a_sel), .b_sel(b_sel), .alu_sel(alu_sel), .reg_wen(reg_wen), .wb_sel(wb_sel));

  // Execute controls for one issuing instruction
  task ex(input [6:0] op, input [2:0] f3, input [6:0] f7,
          input [3:0] exp_alu, input [1:0] exp_a, input [1:0] exp_b, input [255:0] msg);
    begin
      iss_opcode = op; iss_funct3 = f3; iss_funct7 = f7; #1;
      `CHECK(alu_sel, exp_alu, msg)
      `CHECK(a_sel, exp_a, msg)
      `CHECK(b_sel, exp_b, msg)
    end
  endtask

  // Writeback controls for one instruction writing back
  task wb(input [6:0] op, input [4:0] rd, input exp_wen, input [1:0] exp_sel, input [255:0] msg);
    begin
      wb_opcode = op; wb_rd = rd; #1;
      `CHECK(reg_wen, exp_wen, msg)
      if (exp_wen) `CHECK(wb_sel, exp_sel, msg)
    end
  endtask

  // Branch controls for the compare-cycle instruction with comparator results eq/lt
  task br(input [6:0] op, input [2:0] f3, input eq, input lt, input exp_un, input exp_taken,
          input [255:0] msg);
    begin
      cmp_opcode = op; cmp_funct3 = f3; br_eq = eq; br_lt = lt; #1;
      `CHECK(br_un, exp_un, msg)
      `CHECK(br_taken, exp_taken, msg)
      `CHECK(pc_sel, exp_taken, msg)
    end
  endtask

  initial begin
    // --- branch controls (compare cycle)
    br(OP_BRANCH, 3'h0, 1, 0, 0, 1, "BEQ taken when eq");
    br(OP_BRANCH, 3'h0, 0, 1, 0, 0, "BEQ not taken when !eq");
    br(OP_BRANCH, 3'h1, 0, 0, 0, 1, "BNE taken when !eq");
    br(OP_BRANCH, 3'h1, 1, 0, 0, 0, "BNE not taken when eq");
    br(OP_BRANCH, 3'h4, 0, 1, 0, 1, "BLT taken when lt (signed)");
    br(OP_BRANCH, 3'h4, 1, 0, 0, 0, "BLT not taken when !lt");
    br(OP_BRANCH, 3'h5, 0, 0, 0, 1, "BGE taken when !lt");
    br(OP_BRANCH, 3'h5, 0, 1, 0, 0, "BGE not taken when lt");
    br(OP_BRANCH, 3'h6, 0, 1, 1, 1, "BLTU taken when lt, unsigned compare");
    br(OP_BRANCH, 3'h6, 0, 0, 1, 0, "BLTU not taken when !lt");
    br(OP_BRANCH, 3'h7, 1, 0, 1, 1, "BGEU taken when !lt, unsigned compare");
    br(OP_BRANCH, 3'h7, 0, 1, 1, 0, "BGEU not taken when lt");
    br(OP_JAL,    3'h0, 0, 0, 0, 1, "JAL always taken");
    br(OP_JALR,   3'h0, 0, 0, 0, 1, "JALR always taken");
    br(OP_R,      3'h0, 1, 1, 0, 0, "non-branch never taken");

    // --- R-type
    ex(OP_R, 3'h0, 7'h00, ADD,  REG, REG, "ADD");
    ex(OP_R, 3'h0, 7'h20, SUB,  REG, REG, "SUB");
    ex(OP_R, 3'h1, 7'h00, SLL,  REG, REG, "SLL");
    ex(OP_R, 3'h2, 7'h00, SLT,  REG, REG, "SLT");
    ex(OP_R, 3'h3, 7'h00, SLTU, REG, REG, "SLTU");
    ex(OP_R, 3'h4, 7'h00, XOR,  REG, REG, "XOR");
    ex(OP_R, 3'h5, 7'h00, SRL,  REG, REG, "SRL");
    ex(OP_R, 3'h5, 7'h20, SRA,  REG, REG, "SRA");
    ex(OP_R, 3'h6, 7'h00, OR,   REG, REG, "OR");
    ex(OP_R, 3'h7, 7'h00, AND,  REG, REG, "AND");
    ex(OP_R, 3'h4, 7'h01, DIV,  REG, REG, "DIV");
    ex(OP_R, 3'h5, 7'h01, DIVU, REG, REG, "DIVU");
    // --- I-type (funct7 field = imm[11:5]; only shifts use it)
    ex(OP_I, 3'h0, 7'h7F, ADD,  REG, IMM, "ADDI (negative imm, not SUB)");
    ex(OP_I, 3'h2, 7'h00, SLT,  REG, IMM, "SLTI");
    ex(OP_I, 3'h3, 7'h00, SLTU, REG, IMM, "SLTIU");
    ex(OP_I, 3'h4, 7'h00, XOR,  REG, IMM, "XORI");
    ex(OP_I, 3'h6, 7'h00, OR,   REG, IMM, "ORI");
    ex(OP_I, 3'h7, 7'h00, AND,  REG, IMM, "ANDI");
    ex(OP_I, 3'h1, 7'h00, SLL,  REG, IMM, "SLLI");
    ex(OP_I, 3'h5, 7'h00, SRL,  REG, IMM, "SRLI");
    ex(OP_I, 3'h5, 7'h20, SRA,  REG, IMM, "SRAI");
    // --- U-type, ECALL
    ex(OP_LUI,   3'h0, 7'h00, NOP, REG, IMM, "LUI passes imm");
    ex(OP_AUIPC, 3'h0, 7'h00, ADD, PC,  IMM, "AUIPC = pc + imm");
    ex(OP_ECALL, 3'h0, 7'h00, ADD, REG, IMM, "ECALL = x0 + imm 0 (D8)");
    // --- address / target computations
    ex(OP_LOAD,   3'h2, 7'h00, ADD, REG, IMM, "load address = rs1 + imm");
    ex(OP_STORE,  3'h2, 7'h00, ADD, REG, IMM, "store address = rs1 + imm");
    ex(OP_BRANCH, 3'h0, 7'h00, ADD, PC,  IMM, "branch target = pc + imm");
    ex(OP_JAL,    3'h0, 7'h00, ADD, PC,  IMM, "JAL target = pc + imm");
    ex(OP_JALR,   3'h0, 7'h00, ADD, REG, IMM, "JALR target = rs1 + imm");

    // --- writeback controls
    wb(OP_R,      5'd5, 1, WB_ALU, "R-type writes the ALU result");
    wb(OP_I,      5'd5, 1, WB_ALU, "I-type writes the ALU result");
    wb(OP_LUI,    5'd5, 1, WB_ALU, "LUI writes the ALU result");
    wb(OP_AUIPC,  5'd5, 1, WB_ALU, "AUIPC writes the ALU result");
    wb(OP_LOAD,   5'd5, 1, WB_MEM, "load writes memory data");
    wb(OP_JAL,    5'd1, 1, WB_PC4, "JAL writes pc+4");
    wb(OP_JALR,   5'd1, 1, WB_PC4, "JALR writes pc+4");
    wb(OP_STORE,  5'd5, 0, WB_ALU, "store writes no register");
    wb(OP_BRANCH, 5'd5, 0, WB_ALU, "branch writes no register");
    wb(OP_ECALL,  5'd0, 0, WB_ALU, "ECALL writes no register");
    wb(OP_R,      5'd0, 0, WB_ALU, "write to x0 suppressed");
    reset = 1;
    wb(OP_R,      5'd5, 0, WB_ALU, "no register write during reset");

    `TB_FINISH
  end
endmodule
