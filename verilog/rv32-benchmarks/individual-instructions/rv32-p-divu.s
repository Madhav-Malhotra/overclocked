.section .text.init
.globl _start

_start:

# ------------------------------------------------------------
# Basic DIVU tests
# ------------------------------------------------------------

test_1:
    addi    x1,x0,20
    addi    x2,x0,5
    divu    x30,x1,x2
    addi    x29,x0,4
    addi    x3,x0,1
    bne     x30,x29,fail

test_2:
    addi    x1,x0,15
    addi    x2,x0,4
    divu    x30,x1,x2
    addi    x29,x0,3
    addi    x3,x0,2
    bne     x30,x29,fail

test_3:
    addi    x1,x0,100
    addi    x2,x0,10
    divu    x30,x1,x2
    addi    x29,x0,10
    addi    x3,x0,3
    bne     x30,x29,fail

# ------------------------------------------------------------
# Large unsigned values
# ------------------------------------------------------------

test_4:
    addi    x1,x0,-1
    addi    x2,x0,2

    divu    x30,x1,x2

    lui     x29,0x80000
    addi    x29,x29,-1

    addi    x3,x0,4
    bne     x30,x29,fail

test_5:
    addi    x1,x0,-1
    addi    x2,x0,-1

    divu    x30,x1,x2

    addi    x29,x0,1

    addi    x3,x0,5
    bne     x30,x29,fail

# ------------------------------------------------------------
# Division by zero
# Spec: result = 0xFFFFFFFF
# ------------------------------------------------------------

test_6:
    addi    x1,x0,15
    addi    x2,x0,0

    divu    x30,x1,x2

    addi    x29,x0,-1

    addi    x3,x0,6
    bne     x30,x29,fail

# ------------------------------------------------------------
# Forwarding / dependency tests
# ------------------------------------------------------------

test_7:
    addi    x1,x0,81
    addi    x2,x0,9

    divu    x5,x1,x2
    addi    x6,x5,0

    addi    x29,x0,9
    addi    x3,x0,7
    bne     x6,x29,fail

test_8:
    addi    x1,x0,64
    addi    x2,x0,8

    divu    x1,x1,x2

    addi    x29,x0,8
    addi    x3,x0,8
    bne     x1,x29,fail

# ------------------------------------------------------------
# x0 destination test
# ------------------------------------------------------------

test_9:
    addi    x1,x0,50
    addi    x2,x0,5

    divu    x0,x1,x2

    addi    x29,x0,0
    addi    x3,x0,9
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