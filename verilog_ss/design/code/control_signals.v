// =============================================================================
// Module:      control_signals
// Description: Generates all datapath control signals for the RV32I pipeline.
//              Decodes opcode/funct3/funct7 from the DX stage and produces
//              ALU op, branch logic, memory R/W, register write-enable, and
//              writeback select. Also computes MX/WX forwarding selects for
//              ALU inputs and the branch comparator.
// Inputs:      clock, reset
//              dx_en, xm_en, mw_en - pipeline stage enables (for internal regs)
//              opcode_dx/xm/mw     - opcodes of instructions in each stage
//              funct3, funct7      - function codes of the DX instruction
//              br_eq, br_lt        - branch comparator outputs
//              addr_rs1_dx, addr_rs2_dx - source register addresses in DX
//              addr_rd_xm, addr_rd_mw   - destination register addresses in XM/MW
// Outputs:     pc_sel, br_un, br_taken
//              a_sel, b_sel            - ALU input forwarding selects (2-bit)
//              branch_comp_data1/2_sel - branch comparator forwarding selects
//              alu_sel                 - 4-bit ALU operation
//              mem_rw                  - data memory write enable
//              reg_wen                 - register file write enable
//              wb_sel                  - 2-bit writeback source select
// =============================================================================
module control_signals #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW)
)
(
    input clock,
    input reset,
    input [6:0] opcode_dx_0,
    input [6:0] opcode_xm_0,
    input [6:0] opcode_mw_0,
    // funct3/funct7 are sampled from the DX pipeline register
    input [2:0] funct3_0,
    input [6:0] funct7_0,
    // branch comparator results arrive in the Execute stage
    input br_eq_0,
    input br_lt_0,
    input [ADDRW-1:0] addr_rs1_dx_0,
    input [ADDRW-1:0] addr_rs2_dx_0,
    input [ADDRW-1:0] addr_rd_xm_0,
    input [ADDRW-1:0] addr_rd_mw_0,
    output [2:0] branch_comp_data1_sel_0,
    output [2:0] branch_comp_data2_sel_0,
    // br_taken exposed for use in test harness
    output br_taken_0,
    output pc_sel_0,
    output br_un_0,
    output [2:0] a_sel_0,
    output [2:0] b_sel_0,
    output [3:0] alu_sel_0,
    output mem_rw_0,
    output reg_wen_0,
    output [1:0] wb_sel_0,
    // immediate select is handled inside decoder.v


    //way 1
    input [6:0] opcode_dx_1,
    input [6:0] opcode_xm_1,
    input [6:0] opcode_mw_1,
    // funct3/funct7 are sampled from the DX pipeline register
    input [2:0] funct3_1,
    input [6:0] funct7_1,
    // branch comparator results arrive in the Execute stage
    input br_eq_1,
    input br_lt_1,
    input [ADDRW-1:0] addr_rs1_dx_1,
    input [ADDRW-1:0] addr_rs2_dx_1,
    input [ADDRW-1:0] addr_rd_xm_1,
    input [ADDRW-1:0] addr_rd_mw_1,
    // used to check case 2 of forwarding for way 1
    input [DATAW-1:0] m_pc_0, 
    input [DATAW-1:0] x_pc_1, 
    output [2:0] branch_comp_data1_sel_1,
    output [2:0] branch_comp_data2_sel_1,
    // br_taken exposed for use in test harness
    output br_taken_1,
    output pc_sel_1,
    output br_un_1,
    output [2:0] a_sel_1,
    output [2:0] b_sel_1,
    output [3:0] alu_sel_1,
    output mem_rw_1,
    output reg_wen_1,
    output [1:0] wb_sel_1
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
localparam MUL = 4'd11;
localparam DIV = 4'd12;
localparam DIVU = 4'd13;

// wb_sel encoding
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;


// ===============================
// EXECUTE STAGE CONTROL SIGNALS
// ===============================

 /* Determine instruction type */
    // way 0
wire is_branch_x_0  = (opcode_dx_0 == 7'b1100011);
wire is_alu_x_0     = (opcode_dx_0 == 7'b0110011);
wire is_alu_imm_x_0 = (opcode_dx_0 == 7'b0010011);
wire is_jal_x_0     = (opcode_dx_0 == 7'b1101111);
wire is_auipc_x_0   = (opcode_dx_0 == 7'b0010111);
wire is_lui_x_0     = (opcode_dx_0 == 7'b0110111);
wire is_load_x_0    = (opcode_dx_0 == 7'b0000011);
wire is_store_x_0   = (opcode_dx_0 == 7'b0100011);
wire is_jalr_x_0    = (opcode_dx_0 == 7'b1100111);
wire is_ecall_x_0   = (opcode_dx_0 == 7'b1110011);
wire is_u_type_x_0  = is_lui_x_0 || is_auipc_x_0;

    // way 1
wire is_branch_x_1  = (opcode_dx_1 == 7'b1100011);
wire is_alu_x_1     = (opcode_dx_1 == 7'b0110011); // is R-type instruction
wire is_alu_imm_x_1 = (opcode_dx_1 == 7'b0010011);
wire is_jal_x_1     = (opcode_dx_1 == 7'b1101111);
wire is_auipc_x_1   = (opcode_dx_1 == 7'b0010111);
wire is_lui_x_1     = (opcode_dx_1 == 7'b0110111);
wire is_load_x_1    = (opcode_dx_1 == 7'b0000011);
wire is_store_x_1   = (opcode_dx_1 == 7'b0100011);
wire is_jalr_x_1    = (opcode_dx_1 == 7'b1100111);
wire is_ecall_x_1   = (opcode_dx_1 == 7'b1110011);
wire is_u_type_x_1  = is_lui_x_1 || is_auipc_x_1;

wire stall_occured = (x_pc_1 - m_pc_0 == 4);  // ONCE STALLING LOGIC IS CONFIRMED, USE THAT INSTEAD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


/* Determine if branch is taken */
// JAL/JALR always jump; conditional branches jump when their condition holds

    // way 0
wire branch_taken_0 = (is_branch_x_0 && (
    (funct3_0 == 'h0 && br_eq_0) ||               // BEQ
    (funct3_0 == 'h1 && !br_eq_0) ||              // BNE
    (funct3_0 == 'h4 && br_lt_0) ||               // BLT
    (funct3_0 == 'h5 && !br_lt_0) ||              // BGE
    (funct3_0 == 'h6 && br_lt_0) ||               // BLTU
    (funct3_0 == 'h7 && !br_lt_0))                // BGEU
) || is_jal_x_0 || is_jalr_x_0;

// unsigned comparison for BLTU/BGEU
assign br_un_0 = is_branch_x_0 && (funct3_0 == 'h6 || funct3_0 == 'h7);

    // way 1
wire branch_taken_1 = (is_branch_x_1 && (
    (funct3_1 == 'h0 && br_eq_1) ||               // BEQ
    (funct3_1 == 'h1 && !br_eq_1) ||              // BNE
    (funct3_1 == 'h4 && br_lt_1) ||               // BLT
    (funct3_1 == 'h5 && !br_lt_1) ||              // BGE
    (funct3_1 == 'h6 && br_lt_1) ||               // BLTU
    (funct3_1 == 'h7 && !br_lt_1))                // BGEU
) || is_jal_x_1 || is_jalr_x_1;

// unsigned comparison for BLTU/BGEU
assign br_un_1 = is_branch_x_1 && (funct3_1 == 'h6 || funct3_1 == 'h7);

/* Determine if bypass required */

// A sel definitions (ALU input 1)
localparam REG = 3'b000;
localparam PC  = 3'b001;
localparam WX_BYPASS_0 = 3'b010;
localparam WX_BYPASS_1 = 3'b011;
localparam MX_BYPASS_0 = 3'b100;
localparam MX_BYPASS_1 = 3'b101;


// B sel definitions (ALU input 2)
localparam IMM  = 3'b001;

// XM stage pipeline registers
    // way 0
reg is_store_xm_r_0;
reg is_load_xm_r_0;
reg is_jal_xm_r_0;
reg is_jalr_xm_r_0;
reg is_branch_xm_r_0;
reg is_ecall_xm_r_0;

    // way 1
reg is_store_xm_r_1;
reg is_load_xm_r_1;
reg is_jal_xm_r_1;
reg is_jalr_xm_r_1;
reg is_branch_xm_r_1;
reg is_ecall_xm_r_1;

// MW stage pipeline registers
    // way 0
reg is_store_mw_r_0;
reg is_branch_mw_r_0;
reg is_ecall_mw_r_0;
reg is_load_mw_r_0;
reg is_jal_mw_r_0;
reg is_jalr_mw_r_0;

    // way 1
reg is_store_mw_r_1;
reg is_branch_mw_r_1;
reg is_ecall_mw_r_1;
reg is_load_mw_r_1;
reg is_jal_mw_r_1;
reg is_jalr_mw_r_1;


//way 0
// stores, branches, and ecalls never produce a register result; x0 writes are also suppressed
wire insn_xm_writes_reg_0 = !(is_store_xm_r_0 || is_branch_xm_r_0 || is_ecall_xm_r_0) && (addr_rd_xm_0 != 0);
wire insn_mw_writes_reg_0 = !(is_store_mw_r_0 || is_branch_mw_r_0 || is_ecall_mw_r_0) && (addr_rd_mw_0 != 0);

//way 1
// stores, branches, and ecalls never produce a register result; x0 writes are also suppressed
wire insn_xm_writes_reg_1 = !(is_store_xm_r_1 || is_branch_xm_r_1 || is_ecall_xm_r_1) && (addr_rd_xm_1 != 0);
wire insn_mw_writes_reg_1 = !(is_store_mw_r_1 || is_branch_mw_r_1 || is_ecall_mw_r_1) && (addr_rd_mw_1 != 0);

// ==========================
// FORWARDING / MUX SELECTS
// ==========================

/* 
    ALU: A and B select (including forwarding)
*/

// way 0
    // U-type and JAL use PC, not rs1; bypass only applies when rs1 is actually read
assign a_sel_0 = (is_branch_x_0 || is_auipc_x_0 || is_jal_x_0) ? PC :
               (!is_u_type_x_0 && addr_rs1_dx_0 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
               (!is_u_type_x_0 && addr_rs1_dx_0 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
               (!is_u_type_x_0 && addr_rs1_dx_0 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
               (!is_u_type_x_0 && addr_rs1_dx_0 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                REG;
    // bypass on b_sel only applies to R-type (ALU reg-reg); all others use an immediate
assign b_sel_0 = (is_alu_x_0 && addr_rs2_dx_0 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
                 (is_alu_x_0 && addr_rs2_dx_0 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                 (is_alu_x_0 && addr_rs2_dx_0 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                 (is_alu_x_0 && addr_rs2_dx_0 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 1 - WX
                 (!is_alu_x_0) ? IMM : // if not R-type, use the immediate
                    REG; // default, use decoded rs2 value

// way 1
/* 
CASE 1: way 0 and way 1 don't have the same rd --> follow same bypassing logic as way 1
CASE 2: way 0 and way 1 have same rd --> way 1 must stall, and in next cycle, can now do an MX bypass from way 0 to way 1
    - Can check if case 2 occured by comparing pc values of way 0 in memory and way 1 in execute, x_pc_1 - m_pc_0 = 4 bytes, we can do MX bypass  
*/
assign a_sel_1 = (is_branch_x_1 || is_auipc_x_1 || is_jal_x_1) ? PC :
                (stall_occured && !(is_u_type_x_1 || is_jal_x_1)) ?
                // Case 2: MX bypass from way 0 to way 1 is priority
                    (addr_rs1_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                    (addr_rs1_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                    (addr_rs1_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                    REG
                :
                // can do same logic as way 0
                    (addr_rs1_dx_1 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
                    (addr_rs1_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                    (addr_rs1_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                    (addr_rs1_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                    REG;

// bypass on b_sel only applies to R-type (ALU reg-reg); all others use an immediate
assign b_sel_1 = (!is_alu_x_1) ? IMM :
                    (stall_occured) ?
                    // Case 2: MX bypass from way 0 to way 1 is priority
                        (addr_rs2_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                        (addr_rs2_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                        (addr_rs2_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 
                        REG
                    :
                    // can do same logic as way 0
                        (addr_rs2_dx_1 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : //check way 1 - MX
                        (addr_rs2_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                        (addr_rs2_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                        (addr_rs2_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                        REG;

/* 
    Branch Comparator: A and B select (icluding forwarding)
*/

//way 0
assign branch_comp_data1_sel_0 = (addr_rs1_dx_0 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
                                 (addr_rs1_dx_0 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                                 (addr_rs1_dx_0 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                 (addr_rs1_dx_0 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                                                                                                        REG;
                                                                                                        
assign branch_comp_data2_sel_0 = (addr_rs2_dx_0 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
                                 (addr_rs2_dx_0 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX 
                                 (addr_rs2_dx_0 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                 (addr_rs2_dx_0 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                                                    
                                                                                                        REG;
//way 1
assign branch_comp_data1_sel_1 = (stall_occured) ?
                                    // Case 2: MX bypass from way 0 to way 1 is priority
                                    (addr_rs1_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                                    (addr_rs1_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                    (addr_rs1_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                                    REG
                                :
                                // can do same logic as way 0
                                    (addr_rs1_dx_1 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : // check way 1 - MX
                                    (addr_rs1_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                                    (addr_rs1_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                    (addr_rs1_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                                    REG;

assign branch_comp_data2_sel_1 = (stall_occured) ?
                                // Case 2: MX bypass from way 0 to way 1 is priority
                                    (addr_rs2_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                                    (addr_rs2_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                    (addr_rs2_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 
                                    REG
                                :
                                // can do same logic as way 0
                                    (addr_rs2_dx_1 == addr_rd_xm_1 && addr_rd_xm_1 != 0 && insn_xm_writes_reg_1) ? MX_BYPASS_1 : //check way 1 - MX
                                    (addr_rs2_dx_1 == addr_rd_xm_0 && addr_rd_xm_0 != 0 && insn_xm_writes_reg_0) ? MX_BYPASS_0 : // check way 0 - MX
                                    (addr_rs2_dx_1 == addr_rd_mw_1 && addr_rd_mw_1 != 0 && insn_mw_writes_reg_1) ? WX_BYPASS_1 : // check way 1 - WX
                                    (addr_rs2_dx_1 == addr_rd_mw_0 && addr_rd_mw_0 != 0 && insn_mw_writes_reg_0) ? WX_BYPASS_0 : // check way 0 - WX
                                    REG;

// Just used via test harness
assign br_taken_0 = branch_taken_0;
assign pc_sel_0 = branch_taken_0 || is_jal_x_0 || is_jalr_x_0;

assign br_taken_1 = branch_taken_1;
assign pc_sel_1 = branch_taken_1 || is_jal_x_1 || is_jalr_x_1;

// LUI passes B (immediate) through unchanged; all other non-ALU ops use ADD for address/target computation
    // way 0
assign alu_sel_0 =    (is_lui_x_0) ? NOP :
                    (is_auipc_x_0 || is_jal_x_0 || is_jalr_x_0 || is_load_x_0 || is_store_x_0 || is_branch_x_0) ? ADD :
                    // RISC-V m-extension instructions:
                    (is_alu_x_0 && funct7_0 == 'h01) ? 
                        ((funct3_0 == 'h0) ? MUL : 
                        (funct3_0 == 'h4) ? DIV : 
                        (funct3_0 == 'h5) ? DIVU : 
                    NOP) :
                    (is_alu_x_0 && funct7_0 == 'h20) ? ((funct3_0 == 'h0) ? SUB : SRA) :
                    (is_alu_x_0 || is_alu_imm_x_0) ?
                        ((funct3_0 == 'h0) ? ADD :
                        (funct3_0 == 'h1) ? SLL :
                        (funct3_0 == 'h2) ? SLT :
                        (funct3_0 == 'h3) ? SLTU :
                        (funct3_0 == 'h4) ? XOR :
                        (funct3_0 == 'h5 && funct7_0 == 'h0) ? SRL :
                        (funct3_0 == 'h5 && funct7_0 == 'h20) ? SRA :
                        (funct3_0 == 'h6) ? OR :
                        (funct3_0 == 'h7) ? AND :
                        NOP) // invalid funct3 for ALU
                    : NOP;  // invalid opcode

    // way 1
assign alu_sel_1 =    (is_lui_x_1) ? NOP :
                    (is_auipc_x_1 || is_jal_x_1 || is_jalr_x_1 || is_load_x_1 || is_store_x_1 || is_branch_x_1) ? ADD :
                    // RISC-V m-extension instructions:
                    (is_alu_x_1 && funct7_1 == 'h01) ? 
                        ((funct3_1 == 'h0) ? MUL : 
                        (funct3_1 == 'h4) ? DIV : 
                        (funct3_1 == 'h5) ? DIVU : 
                    NOP) :
                    (is_alu_x_1 && funct7_1 == 'h20) ? ((funct3_1 == 'h0) ? SUB : SRA) :
                    (is_alu_x_1 || is_alu_imm_x_1) ?
                        ((funct3_1 == 'h0) ? ADD :
                        (funct3_1 == 'h1) ? SLL :
                        (funct3_1 == 'h2) ? SLT :
                        (funct3_1 == 'h3) ? SLTU :
                        (funct3_1 == 'h4) ? XOR :
                        (funct3_1 == 'h5 && funct7_1 == 'h0) ? SRL :
                        (funct3_1 == 'h5 && funct7_1 == 'h20) ? SRA :
                        (funct3_1 == 'h6) ? OR :
                        (funct3_1 == 'h7) ? AND :
                        NOP) // invalid funct3 for ALU
                    : NOP;  // invalid opcode

// Execute-Memory Pipeline
always @(posedge clock) begin
    if (reset) begin
         // way 0
        is_store_xm_r_0 <= 1'b0;
        is_load_xm_r_0 <= 1'b0;
        is_jal_xm_r_0 <= 1'b0;
        is_jalr_xm_r_0 <= 1'b0;
        is_branch_xm_r_0 <= 1'b0;
        is_ecall_xm_r_0 <= 1'b0;
    end
    else begin
        is_store_xm_r_0 <= is_store_x_0;
        is_load_xm_r_0 <= is_load_x_0;
        is_jal_xm_r_0 <= is_jal_x_0;
        is_jalr_xm_r_0 <= is_jalr_x_0;
        is_branch_xm_r_0 <= is_branch_x_0;
        is_ecall_xm_r_0 <= is_ecall_x_0;
    end
end


// way 1
always @(posedge clock) begin
    if (reset) begin
        is_store_xm_r_1 <= 1'b0;
        is_load_xm_r_1 <= 1'b0;
        is_jal_xm_r_1 <= 1'b0;
        is_jalr_xm_r_1 <= 1'b0;
        is_branch_xm_r_1 <= 1'b0;
        is_ecall_xm_r_1 <= 1'b0;
    end else if (br_taken_0) begin
        is_store_xm_r_1 <= 1'b0;
        is_load_xm_r_1 <= 1'b0;
        is_jal_xm_r_1 <= 1'b0;
        is_jalr_xm_r_1 <= 1'b0;
        is_branch_xm_r_1 <= 1'b0;
        is_ecall_xm_r_1 <= 1'b0;
    end
    else begin
        is_store_xm_r_1 <= is_store_x_1;
        is_load_xm_r_1 <= is_load_x_1;
        is_jal_xm_r_1 <= is_jal_x_1;
        is_jalr_xm_r_1 <= is_jalr_x_1;
        is_branch_xm_r_1 <= is_branch_x_1;
        is_ecall_xm_r_1 <= is_ecall_x_1;
    end
end

// ==============================
// MEMORY STAGE CONTROL SIGNALS
// ==============================

// gate with reset so no spurious writes occur during pipeline flush
//way 0
assign mem_rw_0 = is_store_xm_r_0 && !reset;

//way 1
assign mem_rw_1 = is_store_xm_r_1 && !reset;

//way 0
// Memory-Writeback Pipeline registers
always @(posedge clock) begin
    if (reset) begin
        is_store_mw_r_0  <= 1'b0;
        is_branch_mw_r_0 <= 1'b0;
        is_ecall_mw_r_0  <= 1'b0;
        is_load_mw_r_0   <= 1'b0;
        is_jal_mw_r_0    <= 1'b0;
        is_jalr_mw_r_0   <= 1'b0;
    end
    else begin
        is_store_mw_r_0  <= is_store_xm_r_0;
        is_branch_mw_r_0 <= is_branch_xm_r_0;
        is_ecall_mw_r_0  <= is_ecall_xm_r_0;
        is_load_mw_r_0  <= is_load_xm_r_0;
        is_jal_mw_r_0    <= is_jal_xm_r_0;
        is_jalr_mw_r_0   <= is_jalr_xm_r_0;
    end
end

//way 1 
always @(posedge clock) begin
    if (reset) begin
        is_store_mw_r_1  <= 1'b0;
        is_branch_mw_r_1 <= 1'b0;
        is_ecall_mw_r_1  <= 1'b0;
        is_load_mw_r_1   <= 1'b0;
        is_jal_mw_r_1    <= 1'b0;
        is_jalr_mw_r_1   <= 1'b0;
    end
    else begin
        is_store_mw_r_1  <= is_store_xm_r_1;
        is_branch_mw_r_1 <= is_branch_xm_r_1;
        is_ecall_mw_r_1  <= is_ecall_xm_r_1;
        is_load_mw_r_1   <= is_load_xm_r_1;
        is_jal_mw_r_1    <= is_jal_xm_r_1;
        is_jalr_mw_r_1   <= is_jalr_xm_r_1;
    end
end


// ===================================
// WRITEBACK STAGE CONTROL SIGNALS
// ===================================

// way 0
    // re-decode from opcode_mw rather than relying on is_ecall_mw_r to avoid propagating stale state
wire is_ecall_wb_0 = (opcode_mw_0 == 7'b1110011);
wire is_nop_0 = (opcode_mw_0 == 7'b0);
    // stores, branches, ecalls, NOPs, reset, and writes to x0 all suppress the register write
assign reg_wen_0 = !(is_store_mw_r_0 || is_branch_mw_r_0 || is_ecall_wb_0 || is_nop_0 || reset || addr_rd_mw_0 == 0);

    // loads read from memory; JAL/JALR write PC+4; everything else writes the ALU result
assign wb_sel_0 = (is_load_mw_r_0) ? WB_MEM :
                (is_jal_mw_r_0 || is_jalr_mw_r_0) ? WB_PC4 :
                WB_ALU;

// way 1
    // re-decode from opcode_mw rather than relying on is_ecall_mw_r to avoid propagating stale state
wire is_ecall_wb_1 = (opcode_mw_1 == 7'b1110011);
wire is_nop_1 = (opcode_mw_1 == 7'b0);
    // stores, branches, ecalls, NOPs, reset, and writes to x0 all suppress the register write
assign reg_wen_1 = !(is_store_mw_r_1 || is_branch_mw_r_1 || is_ecall_wb_1 || is_nop_1 || reset || addr_rd_mw_1 == 0);

    // loads read from memory; JAL/JALR write PC+4; everything else writes the ALU result
assign wb_sel_1 = (is_load_mw_r_1) ? WB_MEM :
                (is_jal_mw_r_1 || is_jalr_mw_r_1) ? WB_PC4 :
                WB_ALU;

endmodule