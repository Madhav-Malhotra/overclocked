# rv32ui-p-simple - Simple test that just passes
# Rewritten with proper HTIF support for Spike compatibility
# WARNING: AI WAS USED TO GENERATE THIS TEST

.section .text.init
.globl _start

_start:
    # Simple test - just pass immediately
    fence   iorw, iorw
    addi    x3, x0, 1       # Test passed
    la      t0, tohost
    sw      x3, 0(t0)       # Write to tohost
    ecall
    unimp
