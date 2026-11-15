// =============================================================================
// Module:      mult_stall_signals
// Description: Evaluates start and stall conditions for using the multi-cycle multiplier 
// Inputs:      pc_dx_r, to check if stall occured
//              alu_sel, multicyc_sel, array_mult_busy to see if stall is applicable
// Outputs:     array_mult_start   - triggers beginning of multi-cycle multiplication (defined in alu) 
//              mult_stall         - asserted when stall is required
//              array_mult_hold    - control signal for array mult
// =============================================================================
module mult_stall_signals #(
    parameter DATAW = 32
)( 
    input clock,
    input reset,
    input [DATAW-1:0] pc_dx_r,
    input [3:0] alu_sel,
    input multicyc_sel,
    input array_mult_busy,
    output array_mult_start,
    output mul_stall,
    output array_mult_hold
);

    localparam MUL_ALU = 4'd11;   // alu_sel encoding for MUL (used to detect MUL in EX)

    wire is_mul_exec = (alu_sel == MUL_ALU);

    reg  array_mult_busy_d1;
    reg  prev_is_mul;
    reg  [DATAW-1:0] prev_pc_dx_r;

    always @(posedge clock) begin
        if (reset) begin
            array_mult_busy_d1 <= 1'b0;
            prev_is_mul        <= 1'b0;
            prev_pc_dx_r       <= {DATAW{1'b0}};
        end else begin
            array_mult_busy_d1 <= array_mult_busy;
            prev_is_mul        <= is_mul_exec;
            prev_pc_dx_r       <= pc_dx_r;
        end
    end

    wire mul_just_started = multicyc_sel && is_mul_exec && (!prev_is_mul || (pc_dx_r != prev_pc_dx_r));

    assign array_mult_start = multicyc_sel && mul_just_started;    
    assign mul_stall = multicyc_sel && (array_mult_busy || array_mult_busy_d1 || mul_just_started);
    assign array_mult_hold = multicyc_sel && is_mul_exec;


endmodule