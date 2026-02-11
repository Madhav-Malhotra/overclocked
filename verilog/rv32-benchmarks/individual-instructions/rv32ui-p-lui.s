.section .text.init
.globl _start

_start:
    lui	x1,0x0
    addi	x29,x0,0
    addi	x3,x0,2
    bne	x1,x29,fail

test_3:
    lui	x1,0xfffff
    srai	x1,x1,0x1
    addi	x29,x0,-2048
    addi	x3,x0,3
    bne	x1,x29,fail

test_4:
    lui	x1,0x7ffff
    srai	x1,x1,0x14
    addi	x29,x0,2047
    addi	x3,x0,4
    bne	x1,x29,fail

test_5:
    lui	x1,0x80000
    srai	x1,x1,0x14
    addi	x29,x0,-2048
    addi	x3,x0,5
    bne	x1,x29,fail

test_6:
    lui	x0,0x80000
    addi	x29,x0,0
    addi	x3,x0,6
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
