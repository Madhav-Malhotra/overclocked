.section .text.init
.globl _start

_start:
    lui	x1,0xff010
    addi	x1,x1,-256
    ori	x30,x1,-241
    addi	x29,x0,-241
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    lui	x1,0xff01
    addi	x1,x1,-16
    ori	x30,x1,240
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    lui	x1,0xff0
    addi	x1,x1,255
    ori	x30,x1,1807
    lui	x29,0xff0
    addi	x29,x29,2047
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    lui	x1,0xf00ff
    addi	x1,x1,15
    ori	x30,x1,240
    lui	x29,0xf00ff
    addi	x29,x29,255
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    lui	x1,0xff010
    addi	x1,x1,-256
    ori	x1,x1,240
    lui	x29,0xff010
    addi	x29,x29,-16
    addi	x3,x0,6
    bne	x1,x29,fail

test_7:
    addi	x4,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    ori	x30,x1,240
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_7+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,7
    bne	x6,x29,fail

test_8:
    addi	x4,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    ori	x30,x1,1807
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_8+0x4
    lui	x29,0xff0
    addi	x29,x29,2047
    addi	x3,x0,8
    bne	x6,x29,fail

test_9:
    addi	x4,x0,0
    lui	x1,0xf00ff
    addi	x1,x1,15
    ori	x30,x1,240
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_9+0x4
    lui	x29,0xf00ff
    addi	x29,x29,255
    addi	x3,x0,9
    bne	x6,x29,fail

test_10:
    addi	x4,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    ori	x30,x1,240
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_10+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,10
    bne	x30,x29,fail

test_11:
    addi	x4,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    addi	x0,x0,0
    ori	x30,x1,-241
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_11+0x4
    addi	x29,x0,-1
    addi	x3,x0,11
    bne	x30,x29,fail

test_12:
    addi	x4,x0,0
    lui	x1,0xf00ff
    addi	x1,x1,15
    addi	x0,x0,0
    addi	x0,x0,0
    ori	x30,x1,240
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_12+0x4
    lui	x29,0xf00ff
    addi	x29,x29,255
    addi	x3,x0,12
    bne	x30,x29,fail

test_13:
    ori	x1,x0,240
    addi	x29,x0,240
    addi	x3,x0,13
    bne	x1,x29,fail

test_14:
    lui	x1,0xff0
    addi	x1,x1,255
    ori	x0,x1,1807
    addi	x29,x0,0
    addi	x3,x0,14
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
