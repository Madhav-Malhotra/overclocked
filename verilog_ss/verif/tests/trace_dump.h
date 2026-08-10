/** Trace format per cycle
* [F] pc_address content
* [D] pc_address opcode rd rs1 rs2 funct3 funct7 imm shamt
* [R] rs1 rs2 rd data_rs1 data_rs2 we
* [E] pc_address alu_result branch_taken
* [M] pc_address memory_address read_write memory_size memory_data
* [W] pc_address write rd datard
*/
integer __trace_fd;
initial begin
  __trace_fd = $fopen(`TRACE_FILE, "w");
end
always @(negedge clock) begin
  if(reset == 0) begin
    // F stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[F] %x %x\n",
      dut.core.`F_PC_0,
      dut.core.`F_INSN_0);
    $fflush(__trace_fd);
    
     // way 1 
    $fwrite(__trace_fd, "[F] %x %x\n",
      dut.core.`F_PC_1,
      dut.core.`F_INSN_1);
    $fflush(__trace_fd);
    
    // D stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[D] %x %x %x %x %x %x %x %x %x\n",
      dut.core.`D_PC_0,
      dut.core.`D_OPCODE_0,
      dut.core.`D_RD_0,
      dut.core.`D_RS1_0,
      dut.core.`D_RS2_0,
      dut.core.`D_FUNCT3_0,
      dut.core.`D_FUNCT7_0,
      dut.core.`D_IMM_0,
      dut.core.`D_SHAMT_0);
    $fflush(__trace_fd);

      // way 1
    $fwrite(__trace_fd, "[D] %x %x %x %x %x %x %x %x %x\n",
      dut.core.`D_PC_1,
      dut.core.`D_OPCODE_1,
      dut.core.`D_RD_1,
      dut.core.`D_RS1_1,
      dut.core.`D_RS2_1,
      dut.core.`D_FUNCT3_1,
      dut.core.`D_FUNCT7_1,
      dut.core.`D_IMM_1,
      dut.core.`D_SHAMT_1);
    $fflush(__trace_fd);
    
    // R stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[R] %x %x %x %x\n",
      dut.core.`R_READ_RS1_0,
      dut.core.`R_READ_RS2_0,
      dut.core.`R_READ_RS1_DATA_0,
      dut.core.`R_READ_RS2_DATA_0);
    $fflush(__trace_fd);

      // way 1
    $fwrite(__trace_fd, "[R] %x %x %x %x\n",
      dut.core.`R_READ_RS1_1,
      dut.core.`R_READ_RS2_1,
      dut.core.`R_READ_RS1_DATA_1,
      dut.core.`R_READ_RS2_DATA_1);
    $fflush(__trace_fd);

    // E stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[E] %x %x %x\n",
      dut.core.`E_PC_0,
      dut.core.`E_ALU_RES_0,
      dut.core.`E_BR_TAKEN_0);
    $fflush(__trace_fd);

      // way 1
    $fwrite(__trace_fd, "[E] %x %x %x\n",
      dut.core.`E_PC_1,
      dut.core.`E_ALU_RES_1,
      dut.core.`E_BR_TAKEN_1);
    $fflush(__trace_fd);

    
    // M stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[M] %x %x %x %x %x\n",
      dut.core.`M_PC_0,
      dut.core.`M_ADDRESS_0,
      dut.core.`M_RW_0,
      dut.core.`M_SIZE_ENCODED_0,
      dut.core.`M_DATA_0);
    $fflush(__trace_fd);

      // way 1
    $fwrite(__trace_fd, "[M] %x %x %x %x %x\n",
      dut.core.`M_PC_1,
      dut.core.`M_ADDRESS_1,
      dut.core.`M_RW_1,
      dut.core.`M_SIZE_ENCODED_1,
      dut.core.`M_DATA_1);
    $fflush(__trace_fd);
    
    // W stage trace dump ------------------------------
      // way 0
    $fwrite(__trace_fd, "[W] %x %x %x %x\n",
      dut.core.`W_PC_0,
      dut.core.`W_ENABLE_0,
      dut.core.`W_DESTINATION_0,
      dut.core.`W_DATA_0);
    $fflush(__trace_fd);

      // way 1
    $fwrite(__trace_fd, "[W] %x %x %x %x\n",
      dut.core.`W_PC_1,
      dut.core.`W_ENABLE_1,
      dut.core.`W_DESTINATION_1,
      dut.core.`W_DATA_1);
    $fflush(__trace_fd);
  
  end
end