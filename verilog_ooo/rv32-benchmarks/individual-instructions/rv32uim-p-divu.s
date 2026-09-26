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
# Unsigned interpretation checks
# ------------------------------------------------------------

test_6:
    addi    x1,x0,-2          # 0xFFFFFFFE
    addi    x2,x0,2

    divu    x30,x1,x2

    lui     x29,0x7ffff
    addi    x29,x29,-1        # 0x7FFFFFFF

    addi    x3,x0,6
    bne     x30,x29,fail

# ------------------------------------------------------------
# Division by zero
# Spec: result = 0xFFFFFFFF
# ------------------------------------------------------------

test_7:
    addi    x1,x0,15
    addi    x2,x0,0

    divu    x30,x1,x2

    addi    x29,x0,-1

    addi    x3,x0,7
    bne     x30,x29,fail

# ------------------------------------------------------------
# RAW hazard: immediate consumer
# ------------------------------------------------------------

test_8:
    addi    x1,x0,81
    addi    x2,x0,9

    divu    x5,x1,x2
    addi    x6,x5,1

    addi    x29,x0,10
    addi    x3,x0,8
    bne     x6,x29,fail

# ------------------------------------------------------------
# RAW hazard: branch consumes DIVU result
# ------------------------------------------------------------

test_9:
    addi    x1,x0,36
    addi    x2,x0,6

    divu    x5,x1,x2

    addi    x29,x0,6
    addi    x3,x0,9
    bne     x5,x29,fail

# ------------------------------------------------------------
# Self dependency: rd == rs1
# ------------------------------------------------------------

test_10:
    addi    x1,x0,64
    addi    x2,x0,8

    divu    x1,x1,x2

    addi    x29,x0,8
    addi    x3,x0,10
    bne     x1,x29,fail

# ------------------------------------------------------------
# Self dependency: rd == rs2
# ------------------------------------------------------------

test_11:
    addi    x1,x0,64
    addi    x2,x0,8

    divu    x2,x1,x2

    addi    x29,x0,8
    addi    x3,x0,11
    bne     x2,x29,fail

# ------------------------------------------------------------
# Forwarding into DIVU rs1
# ------------------------------------------------------------

test_12:
    addi    x1,x0,20
    addi    x2,x0,4

    addi    x1,x1,20
    divu    x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,12
    bne     x5,x29,fail

# ------------------------------------------------------------
# Forwarding into DIVU rs2
# ------------------------------------------------------------

test_13:
    addi    x1,x0,90
    addi    x2,x0,3

    addi    x2,x2,6
    divu    x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,13
    bne     x5,x29,fail

# ------------------------------------------------------------
# Forwarding into both DIVU operands
# ------------------------------------------------------------

test_14:
    addi    x1,x0,60
    addi    x2,x0,3

    addi    x1,x1,30
    addi    x2,x2,6

    divu    x5,x1,x2

    addi    x29,x0,10
    addi    x3,x0,14
    bne     x5,x29,fail

# ------------------------------------------------------------
# DIVU result feeds another DIVU
# ------------------------------------------------------------

test_15:
    addi    x1,x0,100
    addi    x2,x0,10

    divu    x5,x1,x2
    divu    x6,x5,x2

    addi    x29,x0,1
    addi    x3,x0,15
    bne     x6,x29,fail

# ------------------------------------------------------------
# Long dependency chain
# ------------------------------------------------------------

test_16:
    addi    x1,x0,128
    addi    x2,x0,2

    divu    x5,x1,x2      # 64
    divu    x5,x5,x2      # 32
    divu    x5,x5,x2      # 16
    divu    x5,x5,x2      # 8

    addi    x29,x0,8
    addi    x3,x0,16
    bne     x5,x29,fail

# ------------------------------------------------------------
# Multiple independent DIVUs back-to-back
# ------------------------------------------------------------

test_17:
    addi    x1,x0,90
    addi    x2,x0,9

    divu    x5,x1,x2
    divu    x6,x1,x2
    divu    x7,x1,x2

    addi    x29,x0,10
    addi    x3,x0,17

    bne     x5,x29,fail
    bne     x6,x29,fail
    bne     x7,x29,fail

# ------------------------------------------------------------
# WAW: DIVU then ADDI write same register
# Younger write must win
# ------------------------------------------------------------

test_18:
    addi    x1,x0,100
    addi    x2,x0,10

    divu    x5,x1,x2      # 10
    addi    x5,x0,99      # younger write

    addi    x29,x0,99
    addi    x3,x0,18
    bne     x5,x29,fail

# ------------------------------------------------------------
# WAW: two DIVUs write same destination
# Younger write must win
# ------------------------------------------------------------

test_19:
    addi    x1,x0,100
    addi    x2,x0,10
    addi    x4,x0,2

    divu    x5,x1,x2      # 10
    divu    x5,x1,x4      # 50

    addi    x29,x0,50
    addi    x3,x0,19
    bne     x5,x29,fail

# ------------------------------------------------------------
# WAR: older DIVU must read x1 before younger write
# ------------------------------------------------------------

test_20:
    addi    x1,x0,100
    addi    x2,x0,10

    divu    x5,x1,x2
    addi    x1,x0,77

    addi    x29,x0,10
    addi    x3,x0,20
    bne     x5,x29,fail

# ------------------------------------------------------------
# WAR: overwrite both source operands
# ------------------------------------------------------------

test_21:
    addi    x1,x0,100
    addi    x2,x0,10

    divu    x5,x1,x2

    addi    x1,x0,1
    addi    x2,x0,1

    addi    x29,x0,10
    addi    x3,x0,21
    bne     x5,x29,fail

# ------------------------------------------------------------
# WAR + WAW combined stress
# ------------------------------------------------------------

test_22:
    addi    x1,x0,120
    addi    x2,x0,10

    divu    x5,x1,x2      # 12

    addi    x1,x0,7
    addi    x5,x0,99

    addi    x29,x0,99
    addi    x3,x0,22
    bne     x5,x29,fail

# ------------------------------------------------------------
# Multiple writes around long-latency DIVU
# ------------------------------------------------------------

test_23:
    addi    x1,x0,144
    addi    x2,x0,12

    divu    x5,x1,x2      # 12
    addi    x6,x0,42
    addi    x7,x0,99

    addi    x29,x0,12
    addi    x3,x0,23
    bne     x5,x29,fail

    addi    x29,x0,42
    bne     x6,x29,fail

    addi    x29,x0,99
    bne     x7,x29,fail

# ------------------------------------------------------------
# x0 destination test
# ------------------------------------------------------------

test_24:
    addi    x1,x0,50
    addi    x2,x0,5

    divu    x0,x1,x2

    addi    x29,x0,0
    addi    x3,x0,18
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