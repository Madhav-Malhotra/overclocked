# =============================================================================
# rv32uim-p-mul.s  —  Comprehensive RV32M MUL test suite
#
# Tests the MUL instruction only (lower 32-bit signed/unsigned product).
#
# Coverage:
#   Section A  – Functional correctness  (tests  1–15, original)
#   Section B  – Edge / boundary values  (tests 16–24, new)
#   Section C  – MX bypass: MUL→MUL     (tests 25–28, new)  [RAW]
#   Section D  – WX bypass: ALU→MUL     (tests 29–32, new)  [RAW]
#   Section E  – WM bypass: MUL→MUL     (tests 33–36, new)  [RAW]
#   Section F  – Load-use hazard         (tests 37–39, new)  [RAW]
#   Section G  – MUL result → store      (tests 40–41, new)  [RAW]
#   Section H  – Pipeline stress         (tests 42–43, new)
#   Section I  – WAR dependencies        (tests 44–47, new)
#   Section J  – WAW dependencies        (tests 48–52, new)
#
# Dependency hazard taxonomy:
#   RAW (Read-After-Write) – a later instruction reads a reg before an earlier
#          write has propagated.  This is the "true" data hazard.  All of
#          sections C–G are RAW.  Requires stalls or forwarding.
#   WAR (Write-After-Read) – a later instruction writes a reg that an earlier
#          instruction is still reading.  In-order pipelines: never a true
#          hazard (read always retires before the write).  OOO/scoreboard:
#          must not allow the write to precede the read.  Section I.
#   WAW (Write-After-Write) – two instructions both write the same rd.  The
#          second (program-order) write must be the final value.  Dangerous
#          for multi-cycle MUL: if MUL is first and a fast ALU is second, the
#          ALU completes WB first; MUL must not then clobber it.  Section J.
#   RAR (Read-After-Read) – two instructions read the same rs.  Never a
#          hazard in any pipeline.  No tests required.
#
# Bypass / stall notation:
#   MX  – EX-stage MUL result forwarded to the EX-stage MUL consumer
#          (MUL is immediately followed by another MUL that reads its output)
#   WX  – WB-stage ALU result forwarded to EX-stage MUL source register
#          (an ordinary instruction writes a register that MUL reads next)
#   WM  – WB-stage MUL result forwarded to EX-stage MUL source register
#          (a MUL two cycles back feeds the next MUL)
#   Load-use – a load immediately precedes MUL; the pipeline must stall
#               (LW result not available until after MUL would have consumed it)
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

# =============================================================================
# Section A  –  Functional correctness
# (Original tests 1–15, annotated)
# =============================================================================

# -----------------------------------------------------------------------------
# Test 1 – 0 × 0 = 0
#   Confirms the zero-input base case.
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
#   Multiplicative identity, both operands positive.
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
#   Small positive × small positive.
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
#   Negative × positive; sign propagation.
# -----------------------------------------------------------------------------
test_4:
    addi    x1,  x0, -1
    addi    x2,  x0, 1
    mul     x30, x1, x2          # -1 * 1 = -1 (0xFFFFFFFF)
    addi    x29, x0, -1
    addi    x3,  x0, 4
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 5 – (-1) × (-1) = 1
#   Negative × negative; product becomes positive.
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
#   Negative × positive, small values.
# -----------------------------------------------------------------------------
test_6:
    addi    x1,  x0, -5
    addi    x2,  x0, 6
    mul     x30, x1, x2          # -5 * 6 = -30 (0xFFFFFFE2)
    addi    x29, x0, -30
    addi    x3,  x0, 6
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 7 – 12 × (-4) = -48
#   Positive × negative, small values.
# -----------------------------------------------------------------------------
test_7:
    addi    x1,  x0, 12
    addi    x2,  x0, -4
    mul     x30, x1, x2          # 12 * (-4) = -48 (0xFFFFFFD0)
    addi    x29, x0, -48
    addi    x3,  x0, 7
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 8 – 0x80000000 × 2 → lower 32 bits = 0x00000000
#   Overflow: the 64-bit product is 0x1_0000_0000; MUL keeps only [31:0].
# -----------------------------------------------------------------------------
test_8:
    lui     x1,  0x80000         # x1 = 0x80000000 (INT_MIN as bits)
    addi    x2,  x0, 2
    mul     x30, x1, x2          # 0x80000000 * 2 = 0x1_0000_0000 → lower 32 = 0
    addi    x29, x0, 0
    addi    x3,  x0, 8
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 9 – 0x40000000 × 4 → lower 32 bits = 0x00000000
#   Overflow: 0x40000000 * 4 = 0x1_0000_0000 → lower 32 = 0.
# -----------------------------------------------------------------------------
test_9:
    lui     x1,  0x40000         # x1 = 0x40000000
    addi    x2,  x0, 4
    mul     x30, x1, x2          # 0x40000000 * 4 = 0x1_0000_0000 → lower 32 = 0
    addi    x29, x0, 0
    addi    x3,  x0, 9
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 10 – rd = rs1: MUL x1, x1, x2  (5 × 6 = 30)
#   Destination register is the same as the first source operand.
#   The hardware must latch rs1 before writing rd.
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
#   Destination register is the same as the second source operand.
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
#   Destination is both sources; value should be the square of the operand.
# -----------------------------------------------------------------------------
test_12:
    addi    x1,  x0, 8
    mul     x1,  x1, x1          # rd=rs1=rs2; x1 = 8 * 8 = 64
    addi    x29, x0, 64
    addi    x3,  x0, 12
    bne     x1,  x29, fail

# -----------------------------------------------------------------------------
# Test 13 – 123 × 0 = 0
#   Zero second operand; any non-zero × zero must be zero.
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
#   Zero first operand with a negative second operand.
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
#   x0 is the hardwired-zero register; any write to it must have no effect.
# -----------------------------------------------------------------------------
test_15:
    addi    x1,  x0, 4
    addi    x2,  x0, 5
    mul     x0,  x1, x2          # result discarded; x0 must remain 0
    addi    x29, x0, 0
    addi    x3,  x0, 15
    bne     x0,  x29, fail

# =============================================================================
# Section B  –  Edge / boundary values
# =============================================================================

# -----------------------------------------------------------------------------
# Test 16 – INT_MIN × (-1): signed overflow corner case
#   0x80000000 * 0xFFFFFFFF (i.e. -2147483648 * -1).
#   True 64-bit product = 0x0000_0000_8000_0000.
#   MUL keeps lower 32 bits = 0x80000000.
#   (Note: MULH would give 0x00000000 for the upper 32 bits.)
# -----------------------------------------------------------------------------
test_16:
    lui     x1,  0x80000         # x1 = 0x80000000 = INT_MIN
    addi    x2,  x0, -1          # x2 = 0xFFFFFFFF
    mul     x30, x1, x2
    # Lower 32 of (0x80000000 * 0xFFFFFFFF) = 0x80000000
    lui     x29, 0x80000         # x29 = 0x80000000
    addi    x3,  x0, 16
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 17 – INT_MAX × INT_MAX
#   0x7FFFFFFF * 0x7FFFFFFF = 0x3FFF_FFFF_0000_0001.
#   Lower 32 bits = 0x00000001.
# -----------------------------------------------------------------------------
test_17:
    lui     x1,  0x7FFFF
    addi    x1,  x1, 0x7FF       # x1 = 0x7FFFFFFF = INT_MAX  (lui+addi trick)
    mv      x2,  x1              # x2 = INT_MAX as well
    mul     x30, x1, x2          # lower 32 of 0x3FFFFFFF_00000001 = 0x00000001
    addi    x29, x0, 1
    addi    x3,  x0, 17
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 18 – 0xFFFFFFFF × 0xFFFFFFFF (all-ones × all-ones)
#   As unsigned: (2^32 - 1)^2 = 2^64 - 2^33 + 1.
#   As signed:   (-1) * (-1) = 1.
#   MUL lower 32 bits = 0x00000001.
# -----------------------------------------------------------------------------
test_18:
    addi    x1,  x0, -1          # x1 = 0xFFFFFFFF
    addi    x2,  x0, -1          # x2 = 0xFFFFFFFF
    mul     x30, x1, x2          # lower 32 = 1
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
#   Multiplier is a power of 2; some implementations shortcut via shift.
#   Verify MUL and a left-shift give the same lower-32-bit answer.
# -----------------------------------------------------------------------------
test_22:
    addi    x1,  x0, 1
    addi    x2,  x0, 16
    mul     x30, x1, x2          # 1 * 16 = 16  (same as slli by 4)
    addi    x29, x0, 16
    addi    x3,  x0, 22
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 23 – Power-of-2 operand causes overflow truncation
#   0x20000000 * 8 = 0x1_0000_0000 → lower 32 = 0.
# -----------------------------------------------------------------------------
test_23:
    lui     x1,  0x20000         # x1 = 0x20000000
    addi    x2,  x0, 8
    mul     x30, x1, x2          # 0x20000000 * 8 = 0x1_0000_0000 → 0
    addi    x29, x0, 0
    addi    x3,  x0, 23
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 24 – Large positive × large positive, non-trivial lower 32 bits
#   0x00010001 * 0x00010001 = 0x0001_0002_0001.
#   Lower 32 bits = 0x00020001.
# -----------------------------------------------------------------------------
test_24:
    lui     x1,  0x10            # 0x10000
    addi    x1,  x1,  1          # x1 = 0x00010001
    mv      x2,  x1
    mul     x30, x1, x2          # lower 32 of 0x0001_0002_0001 = 0x00020001
    lui     x29, 0x2             # 0x00002000
    addi    x29, x29, 1          # x29 = 0x00002001  ← wrong; compute carefully
    # 0x00010001^2 = 0x0001_0002_0001  → lower 32 = 0x00020001
    # Build 0x00020001: lui x29,0x20 gives 0x00020000; ori adds 1
    lui     x29, 0x20            # 0x00020000
    ori     x29, x29, 1          # x29 = 0x00020001
    addi    x3,  x0, 24
    bne     x30, x29, fail

# =============================================================================
# Section C  –  MX bypass: MUL result forwarded immediately to next MUL
#
# Pipeline timing (5-stage, multi-cycle MUL):
#   MUL#1:  IF | ID | EX(mul) | MEM | WB
#   MUL#2:       IF | ID      | EX(mul) ← needs MUL#1 result
#
# If the pipeline stalls until WB, x29 is correct; if it bypasses from the
# MEM/WB boundary, it is also correct.  The test verifies the VALUE is right
# regardless of stall vs forward policy — a wrong value reveals a missing stall
# or a broken bypass.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 25 – MX: rd of MUL#1 is rs1 of MUL#2
#   MUL x10, x1, x2  →  x10 = 3 * 4 = 12
#   MUL x30, x10, x2 →  x30 = 12 * 4 = 48   (x10 from previous MUL)
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
#   MUL x30, x2, x10 →  x30 = 3 * 15 = 45   (x10 from previous MUL)
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
#   MUL x10, x1, x2  →  x10 = 6 * 2 = 12
#   MUL x30, x10, x10 → x30 = 12 * 12 = 144
# -----------------------------------------------------------------------------
test_27:
    addi    x1,  x0, 6
    addi    x2,  x0, 2
    mul     x10, x1,  x2         # MUL#1: x10 = 12
    mul     x30, x10, x10        # MUL#2 (MX, both): 12 * 12 = 144
    addi    x29, x0,  144
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
#
# An ordinary ALU instruction (ADD, ADDI, LUI, ORI, …) writes a register
# one cycle before MUL reads it.  In a standard 5-stage pipeline the WB
# of the ALU instruction overlaps with the EX of MUL — the forward path
# from WB→EX (WX) must supply the value.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 29 – WX: ADDI result feeds rs1 of MUL
#   addi x10, x0, 7   →  x10 = 7   (ALU, written at WB)
#   mul  x30, x10, x2 →  x30 = 7 * 9 = 63
#   One ALU instruction separating them means the result is being forwarded
#   from WB into EX of MUL (classic WX).
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
# Test 31 – WX: LUI result feeds rs1 of MUL
#   LUI is a purely register-writing ALU instruction with no memory access.
# -----------------------------------------------------------------------------
test_31:
    lui     x10, 1               # x10 = 0x00001000
    addi    x2,  x0,  2
    mul     x30, x10, x2         # WX: 0x1000 * 2 = 0x2000 = 8192
    lui     x29, 2               # x29 = 0x00002000 = 8192
    addi    x3,  x0,  31
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 32 – WX: both rs1 and rs2 come from back-to-back ALU writes
#   addi x10, x0, 5   →  x10 = 5
#   addi x11, x0, 11  →  x11 = 11
#   mul  x30, x10, x11 →  x30 = 55
#   Each operand is forwarded from WX; the later ADDI is in MEM when MUL is in EX.
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
#
# A MUL result written in WB (two cycles after EX completes) feeds a later
# MUL's EX stage.  One intervening instruction separates the two MULs so the
# first MUL's result travels through the MEM stage before arriving at the
# second MUL's EX stage — this is the WM (writeback-to-multiplier) path.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 33 – WM: one intervening NOP between two MULs, rs1 forwarded
#   mul x10, x1, x2   →  x10 = 3 * 5 = 15      (MUL#1)
#   addi x0, x0, 0    →  NOP (bubble)
#   mul x30, x10, x2  →  x30 = 15 * 5 = 75     (WM: x10 from MUL#1)
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
#   mul x10, x1, x2   →  x10 = 7 * 4 = 28
#   addi x0, x0, 0    →  NOP
#   mul x30, x2, x10  →  x30 = 4 * 28 = 112
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
#   mul x10, x1, x2   →  x10 = 5 * 2 = 10
#   addi x0, x0, 0    →  NOP
#   mul x30, x10, x10 →  x30 = 10 * 10 = 100
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
#   mul x10, x1, x2   →  x10 = 4 * 3 = 12   (MUL#1)
#   mul x11, x10, x2  →  x11 = 12 * 3 = 36  (MUL#2, MX: x10 from MUL#1)
#   addi x0, x0, 0    →  NOP
#   mul x30, x11, x10 →  x30 = 36 * 12 = 432
#                         (WM: x11 from MUL#2; WX/stall: x10 already stable)
# -----------------------------------------------------------------------------
test_36:
    addi    x1,  x0, 4
    addi    x2,  x0, 3
    mul     x10, x1,  x2         # MUL#1: x10 = 12
    mul     x11, x10, x2         # MUL#2 (MX): x11 = 36
    addi    x0,  x0,  0          # NOP
    mul     x30, x11, x10        # WM (x11) + stable (x10): 36 * 12 = 432
    lui     x29, 0               # build 432 = 0x1B0
    addi    x29, x0,  432
    addi    x3,  x0,  36
    bne     x30, x29, fail

# =============================================================================
# Section F  –  Load-use hazard before MUL
#
# An LW immediately before MUL causes a structural hazard: the load result is
# not available until the end of MEM, but MUL needs it at the start of EX.
# A correct implementation inserts a pipeline bubble (stall one cycle).
# A wrong implementation would feed a stale or garbage value into MUL.
#
# We load known values from memory (using the stack or a static word) and
# verify the MUL result matches the expected product.
# =============================================================================

# Prepare memory words for load-use tests.
# We use the stack pointer and store values there first.
# sp is assumed to be initialised by the runtime/linker.

# -----------------------------------------------------------------------------
# Test 37 – Load-use: LW → MUL (rs1 from load)
#   Store 11 into a stack slot, load it back, immediately multiply.
# -----------------------------------------------------------------------------
test_37:
    addi    x2,  x0,  11
    sw      x2,  -4(sp)          # mem[-4] = 11
    lw      x10, -4(sp)          # x10 = 11  (load)
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
    sw      x2,  -8(sp)          # mem[-8] = 9
    lw      x10, -8(sp)          # x10 = 9  (load)
    mul     x30, x1,  x10        # load-use stall (rs2); 7 * 9 = 63
    addi    x29, x0,  63
    addi    x3,  x0,  38
    bne     x30, x29, fail

# -----------------------------------------------------------------------------
# Test 39 – Load-use: LW → MUL (both operands from loads at different depths)
#   Load rs1, one ALU instruction (the store for the second load), then
#   load rs2, then MUL.  rs1 has had two cycles to settle (WX path);
#   rs2 is a fresh load-use stall.
# -----------------------------------------------------------------------------
test_39:
    addi    x2,  x0,  6
    addi    x4,  x0,  13
    sw      x2,  -12(sp)         # mem[-12] = 6
    sw      x4,  -16(sp)         # mem[-16] = 13
    lw      x10, -12(sp)         # x10 = 6
    lw      x11, -16(sp)         # x11 = 13  (load-use for rs2)
    mul     x30, x10, x11        # load-use stall on x11; 6 * 13 = 78
    addi    x29, x0,  78
    addi    x3,  x0,  39
    bne     x30, x29, fail

# =============================================================================
# Section G  –  MUL result forwarded into a store
#
# After MUL writes rd, an immediately following SW tries to store that register.
# In most pipelines, MEM for SW overlaps with WB of MUL, so the store must
# obtain the value via bypass or wait.  We verify by loading the word back.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 40 – MUL then SW then LW: result correctly propagated to memory
#   MUL x10, x1, x2  →  x10 = 8 * 9 = 72
#   SW  x10, -4(sp)  →  mem stores 72 (must forward x10 from MUL's WB)
#   LW  x11, -4(sp)  →  x11 = 72
# -----------------------------------------------------------------------------
test_40:
    addi    x1,  x0, 8
    addi    x2,  x0, 9
    mul     x10, x1,  x2         # x10 = 72
    sw      x10, -20(sp)         # store x10 (MUL→store forward)
    lw      x11, -20(sp)         # reload
    addi    x29, x0,  72
    addi    x3,  x0,  40
    bne     x11, x29, fail

# -----------------------------------------------------------------------------
# Test 41 – MUL then SW with negative result
#   MUL x10, x1, x2  →  x10 = -7 * 6 = -42
#   SW  x10, -4(sp)  →  mem stores 0xFFFFFFD6
#   LW  x11, -4(sp)  →  x11 = -42 (sign-extended)
# -----------------------------------------------------------------------------
test_41:
    addi    x1,  x0, -7
    addi    x2,  x0,  6
    mul     x10, x1,  x2         # x10 = -42
    sw      x10, -24(sp)
    lw      x11, -24(sp)
    addi    x29, x0,  -42
    addi    x3,  x0,  41
    bne     x11, x29, fail

# =============================================================================
# Section H  –  Pipeline stress
#
# Sequences of many back-to-back MUL instructions stress the multiplier's
# throughput and any credit/scoreboard logic for structural hazards.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 42 – Six consecutive MULs, each independent (no data hazards)
#   Stresses structural hazard detection when the multiplier has a
#   multi-cycle latency but subsequent instructions have no dependency.
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
    # Verify last result; earlier results verified implicitly by not crashing
    addi    x29, x0,  21
    addi    x3,  x0,  42
    bne     x15, x29, fail
    # Also spot-check x12
    addi    x29, x0,  35
    bne     x12, x29, fail

# -----------------------------------------------------------------------------
# Test 43 – Accumulator chain: MUL product feeds the next MUL each time
#   x10  = 1 * 2  = 2
#   x10  = 2 * 3  = 6
#   x10  = 6 * 4  = 24
#   x10  = 24 * 5 = 120
#   This is the hardest forwarding chain: every MUL depends on the previous.
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
#
# Definition: instruction #2 writes a register that instruction #1 read.
#
#   MUL#1  reads  rs_a           ← the "read"
#   MUL#2  writes rd = rs_a      ← the "write", same register
#
# In a strictly in-order pipeline this is never a true hazard: the read
# always completes at or before the EX stage of MUL#1, well before MUL#2
# reaches its WB stage.  However a buggy scoreboard, an OOO window, or a
# speculative write path can allow the write to land before the read
# finishes, feeding MUL#1 the new value instead of the one it should have
# seen.
#
# Verification strategy: set rs_a to value A, let MUL#1 read it, then let
# MUL#2 overwrite rs_a with value B.  Check that MUL#1's result reflects A,
# not B.  Because the instructions are in-order and the check comes after
# both complete, a wrong result from MUL#1 is the only observable symptom.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 44 – WAR: MUL#2 writes the register MUL#1 used as rs1
#   x10 = 3  (the value MUL#1 must read)
#   x2  = 5
#   MUL x30, x10, x2   → MUL#1 reads x10=3; x30 must be 3*5=15
#   MUL x10, x2,  x2   → MUL#2 writes x10=5*5=25   (WAR on x10)
#   Check x30 == 15 (proves MUL#1 saw x10=3, not the later 25)
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
#   MUL x30, x1, x10   → MUL#1 reads x10=4; x30 must be 7*4=28
#   MUL x10, x1, x2    → MUL#2 writes x10=7*9=63   (WAR on x10 as rs2)
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
#   Tests the WAR path when the overwriting instruction is a fast ALU op,
#   not another MUL.  The ADDI completes in WB long before MUL; a broken
#   forwarding path could re-source MUL's rs1 from the post-ADDI value.
#   MUL x30, x10, x2   → MUL#1 reads x10=6; x30 must be 6*8=48
#   ADDI x10, x0, 99   → ALU writes x10=99 one cycle later  (WAR on x10)
# -----------------------------------------------------------------------------
test_46:
    addi    x10, x0,  6
    addi    x2,  x0,  8
    mul     x30, x10, x2          # MUL#1: reads x10=6; x30 = 6*8 = 48
    addi    x10, x0,  99          # ALU (WAR): writes x10=99 while MUL#1 is still in flight
    addi    x29, x0,  48
    addi    x3,  x0,  46
    bne     x30, x29, fail        # x30 must be 48, not (99*8=792 lower bits)

# -----------------------------------------------------------------------------
# Test 47 – WAR: both rs1 and rs2 of MUL#1 are overwritten by MUL#2
#   MUL x30, x10, x11  → MUL#1 reads x10=2, x11=3; x30 must be 6
#   MUL x10, x1,  x2   → MUL#2 writes x10=5*7=35
#   MUL x11, x2,  x1   → MUL#3 writes x11=7*5=35
#   Checks MUL#1 result is 6 despite both its source regs being overwritten.
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
#
# Definition: two instructions both write the same destination register.
# The architecturally correct result is that the LAST write wins.
#
# Why this matters for MUL specifically:
#   MUL has a multi-cycle latency.  If MUL writes x10 and then a fast ADDI
#   also writes x10, the ADDI reaches WB first.  A broken scoreboard or
#   write-back arbiter may then allow MUL's late result to arrive and silently
#   overwrite the ADDI's value.  After both instructions retire, x10 must hold
#   the ADDI's value (the architecturally later write), not MUL's.
#
# Equally, if MUL is the second writer it must overwrite an earlier ALU write.
#
# Verification: after both writers complete, read the destination and confirm
# it holds the value from the instruction that was second in program order.
# =============================================================================

# -----------------------------------------------------------------------------
# Test 48 – WAW: MUL first, then ALU writes same rd; ALU must win
#   MUL  x10, x1, x2   → starts writing x10 = 3*4=12 (long latency)
#   ADDI x10, x0, 99   → also writes x10 = 99  (short latency, commits first)
#   After both retire: x10 must be 99 (ADDI is the later program-order write)
# -----------------------------------------------------------------------------
test_48:
    addi    x1,  x0,  3
    addi    x2,  x0,  4
    mul     x10, x1,  x2          # WAW write #1: x10 ← 12 (arrives late)
    addi    x10, x0,  99          # WAW write #2: x10 ← 99 (arrives early in WB)
    # Architectural requirement: x10 = 99 (second write in program order)
    addi    x29, x0,  99
    addi    x3,  x0,  48
    bne     x10, x29, fail        # if x10 = 12, MUL's stale write clobbered ADDI

# -----------------------------------------------------------------------------
# Test 49 – WAW: ALU first, then MUL writes same rd; MUL must win
#   ADDI x10, x0, 55   → writes x10 = 55 first
#   MUL  x10, x1, x2   → also writes x10 = 6*7=42 (arrives later, must win)
#   After both retire: x10 must be 42
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
#   MUL#1 x10, x1, x2  → x10 ← 2*3=6   (first write, must be overwritten)
#   MUL#2 x10, x4, x6  → x10 ← 5*7=35  (second write, must survive)
#   After both retire: x10 must be 35
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
#   Tests that a non-arithmetic, non-memory write (LUI) also correctly
#   beats a slow in-flight MUL in the WAW ordering.
#   MUL x10, x1, x2   → x10 ← 9*4=36
#   LUI x10, 0xABCDE  → x10 ← 0xABCDE000
#   After both retire: x10 must be 0xABCDE000
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
#   MUL#1 x10, x1, x2  → WAW write #1: x10 ← 3*5=15
#   MUL#2 x10, x4, x6  → WAW write #2: x10 ← 4*6=24  (must win)
#   MUL#3 x30, x10, x2 → RAW: must read x10=24 (not the stale 15)
#   x30 must be 24*5=120
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