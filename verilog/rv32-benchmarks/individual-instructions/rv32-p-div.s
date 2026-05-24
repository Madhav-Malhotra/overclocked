.section .text.init
.globl _start

_start:

# ------------------------------------------------------------
# Basic signed DIV tests
# ------------------------------------------------------------

test_1:
    addi    x1,x0,10
    addi    x2,x0,2
    div     x30,x1,x2
    addi    x29,x0,5
    addi    x3,x0,1
    bne     x30,x29,fail

test_2:
    addi    x1,x0,7
    addi    x2,x0,2
    div     x30,x1,x2
    addi    x29,x0,3
    addi    x3,x0,2
    bne     x30,x29,fail

# ------------------------------------------------------------
# Negative operand tests
# ------------------------------------------------------------

test_3:
    addi    x1,x0,-10
    addi    x2,x0,2
    div     x30,x1,x2
    addi    x29,x0,-5
    addi    x3,x0,3
    bne     x30,x29,fail

test_4:
    addi    x1,x0,10
    addi    x2,x0,-2
    div     x30,x1,x2
    addi    x29,x0,-5
    addi    x3,x0,4
    bne     x30,x29,fail

test_5:
    addi    x1,x0,-10
    addi    x2,x0,-2
    div     x30,x1,x2
    addi    x29,x0,5
    addi    x3,x0,5
    bne     x30,x29,fail

test_6:
    addi    x1,x0,-7
    addi    x2,x0,2
    div     x30,x1,x2
    addi    x29,x0,-3
    addi    x3,x0,6
    bne     x30,x29,fail

# ------------------------------------------------------------
# Division by zero
# Spec: result = -1
# ------------------------------------------------------------

test_7:
    addi    x1,x0,15
    addi    x2,x0,0
    div     x30,x1,x2
    addi    x29,x0,-1
    addi    x3,x0,7
    bne     x30,x29,fail

# ------------------------------------------------------------
# INT_MIN / -1 overflow case
# Spec: result = INT_MIN
# ------------------------------------------------------------

test_8:
    lui     x1,0x80000
    addi    x2,x0,-1

    div     x30,x1,x2

    lui     x29,0x80000

    addi    x3,x0,8
    bne     x30,x29,fail

# ------------------------------------------------------------
# Forwarding / dependency tests
# ------------------------------------------------------------

test_9:
    addi    x1,x0,40
    addi    x2,x0,5

    div     x5,x1,x2
    addi    x6,x5,0

    addi    x29,x0,8
    addi    x3,x0,9
    bne     x6,x29,fail

test_10:
    addi    x1,x0,100
    addi    x2,x0,10

    div     x1,x1,x2

    addi    x29,x0,10
    addi    x3,x0,10
    bne     x1,x29,fail

# ------------------------------------------------------------
# x0 destination test
# ------------------------------------------------------------

test_11:
    addi    x1,x0,50
    addi    x2,x0,5

    div     x0,x1,x2

    addi    x29,x0,0
    addi    x3,x0,11
    bne     x0,x29,fail

    bne     x0,x3,pass

fail:
    fence   iorw,iorw
    beq     x3,x0,fail+0x4
    slli    x3,x3,0x1
    ori     x3,x3,1

    la      t0,tohost
    sw      x3,0(t0)

    ecall

pass:
    fence   iorw,iorw
    addi    x3,x0,1

    la      t0,tohost
    sw      x3,0(t0)

    ecall
    unimp

.section .text.init

end_signature: