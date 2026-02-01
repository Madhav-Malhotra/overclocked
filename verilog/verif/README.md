# Verification Infrastructure

This directory contains the complete verification infrastructure for the RV32I pipelined processor.

## Architecture Overview

The verification flow uses **trace-based comparison** against golden references:

```
Verilog RTL → Verilator → C++ Simulation → Execution Traces → Diff vs Golden → Pass/Fail
```

### Key Concepts

1. **Trace Generation** - During simulation, each pipeline stage dumps its state every cycle
2. **Golden References** - Pre-verified execution traces stored in `golden_sim/`
3. **Differential Testing** - Python scripts compare simulation output against golden traces
4. **Filtered Comparison** - Ignore don't-care fields (e.g., rs2 in I-type instructions)

## Directory Structure

```
verif/
├── tests/                 # Test harnesses and trace generation
│   ├── test_pd.sv         # SystemVerilog testbench wrapper
│   ├── test_pd.cpp        # Verilator C++ simulation driver
│   ├── clockgen.sv        # Clock generation module
│   ├── tracegen.v         # Trace file dispatcher
│   ├── trace_dump.h       # Trace writer (FDXMW format)
│   └── fields.h           # Pipeline field macros
├── scripts/               # Build and execution scripts
│   ├── Makefile           # Main build orchestrator
│   ├── Makefile.verilator # Verilator-specific build rules
│   ├── cmp_sim_trace.py   # Trace comparison tool
│   ├── design.f           # RTL file list
│   └── check_warnings.sh  # Warning checker
├── data/                  # Default test benchmarks
│   └── rv32ui-p-add.x     # Default test program
├── golden_sim/            # Golden reference traces
│   └── *.trace            # Pre-verified execution traces
├── sim/                   # Simulation outputs (generated)
│   └── verilator/test_pd/ # Verilator build and trace outputs
└── diffs/                 # Diff comparison results (generated)
    └── sim/               # Simulation vs golden diffs
```

## Trace Format

Traces use the **FDXMW format** - 6 lines per clock cycle representing each pipeline stage:

```
[F] pc_addr instruction_content           # Fetch stage
[D] pc_addr opcode rd rs1 rs2 imm         # Decode stage
[R] addr_rs1 addr_rs2 data_rs1 data_rs2   # Register read
[E] pc_addr alu_result branch_taken       # Execute stage
[M] pc_addr mem_addr rw size data         # Memory stage
[W] pc_addr write_enable rd data          # Writeback stage
```

### Example Trace Snippet

```
[F] 01000014 00208093
[D] 01000014 0010011 00001 00001 xxxxx 00000002
[R] 00001 xxxxx 00000000 xxxxxxxx
[E] 01000014 00000002 0
[M] 01000014 xxxxxxxx x x xxxxxxxx
[W] 01000014 1 00001 00000002
```

This shows an `addi x1, x1, 2` instruction being executed (adds immediate 2 to register x1).

## Test Harness Components

### test_pd.sv
SystemVerilog wrapper that instantiates:
- Clock generator (`clockgen`)
- Design under test (`design_wrapper`)
- Trace generation logic (`tracegen.v`)
- Optional VCD dumping for waveform viewing

### test_pd.cpp
Verilator C++ testbench that:
- Initializes the simulation
- Drives the clock via DPI function `toggleClock()`
- Handles VCD file generation (if `VCD=1`)
- Exits on `$finish`

### tracegen.v
Conditional trace generation based on compile-time defines:
- `GEN_TRACE=1` → Include `trace_dump.h` (enable trace output)
- `GEN_TRACE=0` → Skip trace generation (faster simulation)

### trace_dump.h
Dumps pipeline state to trace file each cycle:
- Reads internal signals from `design_wrapper`
- Formats as FDXMW lines
- Writes to `TRACE_FILE` (e.g., `rv32ui-p-add.trace`)

### fields.h
Macros for extracting bit fields from instructions:
- Opcode, funct3, funct7 extraction
- Register specifiers (rd, rs1, rs2)
- Immediate decoding helpers

### clockgen.sv
Generates clock and reset signals:
- Verilator: Uses DPI `toggleClock()` function
- Configurable timeout via `TIMEOUT` define
- Calls `$finish` when timeout reached

## Verification Scripts

### Makefile
Main build orchestrator with targets:

**Build & Run:**
- `make all` - Compile and run default test
- `make compile` - Verilator compilation only
- `make run` - Run simulation (requires `MEM_PATH=...`)

**Benchmarks:**
- `make run_bench BENCH=<name>` - Run single benchmark by name
- `make run_all_benchmarks` - Run all tests sequentially
- `make list_benchmarks` - List available benchmarks

**Comparison:**
- `make diff_all_benchmarks` - Compare all traces vs golden

**Utilities:**
- `make clean` - Remove simulation artifacts
- `make help` - Show all targets

### Makefile.verilator
Verilator-specific build configuration:
- Compiles Verilog → C++
- Links test harness (`test_pd.cpp`)
- Generates executable (`Vtop`)
- Passes defines: `MEM_PATH`, `GEN_TRACE`, `TIMEOUT`, etc.

### cmp_sim_trace.py
Python script for trace comparison:

```bash
python3 cmp_sim_trace.py <test_trace> <golden_trace> <output_diff> [options]
```

**Options:**
- `--mismatch-only` - Show only differing lines
- `--filter "[W]"` - Compare only writeback stage (filters out don't-care fields)

**Output Format:**
```
Line   | Golden                    | Test                      | Match
-------|---------------------------|---------------------------|------
123    | [W] 01000010 1 00001 ... | [W] 01000010 1 00001 ... | ✓

=======================================================================
Total lines compared: 318
Matches: 318
Mismatches: 0
```

### design.f
RTL file list sourced by Makefile:
```
alu.v
branch_comp.v
control_signals.v
decoder.v
dmemory.v
imemory.v
pd.v
register_file.v
writeback.v
```

## Workflow Examples

### Running a Single Test

```bash
cd verilog/verif/scripts

# Run by path
make run MEM_PATH=../../rv32-benchmarks/individual-instructions/rv32ui-p-add.x

# Or by name (easier)
make run_bench BENCH=rv32ui-p-add

# Check trace output
ls ../sim/verilator/test_pd/*.trace

# Compare against golden
python3 cmp_sim_trace.py \
  ../sim/verilator/test_pd/rv32ui-p-add.trace \
  ../golden_sim/rv32ui-p-add.trace \
  /tmp/diff.txt \
  --mismatch-only --filter "[W]"
```

### Running All Tests

```bash
make run_all_benchmarks

# Output shows:
# Running benchmark: .../rv32ui-p-add.x
# Running benchmark: .../rv32ui-p-sub.x
# ...
# PASS: rv32ui-p-add.trace
# FAIL: rv32ui-p-sub.trace
# ...
# SUMMARY
# Passed: 25
# Failed: 3
```

### Debugging with Waveforms

```bash
# Generate VCD file
make run VCD=1 MEM_PATH=path/to/benchmark.x

# Open in GTKWave
cd ../sim/verilator/test_pd
gtkwave benchmark.vcd ../../scripts/format.gtkw
```

### Parallel Testing (Python Orchestrator)

```bash
cd verilog
python3 run_scripts.py

# Runs all benchmarks in parallel
# Generates 3 diff files per test:
#   - *-diff.txt (raw)
#   - *-diff-filtered.txt (standard filtering)
#   - *-diff-filtered-wb-only.txt (writeback only)
```

## Configuration Variables

Set via Makefile or command line:

- `TEST` - Test name (default: `test_pd`)
- `MEM_PATH` - Path to benchmark `.x` file
- `MEM_DEPTH` - Memory size in bytes (default: 1048576 = 1MB)
- `GEN_TRACE` - Enable trace generation (default: 1)
- `TIMEOUT` - Simulation timeout in cycles (default: 50000)
- `VCD` - Enable VCD waveform output (default: 0)

## Adding New Tests

### 1. Create Test Program

Write RISC-V assembly or C code, compile to `.x` executable:

```bash
riscv32-unknown-elf-gcc -march=rv32i -mabi=ilp32 \
  -nostdlib -T linker.ld -o test.x test.s
```

### 2. Generate Golden Trace

Run with known-good processor (or Spike ISA simulator):

```bash
# Place golden trace in verif/golden_sim/
cp test.trace verilog/verif/golden_sim/
```

### 3. Run Test

```bash
make run MEM_PATH=/path/to/test.x

# Compare
python3 cmp_sim_trace.py \
  ../sim/verilator/test_pd/test.trace \
  ../golden_sim/test.trace \
  output.diff --mismatch-only --filter "[W]"
```

## Trace Filtering Rationale

Some instruction fields are "don't care" depending on instruction type:

| Instruction Type | Don't Care Fields |
|------------------|-------------------|
| I-type (e.g., ADDI) | rs2 (no second source register) |
| S-type (e.g., SW) | rd (no destination register) |
| B-type (e.g., BEQ) | rd (no destination register) |
| U-type (e.g., LUI) | rs1, rs2 (no source registers) |
| J-type (e.g., JAL) | rs1, rs2 (no source registers) |

**Solution:** Use `--filter "[W]"` to compare only writeback stage, which contains final architectural state (only committed writes matter).

## Known Limitations

1. **No compressed instructions** - Only RV32I base (no RV32C)
2. **No multiply/divide** - RV32M not implemented
3. **Single-ported memory** - Instruction and data are separate
4. **No branch prediction** - Assumes branches not taken (1-cycle penalty on taken)

## Future Enhancements

- **Spike Integration** - Use RISC-V ISA simulator as golden model (eliminates need for pre-generated traces)
- **Coverage Analysis** - Track instruction and hazard coverage
- **Automated Trace Generation** - Generate golden traces from Spike automatically
- **Regression Testing** - CI/CD integration for continuous verification

## Debugging Tips

### Trace Mismatches

1. **Check instruction type** - Ensure comparing valid fields (use filtered diffs)
2. **Identify pipeline stage** - Look at which stage shows first mismatch (F/D/E/M/W)
3. **Check hazard handling** - Mismatches often indicate forwarding/stall bugs
4. **Verify golden trace** - Ensure golden reference is actually correct

### Performance Issues

- Disable tracing for faster simulation: `make run GEN_TRACE=0`
- Increase timeout for long tests: `TIMEOUT=1000000`
- Use parallel testing: `python3 run_scripts.py` (concurrent execution)

### Compilation Errors

- Check `design.f` includes all RTL files
- Verify Verilator version: `verilator --version` (need 4.210+)
- Clean and rebuild: `make clean && make all`

## Contact

For questions about verification infrastructure, see `../CLAUDE.md` or check the main `README.md`.
