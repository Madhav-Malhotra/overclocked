# rv32ui-p-lh - Load Halfword (signed) instruction tests
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST

.section .text.init
.globl _start

_start:
    # Test 2: lh with offset 0 - load 0x00ff, expect sign-extended 255
    la      x1, tdat
    lh      x30, 0(x1)
    addi    x29, x0, 255
    addi    x3, x0, 2
    bne     x30, x29, fail

test_3:
    # Test 3: lh with offset 2 - load 0xff00, expect sign-extended -256
    la      x1, tdat
    lh      x30, 2(x1)
    addi    x29, x0, -256
    addi    x3, x0, 3
    bne     x30, x29, fail

test_4:
    # Test 4: lh with offset 4 - load 0x0ff0, expect 4080
    la      x1, tdat
    lh      x30, 4(x1)
    lui     x29, 0x1
    addi    x29, x29, -16
    addi    x3, x0, 4
    bne     x30, x29, fail

test_5:
    # Test 5: lh with offset 6 - load 0xf00f, expect sign-extended -4081
    la      x1, tdat
    lh      x30, 6(x1)
    lui     x29, 0xfffff
    addi    x29, x29, 15
    addi    x3, x0, 5
    bne     x30, x29, fail

test_6:
    # Test 6: lh with negative offset -6 from tdat+6
    la      x1, tdat
    addi    x1, x1, 6
    lh      x30, -6(x1)
    addi    x29, x0, 255
    addi    x3, x0, 6
    bne     x30, x29, fail

test_7:
    # Test 7: lh with negative offset -4 from tdat+6
    la      x1, tdat
    addi    x1, x1, 6
    lh      x30, -4(x1)
    addi    x29, x0, -256
    addi    x3, x0, 7
    bne     x30, x29, fail

test_8:
    # Test 8: lh with negative offset -2 from tdat+6
    la      x1, tdat
    addi    x1, x1, 6
    lh      x30, -2(x1)
    lui     x29, 0x1
    addi    x29, x29, -16
    addi    x3, x0, 8
    bne     x30, x29, fail

test_9:
    # Test 9: lh with offset 0 from tdat+6
    la      x1, tdat
    addi    x1, x1, 6
    lh      x30, 0(x1)
    lui     x29, 0xfffff
    addi    x29, x29, 15
    addi    x3, x0, 9
    bne     x30, x29, fail

test_10:
    # Test 10: lh with base-offset calculation
    la      x1, tdat
    addi    x1, x1, -32
    lh      x5, 32(x1)
    addi    x29, x0, 255
    addi    x3, x0, 10
    bne     x5, x29, fail

test_11:
    # Test 11: lh with another base-offset
    la      x1, tdat
    addi    x1, x1, -6
    lh      x5, 8(x1)
    addi    x29, x0, -256
    addi    x3, x0, 11
    bne     x5, x29, fail

test_12:
    # Test 12: lh to x0 (should have no effect)
    la      x1, tdat
    lh      x0, 0(x1)
    addi    x29, x0, 0
    addi    x3, x0, 12
    bne     x0, x29, fail

test_13:
    # Test 13: Test bypassing with no delay
    la      x4, tdat
    lh      x14, 0(x4)
    addi    x7, x14, 0
    addi    x29, x0, 255
    addi    x3, x0, 13
    bne     x7, x29, fail

test_14:
    # Test 14: Test bypassing with 1 nop
    la      x4, tdat
    lh      x14, 2(x4)
    nop
    addi    x7, x14, 0
    addi    x29, x0, -256
    addi    x3, x0, 14
    bne     x7, x29, fail

test_15:
    # Test 15: Test bypassing with 2 nops
    la      x4, tdat
    lh      x14, 4(x4)
    nop
    nop
    addi    x7, x14, 0
    lui     x29, 0x1
    addi    x29, x29, -16
    addi    x3, x0, 15
    bne     x7, x29, fail

test_16:
    # Test 16: Test source/dest bypass
    la      x4, tdat
    lh      x1, 0(x4)
    addi    x29, x0, 255
    addi    x3, x0, 16
    bne     x1, x29, fail

test_17:
    # Test 17: Address calculation bypass
    la      x4, tdat
    addi    x1, x4, 2
    lh      x5, 0(x1)
    addi    x29, x0, -256
    addi    x3, x0, 17
    bne     x5, x29, fail

test_18:
    # Test 18: Address calculation with nop
    la      x4, tdat
    nop
    addi    x1, x4, 4
    lh      x5, 0(x1)
    lui     x29, 0x1
    addi    x29, x29, -16
    addi    x3, x0, 18
    bne     x5, x29, fail

test_19:
    # Test 19: Address calculation with 2 nops
    la      x4, tdat
    nop
    nop
    addi    x1, x4, 6
    lh      x5, 0(x1)
    lui     x29, 0xfffff
    addi    x29, x29, 15
    addi    x3, x0, 19
    bne     x5, x29, fail

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

# Data section with test values
.section .data
.align 4

tdat:
tdat1:
    .half 0x00ff
tdat2:
    .half 0xff00
tdat3:
    .half 0x0ff0
tdat4:
    .half 0xf00f
