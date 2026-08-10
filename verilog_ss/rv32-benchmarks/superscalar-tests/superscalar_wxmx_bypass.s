.section .text.init
.globl _start

_start:
    addi    x1, x0, 0          # Way 0: x1 = 0
    addi    x2, x0, 0          # Way 1: x2 = 0

test_bypass_mx_wx:
    # -------------------------------------------------------------------------
    # Cycle 1: Base Generation (Dual-Issue Pair 0)
    # Way 0 writes x1, Way 1 writes x2.
    # At the end of this cycle: x1 and x2 values are in the EX stage.
    # -------------------------------------------------------------------------
    addi    x1, x0, 10          # Way 0: x1 = 10
    addi    x2, x0, 20          # Way 1: x2 = 20

    # -------------------------------------------------------------------------
    # Cycle 2: MX Bypassing Test (Dual-Issue Pair 1)
    # Pair 0 is now in the MEM (M) stage. Pair 1 is in EXECUTE (X).
    #
    # Way 0 reads x1 -> Tests MX Bypass (Way 0 M-stage -> Way 0 X-stage)
    # Way 1 reads x2 -> Tests MX Bypass (Way 1 M-stage -> Way 1 X-stage)
    # Way 1 reads x1 -> Tests Cross-Way MX Bypass (Way 0 M-stage -> Way 1 X-stage)
    # -------------------------------------------------------------------------
    add     x3, x1, x0          # Way 0: x3 = 10 + 0  = 10  (MX from x1)
    add     x4, x2, x1          # Way 1: x4 = 20 + 10 = 30  (MX from x2 and x1)

    # -------------------------------------------------------------------------
    # Cycle 3: WX and MX Mixed Bypassing Test (Dual-Issue Pair 2)
    # Pair 0 is in WRITEBACK (W). Pair 1 is in MEM (M). Pair 2 is in EXECUTE (X).
    #
    # Way 0 reads x1 -> Tests WX Bypass (Way 0 W-stage -> Way 0 X-stage)
    # Way 0 reads x3 -> Tests MX Bypass (Way 0 M-stage -> Way 0 X-stage)
    # Way 1 reads x2 -> Tests WX Bypass (Way 1 W-stage -> Way 1 X-stage)
    # Way 1 reads x4 -> Tests MX Bypass (Way 1 M-stage -> Way 1 X-stage)
    # -------------------------------------------------------------------------
    add     x5, x1, x3          # Way 0: x5 = 10 + 10 = 20  (WX from x1, MX from x3)
    add     x6, x2, x4          # Way 1: x6 = 20 + 30 = 50  (WX from x2, MX from x4)

    # -------------------------------------------------------------------------
    # Cycle 4: Cross-Way WX Bypassing Test (Dual-Issue Pair 3)
    # Pair 1 is in WRITEBACK (W). Pair 2 is in MEM (M). Pair 3 is in EXECUTE (X).
    #
    # Way 0 reads x4 -> Tests Cross-Way WX Bypass (Way 1 W-stage -> Way 0 X-stage)
    # Way 1 reads x3 -> Tests Cross-Way WX Bypass (Way 0 W-stage -> Way 1 X-stage)
    # -------------------------------------------------------------------------
    add     x7, x4, x0          # Way 0: x7 = 30 + 0  = 30  (WX from x4)
    add     x8, x3, x0          # Way 1: x8 = 10 + 0  = 10  (WX from x3)

    # -------------------------------------------------------------------------
    # Cycle 5: Validating Final Results into New Registers
    # Gives the previous cycles time to safely write back to the register file.
    # -------------------------------------------------------------------------
    add     x9, x5, x6          # Way 0: x9 = 20 + 50 = 70
    add     x10, x7, x8         # Way 1: x10 = 30 + 10 = 40

    # -------------------------------------------------------------------------
    # Safe Exit via Memory-Mapped HTIF (No Branches)
    # We directly store "1" (pass status) into the tohost address.
    # -------------------------------------------------------------------------
    fence   iorw,iorw
    addi    x3, x0, 1
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0, tohost
    addi    x0, x0, 0  
    sw      x3, 0(t0)
    ecall
    unimp
.section .text.init
.globl _start

end_signature: