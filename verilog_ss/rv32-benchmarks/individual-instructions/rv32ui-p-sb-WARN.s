# rv32ui-p-sb - Store Byte instruction tests
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST


.section .text.init
.globl _start

_start:
    # Test 2: sb with offset 0, store 0xaa (-86), verify with lb
    la      x1, tdat
    addi    x2, x0, -86     # 0xaa
    sb      x2, 0(x1)
    lb      x30, 0(x1)
    addi    x29, x0, -86
    addi    x3, x0, 2
    bne     x30, x29, fail

test_3:
    # Test 3: sb with offset 1, store 0x00, verify with lb
    la      x1, tdat
    addi    x2, x0, 0
    sb      x2, 1(x1)
    lb      x30, 1(x1)
    addi    x29, x0, 0
    addi    x3, x0, 3
    bne     x30, x29, fail

test_4:
    # Test 4: sb with offset 2, store 0xa0 (-96), verify with lh
    la      x1, tdat
    addi    x2, x0, -96     # 0xa0
    sb      x2, 2(x1)
    lh      x30, 2(x1)      # Should read halfword 0xefa0 (sign-extended to 0xffffefa0)
    lui     x29, 0xfffff
    addi    x29, x29, -96   # 0xffffefa0 = -4192
    addi    x3, x0, 4
    bne     x30, x29, fail

test_5:
    # Test 5: sb with offset 3, store 0x0a, verify with lb
    la      x1, tdat
    addi    x2, x0, 10      # 0x0a
    sb      x2, 3(x1)
    lb      x30, 3(x1)
    addi    x29, x0, 10
    addi    x3, x0, 5
    bne     x30, x29, fail

test_6:
    # Test 6: sb with negative offset, store at tdat+0
    la      x1, tdat
    addi    x1, x1, 3
    addi    x2, x0, -86     # 0xaa
    sb      x2, -3(x1)
    la      x1, tdat
    lb      x30, 0(x1)
    addi    x29, x0, -86
    addi    x3, x0, 6
    bne     x30, x29, fail

test_7:
    # Test 7: sb with negative offset, store at tdat+1
    la      x1, tdat
    addi    x1, x1, 3
    addi    x2, x0, 0
    sb      x2, -2(x1)
    la      x1, tdat
    lb      x30, 1(x1)
    addi    x29, x0, 0
    addi    x3, x0, 7
    bne     x30, x29, fail

test_8:
    # Test 8: sb with negative offset, store at tdat+2
    la      x1, tdat
    addi    x1, x1, 3
    addi    x2, x0, -96
    sb      x2, -1(x1)
    la      x1, tdat
    lb      x30, 2(x1)
    addi    x29, x0, -96
    addi    x3, x0, 8
    bne     x30, x29, fail

test_9:
    # Test 9: sb with offset 0 from tdat+3
    la      x1, tdat
    addi    x1, x1, 3
    addi    x2, x0, 10
    sb      x2, 0(x1)
    lb      x30, 0(x1)
    addi    x29, x0, 10
    addi    x3, x0, 9
    bne     x30, x29, fail

test_10:
    # Test 10: Test store and load with base calculation
    la      x1, tdat
    addi    x1, x1, -32
    addi    x2, x0, -86
    sb      x2, 32(x1)
    lb      x5, 32(x1)
    addi    x29, x0, -86
    addi    x3, x0, 10
    bne     x5, x29, fail

test_11:
    # Test 11: Test store and load with different base calculation
    la      x1, tdat
    addi    x1, x1, -5
    addi    x2, x0, 0
    sb      x2, 6(x1)
    lb      x5, 6(x1)
    addi    x29, x0, 0
    addi    x3, x0, 11
    bne     x5, x29, fail

test_12:
    # Test 12: Test bypassing - no delay between dependent instructions
    la      x4, tdat
    addi    x1, x0, -86
    sb      x1, 0(x4)
    lb      x14, 0(x4)
    addi    x29, x0, -86
    addi    x3, x0, 12
    bne     x14, x29, fail

test_13:
    # Test 13: Test bypassing with 1 nop
    la      x4, tdat
    addi    x1, x0, 10
    sb      x1, 1(x4)
    nop
    lb      x14, 1(x4)
    addi    x29, x0, 10
    addi    x3, x0, 13
    bne     x14, x29, fail

test_14:
    # Test 14: Test bypassing with 2 nops
    la      x4, tdat
    addi    x1, x0, -96
    sb      x1, 2(x4)
    nop
    nop
    lb      x14, 2(x4)
    addi    x29, x0, -96
    addi    x3, x0, 14
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
    .byte 0xef
tdat2:
    .byte 0xef
tdat3:
    .byte 0xef
tdat4:
    .byte 0xef
tdat5:
    .byte 0xef
tdat6:
    .byte 0xef
tdat7:
    .byte 0xef
tdat8:
    .byte 0xef
tdat9:
    .byte 0xef
tdat10:
    .byte 0xef
