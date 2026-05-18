// =============================================================================
// Module:      array_mult
// Description: Multicycle 32x32 signed multiplier (low 32 bits of product).
//              Each cycle adds one row of the unsigned magnitude array:
//                row_k = (|a| AND {33{|b|_k}}) with implicit shift folded into
//                a widening multiplicand register `mdc` (left shift per step).
//              After 33 magnitude bits, the unsigned row sum is sign-corrected
//              in 64 bits (two's complement negate when signs differ) and the
//              low 32 bits are registered as `result`.
//
//              Control interface (for parent pipeline):
//              - start_pulse: one-cycle pulse when a new MUL enters EX; latches
//                operands from op_a/op_b and begins the 33-cycle accumulation.
//              - hold: high while the EX stage still holds a MUL (alu_sel==MUL);
//                if hold drops during RUN (instruction flushed), the array aborts.
//
//              busy is high for the entire multiply. The parent stalls until
//              busy falls and then for one more cycle (see pd.v busy_d1) so XM
//              captures a stable registered product.
// =============================================================================
module array_mult #(
    parameter DATAW = 32
) (
    input wire clock,
    input wire reset,
    input wire start_pulse,
    input wire hold,
    input wire [DATAW-1:0] op_a,
    input wire [DATAW-1:0] op_b,
    output reg [DATAW-1:0] result,
    output reg busy
);

  function automatic [32:0] abs33(input [DATAW-1:0] x);
    reg signed [31:0] xs;
    begin
      xs = $signed(x);
      if (xs == -32'sd2147483648)
        abs33 = 33'h0_8000_0000;
      else if (xs < 0)
        abs33 = 33'd0 - $unsigned(xs);
      else
        abs33 = {1'b0, x};
    end
  endfunction

  localparam [1:0] S_IDLE = 2'd0;
  localparam [1:0] S_RUN = 2'd1;

  reg [1:0] state;
  reg [5:0] cnt;

  reg neg_r;
  reg [63:0] acc_u;
  reg [63:0] mdc;
  reg [32:0] b_rem;

  wire [32:0] mag_a = abs33(op_a);
  wire neg_comb = op_a[DATAW-1] ^ op_b[DATAW-1];

  wire [63:0] signed_mag = neg_r ? (~acc_u + 64'd1) : acc_u;

  wire go = start_pulse && (state == S_IDLE);

  always @(posedge clock) begin
    if (reset) begin
      state <= S_IDLE;
      busy <= 1'b0;
      cnt <= 6'd0;
      result <= 32'd0;
      neg_r <= 1'b0;
      acc_u <= 64'd0;
      mdc <= 64'd0;
      b_rem <= 33'd0;
    end else if (!hold && (state == S_RUN)) begin
      state <= S_IDLE;
      busy <= 1'b0;
    end else begin
      case (state)
        S_IDLE: begin
          if (go) begin
            neg_r <= neg_comb;
            acc_u <= 64'd0;
            mdc <= {31'd0, mag_a};
            b_rem <= abs33(op_b);
            cnt <= 6'd0;
            state <= S_RUN;
            busy <= 1'b1;
          end else begin
            busy <= 1'b0;
          end
        end
        S_RUN: begin
          if (cnt < 6'd33) begin
            if (b_rem[0])
              acc_u <= acc_u + mdc;
            mdc <= mdc << 1;
            b_rem <= b_rem >> 1;
            cnt <= cnt + 6'd1;
          end else begin
            result <= signed_mag[31:0];
            state <= S_IDLE;
            busy <= 1'b0;
          end
        end
        default: state <= S_IDLE;
      endcase
    end
  end

endmodule
