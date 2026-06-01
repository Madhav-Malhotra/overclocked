# rv32ui-p-sh - Store Halfword instruction tests
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST


.section .text.init
.globl _start

_start:
    # Test 2: sh with offset 0, store 0x00aa, verify with lh
    la      x1, tdat
    lui     x2, 0x0
    addi    x2, x2, 0xaa
    sh      x2, 0(x1)
    lh      x30, 0(x1)
    addi    x29, x0, 0xaa
    addi    x3, x0, 2
    bne     x30, x29, fail

test_3:
    # Test 3: sh with offset 2, store 0xaa00, verify with lh (sign-extended to 0xffffaa00)
    la      x1, tdat
    lui     x2, 0xb
    addi    x2, x2, -1536   # 0xaa00
    sh      x2, 2(x1)
    lh      x30, 2(x1)      # Loads as signed, becomes 0xffffaa00
    lui     x29, 0xffffb
    addi    x29, x29, -1536 # 0xffffaa00 = -22016
    addi    x3, x0, 3
    bne     x30, x29, fail

test_4:
    # Test 4: sh with offset 4, store 0xbeef, verify with lh (sign-extended to 0xffffbeef)
    la      x1, tdat
    lui     x2, 0xc
    addi    x2, x2, -273    # 0xbeef
    sh      x2, 4(x1)
    lh      x30, 4(x1)      # Loads as signed, becomes 0xffffbeef
    lui     x29, 0xffffc
    addi    x29, x29, -273  # 0xffffbeef = -16657
    addi    x3, x0, 4
    bne     x30, x29, fail

test_5:
    # Test 5: sh with offset 6, store 0x0a00, verify with lh
    la      x1, tdat
    lui     x2, 0x1
    addi    x2, x2, -1536   # 0x0a00
    sh      x2, 6(x1)
    lh      x30, 6(x1)
    lui     x29, 0x1
    addi    x29, x29, -1536
    addi    x3, x0, 5
    bne     x30, x29, fail

test_6:
    # Test 6: sh with negative offset
    la      x1, tdat
    addi    x1, x1, 6
    lui     x2, 0x0
    addi    x2, x2, 0xaa
    sh      x2, -6(x1)
    la      x1, tdat
    lh      x30, 0(x1)
    addi    x29, x0, 0xaa
    addi    x3, x0, 6
    bne     x30, x29, fail

test_7:
    # Test 7: sh with negative offset
    la      x1, tdat
    addi    x1, x1, 6
    lui     x2, 0xb
    addi    x2, x2, -1536
    sh      x2, -4(x1)
    la      x1, tdat
    lh      x30, 2(x1)
    lui     x29, 0xffffb
    addi    x29, x29, -1536
    addi    x3, x0, 7
    bne     x30, x29, fail

test_8:
    # Test 8: sh with negative offset
    la      x1, tdat
    addi    x1, x1, 6
    lui     x2, 0xc
    addi    x2, x2, -273
    sh      x2, -2(x1)
    la      x1, tdat
    lh      x30, 4(x1)
    lui     x29, 0xffffc
    addi    x29, x29, -273
    addi    x3, x0, 8
    bne     x30, x29, fail

test_9:
    # Test 9: sh with offset 0
    la      x1, tdat
    addi    x1, x1, 6
    lui     x2, 0x1
    addi    x2, x2, -1536
    sh      x2, 0(x1)
    lh      x30, 0(x1)
    lui     x29, 0x1
    addi    x29, x29, -1536
    addi    x3, x0, 9
    bne     x30, x29, fail

test_10:
    # Test 10: Test store and load with base calculation
    la      x1, tdat
    addi    x1, x1, -32
    lui     x2, 0x0
    addi    x2, x2, 0xaa
    sh      x2, 32(x1)
    lh      x5, 32(x1)
    addi    x29, x0, 0xaa
    addi    x3, x0, 10
    bne     x5, x29, fail

test_11:
    # Test 11: Test bypassing - no delay
    la      x4, tdat
    lui     x1, 0xb
    addi    x1, x1, -1536
    sh      x1, 0(x4)
    lh      x14, 0(x4)
    lui     x29, 0xffffb
    addi    x29, x29, -1536
    addi    x3, x0, 11
    bne     x14, x29, fail

test_12:
    # Test 12: Test bypassing with 1 nop
    la      x4, tdat
    lui     x1, 0xc
    addi    x1, x1, -273
    sh      x1, 2(x4)
    nop
    lh      x14, 2(x4)
    lui     x29, 0xffffc
    addi    x29, x29, -273
    addi    x3, x0, 12
    bne     x14, x29, fail

test_13:
    # Test 13: Test bypassing with 2 nops
    la      x4, tdat
    lui     x1, 0x1
    addi    x1, x1, -1536
    sh      x1, 4(x4)
    nop
    nop
    lh      x14, 4(x4)
    lui     x29, 0x1
    addi    x29, x29, -1536
    addi    x3, x0, 13
    bne     x14, x29, fail

    # All tests passed
    j       pass

fail:
    # Test failed - x3 contains the test number
    fence   iorw, iorw
    beq     x3, x0, fail_skip
    slli    x3, x3, 1
    ori     x3, x3, 1
fail_skip:
    la      t0, tohost
    sw      x3, 0(t0)
    ecall
    j       fail

pass:
    # All tests passed
    fence   iorw, iorw
    addi    x3, x0, 1
    la      t0, tohost
    sw      x3, 0(t0)
    ecall
    unimp

# Data section - scratch space for stores
.section .data
.align 4

tdat:
tdat1:
    .half 0xbeef
tdat2:
    .half 0xbeef
tdat3:
    .half 0xbeef
tdat4:
    .half 0xbeef
tdat5:
    .half 0xbeef
tdat6:
    .half 0xbeef
