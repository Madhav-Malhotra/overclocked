.section .text.init
.globl _start

_start:
    addi	x3,x0,2
    addi	x5,x0,0
    auipc	x6,0x0
    addi	x6,x6,16
    jalr	x5,0(x6)

linkaddr_2:
    jal	x0,fail

target_2:
    auipc	x6,0x0
    addi	x6,x6,-4
    bne	x5,x6,fail

test_4:
    addi	x3,x0,4
    addi	x4,x0,0
    auipc	x6,0x0
    addi	x6,x6,16
    jalr	x19,0(x6)
    bne	x0,x3,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_4+0x8

test_5:
    addi	x3,x0,5
    addi	x4,x0,0
    auipc	x6,0x0
    addi	x6,x6,20
    addi	x0,x0,0
    jalr	x19,0(x6)
    bne	x0,x3,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_5+0x8

test_6:
    addi	x3,x0,6
    addi	x4,x0,0
    auipc	x6,0x0
    addi	x6,x6,24
    addi	x0,x0,0
    addi	x0,x0,0
    jalr	x19,0(x6)
    bne	x0,x3,fail
    addi	x4,x4,1
    addi	x5,x0,2
    bne	x4,x5,test_6+0x8

test_7:
    addi	x5,x0,1
    auipc	x6,0x0
    addi	x6,x6,28
    jalr	x0,-4(x6)
    addi	x5,x5,1
    addi	x5,x5,1
    addi	x5,x5,1
    addi	x5,x5,1
    addi	x5,x5,1
    addi	x5,x5,1
    addi	x29,x0,4
    addi	x3,x0,7
    bne	x5,x29,fail
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
