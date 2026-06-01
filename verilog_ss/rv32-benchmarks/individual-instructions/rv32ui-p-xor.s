.section .text.init
.globl _start

_start:
    lui	x1,0xff010
    addi	x1,x1,-256
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    lui	x1,0xff01
    addi	x1,x1,-16
    lui	x2,0xf0f0f
    addi	x2,x2,240
    xor	x30,x1,x2
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    lui	x1,0xff0
    addi	x1,x1,255
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    lui	x1,0xf00ff
    addi	x1,x1,15
    lui	x2,0xf0f0f
    addi	x2,x2,240
    xor	x30,x1,x2
    lui	x29,0xff0
    addi	x29,x29,255
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    lui	x1,0xff010
    addi	x1,x1,-256
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x1,x1,x2
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,6
    bne	x1,x29,fail

test_7:
    lui	x1,0xff010
    addi	x1,x1,-256
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x2,x1,x2
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,7
    bne	x2,x29,fail

test_8:
    lui	x1,0xff010
    addi	x1,x1,-256
    xor	x1,x1,x1
    addi	x29,x0,0
    addi	x3,x0,8
    bne	x1,x29,fail

test_9:
    addi	x4,x0,0
    lui	x1,0xff010
    addi	x1,x1,-256
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_9+0x4
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,9
    bne	x6,x29,fail

test_10:
    addi	x4,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    lui	x2,0xf0f0f
    addi	x2,x2,240
    xor	x30,x1,x2
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_10+0x4
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,10
    bne	x6,x29,fail

test_11:
    addi	x4,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_11+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,11
    bne	x6,x29,fail

test_12:
    addi	x4,x0,0
    lui	x1,0xff010
    addi	x1,x1,-256
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_12+0x4
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,12
    bne	x30,x29,fail

test_13:
    addi	x4,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    lui	x2,0xf0f0f
    addi	x2,x2,240
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_13+0x4
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,13
    bne	x30,x29,fail

test_14:
    addi	x4,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    lui	x2,0xf0f1
    addi	x2,x2,-241
    addi	x0,x0,0
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_14+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,14
    bne	x30,x29,fail

test_15:
    addi	x4,x0,0
    lui	x1,0xff010
    addi	x1,x1,-256
    addi	x0,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_15+0x4
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,15
    bne	x30,x29,fail

test_16:
    addi	x4,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    addi	x0,x0,0
    lui	x2,0xf0f0f
    addi	x2,x2,240
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_16+0x4
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,16
    bne	x30,x29,fail

test_17:
    addi	x4,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    addi	x0,x0,0
    addi	x0,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_17+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,17
    bne	x30,x29,fail

test_18:
    addi	x4,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    lui	x1,0xff010
    addi	x1,x1,-256
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_18+0x4
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,18
    bne	x30,x29,fail

test_19:
    addi	x4,x0,0
    lui	x2,0xf0f0f
    addi	x2,x2,240
    lui	x1,0xff01
    addi	x1,x1,-16
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_19+0x4
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,19
    bne	x30,x29,fail

test_20:
    addi	x4,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    lui	x1,0xff0
    addi	x1,x1,255
    addi	x0,x0,0
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_20+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,20
    bne	x30,x29,fail

test_21:
    addi	x4,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    addi	x0,x0,0
    lui	x1,0xff010
    addi	x1,x1,-256
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_21+0x4
    lui	x29,0xf00ff
    addi	x29,x29,15
    addi	x3,x0,21
    bne	x30,x29,fail

test_22:
    addi	x4,x0,0
    lui	x2,0xf0f0f
    addi	x2,x2,240
    addi	x0,x0,0
    lui	x1,0xff01
    addi	x1,x1,-16
    addi	x0,x0,0
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_22+0x4
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,22
    bne	x30,x29,fail

test_23:
    addi	x4,x0,0
    lui	x2,0xf0f1
    addi	x2,x2,-241
    addi	x0,x0,0
    addi	x0,x0,0
    lui	x1,0xff0
    addi	x1,x1,255
    xor	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_23+0x4
    lui	x29,0xff01
    addi	x29,x29,-16
    addi	x3,x0,23
    bne	x30,x29,fail

test_24:
    lui	x1,0xff010
    addi	x1,x1,-256
    xor	x2,x0,x1
    lui	x29,0xff010
    addi	x29,x29,-256
    addi	x3,x0,24
    bne	x2,x29,fail

test_25:
    lui	x1,0xff0
    addi	x1,x1,255
    xor	x2,x1,x0
    lui	x29,0xff0
    addi	x29,x29,255
    addi	x3,x0,25
    bne	x2,x29,fail

test_26:
    xor	x1,x0,x0
    addi	x29,x0,0
    addi	x3,x0,26
    bne	x1,x29,fail

test_27:
    lui	x1,0x11111
    addi	x1,x1,273
    lui	x2,0x22222
    addi	x2,x2,546
    xor	x0,x1,x2
    addi	x29,x0,0
    addi	x3,x0,27
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
