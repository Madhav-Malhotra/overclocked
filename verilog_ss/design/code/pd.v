// =============================================================================
// Module:      pd
// Description: Top-level 5-stage pipelined 2-way superscalar RV32Im processor.
//              Stages: Fetch (F) -> Decode (D) -> Execute (X) -> Memory (M) -> Writeback (W).
//              Implements hazard detection (load, write-data, load-store, store-rs2 stalls),
//              MX/WX/WM data forwarding, and branch resolution in the execute stage
//              (predict not-taken, 1-cycle penalty on taken branch) Same-cycle reads, 1-cycle writes. 
// Inputs:      clock - processor clock
//              reset - synchronous reset; returns PC to BASE_ADDR
// Outputs:     (none - all state is internal; testbench probes internal signals)
// =============================================================================
module pd #(
  parameter DATAW = 32,
  parameter BASE_ADDR = 32'h01000000,
  parameter ADDRW = $clog2(DATAW),
  parameter N_BITS = $clog2(DATAW)
)
(
  input clock,
  input reset
);

  // ===================
  // INSTANTIATE SIGNALS
  // ===================

  // enable signals for each pipeline stage
  // wire fetch_en = 1;
  // wire fd_en_0 = 1;
  // wire fd_en_1 = 1;
  // wire dx_en_0 = 1;
  // wire dx_en_1 = 1;
  // wire xm_en_0 = 1;
  // wire xm_en_1 = 1;
  // wire mw_en_0 = 1;
  // wire mw_en_1 = 1;


// ================================ 
// INPUTS/OUTPUTS TO MODULES: 
// ================================
  // IMEMORY INPUTS
  reg [DATAW-1:0] pc_r_0; // each way has own pc value (to reflect instruction being processed)
  reg [DATAW-1:0] pc_r_1;

  reg [31:0] instr_w_0;
  reg [31:0] instr_w_1;

  reg [DATAW-1:0] imem_in_r;      // unused input to imem

  wire imem_rw_w = 0;             // always 0 (read-only)
  
  // Decoder unit
    // way0
  wire [6:0] opcode_w_0;
  wire [ADDRW-1:0] addr_rd_w_0;
  wire [ADDRW-1:0] addr_rs1_w_0;
  wire [ADDRW-1:0] addr_rs2_w_0;
  wire [2:0] funct3_w_0;
  wire [6:0] funct7_w_0;
  wire [DATAW-1:0] imm_w_0;
  wire [N_BITS-1:0] shamt_w_0;
  wire is_u_type_0;
  wire is_j_type_0;
  wire is_i_type_0;

  // way1
  wire [6:0] opcode_w_1;
  wire [ADDRW-1:0] addr_rd_w_1;
  wire [ADDRW-1:0] addr_rs1_w_1;
  wire [ADDRW-1:0] addr_rs2_w_1;
  wire [2:0] funct3_w_1;
  wire [6:0] funct7_w_1;
  wire [DATAW-1:0] imm_w_1;
  wire [N_BITS-1:0] shamt_w_1;
  wire is_u_type_1;
  wire is_j_type_1;
  wire is_i_type_1;

  // Control Signals
    // way 0
  wire reg_wen_0;
  wire pc_sel_0;
  wire br_un_0;
  wire [2:0] a_sel_0;
  wire [2:0] b_sel_0;
  wire [2:0] branch_comp_data1_sel_0;
  wire [2:0] branch_comp_data2_sel_0;
  wire [3:0] alu_sel_0;
  wire [1:0] wb_sel_0;
  wire br_eq_0;
  wire br_lt_0;
  wire br_taken_0;                  // Not needed for CPU. Just for test file

    // way 1
  wire reg_wen_1;
  wire pc_sel_1;
  wire br_un_1;
  wire [2:0] a_sel_1;
  wire [2:0] b_sel_1;
  wire [2:0] branch_comp_data1_sel_1;
  wire [2:0] branch_comp_data2_sel_1;
  wire [3:0] alu_sel_1;
  wire [1:0] wb_sel_1;
  wire br_eq_1;
  wire br_lt_1;
  wire br_taken_1;                  // Not needed for CPU. Just for test file

  // Register file unit
  wire [DATAW-1:0] data_rs1_w_0;     // wire - register file output
  wire [DATAW-1:0] data_rs2_w_0;     // wire - register file output
  wire [DATAW-1:0] data_rs1_w_1;     // wire - register file output
  wire [DATAW-1:0] data_rs2_w_1;     // wire - register file output

  // ALU inputs
    // way 0
  wire [DATAW-1:0] alu_in1_w_0;
  wire [DATAW-1:0] alu_in2_w_0;
  wire [DATAW-1:0] alu_out_w_0;

  // way 1
  wire [DATAW-1:0] alu_in1_w_1;
  wire [DATAW-1:0] alu_in2_w_1;
  wire [DATAW-1:0] alu_out_w_1;

  // Data memory unit
    // way 0
  wire [DATAW-1:0] data_mem_w_0;
  wire data_mem_rw_0;
  
    // way 1
  wire [DATAW-1:0] data_mem_w_1;
  wire data_mem_rw_1;

  // Writeback unit
  wire [DATAW-1:0] data_rd_w_0; 
  wire [DATAW-1:0] data_rd_w_1;

  // PC + 8
  wire [DATAW-1:0] pc8_f_w_0 = pc_r_0 + 8;    
  wire [DATAW-1:0] pc8_f_w_1 = pc_r_1 + 8;

  // ====================
  // PIPELINE REGSITERS
  // ====================
  // Fetch Decode
    // way 0
  reg [DATAW-1:0] pc_fd_r_0;
  reg [DATAW-1:0] pc_dx_r_0;

    // way 1
  reg [DATAW-1:0] pc_fd_r_1;
  reg [DATAW-1:0] pc_dx_r_1;


  // Decode Execute
    // way 0
  reg [6:0] opcode_dx_r_0;
  reg [2:0] funct3_dx_r_0;
  reg [DATAW-1:0] imm_dx_r_0;
  reg [ADDRW-1:0] addr_rs1_dx_r_0;
  reg [ADDRW-1:0] addr_rs2_dx_r_0;
  reg [ADDRW-1:0] addr_rd_dx_r_0;
  reg [6:0] funct7_dx_r_0; 

  // way 1
  reg [6:0] opcode_dx_r_1;
  reg [2:0] funct3_dx_r_1;
  reg [DATAW-1:0] imm_dx_r_1;
  reg [ADDRW-1:0] addr_rs1_dx_r_1;
  reg [ADDRW-1:0] addr_rs2_dx_r_1;
  reg [ADDRW-1:0] addr_rd_dx_r_1;
  reg [6:0] funct7_dx_r_1; 
  
  // Execute Memory
    // way 0
  reg [DATAW-1:0] pc_xm_r_0;   
  reg [DATAW-1:0] imm_xm_r_0;
  reg [2:0] funct3_xm_r_0;
  reg [DATAW-1:0] alu_xm_r_0;
  reg [DATAW-1:0] data_rs2_xm_r_0;        // P.S. Class slides don't need rs1_xm
  reg [6:0] opcode_xm_r_0;                // Need for stalling logic
  reg [ADDRW-1:0] addr_rs2_xm_r_0;        // Need for forwarding logic
  reg [ADDRW-1:0] addr_rd_xm_r_0;         // Need to determine WB location

  // way 1
  reg [DATAW-1:0] pc_xm_r_1;   
  reg [DATAW-1:0] imm_xm_r_1;
  reg [2:0] funct3_xm_r_1;
  reg [DATAW-1:0] alu_xm_r_1;
  reg [DATAW-1:0] data_rs2_xm_r_1;        // P.S. Class slides don't need rs1_xm
  reg [6:0] opcode_xm_r_1;                // Need for stalling logic
  reg [ADDRW-1:0] addr_rs2_xm_r_1;        // Need for forwarding logic
  reg [ADDRW-1:0] addr_rd_xm_r_1;         // Need to determine WB location

  // Memory Writeback
    // way 0
  reg [DATAW-1:0] pc_mw_r_0;            // Need for signals.h test
  reg [6:0] opcode_mw_r_0;              // Need for stalling logic
  reg [ADDRW-1:0] addr_rd_mw_r_0;       // Need to determine WB location

  // way 1
  reg [DATAW-1:0] pc_mw_r_1;            // Need for signals.h test
  reg [6:0] opcode_mw_r_1;              // Need for stalling logic
  reg [ADDRW-1:0] addr_rd_mw_r_1;       // Need to determine WB location

  // ====================
  // STALL LOGIC
  // ====================
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

    //way 1
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
  wire stall_0 = (load_stall_0 || wd_stall_0 || store_rs2_stall_0) && !(!stall_fd_0 && stall_fd_1);
  wire imem_enable = !stall_0;

    // way 1
  wire stall_1 = load_stall_1 || wd_stall_1 || store_rs2_stall_1 || two_way_write_use_case;
  wire imem_enable_1 = !stall_1;

  // ===================
  // CONTROL/FSMs
  // ===================

  // Fetch unit reset and increment
  // way 0
  always @(posedge clock) begin
    if (reset) begin
      pc_r_0 <= BASE_ADDR;
      imem_in_r <= 0;
    end else if (br_taken_0) begin
      pc_r_0 <= alu_out_w_0;
    end else if(br_taken_1) begin
      pc_r_0 <= alu_out_w_1;
    end else if (stall_0 || stall_1) begin 
      pc_r_0 <= pc_r_0;  
    end else begin 
      pc_r_0 <= pc8_f_w_0;      // default: pc + 8


    end
  end 

  // way 1
  /* 
  For way 1: must stall when way 0 is stalling as well to prevent out of order execution way 1 memory and writeback stages occur before way 0
  */

always @(posedge clock) begin
    if (reset) begin
      pc_r_1 <= BASE_ADDR + 4;
    end else if (br_taken_0) begin        
      pc_r_1 <= alu_out_w_0 + 4;
    end else if (br_taken_1) begin
      pc_r_1 <= alu_out_w_1 + 4;
    end else if (stall_0 || stall_1) begin  // stall way 1 if either way 0 stalls or way 1 has to stall 
      pc_r_1 <= pc_r_1;  
    end else begin
      pc_r_1 <= pc8_f_w_1;    // default: pc + 8
    end
  end 
  
  // ===================
  // PIPELINE LOGIC
  // ===================
  
  // Fetch-Decode stage
  reg stall_fd_0;
  reg stall_fd_1;
  reg stalled_fd_1; 
  reg [31:0] prev_instr_0;
  reg [31:0] prev_instr_1;


// way 0
  always @(posedge clock) begin
    if (reset) begin
      pc_fd_r_0 <= 0;
      prev_instr_0 <= 0;
      stall_fd_0 <= 1;
    end
    else if (br_taken_0 || br_taken_1) begin
      pc_fd_r_0 <= pc_r_0;
      prev_instr_0 <= NOP_INSTR;    // Insert NOP on any taken branch taken (either way)
      stall_fd_0 <= 1;
    end
    else if (stall_0) begin
      pc_fd_r_0 <= pc_fd_r_0;          // Hold FD pipeline registers during stall
      prev_instr_0 <= (!stall_fd_0) ? instr_w_0 : prev_instr_0;
      stall_fd_0 <= 1;
    end else if(stall_1 && !stall_0) begin
      pc_fd_r_0 <= pc_fd_r_0;
      prev_instr_0 <= NOP_INSTR;
      stall_fd_0 <= 1;
    end
    // else if (!stall_fd_0 && stall_fd_1) begin 
    //   pc_fd_r_0 <= pc_fd_r_0;
    //   prev_instr_0 <= prev_instr_0;    // Insert NOP on branch taken
    //   stall_fd_0 <= 0;
    // end
    else begin
      pc_fd_r_0 <= pc_r_0;
      prev_instr_0 <= instr_w_0;
      stall_fd_0 <= 0;
    end
  end

// way 1
    always @(posedge clock) begin
    if (reset) begin
      pc_fd_r_1 <= 0;
      prev_instr_1 <= 0;
      stall_fd_1 <= 1;
    end
    else if (br_taken_0 || br_taken_1) begin
      pc_fd_r_1 <= pc_r_1;
      prev_instr_1 <= NOP_INSTR;    // Insert NOP on branch taken
      stall_fd_1 <= 1;
    end
    else if (stall_0 || stall_1) begin
      pc_fd_r_1 <= pc_fd_r_1;          // Hold FD pipeline registers during stall
      prev_instr_1 <= (!stall_fd_1) ? instr_w_1 : prev_instr_1;
      stall_fd_1 <= 1;
    end
    else begin
      pc_fd_r_1 <= pc_r_1;
      prev_instr_1 <= instr_w_1;
      stall_fd_1 <= 0;
    end
  end

  wire [31:0] instr_fd_w_0 = (stall_fd_0) ? prev_instr_0 : instr_w_0; 
  wire [31:0] instr_fd_w_1 = (stall_fd_1) ? prev_instr_1 : instr_w_1; 


  // Decode-Execute stage 
// way 0
  always @(posedge clock) begin
    if (reset) begin
      pc_dx_r_0 <= 0;
      opcode_dx_r_0 <= 0;
      funct3_dx_r_0 <= 0;
      imm_dx_r_0 <= 0;
      addr_rs1_dx_r_0 <= 0;
      addr_rs2_dx_r_0 <= 0;
      addr_rd_dx_r_0 <= 0;
      funct7_dx_r_0 <= 0;
    end
    else if (stall_0 || br_taken_0 || br_taken_1) begin 
      // Insert NOP only on branch taken
      pc_dx_r_0 <= pc_fd_r_0;
      opcode_dx_r_0 <= NOP_OPCODE;
      funct3_dx_r_0 <= 0;
      imm_dx_r_0 <= 0;
      addr_rs1_dx_r_0 <= 0;
      addr_rs2_dx_r_0 <= 0;
      addr_rd_dx_r_0 <= 0;
      funct7_dx_r_0 <= 0;
    end
    else begin
      // Normal pipeline progression
      pc_dx_r_0 <= pc_fd_r_0;
      opcode_dx_r_0 <= opcode_w_0;
      funct3_dx_r_0 <= funct3_w_0;
      imm_dx_r_0 <= imm_w_0;
      addr_rs1_dx_r_0 <= addr_rs1_w_0;
      addr_rs2_dx_r_0 <= addr_rs2_w_0;
      addr_rd_dx_r_0 <= addr_rd_w_0;
      funct7_dx_r_0 <= funct7_w_0;
    end
  end

// way 1
  always @(posedge clock) begin
    if (reset) begin
      pc_dx_r_1 <= 0;
      opcode_dx_r_1 <= 0;
      funct3_dx_r_1 <= 0;
      imm_dx_r_1 <= 0;
      addr_rs1_dx_r_1 <= 0;
      addr_rs2_dx_r_1 <= 0;
      addr_rd_dx_r_1 <= 0;
      funct7_dx_r_1 <= 0;
    end
    else if (stall_0 || stall_1 || br_taken_0 || br_taken_1) begin
      // Insert NOP only on branch taken
      pc_dx_r_1 <= pc_fd_r_1;
      opcode_dx_r_1 <= NOP_OPCODE;
      funct3_dx_r_1 <= 0;
      imm_dx_r_1 <= 0;
      addr_rs1_dx_r_1 <= 0;
      addr_rs2_dx_r_1 <= 0;
      addr_rd_dx_r_1 <= 0;
      funct7_dx_r_1 <= 0;
    end
    else begin
      // Normal pipeline progression
      pc_dx_r_1 <= pc_fd_r_1;
      opcode_dx_r_1 <= opcode_w_1;
      funct3_dx_r_1 <= funct3_w_1;
      imm_dx_r_1 <= imm_w_1;
      addr_rs1_dx_r_1 <= addr_rs1_w_1;
      addr_rs2_dx_r_1 <= addr_rs2_w_1;
      addr_rd_dx_r_1 <= addr_rd_w_1;
      funct7_dx_r_1 <= funct7_w_1;
    end
  end

  // Execute-Memory stage
// way 0
  always @(posedge clock) begin
    if (reset) begin
      pc_xm_r_0 <= 0;
      imm_xm_r_0 <= 0;
      funct3_xm_r_0 <= 0;
      data_rs2_xm_r_0 <= 0;
      alu_xm_r_0 <= 0;
      opcode_xm_r_0 <= 0;
      addr_rs2_xm_r_0 <= 0;
      addr_rd_xm_r_0 <= 0;
    end
    else begin
      pc_xm_r_0 <= pc_dx_r_0;             // Pipeline PC, rs2 data from last stage
      imm_xm_r_0 <= imm_dx_r_0; 
      funct3_xm_r_0 <= funct3_dx_r_0;
      data_rs2_xm_r_0 <= data_rs2_w_0; 
      alu_xm_r_0 <= alu_out_w_0;          // Pipeline ALU output
      opcode_xm_r_0 <= opcode_dx_r_0;     // Pipeline decoded instruction from last stage
      addr_rs2_xm_r_0 <= addr_rs2_dx_r_0;
      addr_rd_xm_r_0 <= addr_rd_dx_r_0;
    end
  end

// way 1
    always @(posedge clock) begin
    if (reset) begin
      pc_xm_r_1 <= 0;
      imm_xm_r_1 <= 0;
      funct3_xm_r_1 <= 0;
      data_rs2_xm_r_1 <= 0;
      alu_xm_r_1 <= 0;
      opcode_xm_r_1 <= 0;
      addr_rs2_xm_r_1 <= 0;
      addr_rd_xm_r_1 <= 0;
    end
    else if (br_taken_0) begin
      pc_xm_r_1 <= pc_dx_r_1;
      imm_xm_r_1 <= 0;
      funct3_xm_r_1 <= 0;
      data_rs2_xm_r_1 <= 0;
      alu_xm_r_1 <= 0;
      opcode_xm_r_1 <= NOP_OPCODE;
      addr_rs2_xm_r_1 <= 0;
      addr_rd_xm_r_1 <= 0;
    end

    else begin
      pc_xm_r_1 <= pc_dx_r_1;             // Pipeline PC, rs2 data from last stage
      imm_xm_r_1 <= imm_dx_r_1; 
      funct3_xm_r_1 <= funct3_dx_r_1;
      data_rs2_xm_r_1 <= data_rs2_w_1; 
      alu_xm_r_1 <= alu_out_w_1;          // Pipeline ALU output
      opcode_xm_r_1 <= opcode_dx_r_1;     // Pipeline decoded instruction from last stage
      addr_rs2_xm_r_1 <= addr_rs2_dx_r_1;
      addr_rd_xm_r_1 <= addr_rd_dx_r_1;
    end
  end

  // PC + 4 in MEM stage
  wire [DATAW-1:0] pc4_xm_w_0 = pc_xm_r_0 + 4;
  wire [DATAW-1:0] pc4_xm_w_1 = pc_xm_r_1 + 4;

  reg [DATAW-1:0] pc4_mw_r_0;
  reg [DATAW-1:0] alu_mw_r_0;
  reg [2:0] funct3_mw_r_0;

  reg [DATAW-1:0] pc4_mw_r_1;
  reg [DATAW-1:0] alu_mw_r_1;
  reg [2:0] funct3_mw_r_1;

  // Memory-Writeback stage
// way 0
    always @(posedge clock) begin
    if (reset) begin
      pc_mw_r_0 <= 0;
      opcode_mw_r_0 <= 0;
      addr_rd_mw_r_0 <= 0;
      alu_mw_r_0 <= 0;
      funct3_mw_r_0 <= 0;
    end 
    else begin
      pc_mw_r_0 <= pc_xm_r_0;
      opcode_mw_r_0 <= opcode_xm_r_0;
      addr_rd_mw_r_0 <= addr_rd_xm_r_0;
      pc4_mw_r_0 <= pc4_xm_w_0;
      alu_mw_r_0 <= alu_xm_r_0;
      funct3_mw_r_0 <= funct3_xm_r_0;
    end
  end

// way 1
  always @(posedge clock) begin
    if (reset) begin
      pc_mw_r_1 <= 0;
      opcode_mw_r_1 <= 0;
      addr_rd_mw_r_1 <= 0;
      pc_mw_r_1 <= 0;
      alu_mw_r_1 <= 0;
      funct3_mw_r_1 <= 0;
    end 
    else begin
      pc_mw_r_1 <= pc_xm_r_1;
      opcode_mw_r_1 <= opcode_xm_r_1;
      addr_rd_mw_r_1 <= addr_rd_xm_r_1;
      pc4_mw_r_1 <= pc4_xm_w_1;
      alu_mw_r_1 <= alu_xm_r_1;
      funct3_mw_r_1 <= funct3_xm_r_1;
    end
  end


  // ===================================
  // INSTANTIATE MODULES
  // ===================================
  imemory imem1(
    .clock(clock),           // input
    .address_0(pc_r_0),        // input
    .address_1(pc_r_1),        // input
    .data_in(imem_in_r),     // input
    .read_write(imem_rw_w),  // input (hardcoded to 0)
    .enable(imem_enable),    // input 
    .data_out_0(instr_w_0),       // output
    .data_out_1(instr_w_1)       // output

  );

  // way 0
  decoder dec1( 
    .instr(instr_fd_w_0),         // input
    .opcode(opcode_w_0),          // output
    .addr_rd(addr_rd_w_0),        // output
    .addr_rs1(addr_rs1_w_0),      // output
    .addr_rs2(addr_rs2_w_0),      // output
    .funct3(funct3_w_0),          // output
    .funct7(funct7_w_0),          // output
    .imm(imm_w_0),                // output
    .shamt(shamt_w_0),            // output
    .is_u_type_w(is_u_type_0),    // output
    .is_j_type_w(is_j_type_0),    // output
    .is_i_type_w(is_i_type_0)     // output
  );

  // way 1
  decoder dec2(
    .instr(instr_fd_w_1),         // input
    .opcode(opcode_w_1),          // output
    .addr_rd(addr_rd_w_1),        // output
    .addr_rs1(addr_rs1_w_1),      // output
    .addr_rs2(addr_rs2_w_1),      // output
    .funct3(funct3_w_1),          // output
    .funct7(funct7_w_1),          // output
    .imm(imm_w_1),                // output
    .shamt(shamt_w_1),            // output
    .is_u_type_w(is_u_type_1),    // output
    .is_j_type_w(is_j_type_1),    // output
    .is_i_type_w(is_i_type_1)     // output
  );


  register_file rf1(
    .clock(clock),          // input
    // way 0
    .write_enable(reg_wen_0), // input
    .addr_rs1(addr_rs1_w_0),  // input
    .addr_rs2(addr_rs2_w_0),  // input
    .addr_rd(addr_rd_mw_r_0), // input
    .data_rd(data_rd_w_0),    // input
    .data_rs1(data_rs1_w_0),  // output
    .data_rs2(data_rs2_w_0),   // output

    //way 1
    .write_enable_1(reg_wen_1), // input
    .addr_rs1_1(addr_rs1_w_1),  // input
    .addr_rs2_1(addr_rs2_w_1),  // input
    .addr_rd_1(addr_rd_mw_r_1), // input
    .data_rd_1(data_rd_w_1),    // input
    .data_rs1_1(data_rs1_w_1),  // output
    .data_rs2_1(data_rs2_w_1)   // output
  );

  wire [DATAW-1:0] data_rs1_stall_w = data_rs1_w_0;
  wire [DATAW-1:0] data_rs2_stall_w =  data_rs2_w_0;

  control_signals cs1(
    .clock(clock),
    .reset(reset),
    .opcode_dx_0(opcode_dx_r_0),      // input
    .opcode_xm_0(opcode_xm_r_0),      // input
    .opcode_mw_0(opcode_mw_r_0),      // input
    .funct3_0(funct3_dx_r_0),         // input
    .funct7_0(funct7_dx_r_0),         // input
    .br_eq_0(br_eq_0),                // input
    .br_lt_0(br_lt_0),                // input
    .addr_rs1_dx_0(addr_rs1_dx_r_0),  // input
    .addr_rs2_dx_0(addr_rs2_dx_r_0),  // input
    .addr_rd_xm_0(addr_rd_xm_r_0),    // input
    .addr_rd_mw_0(addr_rd_mw_r_0),    // input
    .br_taken_0(br_taken_0),          // output
    .branch_comp_data1_sel_0(branch_comp_data1_sel_0), // output
    .branch_comp_data2_sel_0(branch_comp_data2_sel_0), // output
    .pc_sel_0(pc_sel_0),              // output
    .br_un_0(br_un_0),                // output
    .a_sel_0(a_sel_0),                // output
    .b_sel_0(b_sel_0),                // output
    .alu_sel_0(alu_sel_0),            // output
    .mem_rw_0(data_mem_rw_0),         // output
    .reg_wen_0(reg_wen_0),            // output
    .wb_sel_0(wb_sel_0),              // output

// way 1
    .opcode_dx_1(opcode_dx_r_1),      // input
    .opcode_xm_1(opcode_xm_r_1),      // input
    .opcode_mw_1(opcode_mw_r_1),      // input
    .funct3_1(funct3_dx_r_1),         // input
    .funct7_1(funct7_dx_r_1),         // input
    .br_eq_1(br_eq_1),                // input
    .br_lt_1(br_lt_1),                // input
    .addr_rs1_dx_1(addr_rs1_dx_r_1),  // input
    .addr_rs2_dx_1(addr_rs2_dx_r_1),  // input
    .addr_rd_xm_1(addr_rd_xm_r_1),    // input
    .addr_rd_mw_1(addr_rd_mw_r_1),    // input
    .m_pc_0(pc_xm_r_0),               // input
    .x_pc_1(pc_dx_r_1),               // input
    .br_taken_1(br_taken_1),          // output
    .branch_comp_data1_sel_1(branch_comp_data1_sel_1), // output
    .branch_comp_data2_sel_1(branch_comp_data2_sel_1), // output
    .pc_sel_1(pc_sel_1),              // output
    .br_un_1(br_un_1),                // output
    .a_sel_1(a_sel_1),                // output
    .b_sel_1(b_sel_1),                // output
    .alu_sel_1(alu_sel_1),            // output
    .mem_rw_1(data_mem_rw_1),         // output
    .reg_wen_1(reg_wen_1),            // output
    .wb_sel_1(wb_sel_1)              // output
  );



  // Forwarding logic values
  localparam REG = 3'b000;
  localparam PC  = 3'b001; // for rs1
  localparam IMM  = 3'b001; // for rs2
  localparam WX_BYPASS_0 = 3'b010;
  localparam WX_BYPASS_1 = 3'b011;
  localparam MX_BYPASS_0 = 3'b100;
  localparam MX_BYPASS_1 = 3'b101;

  // branch forwarding logic (cases for WX and MX bypassing)

//way 0
  wire [DATAW-1:0] bc_data1_in_0 =  (branch_comp_data1_sel_0 == WX_BYPASS_0) ? data_rd_w_0:
                                  (branch_comp_data1_sel_0 == WX_BYPASS_1) ? data_rd_w_1:
                                  (branch_comp_data1_sel_0 == MX_BYPASS_0) ? alu_xm_r_0 :
                                  (branch_comp_data1_sel_0 == MX_BYPASS_1) ? alu_xm_r_1 :
                                        data_rs1_w_0;

  wire [DATAW-1:0] bc_idata2_in_0 =  (branch_comp_data2_sel_0 == WX_BYPASS_0) ? data_rd_w_0 :
                                  (branch_comp_data2_sel_0 == WX_BYPASS_1) ? data_rd_w_1 :
                                  (branch_comp_data2_sel_0 == MX_BYPASS_0) ? alu_xm_r_0 :
                                  (branch_comp_data2_sel_0 == MX_BYPASS_1) ? alu_xm_r_1 :
                                        data_rs2_w_0;

  // way 1

  wire [DATAW-1:0] bc_idata1_in_1 =  (branch_comp_data1_sel_1 == WX_BYPASS_0) ? data_rd_w_0 :
                                  (branch_comp_data1_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                                  (branch_comp_data1_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                                  (branch_comp_data1_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                        data_rs1_w_1;

  wire [DATAW-1:0] bc_idata2_in_1 =  (branch_comp_data2_sel_1 == WX_BYPASS_0) ? data_rd_w_0:
                                  (branch_comp_data2_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                                  (branch_comp_data2_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                                  (branch_comp_data2_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                        data_rs2_w_1;
//way 0
  branch_comp bc1(
    .idata1(bc_data1_in_0),
    .idata2(bc_idata2_in_0),
    .br_un(br_un_0),
    .br_eq(br_eq_0),
    .br_lt(br_lt_0)
  );

  //way 1
  branch_comp bc2(
    .idata1(bc_idata1_in_1),
    .idata2(bc_idata2_in_1),
    .br_un(br_un_1),
    .br_eq(br_eq_1),
    .br_lt(br_lt_1)
  );
  
  // way 0
    // A sel definitions (determines ALU input 1)
  assign alu_in1_w_0 = (a_sel_0 == PC) ? pc_dx_r_0 :
                       (a_sel_0 == WX_BYPASS_0) ? data_rd_w_0 : 
                       (a_sel_0 == WX_BYPASS_1) ? data_rd_w_1 :
                       (a_sel_0 == MX_BYPASS_0) ? alu_xm_r_0 :
                       (a_sel_0 == MX_BYPASS_1) ? alu_xm_r_1 :
                                                  data_rs1_w_0; // default --> use decoded way 0 rs1 value

  // B sel definitions (determines ALU input 2)
  assign alu_in2_w_0 = (b_sel_0 == IMM) ? imm_dx_r_0 :
                       (b_sel_0 == WX_BYPASS_0) ? data_rd_w_0 :
                       (b_sel_0 == WX_BYPASS_1) ? data_rd_w_1 :
                       (b_sel_0 == MX_BYPASS_0) ? alu_xm_r_0 :
                       (b_sel_0 == MX_BYPASS_1) ? alu_xm_r_1 :
                                                  data_rs2_w_0; // default --> use decoded way 0 rs2 value

// way 1
  // A sel definitions (determines ALU input 1)
  assign alu_in1_w_1 =  (a_sel_1 == PC) ? pc_dx_r_1 :
                        (a_sel_1 == WX_BYPASS_0) ? data_rd_w_0 :
                        (a_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                        (a_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                        (a_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                                  data_rs1_w_1 ; // default --> use decoded way 1 rs1 value

  // B sel definitions (determines ALU input 2)
  assign alu_in2_w_1 = 
                     (b_sel_1 == IMM) ? imm_dx_r_1 :
                     (b_sel_1 == WX_BYPASS_0) ? data_rd_w_0 :
                     (b_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                     (b_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                     (b_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                             data_rs2_w_1 ; // default --> use decoded way 1 rs2 value
  // way 0
  alu al1(
    .idata1(alu_in1_w_0),
    .idata2(alu_in2_w_0),
    .alu_sel(alu_sel_0),
    .odata(alu_out_w_0)
  );

  //way 2
  alu al2(
    .idata1(alu_in1_w_1),
    .idata2(alu_in2_w_1),
    .alu_sel(alu_sel_1),
    .odata(alu_out_w_1)
  );

  // way 1
  wire [1:0] mem_write_access_size_0 = funct3_xm_r_0[1:0];     // For testbench

  // way 2
  wire [1:0] mem_write_access_size_1 = funct3_xm_r_1[1:0];     // For testbench


  // WM bypass logic  
  wire is_store_xm_0 = (opcode_xm_r_0 == STORE_OPCODE);  // Store instruction in XM stage
  wire is_store_xm_1 = (opcode_xm_r_1 == STORE_OPCODE);  // Store instruction in XM stage

  wire stall_occured = (pc_xm_r_1 - pc_mw_r_0 == 4);  // ONCE STALLING LOGIC IS CONFIRMED, USE THAT INSTEAD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  wire wm_forward_way0_0 = is_store_xm_0 &&               //from way 0 write into way 0 mem
                    (addr_rs2_xm_r_0 == addr_rd_mw_r_0) && 
                    (addr_rd_mw_r_0 != 0) && 
                    instr_mw_writes_reg_0;

  wire wm_forward_way1_0 = is_store_xm_0 &&                 //from way 1 write into way 0 mem
                    (addr_rs2_xm_r_0 == addr_rd_mw_r_1) && 
                    (addr_rd_mw_r_1 != 0) && 
                    instr_mw_writes_reg_1;

  wire wm_forward_way0_1 = is_store_xm_1 && 
                    (addr_rs2_xm_r_1 == addr_rd_mw_r_0) &&  //from way 0 write into way 1 mem
                    (addr_rd_mw_r_0 != 0) && 
                    instr_mw_writes_reg_0;

  wire wm_forward_way1_1 = is_store_xm_1 &&               //from way 1 write into way 1 mem
                    (addr_rs2_xm_r_1 == addr_rd_mw_r_1) &&  
                    (addr_rd_mw_r_1 != 0) && 
                    instr_mw_writes_reg_1;

  // Data memory instantiation based on forwarding logic
// way 0
  wire [DATAW-1:0] dmem_data_in_0 = (wm_forward_way1_0) ? data_rd_w_1 : // WM bypass from way 1 (younger)
                                    (wm_forward_way0_0) ? data_rd_w_0 : // WM bypass from way 0
                                    data_rs2_xm_r_0; // default: store's own rs2


/*
Way 1:  
  CASE 1: way 0 and way 1 don't have the same rd --> follow same bypassing logic as way 1
  CASE 2: way 0 and way 1 have same rd --> way 1 must stall, and in next cycle, can now do an WM bypass from way 0 to way 1
      - Can check if case 2 occured by comparing pc values of way 0 in writeback and way 1 in memory, pc_xm_r_1 - pc_mw_r_0 = 4 bytes, we can do WM bypass  
*/
  wire [DATAW-1:0] dmem_data_in_1 = (stall_occured) ?
                            ((wm_forward_way0_1) ? data_rd_w_0 : // WM bypass from way 0 (group partner)
                             (wm_forward_way1_1) ? data_rd_w_1 : // WM bypass from way 1
                             data_rs2_xm_r_1) // default: store's own rs2
                      :
                            ((wm_forward_way1_1) ? data_rd_w_1 : // WM bypass from way 1 (younger)
                             (wm_forward_way0_1) ? data_rd_w_0 : // WM bypass from way 0
                             data_rs2_xm_r_1); // default: store's own rs2

  dmemory dmem1(
    .clock(clock),               // input
    // way 0
    .read_write(data_mem_rw_0),   // input
    .access_size(mem_write_access_size_0),   // input
    .address(alu_xm_r_0),          // input
    .data_in(dmem_data_in_0),      // input
    .data_out(data_mem_w_0),        // output

    //way 1
    .read_write_1(data_mem_rw_1),    // input
    .access_size_1(mem_write_access_size_1),   // input
    .address_1(alu_xm_r_1),          // input
    .data_in_1(dmem_data_in_1),      // input
    .data_out_1(data_mem_w_1)        // output
  );

  // Mem read access size logic
  wire [1:0] mem_read_access_size_0 = funct3_mw_r_0[1:0];  // For testbench

  //way 1
  wire [1:0] mem_read_access_size_1 = funct3_mw_r_1[1:0];  // For testbench

  localparam BYTE_OP = 2'b00;
  localparam HALF_OP = 2'b01;
  localparam WORD_OP = 2'b10;

  wire is_unsigned_0 = funct3_mw_r_0[2];
  wire is_unsigned_1 = funct3_mw_r_1[2];


  wire [DATAW-1:0] data_mem_w_sized_0 = 
    (mem_read_access_size_0 == BYTE_OP) ? 
      (is_unsigned_0) ? {24'b0, data_mem_w_0[7:0]} :                             // LBU
      {{24{data_mem_w_0[7]}}, data_mem_w_0[7:0]} :                               // LB
    (mem_read_access_size_0 == HALF_OP) ? 
      (is_unsigned_0) ? {16'b0, data_mem_w_0[15:0]} :                            // LHU
      {{16{data_mem_w_0[15]}}, data_mem_w_0[15:0]} :                             // LH
    (mem_read_access_size_0 == WORD_OP) ? data_mem_w_0 : data_mem_w_0;             // LW


// way 1
  wire [DATAW-1:0] data_mem_w_sized_1 = 
    (mem_read_access_size_1 == BYTE_OP) ? 
      (is_unsigned_1) ? {24'b0, data_mem_w_1[7:0]} :                             // LBU
      {{24{data_mem_w_1[7]}}, data_mem_w_1[7:0]} :                               // LB
    (mem_read_access_size_1 == HALF_OP) ? 
      (is_unsigned_1) ? {16'b0, data_mem_w_1[15:0]} :                            // LHU
      {{16{data_mem_w_1[15]}}, data_mem_w_1[15:0]} :                             // LH
    (mem_read_access_size_1 == WORD_OP) ? data_mem_w_1 : data_mem_w_1;             // LW

  // According to lecture slides, this should be in the memory stage
  writeback wb1(
    // way 0
    .alu(alu_mw_r_0),                 // input
    .mem(data_mem_w_sized_0),         // input
    .pc4(pc4_mw_r_0),                 // input
    .wb_sel(wb_sel_0),                // input
    .wb_data(data_rd_w_0),             // output

    //way 1
    .alu_1(alu_mw_r_1),                 // input
    .mem_1(data_mem_w_sized_1),         // input
    .pc4_1(pc4_mw_r_1),                 // input
    .wb_sel_1(wb_sel_1),                // input
    .wb_data_1(data_rd_w_1)             // output
  );

endmodule