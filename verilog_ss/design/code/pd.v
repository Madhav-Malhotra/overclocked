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
  wire fetch_en = 1;
  wire fd_en_0 = 1;
  wire fd_en_1 = 1;
  wire dx_en_0 = 1;
  wire dx_en_1 = 1;
  wire xm_en_0 = 1;
  wire xm_en_1 = 1;
  wire mw_en_0 = 1;
  wire mw_en_1 = 1;


// ================================ 
// INPUTS/OUTPUTS TO MODULES: 
// ================================
  // IMEMORY INPUTS
  reg [DATAW-1:0] pc_r_0; // each way has own pc value (to reflect instruction being processed)
  reg [DATAW-1:0] pc_r_1;

  wire [63:0] instr_w;       // output line into pipeline register
  wire [31:0] instr_w_upper = instr_w[63:32];
  wire [31:0] instr_w_lower = instr_w[31:0];

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
  wire reg_wen_0;
  wire pc_sel_0;
  wire br_un_0;
  wire [1:0] a_sel_0;
  wire [1:0] b_sel_0;
  wire [1:0] branch_comp_data1_sel_0;
  wire [1:0] branch_comp_data2_sel_0;
  wire [3:0] alu_sel_0;
  wire [1:0] wb_sel_0;
  wire br_eq_0;
  wire br_lt_0;
  wire br_taken_0;                  // Not needed for CPU. Just for test file

    // Control Signals
  wire reg_wen_1;
  wire pc_sel_1;
  wire br_un_1;
  wire [1:0] a_sel_1;
  wire [1:0] b_sel_1;
  wire [1:0] branch_comp_data1_sel_1;
  wire [1:0] branch_comp_data2_sel_1;
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
  wire [DATAW-1:0] pc4_f_w_0 = pc_r_0 + 8;    // NEED ADD MUX TO SELECT PC+4 FOR STALLING LOGIC
  wire [DATAW-1:0] pc4_f_w_1 = pc_r_1 + 8;    // NEED ADD MUX TO SELECT PC+4 FOR STALLING LOGIC


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
  wire is_load_dx_0 = (opcode_dx_r_0 == LOAD_OPCODE); // DX instruction is load
  wire is_store_fd_0 = (opcode_w_0 == STORE_OPCODE);  // FD instruction is store
  wire is_load_xm_0 = (opcode_xm_r_0 == LOAD_OPCODE);

  wire is_nop_mw_0 = (opcode_mw_r_0 == NOP_OPCODE && addr_rd_mw_r_0 == 0);
  wire is_nop_xm_0 = (opcode_xm_r_0 == NOP_OPCODE && addr_rd_xm_r_0 == 0);


  // stalls due to load hazard - load in X to rd, read rd in D
  wire load_stall_0 = is_load_dx_0 && 
               ((addr_rd_dx_r_0 == addr_rs1_w_0 && !is_u_type_0 && !is_j_type_0) || 
                (addr_rd_dx_r_0 == addr_rs2_w_0 && !is_u_type_0 && !is_j_type_0 && !is_store_fd_0 && !is_i_type_0));

  // stalls due to write data hazard (no WD forward path)
  // Doesn't involve x0 + is an opcode that writes to an rd
  wire instr_mw_writes_reg_0 = (addr_rd_mw_r_0 != 0) && 
    !(opcode_mw_r_0 == STORE_OPCODE || opcode_mw_r_0 == BRANCH_OPCODE || opcode_mw_r_0 == ECALL_OPCODE); 

  //way 2
  wire instr_mw_writes_reg_1 = (addr_rd_mw_r_1!= 0) && 
  !(opcode_mw_r_1 == STORE_OPCODE ||opcode_mw_r_1 == BRANCH_OPCODE || opcode_mw_r_1 == ECALL_OPCODE); 
  
  // + is an opcode that uses rs1/2
  wire wd_stall_0 = !is_nop_mw_0 && ( addr_rd_mw_r_0!= addr_rd_xm_r_0) && ( addr_rd_mw_r_0 != addr_rd_dx_r_0) && instr_mw_writes_reg_0 && (
    (addr_rd_mw_r_0 == addr_rs1_w_0 && addr_rs1_w_0 != 0 && !is_u_type_0 && !is_j_type_0) || 
    (addr_rd_mw_r_0 == addr_rs2_w_0 && addr_rs2_w_0 != 0 && !is_u_type_0 && !is_j_type_0 && !is_i_type_0) 
  );

  // stalls for load-store extreme dependency
  wire load_store_stall_0 = is_load_xm_0 && is_store_fd_0 &&
    (addr_rd_xm_r_0 == addr_rs1_w_0) && (addr_rd_xm_r_0 == addr_rs2_w_0);

  // Some instruction in mem stage writing to rs2 of store
  wire instr_xm_writes_reg_0 = (addr_rd_xm_r_0 != 0) && 
    !(opcode_xm_r_0 == STORE_OPCODE || opcode_xm_r_0 == BRANCH_OPCODE || opcode_xm_r_0 == ECALL_OPCODE);   
  wire store_rs2_stall_0 = is_store_fd_0 && (addr_rd_xm_r_0 == addr_rs2_w_0) 
    && instr_xm_writes_reg_0 && !is_nop_xm_0;


  // Combine stalls
  wire stall = load_stall_0 || wd_stall_0 || load_store_stall_0 || store_rs2_stall_0;
  wire imem_enable = !stall;

  // ===================
  // CONTROL/FSMs
  // ===================

  // Fetch unit reset and increment
  always @(posedge clock) begin
    if (reset) begin
      pc_r_0 <= BASE_ADDR;
      pc_r_1 <= BASE_ADDR + 4;
      imem_in_r <= 0;
    end else if (br_taken_0) begin          // NEED TO FIX THIS LOGIC
      pc_r_0 <= alu_out_w_0;
      pc_r_1 <= alu_out_w_1;
    end else if (stall || !fetch_en) begin // FIX THIS LOGIC
      pc_r_0 <= pc_r_0;  
      pc_r_1 <= pc_r_1;  
    end else begin
      pc_r_0 <= (pc_sel_0 == 1) ? alu_out_w_0 : pc4_f_w_0;
      pc_r_1 <= (pc_sel_1 == 1) ? alu_out_w_1 : pc4_f_w_1;
    end
  end 

  
  // ===================
  // PIPELINE LOGIC
  // ===================
  
  // Fetch-Decode stage
  reg stall_fd_0; 
  reg stall_fd_1; 
  reg [31:0] prev_instr_0;
  reg [31:0] prev_instr_1;


// way 1
  always @(posedge clock) begin
    if (reset) begin
      pc_fd_r_0 <= 0;
      prev_instr_0 <= 0;
      stall_fd_0 <= 1;
    end
    else if (!fd_en_0) begin
        pc_fd_r_0 <= pc_fd_r_0;
        prev_instr_0 <= prev_instr_0;
        stall_fd_0 <= stall_fd_0;
    end
    else if (br_taken_0) begin
      pc_fd_r_0 <= pc_r_0;
      prev_instr_0 <= NOP_INSTR;    // Insert NOP on branch taken
      stall_fd_0 <= 1;
    end
    else if (stall) begin
      pc_fd_r_0 <= pc_fd_r_0;          // Hold FD pipeline registers during stall
      prev_instr_0 <= (!stall_fd_0) ? instr_w_upper : prev_instr_0;
      stall_fd_0 <= 1;
    end
    else begin
      pc_fd_r_0 <= pc_r_0;
      prev_instr_0 <= instr_w_upper;
      stall_fd_0 <= 0;
    end
  end

// way 2
    always @(posedge clock) begin
    if (reset) begin
      pc_fd_r_1 <= 0;
      prev_instr_1 <= 0;
      stall_fd_1 <= 1;
    end
    else if (!fd_en_0) begin
        pc_fd_r_1 <= pc_fd_r_1;
        prev_instr_1 <= prev_instr_1;
        stall_fd_1 <= stall_fd_1;
    end
    else if (br_taken_1) begin
      pc_fd_r_1 <= pc_r_1;
      prev_instr_1 <= NOP_INSTR;    // Insert NOP on branch taken
      stall_fd_1 <= 1;
    end
    else if (stall) begin
      pc_fd_r_1 <= pc_fd_r_1;          // Hold FD pipeline registers during stall
      prev_instr_1 <= (!stall_fd_1) ? instr_w_lower : prev_instr_1;
      stall_fd_1 <= 1;
    end
    else begin
      pc_fd_r_1 <= pc_r_1;
      prev_instr_1 <= instr_w_lower;
      stall_fd_1 <= 0;
    end
  end

  wire [31:0] instr_fd_w_0 = (stall_fd_0) ? prev_instr_0 : instr_w_upper; 
  wire [31:0] instr_fd_w_1 = (stall_fd_1) ? prev_instr_1 : instr_w_lower; 


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
    else if (!dx_en_0) begin
      pc_dx_r_0 <= pc_dx_r_0;
      opcode_dx_r_0 <= opcode_dx_r_0;
      funct3_dx_r_0 <= funct3_dx_r_0;
      imm_dx_r_0 <= imm_dx_r_0;
      addr_rs1_dx_r_0 <= addr_rs1_dx_r_0;
      addr_rs2_dx_r_0 <= addr_rs2_dx_r_0;
      addr_rd_dx_r_0 <= addr_rd_dx_r_0;
      funct7_dx_r_0 <= funct7_dx_r_0;
    end
    else if (stall || br_taken_0) begin
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
    else if (!dx_en_1) begin
      pc_dx_r_1 <= pc_dx_r_1;
      opcode_dx_r_1 <= opcode_dx_r_1;
      funct3_dx_r_1 <= funct3_dx_r_1;
      imm_dx_r_1 <= imm_dx_r_1;
      addr_rs1_dx_r_1 <= addr_rs1_dx_r_1;
      addr_rs2_dx_r_1 <= addr_rs2_dx_r_1;
      addr_rd_dx_r_1 <= addr_rd_dx_r_1;
      funct7_dx_r_1 <= funct7_dx_r_1;
    end
    else if (stall || br_taken_1) begin
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
// way 1
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
    else if (!xm_en_0) begin
      pc_xm_r_0 <= pc_xm_r_0;
      imm_xm_r_0 <= imm_xm_r_0;
      funct3_xm_r_0 <= funct3_xm_r_0;
      data_rs2_xm_r_0 <= data_rs2_xm_r_0;
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

// way 2
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
    else if (!xm_en_1) begin
      pc_xm_r_1 <= pc_xm_r_1;
      imm_xm_r_1 <= imm_xm_r_1;
      funct3_xm_r_1 <= funct3_xm_r_1;
      data_rs2_xm_r_1 <= data_rs2_xm_r_1;
      alu_xm_r_1 <= 0;
      opcode_xm_r_1 <= 0;
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
    else if (!mw_en_0) begin
      pc_mw_r_0 <= pc_mw_r_0;
      opcode_mw_r_0 <= opcode_mw_r_0;
      addr_rd_mw_r_0 <= addr_rd_mw_r_0;
      alu_mw_r_0 <= alu_mw_r_0;
      funct3_mw_r_0 <= funct3_mw_r_0;
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
    else if (!mw_en_1) begin
      pc_mw_r_1 <= pc_mw_r_1;
      opcode_mw_r_1 <= opcode_mw_r_1;
      addr_rd_mw_r_1 <= addr_rd_mw_r_1;
      pc_mw_r_1 <= pc_mw_r_1;
      alu_mw_r_1 <= alu_mw_r_1;
      funct3_mw_r_1 <= funct3_mw_r_1;
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
    .address(pc_r_0),        // input
    .data_in(imem_in_r),     // input
    .read_write(imem_rw_w),  // input (hardcoded to 0)
    .enable(imem_enable),    // input 
    .data_out(instr_w)       // output
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
    .dx_en_0(dx_en_0),
    .xm_en_0(xm_en_0),
    .mw_en_0(mw_en_0),
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
    .dx_en_1(dx_en_1),
    .xm_en_1(xm_en_1),
    .mw_en_1(mw_en_1),
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
  localparam REG = 2'b00;
  localparam PC  = 2'b01;
  localparam WX_BYPASS = 2'b010;
  localparam WX_BYPASS = 2'b011;
  localparam MX_BYPASS = 2'b100;
  localparam MX_BYPASS = 2'b101;

  // branch forwarding logic (cases for WX and MX bypassing)

//way 0
  wire [DATAW-1:0] idata1_in_0 =  (branch_comp_data1_sel_0 == WX_BYPASS) ? data_rd_w_0:
                                (branch_comp_data1_sel_0 == MX_BYPASS) ? alu_xm_r_0 :
                                                                     data_rs1_w_0;

  wire [DATAW-1:0] idata2_in_0 =  (branch_comp_data2_sel_0 == WX_BYPASS) ? data_rd_w_0 :
                                (branch_comp_data2_sel_0 == MX_BYPASS) ? alu_xm_r_0 :
                                                                     data_rs2_w_0;

  // way 1

  wire [DATAW-1:0] idata1_in_1 =  (branch_comp_data1_sel_1 == WX_BYPASS) ? data_rd_w_1 :
                                (branch_comp_data1_sel_1 == MX_BYPASS) ? alu_xm_r_1 :
                                                                     data_rs1_w_0;

  wire [DATAW-1:0] idata2_in_1 =  (branch_comp_data2_sel_1 == WX_BYPASS) ? data_rd_w_1 :
                                (branch_comp_data2_sel_1 == MX_BYPASS) ? alu_xm_r_1 :
                                                                     data_rs2_w_1;
//way 0
  branch_comp bc1(
    .idata1(idata1_in_0),
    .idata2(idata2_in_0),
    .br_un(br_un_0),
    .br_eq(br_eq_0),
    .br_lt(br_lt_0)
  );

  //way 1
  branch_comp bc2(
    .idata1(idata1_in_1),
    .idata2(idata2_in_1),
    .br_un(br_un_1),
    .br_eq(br_eq_1),
    .br_lt(br_lt_1)
  );
  
  // A sel definitions (determines ALU input 1)
  assign alu_in1_w_0 = (a_sel_0 == REG) ? data_rs1_w_0 :
                     (a_sel_0 == PC) ? pc_dx_r_0 :
                     (a_sel_0 == WX_BYPASS) ? data_rd_w_0 :
                                            alu_xm_r_0;

  // B sel definitions (determines ALU input 2)
  localparam IMM  = 2'b01;
  assign alu_in2_w_0 = (b_sel_0 == REG) ? data_rs2_w_0 :
                     (b_sel_0 == IMM) ? imm_dx_r_0 :
                     (b_sel_0 == WX_BYPASS) ? data_rd_w_0 :
                                             alu_xm_r_0;

  // A sel definitions (determines ALU input 1)
  assign alu_in1_w_1 = (a_sel_1 == REG) ? data_rs1_w_1 :
                     (a_sel_1 == PC) ? pc_dx_r_1 :
                     (a_sel_1 == WX_BYPASS) ? data_rd_w_1 :
                                            alu_xm_r_1;

  // B sel definitions (determines ALU input 2)
  assign alu_in2_w_1 = (b_sel_1 == REG) ? data_rs2_w_1 :
                     (b_sel_1 == IMM) ? imm_dx_r_1 :
                     (b_sel_1 == WX_BYPASS) ? data_rd_w_1 :
                                             alu_xm_r_1;
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

  wire [1:0] mem_write_access_size_0 = funct3_xm_r_0[1:0];     // For testbench

  // way 2
  wire [1:0] mem_write_access_size_1 = funct3_xm_r_1[1:0];     // For testbench

  // WM bypass logic
  wire is_store_xm_0 = (opcode_xm_r_0 == STORE_OPCODE);  // Store instruction in XM stage
  wire is_store_xm_1 = (opcode_xm_r_1 == STORE_OPCODE);  // Store instruction in XM stage


  wire wm_forward_0 = is_store_xm_0 && 
                    (addr_rs2_xm_r_0 == addr_rd_mw_r_0) && 
                    (addr_rd_mw_r_0 != 0) && 
                    instr_mw_writes_reg_0;

  wire wm_forward_1 = is_store_xm_1 && 
                    (addr_rs2_xm_r_1 == addr_rd_mw_r_1) && 
                    (addr_rd_mw_r_1 != 0) && 
                    instr_mw_writes_reg_1;
  // Data memory instantiation based on forwarding logic
  wire [DATAW-1:0] dmem_data_in_0 = (wm_forward_0) ? data_rd_w_0 : data_rs2_xm_r_0;
  wire [DATAW-1:0] dmem_data_in_1 = (wm_forward_1) ? data_rd_w_1 : data_rs2_xm_r_1;


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