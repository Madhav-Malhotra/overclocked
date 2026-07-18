# superscalar_war_waw.S
# Focus: WAW (Write-After-Write) and WAR (Write-After-Read) concurrency conflicts

.section .text.init
.globl _start

_start:
    addi    x3, x0, 1          # Fail marker tracker (matches template format)

    # =========================================================================
    # Test 1: WAW Hazard in the Same Issue Cycle
    # Both Way 0 and Way 1 attempt to write to the exact same register (x14).
    # Since the execution is in-order, Way 1 must win. Way 0's write must be
    # suppressed/overwritten so that the final architectural state matches Way 1.
    # Note: Target register changed from x3 to x14 to protect the x3 fail tracker.
    # =========================================================================
    addi    x1, x0, 5
    addi    x2, x0, 10
    addi    x14, x1, 0          # Cycle N: Way 0 (Writes 5 to x14)
    addi    x14, x2, 0          # Cycle N: Way 1 (Writes 10 to x14 - Concurrent WAW)
    
    # Check if Way 1 successfully overwrote Way 0
    addi    x4, x0, 10
    bne     x14, x4, fail

    # =========================================================================
    # Test 2: WAR Hazard across parallel ways
    # Way 0 reads a register (x5), while Way 1 simultaneously overwrites it (x5).
    # Way 0 MUST read the old value of x5 before Way 1's new write destroys it.
    # =========================================================================
    addi    x3, x0, 2          # Fail marker = 2
    addi    x5, x0, 50          # Setup baseline
    addi    x6, x0, 100
    
    add     x7, x5, x0          # Cycle N: Way 0 (Reads x5, should get 50)
    addi    x5, x6, 0           # Cycle N: Way 1 (Overwrites x5 with 100)
    
    # Verify Way 0 grabbed the value *prior* to Way 1's update
    addi    x8, x0, 50
    bne     x7, x8, fail
    
    # Verify Way 1's update eventually committed to the RF
    addi    x9, x0, 100
    bne     x5, x9, fail

    # =========================================================================
    # Test 3: Structural Multi-Port Memory-to-Register WAW
    # A load instruction in Way 0 finishes at the same time an ALU operation
    # in Way 1 finishes, both targeting the same destination register.
    # =========================================================================
    addi    x3, x0, 3          # Fail marker = 3
    la      x11, val_block
    addi    x12, x0, 999
    
    lw      x13, 0(x11)         # Cycle N: Way 0 (Loads 7 into x13)
    addi    x13, x12, 0         # Cycle N: Way 1 (Writes 999 into x13)
    
    # Due to in-order semantics, Way 1's write must stick if they complete 
    # sequentially, or the system must stall to ensure chronological order.
    bne     x13, x12, fail

    # All tests passed
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
    addi    x3,x0,1             # HTIF standard success return value
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
val_block:
    .word 7