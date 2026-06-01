// =============================================================================
// Module:      decoder
// Description: Extracts all instruction fields and generates sign-extended
//              immediates for all RV32I formats (R, I, S, B, U, J).
//              Also identifies instruction type for stall logic in pd.v.
// Inputs:      instr       - 32-bit raw instruction word
// Outputs:     opcode      - 7-bit opcode field
//              addr_rd     - destination register address
//              addr_rs1    - source register 1 address
//              addr_rs2    - source register 2 address
//              funct3      - 3-bit function code
//              funct7      - 7-bit function code (R-type only)
//              imm         - sign-extended immediate (format-dependent)
//              shamt       - shift amount (I-type shifts only)
//              is_u_type_w - high when instruction is U-type (for stall logic)
//              is_j_type_w - high when instruction is J-type (for stall logic)
//              is_i_type_w - high when instruction is I-type (for stall logic)
// =============================================================================
module decoder #(
    parameter DATAW  =  32,
    parameter ADDRW  =  $clog2(DATAW),
    parameter N_BITS =  $clog2(DATAW)
)(
    input  [DATAW-1:0]  instr,
    output [6:0]        opcode,
    output [ADDRW-1:0]  addr_rd,
    output [ADDRW-1:0]  addr_rs1,
    output [ADDRW-1:0]  addr_rs2,
    output [2:0]        funct3,
    output [6:0]        funct7,
    output [DATAW-1:0]  imm,
    output [N_BITS-1:0] shamt,
    output              is_u_type_w,
    output              is_j_type_w,
    output              is_i_type_w
);

// I/S/B immediate size (excludes imm[0] for B-type)
localparam IMM_SIZE = 12;
// U/J immediate size (excludes imm[0] for J-type)
localparam IMM_UJ_SIZE = 20;

// ====================
// FIELD EXTRACTION
// ====================

wire is_i_shift;

//aliases for readability prefixed with '_' to not conflict with outputs
wire [6:0] _opcode     = instr[6:0];
wire [ADDRW-1:0] _rd  = instr[11:7];
wire [2:0] _funct3     = instr[14:12];
wire [ADDRW-1:0] _rs1 = instr[19:15];
wire [ADDRW-1:0] _rs2 = instr[24:20];
// R-type only
wire [6:0] _funct7     = instr[31:25];

// immediate fields reassembled per encoding type (I, S, B, ...)
wire [IMM_SIZE-1:0] _imm_i = instr[31:20];
wire [IMM_SIZE-1:0] _imm_s = {instr[31:25], instr[11:7]};
//                              imm[11:5]     imm[4:0]
wire [IMM_SIZE-1:0] _imm_b = {instr[31], instr[7], instr[30:25], instr[11:8]};
//                              imm[12]    imm[11]   imm[10:5]      imm[4:1]

wire [IMM_UJ_SIZE-1:0] _imm_u = instr[31:12];
wire [IMM_UJ_SIZE-1:0] _imm_j = {instr[31], instr[19:12], instr[20], instr[30:21]};
//                                imm[20]    imm[19:12]    imm[11]     imm[10:1]

// ====================
// INSTRUCTION DECODE
// ====================

// opcode-level identification
wire is_alu = (_opcode == 7'b0110011);
wire is_alu_imm = (_opcode == 7'b0010011);
wire is_load = (_opcode == 7'b0000011);
wire is_store = (_opcode == 7'b0100011);
wire is_branch = (_opcode == 7'b1100011);
wire is_jal = (_opcode == 7'b1101111);
wire is_jalr = (_opcode == 7'b1100111);
wire is_lui = (_opcode == 7'b0110111);
wire is_auipc = (_opcode == 7'b0010111);
wire is_ecall = (_opcode == 7'b1110011) & (_funct3 == 3'b0) & (_imm_i == 12'b0);

// format classification used to select the correct immediate encoding
wire is_r_type = is_alu;
wire is_i_type = is_alu_imm | is_load | is_jalr | is_ecall;
wire is_s_type = is_store;
wire is_b_type = is_branch;
wire is_u_type = is_lui | is_auipc;
wire is_j_type = is_jal;

// expose type flags to pd.v for stall logic
assign is_u_type_w = is_u_type;
assign is_j_type_w = is_j_type;
assign is_i_type_w = is_i_type;

// ====================
// OUTPUT ASSIGNMENTS
// ====================

// always drive all outputs to avoid synthesis latches; unused values are don't-cares
assign opcode = _opcode;
assign addr_rd = _rd;

assign addr_rs1 = _rs1;
assign addr_rs2 = _rs2;

assign funct3 = _funct3;
assign funct7 = _funct7;

// I-type shifts (SLLI/SRLI/SRAI) encode the shift amount in imm[4:0]
assign is_i_shift = (is_alu_imm && (_funct3 == 'h1 || _funct3 == 'h5)) ? 1 : 0;
assign shamt = _imm_i[4:0];

// select and sign-extend the immediate based on instruction format
                // R-type has no immediate
assign imm = (is_r_type) ? 0 :
                // shift uses imm[4:0] only
                (is_i_shift) ? {27'b0, shamt} :
                // sign-extend
                (is_i_type) ? {{(DATAW - IMM_SIZE){_imm_i[IMM_SIZE-1]}}, _imm_i} :
                // sign-extend
                (is_s_type) ? {{(DATAW - IMM_SIZE){_imm_s[IMM_SIZE-1]}}, _imm_s} :
                // sign-extend; imm[0]=0 for 2B alignment
                (is_b_type) ? {{(DATAW - IMM_SIZE - 1){_imm_b[IMM_SIZE-1]}}, _imm_b, 1'b0} :
                // shift left 12
                (is_u_type) ? {_imm_u, 12'b0} :
                // sign-extend; imm[0]=0 for 2B alignment
                (is_j_type) ? {{(DATAW - IMM_UJ_SIZE - 1){_imm_j[IMM_UJ_SIZE-1]}}, _imm_j, 1'b0} :
                // default (should not occur)
                0;

endmodule