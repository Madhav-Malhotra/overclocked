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

  // Fetch unit
  reg [DATAW-1:0] pc_r;
  reg [DATAW-1:0] instr_w;        // output line into pipeline register
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
  reg [DATAW-1:0] data_rs1_w;     // wire - register file output
  reg [DATAW-1:0] data_rs2_w;     // wire - register file output

  // ALU inputs
  wire [DATAW-1:0] alu_in1_w;
  wire [DATAW-1:0] alu_in2_w;
  reg [DATAW-1:0] alu_out_w;

  // Data memory unit
  reg [DATAW-1:0] data_mem_w;
  wire data_mem_rw;

  // Writeback unit
  reg [DATAW-1:0] data_rd_w;

  // PC + 4
  wire [DATAW-1:0] pc4_f_w = pc_r + 4;

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

  // ===================
  // CONTROL/FSMs
  // ===================

  // Fetch unit reset and increment
  always @(posedge clock) begin
    if (reset) begin
      pc_r <= BASE_ADDR;
      imem_in_r <= 0;
    end
    else if (stall) begin
      pc_r <= pc_r;  // Hold PC value during stall
    end
    else begin
      pc_r <= (pc_sel == 1) ? alu_out_w : pc4_f_w;
    end
  end

  // ===================
  // PIPELINE REGISTERS
  // ===================

  // Fetch-Decode stage
  reg [DATAW-1:0] pc_fd_r;
  reg [DATAW-1:0] instr_fd_r;
  always @(posedge clock) begin
    if (reset) begin
      pc_fd_r <= 0;
      instr_fd_r <= 0;
    end
    else if (stall) begin
      pc_fd_r <= pc_fd_r;          // Hold FD pipeline registers during stall
      instr_fd_r <= instr_fd_r;
    end
    else if (br_taken) begin
      instr_fd_r <= NOP_INSTR;    // Insert NOP into pipeline for second instruction after branch
      pc_fd_r <= pc_r;
    end
    else begin
      pc_fd_r <= pc_r;
      instr_fd_r <= instr_w;
    end
  end

  // Decode-Execute stage
  reg [DATAW-1:0] pc_dx_r;
  reg [6:0] opcode_dx_r;            // Store decoded instr, not OG instr
  reg [2:0] funct3_dx_r;
  reg [DATAW-1:0] imm_dx_r;
  reg [ADDRW-1:0] addr_rs1_dx_r;
  reg [ADDRW-1:0] addr_rs2_dx_r;
  reg [ADDRW-1:0] addr_rd_dx_r;
  
  always @(posedge clock) begin
    if (reset) begin
      pc_dx_r <= 0;
      opcode_dx_r <= 0;
      funct3_dx_r <= 0;
      imm_dx_r <= 0;
      addr_rs1_dx_r <= 0;
      addr_rs2_dx_r <= 0;
      addr_rd_dx_r <= 0;
    end
    else if (stall || br_taken) begin
      pc_dx_r <= pc_fd_r;               // Connect to prior FD pipeline reg
      opcode_dx_r <= NOP_OPCODE;    // Insert NOP into pipeline for first instruction after branch
      funct3_dx_r <= 0;
      imm_dx_r <= 0;
      addr_rs1_dx_r <= 0;
      addr_rs2_dx_r <= 0;
      addr_rd_dx_r <= 0;
    end
    else begin
      pc_dx_r <= pc_fd_r;               // Connect to prior FD pipeline reg
      opcode_dx_r <= opcode_w;          // Connect to decoder outputs
      funct3_dx_r <= funct3_w;
      imm_dx_r <= imm_w;
      addr_rs1_dx_r <= addr_rs1_w;
      addr_rs2_dx_r <= addr_rs2_w;
      addr_rd_dx_r <= addr_rd_w;
    end
  end

  // Execute-Memory stage
  reg [DATAW-1:0] pc_xm_r;   
  reg [DATAW-1:0] imm_xm_r;
  reg [2:0] funct3_xm_r;
  reg [DATAW-1:0] alu_xm_r;
  reg [DATAW-1:0] data_rs2_xm_r;        // P.S. Class slides don't need rs1_xm
  reg [6:0] opcode_xm_r;                // Need for stalling logic
  reg [ADDRW-1:0] addr_rs2_xm_r;        // Need for forwarding logic
  reg [ADDRW-1:0] addr_rd_xm_r;         // Need to determine WB location
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

  // PC + 4 in MEM stage
  wire [DATAW-1:0] pc4_xm_w;
  assign pc4_xm_w = pc_xm_r + 4;

  // Memory-Writeback stage
  reg [DATAW-1:0] pc_mw_r;            // Need for signals.h test
  reg [DATAW-1:0] data_rd_mw_r;       // Need to determine WB content
  reg [6:0] opcode_mw_r;              // Need for stalling logic
  reg [ADDRW-1:0] addr_rd_mw_r;       // Need to determine WB location
  always @(posedge clock) begin
    if (reset) begin
      pc_mw_r <= 0;
      data_rd_mw_r <= 0;
      opcode_mw_r <= 0;
      addr_rd_mw_r <= 0;
    end
    else begin
      pc_mw_r <= pc_xm_r;
      data_rd_mw_r <= data_rd_w;
      opcode_mw_r <= opcode_xm_r;
      addr_rd_mw_r <= addr_rd_xm_r;
    end
  end


  // ===================
  // INSTANTIATE MODULES
  // ===================

  imemory imem1(
    .clock(clock),          // input
    .address(pc_r),         // input
    .data_in(imem_in_r),    // input
    .read_write(imem_rw_w), // input (hardcoded to 0)
    .data_out(instr_w)      // output
  );

  decoder dec1(
    .instr(instr_fd_r),         // input
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

  wire rf_en = !(stall || br_taken || reset);
  register_file rf1(
    .clock(clock),          // input
    .write_enable(reg_wen), // input
    .reg_enable(rf_en),     // input
    .addr_rs1(addr_rs1_w),  // input
    .addr_rs2(addr_rs2_w),  // input
    .addr_rd(addr_rd_mw_r), // input
    .data_rd(data_rd_mw_r), // input
    .data_rs1(data_rs1_w),  // output
    .data_rs2(data_rs2_w)   // output
  );

  control_signals cs1(
    .clock(clock),
    .reset(reset),
    .opcode_dx(opcode_dx_r),      // input
    .opcode_xm(opcode_xm_r),      // input
    .opcode_mw(opcode_mw_r),      // input
    .funct3(funct3_w),            // input
    .funct7(funct7_w),            // input
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

  // Forwarding logic values
  localparam REG = 2'b00;
  localparam PC  = 2'b01;
  localparam WX_BYPASS = 2'b10;
  localparam MX_BYPASS = 2'b11;

  // branch forwarding logic (cases for WX and MX bypassing)

  wire [DATAW-1:0] idata1_in =  (branch_comp_data1_sel == WX_BYPASS) ? data_rd_mw_r :
                                (branch_comp_data1_sel == MX_BYPASS) ? alu_xm_r :
                                                                     data_rs1_w;

  wire [DATAW-1:0] idata2_in =  (branch_comp_data2_sel == WX_BYPASS) ? data_rd_mw_r :
                                (branch_comp_data2_sel == MX_BYPASS) ? alu_xm_r :
                                                                     data_rs2_w;

  branch_comp bc1(
    .idata1(idata1_in),
    .idata2(idata2_in),
    .br_un(br_un),
    .br_eq(br_eq),
    .br_lt(br_lt)
  );

  // A sel definitions (determines ALU input 1)
  assign alu_in1_w = (a_sel == REG) ? data_rs1_w :
                     (a_sel == PC) ? pc_dx_r :
                     (a_sel == WX_BYPASS) ? data_rd_mw_r :
                                            alu_xm_r;

  // B sel definitions (determines ALU input 2)
  localparam IMM  = 2'b01;
  assign alu_in2_w = (b_sel == REG) ? data_rs2_w :
                     (b_sel == IMM) ? imm_dx_r :
                     (b_sel == WX_BYPASS) ? data_rd_mw_r :
                                            alu_xm_r;

  alu al1(
    .idata1(alu_in1_w),
    .idata2(alu_in2_w),
    .alu_sel(alu_sel),
    .odata(alu_out_w)
  );

  wire [1:0] access_size = funct3_xm_r[1:0];     // For testbench

  // WM bypass logic
  wire is_store_xm = (opcode_xm_r == STORE_OPCODE);  // Store instruction in XM stage

  wire wm_forward = is_store_xm && 
                    (addr_rs2_xm_r == addr_rd_mw_r) && 
                    (addr_rd_mw_r != 0) && 
                    instr_mw_writes_reg;

  // Data memory instantiation based on forwarding logic
  wire [DATAW-1:0] dmem_data_in = (wm_forward) ? data_rd_mw_r : data_rs2_xm_r;

  dmemory dmem1(
    .clock(clock),               // input
    .address(alu_xm_r),          // input
    .data_in(dmem_data_in),      // input
    .mem_rw(data_mem_rw),        // input
    .access_size(access_size),   // input
    .is_unsigned(funct3_xm_r[2]),// input
    .data_out(data_mem_w)        // output
  );

  // According to lecture slides, this should be in the memory stage
  writeback wb1(
    .alu(alu_xm_r),      // input
    .mem(data_mem_w),    // input
    .pc4(pc4_xm_w),      // input
    .wb_sel(wb_sel),     // input
    .wb_data(data_rd_w)  // output
  );

endmodule
