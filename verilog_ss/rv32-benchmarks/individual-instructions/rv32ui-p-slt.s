.section .text.init
.globl _start

_start:
    addi	x1,x0,0
    addi	x2,x0,0
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    addi	x1,x0,1
    addi	x2,x0,1
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    addi	x1,x0,3
    addi	x2,x0,7
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    addi	x1,x0,7
    addi	x2,x0,3
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    addi	x1,x0,0
    lui	x2,0xffff8
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,6
    bne	x30,x29,fail

test_7:
    lui	x1,0x80000
    addi	x2,x0,0
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,7
    bne	x30,x29,fail

test_8:
    lui	x1,0x80000
    lui	x2,0xffff8
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,8
    bne	x30,x29,fail

test_9:
    addi	x1,x0,0
    lui	x2,0x8
    addi	x2,x2,-1
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,9
    bne	x30,x29,fail

test_10:
    lui	x1,0x80000
    addi	x1,x1,-1
    addi	x2,x0,0
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,10
    bne	x30,x29,fail

test_11:
    lui	x1,0x80000
    addi	x1,x1,-1
    lui	x2,0x8
    addi	x2,x2,-1
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,11
    bne	x30,x29,fail

test_12:
    lui	x1,0x80000
    lui	x2,0x8
    addi	x2,x2,-1
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,12
    bne	x30,x29,fail

test_13:
    lui	x1,0x80000
    addi	x1,x1,-1
    lui	x2,0xffff8
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,13
    bne	x30,x29,fail

test_14:
    addi	x1,x0,0
    addi	x2,x0,-1
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,14
    bne	x30,x29,fail

test_15:
    addi	x1,x0,-1
    addi	x2,x0,1
    slt	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,15
    bne	x30,x29,fail

test_16:
    addi	x1,x0,-1
    addi	x2,x0,-1
    slt	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,16
    bne	x30,x29,fail

test_17:
    addi	x1,x0,14
    addi	x2,x0,13
    slt	x1,x1,x2
    addi	x29,x0,0
    addi	x3,x0,17
    bne	x1,x29,fail

test_18:
    addi	x1,x0,11
    addi	x2,x0,13
    slt	x2,x1,x2
    addi	x29,x0,1
    addi	x3,x0,18
    bne	x2,x29,fail

test_19:
    addi	x1,x0,13
    slt	x1,x1,x1
    addi	x29,x0,0
    addi	x3,x0,19
    bne	x1,x29,fail

test_20:
    addi	x4,x0,0
    addi	x1,x0,11
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_20+0x4
    addi	x29,x0,1
    addi	x3,x0,20
    bne	x6,x29,fail

test_21:
    addi	x4,x0,0
    addi	x1,x0,14
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_21+0x4
    addi	x29,x0,0
    addi	x3,x0,21
    bne	x6,x29,fail

test_22:
    addi	x4,x0,0
    addi	x1,x0,12
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_22+0x4
    addi	x29,x0,1
    addi	x3,x0,22
    bne	x6,x29,fail

test_23:
    addi	x4,x0,0
    addi	x1,x0,14
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_23+0x4
    addi	x29,x0,0
    addi	x3,x0,23
    bne	x30,x29,fail

test_24:
    addi	x4,x0,0
    addi	x1,x0,11
    addi	x2,x0,13
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_24+0x4
    addi	x29,x0,1
    addi	x3,x0,24
    bne	x30,x29,fail

test_25:
    addi	x4,x0,0
    addi	x1,x0,15
    addi	x2,x0,13
    addi	x0,x0,0
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_25+0x4
    addi	x29,x0,0
    addi	x3,x0,25
    bne	x30,x29,fail

test_26:
    addi	x4,x0,0
    addi	x1,x0,10
    addi	x0,x0,0
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_26+0x4
    addi	x29,x0,1
    addi	x3,x0,26
    bne	x30,x29,fail

test_27:
    addi	x4,x0,0
    addi	x1,x0,16
    addi	x0,x0,0
    addi	x2,x0,13
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_27+0x4
    addi	x29,x0,0
    addi	x3,x0,27
    bne	x30,x29,fail

test_28:
    addi	x4,x0,0
    addi	x1,x0,9
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x2,x0,13
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_28+0x4
    addi	x29,x0,1
    addi	x3,x0,28
    bne	x30,x29,fail

test_29:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x1,x0,17
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_29+0x4
    addi	x29,x0,0
    addi	x3,x0,29
    bne	x30,x29,fail

test_30:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x1,x0,8
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_30+0x4
    addi	x29,x0,1
    addi	x3,x0,30
    bne	x30,x29,fail

test_31:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x1,x0,18
    addi	x0,x0,0
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_31+0x4
    addi	x29,x0,0
    addi	x3,x0,31
    bne	x30,x29,fail

test_32:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x0,x0,0
    addi	x1,x0,7
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_32+0x4
    addi	x29,x0,1
    addi	x3,x0,32
    bne	x30,x29,fail

test_33:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x0,x0,0
    addi	x1,x0,19
    addi	x0,x0,0
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_33+0x4
    addi	x29,x0,0
    addi	x3,x0,33
    bne	x30,x29,fail

test_34:
    addi	x4,x0,0
    addi	x2,x0,13
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x1,x0,6
    slt	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_34+0x4
    addi	x29,x0,1
    addi	x3,x0,34
    bne	x30,x29,fail

test_35:
    addi	x1,x0,-1
    slt	x2,x0,x1
    addi	x29,x0,0
    addi	x3,x0,35
    bne	x2,x29,fail

test_36:
    addi	x1,x0,-1
    slt	x2,x1,x0
    addi	x29,x0,1
    addi	x3,x0,36
    bne	x2,x29,fail

test_37:
    slt	x1,x0,x0
    addi	x29,x0,0
    addi	x3,x0,37
    bne	x1,x29,fail

test_38:
    addi	x1,x0,16
    addi	x2,x0,30
    slt	x0,x1,x2
    addi	x29,x0,0
    addi	x3,x0,38
    bne	x0,x29,fail
    bne	x0,x3,pass

fail:
    fence	iorw,iorw
    beq	x3,x0,fail+0x4
    slli	x3,x3,0x1
    ori	x3,x3,1
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0,tohost
    sw      x3,0(t0)
    ecall

pass:
    fence	iorw,iorw
    addi	x3,x0,1
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0,tohost
    sw      x3,0(t0)
    ecall
    unimp
.section .text.init
.globl _start

end_signature:
