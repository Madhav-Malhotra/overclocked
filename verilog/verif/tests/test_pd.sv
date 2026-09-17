// DO NOT rely on this file, it will be changed with a fresh one
`include "signals.h"

module top;
  wire clock, reset;

  reg [31:0] pc;
  reg [31:0] fd_pc;
  reg [31:0] fd_pc4;
  reg [6:0] opcode_fd;
  reg [4:0] addr_rd_fd;
  reg [6:0] opcode_dx;
  reg [4:0] addr_rd_dx;
  reg [31:0] dx_pc;
  reg [31:0] dmem_data_in;
  reg [6:0] opcode_xm;
  reg [4:0] addr_rd_xm;
  reg [31:0] xm_pc;
  reg [31:0] wb_in_alu;
  reg [31:0] mem;
  reg [31:0] mw_pc4;
  reg [6:0] opcode_mw;
  reg [4:0] addr_rd_mw;
  reg [31:0] mw_pc;

  clockgen clkg(
    .clk(clock),
    .rst(reset)
  );
  design_wrapper dut(
    .clock(clock),
    .reset(reset),
    .pc(pc),
    .fd_pc(fd_pc),
    .fd_pc4(fd_pc4),
    .opcode_fd(opcode_fd),
    .addr_rd_fd(addr_rd_fd),
    .opcode_dx(opcode_dx),
    .addr_rd_dx(addr_rd_dx),
    .dx_pc(dx_pc),
    .dmem_data_in(dmem_data_in),
    .opcode_xm(opcode_xm),
    .addr_rd_xm(addr_rd_xm),
    .xm_pc(xm_pc),
    .wb_in_alu(wb_in_alu),
    .mem(mem),
    .mw_pc4(mw_pc4),
    .opcode_mw(opcode_mw),
    .addr_rd_mw(addr_rd_mw),
    .mw_pc(mw_pc)
  );
  `ifdef VCD
  initial begin
    $dumpfile(`VCD_FILE);
    $dumpvars;
  end
  `endif

  `include "tracegen.v"
endmodule
