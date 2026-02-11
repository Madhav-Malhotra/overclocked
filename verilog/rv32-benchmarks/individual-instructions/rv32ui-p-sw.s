.section .text.init
.globl _start

_start:
    auipc	x1,0x0
    addi	x1,x1,1220
    lui	x2,0xaa0
    addi	x2,x2,170
    sw	x2,0(x1)
    lw	x30,0(x1)
    lui	x29,0xaa0
    addi	x29,x29,170
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    auipc	x1,0x0
    addi	x1,x1,1180
    lui	x2,0xaa00b
    addi	x2,x2,-1536
    sw	x2,4(x1)
    lw	x30,4(x1)
    lui	x29,0xaa00b
    addi	x29,x29,-1536
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    auipc	x1,0x0
    addi	x1,x1,1140
    lui	x2,0xaa01
    addi	x2,x2,-1376
    sw	x2,8(x1)
    lw	x30,8(x1)
    lui	x29,0xaa01
    addi	x29,x29,-1376
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    auipc	x1,0x0
    addi	x1,x1,1100
    lui	x2,0xa00aa
    addi	x2,x2,10
    sw	x2,12(x1)
    lw	x30,12(x1)
    lui	x29,0xa00aa
    addi	x29,x29,10
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    auipc	x1,0x0
    addi	x1,x1,1088
    lui	x2,0xaa0
    addi	x2,x2,170
    sw	x2,-12(x1)
    lw	x30,-12(x1)
    lui	x29,0xaa0
    addi	x29,x29,170
    addi	x3,x0,6
    bne	x30,x29,fail

test_7:
    auipc	x1,0x0
    addi	x1,x1,1048
    lui	x2,0xaa00b
    addi	x2,x2,-1536
    sw	x2,-8(x1)
    lw	x30,-8(x1)
    lui	x29,0xaa00b
    addi	x29,x29,-1536
    addi	x3,x0,7
    bne	x30,x29,fail

test_8:
    auipc	x1,0x0
    addi	x1,x1,1008
    lui	x2,0xaa01
    addi	x2,x2,-1376
    sw	x2,-4(x1)
    lw	x30,-4(x1)
    lui	x29,0xaa01
    addi	x29,x29,-1376
    addi	x3,x0,8
    bne	x30,x29,fail

test_9:
    auipc	x1,0x0
    addi	x1,x1,968
    lui	x2,0xa00aa
    addi	x2,x2,10
    sw	x2,0(x1)
    lw	x30,0(x1)
    lui	x29,0xa00aa
    addi	x29,x29,10
    addi	x3,x0,9
    bne	x30,x29,fail

test_10:
    auipc	x1,0x0
    addi	x1,x1,932
    lui	x2,0x12345
    addi	x2,x2,1656
    addi	x4,x1,-32
    sw	x2,32(x4)
    lw	x5,0(x1)
    lui	x29,0x12345
    addi	x29,x29,1656
    addi	x3,x0,10
    bne	x5,x29,fail

test_11:
    auipc	x1,0x0
    addi	x1,x1,888
    lui	x2,0x58213
    addi	x2,x2,152
    addi	x1,x1,-3
    sw	x2,7(x1)
    auipc	x4,0x0
    addi	x4,x4,868
    lw	x5,0(x4)
    lui	x29,0x58213
    addi	x29,x29,152
    addi	x3,x0,11
    bne	x5,x29,fail

test_12:
    addi	x3,x0,12
    addi	x4,x0,0
    lui	x1,0xaabbd
    addi	x1,x1,-803
    auipc	x2,0x0
    addi	x2,x2,788
    sw	x1,0(x2)
    lw	x30,0(x2)
    lui	x29,0xaabbd
    addi	x29,x29,-803
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_12+0x8

test_13:
    addi	x3,x0,13
    addi	x4,x0,0
    lui	x1,0xdaabc
    addi	x1,x1,-819
    auipc	x2,0x0
    addi	x2,x2,732
    addi	x0,x0,0
    sw	x1,4(x2)
    lw	x30,4(x2)
    lui	x29,0xdaabc
    addi	x29,x29,-819
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_13+0x8

test_14:
    addi	x3,x0,14
    addi	x4,x0,0
    lui	x1,0xddaac
    addi	x1,x1,-1076
    auipc	x2,0x0
    addi	x2,x2,672
    addi	x0,x0,0
    addi	x0,x0,0
    sw	x1,8(x2)
    lw	x30,8(x2)
    lui	x29,0xddaac
    addi	x29,x29,-1076
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_14+0x8

test_15:
    addi	x3,x0,15
    addi	x4,x0,0
    lui	x1,0xcddab
    addi	x1,x1,-1092
    addi	x0,x0,0
    auipc	x2,0x0
    addi	x2,x2,604
    sw	x1,12(x2)
    lw	x30,12(x2)
    lui	x29,0xcddab
    addi	x29,x29,-1092
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_15+0x8

test_16:
    addi	x3,x0,16
    addi	x4,x0,0
    lui	x1,0xccddb
    addi	x1,x1,-1349
    addi	x0,x0,0
    auipc	x2,0x0
    addi	x2,x2,544
    addi	x0,x0,0
    sw	x1,16(x2)
    lw	x30,16(x2)
    lui	x29,0xccddb
    addi	x29,x29,-1349
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_16+0x8

test_17:
    addi	x3,x0,17
    addi	x4,x0,0
    lui	x1,0xbccde
    addi	x1,x1,-1365
    addi	x0,x0,0
    addi	x0,x0,0
    auipc	x2,0x0
    addi	x2,x2,476
    sw	x1,20(x2)
    lw	x30,20(x2)
    lui	x29,0xbccde
    addi	x29,x29,-1365
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_17+0x8

test_18:
    addi	x3,x0,18
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,428
    lui	x1,0x112
    addi	x1,x1,563
    sw	x1,0(x2)
    lw	x30,0(x2)
    lui	x29,0x112
    addi	x29,x29,563
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_18+0x8

test_19:
    addi	x3,x0,19
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,372
    lui	x1,0x30011
    addi	x1,x1,547
    addi	x0,x0,0
    sw	x1,4(x2)
    lw	x30,4(x2)
    lui	x29,0x30011
    addi	x29,x29,547
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_19+0x8

test_20:
    addi	x3,x0,20
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,312
    lui	x1,0x33001
    addi	x1,x1,290
    addi	x0,x0,0
    addi	x0,x0,0
    sw	x1,8(x2)
    lw	x30,8(x2)
    lui	x29,0x33001
    addi	x29,x29,290
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_20+0x8

test_21:
    addi	x3,x0,21
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,248
    addi	x0,x0,0
    lui	x1,0x23300
    addi	x1,x1,274
    sw	x1,12(x2)
    lw	x30,12(x2)
    lui	x29,0x23300
    addi	x29,x29,274
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_21+0x8

test_22:
    addi	x3,x0,22
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,188
    addi	x0,x0,0
    lui	x1,0x22330
    addi	x1,x1,17
    addi	x0,x0,0
    sw	x1,16(x2)
    lw	x30,16(x2)
    lui	x29,0x22330
    addi	x29,x29,17
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_22+0x8

test_23:
    addi	x3,x0,23
    addi	x4,x0,0
    auipc	x2,0x0
    addi	x2,x2,124
    addi	x0,x0,0
    addi	x0,x0,0
    lui	x1,0x12233
    addi	x1,x1,1
    sw	x1,20(x2)
    lw	x30,20(x2)
    lui	x29,0x12233
    addi	x29,x29,1
    bne	x30,x29,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_23+0x8
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

.section .data
.align 4

tdat:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat2:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat3:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat4:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat5:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat6:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat7:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat8:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat9:
    .byte 0xef, 0xbe, 0xad, 0xde

tdat10:
    .byte 0xef, 0xbe, 0xad, 0xde
