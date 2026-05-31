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
# RAW hazard: immediate consumer
# ------------------------------------------------------------

test_9:
    addi    x1,x0,40
    addi    x2,x0,5

    div     x5,x1,x2
    addi    x6,x5,1

    addi    x29,x0,9
    addi    x3,x0,9
    bne     x6,x29,fail

# ------------------------------------------------------------
# RAW hazard: branch consumes DIV result
# ------------------------------------------------------------

test_10:
    addi    x1,x0,36
    addi    x2,x0,6

    div     x5,x1,x2

    addi    x29,x0,6
    addi    x3,x0,10
    bne     x5,x29,fail

# ------------------------------------------------------------
# Self dependency: rd == rs1
# ------------------------------------------------------------

test_11:
    addi    x1,x0,100
    addi    x2,x0,10

    div     x1,x1,x2

    addi    x29,x0,10
    addi    x3,x0,11
    bne     x1,x29,fail

# ------------------------------------------------------------
# Self dependency: rd == rs2
# ------------------------------------------------------------

test_12:
    addi    x1,x0,100
    addi    x2,x0,10

    div     x2,x1,x2

    addi    x29,x0,10
    addi    x3,x0,12
    bne     x2,x29,fail

# ------------------------------------------------------------
# Forwarding into DIV rs1
# ------------------------------------------------------------

test_13:
    addi    x1,x0,20
    addi    x2,x0,4

    addi    x1,x1,20
    div     x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,13
    bne     x5,x29,fail

# ------------------------------------------------------------
# Forwarding into DIV rs2
# ------------------------------------------------------------

test_14:
    addi    x1,x0,90
    addi    x2,x0,3

    addi    x2,x2,6
    div     x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,14
    bne     x5,x29,fail

# ------------------------------------------------------------
# Forwarding into both DIV operands
# ------------------------------------------------------------

test_15:
    addi    x1,x0,60
    addi    x2,x0,3

    addi    x1,x1,30
    addi    x2,x2,6

    div     x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,15
    bne     x5,x29,fail

# ------------------------------------------------------------
# DIV result feeds another DIV
# ------------------------------------------------------------

test_16:
    addi    x1,x0,100
    addi    x2,x0,10

    div     x5,x1,x2
    div     x6,x5,x2

    addi    x29,x0,1
    addi    x3,x0,16
    bne     x6,x29,fail

# ------------------------------------------------------------
# Long dependency chain
# ------------------------------------------------------------

test_17:
    addi    x1,x0,128
    addi    x2,x0,2

    div     x5,x1,x2      # 64
    div     x5,x5,x2      # 32
    div     x5,x5,x2      # 16
    div     x5,x5,x2      # 8

    addi    x29,x0,8
    addi    x3,x0,17
    bne     x5,x29,fail

# ------------------------------------------------------------
# Multiple independent DIVs back-to-back
# ------------------------------------------------------------

test_18:
    addi    x1,x0,90
    addi    x2,x0,9

    div     x5,x1,x2
    div     x6,x1,x2
    div     x7,x1,x2

    addi    x29,x0,10
    addi    x3,x0,18

    bne     x5,x29,fail
    bne     x6,x29,fail
    bne     x7,x29,fail

# ------------------------------------------------------------
# x0 destination test
# ------------------------------------------------------------

test_19:
    addi    x1,x0,50
    addi    x2,x0,5

    div     x0,x1,x2

    addi    x29,x0,0
    addi    x3,x0,19
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