# ISS Architecture Deep Dive

This document provides a detailed explanation of the Instruction Set Simulator (ISS) infrastructure. It covers the key files, their purpose, and how they work together to enable testing RISC-V programs on both Spike (the reference simulator) and your custom processor.

**Target Audience:** Computer engineering undergraduate students who want to understand or modify the build system, linker scripts, and startup code.

**Prerequisites:** Basic understanding of C programming, assembly language, and compilation process (source → assembly → object → executable).

---

## Table of Contents

1. [What is an ISS?](#what-is-an-iss)
2. [Key Concepts](#key-concepts)
3. [File-by-File Breakdown](#file-by-file-breakdown)
   - [riscv32.ld - Linker Script](#riscv32ld---linker-script)
   - [start.s - Startup Code](#starts---startup-code)
   - [Makefile.iss (simple-programs)](#makefileiss-simple-programs)
   - [Makefile.new (individual-instructions)](#makefilenew-individual-instructions)
   - [ece320.ld - Legacy Linker Script](#ece320ld---legacy-linker-script)
4. [Build Process Flow](#build-process-flow)
5. [Memory Layout](#memory-layout)
6. [HTIF Protocol](#htif-protocol)
7. [Common Modifications](#common-modifications)

---

## What is an ISS?

An **ISS (Instruction Set Simulator)** is a software program that simulates the execution of processor instructions. It acts as a "virtual processor" that runs on your computer.

**Spike** is the official RISC-V ISS - it's the "golden reference" implementation that defines correct behavior for RISC-V instructions. When we test your custom processor, we compare its output to Spike's output to verify correctness.

**Why use an ISS?**
- **Debugging:** Run programs step-by-step, inspect registers and memory
- **Validation:** Compare your processor's behavior against the reference
- **Development:** Test software before hardware is ready
- **Portability:** Run RISC-V programs on any computer (x86, ARM, etc.)

---

## Key Concepts

### ELF Files

**ELF (Executable and Linkable Format)** is the standard file format for executables on Linux and RISC-V systems.

An ELF file contains:
- **Sections:** Code (`.text`), data (`.data`), uninitialized data (`.bss`)
- **Symbols:** Labels like `_start`, `main`, `tohost`
- **Headers:** Metadata about the file structure and how to load it
- **Relocation info:** How to adjust addresses when loading at different base addresses

When you compile a `.c` or `.s` file, the toolchain produces an ELF file (`.elf` extension).

### Memory Sections

Programs are organized into **sections** that serve different purposes:

| Section | Purpose | Example Contents |
|---------|---------|------------------|
| `.text` | Executable code (instructions) | `addi x1, x0, 5` |
| `.data` | Initialized global/static variables | `int x = 42;` → `.word 42` |
| `.bss` | Uninitialized global/static variables | `int y;` → no data, just reserved space |
| `.rodata` | Read-only data (constants, strings) | `const char* s = "Hello";` |

The **linker script** controls where these sections are placed in memory.

### Linker and Linker Scripts

The **linker** is a program (part of the toolchain) that combines multiple object files (`.o`) into a single executable (`.elf`).

A **linker script** (`.ld` file) is a configuration file that tells the linker:
- Where to place sections in memory (addresses)
- How to arrange sections (order)
- What symbols to define (e.g., `tohost`, `_stack_top`)

Without a linker script, the linker uses default rules (which may not match your processor's memory layout).

### HTIF (Host-Target Interface)

**HTIF** is a simple communication protocol between a RISC-V program (target) and the host computer running the simulator.

It uses two special memory locations:
- **`tohost`** - Target writes to this address to send data to host
- **`fromhost`** - Host writes here to send data to target

For our purposes, HTIF is used to signal test completion:
1. Test writes result to `tohost` (1 = pass, other = fail)
2. Test executes `ecall` instruction
3. Spike detects the `ecall`, reads `tohost`, and exits with the result

**Important:** The `tohost` and `fromhost` symbols must be defined by the linker script and aligned on 8-byte boundaries.

### Base Address

The **base address** is the memory address where your program starts. For this course:
- **Processor base address:** `0x01000000` (16MB mark)
- **Memory size:** 1MB (configurable)
- **Stack top:** `0x01000000 + 1MB = 0x01100000`

All addresses in your program are relative to this base address.

### Toolchain Prefixes

RISC-V toolchain binaries have prefixes to distinguish them from native tools:

| Prefix | Description |
|--------|-------------|
| `riscv32-unknown-elf-` | 32-bit RISC-V, bare-metal (no OS) |
| `riscv64-unknown-elf-` | 64-bit RISC-V, bare-metal |

Examples:
- `riscv32-unknown-elf-gcc` - Compiler for 32-bit RISC-V
- `riscv64-unknown-elf-gcc` - Can compile 32-bit with `-march=rv32i`

We use `riscv64-unknown-elf-gcc -march=rv32i` because it's more commonly installed.

---

## File-by-File Breakdown

### riscv32.ld - Linker Script

**Location:** `verilog/rv32-benchmarks/riscv32.ld`

**Purpose:** Defines memory layout for programs compatible with both Spike and your processor.

**Full File:**
```ld
OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  ram (rwx) : ORIGIN = 0x01000000, LENGTH = 1M
}

SECTIONS
{
  .text : {
    *(.text.init)
    *(.text)
    *(.text.*)
  } > ram

  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > ram

  .data : {
    *(.data)
    *(.data.*)
  } > ram

  .bss : {
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } > ram

  .htif : ALIGN(8) {
    . = ALIGN(8);
    tohost = .;
    . = . + 8;
    fromhost = .;
    . = . + 8;
  } > ram

  _stack_top = ORIGIN(ram) + LENGTH(ram);
}
```

**Line-by-Line Explanation:**

#### Header Section
```ld
OUTPUT_ARCH("riscv")
ENTRY(_start)
```
- **`OUTPUT_ARCH("riscv")`** - Tells the linker this ELF file is for RISC-V architecture (not x86, ARM, etc.)
- **`ENTRY(_start)`** - Declares `_start` as the entry point (first instruction executed)
  - When the processor boots, program counter (PC) is set to the address of `_start`
  - For assembly tests, `_start` is in your `.s` file
  - For C programs, `_start` is in `start.s` (which then calls `main`)

#### Memory Regions
```ld
MEMORY
{
  ram (rwx) : ORIGIN = 0x01000000, LENGTH = 1M
}
```
- **`MEMORY { ... }`** - Defines available memory regions
- **`ram (rwx)`** - Names this region "ram" with permissions:
  - `r` = readable
  - `w` = writable
  - `x` = executable (can contain code)
- **`ORIGIN = 0x01000000`** - Memory starts at address `0x01000000` (16MB)
  - This matches your processor's `BASE_ADDR` parameter
  - Spike requires `-m0x01000000:0x200000` to create memory at this address
- **`LENGTH = 1M`** - Memory is 1 megabyte (1048576 bytes)
  - Matches default processor `MEM_DEPTH = 1048576`

#### Sections Placement
```ld
SECTIONS
{
  .text : {
    *(.text.init)
    *(.text)
    *(.text.*)
  } > ram
```
- **`SECTIONS { ... }`** - Defines how to arrange sections in memory
- **`.text : { ... } > ram`** - Place `.text` section in `ram` region
- **`*(.text.init)`** - First, include all `.text.init` sections from input files
  - `*` means "from all input files"
  - `.text.init` is where `_start` is placed (startup code)
  - This ensures startup code is at the beginning (lowest address)
- **`*(.text)`** - Then include all `.text` sections (main code)
- **`*(.text.*)`** - Finally include all `.text.something` sections
  - Matches compiler-generated sections like `.text.main`, `.text.startup`

**Why order matters:** The processor starts executing at the base address, so startup code must be first.

```ld
  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > ram
```
- **`.rodata`** - Read-only data section
  - Contains string constants like `"Hello, world!"`
  - Contains `const` variables in C
- Placed after `.text` section in `ram`

```ld
  .data : {
    *(.data)
    *(.data.*)
  } > ram
```
- **`.data`** - Initialized data section
  - Contains global variables with initial values: `int x = 42;`
  - Contains arrays with initial data: `int arr[] = {1, 2, 3};`
- Placed after `.rodata` section

```ld
  .bss : {
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } > ram
```
- **`.bss`** - "Block Started by Symbol" (historical name)
  - Contains uninitialized global variables: `int y;`
  - Contains zero-initialized data: `int z = 0;`
  - Doesn't take space in the ELF file (just reserves memory at runtime)
- **`*(COMMON)`** - Also include COMMON symbols (uninitialized globals from multiple files)

#### HTIF Symbols
```ld
  .htif : ALIGN(8) {
    . = ALIGN(8);
    tohost = .;
    . = . + 8;
    fromhost = .;
    . = . + 8;
  } > ram
```
This is the most important section for test signaling!

- **`.htif : ALIGN(8)`** - Create `.htif` section, aligned on 8-byte boundary
- **`. = ALIGN(8);`** - Current location pointer (`.`) aligned to 8 bytes
  - HTIF requires 8-byte alignment for 64-bit operations
  - Example: If current location is `0x01000105`, align to `0x01000108`
- **`tohost = .;`** - Define symbol `tohost` at current location
  - This is where tests write their result
  - Spike monitors this address
- **`. = . + 8;`** - Advance location by 8 bytes (64 bits)
  - Reserves space for `tohost` (even though we only write 32 bits, HTIF uses 64)
- **`fromhost = .;`** - Define symbol `fromhost` 8 bytes after `tohost`
  - Not used in our tests, but required by HTIF protocol
- **`. = . + 8;`** - Reserve 8 bytes for `fromhost`

**Result:** 16 bytes of memory reserved for HTIF communication:
```
Address        | Symbol    | Purpose
---------------|-----------|------------------------
tohost         | (8 bytes) | Test → Spike communication
tohost + 8     | fromhost  | Spike → Test communication (unused)
```

#### Stack Pointer
```ld
  _stack_top = ORIGIN(ram) + LENGTH(ram);
}
```
- **`_stack_top`** - Define symbol for top of stack
- **`ORIGIN(ram)`** - Base address: `0x01000000`
- **`LENGTH(ram)`** - Memory size: `1048576` bytes (1MB)
- **Result:** `_stack_top = 0x01000000 + 0x100000 = 0x01100000`

**Why this value?** The stack grows downward (toward lower addresses):
```
0x01100000  ← _stack_top (stack starts here, empty)
           |
           v  (stack grows down as you push data)
0x01000000  ← Base address (code, data here)
```

The startup code (`start.s`) loads this value into the stack pointer register (`sp`/`x2`).

---

### start.s - Startup Code

**Location:** `verilog/rv32-benchmarks/start.s`

**Purpose:** Minimal startup code that initializes the stack and calls `main()` for C programs.

**Full File:**
```assembly
/* Minimal startup code for RISC-V bare-metal programs */

.section .text.init
.globl _start
_start:
    /* Initialize stack pointer to end of RAM */
    lui sp, %hi(_stack_top)
    addi sp, sp, %lo(_stack_top)

    /* Call main function */
    call main

    /* main returned a value in a0 (0=fail, 1=pass) */
    /* Write result to tohost and signal Spike to exit */
    la t0, tohost
    sw a0, 0(t0)
    ecall           /* Tell Spike to stop simulation */

    /* Safety fallback - should never reach here */
_hang:
    j _hang
```

**Line-by-Line Explanation:**

#### Section Directive
```assembly
.section .text.init
```
- **`.section .text.init`** - Place following code in `.text.init` section
- Linker script puts `.text.init` first, so this code executes first

#### Entry Point
```assembly
.globl _start
_start:
```
- **`.globl _start`** - Make `_start` symbol visible to linker (global scope)
  - Without this, linker can't find the entry point
- **`_start:`** - Label marking the entry point
  - Linker script declares `ENTRY(_start)`, so PC starts here

#### Stack Initialization
```assembly
    lui sp, %hi(_stack_top)
    addi sp, sp, %lo(_stack_top)
```
This loads `_stack_top` address into stack pointer register (`sp` = `x2`).

- **`sp`** - Stack pointer register (register `x2` in RISC-V)
- **`_stack_top`** - Symbol defined in linker script (`0x01100000`)

**Why two instructions?** RISC-V uses 32-bit instructions, but addresses are 32-bit values. You can't fit a 32-bit address in a 32-bit instruction that also needs to encode the operation and register!

**Solution:** Split address into upper and lower 20/12 bits:
- **`lui sp, %hi(_stack_top)`** - Load Upper Immediate
  - `%hi(_stack_top)` = upper 20 bits of address (`0x01100` in our case)
  - Loads this into upper 20 bits of `sp`, setting lower 12 bits to 0
  - Result: `sp = 0x01100000`
- **`addi sp, sp, %lo(_stack_top)`** - Add lower 12 bits
  - `%lo(_stack_top)` = lower 12 bits of address (`0x000` in our case)
  - Adds this to `sp`
  - Result: `sp = 0x01100000 + 0 = 0x01100000`

**Example with non-zero lower bits (address `0x01234ABC`):**
```assembly
lui  sp, 0x01235      # sp = 0x01235000 (upper 20 bits, lower 12 bits = 0)
addi sp, sp, -1348    # sp = 0x01235000 + 0xABC (sign-extended) = 0x01234ABC
```
The `%hi` and `%lo` macros handle sign-extension automatically.

#### Call Main
```assembly
    call main
```
- **`call main`** - Pseudo-instruction that expands to:
  ```assembly
  auipc ra, %pcrel_hi(main)    # Load upper bits of PC-relative address
  jalr  ra, %pcrel_lo(main)(ra) # Jump and link to main
  ```
- **Effect:**
  1. Saves return address in `ra` register (`x1`)
  2. Jumps to `main` function
  3. When `main` returns (executes `ret`), execution continues at next instruction

**Return value:** By RISC-V calling convention, `main()` returns value in register `a0` (`x10`).

#### HTIF Exit Sequence
```assembly
    la t0, tohost
    sw a0, 0(t0)
    ecall
```
- **`la t0, tohost`** - Load Address pseudo-instruction
  - Expands to `lui`/`addi` sequence (like stack initialization)
  - Loads address of `tohost` symbol into `t0` register
- **`sw a0, 0(t0)`** - Store Word
  - Stores 32-bit value from `a0` (return value from `main`) to memory at address `t0 + 0`
  - This writes the test result to the `tohost` location
- **`ecall`** - Environment Call instruction
  - Signals to Spike: "Test is done, check `tohost` for result"
  - Spike reads `tohost`, uses value as exit code (1 = pass, 0 = fail)

**Why write before ecall?** The processor executes these instructions sequentially. If you `ecall` before writing to `tohost`, Spike will read garbage data.

#### Safety Fallback
```assembly
_hang:
    j _hang
```
- **`j _hang`** - Jump to self (infinite loop)
- **Purpose:** If `ecall` doesn't stop simulation, prevent processor from executing random memory
- In Spike, this is never reached (ecall exits)
- In your processor (Verilator), timeout will trigger first

---

### Makefile.iss (simple-programs)

**Location:** `verilog/rv32-benchmarks/simple-programs/Makefile.iss`

**Purpose:** Build C programs into ISS-compatible ELF files for Spike.

**Full File:**
```makefile
# Toolchain
RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJDUMP = $(RISCV_PREFIX)objdump

# Compiler flags
CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -O2
LDFLAGS = -T../riscv32.ld

# Startup code
STARTUP = ../start.s

# Source files
SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=.iss.elf)

# Default target
all: $(TARGETS)
	@echo ""
	@echo "Built $(words $(TARGETS)) ISS-compatible benchmarks"
	@echo "Run with: spike --isa=rv32i -m0x01000000:0x200000 <file>.iss.elf"

# Pattern rule to build .iss.elf from .c
%.iss.elf: %.c $(STARTUP)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(STARTUP) $<

# Generate disassembly
%.dis: %.iss.elf
	$(OBJDUMP) -d $< > $@

# Clean
clean:
	rm -f *.iss.elf *.dis

# Build with disassembly
debug: $(TARGETS) $(TARGETS:.iss.elf=.dis)

.PHONY: all clean debug
```

**Key Sections Explained:**

#### Toolchain Setup
```makefile
RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJDUMP = $(RISCV_PREFIX)objdump
```
- **`RISCV_PREFIX`** - Common prefix for all RISC-V tools
- **`CC`** - Compiler variable = `riscv64-unknown-elf-gcc`
- **`OBJDUMP`** - Disassembler = `riscv64-unknown-elf-objdump`

**Why `riscv64` for 32-bit?** The 64-bit compiler can cross-compile to 32-bit with `-march=rv32i` flag. Many systems only have the 64-bit toolchain installed.

#### Compiler Flags
```makefile
CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -O2
LDFLAGS = -T../riscv32.ld
```

**`CFLAGS`** - Compiler flags passed to `gcc`:
- **`-march=rv32i`** - Target architecture: RV32I (32-bit base integer instruction set)
  - Only generates ADD, SUB, LOAD, STORE, BRANCH instructions (no multiply, divide, float)
- **`-mabi=ilp32`** - Application Binary Interface:
  - `i` = integer registers only (no floating-point)
  - `lp32` = `int`, `long`, and pointers are 32-bit
- **`-nostdlib`** - Don't link standard library (`libc`)
  - We're bare-metal (no OS), so no `printf`, `malloc`, etc.
  - Must provide our own startup code (`start.s`)
- **`-O2`** - Optimization level 2
  - Enables optimizations (function inlining, dead code elimination, etc.)
  - Without this, code would be much larger and slower

**`LDFLAGS`** - Linker flags:
- **`-T../riscv32.ld`** - Use custom linker script at `../riscv32.ld`
  - Overrides default linker behavior
  - Sets base address to `0x01000000`
  - Defines `tohost`/`fromhost` symbols

#### File Discovery
```makefile
STARTUP = ../start.s
SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=.iss.elf)
```
- **`STARTUP`** - Path to startup code (needs to be linked with every C program)
- **`$(wildcard *.c)`** - Find all `.c` files in current directory
  - Example: `SimpleAdd.c`, `BubbleSort.c`, `Fibonacci.c`
- **`$(SOURCES:.c=.iss.elf)`** - Replace `.c` with `.iss.elf` in each source name
  - `SimpleAdd.c` → `SimpleAdd.iss.elf`
  - This creates the list of output files to build

#### Build Rules
```makefile
%.iss.elf: %.c $(STARTUP)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(STARTUP) $<
```
This is a **pattern rule** - it matches any target ending in `.iss.elf`.

- **`%.iss.elf: %.c $(STARTUP)`** - To build `X.iss.elf`, need `X.c` and `start.s`
  - `%` is a wildcard (matches any string)
  - Example: `SimpleAdd.iss.elf` needs `SimpleAdd.c` and `../start.s`
- **`$@`** - Automatic variable = target name (`SimpleAdd.iss.elf`)
- **`$<`** - Automatic variable = first prerequisite (`SimpleAdd.c`)
- **Command:** `riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -nostdlib -O2 -T../riscv32.ld -o SimpleAdd.iss.elf ../start.s SimpleAdd.c`

**Build steps:**
1. Compile `start.s` to object file (in memory)
2. Compile `SimpleAdd.c` to object file (in memory)
3. Link both objects together using `riscv32.ld` linker script
4. Produce `SimpleAdd.iss.elf` executable

**Why link `start.s` first?** Its `.text.init` section must come before `.text` section (startup code must execute first).

#### Disassembly Rule
```makefile
%.dis: %.iss.elf
	$(OBJDUMP) -d $< > $@
```
- **`objdump -d`** - Disassemble (show assembly for all code sections)
- **`$<`** - Input file (`SimpleAdd.iss.elf`)
- **`$@`** - Output file (`SimpleAdd.dis`)
- **`>`** - Redirect output to file

Creates human-readable disassembly showing addresses, hex encoding, and assembly:
```
01000000 <_start>:
 1000000:	010001b7          	lui	sp,0x1000
 1000004:	00018193          	addi	sp,sp,0
 1000008:	008000ef          	jal	1000010 <main>
 100000c:	...
```

---

### Makefile.new (individual-instructions)

**Location:** `verilog/rv32-benchmarks/individual-instructions/Makefile.new`

**Purpose:** Build assembly tests (`.s` files) into ELF executables for Spike.

**Full File:**
```makefile
# Toolchain
RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJDUMP = $(RISCV_PREFIX)objdump

# Flags
ASFLAGS = -march=rv32i -mabi=ilp32
LDFLAGS = -T../riscv32.ld -nostdlib

# Find all test-*.s files
TEST_FILES = $(wildcard test-*.s)
TARGETS = $(TEST_FILES:.s=.elf)

# Default target
all: $(TARGETS)
	@echo ""
	@echo "Built $(words $(TARGETS)) simple instruction tests"
	@echo "Run with: spike --isa=rv32i -m0x01000000:0x200000 <file>.elf"

# Build ELF from assembly
%.elf: %.s
	@echo "Building $@..."
	@$(CC) $(ASFLAGS) $(LDFLAGS) -o $@ $<

# Generate disassembly
%.dis: %.elf
	$(OBJDUMP) -d $< > $@

# Test with spike
test-%: test-%.elf
	@echo "Testing $<..."
	@spike --isa=rv32i -m0x01000000:0x200000 $< 2>&1 && echo "✓ PASSED" || echo "✗ FAILED"

# Clean
clean:
	rm -f test-*.elf test-*.dis

# Build with disassembly
debug: $(TARGETS) $(TARGETS:.elf=.dis)

.PHONY: all clean debug
```

**Key Differences from Makefile.iss:**

#### Assembly Flags
```makefile
ASFLAGS = -march=rv32i -mabi=ilp32
LDFLAGS = -T../riscv32.ld -nostdlib
```
- **`ASFLAGS`** - Flags for assembling `.s` files
  - Same architecture flags (`-march=rv32i -mabi=ilp32`)
  - No optimization flags (assembly is already optimized by hand)
- **`LDFLAGS`** - Linker flags
  - Same linker script (`-T../riscv32.ld`)
  - `-nostdlib` prevents linking startup code (assembly tests have their own `_start`)

#### File Discovery
```makefile
TEST_FILES = $(wildcard test-*.s)
TARGETS = $(TEST_FILES:.s=.elf)
```
- Only matches `test-*.s` files (not all `.s` files)
- Produces `.elf` files (not `.iss.elf`)

#### Build Rule
```makefile
%.elf: %.s
	@$(CC) $(ASFLAGS) $(LDFLAGS) -o $@ $<
```
- **Simpler than C build:** Only one input file (`.s`), no startup code needed
- Assembly tests provide their own `_start` label and HTIF signaling

#### Test Rule
```makefile
test-%: test-%.elf
	@spike --isa=rv32i -m0x01000000:0x200000 $< 2>&1 && echo "✓ PASSED" || echo "✗ FAILED"
```
- **`test-%`** - Pattern target for testing
  - `make test-add-simple` runs `test-add-simple.elf` on Spike
- **`spike --isa=rv32i -m0x01000000:0x200000 $<`** - Run test on Spike
- **`2>&1`** - Redirect stderr to stdout (capture all output)
- **`&& echo "✓ PASSED" || echo "✗ FAILED"`** - Print result based on exit code
  - If Spike exits with 1 (`tohost = 1`), print "PASSED"
  - If Spike exits with 0 or other, print "FAILED"

---

### ece320.ld - Legacy Linker Script

**Location:** `verilog/rv32-benchmarks/simple-programs/ece320.ld`

**Purpose:** Original linker script (legacy, not ISS-compatible).

**Full File:**
```ld
OUTPUT_ARCH( "riscv" )
ENTRY(main)

SECTIONS
{
. = 0x01000000;
.text.init : { *(.text.init) }
. = ALIGN(0x1000);
.tohost : { *(.tohost) }
. = ALIGN(0x1000);
.text : { *(.text) }
. = ALIGN(0x1000);
.data : { *(.data) }
.bss : { *(.bss) }
_end = .;
}
```

**Key Differences from riscv32.ld:**

| Feature | ece320.ld (legacy) | riscv32.ld (ISS) |
|---------|-------------------|------------------|
| Entry point | `ENTRY(main)` | `ENTRY(_start)` |
| HTIF symbols | `.tohost` section (not defined) | `tohost`/`fromhost` symbols defined |
| Alignment | 4KB alignment (`.  = ALIGN(0x1000)`) | Natural alignment |
| Stack pointer | Not defined | `_stack_top` defined |
| Memory region | Implicit | Explicit `MEMORY { ram ... }` |

**Why legacy?**
- Doesn't define `tohost` symbol (Spike can't detect test completion)
- Aligns sections on 4KB boundaries (wastes memory)
- Enters at `main` instead of `_start` (no stack initialization for C)

**Still used for:** Original `.x` files built for the processor (not Spike-compatible).

---

## Build Process Flow

### C Program Build Flow

```
┌─────────────┐
│  program.c  │  ← Your C source code
└──────┬──────┘
       │
       │ Compile with gcc
       │ -march=rv32i -mabi=ilp32 -nostdlib -O2
       ▼
┌─────────────┐      ┌──────────┐
│ program.o   │  +   │ start.o  │  ← Compiled object files
└──────┬──────┘      └────┬─────┘
       │                  │
       └──────────┬───────┘
                  │
                  │ Link with riscv32.ld
                  │ -T../riscv32.ld
                  ▼
          ┌───────────────┐
          │ program.iss.elf│  ← Executable ELF file
          └───────┬────────┘
                  │
        ┌─────────┴─────────┐
        │                   │
        ▼                   ▼
┌──────────────┐    ┌──────────┐
│ Spike ISS    │    │ Your CPU │
└──────────────┘    └──────────┘
```

**Steps:**
1. **Compile `start.s`:**
   - Assembler converts assembly to machine code
   - Produces `start.o` (object file with `.text.init` section)

2. **Compile `program.c`:**
   - Preprocessor handles `#include`, `#define`
   - Compiler translates C to RISC-V assembly
   - Assembler converts assembly to machine code
   - Produces `program.o` (object file with `.text`, `.data`, `.bss` sections)

3. **Link together:**
   - Linker combines `start.o` and `program.o`
   - Uses `riscv32.ld` to determine section placement
   - Resolves symbols (`main`, `tohost`, `_stack_top`)
   - Produces `program.iss.elf` (executable with all sections placed at correct addresses)

4. **Load and run:**
   - Spike or your processor loads ELF file
   - Extracts `.text`, `.data` sections and places in memory
   - Sets PC to `_start` address
   - Begins execution

### Assembly Test Build Flow

```
┌──────────────┐
│  test-add.s  │  ← Your assembly source
└──────┬───────┘
       │
       │ Assemble with gcc
       │ -march=rv32i -mabi=ilp32
       ▼
┌──────────────┐
│  test-add.o  │  ← Object file
└──────┬───────┘
       │
       │ Link with riscv32.ld
       │ -T../riscv32.ld -nostdlib
       ▼
┌──────────────┐
│ test-add.elf │  ← Executable ELF
└──────┬───────┘
       │
       ▼
 ┌──────────┐
 │ Spike    │
 └──────────┘
```

**Steps:**
1. **Assemble:** Convert assembly instructions to machine code
2. **Link:** Use linker script to place sections and define symbols
3. **Run:** Load and execute on Spike

**Simpler than C:** No separate startup code needed (test provides its own `_start`).

---

## Memory Layout

Here's how memory is laid out at runtime:

```
Address          Section           Contents
═══════════════════════════════════════════════════════════
0x01100000       (end of RAM)
                 ↑
                 │ (stack grows down)
                 │
_stack_top ──────┘
                 (unused space)

                 .htif             fromhost (8 bytes)
                                   tohost (8 bytes)

                 .bss              Uninitialized variables
                                   (zero-filled at load)

                 .data             Initialized variables
                                   Global arrays
                                   Static data

                 .rodata           String constants
                                   Const variables

                 .text             main() function
                                   Other functions

                 .text.init        _start (startup code)
0x01000000 ──────┘ (base address)
═══════════════════════════════════════════════════════════
```

**Example Addresses (SimpleAdd.c):**
```
0x01000000  _start:        lui  sp, 0x1100
0x01000004                 addi sp, sp, 0
0x01000008                 jal  main
0x0100000C  (HTIF write)   la   t0, tohost
0x01000010                 sw   a0, 0(t0)
0x01000014                 ecall
...
0x01000100  main:          addi sp, sp, -16
0x01000104                 addi a0, x0, 3    # a = 3
0x01000108                 addi a1, x0, 2    # b = 2
...
0x010002A0  tohost:        (8 bytes reserved)
0x010002A8  fromhost:      (8 bytes reserved)
0x010002B0  _stack_top:    (stack starts here)
```

**Memory Access:**
- **Instruction fetch:** Processor reads from `.text` section
- **Load/store:** Processor accesses `.data`, `.bss`, stack
- **HTIF write:** Test writes to `tohost` address to signal completion

---

## HTIF Protocol

**HTIF (Host-Target Interface)** is how your program communicates with Spike.

### How It Works

1. **Linker defines symbols:**
   ```ld
   tohost = 0x010002A0;      # Example address
   fromhost = 0x010002A8;
   ```

2. **Test writes result:**
   ```assembly
   la   t0, tohost      # Load address 0x010002A0
   addi a0, x0, 1       # a0 = 1 (pass)
   sw   a0, 0(t0)       # Memory[0x010002A0] = 1
   ecall                # Signal Spike
   ```

3. **Spike reads `tohost`:**
   - `ecall` instruction triggers HTIF handler in Spike
   - Spike reads memory at `tohost` address
   - If `tohost == 1`, exit with success
   - If `tohost == 0` or other, exit with failure

### Why Use `fence` Before Write?

```assembly
fence iorw, iorw    # Memory fence
la    t0, tohost
sw    a0, 0(t0)
```

**`fence`** ensures memory ordering:
- Waits for all previous memory operations to complete
- Prevents store to `tohost` from being reordered

**Without fence:** The processor might execute `sw` before earlier stores complete, causing incorrect results to be signaled.

**Fence types:**
- `iorw` = Input, Output, Read, Write
- `fence iorw, iorw` = "All memory operations before this fence complete before any operations after"

### HTIF in Your Processor

Your processor doesn't implement full HTIF (no special handling of `tohost` address). Instead:

1. Test writes to `tohost` (normal store instruction)
2. Verilator simulation hits timeout (50,000 cycles)
3. Simulation ends
4. Trace file shows final register states

To check pass/fail:
- Look at final value written to `tohost` address in trace
- Compare trace against golden reference (Spike trace)

---

## Common Modifications

### Changing Memory Size

**Modify linker script (`riscv32.ld`):**
```ld
MEMORY
{
  ram (rwx) : ORIGIN = 0x01000000, LENGTH = 2M  # Changed from 1M
}
```

**Update Spike command:**
```bash
spike --isa=rv32i -m0x01000000:0x400000 program.elf  # 4MB (2M = 2097152 = 0x200000)
```

**Update processor parameter:**
```verilog
pd #(
    .BASE_ADDR(32'h01000000),
    .MEM_DEPTH(2097152)    // 2MB
) dut (
    ...
);
```

### Changing Base Address

**Modify linker script:**
```ld
MEMORY
{
  ram (rwx) : ORIGIN = 0x80000000, LENGTH = 1M  # Changed base
}
```

**Update Spike command:**
```bash
spike --isa=rv32i -m0x80000000:0x200000 program.elf
```

**Update processor parameter:**
```verilog
pd #(
    .BASE_ADDR(32'h80000000),
    ...
```

**Warning:** Some addresses conflict with Spike's devices (e.g., `0x10000000` has UART). Use `0x01000000` or `0x80000000` to avoid conflicts.

### Adding Custom Sections

**In linker script:**
```ld
.mysection : {
    *(.mysection)
    *(.mysection.*)
} > ram
```

**In assembly:**
```assembly
.section .mysection
my_data:
    .word 0x12345678
```

**In C (with attributes):**
```c
__attribute__((section(".mysection"))) int my_var = 42;
```

### Enabling Floating-Point (RV32F)

**Change compiler flags:**
```makefile
CFLAGS = -march=rv32if -mabi=ilp32f -nostdlib -O2
```
- `-march=rv32if` - Add F extension (single-precision float)
- `-mabi=ilp32f` - Use floating-point registers for float arguments

**Update Spike:**
```bash
spike --isa=rv32if -m0x01000000:0x200000 program.elf
```

**Note:** Your processor must implement F extension instructions!

---

## Summary

This ISS setup provides:

1. **`riscv32.ld`** - Linker script that defines memory layout and HTIF symbols
2. **`start.s`** - Startup code for C programs (stack init, call main, HTIF exit)
3. **Makefiles** - Automated build process for C and assembly tests
4. **Spike compatibility** - Tests work on both Spike and your processor
5. **Trace comparison** - Verify correctness by comparing outputs

**Key takeaways:**
- Linker scripts control memory layout (base address, section order, symbols)
- Startup code bridges bare-metal environment and C runtime
- HTIF enables tests to signal pass/fail via `tohost` symbol
- Build process: Compile → Assemble → Link → Execute

For questions or modifications, consult this document or examine the files directly!
