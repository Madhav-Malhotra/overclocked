# RISC-V Benchmarks for ECE 320

This directory contains benchmarks for testing and verifying RV32I processor implementations. Benchmarks can be run both on your custom processor and on Spike (the official RISC-V ISS - Instruction Set Simulator) to verify correctness.

## Repository Structure

```
rv32-benchmarks/
├── individual-instructions/    # Single-instruction tests (rv32ui-p-*.s)
├── simple-programs/            # C program benchmarks (SimpleAdd, BubbleSort, etc.)
├── riscv32.ld                  # Linker script for ISS compatibility
├── start.s                     # Minimal startup code for C programs
└── README.md                   # This file
```

**Key Files:**
- `.x` - Executable binary files for your processor
- `.c` - C source code (simple-programs only)
- `.s` - Assembly source code
- `.trace` - Spike execution traces (shows commits and register writes)

---

## Running Benchmarks

### Quick Start: Running All Benchmarks

From the verification scripts directory, run the full pipeline:

```bash
cd verilog/verif/scripts
make run_all_benchmarks
```

This single command:
1. Compiles all `.s`/`.c` sources into `.elf` (for Spike) and `.x` (for the processor)
2. Runs all `.x` benchmarks on your processor
3. Generates Spike commit traces for each benchmark
4. Compares processor register writes against Spike
5. Prints PASS/FAIL summary

### Running Individual Benchmarks

**By path:**
```bash
cd verilog/verif/scripts
make run MEM_PATH=/path/to/benchmark.x
```

**By name:**
```bash
cd verilog/verif/scripts
make run_bench BENCH=rv32ui-p-add
```

### Running Benchmarks on Spike (Manual)

To manually build and run on Spike:

```bash
# Individual instructions
cd verilog/rv32-benchmarks/individual-instructions
make -f Makefile.new all                    # Build all .elf + .x from *.s
spike --isa=rv32g -m0x01000000:0x200000 rv32ui-p-add.elf

# Simple programs
cd verilog/rv32-benchmarks/simple-programs
make -f Makefile.iss all                    # Build all .iss.elf + .x from *.c
spike --isa=rv32g -m0x01000000:0x200000 SimpleAdd.iss.elf
```

Note: `make run_all_benchmarks` does all of this automatically.

**Important Spike flags:**
- `--isa=rv32g` - Use RV32G ISA (I+M+A+F+D superset; accepts binaries from any standard 32-bit extension)
- `-m0x01000000:0x200000` - Set memory base address to 0x01000000 with 2MB size (matches processor)

### Interpreting Results

**Pass/Fail Convention:**
- **Assembly tests (.s files)**: Write result to `tohost` symbol, then execute `ecall`
  - `tohost = 1` → Test PASSED
  - `tohost = <other>` → Test FAILED (value indicates test number that failed)
- **C programs**: Return value from `main()`
  - `return 1` → PASSED
  - `return 0` → FAILED

**Trace Comparison:**
```
PASS: rv32ui-p-add (320 commits)   # Processo r register writes match Spike
FAIL: rv32ui-p-sub (3 mismatches, 320 commits)  # Mismatch detected
```

**Diff files** are written to `verilog/verif/diffs/spike/<benchmark>.diff`:
- Shows per-commit comparison of processor vs. Spike register writes
- Each row: `[W]` commit index, status (OK/MISMATCH), PROC and SPIKE (pc, rd, value)
- Mismatches indicate your processor computed different register values than expected

---

## Creating Benchmarks

### Creating Assembly (.s) Benchmarks

Assembly benchmarks are ideal for testing specific instructions or instruction sequences.

**1. Use the template:**
```bash
cd verilog/rv32-benchmarks/individual-instructions
cp template-test.s test-myinstruction.s
```

**2. Edit your test file:**

The template has these key sections:

```assembly
.section .text.init
.globl _start
_start:
    # Test 1: <describe what you're testing>
    addi    x1, x0, 5           # x1 = 5
    addi    x2, x0, 7           # x2 = 7
    add     x3, x1, x2          # x3 = x1 + x2 = 12
    addi    x4, x0, 12          # x4 = expected result
    addi    x5, x0, 1           # x5 = test number (for debugging)
    bne     x3, x4, fail        # if x3 != 12, fail

    # Test 2: <another test case>
    # ...

    j       pass                # All tests passed

fail:
    # x5 contains the failing test number
    fence   iorw, iorw
    la      t0, tohost
    sw      x5, 0(t0)           # Write test number to tohost
    ecall                       # Signal exit
    j       fail

pass:
    # All tests passed
    fence   iorw, iorw
    la      t0, tohost
    addi    a0, x0, 1           # Exit code 1 = success
    sw      a0, 0(t0)           # Write to tohost
    ecall                       # Signal exit
    unimp
```

**3. Add data sections (if needed for load/store tests):**
```assembly
.section .data
.align 4
test_data:
    .word 0x12345678
    .half 0x00FF
    .byte 0xAB
```

**4. Build and test:**
```bash
make -f Makefile.new test-myinstruction.elf test-myinstruction.x
spike --isa=rv32g -m0x01000000:0x200000 test-myinstruction.elf
# Or just run the full pipeline to pick it up automatically:
cd ../../verif/scripts && make run_all_benchmarks
```

### Creating C Benchmarks

C benchmarks are ideal for testing higher-level functionality like algorithms.

**1. Write your C program:**

```c
#include "pass_fail.h"

int main() {
    int a = 3;
    int b = 2;
    int c = a + b;

    if (c == 5) {
        return pass();  // Return 1 for success
    } else {
        return fail();  // Return 0 for failure
    }
}

int pass() {
    return 1;
}

int fail() {
    return 0;
}
```

**2. Include the pass_fail.h header:**
```c
#ifndef _PASS_FAIL_H_
int pass();
int fail();
#endif
```

**3. Build for ISS (Spike):**
```bash
cd verilog/rv32-benchmarks/simple-programs
make -f Makefile.iss MyProgram.iss.elf
```

**4. Test on Spike:**
```bash
spike --isa=rv32g -m0x01000000:0x200000 MyProgram.iss.elf
```

**Compiler Flags (from Makefile.iss):**
- `-march=rv32i` - Target RV32I instruction set
- `-mabi=ilp32` - Use 32-bit integer ABI
- `-nostdlib` - Don't link standard library (bare-metal)
- `-O2` - Enable optimizations

**Restrictions:**
- No standard library functions (`printf`, `malloc`, etc.)
- No floating-point operations
- No system calls except `ecall` (handled by startup code)
- Limited memory (1MB by default)

**Data Sections:**
C programs can use arrays and global variables:
```c
int test_array[] = {1, 2, 3, 4, 5};  // Placed in .data section
int result;                          // Placed in .bss section
```

The linker script (`riscv32.ld`) and startup code (`start.s`) handle:
- Stack pointer initialization
- Calling `main()`
- Returning result via HTIF (tohost)

---

## Troubleshooting

**"Benchmark not found"**
- Use `make list_benchmarks` to see available tests
- Check that you're using the correct path or benchmark name

**"Simulation timeout"**
- Increase timeout: `make run TIMEOUT=100000 MEM_PATH=...`
- Check if your processor is stuck in an infinite loop

**"Trace mismatches on don't-care fields"**
- Use filtered diffs: `python3 cmp_sim_trace.py <test> <golden> <output> --filter "[W]"`
- Only writeback (`[W]`) lines with `write_enable=1` matter for correctness

**"Spike: devices overlap" error**
- This means memory regions conflict (shouldn't happen with provided linker scripts)
- Ensure you're using `-m0x01000000:0x200000` flag with Spike

**"Unaligned memory access" errors**
- Ensure data sections are properly aligned: `.align 4`
- Use correct load/store instructions (`lw`/`sw` for words, `lh`/`sh` for halfwords, `lb`/`sb` for bytes)

**C program doesn't exit correctly**
- Ensure `main()` returns `pass()` or `fail()` (defined in your code)
- Check that `start.s` is linked (it handles the startup and HTIF signaling)

---

## Advanced Topics

For detailed information about the ISS architecture, linker scripts, startup code, and build system, see:

**[ISS_ARCHITECTURE.md](ISS_ARCHITECTURE.md)**

This document explains:
- Linker script structure and memory layout
- HTIF (Host-Target Interface) protocol
- Startup code execution flow
- Makefile build process
- ELF file format and sections
- How Spike interprets test completion

---

## Compiling Your Own Toolchain

If you need to build the RISC-V toolchain from scratch:

```bash
git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv --with-arch=rv32i --with-abi=ilp32
make
```

**Flags:**
- `--with-arch=rv32i` - Base RV32I instruction set
- `--with-abi=ilp32` - 32-bit integer ABI (no floating-point)
- `--prefix=/opt/riscv` - Install location

The toolchain includes:
- `riscv32-unknown-elf-gcc` - Compiler
- `riscv32-unknown-elf-objdump` - Disassembler
- `riscv32-unknown-elf-objcopy` - Binary converter
- And more tools for bare-metal RISC-V development
