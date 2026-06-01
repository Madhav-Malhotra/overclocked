# rv32ui-p-lw - Load Word instruction tests
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST


.section .text.init
.globl _start

_start:
    # Test 2: lw with offset 0 - load 0x00ff00ff
    la      x1, tdat
    lw      x30, 0(x1)
    lui     x29, 0x00ff0
    addi    x29, x29, 255
    addi    x3, x0, 2
    bne     x30, x29, fail

test_3:
    # Test 3: lw with offset 4 - load 0xff00ff00
    la      x1, tdat
    lw      x30, 4(x1)
    lui     x29, 0xff010
    addi    x29, x29, -256
    addi    x3, x0, 3
    bne     x30, x29, fail

test_4:
    # Test 4: lw with offset 8 - load 0x0ff00ff0
    la      x1, tdat
    lw      x30, 8(x1)
    lui     x29, 0x0ff01
    addi    x29, x29, -16
    addi    x3, x0, 4
    bne     x30, x29, fail

test_5:
    # Test 5: lw with offset 12 - load 0xf00ff00f
    la      x1, tdat
    lw      x30, 12(x1)
    lui     x29, 0xf00ff
    addi    x29, x29, 15
    addi    x3, x0, 5
    bne     x30, x29, fail

test_6:
    # Test 6: lw with negative offset -12 from tdat+12
    la      x1, tdat
    addi    x1, x1, 12
    lw      x30, -12(x1)
    lui     x29, 0x00ff0
    addi    x29, x29, 255
    addi    x3, x0, 6
    bne     x30, x29, fail

test_7:
    # Test 7: lw with negative offset -8 from tdat+12
    la      x1, tdat
    addi    x1, x1, 12
    lw      x30, -8(x1)
    lui     x29, 0xff010
    addi    x29, x29, -256
    addi    x3, x0, 7
    bne     x30, x29, fail

test_8:
    # Test 8: lw with negative offset -4 from tdat+12
    la      x1, tdat
    addi    x1, x1, 12
    lw      x30, -4(x1)
    lui     x29, 0x0ff01
    addi    x29, x29, -16
    addi    x3, x0, 8
    bne     x30, x29, fail

test_9:
    # Test 9: lw with offset 0 from tdat+12
    la      x1, tdat
    addi    x1, x1, 12
    lw      x30, 0(x1)
    lui     x29, 0xf00ff
    addi    x29, x29, 15
    addi    x3, x0, 9
    bne     x30, x29, fail

test_10:
    # Test 10: lw with base-offset calculation
    la      x1, tdat
    addi    x1, x1, -32
    lw      x5, 32(x1)
    lui     x29, 0x00ff0
    addi    x29, x29, 255
    addi    x3, x0, 10
    bne     x5, x29, fail

test_11:
    # Test 11: lw with another base-offset
    la      x1, tdat
    addi    x1, x1, -6
    lw      x5, 10(x1)
    lui     x29, 0xff010
    addi    x29, x29, -256
    addi    x3, x0, 11
    bne     x5, x29, fail

test_12:
    # Test 12: lw to x0 (should have no effect)
    la      x1, tdat
    lw      x0, 0(x1)
    addi    x29, x0, 0
    addi    x3, x0, 12
    bne     x0, x29, fail

test_13:
    # Test 13: Test bypassing with no delay
    la      x4, tdat
    lw      x14, 0(x4)
    addi    x7, x14, 0
    lui     x29, 0x00ff0
    addi    x29, x29, 255
    addi    x3, x0, 13
    bne     x7, x29, fail

test_14:
    # Test 14: Test bypassing with 1 nop
    la      x4, tdat
    lw      x14, 4(x4)
    nop
    addi    x7, x14, 0
    lui     x29, 0xff010
    addi    x29, x29, -256
    addi    x3, x0, 14
    bne     x7, x29, fail

test_15:
    # Test 15: Test bypassing with 2 nops
    la      x4, tdat
    lw      x14, 8(x4)
    nop
    nop
    addi    x7, x14, 0
    lui     x29, 0x0ff01
    addi    x29, x29, -16
    addi    x3, x0, 15
    bne     x7, x29, fail

test_16:
    # Test 16: Test source/dest bypass
    la      x4, tdat
    lw      x1, 0(x4)
    lui     x29, 0x00ff0
    addi    x29, x29, 255
    addi    x3, x0, 16
    bne     x1, x29, fail

test_17:
    # Test 17: Address calculation bypass
    la      x4, tdat
    addi    x1, x4, 4
    lw      x5, 0(x1)
    lui     x29, 0xff010
    addi    x29, x29, -256
    addi    x3, x0, 17
    bne     x5, x29, fail

test_18:
    # Test 18: Address calculation with nop
    la      x4, tdat
    nop
    addi    x1, x4, 8
    lw      x5, 0(x1)
    lui     x29, 0x0ff01
    addi    x29, x29, -16
    addi    x3, x0, 18
    bne     x5, x29, fail

test_19:
    # Test 19: Address calculation with 2 nops
    la      x4, tdat
    nop
    nop
    addi    x1, x4, 12
    lw      x5, 0(x1)
    lui     x29, 0xf00ff
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
    .word 0x00ff00ff
tdat2:
    .word 0xff00ff00
tdat3:
    .word 0x0ff00ff0
tdat4:
    .word 0xf00ff00f
