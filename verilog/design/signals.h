
/* Your Code Below! Enable the following define's 
 * and replace ??? with actual wires */
// ----- signals -----
// You will also need to define PC properly
`define F_PC                pc_r
`define F_INSN              instr_w

`define D_PC                pc_fd_r
`define D_OPCODE            opcode_w
`define D_RD                addr_rd_w
`define D_RS1               addr_rs1_w
`define D_RS2               addr_rs2_w
`define D_FUNCT3            funct3_w
`define D_FUNCT7            funct7_w
`define D_IMM               imm_w
`define D_SHAMT             shamt_w

`define R_WRITE_ENABLE      reg_wen
`define R_WRITE_DESTINATION addr_rd_mw_r
`define R_WRITE_DATA        data_rd_w
`define R_READ_RS1          addr_rs1_w
`define R_READ_RS2          addr_rs2_w
`define R_READ_RS1_DATA     data_rs1_w
`define R_READ_RS2_DATA     data_rs2_w

`define E_PC                pc_dx_r
`define E_ALU_RES           alu_out_w
`define E_BR_TAKEN          br_taken

`define M_PC                pc_xm_r
`define M_ADDRESS           alu_xm_r
`define M_RW                data_mem_rw
`define M_SIZE_ENCODED      mem_write_access_size
`define M_DATA              dmem_data_in

`define W_PC                pc_mw_r
`define W_ENABLE            reg_wen
`define W_DESTINATION       addr_rd_mw_r
`define W_DATA              data_rd_w

`define IMEMORY             imem1
`define DMEMORY             dmem1

// ----- signals -----

// ----- design -----
`define TOP_MODULE                 pd
// ----- design -----
