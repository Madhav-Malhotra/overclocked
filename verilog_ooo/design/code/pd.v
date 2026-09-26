// =============================================================================
// Module:      pd
// Description: <NEED TO ADD THIS>
// Inputs:      clock - processor clock
//              reset - synchronous reset; returns PC to BASE_ADDR
// Outputs:     (none - all state is internal; testbench probes internal signals)
// =============================================================================
module pd #(
  parameter DATAW = 32,
  parameter BASE_ADDR = 32'h01000000,
  parameter ADDRW = $clog2(DATAW),
  parameter N_BITS = $clog2(DATAW),

  // functional units
  parameter NUM_ALU = 2,
  parameter NUM_MULTICYCLE_MULT = 1,
  parameter NUM_LOAD_STORE = 1
)(
  input clock,
  input reset
);

/* WIRES/REGISTERS */

// Fetch
reg [32:0]  f_pc = BASE_ADDR;
reg [32:0]  f_imem_in;
reg         f_imem_rw = 0;
wire        f_imem_enable;
reg [32:0]  f_instr_out;

// Decode
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
     d_pc<= 0;  
  end else begin 
    d_pc <= f_pc;
    d_instr <= f_instr_out;

  end 

end 


decoder dec (
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
  .is_i_type_w(d_is_i_type_w)
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




/* WRITEBACK STAGE: writeback unit*/








endmodule