# Simple LH (Load Halfword) instruction test
# Tests loading signed 16-bit values from memory

.section .text.init
.globl _start

_start:
    # Test 1: Load positive halfword (0x00FF)
    la      x1, test_data
    lh      x2, 0(x1)
    addi    x3, x0, 0xFF
    addi    x5, x0, 1           # Test number
    bne     x2, x3, fail

    # Test 2: Load negative halfword (0xFF00 = -256)
    la      x1, test_data
    lh      x2, 2(x1)
    addi    x3, x0, -256
    addi    x5, x0, 2           # Test number
    bne     x2, x3, fail

    # Test 3: Load from offset
    la      x1, test_data
    lh      x2, 4(x1)
    lui     x3, 0x1
    addi    x3, x3, -16         # 0x0FF0
    addi    x5, x0, 3           # Test number
    bne     x2, x3, fail

    # Test 4: Load with negative offset
    la      x1, test_data
    addi    x1, x1, 6
    lh      x2, -2(x1)
    lui     x3, 0x1
    addi    x3, x3, -16         # 0x0FF0
    addi    x5, x0, 4           # Test number
    bne     x2, x3, fail

    # All tests passed
    j       pass

fail:
    # x5 contains the failing test number
    fence   iorw, iorw
    la      t0, tohost
    sw      x5, 0(t0)
    ecall
    j       fail

pass:
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 1           # Exit code 1 = test passed
    sw      a0, 0(t0)
    ecall
    unimp

# Test data section
.section .data
.align 4

test_data:
    .half 0x00FF        # Offset 0: positive halfword (255)
    .half 0xFF00        # Offset 2: negative halfword (-256)
    .half 0x0FF0        # Offset 4: 4080
    .half 0xF00F        # Offset 6: -4081 (signed)
