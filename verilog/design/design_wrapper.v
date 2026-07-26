`include "signals.h"

module design_wrapper(
  // Input to the design
  input wire clock,
  input wire reset,
  output [31:0] pc
);
  wire [31:0] pc;
  `TOP_MODULE core(
    .clock(clock),
    .reset(reset),
    .pc(pc)
  );
  assign pc = pc;

endmodule
