.section .text.init
.globl _start

_start:
test_superscalar_branchless:
    # -------------------------------------------------------------------------
    # Cycle 1: Dual-Issue Pair 0
    # Way 0 writes x1, Way 1 writes x2. 
    # -------------------------------------------------------------------------
    addi    x1, x0, 10
    addi    x2, x0, 20

    # -------------------------------------------------------------------------
    # Cycle 2: Dual-Issue Pair 1
    # Way 0 writes x3, Way 1 writes x4.
    # -------------------------------------------------------------------------
    addi    x3, x0, 30
    addi    x4, x0, 40

    # -------------------------------------------------------------------------
    # Cycle 3: Dual-Issue Pair 2
    # Way 0 writes x5, Way 1 writes x6.
    # -------------------------------------------------------------------------
    addi    x5, x0, 50
    addi    x6, x0, 60

    # -------------------------------------------------------------------------
    # Cycle 4: Dual-Issue Pair 3
    # Way 0 writes x7, Way 1 writes x8.
    # -------------------------------------------------------------------------
    addi    x7, x0, 70
    addi    x8, x0, 80

    # -------------------------------------------------------------------------
    # Safe Exit via Memory-Mapped HTIF (No Branches)
    # We directly store "1" (pass status) into the tohost address.
    # -------------------------------------------------------------------------
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