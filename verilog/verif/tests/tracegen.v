// The following code will not be synthesizable
`include "fields.h"
generate if(`GEN_TRACE == 1) begin
  `include "trace_dump.h"
end
endgenerate
