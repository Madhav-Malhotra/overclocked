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
  wire fd_en = 1;
  wire dx_en = 1;
  wire dx_en_2 = 1;
  wire xm_en = 1;
  wire xm_en_2 = 1;
  wire mw_en = 1;
  wire mw_en_2 = 1;


  // Fetch unit
  reg [DATAW-1:0] pc_r;
  wire [63:0] instr_w;       // output line into pipeline register
  reg [DATAW-1:0] imem_in_r;      // unused input to imem
  wire imem_rw_w = 0;             // always 0 (read-only)

  // Decode unit
  wire [6:0] opcode_w;
  wire [ADDRW-1:0] addr_rd_w;
  wire [ADDRW-1:0] addr_rs1_w;
  wire [ADDRW-1:0] addr_rs2_w;
  wire [2:0] funct3_w;
  wire [6:0] funct7_w;
  wire [DATAW-1:0] imm_w;
  wire [N_BITS-1:0] shamt_w;
  wire is_u_type;
  wire is_j_type;
  wire is_i_type;

  wire [6:0] opcode_w_2;
  wire [ADDRW-1:0] addr_rd_w_2;
  wire [ADDRW-1:0] addr_rs1_w_2;
  wire [ADDRW-1:0] addr_rs2_w_2;
  wire [2:0] funct3_w_2;
  wire [6:0] funct7_w_2;
  wire [DATAW-1:0] imm_w_2;
  wire [N_BITS-1:0] shamt_w_2;
  wire is_u_type_2;
  wire is_j_type_2;
  wire is_i_type_2;

  // Control Signals
  wire reg_wen;
  wire pc_sel;
  wire br_un;
  wire [1:0] a_sel;
  wire [1:0] b_sel;
  wire [1:0] branch_comp_data1_sel;
  wire [1:0] branch_comp_data2_sel;
  wire [3:0] alu_sel;
  wire [1:0] wb_sel;
  wire br_eq;
  wire br_lt;
  wire br_taken;                  // Not needed for CPU. Just for test file

  // Register file unit
  wire [DATAW-1:0] data_rs1_w;     // wire - register file output
  wire [DATAW-1:0] data_rs2_w;     // wire - register file output
  wire [DATAW-1:0] data_rs1_w_2;     // wire - register file output
  wire [DATAW-1:0] data_rs2_w_2;     // wire - register file output

  // ALU inputs
  wire [DATAW-1:0] alu_in1_w;
  wire [DATAW-1:0] alu_in2_w;
  wire [DATAW-1:0] alu_out_w;

  wire [DATAW-1:0] alu_in1_w_2;
  wire [DATAW-1:0] alu_in2_w_2;
  wire [DATAW-1:0] alu_out_w_2;

  // Data memory unit
  wire [DATAW-1:0] data_mem_w;
  wire data_mem_rw;
  
  wire [DATAW-1:0] data_mem_w_2;
  wire data_mem_rw_2;

  // Writeback unit
  wire [DATAW-1:0] data_rd_w;
  wire [DATAW-1:0] data_rd_w_2;

  // PC + 8
  wire [DATAW-1:0] pc4_f_w = pc_r + 8;    // NEED ADD MUX TO SELECT PC+4 FOR STALLING LOGIC


  // ====================
  // PIPELINE REGSITERS
  // ====================
  // Fetch Decode
  reg [DATAW-1:0] pc_fd_r;
  reg [DATAW-1:0] pc_dx_r;

  // Decode Execute
  reg [6:0] opcode_dx_r;
  reg [2:0] funct3_dx_r;
  reg [DATAW-1:0] imm_dx_r;
  reg [ADDRW-1:0] addr_rs1_dx_r;
  reg [ADDRW-1:0] addr_rs2_dx_r;
  reg [ADDRW-1:0] addr_rd_dx_r;
  reg [6:0] funct7_dx_r; 

  reg [6:0] opcode_dx_r_2;
  reg [2:0] funct3_dx_r_2;
  reg [DATAW-1:0] imm_dx_r_2;
  reg [ADDRW-1:0] addr_rs1_dx_r_2;
  reg [ADDRW-1:0] addr_rs2_dx_r_2;
  reg [ADDRW-1:0] addr_rd_dx_r_2;
  reg [6:0] funct7_dx_r_2; 
  
  // Execute Memory
  reg [DATAW-1:0] pc_xm_r;   
  reg [DATAW-1:0] imm_xm_r;
  reg [2:0] funct3_xm_r;
  reg [DATAW-1:0] alu_xm_r;
  reg [DATAW-1:0] data_rs2_xm_r;        // P.S. Class slides don't need rs1_xm
  reg [6:0] opcode_xm_r;                // Need for stalling logic
  reg [ADDRW-1:0] addr_rs2_xm_r;        // Need for forwarding logic
  reg [ADDRW-1:0] addr_rd_xm_r;         // Need to determine WB location

  reg [DATAW-1:0] pc_xm_r_2;   
  reg [DATAW-1:0] imm_xm_r_2;
  reg [2:0] funct3_xm_r_2;
  reg [DATAW-1:0] alu_xm_r_2;
  reg [DATAW-1:0] data_rs2_xm_r_2;        // P.S. Class slides don't need rs1_xm
  reg [6:0] opcode_xm_r_2;                // Need for stalling logic
  reg [ADDRW-1:0] addr_rs2_xm_r_2;        // Need for forwarding logic
  reg [ADDRW-1:0] addr_rd_xm_r_2;         // Need to determine WB location

  // Memory Writeback
  reg [DATAW-1:0] pc_mw_r;            // Need for signals.h test
  reg [6:0] opcode_mw_r;              // Need for stalling logic
  reg [ADDRW-1:0] addr_rd_mw_r;       // Need to determine WB location

  reg [DATAW-1:0] pc_mw_r_2;            // Need for signals.h test
  reg [6:0] opcode_mw_r_2;              // Need for stalling logic
  reg [ADDRW-1:0] addr_rd_mw_r_2;       // Need to determine WB location

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
  wire is_load_dx = (opcode_dx_r == LOAD_OPCODE); // DX instruction is load
  wire is_store_fd = (opcode_w == STORE_OPCODE);  // FD instruction is store
  wire is_load_xm = (opcode_xm_r == LOAD_OPCODE);

  wire is_nop_mw = (opcode_mw_r == NOP_OPCODE && addr_rd_mw_r == 0);
  wire is_nop_xm = (opcode_xm_r == NOP_OPCODE && addr_rd_xm_r == 0);


  // stalls due to load hazard - load in X to rd, read rd in D
  wire load_stall = is_load_dx && 
               ((addr_rd_dx_r == addr_rs1_w && !is_u_type && !is_j_type) || 
                (addr_rd_dx_r == addr_rs2_w && !is_u_type && !is_j_type && !is_store_fd && !is_i_type));

  // stalls due to write data hazard (no WD forward path)
  // Doesn't involve x0 + is an opcode that writes to an rd
  wire instr_mw_writes_reg = (addr_rd_mw_r != 0) && 
    !(opcode_mw_r == STORE_OPCODE || opcode_mw_r == BRANCH_OPCODE || opcode_mw_r == ECALL_OPCODE); 
  // + is an opcode that uses rs1/2
  wire wd_stall = !is_nop_mw && (addr_rd_mw_r != addr_rd_xm_r) && (addr_rd_mw_r != addr_rd_dx_r) && instr_mw_writes_reg && (
    (addr_rd_mw_r == addr_rs1_w && addr_rs1_w != 0 && !is_u_type && !is_j_type) || 
    (addr_rd_mw_r == addr_rs2_w && addr_rs2_w != 0 && !is_u_type && !is_j_type && !is_i_type) 
  );

  // stalls for load-store extreme dependency
  wire load_store_stall = is_load_xm && is_store_fd &&
    (addr_rd_xm_r == addr_rs1_w) && (addr_rd_xm_r == addr_rs2_w);

  // Some instruction in mem stage writing to rs2 of store
  wire instr_xm_writes_reg = (addr_rd_xm_r != 0) && 
    !(opcode_xm_r == STORE_OPCODE || opcode_xm_r == BRANCH_OPCODE || opcode_xm_r == ECALL_OPCODE);   
  wire store_rs2_stall = is_store_fd && (addr_rd_xm_r == addr_rs2_w) 
    && instr_xm_writes_reg && !is_nop_xm;


  // Combine stalls
  wire stall = load_stall || wd_stall || load_store_stall || store_rs2_stall;
  wire imem_enable = !stall;

  // ===================
  // CONTROL/FSMs
  // ===================

  // Fetch unit reset and increment
  always @(posedge clock) begin
    if (reset) begin
      pc_r <= BASE_ADDR;
      imem_in_r <= 0;
    end
    else if (br_taken) begin          // ADD THIS BEFORE stall check
    pc_r <= alu_out_w;
  end
    else if (stall || !fetch_en ) begin
      pc_r <= pc_r;  // Hold PC value during stall
    end
    else begin
      pc_r <= (pc_sel == 1) ? alu_out_w : pc4_f_w;
    end
  end 

  
  // ===================
  // PIPELINE LOGIC
  // ===================
  
  // Fetch-Decode stage
  reg stall_fd; 
  reg [63:0] prev_instr;

  always @(posedge clock) begin
    if (reset) begin
      pc_fd_r <= 0;
      prev_instr <= 0;
      stall_fd <= 1;
    end
    else if (!fd_en) begin
        pc_fd_r <= pc_fd_r;
        prev_instr <= prev_instr;
        stall_fd <= stall_fd;
    end
    else if (br_taken) begin
      pc_fd_r <= pc_r;
      prev_instr <= NOP_INSTR;    // Insert NOP on branch taken
      stall_fd <= 1;
    end
    else if (stall) begin
      pc_fd_r <= pc_fd_r;          // Hold FD pipeline registers during stall
      prev_instr <= (!stall_fd) ? instr_w : prev_instr;
      stall_fd <= 1;
    end
    else begin
      pc_fd_r <= pc_r;
      prev_instr <= instr_w;
      stall_fd <= 0;
    end
  end

  wire [63:0] instr_fd_w = (stall_fd) ? prev_instr : instr_w; 

  // Decode-Execute stage 
// way 1
  always @(posedge clock) begin
    if (reset) begin
      pc_dx_r <= 0;
      opcode_dx_r <= 0;
      funct3_dx_r <= 0;
      imm_dx_r <= 0;
      addr_rs1_dx_r <= 0;
      addr_rs2_dx_r <= 0;
      addr_rd_dx_r <= 0;
      funct7_dx_r <= 0;
    end
    else if (!dx_en) begin
      pc_dx_r <= pc_dx_r;
      opcode_dx_r <= opcode_dx_r;
      funct3_dx_r <= funct3_dx_r;
      imm_dx_r <= imm_dx_r;
      addr_rs1_dx_r <= addr_rs1_dx_r;
      addr_rs2_dx_r <= addr_rs2_dx_r;
      addr_rd_dx_r <= addr_rd_dx_r;
      funct7_dx_r <= funct7_dx_r;
    end
    else if (stall || br_taken) begin
      // Insert NOP only on branch taken
      pc_dx_r <= pc_fd_r;
      opcode_dx_r <= NOP_OPCODE;
      funct3_dx_r <= 0;
      imm_dx_r <= 0;
      addr_rs1_dx_r <= 0;
      addr_rs2_dx_r <= 0;
      addr_rd_dx_r <= 0;
      funct7_dx_r <= 0;
    end
    else begin
      // Normal pipeline progression
      pc_dx_r <= pc_fd_r;
      opcode_dx_r <= opcode_w;
      funct3_dx_r <= funct3_w;
      imm_dx_r <= imm_w;
      addr_rs1_dx_r <= addr_rs1_w;
      addr_rs2_dx_r <= addr_rs2_w;
      addr_rd_dx_r <= addr_rd_w;
      funct7_dx_r <= funct7_w;
    end
  end

// way 2
  always @(posedge clock) begin
    if (reset) begin
      pc_dx_r <= 0;
      opcode_dx_r_2 <= 0;
      funct3_dx_r_2 <= 0;
      imm_dx_r_2 <= 0;
      addr_rs1_dx_r_2 <= 0;
      addr_rs2_dx_r_2 <= 0;
      addr_rd_dx_r_2 <= 0;
      funct7_dx_r_2 <= 0;
    end
    else if (!dx_en_2) begin
      // pc_dx_r <= pc_dx_r;
      opcode_dx_r_2 <= opcode_dx_r_2;
      funct3_dx_r_2 <= funct3_dx_r_2;
      imm_dx_r_2 <= imm_dx_r_2;
      addr_rs1_dx_r_2 <= addr_rs1_dx_r_2;
      addr_rs2_dx_r_2 <= addr_rs2_dx_r_2;
      addr_rd_dx_r_2 <= addr_rd_dx_r_2;
      funct7_dx_r_2 <= funct7_dx_r_2;
    end
    else if (stall || br_taken) begin
      // Insert NOP only on branch taken
      // pc_dx_r <= pc_fd_r;
      opcode_dx_r_2 <= NOP_OPCODE;
      funct3_dx_r_2 <= 0;
      imm_dx_r_2 <= 0;
      addr_rs1_dx_r_2 <= 0;
      addr_rs2_dx_r_2 <= 0;
      addr_rd_dx_r_2 <= 0;
      funct7_dx_r_2 <= 0;
    end
    else begin
      // Normal pipeline progression
      // pc_dx_r <= pc_fd_r;
      opcode_dx_r_2 <= opcode_w_2;
      funct3_dx_r_2 <= funct3_w_2;
      imm_dx_r_2 <= imm_w_2;
      addr_rs1_dx_r_2 <= addr_rs1_w_2;
      addr_rs2_dx_r_2 <= addr_rs2_w_2;
      addr_rd_dx_r_2 <= addr_rd_w_2;
      funct7_dx_r_2 <= funct7_w_2;
    end
  end

  // Execute-Memory stage
// way 1
  always @(posedge clock) begin
    if (reset) begin
      pc_xm_r <= 0;
      imm_xm_r <= 0;
      funct3_xm_r <= 0;
      data_rs2_xm_r <= 0;
      alu_xm_r <= 0;
      opcode_xm_r <= 0;
      addr_rs2_xm_r <= 0;
      addr_rd_xm_r <= 0;
    end
    else if (!xm_en) begin
      pc_xm_r <= pc_xm_r;
      imm_xm_r <= imm_xm_r;
      funct3_xm_r <= funct3_xm_r;
      data_rs2_xm_r <= data_rs2_xm_r;
      alu_xm_r <= 0;
      opcode_xm_r <= 0;
      addr_rs2_xm_r <= 0;
      addr_rd_xm_r <= 0;
    end
    else begin
      pc_xm_r <= pc_dx_r;             // Pipeline PC, rs2 data from last stage
      imm_xm_r <= imm_dx_r; 
      funct3_xm_r <= funct3_dx_r;
      data_rs2_xm_r <= data_rs2_w; 
      alu_xm_r <= alu_out_w;          // Pipeline ALU output
      opcode_xm_r <= opcode_dx_r;     // Pipeline decoded instruction from last stage
      addr_rs2_xm_r <= addr_rs2_dx_r;
      addr_rd_xm_r <= addr_rd_dx_r;
    end
  end

// way 2
    always @(posedge clock) begin
    if (reset) begin
      // pc_xm_r <= 0;
      imm_xm_r_2 <= 0;
      funct3_xm_r_2 <= 0;
      data_rs2_xm_r_2 <= 0;
      alu_xm_r_2 <= 0;
      opcode_xm_r_2 <= 0;
      addr_rs2_xm_r_2 <= 0;
      addr_rd_xm_r_2 <= 0;
    end
    else if (!xm_en_2) begin
      // pc_xm_r <= pc_xm_r;
      imm_xm_r_2 <= imm_xm_r_2;
      funct3_xm_r_2 <= funct3_xm_r_2;
      data_rs2_xm_r_2 <= data_rs2_xm_r_2;
      alu_xm_r_2 <= 0;
      opcode_xm_r_2 <= 0;
      addr_rs2_xm_r_2 <= 0;
      addr_rd_xm_r_2 <= 0;
    end
    else begin
      pc_xm_r_2 <= pc_dx_r_2_2;             // Pipeline PC, rs2 data from last stage
      imm_xm_r_2 <= imm_dx_r_2; 
      funct3_xm_r_2 <= funct3_dx_r_2;
      data_rs2_xm_r_2 <= data_rs2_w_2; 
      alu_xm_r_2 <= alu_out_w_2;          // Pipeline ALU output
      opcode_xm_r_2 <= opcode_dx_r_2;     // Pipeline decoded instruction from last stage
      addr_rs2_xm_r_2 <= addr_rs2_dx_r_2;
      addr_rd_xm_r_2 <= addr_rd_dx_r_2;
    end
  end

  // PC + 4 in MEM stage
  wire [DATAW-1:0] pc4_xm_w = pc_xm_r + 4;
  reg [DATAW-1:0] pc4_mw_r;
  reg [DATAW-1:0] alu_mw_r;
  reg [2:0] funct3_mw_r;

  // Memory-Writeback stage
// way 1
    always @(posedge clock) begin
    if (reset) begin
      pc_mw_r <= 0;
      opcode_mw_r <= 0;
      addr_rd_mw_r <= 0;
      pc_mw_r <= 0;
      alu_mw_r <= 0;
      funct3_mw_r <= 0;
    end 
    else if (!mw_en) begin
      pc_mw_r <= pc_mw_r;
      opcode_mw_r <= opcode_mw_r;
      addr_rd_mw_r <= addr_rd_mw_r;
      pc_mw_r <= pc_mw_r;
      alu_mw_r <= alu_mw_r;
      funct3_mw_r <= funct3_mw_r;
    end
    else begin
      pc_mw_r <= pc_xm_r;
      opcode_mw_r <= opcode_xm_r;
      addr_rd_mw_r <= addr_rd_xm_r;
      pc4_mw_r <= pc4_xm_w;
      alu_mw_r <= alu_xm_r;
      funct3_mw_r <= funct3_xm_r;
    end
  end

// way 2
  always @(posedge clock) begin
    if (reset) begin
      // pc_mw_r <= 0;
      opcode_mw_r_2 <= 0;
      addr_rd_mw_r_2 <= 0;
      pc_mw_r_2 <= 0;
      alu_mw_r_2 <= 0;
      funct3_mw_r_2 <= 0;
    end 
    else if (!mw_en_2) begin
      // pc_mw_r <= pc_mw_r;
      opcode_mw_r_2 <= opcode_mw_r;
      addr_rd_mw_r_2 <= addr_rd_mw_r;
      pc_mw_r_2 <= pc_mw_r;
      alu_mw_r_2 <= alu_mw_r;
      funct3_mw_r_2 <= funct3_mw_r;
    end
    else begin
      // pc_mw_r <= pc_xm_r;
      opcode_mw_r_2 <= opcode_xm_r;
      addr_rd_mw_r_2 <= addr_rd_xm_r;
      pc4_mw_r_2 <= pc4_xm_w;
      alu_mw_r_2 <= alu_xm_r;
      funct3_mw_r_2 <= funct3_xm_r;
    end
  end


  // ===================
  // INSTANTIATE MODULES
  // ===================
  imemory imem1(
    .clock(clock),           // input
    .address(pc_r),          // input
    .data_in(imem_in_r),     // input
    .read_write(imem_rw_w),  // input (hardcoded to 0)
    .enable(imem_enable),    // input 
    .data_out(instr_w)       // output
  );

  // way 1
  decoder dec1( 
    .instr(instr_fd_w [63:32]),         // input
    .opcode(opcode_w),          // output
    .addr_rd(addr_rd_w),        // output
    .addr_rs1(addr_rs1_w),      // output
    .addr_rs2(addr_rs2_w),      // output
    .funct3(funct3_w),          // output
    .funct7(funct7_w),          // output
    .imm(imm_w),                // output
    .shamt(shamt_w),            // output
    .is_u_type_w(is_u_type),    // output
    .is_j_type_w(is_j_type),    // output
    .is_i_type_w(is_i_type)     // output
  );

  // way 2
  decoder dec2(
    .instr(instr_fd_w [31:0]),         // input
    .opcode(opcode_w_2),          // output
    .addr_rd(addr_rd_w_2),        // output
    .addr_rs1(addr_rs1_w_2),      // output
    .addr_rs2(addr_rs2_w_2),      // output
    .funct3(funct3_w_2),          // output
    .funct7(funct7_w_2),          // output
    .imm(imm_w_2),                // output
    .shamt(shamt_w_2),            // output
    .is_u_type_w(is_u_type_2),    // output
    .is_j_type_w(is_j_type_2),    // output
    .is_i_type_w(is_i_type_2)     // output
  );


  register_file rf1(
    .clock(clock),          // input
    .write_enable(reg_wen), // input
    .addr_rs1(addr_rs1_w),  // input
    .addr_rs2(addr_rs2_w),  // input
    .addr_rd(addr_rd_mw_r), // input
    .data_rd(data_rd_w),    // input
    .data_rs1(data_rs1_w),  // output
    .data_rs2(data_rs2_w)   // output

    //2-way
    .write_enable_2(reg_wen_2), // input
    .addr_rs1_2(addr_rs1_w_2),  // input
    .addr_rs2_2(addr_rs2_w_2),  // input
    .addr_rd_2(addr_rd_mw_r_2), // input
    .data_rd_2(data_rd_w_2),    // input
    .data_rs1_2(data_rs1_w_2),  // output
    .data_rs2_2(data_rs2_w_2)   // output
  );
  // wire [DATAW-1:0] data_rs1_stall_w = !(stall_fd || reset) ? data_rs1_w : 0;
  // wire [DATAW-1:0] data_rs2_stall_w = !(stall_fd || reset) ? data_rs2_w : 0;
  wire [DATAW-1:0] data_rs1_stall_w = data_rs1_w;
  wire [DATAW-1:0] data_rs2_stall_w =  data_rs2_w;

  control_signals cs1(
    .clock(clock),
    .reset(reset),
    .dx_en(dx_en),
    .xm_en(xm_en),
    .mw_en(mw_en),
    .opcode_dx(opcode_dx_r),      // input
    .opcode_xm(opcode_xm_r),      // input
    .opcode_mw(opcode_mw_r),      // input
    .funct3(funct3_dx_r),         // input
    .funct7(funct7_dx_r),         // input
    .br_eq(br_eq),                // input
    .br_lt(br_lt),                // input
    .addr_rs1_dx(addr_rs1_dx_r),  // input
    .addr_rs2_dx(addr_rs2_dx_r),  // input
    .addr_rd_xm(addr_rd_xm_r),    // input
    .addr_rd_mw(addr_rd_mw_r),    // input
    .br_taken(br_taken),          // output
    .branch_comp_data1_sel(branch_comp_data1_sel), // output
    .branch_comp_data2_sel(branch_comp_data2_sel), // output
    .pc_sel(pc_sel),              // output
    .br_un(br_un),                // output
    .a_sel(a_sel),                // output
    .b_sel(b_sel),                // output
    .alu_sel(alu_sel),            // output
    .mem_rw(data_mem_rw),         // output
    .reg_wen(reg_wen),            // output
    .wb_sel(wb_sel)               // output
  );

  //2-way
  control_signals cs2(
    .clock(clock),
    .reset(reset),
    .dx_en(dx_en_2),
    .xm_en(xm_en_2),
    .mw_en(mw_en_2),
    .opcode_dx(opcode_dx_r_2),      // input
    .opcode_xm(opcode_xm_r_2),      // input
    .opcode_mw(opcode_mw_r_2),      // input
    .funct3(funct3_dx_r_2),         // input
    .funct7(funct7_dx_r_2),         // input
    .br_eq(br_eq_2),                // input
    .br_lt(br_lt_2),                // input
    .addr_rs1_dx(addr_rs1_dx_r_2),  // input
    .addr_rs2_dx(addr_rs2_dx_r_2),  // input
    .addr_rd_xm(addr_rd_xm_r_2),    // input
    .addr_rd_mw(addr_rd_mw_r_2),    // input
    .br_taken(br_taken_2),          // output
    .branch_comp_data1_sel(branch_comp_data1_sel_2), // output
    .branch_comp_data2_sel(branch_comp_data2_sel_2), // output
    .pc_sel(pc_sel_2),              // output
    .br_un(br_un_2),                // output
    .a_sel(a_sel_2),                // output
    .b_sel(b_sel_2),                // output
    .alu_sel(alu_sel_2),            // output
    .mem_rw(data_mem_rw_2),         // output
    .reg_wen(reg_wen_2),            // output
    .wb_sel(wb_sel_2)               // output

  );

  // Forwarding logic values
  localparam REG = 2'b00;
  localparam PC  = 2'b01;
  localparam WX_BYPASS = 2'b10;
  localparam MX_BYPASS = 2'b11;

  // branch forwarding logic (cases for WX and MX bypassing)

  wire [DATAW-1:0] idata1_in =  (branch_comp_data1_sel == WX_BYPASS) ? data_rd_w :
                                (branch_comp_data1_sel == MX_BYPASS) ? alu_xm_r :
                                                                     data_rs1_w;

  wire [DATAW-1:0] idata2_in =  (branch_comp_data2_sel == WX_BYPASS) ? data_rd_w :
                                (branch_comp_data2_sel == MX_BYPASS) ? alu_xm_r :
                                                                     data_rs2_w;

  branch_comp bc1(
    .idata1(idata1_in),
    .idata2(idata2_in),
    .br_un(br_un),
    .br_eq(br_eq),
    .br_lt(br_lt)
  );

  //2-way
  branch_comp bc2(
    .idata1(idata1_in_2),
    .idata2(idata2_in_2),
    .br_un(br_un_2),
    .br_eq(br_eq_2),
    .br_lt(br_lt_2)
  );
  
  // A sel definitions (determines ALU input 1)
  assign alu_in1_w = (a_sel == REG) ? data_rs1_w :
                     (a_sel == PC) ? pc_dx_r :
                     (a_sel == WX_BYPASS) ? data_rd_w :
                                            alu_xm_r;

  // B sel definitions (determines ALU input 2)
  localparam IMM  = 2'b01;
  assign alu_in2_w = (b_sel == REG) ? data_rs2_w :
                     (b_sel == IMM) ? imm_dx_r :
                     (b_sel == WX_BYPASS) ? data_rd_w :
                                            alu_xm_r;

  alu al1(
    .idata1(alu_in1_w),
    .idata2(alu_in2_w),
    .alu_sel(alu_sel),
    .odata(alu_out_w)
  );

  //way 2
  alu al2(
    .idata1(alu_in1_w_2),
    .idata2(alu_in2_w_2),
    .alu_sel(alu_sel_2),
    .odata(alu_out_w_2)
  );

  wire [1:0] mem_write_access_size = funct3_xm_r[1:0];     // For testbench

  // WM bypass logic
  wire is_store_xm = (opcode_xm_r == STORE_OPCODE);  // Store instruction in XM stage

  wire wm_forward = is_store_xm && 
                    (addr_rs2_xm_r == addr_rd_mw_r) && 
                    (addr_rd_mw_r != 0) && 
                    instr_mw_writes_reg;

  // Data memory instantiation based on forwarding logic
  wire [DATAW-1:0] dmem_data_in = (wm_forward) ? data_rd_w : data_rs2_xm_r;

  dmemory dmem1(
    .clock(clock),               // input
    .read_write(data_mem_rw),    // input
    .access_size(mem_write_access_size),   // input
    .address(alu_xm_r),          // input
    .data_in(dmem_data_in),      // input
    .data_out(data_mem_w)        // output

    //way 2
    .read_write_2(data_mem_rw_2),    // input
    .access_size_2(mem_write_access_size_2),   // input
    .address_2(alu_xm_r_2),          // input
    .data_in_2(dmem_data_in_2),      // input
    .data_out_2(data_mem_w_2)        // output
  );

  // Mem read access size logic
  wire [1:0] mem_read_access_size = funct3_mw_r[1:0];  // For testbench

  localparam BYTE_OP = 2'b00;
  localparam HALF_OP = 2'b01;
  localparam WORD_OP = 2'b10;
  wire is_unsigned = funct3_mw_r[2];

  wire [DATAW-1:0] data_mem_w_sized = 
    (mem_read_access_size == BYTE_OP) ? 
      (is_unsigned) ? {24'b0, data_mem_w[7:0]} :                             // LBU
      {{24{data_mem_w[7]}}, data_mem_w[7:0]} :                               // LB
    (mem_read_access_size == HALF_OP) ? 
      (is_unsigned) ? {16'b0, data_mem_w[15:0]} :                            // LHU
      {{16{data_mem_w[15]}}, data_mem_w[15:0]} :                             // LH
    (mem_read_access_size == WORD_OP) ? data_mem_w : data_mem_w;             // LW

  // According to lecture slides, this should be in the memory stage
  writeback wb1(
    .alu(alu_mw_r),                 // input
    .mem(data_mem_w_sized),         // input
    .pc4(pc4_mw_r),                 // input
    .wb_sel(wb_sel),                // input
    .wb_data(data_rd_w)             // output

    //2-way
    .alu_2(alu_mw_r_2),                 // input
    .mem_2(data_mem_w_sized_2),         // input
    .pc4_2(pc4_mw_r_2),                 // input
    .wb_sel_2(wb_sel_2),                // input
    .wb_data_2(data_rd_w_2)             // output
  );

endmodule