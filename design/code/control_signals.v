module control_signals #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW)
)
(
    input clock,
    input reset,
    input [6:0] opcode_dx,
    input [6:0] opcode_xm,
    input [6:0] opcode_mw,
    input [2:0] funct3,                         // come during DE stage
    input [6:0] funct7,                         // come during DE stage
    input br_eq,                                // come during EX stage
    input br_lt,                                // come during EX stage
    input [ADDRW-1:0] addr_rs1_dx,
    input [ADDRW-1:0] addr_rs2_dx,
    input [ADDRW-1:0] addr_rd_xm,
    input [ADDRW-1:0] addr_rd_mw,
    output [1:0] branch_comp_data1_sel,
    output [1:0] branch_comp_data2_sel,
    output br_taken,                            // Just for test file
    output pc_sel,
    output br_un,
    output [1:0] a_sel,
    output [1:0] b_sel,
    output [3:0] alu_sel,
    output mem_rw,
    output reg_wen,
    output [1:0] wb_sel
    // NOTE: ImmSel done inside the decoder
);

// ALU sel definitions
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

// WB sel definitions
localparam WB_MEM = 2'd0;
localparam WB_ALU = 2'd1;
localparam WB_PC4 = 2'd2;


// Decode-Execute Pipeline registers
reg [2:0] funct3_dx_r;
reg [6:0] funct7_dx_r;
always @(posedge clock) begin
    if (reset) begin
        funct3_dx_r <= 3'd0;
        funct7_dx_r <= 7'd0;
    end else begin
        funct3_dx_r <= funct3;
        funct7_dx_r <= funct7;
    end
end

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

wire branch_taken = (is_branch_x && (
    (funct3_dx_r == 'h0 && br_eq) ||               // BEQ
    (funct3_dx_r == 'h1 && !br_eq) ||              // BNE
    (funct3_dx_r == 'h4 && br_lt) ||               // BLT
    (funct3_dx_r == 'h5 && !br_lt) ||              // BGE
    (funct3_dx_r == 'h6 && br_lt) ||               // BLTU
    (funct3_dx_r == 'h7 && !br_lt))                 // BGEU
) || is_jal_x || is_jalr_x;

assign br_un = is_branch_x && (funct3_dx_r == 'h6 || funct3_dx_r == 'h7);   // BLTU/BGEU

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

// Ensure that the instruction in the Memory or Writeback stage writes to a register for bypass logic
wire insn_xm_writes_reg = !(is_store_xm_r || is_branch_xm_r || is_ecall_xm_r) && (addr_rd_xm != 0);
wire insn_mw_writes_reg = !(is_store_mw_r || is_branch_mw_r || is_ecall_mw_r) && (addr_rd_mw != 0);

// WX, MX bypass and PC/IMM/REG selection logic
// MDV - Check forwarding logic + pipelined variants 
assign a_sel = (is_branch_x || is_auipc_x || is_jal_x) ? PC :
               (!(is_u_type_x || is_jal_x) && addr_rs1_dx == addr_rd_xm && addr_rd_xm != 0 && insn_xm_writes_reg) ? MX_BYPASS :
               (!(is_u_type_x || is_jal_x) && addr_rs1_dx == addr_rd_mw && addr_rd_mw != 0 && insn_mw_writes_reg) ? WX_BYPASS :
                REG;
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

assign br_taken = branch_taken;             // Just for test file
assign pc_sel = branch_taken || is_jal_x || is_jalr_x;

assign alu_sel =    (is_lui_x) ? NOP :
                    (is_auipc_x || is_jal_x || is_jalr_x || is_load_x || is_store_x || is_branch_x) ? ADD :
                    (is_alu_x && funct7_dx_r == 'h20) ? ((funct3_dx_r == 'h0) ? SUB : SRA) :
                    (is_alu_x || is_alu_imm_x) ?
                        ((funct3_dx_r == 'h0) ? ADD :
                        (funct3_dx_r == 'h1) ? SLL :
                        (funct3_dx_r == 'h2) ? SLT :
                        (funct3_dx_r == 'h3) ? SLTU :
                        (funct3_dx_r == 'h4) ? XOR :
                        (funct3_dx_r == 'h5 && funct7_dx_r == 'h0) ? SRL :
                        (funct3_dx_r == 'h5 && funct7_dx_r == 'h20) ? SRA :
                        (funct3_dx_r == 'h6) ? OR :
                        (funct3_dx_r == 'h7) ? AND :
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
    end else begin
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

assign mem_rw = is_store_xm_r && !reset;
// MDV - check proper pipelined variant


// Memory-Writeback Pipeline registers
always @(posedge clock) begin
    if (reset) begin
        is_store_mw_r <= 1'b0;
        is_branch_mw_r <= 1'b0;
        is_ecall_mw_r <= 1'b0;
        is_load_mw_r <= 1'b0;
        is_jal_mw_r <= 1'b0;
        is_jalr_mw_r <= 1'b0;
    end else begin
        is_store_mw_r <= is_store_xm_r;
        is_branch_mw_r <= is_branch_xm_r;
        is_ecall_mw_r <= is_ecall_xm_r;
        is_load_mw_r <= is_load_xm_r;
        is_jal_mw_r <= is_jal_xm_r;
        is_jalr_mw_r <= is_jalr_xm_r;
    end
end

// =================================
// WRITEBACK STAGE CONTROL SIGNALS
// =================================
wire is_ecall_wb = (opcode_mw == 7'b1110011);
wire is_nop = (opcode_mw == 7'b0);
assign reg_wen = !(is_store_mw_r || is_branch_mw_r || is_ecall_wb || is_nop || reset || addr_rd_mw == 0);

assign wb_sel = (is_load_mw_r) ? WB_MEM :
                (is_jal_mw_r || is_jalr_mw_r) ? WB_PC4 :
                // (is_store || is_branch) ? WB_ALU :   // Left here for clarity, synthesizer will optimize it away
                WB_ALU;

endmodule
