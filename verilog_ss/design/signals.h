
/* Your Code Below! Enable the following define's 
 * and replace ??? with actual wires */
// ----- signals -----
// You will also need to define PC properly
`define F_PC_0                pc_r_0
`define F_INSN_0              instr_w_0

`define D_PC_0                pc_fd_r_0

`define D_OPCODE_0            opcode_w_0
`define D_RD_0                addr_rd_w_0
`define D_RS1_0               addr_rs1_w_0
`define D_RS2_0               addr_rs2_w_0
`define D_FUNCT3_0            funct3_w_0
`define D_FUNCT7_0            funct7_w_0
`define D_IMM_0               imm_w_0
`define D_SHAMT_0             shamt_w_0

`define R_WRITE_ENABLE_0      reg_wen_0
`define R_WRITE_DESTINATION_0 addr_rd_mw_r_0
`define R_WRITE_DATA_0        data_rd_w_0
`define R_READ_RS1_0          addr_rs1_w_0
`define R_READ_RS2_0          addr_rs2_w_0
`define R_READ_RS1_DATA_0     data_rs1_w_0
`define R_READ_RS2_DATA_0     data_rs2_w_0

`define E_PC_0                pc_dx_r_0
`define E_ALU_RES_0           alu_out_w_0
`define E_BR_TAKEN_0          br_taken_0

`define M_PC_0                pc_xm_r_0
`define M_ADDRESS_0           alu_xm_r_0
`define M_RW_0                data_mem_rw_0
`define M_SIZE_ENCODED_0      mem_write_access_size_0
`define M_DATA_0              dmem_data_in_0

`define W_PC_0                pc_mw_r_0
`define W_ENABLE_0            reg_wen_0
`define W_DESTINATION_0       addr_rd_mw_r_0
`define W_DATA_0              data_rd_w_0

`define IMEMORY             imem1
`define DMEMORY             dmem1


// ----- design -----
`define TOP_MODULE                 pd
// ----- design -----

`define F_PC_1                pc_r_1
`define F_INSN_1              instr_w_1

`define D_PC_1                pc_fd_r_1

`define D_OPCODE_1            opcode_w_1
`define D_RD_1                addr_rd_w_1
`define D_RS1_1               addr_rs1_w_1
`define D_RS2_1               addr_rs2_w_1
`define D_FUNCT3_1            funct3_w_1
`define D_FUNCT7_1            funct7_w_1
`define D_IMM_1               imm_w_1
`define D_SHAMT_1             shamt_w_1

`define R_WRITE_ENABLE_1      reg_wen_1
`define R_WRITE_DESTINATION_1 addr_rd_mw_r_1
`define R_WRITE_DATA_1        data_rd_w_1
`define R_READ_RS1_1          addr_rs1_w_1
`define R_READ_RS2_1          addr_rs2_w_1
`define R_READ_RS1_DATA_1     data_rs1_w_1
`define R_READ_RS2_DATA_1     data_rs2_w_1

`define E_PC_1                pc_dx_r_1
`define E_ALU_RES_1           alu_out_w_1
`define E_BR_TAKEN_1          br_taken_1

`define M_PC_1                pc_xm_r_1
`define M_ADDRESS_1           alu_xm_r_1
`define M_RW_1                data_mem_rw_1
`define M_SIZE_ENCODED_1      mem_write_access_size_1
`define M_DATA_1              dmem_data_in_1

`define W_PC_1                pc_mw_r_1
`define W_ENABLE_1            reg_wen_1
`define W_DESTINATION_1       addr_rd_mw_r_1
`define W_DATA_1              data_rd_w_1

// ----- signals -----