# Template for RV32I instruction tests
# Copy this file and modify for each instruction you want to test
#
# Usage:
#   1. Copy: cp template-test.s test-<instruction>.s
#   2. Edit: Fill in instruction-specific test cases
#   3. Build: make -f Makefile.new test-<instruction>.elf
#   4. Test: spike --isa=rv32i -m0x01000000:0x200000 test-<instruction>.elf

.section .text.init
.globl _start

_start:
    # Test 1: <describe what this test does>
    # Example: ADD x3, x1, x2 where x1=5, x2=7 should give x3=12
    addi    x1, x0, 5           # x1 = 5
    addi    x2, x0, 7           # x2 = 7
    add     x3, x1, x2          # x3 = x1 + x2 = 12
    addi    x4, x0, 12          # x4 = expected result
    bne     x3, x4, fail        # if x3 != 12, fail

    # Test 2: <describe test 2>
    # Add more tests here...

    # Test 3: <describe test 3>
    # Add more tests here...

    # All tests passed
    j       pass

fail:
    # Test failed - gp (x3) contains the test number that failed
    # (Set x3 to test number before branching to fail)
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 93          # Exit code for failure
    sw      a0, 0(t0)
    ecall
    # Infinite loop in case ecall doesn't stop simulation
    j       fail

pass:
    # All tests passed
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 0           # Exit code 0 = success
    sw      a0, 0(t0)
    ecall
    unimp

# Data section (if needed for load/store tests)
.section .data
.align 4

test_data:
    .word 0x12345678
    .word 0xDEADBEEF

# HTIF symbols are provided by the linker script (riscv32.ld)
