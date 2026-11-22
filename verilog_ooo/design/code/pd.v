// =============================================================================
// Module:      pd
// Description: Top level of the out-of-order RV32 core (scoreboarding).
//              Fetch -> in-order Decode/Dispatch -> out-of-order Issue ->
//              Execute -> out-of-order Writeback, one instruction per cycle per
//              stage. Dispatch allocates rows in three tables:
//                instr_status           - decoded instruction buffer
//                functional_unit_status - one row per FU slot (operands, tags)
//                reg_status_table       - architectural reg -> producer FU id
//              Issue selects the smallest-PC ready row (cycle N, RF read
//              addresses driven), then issues it to its FU with its
//              operands and decoded fields (cycle N+1). Instructions are
//              identified by their instr_status row (ist_idx, plan.md D1).
//              Status (plan.md): fetch/dispatch/issue exist; execution units,
//              writeback and branch redirect do not yet. The wb_* bus and FU
//              ready vector are placeholders (constants).
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
localparam INSTR_ROW_W = $clog2(NUM_BUFFER_ROWS);  // width of an instr_status row index

// FU ids (same values in decoder.v and func_unit_status.v)
localparam NONE   = 0;  // no FU: FENCE / unknown no-op; also "no pending producer"
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
wire [INSTR_ROW_W-1:0] ds_ist_idx;       // instr_status row the dispatching instruction is written to

// Issue select (cycle N)
wire                   iss_sel_valid;     // a row is selected for issue this cycle
wire [INSTR_ROW_W-1:0] iss_sel_ist_idx;   // its instr_status row
wire [ADDRW-1:0]       iss_rf_rs1;        // register-file read address: rs1 of the selected row
wire [ADDRW-1:0]       iss_rf_rs2;        // register-file read address: rs2 of the selected row
wire [DATAW-1:0]       iss_rf_rs1_data;   // registered RF read data for rs1 (used in cycle N+1)
wire [DATAW-1:0]       iss_rf_rs2_data;   // registered RF read data for rs2 (used in cycle N+1)

// Issue (cycle N+1): everything the FU needs to execute the instruction
wire                   iss_valid;         // an instruction issues to FU iss_fu_id this cycle
wire [FUW-1:0]         iss_fu_id;         // FU it executes on
wire [INSTR_ROW_W-1:0] iss_ist_idx;       // its instr_status row (instruction identity, D1)
wire [DATAW-1:0]       iss_pc;            // its PC
wire [ADDRW-1:0]       iss_rd;            // its destination register number
wire                   iss_writes_rd;     // it writes rd at writeback
wire [DATAW-1:0]       iss_op1;           // rs1 value (forwarded or read from the RF)
wire [DATAW-1:0]       iss_op2;           // rs2 value (forwarded or read from the RF)
wire [6:0]             iss_opcode;        // decoded fields, from instr_status
wire [2:0]             iss_funct3;
wire [6:0]             iss_funct7;
wire [DATAW-1:0]       iss_imm;
wire [4:0]             iss_shamt;

// Writeback broadcast (TODO: drive these from the WB stage)
wire              wb_en        = 1'b0;
wire [FUW-1:0]    wb_tag       = 0;
wire [DATAW-1:0]  wb_data      = 0;
wire [ADDRW-1:0]  wb_rd        = 0;
wire              wb_writes_rd = 1'b0;
wire [INSTR_ROW_W-1:0] wb_ist_idx = 0;  // instr_status row of the writing-back instruction
wire [DATAW-1:0]  wb_pc        = 0;     // trace + D2 priority only

// FU ready (ready/valid): bit id-1 = FU id can accept an instruction (TODO Phase 3: drive from the FUs)
wire [NUM_FU-1:0] fu_ready     = {NUM_FU{1'b1}};


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
  .N_BITS(INSTR_ROW_W),
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

  .buffer_full(ds_instr_buffer_full),
  .ds_ist_idx(ds_ist_idx),

  // IS: mark the selected row IS, the issuing row EX; read the issuing row's fields
  .iss_sel_valid(iss_sel_valid),
  .iss_sel_ist_idx(iss_sel_ist_idx),
  .iss_valid(iss_valid),
  .iss_ist_idx(iss_ist_idx),
  .iss_opcode(iss_opcode),
  .iss_funct3(iss_funct3),
  .iss_funct7(iss_funct7),
  .iss_imm(iss_imm),
  .iss_shamt(iss_shamt),

  // clear row in WB
  .wb_en(wb_en),
  .wb_ist_idx(wb_ist_idx)
);

functional_unit_status # (
    .DATAW(DATAW),
    .NUM_ALU(NUM_ALU),
    .NUM_MULTICYCLE_MULT(NUM_MULTICYCLE_MULT),
    .NUM_LOAD_STORE(NUM_LOAD_STORE),
    .FUW(FUW),
    .IST_W(INSTR_ROW_W)
) funcStatus (
    .clock(clock),
    .reset(reset),
    // Slot assignment for the dispatching instruction's FU class
    .ds_fu_type(d_fu_id),
    .ds_assigned_fu_id(ds_assigned_fu_id), // output

    // Populate row in dispatch
    .ds_en(ds_en),
    .ds_fu_id(ds_assigned_fu_id), // actual functional unit id
    .ds_pc(d_pc),
    .ds_ist_idx(ds_ist_idx),
    .ds_rs1(d_addr_rs1),
    .ds_rs2(d_addr_rs2),
    .ds_uses_rs1(d_uses_rs1),
    .ds_uses_rs2(d_uses_rs2),
    .ds_rd(d_addr_rd),
    .ds_writes_rd(d_writes_rd),
    .ds_rs1_tag(ds_rs1_tag),
    .ds_rs2_tag(ds_rs2_tag),

    // Issue select (cycle N): RF read addresses
    .fu_ready(fu_ready),             // FU can accept an instruction (placeholder until Phase 3)
    .iss_sel_valid(iss_sel_valid),
    .iss_sel_ist_idx(iss_sel_ist_idx),
    .iss_rf_rs1(iss_rf_rs1),
    .iss_rf_rs2(iss_rf_rs2),

    // Issue (cycle N+1): instruction and operands to its FU
    .iss_rf_rs1_data(iss_rf_rs1_data),
    .iss_rf_rs2_data(iss_rf_rs2_data),
    .iss_valid(iss_valid),
    .iss_fu_id(iss_fu_id),
    .iss_ist_idx(iss_ist_idx),
    .iss_pc(iss_pc),
    .iss_rd(iss_rd),
    .iss_writes_rd(iss_writes_rd),
    .iss_op1(iss_op1),
    .iss_op2(iss_op2),

    .wb_en(wb_en),
    .wb_tag(wb_tag),
    .wb_data(wb_data)
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



/* ISSUE STAGE */
// Cycle N  : funcStatus selects the smallest-PC ready row (no pending tags, FU
//            free) and drives its source registers to the RF read ports.
// Cycle N+1: funcStatus drives the iss_* outputs (operands: forwarded WB
//            value or RF data); instrStatus supplies the decoded fields of the
//            same row.

register_file #(
  .DATAW(DATAW),
  .NUM_REGS(NUM_REGS),
  .BASE_ADDR(BASE_ADDR)
) regfile (
  .clock(clock),
  .write_enable(wb_en && wb_writes_rd),
  .addr_rs1(iss_rf_rs1), // IS select
  .addr_rs2(iss_rf_rs2), // IS select
  .addr_rd(wb_rd), // WB
  .data_rd(wb_data), // WB
  .data_rs1(iss_rf_rs1_data), // IS read data
  .data_rs2(iss_rf_rs2_data) // IS read data
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