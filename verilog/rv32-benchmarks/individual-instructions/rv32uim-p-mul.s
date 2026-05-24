.section .text.init
.globl _start

_start:

# -------------------------------------------------
# Basic multiplication tests for RV32M MUL
# MUL returns lower 32 bits of signed multiply
# -------------------------------------------------

test_1:
    addi    x1,x0,0
    addi    x2,x0,0
    mul     x30,x1,x2
    addi    x29,x0,0
    addi    x3,x0,1
    bne     x30,x29,fail

test_2:
    addi    x1,x0,1
    addi    x2,x0,1
    mul     x30,x1,x2
    addi    x29,x0,1
    addi    x3,x0,2
    bne     x30,x29,fail

test_3:
    addi    x1,x0,3
    addi    x2,x0,7
    mul     x30,x1,x2
    addi    x29,x0,21
    addi    x3,x0,3
    bne     x30,x29,fail

test_4:
    addi    x1,x0,-1
    addi    x2,x0,1
    mul     x30,x1,x2
    addi    x29,x0,-1
    addi    x3,x0,4
    bne     x30,x29,fail

test_5:
    addi    x1,x0,-1
    addi    x2,x0,-1
    mul     x30,x1,x2
    addi    x29,x0,1
    addi    x3,x0,5
    bne     x30,x29,fail

test_6:
    addi    x1,x0,-5
    addi    x2,x0,6
    mul     x30,x1,x2
    addi    x29,x0,-30
    addi    x3,x0,6
    bne     x30,x29,fail

test_7:
    addi    x1,x0,12
    addi    x2,x0,-4
    mul     x30,x1,x2
    addi    x29,x0,-48
    addi    x3,x0,7
    bne     x30,x29,fail

# -------------------------------------------------
# Overflow behavior
# Only lower 32 bits should remain
# -------------------------------------------------

test_8:
    lui     x1,0x80000      # 0x80000000
    addi    x2,x0,2
    mul     x30,x1,x2

    # Expected lower 32 bits = 0x00000000
    addi    x29,x0,0
    addi    x3,x0,8
    bne     x30,x29,fail

test_9:
    lui     x1,0x40000      # 0x40000000
    addi    x2,x0,4
    mul     x30,x1,x2

    # 0x40000000 * 4 = 0x100000000
    # lower 32 bits = 0
    addi    x29,x0,0
    addi    x3,x0,9
    bne     x30,x29,fail

# -------------------------------------------------
# Destination equals source tests
# -------------------------------------------------

test_10:
    addi    x1,x0,5
    addi    x2,x0,6
    mul     x1,x1,x2
    addi    x29,x0,30
    addi    x3,x0,10
    bne     x1,x29,fail

test_11:
    addi    x1,x0,9
    addi    x2,x0,7
    mul     x2,x1,x2
    addi    x29,x0,63
    addi    x3,x0,11
    bne     x2,x29,fail

test_12:
    addi    x1,x0,8
    mul     x1,x1,x1
    addi    x29,x0,64
    addi    x3,x0,12
    bne     x1,x29,fail

# -------------------------------------------------
# Multiply by zero
# -------------------------------------------------

test_13:
    addi    x1,x0,123
    addi    x2,x0,0
    mul     x30,x1,x2
    addi    x29,x0,0
    addi    x3,x0,13
    bne     x30,x29,fail

test_14:
    addi    x1,x0,0
    addi    x2,x0,-55
    mul     x30,x1,x2
    addi    x29,x0,0
    addi    x3,x0,14
    bne     x30,x29,fail

# -------------------------------------------------
# x0 write test
# -------------------------------------------------

test_15:
    addi    x1,x0,4
    addi    x2,x0,5
    mul     x0,x1,x2
    addi    x29,x0,0
    addi    x3,x0,15
    bne     x0,x29,fail

# -------------------------------------------------
# PASS
# -------------------------------------------------

pass:
    fence   iorw,iorw
    addi    x3,x0,1

    la      t0,tohost
    sw      x3,0(t0)

    ecall
    unimp

# -------------------------------------------------
# FAIL
# -------------------------------------------------

fail:
    fence   iorw,iorw

    beq     x3,x0,fail+0x4

    slli    x3,x3,1
    ori     x3,x3,1

    la      t0,tohost
    sw      x3,0(t0)

    ecall