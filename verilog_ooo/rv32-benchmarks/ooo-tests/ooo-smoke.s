# =============================================================================
# ooo-smoke.s - minimal branch-free smoke test for the OoO core (Phase 0)
#
# Exercises: ALU reg/imm ops, LUI/AUIPC, a RAW chain, an independent MUL
# (MCM), and a store/load pair. Contains NO branches or jumps (plan.md D5).
#
# Expected OoO behaviour once Phases 1-4 are done:
#   - the MUL (x10) completes ~33 cycles after issue; the independent adds
#     that follow it (x11, x12) write back before it.
#   - final registers match spike (cmp_ooo_spike.py).
# =============================================================================
.section .text.init
.globl _start

_start:
    addi    x1, x0, 5           # x1 = 5
    addi    x2, x0, 7           # x2 = 7
    add     x3, x1, x2          # x3 = 12           (RAW on x1, x2)
    sub     x4, x3, x1          # x4 = 7            (RAW on x3)
    xori    x5, x4, 0xff        # x5 = 0xf8
    lui     x6, 0x12345         # x6 = 0x12345000
    auipc   x7, 0               # x7 = pc
    slli    x8, x2, 3           # x8 = 56
    sltu    x9, x1, x2          # x9 = 1
    mul     x10, x1, x2         # x10 = 35          (MCM, long latency)
    addi    x11, x0, 100        # x11 = 100         (independent of the mul)
    addi    x12, x11, 1         # x12 = 101
    la      x13, test_data      # x13 = &test_data
    sw      x3, 0(x13)          # mem[test_data] = 12
    lw      x14, 0(x13)         # x14 = 12          (load after store, same address)
    add     x15, x10, x14       # x15 = 47          (waits on the mul)

pass:
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 1           # HTIF: 1 = pass ((code<<1)|1); writing 0 makes spike hang
    sw      a0, 0(t0)
    ecall
    unimp

.section .data
.align 4
test_data:
    .word 0x00000000
    .word 0xDEADBEEF
