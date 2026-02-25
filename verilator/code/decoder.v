module decoder #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter N_BITS = $clog2(DATAW)
)(
    input [DATAW-1:0] instr,
    output [6:0] opcode,
    output [ADDRW-1:0] addr_rd,
    output [ADDRW-1:0] addr_rs1,
    output [ADDRW-1:0] addr_rs2,
    output [2:0] funct3,
    output [6:0] funct7,
    output [DATAW-1:0] imm,
    output [N_BITS-1:0] shamt,
    output is_u_type_w,
    output is_j_type_w,
    output is_i_type_w
);

    localparam IMM_SIZE = 12;    // I/S/B immediate size (not including imm[0] for B)
    localparam IMM_UJ_SIZE = 20;  // U/J immediate size (not including imm[0] for J)

    // Declare signals
    wire is_i_shift;

    // aliases for readability
    // all prefixed with '_' to avoid conflict with outputs
    wire [6:0] _opcode     = instr[6:0];
    wire [ADDRW-1:0] _rd  = instr[11:7];
    wire [2:0] _funct3     = instr[14:12];
    wire [ADDRW-1:0] _rs1 = instr[19:15];
    wire [ADDRW-1:0] _rs2 = instr[24:20];
    wire [6:0] _funct7     = instr[31:25];  // Only for R-type

    wire [IMM_SIZE-1:0] _imm_i = instr[31:20];  // Only for I-type
    wire [IMM_SIZE-1:0] _imm_s = {instr[31:25], instr[11:7]};  // Only for S-type
    //                              imm[11:5]     imm[4:0]
    wire [IMM_SIZE-1:0] _imm_b = {instr[31], instr[7], instr[30:25], instr[11:8]};  // Only for B-type (imm[0] = 0 for 2B alignment)
    //                              imm[12]    imm[11]   imm[10:5]      imm[4:1]   imm[0]

    wire [IMM_UJ_SIZE-1:0] _imm_u = instr[31:12];  // Only for U-type
    wire [IMM_UJ_SIZE-1:0] _imm_j = {instr[31], instr[19:12], instr[20], instr[30:21]};  // Only for J-type
    //                                imm[20]    imm[19:12]    imm[11]     imm[10:1]

    // instruction identification
    wire is_alu = (_opcode == 7'b0110011);
    wire is_alu_imm = (_opcode == 7'b0010011);
    wire is_load = (_opcode == 7'b0000011);
    wire is_store = (_opcode == 7'b0100011);
    wire is_branch = (_opcode == 7'b1100011);
    wire is_jal = (_opcode == 7'b1101111);
    wire is_jalr = (_opcode == 7'b1100111);
    wire is_lui = (_opcode == 7'b0110111);
    wire is_auipc = (_opcode == 7'b0010111);
    wire is_ecall = (_opcode == 7'b1110011) & (_funct3 == 3'b000) & (_imm_i == 12'b000000000000);

    // instruction type identification
    wire is_r_type = is_alu;
    wire is_i_type = is_alu_imm | is_load | is_jalr | is_ecall;
    wire is_s_type = is_store;
    wire is_b_type = is_branch;
    wire is_u_type = is_lui | is_auipc;
    wire is_j_type = is_jal;

    // For stall logic
    assign is_u_type_w = is_u_type;
    assign is_j_type_w = is_j_type;
    assign is_i_type_w = is_i_type;

    // special identifiers (useful if we want to explicitly write 0 for the don't care cases)
    // wire is_shift = is_i_type & ((_funct3 == 3'b101) | (_funct3 == 3'b001)); // SRLI, SRAI, SLLI
    // wire is_sltiu = (_funct3 == 3'b011);


    // always writing to the outputs regardless of if they are used or not
    // helps to avoid latches in synthesis, and they are don't care values anyway
    assign opcode = _opcode;
    assign addr_rd = _rd;

    assign addr_rs1 = _rs1;
    assign addr_rs2 = _rs2;

    assign funct3 = _funct3;
    assign funct7 = _funct7;

    assign is_i_shift = (is_alu_imm && (_funct3 == 'h1 || _funct3 == 'h5)) ? 1 : 0;
    assign shamt = _imm_i[4:0];

    assign imm = (is_r_type) ? 0 :                                                                   // R-type has no immediate
                 (is_i_shift) ? {27'b0, shamt} :                                                     // i-shift uses imm[4:0] only
                 (is_i_type) ? {{(DATAW - IMM_SIZE){_imm_i[IMM_SIZE-1]}}, _imm_i} :                  // sign-extend
                 (is_s_type) ? {{(DATAW - IMM_SIZE){_imm_s[IMM_SIZE-1]}}, _imm_s} :                  // sign-extend
                 (is_b_type) ? {{(DATAW - IMM_SIZE - 1){_imm_b[IMM_SIZE-1]}}, _imm_b, 1'b0} :        // sign-extend and imm[0] = 0 for 2B alignment
                 (is_u_type) ? {_imm_u, 12'b0} :                                                     // imm << 12
                 (is_j_type) ? {{(DATAW - IMM_UJ_SIZE - 1){_imm_j[IMM_UJ_SIZE-1]}}, _imm_j, 1'b0} :  // sign-extend and imm[0] = 0 for 2B alignment
                 0;                                                                                  // default case

endmodule