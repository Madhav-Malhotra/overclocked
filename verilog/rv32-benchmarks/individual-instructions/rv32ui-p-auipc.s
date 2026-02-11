.section .text.init
.globl _start

_start:
    auipc	x10,0x2
    addi	x10,x10,1820
    jal	x11,_start+0xc
    sub	x10,x10,x11
    lui	x29,0x2
    addi	x29,x29,1808
    addi	x3,x0,2
    bne	x10,x29,fail

test_3:
    auipc	x10,0xffffe
    addi	x10,x10,-1796
    jal	x11,test_3+0xc
    sub	x10,x10,x11
    lui	x29,0xffffe
    addi	x29,x29,-1808
    addi	x3,x0,3
    bne	x10,x29,fail
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
