# superscalar_stalling_extreme.S
# Focus: Inter-way structural blocks, back-to-back multi-cycle structural stalls

.section .text.init
.globl _start

_start:
    addi    x3, x0, 1          # Fail marker tracker (matches template format)

    # =========================================================================
    # Test 1: Inter-Way RAW Dependency (No Same-Stage Bypassing)
    # Way 1 strictly depends on Way 0 fetched in the same cycle.
    # Since X->X bypass is missing, the hazard unit MUST split the pair:
    # Way 0 issues immediately, Way 1 stalls and issues next cycle in Way 0.
    # =========================================================================
    addi    x1, x0, 15          # Cycle N: Way 0
    add     x2, x1, x1          # Cycle N: Way 1 (RAW on x1. Must split/stall!)
    
    addi    x9, x0, 30          # Validation target (using x9 so we don't clobber x3 tracker)
    bne     x2, x9, fail

    # =========================================================================
    # Test 2: Double-Load Structural back-to-back Stall
    # If your pipeline has limited memory ports, issuing two loads back-to-back
    # or concurrently can cause structural thrashing.
    # =========================================================================
    addi    x3, x0, 2          # Fail marker = 2
    la      x4, data_block
    
    lw      x5, 0(x4)           # Cycle N: Way 0 
    lw      x6, 4(x4)           # Cycle N: Way 1 
    # The following instructions depend on BOTH loads. This creates a dense hazard matrix.
    add     x7, x5, x6          # Cycle N+1: Way 0 (Must stall for data availability)
    nop                         # Cycle N+1: Way 1
    
    addi    x8, x0, 3
    bne     x7, x8, fail

    # =========================================================================
    # Test 3: The "Cascading Waterfall" Stall
    # A chain of dependent instructions where each step forces a split/stall due
    # to the lack of inter-way same-stage bypassing.
    # =========================================================================
    addi    x3, x0, 3          # Fail marker = 3
    addi    x20, x0, 1          # Way 0
    add     x21, x20, x20       # Way 1 -> Depends on x20 (Forces split)
    add     x22, x21, x20       # Way 0 -> Depends on x21
    add     x23, x22, x20       # Way 1 -> Depends on x22 (Forces split)
    
    addi    x24, x0, 4
    bne     x23, x24, fail

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
data_block:
    .word 1
    .word 2