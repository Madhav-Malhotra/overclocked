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
    // active high pipeline enables — freezes the corresponding pipeline reg
    input dx_en,
    input xm_en,
    input mw_en,
    input [6:0] opcode_dx,
    input [6:0] opcode_xm,
    input [6:0] opcode_mw,
    // funct3/funct7 are sampled from the DX pipeline register
    input [2:0] funct3,
    input [6:0] funct7,
    // branch comparator results arrive in the Execute stage
    input br_eq,
    input br_lt,
    input [ADDRW-1:0] addr_rs1_dx,
    input [ADDRW-1:0] addr_rs2_dx,
    input [ADDRW-1:0] addr_rd_xm,
    input [ADDRW-1:0] addr_rd_mw,
    output [1:0] branch_comp_data1_sel,
    output [1:0] branch_comp_data2_sel,
    // br_taken exposed for use in test harness
    output br_taken,
    output pc_sel,
    output br_un,
    output [1:0] a_sel,
    output [1:0] b_sel,
    output [3:0] alu_sel,
    output mem_rw,
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
localparam MUL = 4'd11;

// wb_sel encoding
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;

// ====================
// PIPELINE REGISTERS
// ====================

// Decode-Execute Pipeline registers

////////////////////code below isn't needed
// reg [2:0] funct3_dx_r;
// reg [6:0] funct7_dx_r;
// always @(posedge clock) begin
//     if (reset) begin
//         funct3_dx_r <= 3'd0;
//         funct7_dx_r <= 7'd0;
//     end
//     else if (dx_en) begin
//         funct3_dx_r <= funct3;
//         funct7_dx_r <= funct7;
//     end
// end
//////////////////////code above isn't needed

// ===============================
// EXECUTE STAGE CONTROL SIGNALS
// ===============================

wire is_branch_x  = (opcode_dx == 7'b1100011);
wire is_alu_x     = (opcode_dx == 7'b0110011);
wire is_alu_imm_x = (opcode_dx == 7'b0010011);
wire is_jal_x     = (opcode_dx == 7'b1101111);
wire is_auipc_x   = (opcode_dx == 7'b0010111);
wire is_lui_x     = (opcode_dx == 7'b0110111);
wire is_load_x    = (opcode_dx == 7'b0000011);
wire is_store_x   = (opcode_dx == 7'b0100011);
wire is_jalr_x    = (opcode_dx == 7'b1100111);
wire is_ecall_x   = (opcode_dx == 7'b1110011);
wire is_u_type_x  = is_lui_x || is_auipc_x;

// JAL/JALR always jump; conditional branches jump when their condition holds
wire branch_taken = (is_branch_x && (
    (funct3 == 'h0 && br_eq) ||               // BEQ
    (funct3 == 'h1 && !br_eq) ||              // BNE
    (funct3 == 'h4 && br_lt) ||               // BLT
    (funct3 == 'h5 && !br_lt) ||              // BGE
    (funct3 == 'h6 && br_lt) ||               // BLTU
    (funct3 == 'h7 && !br_lt))                // BGEU
) || is_jal_x || is_jalr_x;

// unsigned comparison for BLTU/BGEU
assign br_un = is_branch_x && (funct3 == 'h6 || funct3 == 'h7);

// A sel definitions (ALU input 1)
localparam REG = 2'b00;
localparam PC  = 2'b01;
localparam WX_BYPASS = 2'b10;
localparam MX_BYPASS = 2'b11;

// B sel definitions (ALU input 2)
localparam IMM  = 2'b01;

// XM stage pipeline registers
reg is_store_xm_r;
reg is_load_xm_r;
reg is_jal_xm_r;
reg is_jalr_xm_r;
reg is_branch_xm_r;
reg is_ecall_xm_r;

// MW stage pipeline registers
reg is_store_mw_r;
reg is_branch_mw_r;
reg is_ecall_mw_r;
reg is_load_mw_r;
reg is_jal_mw_r;
reg is_jalr_mw_r;

// stores, branches, and ecalls never produce a register result; x0 writes are also suppressed
wire insn_xm_writes_reg = !(is_store_xm_r || is_branch_xm_r || is_ecall_xm_r) && (addr_rd_xm != 0);
wire insn_mw_writes_reg = !(is_store_mw_r || is_branch_mw_r || is_ecall_mw_r) && (addr_rd_mw != 0);

// ==========================
// FORWARDING / MUX SELECTS
// ==========================

// U-type and JAL use PC, not rs1; bypass only applies when rs1 is actually read
assign a_sel = (is_branch_x || is_auipc_x || is_jal_x) ? PC :
               (!(is_u_type_x || is_jal_x) && addr_rs1_dx == addr_rd_xm && addr_rd_xm != 0 && insn_xm_writes_reg) ? MX_BYPASS :
               (!(is_u_type_x || is_jal_x) && addr_rs1_dx == addr_rd_mw && addr_rd_mw != 0 && insn_mw_writes_reg) ? WX_BYPASS :
                REG;
// bypass on b_sel only applies to R-type (ALU reg-reg); all others use an immediate
assign b_sel = (is_alu_x && addr_rs2_dx == addr_rd_xm && addr_rd_xm != 0 && insn_xm_writes_reg) ? MX_BYPASS :
               (is_alu_x && addr_rs2_dx == addr_rd_mw && addr_rd_mw != 0 && insn_mw_writes_reg) ? WX_BYPASS :
               (!is_alu_x) ? IMM :
                             REG;

assign branch_comp_data1_sel =  (addr_rs1_dx == addr_rd_xm && addr_rd_xm != 0 && insn_xm_writes_reg) ? MX_BYPASS :
                                (addr_rs1_dx == addr_rd_mw && addr_rd_mw != 0 && insn_mw_writes_reg) ? WX_BYPASS :
                                                                                                        REG;
assign branch_comp_data2_sel =  (addr_rs2_dx == addr_rd_xm && addr_rd_xm != 0 && insn_xm_writes_reg) ? MX_BYPASS :
                                (addr_rs2_dx == addr_rd_mw && addr_rd_mw != 0 && insn_mw_writes_reg) ? WX_BYPASS :
                                                                                                        REG;

// Just used via test harness
assign br_taken = branch_taken;
assign pc_sel = branch_taken || is_jal_x || is_jalr_x;

// LUI passes B (immediate) through unchanged; all other non-ALU ops use ADD for address/target computation
assign alu_sel =    (is_lui_x) ? NOP :
                    (is_auipc_x || is_jal_x || is_jalr_x || is_load_x || is_store_x || is_branch_x) ? ADD :
                    (is_alu_x && funct7 == 'h01) ? ((funct3 == 'h0) ? MUL : NOP) :
                    (is_alu_x && funct7 == 'h20) ? ((funct3 == 'h0) ? SUB : SRA) :
                    (is_alu_x || is_alu_imm_x) ?
                        ((funct3 == 'h0) ? ADD :
                        (funct3 == 'h1) ? SLL :
                        (funct3 == 'h2) ? SLT :
                        (funct3 == 'h3) ? SLTU :
                        (funct3 == 'h4) ? XOR :
                        (funct3 == 'h5 && funct7 == 'h0) ? SRL :
                        (funct3 == 'h5 && funct7 == 'h20) ? SRA :
                        (funct3 == 'h6) ? OR :
                        (funct3 == 'h7) ? AND :
                        NOP) // invalid funct3 for ALU
                    : NOP;  // invalid opcode

// Execute-Memory Pipeline
always @(posedge clock) begin
    if (reset) begin
        is_store_xm_r <= 1'b0;
        is_load_xm_r <= 1'b0;
        is_jal_xm_r <= 1'b0;
        is_jalr_xm_r <= 1'b0;
        is_branch_xm_r <= 1'b0;
        is_ecall_xm_r <= 1'b0;
    end
    else if (xm_en) begin
        is_store_xm_r <= is_store_x;
        is_load_xm_r <= is_load_x;
        is_jal_xm_r <= is_jal_x;
        is_jalr_xm_r <= is_jalr_x;
        is_branch_xm_r <= is_branch_x;
        is_ecall_xm_r <= is_ecall_x;
    end
end

// ==============================
// MEMORY STAGE CONTROL SIGNALS
// ==============================

// gate with reset so no spurious writes occur during pipeline flush
assign mem_rw = is_store_xm_r && !reset;

// Memory-Writeback Pipeline registers
always @(posedge clock) begin
    if (reset) begin
        is_store_mw_r <= 1'b0;
        is_branch_mw_r <= 1'b0;
        is_ecall_mw_r <= 1'b0;
        is_load_mw_r <= 1'b0;
        is_jal_mw_r <= 1'b0;
        is_jalr_mw_r <= 1'b0;
    end
    else if (mw_en) begin
        is_store_mw_r <= is_store_xm_r;
        is_branch_mw_r <= is_branch_xm_r;
        is_ecall_mw_r <= is_ecall_xm_r;
        is_load_mw_r <= is_load_xm_r;
        is_jal_mw_r <= is_jal_xm_r;
        is_jalr_mw_r <= is_jalr_xm_r;
    end
end

// ===================================
// WRITEBACK STAGE CONTROL SIGNALS
// ===================================

// re-decode from opcode_mw rather than relying on is_ecall_mw_r to avoid propagating stale state
wire is_ecall_wb = (opcode_mw == 7'b1110011);
wire is_nop = (opcode_mw == 7'b0);
// stores, branches, ecalls, NOPs, reset, and writes to x0 all suppress the register write
assign reg_wen = !(is_store_mw_r || is_branch_mw_r || is_ecall_wb || is_nop || reset || addr_rd_mw == 0);

// loads read from memory; JAL/JALR write PC+4; everything else writes the ALU result
assign wb_sel = (is_load_mw_r) ? WB_MEM :
                (is_jal_mw_r || is_jalr_mw_r) ? WB_PC4 :
                WB_ALU;

endmodule
