// =============================================================================
// Module:      control_signals
// Description: Generates the datapath control signals for the OoO core.
//              Adapted from verilog/design/code/control_signals.v. The OoO core
//              has one instruction per stage that needs control here:
//                Execute   - the instruction being issued this cycle (one
//                            issue per cycle): ALU op and ALU input selects.
//                Branch    - the instruction in the branch FU's compare cycle
//                            (branch_comp.v): unsigned compare, taken, PC select.
//                Writeback - the instruction writing back this cycle (one per
//                            cycle): register write enable and writeback
//                            source select.
//              OoO differences from the scalar file:
//              - No pipeline registers (XM/MW): each stage's instruction is
//                given directly (issue fields from pd.v, writeback opcode from
//                instr_status).
//              - No forwarding selects (MX/WX bypass): the scoreboard forwards
//                operands through producer tags (functional_unit_status).
//              - No MUL selector: MUL runs on the MCM, array_mult.v (plan.md D7).
//                ECALL is a bubble executed as an ADD of zeros (D8).
//              - No mem_rw: the store FU (store.v) writes memory for every
//                instruction it receives.
//              - Branch controls (br_un, br_taken, pc_sel) are decoded for the
//                branch FU's compare cycle (cmp_opcode/cmp_funct3), not the
//                issue cycle. pc_sel is for the fetch redirect (plan.md
//                Phase 6; not connected yet).
// Inputs:      iss_opcode, iss_funct3, iss_funct7 - fields of the issuing instruction
//              cmp_opcode, cmp_funct3 - fields of the instruction in the branch
//                            FU's compare cycle
//              br_eq, br_lt - branch comparator results (branch_comp.v)
//              wb_opcode   - opcode of the instruction writing back
//              wb_rd       - its destination register
//              reset
// Outputs:     br_un       - unsigned compare for BLTU/BGEU
//              br_taken    - branch/jump taken
//              pc_sel      - fetch takes the branch target (Phase 6)
//              a_sel       - ALU input 1 select: REG (rs1) or PC
//              b_sel       - ALU input 2 select: REG (rs2) or IMM
//              alu_sel     - 4-bit ALU operation (encoding as in alu.v)
//              reg_wen     - register file write enable (writeback)
//              wb_sel      - 2-bit writeback source select (writeback.v)
// =============================================================================
module control_signals #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW)
)
(
    input reset,
    // fields of the instruction issued this cycle (Execute)
    input [6:0] iss_opcode,
    input [2:0] iss_funct3,
    input [6:0] iss_funct7,
    // instruction in the branch FU's compare cycle (Branch)
    input [6:0] cmp_opcode,
    input [2:0] cmp_funct3,
    // branch comparator results arrive in the branch FU's compare cycle
    input br_eq,
    input br_lt,
    // instruction writing back this cycle (Writeback)
    input [6:0] wb_opcode,
    input [ADDRW-1:0] wb_rd,
    output br_taken,
    output pc_sel,
    output br_un,
    output [1:0] a_sel,
    output [1:0] b_sel,
    output [3:0] alu_sel,
    output reg_wen,
    output [1:0] wb_sel
    // immediate select is handled inside decoder.v
);

// ====================
// PARAMETERS
// ====================

// alu_sel encoding
localparam ADD = 4'd0;
localparam SUB = 4'd1;
localparam SLL = 4'd2;
localparam SRL = 4'd3;
localparam SRA = 4'd4;
localparam SLT = 4'd5;
localparam SLTU = 4'd6;
localparam XOR = 4'd7;
localparam OR = 4'd8;
localparam AND = 4'd9;
localparam NOP = 4'd10;
// 4'd11 was MUL; multiply is handled only by the MCM functional unit (plan.md D7)
localparam DIV = 4'd12;
localparam DIVU = 4'd13;

// wb_sel encoding
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;


// ===============================
// EXECUTE STAGE CONTROL SIGNALS
// ===============================

wire is_branch_x  = (iss_opcode == 7'b1100011);
wire is_alu_x     = (iss_opcode == 7'b0110011);
wire is_alu_imm_x = (iss_opcode == 7'b0010011);
wire is_jal_x     = (iss_opcode == 7'b1101111);
wire is_auipc_x   = (iss_opcode == 7'b0010111);
wire is_lui_x     = (iss_opcode == 7'b0110111);
wire is_load_x    = (iss_opcode == 7'b0000011);
wire is_store_x   = (iss_opcode == 7'b0100011);
wire is_jalr_x    = (iss_opcode == 7'b1100111);
wire is_ecall_x   = (iss_opcode == 7'b1110011);  // bubble: ADD of x0 and imm 0 (D8)

// A sel definitions (ALU input 1)
localparam REG = 2'b00;
localparam PC  = 2'b01;

// B sel definitions (ALU input 2)
localparam IMM  = 2'b01;

// ==========================
// ALU INPUT SELECTS
// ==========================

// Branches, AUIPC and JAL use PC (target = pc + imm); everything else uses rs1
assign a_sel = (is_branch_x || is_auipc_x || is_jal_x) ? PC : REG;
// only R-type (ALU reg-reg) uses rs2; all others use an immediate
assign b_sel = (!is_alu_x) ? IMM : REG;

// LUI passes B (immediate) through unchanged; all other non-ALU ops use ADD for address/target computation
assign alu_sel =    (is_lui_x) ? NOP :
                    (is_auipc_x || is_jal_x || is_jalr_x || is_load_x || is_store_x || is_branch_x || is_ecall_x) ? ADD :
                    // RISC-V m-extension instructions (no MUL: D7):
                    (is_alu_x && iss_funct7 == 'h01) ?
                        ((iss_funct3 == 'h4) ? DIV :
                        (iss_funct3 == 'h5) ? DIVU :
                    NOP) :
                    (is_alu_x && iss_funct7 == 'h20) ? ((iss_funct3 == 'h0) ? SUB : SRA) :
                    (is_alu_x || is_alu_imm_x) ?
                        ((iss_funct3 == 'h0) ? ADD :
                        (iss_funct3 == 'h1) ? SLL :
                        (iss_funct3 == 'h2) ? SLT :
                        (iss_funct3 == 'h3) ? SLTU :
                        (iss_funct3 == 'h4) ? XOR :
                        (iss_funct3 == 'h5 && iss_funct7 == 'h0) ? SRL :
                        (iss_funct3 == 'h5 && iss_funct7 == 'h20) ? SRA :
                        (iss_funct3 == 'h6) ? OR :
                        (iss_funct3 == 'h7) ? AND :
                        NOP) // invalid funct3 for ALU
                    : NOP;  // invalid opcode

// ===============================
// BRANCH CONTROL SIGNALS (branch FU compare cycle)
// ===============================

wire is_branch_c = (cmp_opcode == 7'b1100011);
wire is_jal_c    = (cmp_opcode == 7'b1101111);
wire is_jalr_c   = (cmp_opcode == 7'b1100111);

// JAL/JALR always jump; conditional branches jump when their condition holds
wire branch_taken = (is_branch_c && (
    (cmp_funct3 == 'h0 && br_eq) ||               // BEQ
    (cmp_funct3 == 'h1 && !br_eq) ||              // BNE
    (cmp_funct3 == 'h4 && br_lt) ||               // BLT
    (cmp_funct3 == 'h5 && !br_lt) ||              // BGE
    (cmp_funct3 == 'h6 && br_lt) ||               // BLTU
    (cmp_funct3 == 'h7 && !br_lt))                // BGEU
) || is_jal_c || is_jalr_c;

// unsigned comparison for BLTU/BGEU
assign br_un = is_branch_c && (cmp_funct3 == 'h6 || cmp_funct3 == 'h7);

assign br_taken = branch_taken;
assign pc_sel = branch_taken || is_jal_c || is_jalr_c;

// ===================================
// WRITEBACK STAGE CONTROL SIGNALS
// ===================================

wire is_store_wb  = (wb_opcode == 7'b0100011);
wire is_branch_wb = (wb_opcode == 7'b1100011);
wire is_load_wb   = (wb_opcode == 7'b0000011);
wire is_jal_wb    = (wb_opcode == 7'b1101111);
wire is_jalr_wb   = (wb_opcode == 7'b1100111);
wire is_ecall_wb  = (wb_opcode == 7'b1110011);
wire is_nop       = (wb_opcode == 7'b0);
// stores, branches, ecalls, NOPs, reset, and writes to x0 all suppress the register write
assign reg_wen = !(is_store_wb || is_branch_wb || is_ecall_wb || is_nop || reset || wb_rd == 0);

// loads read from memory; JAL/JALR write PC+4; everything else writes the ALU result
assign wb_sel = (is_load_wb) ? WB_MEM :
                (is_jal_wb || is_jalr_wb) ? WB_PC4 :
                WB_ALU;

endmodule
