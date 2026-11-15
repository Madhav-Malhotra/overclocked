# =============================================================================
# rv32uim-p-mul8.s  —  Spike-comparable MUL test suite (8-bit-multiplier-safe)
#
# This design's multicycle multiplier (array_mult.v) is hardcoded to 8-bit
# operands: alu.v truncates idata1/idata2 to their low 8 bits before
# multiplying and sign-extends the 8-bit product back out to 32 bits (see
# alu.v / array_mult.v headers). That means MUL only matches true RV32M
# semantics (and therefore Spike) when BOTH operands AND the true product
# fit in a signed 8-bit value (-128..127) -- outside that window, truncation
# changes the answer (see rv32uim-p-mul.s, which tests that truncated
# behavior directly and is NOT Spike-comparable).
#
# Every operand/product pair in this file is deliberately chosen to stay
# within that safe window, so every MUL commit here is bit-identical to
# what Spike (true 32x32 RV32M MUL) would produce. This file is meant to be
# run through the normal build -> simulate -> spike-trace -> diff pipeline
# (make run_and_verify / run_all_benchmarks) as an ordinary benchmark.
#
# Coverage mirrors rv32uim-p-mul.s's structure (functional correctness,
# hazards, bypass paths, pipeline stress, WAR/WAW), minus the 32-bit
# overflow-specific edge cases in that file's Section B, which cannot be
# made Spike-safe without ceasing to test what they're meant to test.
#
# Register conventions:
#   x1, x2  – operand registers
#   x29     – expected result
#   x30     – actual result (or x1/x2 when rd=rs testing)
#   x3      – test number (written into tohost on fail for identification)
#   t0 (x5) – scratch for la/sw to tohost
#
# Fail path encodes the test number:  tohost = (x3 << 1) | 1
# Pass path writes 1 to tohost.
# =============================================================================

    .section .text.init
    .globl _start
_start:
    # x31 is a dedicated scratch-memory pointer for Sections F/G's
    # loads/stores -- deliberately NOT sp/x2. x2 doubles as a general MUL
    # operand register throughout this file (see Section A on), so by the
    # time Sections F/G run, x2 holds whatever small test value was last
    # loaded into it, not a real stack address. Using the "sp" alias for
    # addressing there would resolve to sw/lw off that stale x2 value: the
    # RTL's memory array silently wraps/truncates such addresses (so the
    # self-check still passes), but Spike's strict physical memory model
    # faults on the out-of-range address and hangs rather than raising a
    # clean mismatch. x31 avoids the collision entirely by never being
    # touched anywhere else in this file.
    li      x31, 0x01100000

# =============================================================================
# Section A  –  Functional correctness
# =============================================================================

# -----------------------------------------------------------------------------
# Test 1 – 0 × 0 = 0
# -----------------------------------------------------------------------------
test_1:
    addi    x1,  x0, 0
    addi    x2,  x0, 0
    mul     x30, x1, x2          # 0 * 0 = 0
    addi    x29, x0, 0
    addi    x3,  x0, 1
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 2 – 1 × 1 = 1
# -----------------------------------------------------------------------------
test_2:
    addi    x1,  x0, 1
    addi    x2,  x0, 1
    mul     x30, x1, x2          # 1 * 1 = 1
    addi    x29, x0, 1
    addi    x3,  x0, 2
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 3 – 3 × 7 = 21
# -----------------------------------------------------------------------------
test_3:
    addi    x1,  x0, 3
    addi    x2,  x0, 7
    mul     x30, x1, x2          # 3 * 7 = 21
    addi    x29, x0, 21
    addi    x3,  x0, 3
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 4 – (-1) × 1 = -1
# -----------------------------------------------------------------------------
test_4:
    addi    x1,  x0, -1
    addi    x2,  x0, 1
    mul     x30, x1, x2          # -1 * 1 = -1
    addi    x29, x0, -1
    addi    x3,  x0, 4
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 5 – (-1) × (-1) = 1
# -----------------------------------------------------------------------------
test_5:
    addi    x1,  x0, -1
    addi    x2,  x0, -1
    mul     x30, x1, x2          # (-1) * (-1) = 1
    addi    x29, x0, 1
    addi    x3,  x0, 5
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 6 – (-5) × 6 = -30
# -----------------------------------------------------------------------------
test_6:
    addi    x1,  x0, -5
    addi    x2,  x0, 6
    mul     x30, x1, x2          # -5 * 6 = -30
    addi    x29, x0, -30
    addi    x3,  x0, 6
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 7 – 12 × (-4) = -48
# -----------------------------------------------------------------------------
test_7:
    addi    x1,  x0, 12
    addi    x2,  x0, -4
    mul     x30, x1, x2          # 12 * (-4) = -48
    addi    x29, x0, -48
    addi    x3,  x0, 7
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 8 – (-127) × (-1) = 127
#   Near-INT8_MIN operand; product lands exactly at INT8_MAX. Both operands
#   and the product stay inside the safe window, unlike the original
#   0x80000000 * 2 overflow test this replaces (see rv32uim-p-mul.s test 8).
# -----------------------------------------------------------------------------
test_8:
    addi    x1,  x0, -127
    addi    x2,  x0, -1
    mul     x30, x1, x2          # -127 * -1 = 127
    addi    x29, x0, 127
    addi    x3,  x0, 8
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 9 – INT8_MAX × (-1) = -127
# -----------------------------------------------------------------------------
test_9:
    addi    x1,  x0, 127
    addi    x2,  x0, -1
    mul     x30, x1, x2          # 127 * -1 = -127
    addi    x29, x0, -127
    addi    x3,  x0, 9
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 10 – rd = rs1: MUL x1, x1, x2  (5 × 6 = 30)
# -----------------------------------------------------------------------------
test_10:
    addi    x1,  x0, 5
    addi    x2,  x0, 6
    mul     x1,  x1, x2          # rd=rs1 hazard; x1 = 5 * 6 = 30
    addi    x29, x0, 30
    addi    x3,  x0, 10
    bne     x1,  x29, fail

# -----------------------------------------------------------------------------
# Test 11 – rd = rs2: MUL x2, x1, x2  (9 × 7 = 63)
# -----------------------------------------------------------------------------
test_11:
    addi    x1,  x0, 9
    addi    x2,  x0, 7
    mul     x2,  x1, x2          # rd=rs2 hazard; x2 = 9 * 7 = 63
    addi    x29, x0, 63
    addi    x3,  x0, 11
    bne     x2,  x29, fail

# -----------------------------------------------------------------------------
# Test 12 – rd = rs1 = rs2: MUL x1, x1, x1  (8 × 8 = 64)
# -----------------------------------------------------------------------------
test_12:
    addi    x1,  x0, 8
    mul     x1,  x1, x1          # rd=rs1=rs2; x1 = 8 * 8 = 64
    addi    x29, x0, 64
    addi    x3,  x0, 12
    bne     x1,  x29, fail

# -----------------------------------------------------------------------------
# Test 13 – 123 × 0 = 0
# -----------------------------------------------------------------------------
test_13:
    addi    x1,  x0, 123
    addi    x2,  x0, 0
    mul     x30, x1, x2          # 123 * 0 = 0
    addi    x29, x0, 0
    addi    x3,  x0, 13
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 14 – 0 × (-55) = 0
# -----------------------------------------------------------------------------
test_14:
    addi    x1,  x0, 0
    addi    x2,  x0, -55
    mul     x30, x1, x2          # 0 * (-55) = 0
    addi    x29, x0, 0
    addi    x3,  x0, 14
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 15 – Write to x0 is ignored: MUL x0, x1, x2
# -----------------------------------------------------------------------------
test_15:
    addi    x1,  x0, 4
    addi    x2,  x0, 5
    mul     x0,  x1, x2          # result discarded; x0 must remain 0
    addi    x29, x0, 0
    addi    x3,  x0, 15
    bne     x0,  x29, fail

# =============================================================================
# Section B  –  Boundary values (within the 8-bit-safe window)
#
# "Boundary" here means near the edges of the safe (-128..127) window, not
# 32-bit overflow -- unlike rv32uim-p-mul.s's Section B, every case here
# still matches true RV32M/Spike semantics exactly.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 16 – Product near the negative boundary: -12 × 10 = -120
# -----------------------------------------------------------------------------
test_16:
    addi    x1,  x0, -12
    addi    x2,  x0, 10
    mul     x30, x1, x2          # -12 * 10 = -120
    addi    x29, x0, -120
    addi    x3,  x0, 16
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 17 – Product near the positive boundary: 11 × 11 = 121
# -----------------------------------------------------------------------------
test_17:
    addi    x1,  x0, 11
    addi    x2,  x0, 11
    mul     x30, x1, x2          # 11 * 11 = 121
    addi    x29, x0, 121
    addi    x3,  x0, 17
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 18 – (-1) × (-1) = 1  (all-ones × all-ones, signed)
# -----------------------------------------------------------------------------
test_18:
    addi    x1,  x0, -1
    addi    x2,  x0, -1
    mul     x30, x1, x2          # (-1) * (-1) = 1
    addi    x29, x0, 1
    addi    x3,  x0, 18
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 19 – Multiplicative identity: n × 1 = n  (positive n)
# -----------------------------------------------------------------------------
test_19:
    addi    x1,  x0, 42
    addi    x2,  x0, 1
    mul     x30, x1, x2          # 42 * 1 = 42
    addi    x29, x0, 42
    addi    x3,  x0, 19
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 20 – Multiplicative identity: n × 1 = n  (negative n)
# -----------------------------------------------------------------------------
test_20:
    addi    x1,  x0, -99
    addi    x2,  x0, 1
    mul     x30, x1, x2          # -99 * 1 = -99
    addi    x29, x0, -99
    addi    x3,  x0, 20
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 21 – n × (-1) = -n  (negation via multiply)
# -----------------------------------------------------------------------------
test_21:
    addi    x1,  x0, 77
    addi    x2,  x0, -1
    mul     x30, x1, x2          # 77 * -1 = -77
    addi    x29, x0, -77
    addi    x3,  x0, 21
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 22 – Power-of-2 equivalence: 1 × 16 = 16
# -----------------------------------------------------------------------------
test_22:
    addi    x1,  x0, 1
    addi    x2,  x0, 16
    mul     x30, x1, x2          # 1 * 16 = 16  (same as slli by 4)
    addi    x29, x0, 16
    addi    x3,  x0, 22
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 23 – Product near the negative boundary, other sign combo: -11 × 11 = -121
# -----------------------------------------------------------------------------
test_23:
    addi    x1,  x0, -11
    addi    x2,  x0, 11
    mul     x30, x1, x2          # -11 * 11 = -121
    addi    x29, x0, -121
    addi    x3,  x0, 23
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 24 – Two-digit square: 9 × 9 = 81
# -----------------------------------------------------------------------------
test_24:
    addi    x1,  x0, 9
    mv      x2,  x1
    mul     x30, x1, x2          # 9 * 9 = 81
    addi    x29, x0, 81
    addi    x3,  x0, 24
    bne     x30, x29, fail

# =============================================================================
# Section C  –  MX bypass: MUL result forwarded immediately to next MUL
# =============================================================================

# -----------------------------------------------------------------------------
# Test 25 – MX: rd of MUL#1 is rs1 of MUL#2
#   MUL x10, x1, x2  →  x10 = 3 * 4 = 12
#   MUL x30, x10, x2 →  x30 = 12 * 4 = 48
# -----------------------------------------------------------------------------
test_25:
    addi    x1,  x0, 3
    addi    x2,  x0, 4
    mul     x10, x1,  x2         # MUL#1: x10 = 3 * 4 = 12
    mul     x30, x10, x2         # MUL#2 (MX): rs1 = x10 from MUL#1; 12 * 4 = 48
    addi    x29, x0,  48
    addi    x3,  x0,  25
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 26 – MX: rd of MUL#1 is rs2 of MUL#2
#   MUL x10, x1, x2  →  x10 = 5 * 3 = 15
#   MUL x30, x2, x10 →  x30 = 3 * 15 = 45
# -----------------------------------------------------------------------------
test_26:
    addi    x1,  x0, 5
    addi    x2,  x0, 3
    mul     x10, x1,  x2         # MUL#1: x10 = 5 * 3 = 15
    mul     x30, x2,  x10        # MUL#2 (MX, rs2): 3 * 15 = 45
    addi    x29, x0,  45
    addi    x3,  x0,  26
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 27 – MX: rd of MUL#1 feeds both rs1 AND rs2 of MUL#2 (squaring)
#   MUL x10, x1, x2  →  x10 = 3 * 2 = 6
#   MUL x30, x10, x10 → x30 = 6 * 6 = 36
#   (Smaller operands than the 6/2 pair this replaces, since 12*12=144
#   would overflow the safe window -- see rv32uim-p-mul.s test 27.)
# -----------------------------------------------------------------------------
test_27:
    addi    x1,  x0, 3
    addi    x2,  x0, 2
    mul     x10, x1,  x2         # MUL#1: x10 = 6
    mul     x30, x10, x10        # MUL#2 (MX, both): 6 * 6 = 36
    addi    x29, x0,  36
    addi    x3,  x0,  27
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 28 – MX chain: three consecutive MULs
#   x10 = 2 * 3 = 6
#   x11 = 6 * 4 = 24   (MX from MUL#1)
#   x30 = 24 * 5 = 120  (MX from MUL#2)
# -----------------------------------------------------------------------------
test_28:
    addi    x1,  x0, 2
    addi    x2,  x0, 3
    addi    x4,  x0, 4
    addi    x5,  x0, 5
    mul     x10, x1,  x2         # MUL#1: x10 = 6
    mul     x11, x10, x4         # MUL#2 (MX): x11 = 6 * 4 = 24
    mul     x30, x11, x5         # MUL#3 (MX): x30 = 24 * 5 = 120
    addi    x29, x0,  120
    addi    x3,  x0,  28
    bne     x30, x29, fail

# =============================================================================
# Section D  –  WX bypass: ALU (non-MUL) result forwarded into MUL
# =============================================================================

# -----------------------------------------------------------------------------
# Test 29 – WX: ADDI result feeds rs1 of MUL
# -----------------------------------------------------------------------------
test_29:
    addi    x2,  x0,  9
    addi    x10, x0,  7          # ALU: x10 = 7
    mul     x30, x10, x2         # WX (rs1): 7 * 9 = 63
    addi    x29, x0,  63
    addi    x3,  x0,  29
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 30 – WX: ADDI result feeds rs2 of MUL
# -----------------------------------------------------------------------------
test_30:
    addi    x1,  x0,  8
    addi    x10, x0,  6          # ALU: x10 = 6
    mul     x30, x1,  x10        # WX (rs2): 8 * 6 = 48
    addi    x29, x0,  48
    addi    x3,  x0,  30
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 31 – WX: ORI result feeds rs1 of MUL
#   A purely register-writing ALU instruction with no memory access, like
#   LUI, but LUI's natural output (multiples of 0x1000) is far outside the
#   safe window, so ORI is used to keep the forwarded value safe.
# -----------------------------------------------------------------------------
test_31:
    ori     x10, x0,  16         # x10 = 16
    addi    x2,  x0,  2
    mul     x30, x10, x2         # WX: 16 * 2 = 32
    addi    x29, x0,  32
    addi    x3,  x0,  31
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 32 – WX: both rs1 and rs2 come from back-to-back ALU writes
# -----------------------------------------------------------------------------
test_32:
    addi    x10, x0,  5          # ALU: x10 = 5  (WX for rs1)
    addi    x11, x0,  11         # ALU: x11 = 11 (WX for rs2, one cycle later)
    mul     x30, x10, x11        # WX both operands: 5 * 11 = 55
    addi    x29, x0,  55
    addi    x3,  x0,  32
    bne     x30, x29, fail

# =============================================================================
# Section E  –  WM bypass: MUL result forwarded two instructions later
# =============================================================================

# -----------------------------------------------------------------------------
# Test 33 – WM: one intervening NOP between two MULs, rs1 forwarded
# -----------------------------------------------------------------------------
test_33:
    addi    x1,  x0, 3
    addi    x2,  x0, 5
    mul     x10, x1,  x2         # MUL#1: x10 = 15
    addi    x0,  x0,  0          # NOP (intervening instruction)
    mul     x30, x10, x2         # WM (rs1): 15 * 5 = 75
    addi    x29, x0,  75
    addi    x3,  x0,  33
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 34 – WM: one intervening instruction, rs2 forwarded
# -----------------------------------------------------------------------------
test_34:
    addi    x1,  x0, 7
    addi    x2,  x0, 4
    mul     x10, x1,  x2         # MUL#1: x10 = 28
    addi    x0,  x0,  0          # NOP
    mul     x30, x2,  x10        # WM (rs2): 4 * 28 = 112
    addi    x29, x0,  112
    addi    x3,  x0,  34
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 35 – WM: both operands forwarded from the same earlier MUL (squaring)
# -----------------------------------------------------------------------------
test_35:
    addi    x1,  x0, 5
    addi    x2,  x0, 2
    mul     x10, x1,  x2         # MUL#1: x10 = 10
    addi    x0,  x0,  0          # NOP
    mul     x30, x10, x10        # WM both: 10 * 10 = 100
    addi    x29, x0,  100
    addi    x3,  x0,  35
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 36 – WM mixed: MX and WM in the same chain
#   mul x10, x1, x2   →  x10 = 2 * 3 = 6    (MUL#1)
#   mul x11, x10, x2  →  x11 = 6 * 3 = 18   (MUL#2, MX: x10 from MUL#1)
#   addi x0, x0, 0    →  NOP
#   mul x30, x11, x10 →  x30 = 18 * 6 = 108
#   (Smaller operands than the 4/3 pair this replaces, since that chain
#   reaches 432 -- see rv32uim-p-mul.s test 36.)
# -----------------------------------------------------------------------------
test_36:
    addi    x1,  x0, 2
    addi    x2,  x0, 3
    mul     x10, x1,  x2         # MUL#1: x10 = 6
    mul     x11, x10, x2         # MUL#2 (MX): x11 = 18
    addi    x0,  x0,  0          # NOP
    mul     x30, x11, x10        # WM (x11) + stable (x10): 18 * 6 = 108
    addi    x29, x0,  108
    addi    x3,  x0,  36
    bne     x30, x29, fail

# =============================================================================
# Section F  –  Load-use hazard before MUL
#
# Addresses are relative to x31 (initialized once at the top), not sp/x2 --
# see the note at _start.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 37 – Load-use: LW → MUL (rs1 from load)
# -----------------------------------------------------------------------------
test_37:
    addi    x2,  x0,  11
    sw      x2,  -4(x31)         # mem[x31-4] = 11
    lw      x10, -4(x31)         # x10 = 11  (load)
    mul     x30, x10, x2         # load-use stall; 11 * 11 = 121
    addi    x29, x0,  121
    addi    x3,  x0,  37
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 38 – Load-use: LW → MUL (rs2 from load)
# -----------------------------------------------------------------------------
test_38:
    addi    x1,  x0,  7
    addi    x2,  x0,  9
    sw      x2,  -8(x31)         # mem[x31-8] = 9
    lw      x10, -8(x31)         # x10 = 9  (load)
    mul     x30, x1,  x10        # load-use stall (rs2); 7 * 9 = 63
    addi    x29, x0,  63
    addi    x3,  x0,  38
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 39 – Load-use: LW → MUL (both operands from loads at different depths)
# -----------------------------------------------------------------------------
test_39:
    addi    x2,  x0,  6
    addi    x4,  x0,  13
    sw      x2,  -12(x31)        # mem[x31-12] = 6
    sw      x4,  -16(x31)        # mem[x31-16] = 13
    lw      x10, -12(x31)        # x10 = 6
    lw      x11, -16(x31)        # x11 = 13  (load-use for rs2)
    mul     x30, x10, x11        # load-use stall on x11; 6 * 13 = 78
    addi    x29, x0,  78
    addi    x3,  x0,  39
    bne     x30, x29, fail

# =============================================================================
# Section G  –  MUL result forwarded into a store
# =============================================================================

# -----------------------------------------------------------------------------
# Test 40 – MUL then SW then LW: result correctly propagated to memory
# -----------------------------------------------------------------------------
test_40:
    addi    x1,  x0, 8
    addi    x2,  x0, 9
    mul     x10, x1,  x2         # x10 = 72
    sw      x10, -20(x31)        # store x10 (MUL→store forward)
    lw      x11, -20(x31)        # reload
    addi    x29, x0,  72
    addi    x3,  x0,  40
    bne     x11, x29, fail

# -----------------------------------------------------------------------------
# Test 41 – MUL then SW with negative result
# -----------------------------------------------------------------------------
test_41:
    addi    x1,  x0, -7
    addi    x2,  x0,  6
    mul     x10, x1,  x2         # x10 = -42
    sw      x10, -24(x31)
    lw      x11, -24(x31)
    addi    x29, x0,  -42
    addi    x3,  x0,  41
    bne     x11, x29, fail

# =============================================================================
# Section H  –  Pipeline stress
# =============================================================================

# -----------------------------------------------------------------------------
# Test 42 – Six consecutive MULs, each independent (no data hazards)
# -----------------------------------------------------------------------------
test_42:
    addi    x1,  x0, 2
    addi    x2,  x0, 3
    addi    x4,  x0, 5
    addi    x6,  x0, 7
    mul     x10, x1,  x2         # x10 = 6   (independent)
    mul     x11, x2,  x4         # x11 = 15  (independent)
    mul     x12, x4,  x6         # x12 = 35  (independent)
    mul     x13, x6,  x1         # x13 = 14  (independent)
    mul     x14, x1,  x4         # x14 = 10  (independent)
    mul     x15, x2,  x6         # x15 = 21  (independent)
    addi    x29, x0,  21
    addi    x3,  x0,  42
    bne     x15, x29, fail
    addi    x29, x0,  35
    bne     x12, x29, fail

# -----------------------------------------------------------------------------
# Test 43 – Accumulator chain: MUL product feeds the next MUL each time
# -----------------------------------------------------------------------------
test_43:
    addi    x10, x0, 1
    addi    x2,  x0, 2
    addi    x4,  x0, 3
    addi    x6,  x0, 4
    addi    x8,  x0, 5
    mul     x10, x10, x2         # MX: x10 = 2
    mul     x10, x10, x4         # MX: x10 = 6
    mul     x10, x10, x6         # MX: x10 = 24
    mul     x10, x10, x8         # MX: x10 = 120
    addi    x29, x0,  120
    addi    x3,  x0,  43
    bne     x10, x29, fail

# =============================================================================
# Section I  –  WAR (Write-After-Read) dependencies
# =============================================================================

# -----------------------------------------------------------------------------
# Test 44 – WAR: MUL#2 writes the register MUL#1 used as rs1
# -----------------------------------------------------------------------------
test_44:
    addi    x10, x0,  3
    addi    x2,  x0,  5
    mul     x30, x10, x2          # MUL#1: reads x10=3; x30 = 3*5 = 15
    mul     x10, x2,  x2          # MUL#2 (WAR): writes x10 = 5*5 = 25
    addi    x29, x0,  15
    addi    x3,  x0,  44
    bne     x30, x29, fail        # x30 must be 15, not 25

# -----------------------------------------------------------------------------
# Test 45 – WAR: MUL#2 writes the register MUL#1 used as rs2
# -----------------------------------------------------------------------------
test_45:
    addi    x1,  x0,  7
    addi    x10, x0,  4
    addi    x2,  x0,  9
    mul     x30, x1,  x10         # MUL#1: reads x10=4; x30 = 7*4 = 28
    mul     x10, x1,  x2          # MUL#2 (WAR): writes x10 = 7*9 = 63
    addi    x29, x0,  28
    addi    x3,  x0,  45
    bne     x30, x29, fail        # x30 must be 28, not 63

# -----------------------------------------------------------------------------
# Test 46 – WAR: MUL followed immediately by ALU writing MUL's rs1
# -----------------------------------------------------------------------------
test_46:
    addi    x10, x0,  6
    addi    x2,  x0,  8
    mul     x30, x10, x2          # MUL#1: reads x10=6; x30 = 6*8 = 48
    addi    x10, x0,  99          # ALU (WAR): writes x10=99 while MUL#1 is still in flight
    addi    x29, x0,  48
    addi    x3,  x0,  46
    bne     x30, x29, fail        # x30 must be 48, not derived from 99

# -----------------------------------------------------------------------------
# Test 47 – WAR: both rs1 and rs2 of MUL#1 are overwritten by MUL#2/MUL#3
# -----------------------------------------------------------------------------
test_47:
    addi    x10, x0,  2
    addi    x11, x0,  3
    addi    x1,  x0,  5
    addi    x2,  x0,  7
    mul     x30, x10, x11         # MUL#1: reads x10=2, x11=3; x30 = 2*3 = 6
    mul     x10, x1,  x2          # MUL#2 (WAR rs1): x10 = 35
    mul     x11, x2,  x1          # MUL#3 (WAR rs2): x11 = 35
    addi    x29, x0,  6
    addi    x3,  x0,  47
    bne     x30, x29, fail

# =============================================================================
# Section J  –  WAW (Write-After-Write) dependencies
# =============================================================================

# -----------------------------------------------------------------------------
# Test 48 – WAW: MUL first, then ALU writes same rd; ALU must win
# -----------------------------------------------------------------------------
test_48:
    addi    x1,  x0,  3
    addi    x2,  x0,  4
    mul     x10, x1,  x2          # WAW write #1: x10 ← 12 (arrives late)
    addi    x10, x0,  99          # WAW write #2: x10 ← 99 (arrives early in WB)
    addi    x29, x0,  99
    addi    x3,  x0,  48
    bne     x10, x29, fail        # if x10 = 12, MUL's stale write clobbered ADDI

# -----------------------------------------------------------------------------
# Test 49 – WAW: ALU first, then MUL writes same rd; MUL must win
# -----------------------------------------------------------------------------
test_49:
    addi    x1,  x0,  6
    addi    x2,  x0,  7
    addi    x10, x0,  55          # WAW write #1: x10 ← 55
    mul     x10, x1,  x2          # WAW write #2: x10 ← 42 (must be final value)
    addi    x29, x0,  42
    addi    x3,  x0,  49
    bne     x10, x29, fail        # if x10 = 55, MUL's write was lost

# -----------------------------------------------------------------------------
# Test 50 – WAW: two MULs writing the same rd; second must win
# -----------------------------------------------------------------------------
test_50:
    addi    x1,  x0,  2
    addi    x2,  x0,  3
    addi    x4,  x0,  5
    addi    x6,  x0,  7
    mul     x10, x1,  x2          # WAW MUL#1: x10 ← 6
    mul     x10, x4,  x6          # WAW MUL#2: x10 ← 35 (must be final)
    addi    x29, x0,  35
    addi    x3,  x0,  50
    bne     x10, x29, fail

# -----------------------------------------------------------------------------
# Test 51 – WAW: MUL writes rd, then LUI writes same rd; LUI must win
#   (LUI's own value is unrelated to the multiplier -- LUI is an unaffected
#   pass-through op in alu.v -- only the MUL operands/product need to stay
#   in the safe window.)
# -----------------------------------------------------------------------------
test_51:
    addi    x1,  x0,  9
    addi    x2,  x0,  4
    mul     x10, x1,  x2          # WAW write #1: x10 ← 36
    lui     x10, 0xABCDE          # WAW write #2: x10 ← 0xABCDE000 (must win)
    lui     x29, 0xABCDE          # x29 = 0xABCDE000
    addi    x3,  x0,  51
    bne     x10, x29, fail

# -----------------------------------------------------------------------------
# Test 52 – WAW + RAW combined: after WAW resolves, RAW must see the winner
# -----------------------------------------------------------------------------
test_52:
    addi    x1,  x0,  3
    addi    x2,  x0,  5
    addi    x4,  x0,  4
    addi    x6,  x0,  6
    mul     x10, x1,  x2          # WAW write #1: x10 ← 15
    mul     x10, x4,  x6          # WAW write #2: x10 ← 24 (must win)
    mul     x30, x10, x2          # RAW: x30 = 24*5 = 120
    addi    x29, x0,  120
    addi    x3,  x0,  52
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
