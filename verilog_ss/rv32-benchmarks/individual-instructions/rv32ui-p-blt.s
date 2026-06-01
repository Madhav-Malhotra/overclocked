.section .text.init
.globl _start

_start:
    addi	x3,x0,2
    addi	x1,x0,0
    addi	x2,x0,1
    blt	x1,x2,_start+0x18
    bne	x0,x3,fail
    bne	x0,x3,test_3
    blt	x1,x2,_start+0x14
    bne	x0,x3,fail

test_3:
    addi	x3,x0,3
    addi	x1,x0,-1
    addi	x2,x0,1
    blt	x1,x2,test_3+0x18
    bne	x0,x3,fail
    bne	x0,x3,test_4
    blt	x1,x2,test_3+0x14
    bne	x0,x3,fail

test_4:
    addi	x3,x0,4
    addi	x1,x0,-2
    addi	x2,x0,-1
    blt	x1,x2,test_4+0x18
    bne	x0,x3,fail
    bne	x0,x3,test_5
    blt	x1,x2,test_4+0x14
    bne	x0,x3,fail

test_5:
    addi	x3,x0,5
    addi	x1,x0,1
    addi	x2,x0,0
    blt	x1,x2,test_5+0x14
    bne	x0,x3,test_5+0x18
    bne	x0,x3,fail
    blt	x1,x2,test_5+0x14

test_6:
    addi	x3,x0,6
    addi	x1,x0,1
    addi	x2,x0,-1
    blt	x1,x2,test_6+0x14
    bne	x0,x3,test_6+0x18
    bne	x0,x3,fail
    blt	x1,x2,test_6+0x14

test_7:
    addi	x3,x0,7
    addi	x1,x0,-1
    addi	x2,x0,-2
    blt	x1,x2,test_7+0x14
    bne	x0,x3,test_7+0x18
    bne	x0,x3,fail
    blt	x1,x2,test_7+0x14

test_8:
    addi	x3,x0,8
    addi	x1,x0,1
    addi	x2,x0,-2
    blt	x1,x2,test_8+0x14
    bne	x0,x3,test_8+0x18
    bne	x0,x3,fail
    blt	x1,x2,test_8+0x14

test_9:
    addi	x3,x0,9
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_9+0x8

test_10:
    addi	x3,x0,10
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_10+0x8

test_11:
    addi	x3,x0,11
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_11+0x8

test_12:
    addi	x3,x0,12
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_12+0x8

test_13:
    addi	x3,x0,13
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_13+0x8

test_14:
    addi	x3,x0,14
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_14+0x8

test_15:
    addi	x3,x0,15
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_15+0x8

test_16:
    addi	x3,x0,16
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_16+0x8

test_17:
    addi	x3,x0,17
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_17+0x8

test_18:
    addi	x3,x0,18
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_18+0x8

test_19:
    addi	x3,x0,19
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    addi	x0,x0,0
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_19+0x8

test_20:
    addi	x3,x0,20
    addi	x4,x0,0
    addi	x1,x0,0
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x2,x0,-1
    blt	x1,x2,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_20+0x8

test_21:
    addi	x1,x0,1
    blt	x0,x1,test_21+0x18
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x29,x0,3
    addi	x3,x0,21
    bne	x1,x29,fail
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
