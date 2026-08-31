// DO NOT rely on this file, it will be changed with a fresh one
`include "signals.h"

module top(
  input USE_MULTICYCLE_MULT
);
  wire clock, reset;
  clockgen clkg(
    .clk(clock),
    .rst(reset)
  );
  design_wrapper dut(
    .clock(clock),
    .reset(reset),
    .USE_MULTICYCLE_MULT(USE_MULTICYCLE_MULT)
  );
  `ifdef VCD
  initial begin
    $dumpfile(`VCD_FILE);
    $dumpvars;
  end
  `endif

  `include "tracegen.v"
endmodule
