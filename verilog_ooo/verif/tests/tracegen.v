// The following code will not be synthesizable.
// Included inside `module top` (test_pd.sv): `clock`, `reset`, and `dut` are in scope.

generate if (`GEN_TRACE == 1) begin : g_trace
  `include "trace_dump.h"
end
endgenerate

// End the simulation once the core reports it is done (see SIM_DONE in
// design/signals.h). Without SIM_DONE the run ends at TIMEOUT (clockgen.sv).
`ifdef SIM_DONE
  `ifndef SIM_DONE_DELAY
    `define SIM_DONE_DELAY 5
  `endif
  integer __done_cnt = 0;
  always @(posedge clock) begin
    if (!reset && (`SIM_DONE)) begin
      __done_cnt <= __done_cnt + 1;
      if (__done_cnt == `SIM_DONE_DELAY) begin
        $display("SIM_DONE: core finished");
        $finish;
      end
    end
  end
`endif
