.section .text.init
.globl _start

_start:
    # --- ORIGINAL TESTS (Converted to branchless sequential format) ---
    addi	x1, x0, 0
    addi	x2, x0, 0
    add		x30, x1, x2     # x30 = 0

    # test_3
    addi	x1, x0, 1
    addi	x2, x0, 1
    add		x28, x1, x2     # x28 = 2

    # test_4
    addi	x1, x0, 3
    addi	x2, x0, 7
    add		x27, x1, x2     # x27 = 10

    # test_5
    addi	x1, x0, 0
    lui		x2, 0xffff8
    add		x26, x1, x2     # x26 = 0xffff8000

    # test_6
    lui		x1, 0x80000
    addi	x2, x0, 0
    add		x25, x1, x2     # x25 = 0x80000000

    # test_7
    lui		x1, 0x80000
    lui		x2, 0xffff8
    add		x24, x1, x2     # x24 = 0x7fff8000

    # test_8
    addi	x1, x0, 0
    lui		x2, 0x8
    addi	x2, x2, -1
    add		x23, x1, x2     # x23 = 0x00007fff

    # test_9
    lui		x1, 0x80000
    addi	x1, x1, -1
    addi	x2, x0, 0
    add		x22, x1, x2     # x22 = 0x7fffffff

    # test_10
    lui		x1, 0x80000
    addi	x1, x1, -1
    lui		x2, 0x8
    addi	x2, x2, -1
    add		x21, x1, x2     # x21 = 0x80007ffe

    # test_11
    lui		x1, 0x80000
    lui		x2, 0x8
    addi	x2, x2, -1
    add		x20, x1, x2     # x20 = 0x80007fff

    # test_12
    lui		x1, 0x80000
    addi	x1, x1, -1
    lui		x2, 0xffff8
    add		x19, x1, x2     # x19 = 0x7fff7fff

    # test_13
    addi	x1, x0, 0
    addi	x2, x0, -1
    add		x18, x1, x2     # x18 = -1

    # test_14
    addi	x1, x0, -1
    addi	x2, x0, 1
    add		x17, x1, x2     # x17 = 0

    # test_15
    addi	x1, x0, -1
    addi	x2, x0, -1
    add		x16, x1, x2     # x16 = -2

    # test_16
    addi	x1, x0, 1
    lui		x2, 0x80000
    addi	x2, x2, -1
    add		x14, x1, x2     # x14 = 0x80000000

    # test_17
    addi	x1, x0, 13
    addi	x2, x0, 11
    add		x13, x1, x2     # x13 = 24

    # test_18
    addi	x1, x0, 14
    addi	x2, x0, 11
    add		x12, x1, x2     # x12 = 25

    # test_19
    addi	x1, x0, 13
    add		x11, x1, x1     # x11 = 26


    # --- SUPERSCALAR STALL & BYPASSING EDGE-CASES ---

    # Test 39: Way 1 Stalls (RAW on x2), Way 0 clears out to EX. Fetch freezes.
    # [Pair]
    addi    x1, x0, 10      # Way 0
    addi    x2, x0, 5       # Way 1
    # [Pair]
    addi    x5, x0, 20      # Way 0 -> No hazard, clears to EX.
    add     x6, x2, x1      # Way 1 -> Stalls on x2 from prior lane.

    # Test 40: Intra-Packet RAW Dependency (Bypassing within the same Fetch Pair)
    # [Pair]
    addi    x7, x0, 12      # Way 0: Write x7
    add     x8, x7, x7      # Way 1: Read x7 (Requires intra-packet bypass/stall)

    # Test 41: Dual-Lane Cascading RAW Hazard
    # [Pair]
    addi    x9, x0, 2       # Way 0
    addi    x31, x0, 3      # Way 1
    # [Pair]
    add     x29, x31, x9    # Way 0 -> Depends on x31 (Pair 1, Way 1) -> Should be 5
    add     x10, x29, x9    # Way 1 -> Depends on x29 (Pair 2, Way 0) -> Should be 7

    # Test 42: Way 0 Stall Forces Way 1 Cascade Freeze (In-Order Invariant)
    # [Pair]
    addi    x15, x0, 50     # Way 0
    addi    x0, x0, 0       # Way 1
    # [Pair]
    add     x15, x15, x15   # Way 0 -> RAW Hazard on x15 (Forces Way 0 Stall)
    addi    x4, x0, 99      # Way 1 -> Independent, but must hold state because Way 0 is stuck

    # Test 43: Intra-Packet WAW Hazard Resolution
    # [Pair]
    addi    x15, x0, 100    # Way 0 (Older write)
    addi    x15, x0, 200    # Way 1 (Younger write - must overwrite Way 0)

    # Test 44: Hardwired x0 Hazard Prevention
    # [Pair]
    add     x0, x1, x2      # Way 0 -> Discard write to x0
    addi    x0, x0, 50      # Way 1 -> Discard write to x0
    # [Pair]
    add     x29, x0, x0     # Way 0 -> Must evaluate to 0 immediately, not forward old results
    addi    x0, x0, 0       # Way 1


    # --- ZERO-BRANCH SIGNATURE AGGREGATION ---
    add     x3, x0, x30     # x30 baseline (0)
    xor     x3, x3, x28     # test_3  (^ 2)
    xor     x3, x3, x27     # test_4  (^ 10)
    xor     x3, x3, x26     # test_5  (^ 0xffff8000)
    xor     x3, x3, x25     # test_6  (^ 0x80000000)
    xor     x3, x3, x24     # test_7  (^ 0x7fff8000)
    xor     x3, x3, x23     # test_8  (^ 0x00007fff)
    xor     x3, x3, x22     # test_9  (^ 0x7fffffff)
    xor     x3, x3, x21     # test_10 (^ 0x80007ffe)
    xor     x3, x3, x20     # test_11 (^ 0x80007fff)
    xor     x3, x3, x19     # test_12 (^ 0x7fff7fff)
    xor     x3, x3, x18     # test_13 (^ -1)
    xor     x3, x3, x17     # test_14 (^ 0)
    xor     x3, x3, x16     # test_15 (^ -2)
    xor     x3, x3, x14     # test_16 (^ 0x80000000)
    xor     x3, x3, x13     # test_17 (^ 24)
    xor     x3, x3, x12     # test_18 (^ 25)
    xor     x3, x3, x11     # test_19 (^ 26)
    
    # Accumulate Superscalar specific results
    xor     x3, x3, x5      # test_39 Way 0 (^ 20)
    xor     x3, x3, x6      # test_39 Way 1 (^ 15)
    xor     x3, x3, x8      # test_40 Way 1 (^ 24)
    xor     x3, x3, x10     # test_41 Cascade (^ 7)
    xor     x3, x3, x4      # test_42 Freeze (^ 99)
    xor     x3, x3, x15     # test_43 WAW Overwrite (^ 200)
    xor     x3, x3, x29     # test_44 Zero Register Check (^ 0)

    # Perfect execution math results transformation to inject exact success value:
    # Target value to clean is 0x00007F1E. We construct it inside boundaries:
    lui     x1, 8           # x1 = 0x00008000
    addi    x1, x1, -226    # x1 = 0x00008000 - 226 = 0x00007F1E
    xor     x3, x3, x1      # If x3 was correct, x3 becomes 0
    xori    x3, x3, 1       # If x3 was 0, it becomes 1 (Pass status code for Spike)

    fence   iorw, iorw
    # HTIF: Write test result to tohost for Spike compatibility
    la      t0, tohost
    addi    x0, x0, 0  
    sw      x3, 0(t0)
    ecall
    unimp

.section .text.init
.globl _start

end_signature: