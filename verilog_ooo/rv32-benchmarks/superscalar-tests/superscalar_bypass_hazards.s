# superscalar_bypass_hazards.S
# Focus: MX, WX, WM bypassing paths across dual ways + control hazards

.section .text.init
.globl _start

_start:
    # Initialize base registers cleanly across ways
    addi    x1, x0, 10
    addi    x2, x0, 20
    addi    x3, x0, 1          # Fail marker tracker (matches template format)

    # =========================================================================
    # Test 1: MX Bypass across ways (Memory to Execute)
    # Way 0 loads data. Way 1 in the next cycle's EX stage needs that data.
    # Because of the 1-cycle load-use delay, this must force a pipeline stall.
    # =========================================================================
    la      x5, test_data       # Way 0
    nop                         # Way 1
    lw      x6, 0(x5)           # Cycle N: Way 0 (Load)
    addi    x7, x0, 5           # Cycle N: Way 1
    add     x8, x6, x7          # Cycle N+1: Way 0 (Needs x6 via MX bypass after 1-cycle stall)
    addi    x9, x0, 0x15        # Cycle N+1: Way 1 (0x10 + 5 = 0x15)
    
    bne     x8, x9, fail

    # =========================================================================
    # Test 2: WX Bypass with Inter-way dependency
    # Validates Writeback-to-Execute path when instructions slide down the pipe.
    # =========================================================================
    addi    x3, x0, 2          # Fail marker = 2
    addi    x11, x0, 100        # Way 0
    addi    x12, x0, 200        # Way 1
    add     x13, x11, x12       # Cycle N: Way 0 (x13 = 300)
    nop                         # Cycle N: Way 1
    nop                         # Cycle N+1: Way 0
    nop                         # Cycle N+1: Way 1
    sub     x14, x13, x11       # Cycle N+2: Way 0 (Needs x13 via WX bypass; should be 200)
    addi    x15, x0, 200        # Cycle N+2: Way 1
    
    bne     x14, x15, fail

    # =========================================================================
    # Test 3: WM Bypass (Store Word relying on Writeback data)
    # Verifies data can be bypassed directly into the Memory stage for a store.
    # =========================================================================
    addi    x3, x0, 3          # Fail marker = 3
    la      x16, scratch_mem    # Way 0
    
    # Replaced 'addi x17, x0, 0xABC' with 'li' pseudo-instruction.
    # Added a matching padding nop in Way 0 to maintain perfect cycle structure.
    nop                         # Way 0
    li      x17, 0xABC          # Way 1
    
    add     x18, x17, x0        # Cycle N: Way 0 (x18 = 0xABC)
    nop                         # Cycle N: Way 1
    sw      x18, 0(x16)         # Cycle N+1: Way 0 (WM bypass of x18 directly into memory stage)
    nop                         # Cycle N+1: Way 1
    lw      x19, 0(x16)         # Cycle N+2: Way 0
    nop                         # Cycle N+2: Way 1
    
    bne     x19, x17, fail

    # =========================================================================
    # Test 4: Branch Misprediction Recovery with Dependent Instructions
    # Pipeline predicts NOT TAKEN. We force it to be TAKEN.
    # Instructions fetched speculatively in the shadow of the branch must be 
    # completely squashed and must not pollute the register file.
    # =========================================================================
    addi    x3, x0, 4          # Fail marker = 4
    addi    x20, x0, 5
    addi    x21, x0, 5
    addi    x22, x0, 50         # Targets for verifying squashing
    addi    x23, x0, 60

    beq     x20, x21, taken_target # Cycle N: Way 0 (Branch Taken!)
    addi    x22, x20, 10        # Cycle N: Way 1 (Speculative - Squashed!)
    addi    x23, x21, 20        # Cycle N+1: Way 0 (Speculative - Squashed!)
    nop                         # Cycle N+1: Way 1

    # If it falls through here, squashing completely failed
    j       fail

taken_target:
    # Ensure speculative writes did not happen
    addi    x24, x0, 50
    bne     x22, x24, fail
    addi    x25, x0, 60
    bne     x23, x25, fail

    # All tests in this file passed
    bne     x0, x0, fail        # Fallback safeguard structure from template
    bne     x0, x3, pass

fail:
    fence   iorw,iorw
    beq     x3,x0,fail+0x4
    slli    x3,x3,0x1
    ori     x3,x3,1
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0,tohost
    sw      x3,0(t0)
    ecall

pass:
    fence   iorw,iorw
    addi    x3,x0,1             # In Spike HTIF, writing 1 indicates success/termination
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0,tohost
    sw      x3,0(t0)
    ecall
    unimp

.section .text.init
.globl _start

end_signature:

.section .data
.align 4
test_data:
    .word 0x00000010
scratch_mem:
    .word 0x00000000