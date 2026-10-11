# =============================================================================
# superscalar_mul_branch.s  —  MUL interaction with the 2-way superscalar pipe
#
# Targets the multicycle multiplier (MULTICYCLE=1) in verilog_ss: MULs placed
# in a specific way (way 0 = pc % 8 == 0, way 1 = pc % 8 == 4, forced with
# .balign 8) alongside branches, jumps, loads, stores and dependent MULs.
#
# All operands/products fit in signed 8 bits, so results are identical for
# the 8-bit array_mult, the single-cycle `*` path, and Spike.
#
# Register conventions:
#   x30 – value under test, x29 – expected, x3 – test number
#   x31 – scratch-memory pointer (never used as a MUL operand)
# Fail path: tohost = (x3 << 1) | 1.  Pass path: tohost = 1.
# =============================================================================

    .section .text.init
    .globl _start
_start:
    li      x31, 0x01100000
    li      x1, 3
    li      x2, 5

# -----------------------------------------------------------------------------
# Test 1 – way 0 taken branch, way 1 MUL (younger): MUL must be squashed
# -----------------------------------------------------------------------------
    addi    x30, x0, 7
    .balign 8
t1_pair:
    beq     x0, x0, t1_tgt       # way 0: taken
    mul     x30, x1, x2          # way 1: must NOT commit
    addi    x30, x0, 99          # must NOT execute
    addi    x30, x0, 98          # must NOT execute
t1_tgt:
    addi    x29, x0, 7
    addi    x3,  x0, 1
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 2 – way 0 MUL, way 1 taken branch (younger): MUL commits, skip fallthru
# -----------------------------------------------------------------------------
    addi    x30, x0, 0
    .balign 8
t2_pair:
    mul     x30, x1, x2          # way 0: 15
    beq     x0, x0, t2_tgt       # way 1: taken
    addi    x30, x0, 99          # must NOT execute
    addi    x30, x0, 98          # must NOT execute
t2_tgt:
    addi    x29, x0, 15
    addi    x3,  x0, 2
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 3 – way 0 MUL, way 1 JAL (younger): MUL commits, link written
# -----------------------------------------------------------------------------
    .balign 8
t3_pair:
    mul     x30, x2, x2          # way 0: 25
    jal     x6, t3_tgt           # way 1
    addi    x30, x0, 99          # must NOT execute
t3_tgt:
    addi    x29, x0, 25
    addi    x3,  x0, 3
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 4 – way 0 not-taken branch, way 1 MUL: MUL must commit
# -----------------------------------------------------------------------------
    .balign 8
t4_pair:
    bne     x0, x0, fail         # way 0: not taken
    mul     x30, x1, x1          # way 1: 9
    addi    x29, x0, 9
    addi    x3,  x0, 4
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 5 – way 1 MUL feeding next pair's way 0 branch (MX into branch comp)
# -----------------------------------------------------------------------------
    .balign 8
    addi    x0, x0, 0            # way 0
    mul     x30, x1, x2          # way 1: 15
    addi    x29, x0, 15          # way 0
    addi    x3,  x0, 5           # way 1
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 6 – same-pair dependence: way 0 MUL, way 1 MUL uses its result
# -----------------------------------------------------------------------------
    .balign 8
t6_pair:
    mul     x10, x1, x2          # way 0: 15
    mul     x30, x10, x1         # way 1: 45 (needs way 0's result)
    addi    x29, x0, 45
    addi    x3,  x0, 6
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 7 – both ways MUL, independent, same pair
# -----------------------------------------------------------------------------
    .balign 8
t7_pair:
    mul     x10, x1, x1          # way 0: 9
    mul     x11, x2, x2          # way 1: 25
    add     x30, x10, x11        # 34
    addi    x29, x0, 34
    addi    x3,  x0, 7
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 8 – load-use into MUL (way 1 load, way 0 MUL in next pair)
# -----------------------------------------------------------------------------
    addi    x12, x0, 6
    sw      x12, 0(x31)
    .balign 8
    addi    x0, x0, 0            # way 0
    lw      x13, 0(x31)          # way 1
    mul     x30, x13, x1         # way 0: 18 (load-use stall)
    addi    x29, x0, 18
    addi    x3,  x0, 8
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 9 – MUL result stored immediately (WM bypass) then reloaded
# -----------------------------------------------------------------------------
    .balign 8
    mul     x14, x2, x1          # way 0: 15
    sw      x14, 4(x31)          # way 1: store MUL result
    lw      x30, 4(x31)
    addi    x29, x0, 15
    addi    x3,  x0, 9
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 10 – way 1 MUL, next pair way 1 MUL dependent with way 0 NOP between
#           (regression for the stale-bubble stall_occured bug)
# -----------------------------------------------------------------------------
    .balign 8
    addi    x0, x0, 0            # way 0
    mul     x10, x1, x2          # way 1: 15
    addi    x0, x0, 0            # way 0
    mul     x30, x10, x1         # way 1: 45
    addi    x29, x0, 45
    addi    x3,  x0, 10
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 11 – MUL in a short loop (taken back-edge right after MUL)
# -----------------------------------------------------------------------------
    addi    x15, x0, 1           # acc
    addi    x16, x0, 3           # count
    .balign 8
t11_loop:
    mul     x15, x15, x16        # acc: 1*3=3, 3*2=6, 6*1=6
    addi    x16, x16, -1
    bne     x16, x0, t11_loop
    addi    x30, x15, 0
    addi    x29, x0, 6
    addi    x3,  x0, 11
    bne     x30, x29, fail

# =============================================================================
# PASS
# =============================================================================
pass:
    fence   iorw, iorw
    addi    x3,  x0, 1
    la      t0,  tohost
    sw      x3,  0(t0)
    ecall
    unimp

# =============================================================================
# FAIL
# Encodes test number: tohost = (test_number << 1) | 1
# =============================================================================
fail:
    fence   iorw, iorw
    beq     x3,  x0,  fail+0x4
    slli    x3,  x3,  1
    ori     x3,  x3,  1
    la      t0,  tohost
    sw      x3,  0(t0)
    ecall
