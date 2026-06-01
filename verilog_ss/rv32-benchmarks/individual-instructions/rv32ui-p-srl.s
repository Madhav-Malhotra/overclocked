.section .text.init
.globl _start

_start:
    lui	x1,0x80000
    addi	x2,x0,0
    srl	x30,x1,x2
    lui	x29,0x80000
    addi	x3,x0,2
    bne	x30,x29,fail

test_3:
    lui	x1,0x80000
    addi	x2,x0,1
    srl	x30,x1,x2
    lui	x29,0x40000
    addi	x3,x0,3
    bne	x30,x29,fail

test_4:
    lui	x1,0x80000
    addi	x2,x0,7
    srl	x30,x1,x2
    lui	x29,0x1000
    addi	x3,x0,4
    bne	x30,x29,fail

test_5:
    lui	x1,0x80000
    addi	x2,x0,14
    srl	x30,x1,x2
    lui	x29,0x20
    addi	x3,x0,5
    bne	x30,x29,fail

test_6:
    lui	x1,0x80000
    addi	x1,x1,1
    addi	x2,x0,31
    srl	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,6
    bne	x30,x29,fail

test_7:
    addi	x1,x0,-1
    addi	x2,x0,0
    srl	x30,x1,x2
    addi	x29,x0,-1
    addi	x3,x0,7
    bne	x30,x29,fail

test_8:
    addi	x1,x0,-1
    addi	x2,x0,1
    srl	x30,x1,x2
    lui	x29,0x80000
    addi	x29,x29,-1
    addi	x3,x0,8
    bne	x30,x29,fail

test_9:
    addi	x1,x0,-1
    addi	x2,x0,7
    srl	x30,x1,x2
    lui	x29,0x2000
    addi	x29,x29,-1
    addi	x3,x0,9
    bne	x30,x29,fail

test_10:
    addi	x1,x0,-1
    addi	x2,x0,14
    srl	x30,x1,x2
    lui	x29,0x40
    addi	x29,x29,-1
    addi	x3,x0,10
    bne	x30,x29,fail

test_11:
    addi	x1,x0,-1
    addi	x2,x0,31
    srl	x30,x1,x2
    addi	x29,x0,1
    addi	x3,x0,11
    bne	x30,x29,fail

test_12:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,0
    srl	x30,x1,x2
    lui	x29,0x21212
    addi	x29,x29,289
    addi	x3,x0,12
    bne	x30,x29,fail

test_13:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,1
    srl	x30,x1,x2
    lui	x29,0x10909
    addi	x29,x29,144
    addi	x3,x0,13
    bne	x30,x29,fail

test_14:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,7
    srl	x30,x1,x2
    lui	x29,0x424
    addi	x29,x29,578
    addi	x3,x0,14
    bne	x30,x29,fail

test_15:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,14
    srl	x30,x1,x2
    lui	x29,0x8
    addi	x29,x29,1156
    addi	x3,x0,15
    bne	x30,x29,fail

test_16:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,31
    srl	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,16
    bne	x30,x29,fail

test_17:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,-64
    srl	x30,x1,x2
    lui	x29,0x21212
    addi	x29,x29,289
    addi	x3,x0,17
    bne	x30,x29,fail

test_18:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,-63
    srl	x30,x1,x2
    lui	x29,0x10909
    addi	x29,x29,144
    addi	x3,x0,18
    bne	x30,x29,fail

test_19:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,-57
    srl	x30,x1,x2
    lui	x29,0x424
    addi	x29,x29,578
    addi	x3,x0,19
    bne	x30,x29,fail

test_20:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,-50
    srl	x30,x1,x2
    lui	x29,0x8
    addi	x29,x29,1156
    addi	x3,x0,20
    bne	x30,x29,fail

test_21:
    lui	x1,0x21212
    addi	x1,x1,289
    addi	x2,x0,-1
    srl	x30,x1,x2
    addi	x29,x0,0
    addi	x3,x0,21
    bne	x30,x29,fail

test_22:
    lui	x1,0x80000
    addi	x2,x0,7
    srl	x1,x1,x2
    lui	x29,0x1000
    addi	x3,x0,22
    bne	x1,x29,fail

test_23:
    lui	x1,0x80000
    addi	x2,x0,14
    srl	x2,x1,x2
    lui	x29,0x20
    addi	x3,x0,23
    bne	x2,x29,fail

test_24:
    addi	x1,x0,7
    srl	x1,x1,x1
    addi	x29,x0,0
    addi	x3,x0,24
    bne	x1,x29,fail

test_25:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,7
    srl	x30,x1,x2
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_25+0x4
    lui	x29,0x1000
    addi	x3,x0,25
    bne	x6,x29,fail

test_26:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,14
    srl	x30,x1,x2
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_26+0x4
    lui	x29,0x20
    addi	x3,x0,26
    bne	x6,x29,fail

test_27:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,31
    srl	x30,x1,x2
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x6,x30,0
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_27+0x4
    addi	x29,x0,1
    addi	x3,x0,27
    bne	x6,x29,fail

test_28:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,7
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_28+0x4
    lui	x29,0x1000
    addi	x3,x0,28
    bne	x30,x29,fail

test_29:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,14
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_29+0x4
    lui	x29,0x20
    addi	x3,x0,29
    bne	x30,x29,fail

test_30:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x2,x0,31
    addi	x0,x0,0
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_30+0x4
    addi	x29,x0,1
    addi	x3,x0,30
    bne	x30,x29,fail

test_31:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x0,x0,0
    addi	x2,x0,7
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_31+0x4
    lui	x29,0x1000
    addi	x3,x0,31
    bne	x30,x29,fail

test_32:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x0,x0,0
    addi	x2,x0,14
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_32+0x4
    lui	x29,0x20
    addi	x3,x0,32
    bne	x30,x29,fail

test_33:
    addi	x4,x0,0
    lui	x1,0x80000
    addi	x0,x0,0
    addi	x0,x0,0
    addi	x2,x0,31
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_33+0x4
    addi	x29,x0,1
    addi	x3,x0,33
    bne	x30,x29,fail

test_34:
    addi	x4,x0,0
    addi	x2,x0,7
    lui	x1,0x80000
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_34+0x4
    lui	x29,0x1000
    addi	x3,x0,34
    bne	x30,x29,fail

test_35:
    addi	x4,x0,0
    addi	x2,x0,14
    lui	x1,0x80000
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_35+0x4
    lui	x29,0x20
    addi	x3,x0,35
    bne	x30,x29,fail

test_36:
    addi	x4,x0,0
    addi	x2,x0,31
    lui	x1,0x80000
    addi	x0,x0,0
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_36+0x4
    addi	x29,x0,1
    addi	x3,x0,36
    bne	x30,x29,fail

test_37:
    addi	x4,x0,0
    addi	x2,x0,7
    addi	x0,x0,0
    lui	x1,0x80000
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_37+0x4
    lui	x29,0x1000
    addi	x3,x0,37
    bne	x30,x29,fail

test_38:
    addi	x4,x0,0
    addi	x2,x0,14
    addi	x0,x0,0
    lui	x1,0x80000
    addi	x0,x0,0
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_38+0x4
    lui	x29,0x20
    addi	x3,x0,38
    bne	x30,x29,fail

test_39:
    addi	x4,x0,0
    addi	x2,x0,31
    addi	x0,x0,0
    addi	x0,x0,0
    lui	x1,0x80000
    srl	x30,x1,x2
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_39+0x4
    addi	x29,x0,1
    addi	x3,x0,39
    bne	x30,x29,fail

test_40:
    addi	x1,x0,15
    srl	x2,x0,x1
    addi	x29,x0,0
    addi	x3,x0,40
    bne	x2,x29,fail

test_41:
    addi	x1,x0,32
    srl	x2,x1,x0
    addi	x29,x0,32
    addi	x3,x0,41
    bne	x2,x29,fail

test_42:
    srl	x1,x0,x0
    addi	x29,x0,0
    addi	x3,x0,42
    bne	x1,x29,fail

test_43:
    addi	x1,x0,1024
    lui	x2,0x1
    addi	x2,x2,-2048
    srl	x0,x1,x2
    addi	x29,x0,0
    addi	x3,x0,43
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
