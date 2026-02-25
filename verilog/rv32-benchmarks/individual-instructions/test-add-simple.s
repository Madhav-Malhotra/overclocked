# Simple ADD instruction test
# Tests the ADD instruction with various operands

.section .text.init
.globl _start

_start:
    # Test 1: 0 + 0 = 0
    addi    x1, x0, 0
    addi    x2, x0, 0
    add     x3, x1, x2
    addi    x4, x0, 0
    addi    x5, x0, 1           # Test number
    bne     x3, x4, fail

    # Test 2: 1 + 1 = 2
    addi    x1, x0, 1
    addi    x2, x0, 1
    add     x3, x1, x2
    addi    x4, x0, 2
    addi    x5, x0, 2           # Test number
    bne     x3, x4, fail

    # Test 3: 3 + 7 = 10
    addi    x1, x0, 3
    addi    x2, x0, 7
    add     x3, x1, x2
    addi    x4, x0, 10
    addi    x5, x0, 3           # Test number
    bne     x3, x4, fail

    # Test 4: Negative numbers (-1 + -1 = -2)
    addi    x1, x0, -1
    addi    x2, x0, -1
    add     x3, x1, x2
    addi    x4, x0, -2
    addi    x5, x0, 4           # Test number
    bne     x3, x4, fail

    # Test 5: Overflow (0x7FFFFFFF + 1 = 0x80000000)
    lui     x1, 0x80000
    addi    x1, x1, -1          # x1 = 0x7FFFFFFF
    addi    x2, x0, 1
    add     x3, x1, x2
    lui     x4, 0x80000         # x4 = 0x80000000
    addi    x5, x0, 5           # Test number
    bne     x3, x4, fail

    # All tests passed
    j       pass

fail:
    # x5 contains the failing test number
    fence   iorw, iorw
    la      t0, tohost
    sw      x5, 0(t0)
    ecall
    j       fail

pass:
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 1           # Exit code 1 = test passed
    sw      a0, 0(t0)
    ecall
    unimp
