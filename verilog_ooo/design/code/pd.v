// =============================================================================
// Module:      pd
// Description: <NEED TO ADD THIS>
// Inputs:      clock - processor clock
//              reset - synchronous reset; returns PC to BASE_ADDR
// Outputs:     (none - all state is internal; testbench probes internal signals)
// =============================================================================
module pd #(
  parameter NUM_REGS = 32,
  parameter DATAW = 32,
  parameter BASE_ADDR = 32'h01000000,
  parameter ADDRW = $clog2(DATAW),
  parameter N_BITS = $clog2(DATAW),
  
  parameter NUM_BUFFER_ROWS = 6,

  // functional units
  parameter NUM_ALU = 2,
  parameter NUM_MULTICYCLE_MULT = 1,
  parameter NUM_LOAD_STORE = 1,
  parameter FUW = $clog2(NUM_ALU + NUM_MULTICYCLE_MULT + 2*NUM_LOAD_STORE + 1 + 1) // + 1 for branch_comparator + 1 for N/A

)(
  input clock,
  input reset
);

/* WIRES/REGISTERS */
// FU ids (must match func_unit_status.v)
localparam NONE   = 0;
localparam BRANCH = 1;

// Fetch
reg [32:0]  f_pc = BASE_ADDR;
reg [32:0]  f_imem_in;
reg         f_imem_rw = 0;
wire        f_imem_enable;
reg [32:0]  f_instr_out;

// Decode/Dispatch
reg [32:0]        d_pc;
reg [32:0]        d_instr;
reg [6:0]         d_opcode;
reg [ADDRW-1:0]   d_addr_rd;
reg [ADDRW-1:0]   d_addr_rs1;
reg [ADDRW-1:0]   d_addr_rs2;
reg [2:0]         d_funct3;
reg [6:0]         d_funct7;
reg [DATAW-1:0]   d_imm;
reg [N_BITS-1:0]  d_shamt;
reg               d_is_u_type_w;
reg               d_is_j_type_w;
reg               d_is_i_type_w;
wire              d_uses_rs1;
wire              d_uses_rs2;
wire              d_writes_rd;
reg [FUW-1:0]     d_fu_id;
reg [FUW-1:0]     ds_assigned_fu_id;
reg [FUW-1:0]     ds_curr_WAW;
wire              ds_stall;
reg               ds_instr_buffer_full;

// Writeback broadcast (TODO: drive these from the WB stage)
wire              wb_en        = 1'b0;
wire [FUW-1:0]    wb_tag       = 0;
wire [DATAW-1:0]  wb_data      = 0;
wire [ADDRW-1:0]  wb_rd        = 0;
wire              wb_writes_rd = 1'b0;


/* FETCH STAGE: Imemory */
always @(posedge clock) begin 
  f_imem_in <= 0;
  f_imem_rw <= 0;

  if(reset) begin 
    f_pc <= BASE_ADDR;  

  end else begin 
    f_pc <= f_pc + 4;
  end 

end 

// hold the fetched instruction while dispatch is stalled
assign f_imem_enable = !ds_stall;

imemory imem (
  .clock(clock),
  .address(f_pc),
  .data_in(f_imem_in),
  .read_write(f_imem_rw),
  .enable(f_imem_enable),
  .data_out(f_instr_out)
);


/* DISPATCH STAGE: Decoder, Dispatcher, and the 3 tables?, look for WAW hazards */

always @(posedge clock) begin 
   if(reset) begin 
     d_pc <= 0;  
     d_valid <= 0;
  end else if (!ds_stall)begin 
    d_pc <= f_pc;
    d_valid <= 1;           // TODO: clear on taken-branch redirect
    d_instr <= f_instr_out;
  end 

end 


decoder #(
  .FUW(FUW)
)dec(
  .instr(d_instr),
  .opcode(d_opcode),
  .addr_rd(d_addr_rd),
  .addr_rs1(d_addr_rs1),
  .addr_rs2(d_addr_rs2),
  .funct3(d_funct3),
  .funct7(d_funct7),
  .imm(d_imm),
  .shamt(d_shamt),
  .is_u_type_w(d_is_u_type_w),
  .is_j_type_w(d_is_j_type_w),
  .is_i_type_w(d_is_i_type_w),
  .uses_rs1(d_uses_rs1),
  .uses_rs2(d_uses_rs2),
  .writes_rd(d_writes_rd),
  .fu_id(d_fu_id)
);

// Branch drain: block dispatch while a branch/jump is in flight
reg br_busy;
always @(posedge clock) begin
  if (reset) br_busy <= 0;
  else if (ds_en && ds_assigned_fu_id == BRANCH) br_busy <= 1;
  else if (wb_en && wb_tag == BRANCH) br_busy <= 0;
end

// FIRST; check fu table for space --> if full, stall
// SECOND: Check the the reg_status_table for rd of decoded instruction --> if found, stall
wire ds_WAW_status = d_writes_rd && (ds_curr_WAW != 0);
wire ds_en = d_valid && !ds_instr_buffer_full && (ds_assigned_fu_id != 0) && !ds_WAW_status && !br_busy;

// FU_NONE (e.g. fence) needs no FU row: treat as a nop and just move on
wire ds_is_nop = (d_fu_id == FU_NONE) && !br_busy;
assign ds_stall = d_valid && !ds_en && !ds_is_nop;

wire [FUW-1:0] ds_rs1_tag_initial;
wire [FUW-1:0] ds_rs2_tag_initial;

wire [FUW-1:0] ds_rs1_tag = (!d_uses_rs1 || (wb_en && ds_rs1_tag_raw == wb_tag)) ? 0 : ds_rs1_tag_raw;
wire [FUW-1:0] ds_rs2_tag = (!d_uses_rs2 || (wb_en && ds_rs2_tag_raw == wb_tag)) ? 0 : ds_rs2_tag_raw;

instr_status # (
  .DATAW(DATAW),
  .ADDRW(ADDRW),
  .NUM_BUFFER_ROWS(NUM_BUFFER_ROWS),
  .NUM_FU(NUM_FU)
) instrStatus (
  .clock(clock),
  .reset(reset),
    
  // input status in DS (can remove some of these values if they are unused)
  .ds_en(ds_en),
  .ds_pc(d_pc),
  .ds_opcode(d_opcode),
  .ds_func3(d_funct3),
  .ds_func3(d_funct7),
  .ds_imm(d_imm),
  .ds_shamt(d_shamt),
  .ds_rs1(d_addr_rs1),
  .ds_rs2(d_addr_rs2),
  .ds_rd(d_addr_rd),
  .ds_fu_id(ds_assigned_fu_id),

  // clear row in WB
  .wb_en(),
  .wb_pc(),

  .buffer_full(ds_instr_buffer_full);
);

functional_unit_status # (
    .DATAW(DATAW),
    .NUM_REGS(NUM_REGS),
    .NUM_ALU(NUM_ALU),
    .NUM_MULTICYCLE_MULT(NUM_MULTICYCLE_MULT),
    .NUM_LOAD_STORE(NUM_LOAD_STORE),
    .FUW(FUW)
    
) funcStatus (
    .clock(clock),
    .reset(reset),
    // Check for WAW in dispatch
    .ds_fu_type(d_fu_id),
    .ds_assigned_fu_id(ds_assigned_fu_id), // output

    // Populate row in dispatch
    .ds_en(ds_en),
    .ds_fu_id(ds_assigned_fu_id), // actual functional unit id
    .ds_pc(d_pc),
    .ds_rs1(d_addr_rs1),
    .ds_rs2(d_addr_rs2), 
    .ds_rd(d_addr_rd), 
    .ds_rs1_tag(ds_rs1_tag_initial),
    .ds_rs2_tag(ds_rs2_tag_initial),

    .iss_en(),               // iss = issue
    .iss_fu_id(), // actual functional unit id
    .iss_rs1_data(),
    .iss_rs2_data(),

    .wb_en(wb_en),
    .wb_tag_clear(wb_tag),
    .wb_data(wb_data),

    .busy(),    // connect to the FUs to get their real-time statuses
    .iss_tag_found() 

);


reg_status_table  #(
    .DATAW(DATAW),
    .NUM_REGS(NUM_REGS),
    .NUM_ALU(NUM_ALU),
    .NUM_MULTICYCLE_MULT(NUM_MULTICYCLE_MULT),
    .NUM_LOAD_STORE(NUM_LOAD_STORE),
    .FUW(FUW)
)regStatus(
    .clock(clock),
    .reset(reset),

    .ds_check_rd(d_addr_rd),
    .ds_check_rs1(d_addr_rs1),
    .ds_check_rs2(d_addr_rs2),

    .ds_write_enable(ds_en && d_writes_rd),
    .ds_reg_id_in(d_addr_rd),
    .ds_fu_id_in(ds_assigned_fu_id),
    
    .wb_clear_enable(wb_en && wb_writes_rd),
    .wb_clear_id(wb_rd),
    
    .ds_fu_id_out(ds_curr_WAW),
    .ds_fu_id_out_rs1(ds_rs1_tag_initial),
    .ds_fu_id_out_rs2(ds_rs2_tag_initial)
);



/* ISSUE STAGE: just look for RAW hazards? and copy values from reg file */








/* 
EXECUTE STAGE: all the FUs
- 2 ALUs
- 1 Multi-Cycle multiplier
- 1 Load
- 1 Store
- 1 Branch Comparator
- 1 DMemory
*/

dmemory dmem (
  .clock(clock), 
  .reset(reset),
  .r_pc(),
  .r_access_size(),
  .r_address(),
  .r_offset(),

  .w_en(),
  .w_pc(),
  .w_access_size(),
  .w_address(),
  .w_offset(),
  .w_data_in(),

  .r_data_out()
);

/* WRITEBACK STAGE: writeback unit*/








endmodule