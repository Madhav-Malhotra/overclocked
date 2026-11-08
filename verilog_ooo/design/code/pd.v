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
localparam NUM_FU = NUM_ALU + NUM_MULTICYCLE_MULT + 2*NUM_LOAD_STORE + 1; // + 1 for branch_comparator

// FU ids (must match func_unit_status.v)
localparam NONE   = 0;
localparam BRANCH = 1;

// Fetch
reg [DATAW-1:0]   f_pc = BASE_ADDR;
reg [DATAW-1:0]   f_imem_in;
reg               f_imem_rw = 0;
wire              f_imem_enable;
wire [DATAW-1:0]  f_instr_out;
reg [DATAW-1:0]   f_instr_pc;
reg               f_valid;

// Decode/Dispatch
reg [DATAW-1:0]   d_pc;
reg [DATAW-1:0]   d_instr;
reg               d_valid;
wire [6:0]        d_opcode;
wire [ADDRW-1:0]  d_addr_rd;
wire [ADDRW-1:0]  d_addr_rs1;
wire [ADDRW-1:0]  d_addr_rs2;
wire [2:0]        d_funct3;
wire [6:0]        d_funct7;
wire [DATAW-1:0]  d_imm;
wire [N_BITS-1:0] d_shamt;
wire              d_is_u_type_w;
wire              d_is_j_type_w;
wire              d_is_i_type_w;
wire              d_uses_rs1;
wire              d_uses_rs2;
wire              d_writes_rd;
wire [FUW-1:0]    d_fu_id;
wire [FUW-1:0]    ds_assigned_fu_id;
wire [FUW-1:0]    ds_curr_WAW;
wire              ds_en;
wire              ds_stall;
wire              ds_instr_buffer_full;

// Issue
reg               iss_en = 1;  // funcStatus found a row (iss_instr_found): iss_* below are valid      
wire [FUW-1:0]    iss_fu_id;
wire [DATAW-1:0]  iss_pc;
wire [ADDRW-1:0]  iss_rs1;
wire [ADDRW-1:0]  iss_rs2;
// wire              iss_rs1_fwd;
// wire              iss_rs2_fwd;
// wire [DATAW-1:0]  iss_rs1_fwd_data;
// wire [DATAW-1:0]  iss_rs2_fwd_data;
// wire              iss_tag_found;
wire              fu_issued;        // per-row "has read operands" (for the WAR check in WB)
// wire [6:0]        iss_opcode;
// wire [2:0]        iss_funct3;
// wire [6:0]        iss_funct7;
// wire [DATAW-1:0]  iss_imm;
// wire [4:0]        iss_shamt;
// wire [ADDRW-1:0]  iss_rd;

// Writeback broadcast (TODO: drive these from the WB stage)
wire              wb_en        = 1'b0;
wire [FUW-1:0]    wb_tag       = 0;
wire [DATAW-1:0]  wb_data      = 0;
wire [ADDRW-1:0]  wb_rd        = 0;
wire              wb_writes_rd = 1'b0;
wire [DATAW-1:0]  wb_pc        = 0;


/* FETCH STAGE: Imemory */
always @(posedge clock) begin 
  f_imem_in <= 0;
  f_imem_rw <= 0;

  if(reset) begin 
    f_pc <= BASE_ADDR;  
    f_valid <= 0;
  end else if (!ds_stall) begin  // hold pc while dispatch is stalled
    f_instr_pc <=f_pc;
    f_valid <= 1;
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
    d_pc <= f_instr_pc;
    d_valid <= f_valid;           // TODO: clear on taken-branch redirect
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
assign ds_en = d_valid && !ds_instr_buffer_full && (ds_assigned_fu_id != 0) && !ds_WAW_status && !br_busy;

// NONE (e.g. fence) needs no FU row: treat as a nop and just move on
wire ds_is_nop = (d_fu_id == NONE) && !br_busy;
assign ds_stall = d_valid && !ds_en && !ds_is_nop;

wire [FUW-1:0] ds_rs1_tag_initial;
wire [FUW-1:0] ds_rs2_tag_initial;

wire [FUW-1:0] ds_rs1_tag = (!d_uses_rs1 || (wb_en && ds_rs1_tag_initial == wb_tag)) ? 0 : ds_rs1_tag_initial;
wire [FUW-1:0] ds_rs2_tag = (!d_uses_rs2 || (wb_en && ds_rs2_tag_initial == wb_tag)) ? 0 : ds_rs2_tag_initial;

instr_status # (
  .DATAW(DATAW),
  .ADDRW(ADDRW),
  .NUM_BUFFER_ROWS(NUM_BUFFER_ROWS),
  .NUM_FU(NUM_FU),
  .FUW(FUW)
) instrStatus (
  .clock(clock),
  .reset(reset),
    
  // input status in DS (can remove some of these values if they are unused)
  .ds_en(ds_en),
  .ds_pc(d_pc),
  .ds_opcode(d_opcode),
  .ds_funct3(d_funct3),
  .ds_funct7(d_funct7),
  .ds_imm(d_imm),
  .ds_shamt(d_shamt),
  .ds_rs1(d_addr_rs1),
  .ds_rs2(d_addr_rs2),
  .ds_rd(d_addr_rd),
  .ds_fu_id(ds_assigned_fu_id),

  // IS: mark the issuing instruction and look up its decoded fields
  .iss_en(iss_valid), // = iss_en and fu_issued
  .iss_pc(iss_pc),

  // .iss_opcode(iss_opcode),
  // .iss_funct3(iss_funct3),
  // .iss_funct7(iss_funct7),
  // .iss_imm(iss_imm),
  // .iss_shamt(iss_shamt),
  // .iss_rd(iss_rd),

  // clear row in WB
  .wb_en(wb_en),
  .wb_pc(wb_pc),

  .buffer_full(ds_instr_buffer_full)
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
    .ds_rs1_tag(ds_rs1_tag),
    .ds_rs2_tag(ds_rs2_tag),

    .iss_en(iss_en),               // iss = issue
    .iss_fu_id(iss_fu_id), // actual functional unit id
    .iss_pc(iss_pc),
    .iss_rs1(iss_rs1),
    .iss_rs2(iss_rs2),
    .iss_rs1_data(iss_rs1_data), // inputs: read reg values from regfile
    .iss_rs2_data(iss_rs2_data),
    .issued(fu_issued),

    .wb_en(wb_en),
    .wb_tag_clear(wb_tag),
    .wb_data(wb_data),

    // .busy(),    // connect to the FUs to get their real-time statuses
    // .iss_tag_found() 

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
// For all instructions in the instruction status table:
  // - if they are in DS stage, move into IS stage, if in IS stage, leave them
  // - check for RAW hazards (check the tags)
  // - if no RAWs found, move into EX stage

always @(posedge clock) begin 
  if(reset) begin 
    iss_en <= 0;
  end else begin
    iss_en <= 1;
  end
end 

wire iss_rs1_data;
wire iss_rs2_data;

wire iss_valid = iss_en && fu_issued;

register_file #(
  .DATAW(DATAW),
  .NUM_REGS(NUM_REGS),
  .BASE_ADDR(BASE_ADDR)
) regfile (
  .clock(clock),
  .write_enable(wb_en && wb_writes_rd),
  .addr_rs1(iss_rs1), // IS
  .addr_rs2(iss_rs2), // IS
  .addr_rd(wb_rd), // WB
  .data_rd(wb_data), // WB
  .data_rs1(iss_rs1_data), // IS
  .data_rs2(iss_rs2_data) // IS
);



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
  .r_en(),
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