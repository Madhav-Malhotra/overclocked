// =============================================================================
// Module:      pd
// Description: Top-level 5-stage pipelined 2-way superscalar RV32Im processor.
//              Stages: Fetch (F) -> Decode (D) -> Execute (X) -> Memory (M) -> Writeback (W).
//              Implements hazard detection (load, write-data, load-store, store-rs2, inter-way stalls),
//              MX/WX/WM data forwarding, and branch resolution in the execute stage
//              (predict not-taken, 1-cycle penalty on taken branch) Same-cycle reads, 1-cycle writes. 
//              Each way owns an independent multicycle array_mult unit (instanced inside its ALU),
//              so a MUL in one way does not block the other way's multiplier hardware.
// Inputs:      clock - processor clock
//              reset - synchronous reset; returns PC to BASE_ADDR
// Outputs:     (none - all state is internal; testbench probes internal signals)
// =============================================================================
module pd #(
  parameter DATAW = 32,
  parameter BASE_ADDR = 32'h01000000,
  parameter ADDRW = $clog2(DATAW),
  parameter N_BITS = $clog2(DATAW),
  // 1: multicycle array_mult (stalls pipeline); 0: single-cycle MUL in ALU
  parameter USE_MULTICYCLE_MULT = 1'b0
)
(
  input clock,
  input reset
);

// ================================ 
// INPUTS/OUTPUTS TO MODULES: 
// ================================

  localparam MUL_ALU = 4'd11;   // alu_sel encoding for MUL (used to detect MUL in EX)

  // IMEMORY INPUTS
  reg [DATAW-1:0] pc_r_0; // each way has own pc value (to reflect instruction being processed)
  reg [DATAW-1:0] pc_r_1;

  reg [31:0] instr_w_0;
  reg [31:0] instr_w_1;

  reg [DATAW-1:0] imem_in_r;      // unused input to imem
  wire imem_rw_w = 0;             // always 0 (read-only)
  wire imem_en = !(fetch_stall);

  // Decoder unit signals
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

  // Stalling Signals Unit (data-hazard stalls only; multicycle-mult stalls are separate)
  wire stall_0;
  wire stall_1;
  wire instr_mw_writes_reg_0;
  wire instr_mw_writes_reg_1;

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
    // way 0
  wire [DATAW-1:0] data_rs1_w_0;     // wire - decoded register file values 
  wire [DATAW-1:0] data_rs2_w_0;     
    // way 1
  wire [DATAW-1:0] data_rs1_w_1;     
  wire [DATAW-1:0] data_rs2_w_1;     

  wire [DATAW-1:0] data_rs1_dx_1;
  wire [DATAW-1:0] data_rs2_dx_1;

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
  wire [DATAW-1:0] pc8_f_w_0 = pc_r_0 + 8; // way 0: takes base instruction + 8 and so on
  wire [DATAW-1:0] pc8_f_w_1 = pc_r_1 + 8; // way 1: takes (base instruction + 4) + 8 and so on


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
  localparam STORE_OPCODE = 7'b0100011;

  // ------------------------------------------------------------------
  // Multicycle multiply stall (per way)
  // ------------------------------------------------------------------

  // way 0
  wire is_mul_exec_0     = (alu_sel_0 == MUL_ALU);
  wire array_mult_hold_0 = USE_MULTICYCLE_MULT && is_mul_exec_0;
  wire array_mult_busy_0;
  reg  array_mult_busy_d1_0;
  reg  prev_is_mul_0;
  reg  [DATAW-1:0] prev_pc_dx_r_0;
  always @(posedge clock) begin
    if (reset) begin
      array_mult_busy_d1_0 <= 1'b0;
      prev_is_mul_0        <= 1'b0;
      prev_pc_dx_r_0        <= {DATAW{1'b0}};
    end else begin
      array_mult_busy_d1_0 <= array_mult_busy_0;
      prev_is_mul_0        <= is_mul_exec_0;
      prev_pc_dx_r_0        <= pc_dx_r_0;
    end
  end
  wire mul_just_started_0 = USE_MULTICYCLE_MULT && is_mul_exec_0 &&
      (!prev_is_mul_0 || (pc_dx_r_0 != prev_pc_dx_r_0));
  wire array_mult_start_0 = USE_MULTICYCLE_MULT && mul_just_started_0;
  wire mul_stall_0 = USE_MULTICYCLE_MULT &&
    (array_mult_busy_0 || array_mult_busy_d1_0 || mul_just_started_0);

  // way 1
  wire is_mul_exec_1     = (alu_sel_1 == MUL_ALU);
  wire array_mult_hold_1 = USE_MULTICYCLE_MULT && is_mul_exec_1;
  wire array_mult_busy_1;
  reg  array_mult_busy_d1_1;
  reg  prev_is_mul_1;
  reg  [DATAW-1:0] prev_pc_dx_r_1;
  always @(posedge clock) begin
    if (reset) begin
      array_mult_busy_d1_1 <= 1'b0;
      prev_is_mul_1        <= 1'b0;
      prev_pc_dx_r_1        <= {DATAW{1'b0}};
    end else begin
      array_mult_busy_d1_1 <= array_mult_busy_1;
      prev_is_mul_1        <= is_mul_exec_1;
      prev_pc_dx_r_1        <= pc_dx_r_1;
    end
  end
  wire mul_just_started_1 = USE_MULTICYCLE_MULT && is_mul_exec_1 &&
      (!prev_is_mul_1 || (pc_dx_r_1 != prev_pc_dx_r_1));
  wire array_mult_start_1 = USE_MULTICYCLE_MULT && mul_just_started_1;
  wire mul_stall_1 = USE_MULTICYCLE_MULT &&
    (array_mult_busy_1 || array_mult_busy_d1_1 || mul_just_started_1);

  // Either way's MUL freezes fetch (the two ways must stay fetch-paired).
  wire fetch_stall = stall_0 || stall_1 || mul_stall_0 || mul_stall_1;

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
    end else if (fetch_stall) begin
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
    end else if (fetch_stall) begin  // stall way 1 if either way 0 stalls or way 1 has to stall 
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
    else if (stall_0 || mul_stall_0) begin
      pc_fd_r_0 <= pc_fd_r_0;          // Hold FD pipeline registers during stall
      prev_instr_0 <= (!stall_fd_0) ? instr_w_0 : prev_instr_0;
      stall_fd_0 <= 1;
    end else if (mul_stall_1) begin
      pc_fd_r_0 <= pc_fd_r_0;
      prev_instr_0 <= (!stall_fd_0) ? instr_w_0 : prev_instr_0;
      stall_fd_0 <= 1;
    end else if (stall_1 && !stall_0) begin
      pc_fd_r_0 <= pc_fd_r_0;
      prev_instr_0 <= NOP_INSTR;
      stall_fd_0 <= 1;
    end
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
    else if (stall_0 || stall_1 || mul_stall_0 || mul_stall_1) begin
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
    else if (mul_stall_0) begin
      // Hold MUL in EX (way 0) while its array_mult computes; do not advance to XM.
      pc_dx_r_0 <= pc_dx_r_0;
      opcode_dx_r_0 <= opcode_dx_r_0;
      funct3_dx_r_0 <= funct3_dx_r_0;
      imm_dx_r_0 <= imm_dx_r_0;
      addr_rs1_dx_r_0 <= addr_rs1_dx_r_0;
      addr_rs2_dx_r_0 <= addr_rs2_dx_r_0;
      addr_rd_dx_r_0 <= addr_rd_dx_r_0;
      funct7_dx_r_0 <= funct7_dx_r_0;
    end
    else if (stall_0 || mul_stall_1 || br_taken_0 || br_taken_1) begin
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
    else if (mul_stall_1) begin
      // Hold MUL in EX (way 1) while its array_mult computes; do not advance to XM.
      pc_dx_r_1 <= pc_dx_r_1;
      opcode_dx_r_1 <= opcode_dx_r_1;
      funct3_dx_r_1 <= funct3_dx_r_1;
      imm_dx_r_1 <= imm_dx_r_1;
      addr_rs1_dx_r_1 <= addr_rs1_dx_r_1;
      addr_rs2_dx_r_1 <= addr_rs2_dx_r_1;
      addr_rd_dx_r_1 <= addr_rd_dx_r_1;
      funct7_dx_r_1 <= funct7_dx_r_1;
    end
    else if (mul_stall_0) begin
      // Way 0's MUL is stalling. Hold way 1's already-latched partner here
      // (do not advance to XM) so it retires alongside the MUL instead of
      // racing ahead of it
      pc_dx_r_1 <= pc_dx_r_1;
      opcode_dx_r_1 <= opcode_dx_r_1;
      funct3_dx_r_1 <= funct3_dx_r_1;
      imm_dx_r_1 <= imm_dx_r_1;
      addr_rs1_dx_r_1 <= addr_rs1_dx_r_1;
      addr_rs2_dx_r_1 <= addr_rs2_dx_r_1;
      addr_rd_dx_r_1 <= addr_rd_dx_r_1;
      funct7_dx_r_1 <= funct7_dx_r_1;
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
    else if (mul_stall_0) begin
      // Inject a bubble into XM (way 0) so the instruction that was in XM can
      // drain into MW without the in-flight MUL being re-latched every cycle.
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
    else if (mul_stall_1) begin
      // Inject a bubble into XM (way 1) so the instruction that was in XM can
      // drain into MW without the in-flight MUL being re-latched every cycle.
      pc_xm_r_1 <= 0;
      imm_xm_r_1 <= 0;
      funct3_xm_r_1 <= 0;
      data_rs2_xm_r_1 <= 0;
      alu_xm_r_1 <= 0;
      opcode_xm_r_1 <= 0;
      addr_rs2_xm_r_1 <= 0;
      addr_rd_xm_r_1 <= 0;
    end
    else if (mul_stall_0) begin
      // Way 0's MUL is stalling and way 1's partner is being held in DX
      // (see DX1 above), not advancing -- bubble XM1 too so it isn't
      // re-latched with the same (unchanged) DX1 contents every cycle.
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
    .enable(imem_en),    // input 
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

  stall_signals #(
        .DATAW(32),
        .ADDRW(5)   // $clog2(32) = 5
    ) u_stall_signals (
        .clock                      (clock),
        .reset                      (reset),

        // Stall Status Inputs
        .stall_fd_0                 (stall_fd_0),
        .stall_fd_1                 (stall_fd_1),

        // Opcodes 
        .opcode_w_0                 (opcode_w_0),
        .opcode_dx_r_0              (opcode_dx_r_0),
        .opcode_xm_r_0              (opcode_xm_r_0),
        .opcode_mw_r_0              (opcode_mw_r_0),

        .opcode_w_1                 (opcode_w_1),
        .opcode_dx_r_1              (opcode_dx_r_1),
        .opcode_xm_r_1              (opcode_xm_r_1),
        .opcode_mw_r_1              (opcode_mw_r_1),

        // Register Indices 
        .addr_rs1_w_0               (addr_rs1_w_0),
        .addr_rs2_w_0               (addr_rs2_w_0),
        .addr_rd_w_0                (addr_rd_w_0),
        .addr_rd_dx_r_0             (addr_rd_dx_r_0),
        .addr_rd_xm_r_0             (addr_rd_xm_r_0),
        .addr_rd_mw_r_0             (addr_rd_mw_r_0),

        .addr_rs1_w_1               (addr_rs1_w_1),
        .addr_rs2_w_1               (addr_rs2_w_1),
        .addr_rd_dx_r_1             (addr_rd_dx_r_1),
        .addr_rd_xm_r_1             (addr_rd_xm_r_1),
        .addr_rd_mw_r_1             (addr_rd_mw_r_1),

        // Instruction Types
        .is_u_type_0                (is_u_type_0),
        .is_j_type_0                (is_j_type_0),
        .is_i_type_0                (is_i_type_0),
        .is_u_type_1                (is_u_type_1),
        .is_j_type_1                (is_j_type_1),
        .is_i_type_1                (is_i_type_1),

        // outputs: will the pipeline stall
        .stall_0                    (stall_0),
        .stall_1                    (stall_1),
        .instr_mw_writes_reg_0_op   (instr_mw_writes_reg_0),
        .instr_mw_writes_reg_1_op   (instr_mw_writes_reg_1)
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
    .data_rs2_1(data_rs2_w_1),  // output

    // way 1 DX-stage combinational read (see data_rs1_dx_1 declaration above)
    .addr_rs1_dx_1(addr_rs1_dx_r_1), // input
    .addr_rs2_dx_1(addr_rs2_dx_r_1), // input
    .data_rs1_dx_1(data_rs1_dx_1),   // output
    .data_rs2_dx_1(data_rs2_dx_1)    // output
  );

  wire [DATAW-1:0] data_rs1_stall_w = data_rs1_w_0;
  wire [DATAW-1:0] data_rs2_stall_w =  data_rs2_w_0;

  control_signals cs1(
    .clock(clock),
    .reset(reset),
    .mul_stall_0(mul_stall_0),        // input: way 0 MUL stall so cs1 can bubble its XM regs
    .mul_stall_1(mul_stall_1),        // input: way 1 MUL stall so cs1 can bubble its XM regs
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
                                        data_rs1_dx_1;

  wire [DATAW-1:0] bc_idata2_in_1 =  (branch_comp_data2_sel_1 == WX_BYPASS_0) ? data_rd_w_0:
                                  (branch_comp_data2_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                                  (branch_comp_data2_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                                  (branch_comp_data2_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                        data_rs2_dx_1;
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
                                                  data_rs1_dx_1 ; // default --> use decoded way 1 rs1 value

  // B sel definitions (determines ALU input 2)
  assign alu_in2_w_1 = 
                     (b_sel_1 == IMM) ? imm_dx_r_1 :
                     (b_sel_1 == WX_BYPASS_0) ? data_rd_w_0 :
                     (b_sel_1 == WX_BYPASS_1) ? data_rd_w_1 :
                     (b_sel_1 == MX_BYPASS_0) ? alu_xm_r_0 :
                     (b_sel_1 == MX_BYPASS_1) ? alu_xm_r_1 :
                                             data_rs2_dx_1 ; // default --> DX-stage regfile read for way 1 rs2
  // way 0
  alu al1(
    .clock(clock),
    .reset(reset),
    .idata1(alu_in1_w_0),
    .idata2(alu_in2_w_0),
    .alu_sel(alu_sel_0),
    .multicyc_sel(USE_MULTICYCLE_MULT[0]), // 1 = MUL routed through this way's internal array_mult unit
    .mult_start_pulse(array_mult_start_0),  // one-cycle pulse when MUL first enters EX (way 0)
    .mult_hold(array_mult_hold_0),          // high while MUL occupies EX (way 0)
    .mult_busy(array_mult_busy_0),
    .odata(alu_out_w_0)
  );

  //way 1
  alu al2(
    .clock(clock),
    .reset(reset),
    .idata1(alu_in1_w_1),
    .idata2(alu_in2_w_1),
    .alu_sel(alu_sel_1),
    .multicyc_sel(USE_MULTICYCLE_MULT[0]), // 1 = MUL routed through this way's internal array_mult unit
    .mult_start_pulse(array_mult_start_1),  // one-cycle pulse when MUL first enters EX (way 1)
    .mult_hold(array_mult_hold_1),          // high while MUL occupies EX (way 1)
    .mult_busy(array_mult_busy_1),
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