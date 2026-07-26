`include "signals.h"

module design_wrapper(
  // Input to the design
  input wire clock,
  input wire reset,
  input wire USE_MULTICYCLE_MULT,
  output [31:0] pc
);
  wire [31:0] pc;
  `TOP_MODULE core(
    .clock(clock),
    .reset(reset),
    .USE_MULTICYCLE_MULT(USE_MULTICYCLE_MULT),
    .pc(pc)
  );
  assign pc = pc;

endmodule
