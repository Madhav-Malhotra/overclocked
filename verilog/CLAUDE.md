# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a **5-stage pipelined RISC-V (RV32I) processor** implementation in Verilog with complete verification infrastructure. The processor implements the base integer instruction set (RV32I) with hazard detection, data forwarding, and comprehensive testing against golden reference traces.

## Prerequisites

Install dependencies via system package manager:
```bash
sudo apt install verilator python3 make g++
```

Tested with Verilator 5.020 (works with 4.210+).

## Common Commands

### Build and Run Simulation
```bash
cd verilog/verif/scripts

# Compile and run default test (rv32ui-p-add)
make all

# Run specific benchmark by path
make run MEM_PATH=/path/to/benchmark.x

# Run specific benchmark by name (searches both directories)
make run_bench BENCH=rv32ui-p-add

# Run all available benchmarks
make run_all_benchmarks

# List all available benchmarks
make list_benchmarks
```

### Testing and Verification
```bash
cd verilog/verif/scripts

# Full pipeline: compile sources -> run processor sims -> generate spike traces -> compare
make run_all_benchmarks

# Single benchmark: run + spike compare
make run_and_verify MEM_PATH=/path/to/benchmark.x

# Python test orchestrator (parallel execution, calls build_benchmarks first)
cd ../..
python3 run_scripts.py
```

### Cleaning Build Artifacts
```bash
cd verilog/verif/scripts
make clean
```

### Common Make Variables
- `TEST=test_pd` - Test name (default: test_pd)
- `MEM_PATH=<path>` - Path to benchmark .x file
- `BENCH=<name>` - Benchmark name (without .x extension)
- `GEN_TRACE=1` - Enable trace generation (default: 1)
- `TIMEOUT=50000` - Simulation timeout in cycles (default: 50000)
- `DIFF_MODE=sim|board` - Comparison mode (default: sim)

## Architecture Overview

### Pipeline Structure

The processor implements a classic 5-stage pipeline:

**F (Fetch)** → **D (Decode)** → **X (Execute)** → **M (Memory)** → **W (Writeback)**

Each stage has dedicated pipeline registers (FD, DX, XM, MW) that propagate PC, opcode, operands, and control signals.

### Key Modules (`verilog/design/code/`)

- **`pd.v`** (446 lines) - Top-level processor with pipeline control, hazard detection, and forwarding logic
- **`control_signals.v`** - Generates all control signals from opcode/funct3/funct7
- **`decoder.v`** - Instruction field extraction and immediate generation for all RV32I formats (R, I, S, B, U, J)
- **`alu.v`** - 10-operation ALU (ADD, SUB, shifts, logical, comparisons)
- **`register_file.v`** - 32x32 register file with 2-read, 1-write ports (x0 hardwired to 0, x2/sp initialized)
- **`imemory.v`** - Instruction memory (block RAM)
- **`dmemory.v`** - Data memory with byte/halfword/word access
- **`branch_comp.v`** - Branch condition evaluation (equality, signed/unsigned less-than)
- **`writeback.v`** - Writeback data multiplexer

### Hazard Management

The processor implements 4 types of stalls:
1. **Load stalls** - Load-to-use data hazards (load in X, use in D)
2. **Write-data stalls** - Write-back dependencies
3. **Load-store stalls** - Load in M, store using same register
4. **Store RS2 stalls** - Data hazard on store's source operand

Forwarding paths exist from:
- **WX_BYPASS** - Writeback → Execute ALU inputs
- **MX_BYPASS** - Memory → Execute ALU inputs
- **Branch comparator forwarding** - For branch instructions
- **WM forwarding** - For store data

When stalls occur, the processor injects NOPs (`0x00000013`) and repeats the stalled instruction.

### Verification Infrastructure

Tests are located in `verilog/rv32-benchmarks/`:
- `individual-instructions/` - Per-instruction tests (source: `rv32ui-p-*.s`)
- `simple-programs/` - Integration tests (source: `*.c`)

`.elf` and `.x` files are **generated outputs** — do not commit them. The `.s` and `.c` files are the source of truth.

Verification uses Spike (`--log-commits`) as the golden reference. `cmp_wb_spike.py` compares the processor's register write sequence against Spike's commit log.

Trace files follow the FDXMW format (6 lines per cycle):
```
[F] pc_addr content                    # Fetch
[D] pc_addr opcode rd rs1 rs2...       # Decode
[R] addr_rs1 addr_rs2 data_rs1 data_rs2 # Register read
[E] pc_addr alu_result branch_taken    # Execute
[M] pc_addr mem_addr rw size data      # Memory
[W] pc_addr write_enable rd data       # Writeback
```

Spike commit traces go to `verilog/verif/spike_traces/`.
Simulation outputs go to `verilog/verif/sim/verilator/test_pd/`.
Spike diff reports go to `verilog/verif/diffs/spike/`.

### Test Orchestration

Two testing approaches:

1. **Makefile-based** (`make run_all_benchmarks`) - Builds sources, runs sims, compares vs Spike
2. **Python script** (`run_scripts.py`) - Parallel execution, builds sources first

### Memory Map

- **Instruction memory base**: `0x01000000`
- **Stack pointer (x2) initialization**: `BASE_ADDR + MEM_DEPTH`
- **Memory depth**: 1MB (default, configurable via MEM_DEPTH)

## Important Implementation Details

### Instruction Support
- All RV32I base instructions are implemented
- No compressed instructions (RV32C)
- No multiply/divide (RV32M)
- No floating point
- ECALL instruction is supported but behavior is minimal (decode only)

### Design Constraints
- Single-port memories (instruction and data are separate)
- Instruction fetches stall when pipeline hazards occur
- Branch prediction: Not taken (continues sequential fetch)
- Branch resolution in Execute stage (1-cycle penalty on taken branches)

### File Conventions
- `.s` / `.c` files - **Source of truth** (assembly/C sources)
- `.elf` files - Generated: Spike input (built by Makefile.new / Makefile.iss)
- `.x` files - Generated: Processor `$readmemh` input (derived from same `.elf`)
- `.trace` files - Execution traces in FDXMW format
- `.vcd` files - Waveform dumps (optional, enable with VCD=1)

## Unity/Frontend

The `unity/` directory contains the Overclocked game itself (see `unity/CLAUDE.md`). It consumes this processor via two paths:
- Verilator: `verilator/` compiles the Verilog into a native plugin (`design_wrapper.dll`/`.so`) that `unity/Assets/CPUWrapper/CPU.cs` calls into directly.
- FPGA: `bridge/` and `webserver/` (top-level, sibling to `verilog/`) let the same `ICPU` interface talk to a synthesized design running on a PYNQ-Z2 over a REST API instead of the native plugin.

## Working with This Codebase

### When Modifying the Processor Design

1. **Always read the full module first** - The pipeline logic in `pd.v` is tightly coupled
2. **Understand hazard implications** - Changes to timing affect stall/forward logic
3. **Update control signals** - New instructions require updates to `control_signals.v` and `decoder.v`
4. **Test thoroughly** - Run `make run_all_benchmarks` after changes
5. **Check traces** - Use diff reports to identify pipeline stage where bugs occur

### When Debugging

1. **Check trace files** - Traces show exact pipeline state per cycle
2. **Use filtered diffs** - `-diff-filtered-wb-only.txt` shows only meaningful differences
3. **Enable VCD** - `make run VCD=1 MEM_PATH=...` generates waveforms for GTKWave

### Common Issues

- **"verilator: command not found"** - Install with `sudo apt install verilator`
- **Benchmark not found** - Use `make list_benchmarks` to see available tests
- **Trace mismatches on don't-care fields** - Use filtered diff reports, not raw diffs
- **Simulation timeout** - Increase with `TIMEOUT=100000`

## Git Status Note

Generated files (`.elf`, `.x`, `.bin`) in `rv32-benchmarks/` should be gitignored. Only `.s` and `.c` sources should be committed.