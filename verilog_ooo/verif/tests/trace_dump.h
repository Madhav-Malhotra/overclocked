// =============================================================================
// trace_dump.h - out-of-order event trace writer (included by tracegen.v)
//
// Unlike the scalar FDXMW trace (one line per stage every cycle), the OoO
// trace prints a line only when an event happens. Each event is enabled by
// its *_VALID macro in design/signals.h. Every line ends with "@<cycle>".
//
//   [F] pc instr                                   fetch -> decode
//   [D] ist_idx pc fu rd rs1 rs2 rs1_tag rs2_tag   dispatch ("-" if ist_idx n/a)
//   [D] - pc 0 nop                                 NONE-class instr consumed
//   [I] ist_idx pc fu op1 op2                      operands read, FU issued
//   [X] ist_idx pc fu result                       FU result valid
//   [M] pc addr size_bytes data                    data-memory write
//   [W] pc we rd data                              writeback (scalar [W] format)
//   [S] reason [reason...]                         dispatch stall started/changed
//   [S] resume                                     dispatch stall ended
//
// All values are hex except size_bytes and the cycle number.
// [W] keeps the scalar field order so verilog/verif/scripts tools can parse it.
// =============================================================================
integer __trace_fd;
integer __cycle;
reg [4:0] __stall_now, __stall_prev;   // {stalled, buf_full, fu_busy, waw, br_drain}
initial begin
  __trace_fd = $fopen(`TRACE_FILE, "w");
  __cycle = 0;
  __stall_prev = 5'b0;
end

always @(posedge clock) begin
  if (reset) __cycle <= 0;
  else       __cycle <= __cycle + 1;
end

always @(negedge clock) begin
  if (reset == 0) begin

`ifdef F_VALID
    if (`F_VALID)
      $fwrite(__trace_fd, "[F] %x %x @%0d\n", `F_PC, `F_INSN, __cycle);
`endif

`ifdef D_VALID
    if (`D_VALID) begin
  `ifdef D_IST_IDX
      $fwrite(__trace_fd, "[D] %0d %x %0d %0d %0d %0d %0d %0d @%0d\n", `D_IST_IDX,
  `else
      $fwrite(__trace_fd, "[D] - %x %0d %0d %0d %0d %0d %0d @%0d\n",
  `endif
        `D_PC, `D_FU, `D_RD, `D_RS1, `D_RS2, `D_RS1_TAG, `D_RS2_TAG, __cycle);
    end
`endif

`ifdef D_NOP_VALID
    if (`D_NOP_VALID)
      $fwrite(__trace_fd, "[D] - %x 0 nop @%0d\n", `D_PC, __cycle);
`endif

`ifdef I_VALID
    if (`I_VALID)
      $fwrite(__trace_fd, "[I] %0d %x %0d %x %x @%0d\n",
        `I_IST_IDX, `I_PC, `I_FU, `I_OP1, `I_OP2, __cycle);
`endif

`ifdef X_VALID
    if (`X_VALID)
      $fwrite(__trace_fd, "[X] %0d %x %0d %x @%0d\n",
        `X_IST_IDX, `X_PC, `X_FU, `X_RESULT, __cycle);
`endif

`ifdef M_VALID
    if (`M_VALID)
      $fwrite(__trace_fd, "[M] %x %x %0d %x @%0d\n",
        `M_PC, `M_ADDR,
        (`M_SIZE_ENC == 0) ? 1 : (`M_SIZE_ENC == 1) ? 2 : 4,
        (`M_SIZE_ENC == 0) ? (`M_DATA & 32'h000000ff) :
        (`M_SIZE_ENC == 1) ? (`M_DATA & 32'h0000ffff) : `M_DATA,
        __cycle);
`endif

`ifdef W_VALID
    if (`W_VALID)
      $fwrite(__trace_fd, "[W] %x %x %x %x @%0d\n",
        `W_PC, `W_ENABLE, `W_DEST, `W_DATA, __cycle);
`endif

`ifdef S_VALID
    // Logged only when the stall starts or its reason set changes; "[S] resume"
    // when dispatch is no longer stalled. Avoids one line per stalled cycle.
    __stall_now = (`S_VALID) ? {1'b1, (`S_BUF_FULL) ? 1'b1 : 1'b0, (`S_NO_FU) ? 1'b1 : 1'b0,
                                     (`S_WAW) ? 1'b1 : 1'b0, (`S_BR_DRAIN) ? 1'b1 : 1'b0}
                            : 5'b0;
    if (__stall_now != __stall_prev) begin
      if (__stall_now[4]) begin
        $fwrite(__trace_fd, "[S]");
        if (__stall_now[3]) $fwrite(__trace_fd, " buf_full");
        if (__stall_now[2]) $fwrite(__trace_fd, " fu_busy");
        if (__stall_now[1]) $fwrite(__trace_fd, " waw");
        if (__stall_now[0]) $fwrite(__trace_fd, " br_drain");
        if (__stall_now[3:0] == 4'b0) $fwrite(__trace_fd, " other");
        $fwrite(__trace_fd, " @%0d\n", __cycle);
      end else begin
        $fwrite(__trace_fd, "[S] resume @%0d\n", __cycle);
      end
    end
    __stall_prev = __stall_now;
`endif

    $fflush(__trace_fd);
  end
end
