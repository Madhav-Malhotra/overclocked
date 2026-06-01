.section .text.init
.globl _start

_start:
    addi	x3,x0,2
    addi	x1,x0,0
    jal	x4,target_2

linkaddr_2:
    addi	x0,x0,0
    addi	x0,x0,0
    jal	x0,fail

target_2:
    auipc	x2,0x0
    addi	x2,x2,-12
    bne	x2,x4,fail

test_3:
    addi	x1,x0,1
    jal	x0,test_3+0x18
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x1,x1,1
    addi	x29,x0,3
    addi	x3,x0,3
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
