# RV32I Pipelined Processor

A 5-stage pipelined RISC-V (RV32I) processor implementation in Verilog with complete verification infrastructure.

## Overview

This project implements a complete RV32I base integer instruction set processor with:
- 5-stage pipeline (Fetch, Decode, Execute, Memory, Writeback)
- Hazard detection and data forwarding
- Comprehensive trace-based verification
- Verilator simulation support

## Quick Start

### Prerequisites

Install dependencies via your system package manager:

```bash
sudo apt install verilator python3 make g++
```

Tested with Verilator 5.020, 5.040, 5.042, 4.210.

### Build and Run

```bash
# Navigate to verification scripts
cd verif/scripts

# Run default test (rv32ui-p-add)
make all

# Run a specific benchmark by name
make run_bench BENCH=rv32ui-p-add

# Run all available benchmarks
make run_all_benchmarks

# Compare traces against golden references
make diff_all_benchmarks

# Clean build artifacts
make clean
```

### Example Output

```
$ make all
Verilator Compilation
...
Verilator Run
- .../clockgen.sv:40: Verilog $finish

$ ls verif/sim/verilator/test_pd/
rv32ui-p-add.trace  Vtop  Vtop__ALL.a  ...
```

## Repository Structure

```
verilog/
├── design/
│   ├── code/              # RTL source files (ALU, decoder, pipeline stages)
│   └── design_wrapper.v   # Top-level wrapper
├── verif/
│   ├── tests/             # Test harnesses (test_pd.sv, test_pd.cpp)
│   ├── scripts/           # Build scripts (Makefile, Makefile.verilator)
│   ├── data/              # Test benchmarks (.x files)
│   ├── golden_sim/        # Golden reference traces
│   ├── sim/               # Simulation outputs (generated)
│   └── diffs/             # Diff comparison results (generated)
├── rv32-benchmarks/       # RISC-V test programs
│   ├── individual-instructions/  # Per-instruction tests
│   └── simple-programs/          # Integration tests
└── README.md              # This file
```

## Common Commands

### Running Tests

```bash
# Run specific test by path
make run MEM_PATH=/path/to/benchmark.x

# Run by benchmark name (auto-searches both directories)
make run_bench BENCH=SimpleAdd

# List all available benchmarks
make list_benchmarks
```

### Debug and Analysis

```bash
# Generate VCD waveform for GTKWave
make run VCD=1 MEM_PATH=path/to/benchmark.x

# View waveforms
make waves MEM_PATH=path/to/benchmark.x
```

### Configuration Variables

- `MEM_PATH` - Path to benchmark executable (default: `verif/data/rv32ui-p-add.x`)
- `BENCH` - Benchmark name for `run_bench` target
- `GEN_TRACE` - Enable/disable trace generation (default: 1)
- `TIMEOUT` - Simulation timeout in cycles (default: 50000)
- `VCD` - Enable VCD waveform output (default: 0)

## Verification

The verification flow compares simulation traces against golden references:

1. **Run simulation** - Generates `.trace` files with pipeline state per cycle
2. **Compare traces** - Python scripts diff against golden references
3. **Analyze results** - Filtered diffs show only meaningful mismatches

See `verif/README.md` for detailed verification architecture.

## Design Files

Key RTL modules in `design/code/`:

- `pd.v` - Top-level pipelined processor with hazard control
- `control_signals.v` - Control signal generation from opcode
- `decoder.v` - Instruction decoder and immediate generator
- `alu.v` - 10-operation arithmetic/logic unit
- `register_file.v` - 32x32 register file
- `imemory.v` - Instruction memory
- `dmemory.v` - Data memory with byte/halfword/word access
- `branch_comp.v` - Branch condition comparator
- `writeback.v` - Writeback multiplexer

## Game Integration

This CPU simulation is designed to be integrated into a Unity game (Overcooked-style CPU visualization). The Verilator-generated C++ can be compiled into native plugins for Unity.

### For Game Development

Verilator generates portable C++ classes (`Vtop.h`, `Vtop__ALL.a`) that can be:
1. Wrapped in C API for P/Invoke
2. Compiled as shared libraries (`.so`/`.dll`/`.dylib`)
3. Placed in Unity's `Plugins/` directory
4. Called from C# game logic

**Note:** End users on Steam don't need Verilator - it's only a build-time dependency for developers.

## Troubleshooting

### Common Issues

**"verilator: command not found"**
- Install Verilator: `sudo apt install verilator`

**"No benchmarks found"**
- Check `rv32-benchmarks/` directory exists
- Run `make list_benchmarks` to see available tests

**Trace mismatches**
- Use filtered diffs: check `verif/diffs/sim/*.diff` files
- Look for `Mismatches: 0` in summary

**Simulation timeout**
- Increase timeout: `make run TIMEOUT=100000 MEM_PATH=...`

## Documentation

- `CLAUDE.md` - Detailed implementation notes and architecture guide
- `verif/README.md` - Verification infrastructure documentation
- `verif/scripts/Makefile` - Run `make help` for all targets

## License

Academic project for ECE 320 - Computer Architecture.
