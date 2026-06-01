# rv32ui-p-lb - Load Byte (signed) instruction tests
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST

.section .text.init
.globl _start

_start:
    # Test 2: lb with offset 0 - load 0xff, expect sign-extended -1
    la      x1, tdat
    lb      x30, 0(x1)
    addi    x29, x0, -1
    addi    x3, x0, 2
    bne     x30, x29, fail

test_3:
    # Test 3: lb with offset 1 - load 0x00, expect 0
    la      x1, tdat
    lb      x30, 1(x1)
    addi    x29, x0, 0
    addi    x3, x0, 3
    bne     x30, x29, fail

test_4:
    # Test 4: lb with offset 2 - load 0xf0, expect sign-extended -16
    la      x1, tdat
    lb      x30, 2(x1)
    addi    x29, x0, -16
    addi    x3, x0, 4
    bne     x30, x29, fail

test_5:
    # Test 5: lb with offset 3 - load 0x0f, expect 15
    la      x1, tdat
    lb      x30, 3(x1)
    addi    x29, x0, 15
    addi    x3, x0, 5
    bne     x30, x29, fail

test_6:
    # Test 6: lb with negative offset -3 from tdat+3
    la      x1, tdat
    addi    x1, x1, 3
    lb      x30, -3(x1)
    addi    x29, x0, -1
    addi    x3, x0, 6
    bne     x30, x29, fail

test_7:
    # Test 7: lb with negative offset -2 from tdat+3
    la      x1, tdat
    addi    x1, x1, 3
    lb      x30, -2(x1)
    addi    x29, x0, 0
    addi    x3, x0, 7
    bne     x30, x29, fail

test_8:
    # Test 8: lb with negative offset -1 from tdat+3
    la      x1, tdat
    addi    x1, x1, 3
    lb      x30, -1(x1)
    addi    x29, x0, -16
    addi    x3, x0, 8
    bne     x30, x29, fail

test_9:
    # Test 9: lb with offset 0 from tdat+3
    la      x1, tdat
    addi    x1, x1, 3
    lb      x30, 0(x1)
    addi    x29, x0, 15
    addi    x3, x0, 9
    bne     x30, x29, fail

test_10:
    # Test 10: lb with base-offset calculation
    la      x1, tdat
    addi    x1, x1, -32
    lb      x5, 32(x1)
    addi    x29, x0, -1
    addi    x3, x0, 10
    bne     x5, x29, fail

test_11:
    # Test 11: lb with another base-offset
    la      x1, tdat
    addi    x1, x1, -6
    lb      x5, 7(x1)
    addi    x29, x0, 0
    addi    x3, x0, 11
    bne     x5, x29, fail

test_12:
    # Test 12: lb to x0 (should have no effect)
    la      x1, tdat
    lb      x0, 0(x1)
    addi    x29, x0, 0
    addi    x3, x0, 12
    bne     x0, x29, fail

test_13:
    # Test 13: Test bypassing with no delay
    la      x4, tdat
    lb      x14, 0(x4)
    addi    x7, x14, 0
    addi    x29, x0, -1
    addi    x3, x0, 13
    bne     x7, x29, fail

test_14:
    # Test 14: Test bypassing with 1 nop
    la      x4, tdat
    lb      x14, 1(x4)
    nop
    addi    x7, x14, 0
    addi    x29, x0, 0
    addi    x3, x0, 14
    bne     x7, x29, fail

test_15:
    # Test 15: Test bypassing with 2 nops
    la      x4, tdat
    lb      x14, 2(x4)
    nop
    nop
    addi    x7, x14, 0
    addi    x29, x0, -16
    addi    x3, x0, 15
    bne     x7, x29, fail

test_16:
    # Test 16: Test source/dest bypass
    la      x4, tdat
    lb      x1, 0(x4)
    addi    x29, x0, -1
    addi    x3, x0, 16
    bne     x1, x29, fail

test_17:
    # Test 17: Address calculation bypass
    la      x4, tdat
    addi    x1, x4, 1
    lb      x5, 0(x1)
    addi    x29, x0, 0
    addi    x3, x0, 17
    bne     x5, x29, fail

test_18:
    # Test 18: Address calculation with nop
    la      x4, tdat
    nop
    addi    x1, x4, 2
    lb      x5, 0(x1)
    addi    x29, x0, -16
    addi    x3, x0, 18
    bne     x5, x29, fail

test_19:
    # Test 19: Address calculation with 2 nops
    la      x4, tdat
    nop
    nop
    addi    x1, x4, 3
    lb      x5, 0(x1)
    addi    x29, x0, 15
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
    .byte 0xff
tdat2:
    .byte 0x00
tdat3:
    .byte 0xf0
tdat4:
    .byte 0x0f
