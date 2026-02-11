.section .text.init
.globl _start

_start:
    addi	x1,x0,0
    srai	x30,x1,0x0
    addi	x29,x0,0
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    lui	x1,0x80000
    srai	x30,x1,0x1
    lui	x29,0xc0000
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    lui	x1,0x80000
    srai	x30,x1,0x7
    lui	x29,0xff000
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    lui	x1,0x80000
    srai	x30,x1,0xe
    lui	x29,0xfffe0
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    lui	x1,0x80000
    addi	x1,x1,1
    srai	x30,x1,0x1f
    addi	x29,x0,-1
    addi	x3,x0,6
    bne	x30,x29,fail

test_7:
    lui	x1,0x80000
    addi	x1,x1,-1
    srai	x30,x1,0x0
    lui	x29,0x80000
    addi	x29,x29,-1
    addi	x3,x0,7
    bne	x30,x29,fail

test_8:
    lui	x1,0x80000
    addi	x1,x1,-1
    srai	x30,x1,0x1
    lui	x29,0x40000
    addi	x29,x29,-1
    addi	x3,x0,8
    bne	x30,x29,fail

test_9:
    lui	x1,0x80000
    addi	x1,x1,-1
    srai	x30,x1,0x7
    lui	x29,0x1000
    addi	x29,x29,-1
    addi	x3,x0,9
    bne	x30,x29,fail

test_10:
    lui	x1,0x80000
    addi	x1,x1,-1
    srai	x30,x1,0xe
    lui	x29,0x20
    addi	x29,x29,-1
    addi	x3,x0,10
    bne	x30,x29,fail

test_11:
    lui	x1,0x80000
    addi	x1,x1,-1
    srai	x30,x1,0x1f
    addi	x29,x0,0
    addi	x3,x0,11
    bne	x30,x29,fail

test_12:
    lui	x1,0x81818
    addi	x1,x1,385
    srai	x30,x1,0x0
    lui	x29,0x81818
    addi	x29,x29,385
    addi	x3,x0,12
    bne	x30,x29,fail

test_13:
    lui	x1,0x81818
    addi	x1,x1,385
    srai	x30,x1,0x1
    lui	x29,0xc0c0c
    addi	x29,x29,192
    addi	x3,x0,13
    bne	x30,x29,fail

test_14:
    lui	x1,0x81818
    addi	x1,x1,385
    srai	x30,x1,0x7
    lui	x29,0xff030
    addi	x29,x29,771
    addi	x3,x0,14
    bne	x30,x29,fail

test_15:
    lui	x1,0x81818
    addi	x1,x1,385
    srai	x30,x1,0xe
    lui	x29,0xfffe0
    addi	x29,x29,1542
    addi	x3,x0,15
    bne	x30,x29,fail

test_16:
    lui	x1,0x81818
    addi	x1,x1,385
    srai	x30,x1,0x1f
    addi	x29,x0,-1
    addi	x3,x0,16
    bne	x30,x29,fail

test_17:
    lui	x1,0x80000
    srai	x1,x1,0x7
    lui	x29,0xff000
    addi	x3,x0,17
    bne	x1,x29,fail

test_18:
    addi	x4,x0,0
    lui	x1,0x80000
    srai	x30,x1,0x7
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_18+0x4
    lui	x29,0xff000
    addi	x3,x0,18
    bne	x6,x29,fail

test_19:
    addi	x4,x0,0
    lui	x1,0x80000
    srai	x30,x1,0xe
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_19+0x4
    lui	x29,0xfffe0
    addi	x3,x0,19
    bne	x6,x29,fail

test_20:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x1,x1,1
    srai	x30,x1,0x1f
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_20+0x4
    addi	x29,x0,-1
    addi	x3,x0,20
    bne	x6,x29,fail

test_21:
    addi	x4,x0,0
    lui	x1,0x80000
    srai	x30,x1,0x7
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_21+0x4
    lui	x29,0xff000
    addi	x3,x0,21
    bne	x30,x29,fail

test_22:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x0,x0,0
    srai	x30,x1,0xe
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_22+0x4
    lui	x29,0xfffe0
    addi	x3,x0,22
    bne	x30,x29,fail

test_23:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x1,x1,1
    addi	x0,x0,0
    addi	x0,x0,0
    srai	x30,x1,0x1f
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_23+0x4
    addi	x29,x0,-1
    addi	x3,x0,23
    bne	x30,x29,fail

test_24:
    srai	x1,x0,0x4
    addi	x29,x0,0
    addi	x3,x0,24
    bne	x1,x29,fail

test_25:
    addi	x1,x0,33
    srai	x0,x1,0xa
    addi	x29,x0,0
    addi	x3,x0,25
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
