// =============================================================================
// Module:      array_mult
// Description: Multicycle 32×32 signed multiplier, low 32 bits of product.
//              In the OoO core this is the MCM functional unit (FU id 2), the
//              only multiply path (plan.md D7): MUL only, no divide (D7a).
//
//              Algorithm — serial shift-and-add in direct 2's complement.
//              No abs/negate step is needed because the MSB of op_b simply
//              carries a negative weight in 2's complement:
//
//                for i = 0 .. 30:  if b[i]  acc += sign_ext(a) << i   (+weight)
//                for i = 31:       if b[31]  acc -= sign_ext(a) << 31  (−weight)
//
//              A 64-bit accumulator prevents overflow across all partial sums.
//              op_a / op_b are latched at ex_valid so later activity
//              on the issue wires cannot corrupt the result.
//
//              Latency: 33 clock cycles from ex_valid to busy deasserting
//                (32 accumulate + 1 result-latch); result_valid rises with
//                the result latch, i.e. 34 cycles from the issue cycle to the
//                first cycle result_valid is high.
//
//              OoO functional-unit interface (ready/valid):
//                ex_valid    One-cycle pulse when a MUL is issued to the MCM.
//                fu_ready     MCM can accept a MUL (not busy, no result held).
//                result_valid Product computed; held until wb_ready (plan.md D3).
//                wb_ready     Writeback takes the product this cycle.
//              There is no hold/abort input: the OoO core does not squash
//              instructions (branch handling is decided in plan.md Phase 6).
// =============================================================================
module array_mult #(
    parameter DATAW = 32
) (
    input  wire             clock,
    input  wire             reset,
    input  wire             ex_valid,
    input  wire [DATAW-1:0] op_a,
    input  wire [DATAW-1:0] op_b,
    output wire             fu_ready,
    output reg  [DATAW-1:0] result,
    output reg              result_valid,
    input  wire             wb_ready
);

localparam S_IDLE = 1'b0;
localparam S_RUN  = 1'b1;

reg       state;
reg [5:0] cnt;    // bit position currently being processed (0 = LSB of op_b)

// Latched at ex_valid to isolate the unit from the live issue wires.
reg signed [2*DATAW-1:0] mdc;     // sign_ext(op_a) left-shifted by cnt each cycle
reg        [DATAW-1:0]   b_shift; // shift register; LSB is always the current bit

// 64-bit accumulator: wide enough to hold all intermediate partial sums exactly.
reg signed [2*DATAW-1:0] acc;

reg busy;  // high for the full computation

// High for one cycle: a new MUL arrives and the unit is free.
wire go = ex_valid && (state == S_IDLE);

always @(posedge clock) begin
    if (reset) begin
        state   <= S_IDLE;
        busy    <= 1'b0;
        cnt     <= 6'd0;
        result  <= {DATAW{1'b0}};
        mdc     <= {2*DATAW{1'b0}};
        b_shift <= {DATAW{1'b0}};
        acc     <= {2*DATAW{1'b0}};
        result_valid <= 1'b0;
    end else begin
        if (wb_ready) result_valid <= 1'b0;
        case (state)
            S_IDLE: begin
                if (go) begin
                    // Sign-extend op_a to 64 bits so every partial product
                    // propagates the correct sign without a correction step.
                    mdc     <= {{DATAW{op_a[DATAW-1]}}, op_a};
                    b_shift <= op_b;
                    acc     <= {2*DATAW{1'b0}};
                    cnt     <= 6'd0;
                    state   <= S_RUN;
                    busy    <= 1'b1;
                end
            end
            S_RUN: begin
                if (cnt < DATAW) begin
                    // Bit DATAW-1 has weight −2^(DATAW-1) in 2's complement:
                    // subtract its contribution.  All lower bits add normally.
                    if (b_shift[0])
                        acc <= (cnt == DATAW - 1) ? acc - mdc : acc + mdc;
                    mdc     <= mdc << 1;      // advance column: op_a << (cnt+1)
                    b_shift <= b_shift >> 1;  // expose the next bit of op_b
                    cnt     <= cnt + 6'd1;
                end else begin
                    // All DATAW bits of op_b consumed; latch the low DATAW bits.
                    result <= acc[DATAW-1:0];
                    result_valid <= 1'b1;
                    state  <= S_IDLE;
                    busy   <= 1'b0;
                end
            end
            default: state <= S_IDLE;
        endcase
    end
end

// Ready when no multiply is running and no product is waiting for writeback
assign fu_ready = !busy && !result_valid;

endmodule
