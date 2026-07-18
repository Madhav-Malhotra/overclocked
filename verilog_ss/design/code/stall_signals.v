// =============================================================================
// Module:      stall_signals
// Description: Evaluates stall conditions for all RV32I instructions 
//              (including inter-way dependancies).
// Inputs:      idata1, idata2 - 32-bit operands to compare
//              br_un          - 1 selects unsigned comparison, 0 selects signed
// Outputs:     br_eq          - asserted when idata1 == idata2
//              br_lt          - asserted when idata1 < idata2
// =============================================================================
module stall_signals #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW) // Note: If DATAW=32, ADDRW will be 5
)( 
    input clock,
    input reset,

    // Existing Stall Status inputs
    input stall_fd_0,
    input stall_fd_1,

    // Opcodes: 
    input [6:0] opcode_w_0,
    input [6:0] opcode_dx_r_0,
    input [6:0] opcode_xm_r_0,
    input [6:0] opcode_mw_r_0,

    input [6:0] opcode_w_1,
    input [6:0] opcode_dx_r_1,
    input [6:0] opcode_xm_r_1,
    input [6:0] opcode_mw_r_1,
    
    // Register indices: 
    input [ADDRW-1:0] addr_rs1_w_0,
    input [ADDRW-1:0] addr_rs2_w_0,
    input [ADDRW-1:0] addr_rd_w_0,       
    input [ADDRW-1:0] addr_rd_dx_r_0,
    input [ADDRW-1:0] addr_rd_xm_r_0,
    input [ADDRW-1:0] addr_rd_mw_r_0,

    input [ADDRW-1:0] addr_rs1_w_1,
    input [ADDRW-1:0] addr_rs2_w_1,
    input [ADDRW-1:0] addr_rd_dx_r_1,    
    input [ADDRW-1:0] addr_rd_xm_r_1,
    input [ADDRW-1:0] addr_rd_mw_r_1,
    
    // Instruction types:
    input is_u_type_0,
    input is_j_type_0,
    input is_i_type_0,
    input is_u_type_1,
    input is_j_type_1,
    input is_i_type_1,

    output stall_0,
    output stall_1,
    output instr_mw_writes_reg_0_op,
    output instr_mw_writes_reg_1_op
);


  localparam NOP_INSTR = 32'h00000013; // Pseudo instruction: ADDI x0, x0, 0
  localparam NOP_OPCODE = 7'b0010011;  // Opcode for ADDI
  localparam LOAD_OPCODE = 7'b0000011;
  localparam STORE_OPCODE = 7'b0100011;
  localparam BRANCH_OPCODE = 7'b1100011;
  localparam ECALL_OPCODE = 7'b1110011;


// this logic happens during the decode stage so the _w signals represent the FD instruction that is currently being decoded
  // way 0
  wire is_load_dx_0 = (opcode_dx_r_0 == LOAD_OPCODE); // DX instruction is load
  wire is_store_fd_0 = (opcode_w_0 == STORE_OPCODE);  // FD instruction is store
  wire is_load_xm_0 = (opcode_xm_r_0 == LOAD_OPCODE);

  wire is_nop_mw_0 = (opcode_mw_r_0 == NOP_OPCODE && addr_rd_mw_r_0 == 0);
  wire is_nop_xm_0 = (opcode_xm_r_0 == NOP_OPCODE && addr_rd_xm_r_0 == 0);

  // way 1
  wire is_load_dx_1 = (opcode_dx_r_1 == LOAD_OPCODE); // DX instruction is load
  wire is_store_fd_1 = (opcode_w_1 == STORE_OPCODE);  // FD instruction is store
  wire is_load_xm_1 = (opcode_xm_r_1 == LOAD_OPCODE);

  wire is_nop_mw_1 = (opcode_mw_r_1 == NOP_OPCODE && addr_rd_mw_r_1 == 0);
  wire is_nop_xm_1 = (opcode_xm_r_1 == NOP_OPCODE && addr_rd_xm_r_1 == 0);


  // stalls due to load hazard - load in X (either way) to rd, rd read in D.
  // Grouped by CONSUMER: if way 0's D instruction depends on an X-stage load,
  // the whole front end must stall (stall_0). If only way 1's D instruction
  // depends, way 1 alone stalls (split issue) and picks the value up later.
  // Register-use qualifiers belong to the CONSUMER's instruction type.
  // Store rs2 is exempt: it is consumed in M and covered by the WM bypass.
    // consumer way 0
  wire d0_uses_rs1   = !is_u_type_0 && !is_j_type_0;
  wire d0_uses_rs2_x = !is_u_type_0 && !is_j_type_0 && !is_i_type_0 && !is_store_fd_0;
    // consumer way 1
  wire d1_uses_rs1   = !is_u_type_1 && !is_j_type_1;
  wire d1_uses_rs2_x = !is_u_type_1 && !is_j_type_1 && !is_i_type_1 && !is_store_fd_1;

  wire load_stall_0 = (is_load_dx_0 && addr_rd_dx_r_0 != 0 &&
                        ((d0_uses_rs1   && addr_rd_dx_r_0 == addr_rs1_w_0) ||
                         (d0_uses_rs2_x && addr_rd_dx_r_0 == addr_rs2_w_0))) ||
                      (is_load_dx_1 && addr_rd_dx_r_1 != 0 &&
                        ((d0_uses_rs1   && addr_rd_dx_r_1 == addr_rs1_w_0) ||
                         (d0_uses_rs2_x && addr_rd_dx_r_1 == addr_rs2_w_0)));

  wire load_stall_1 = (is_load_dx_0 && addr_rd_dx_r_0 != 0 &&
                        ((d1_uses_rs1   && addr_rd_dx_r_0 == addr_rs1_w_1) ||
                         (d1_uses_rs2_x && addr_rd_dx_r_0 == addr_rs2_w_1))) ||
                      (is_load_dx_1 && addr_rd_dx_r_1 != 0 &&
                        ((d1_uses_rs1   && addr_rd_dx_r_1 == addr_rs1_w_1) ||
                         (d1_uses_rs2_x && addr_rd_dx_r_1 == addr_rs2_w_1)));

  // stalls due to write data hazard (no WD forward path)
  // Doesn't involve x0 + is an opcode that writes to an rd
    // way 0
  wire instr_mw_writes_reg_0 = (addr_rd_mw_r_0 != 0) && 
        !(opcode_mw_r_0 == STORE_OPCODE || opcode_mw_r_0 == BRANCH_OPCODE || opcode_mw_r_0 == ECALL_OPCODE); 

//     //way 1
  wire instr_mw_writes_reg_1 = (addr_rd_mw_r_1!= 0) && 
        !(opcode_mw_r_1 == STORE_OPCODE || opcode_mw_r_1 == BRANCH_OPCODE || opcode_mw_r_1 == ECALL_OPCODE); 
  

    // Some instruction in mem stage writing to rs2 of store --> cannot do any sort of bypass
  wire instr_xm_writes_reg_0 = (addr_rd_xm_r_0 != 0) && 
    !(opcode_xm_r_0 == STORE_OPCODE || opcode_xm_r_0 == BRANCH_OPCODE || opcode_xm_r_0 == ECALL_OPCODE);   
  
  wire instr_xm_writes_reg_1 = (addr_rd_xm_r_1 != 0) && 
    !(opcode_xm_r_1 == STORE_OPCODE || opcode_xm_r_1 == BRANCH_OPCODE || opcode_xm_r_1 == ECALL_OPCODE);   
    
  wire instr_dx_writes_reg_0 = (addr_rd_dx_r_0 != 0) &&
    !(opcode_dx_r_0 == STORE_OPCODE || opcode_dx_r_0 == BRANCH_OPCODE || opcode_dx_r_0 == ECALL_OPCODE);
  wire instr_dx_writes_reg_1 = (addr_rd_dx_r_1 != 0) &&
    !(opcode_dx_r_1 == STORE_OPCODE || opcode_dx_r_1 == BRANCH_OPCODE || opcode_dx_r_1 == ECALL_OPCODE);
  
  // WD STALL
  wire bypass_to_0 =  ( (addr_rd_mw_r_0 == addr_rd_xm_r_0 && instr_xm_writes_reg_0) || // wx bypass from way 0
                        (addr_rd_mw_r_0 == addr_rd_xm_r_1 && instr_xm_writes_reg_1) || // wx bypass from way 1
                        (addr_rd_mw_r_0 == addr_rd_dx_r_0 && instr_dx_writes_reg_0) || // mx bypass from way 0
                        (addr_rd_mw_r_0 == addr_rd_dx_r_1 && instr_dx_writes_reg_1) ) && // mx bypass from way 1 
                        (instr_mw_writes_reg_0 && !is_nop_mw_0);  // instruction in wb actually writesback...

 wire bypass_to_1 =   ((addr_rd_mw_r_1 == addr_rd_xm_r_1 && instr_xm_writes_reg_1) || // wx bypass from way 1
                        (addr_rd_mw_r_1 == addr_rd_xm_r_0 && instr_xm_writes_reg_0) || // wx bypass from way 0
                        (addr_rd_mw_r_1 == addr_rd_dx_r_1 && instr_dx_writes_reg_1) || // mx bypass from way 1 
                        (addr_rd_mw_r_1 == addr_rd_dx_r_0 && instr_dx_writes_reg_0) ) && // mx bypass from way 0
                        (instr_mw_writes_reg_1 && !is_nop_mw_1);  // instruction in wb actually writesback...
                      
  // way 0
  wire wd_stall_0 = (addr_rd_mw_r_0 == addr_rs1_w_0 && addr_rs1_w_0 != 0 && !is_u_type_0 && !is_j_type_0 && !bypass_to_0) ||  // check rs1 of WB in way 0 and D
                    (addr_rd_mw_r_1 == addr_rs1_w_0 && addr_rs1_w_0 != 0 && !is_u_type_0 && !is_j_type_0 && !bypass_to_1) ||  // check rs1 of WB in way 1 and D
                    (addr_rd_mw_r_0 == addr_rs2_w_0 && addr_rs2_w_0 != 0 && !is_u_type_0 && !is_j_type_0 && !is_i_type_0 && !bypass_to_0) ||  // check rs2 of WB in way 0 and D
                    (addr_rd_mw_r_1 == addr_rs2_w_0 && addr_rs2_w_0 != 0 && !is_u_type_0 && !is_j_type_0 && !is_i_type_0 && !bypass_to_1); // check rs2 of WB in way 1 and D

  // way 1
  wire wd_stall_1 = (addr_rd_mw_r_0 == addr_rs1_w_1 && addr_rs1_w_1 != 0 && !is_u_type_1 && !is_j_type_1 && !bypass_to_0) ||  // check rs1 of WB in way 0 and D
                    (addr_rd_mw_r_1 == addr_rs1_w_1 && addr_rs1_w_1 != 0 && !is_u_type_1 && !is_j_type_1 && !bypass_to_1) ||  // check rs1 of WB in way 1 and D
                    (addr_rd_mw_r_0 == addr_rs2_w_1 && addr_rs2_w_1 != 0 && !is_u_type_1 && !is_j_type_1 && !is_i_type_1 && !bypass_to_0) ||  // check rs2 of WB in way 0 and D
                    (addr_rd_mw_r_1 == addr_rs2_w_1 && addr_rs2_w_1 != 0 && !is_u_type_1 && !is_j_type_1 && !is_i_type_1 && !bypass_to_1); // check rs2 of WB in way 1 and D

    
  // way 0
  wire store_rs2_stall_0 = is_store_fd_0 &&
                           ((addr_rd_xm_r_0 == addr_rs2_w_0 && instr_xm_writes_reg_0 && !is_nop_xm_0) || // conflict with way 0
                            (addr_rd_xm_r_1 == addr_rs2_w_0 && instr_xm_writes_reg_1 && !is_nop_xm_1));   // conflict with way 1 

  // way 1
  wire store_rs2_stall_1 = is_store_fd_1 &&
                           ((addr_rd_xm_r_0 == addr_rs2_w_1 && instr_xm_writes_reg_0 && !is_nop_xm_0) || // conflict with way 0
                            (addr_rd_xm_r_1 == addr_rs2_w_1 && instr_xm_writes_reg_1 && !is_nop_xm_1));   // conflict with way 1 

 // STALLS FOR SUPERSCALAR:
 // write-use case between ways --> 2 consecutive instructions (taken by way0 and way1) are writing to/accessing same register value
  wire insn_writes_reg_fd_0 = (addr_rd_w_0 != 0) && !(opcode_w_0 == STORE_OPCODE || opcode_w_0 == BRANCH_OPCODE || opcode_w_0 == ECALL_OPCODE);

  wire two_way_write_use_case = insn_writes_reg_fd_0 && 
                                !is_u_type_1 && !is_j_type_1 && 
                                ((addr_rd_w_0 == addr_rs1_w_1 && addr_rs1_w_1 != 0) || (addr_rd_w_0 == addr_rs2_w_1 && addr_rs2_w_1 != 0 && !is_i_type_1));

  // Combine stalls
    // way 0
  assign stall_0 = (load_stall_0 || wd_stall_0 || store_rs2_stall_0) && !(!stall_fd_0 && stall_fd_1);

    // way 1
  assign stall_1 = load_stall_1 || wd_stall_1 || store_rs2_stall_1 || two_way_write_use_case;


// Other signals used by other logic
assign instr_mw_writes_reg_0_op = instr_mw_writes_reg_0;
assign instr_mw_writes_reg_1_op = instr_mw_writes_reg_1;  

endmodule