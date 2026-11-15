# RV32IM Out-of-Order Processor (Scoreboarding)

An out-of-order RISC-V processor in Verilog using **scoreboarding** (in-order
dispatch, out-of-order issue/execute/writeback), with the same verification
layout as the scalar (`verilog/`) and superscalar (`verilog_ss/`) cores.

> **Status:** under construction. See `plan.md` for the phase-by-phase plan and
> `CLAUDE.md` for the design specification and current gaps. The core does not
> compile yet (Phase 1), so no benchmark passes.

Directory structure (same as `verilog/` and `verilog_ss/`):

```
verilog_ooo/
├── design/
│   ├── code/                 # RTL (pd.v top, scoreboard tables, decoder, ALU, memories)
│   ├── simple_testbenches/   # Self-checking unit testbenches (Icarus) + Makefile
│   ├── design_wrapper.v      # Top-level wrapper (instantiates pd as dut.core)
│   └── signals.h             # Maps OoO trace events to core signals
├── verif/
│   ├── tests/                # Testbench (test_pd.sv/.cpp), OoO event-trace writer
│   ├── scripts/              # Makefiles, design.f, spike/compare/parallel scripts, docker/
│   ├── data/                 # Reference test image (rv32ui-p-add.x)
│   ├── golden_sim/           # Known-good OoO traces (filled once benchmarks pass)
│   ├── spike_traces/         # Spike reference traces (generated)
│   ├── sim/                  # Simulation outputs (generated, gitignored)
│   ├── diffs/                # Compare reports (generated, gitignored)
│   └── README.md             # Verification flow and trace format
├── rv32-benchmarks/          # individual-instructions, simple-programs,
│                             # superscalar-tests, ooo-tests (OoO directed tests)
├── run_scripts.py            # Top-level runner: lint -> unit TBs -> benchmarks
├── plan.md                   # Implementation plan
├── CLAUDE.md                 # Design spec / handoff
└── README.md                 # This file
```

## Quick start

```sh
# Everything (lint, unit testbenches, build + simulate + spike-compare all suites)
python3 run_scripts.py

# Or step by step, from verif/scripts:
cd verif/scripts
make help                          # all targets and variables
make lint                          # Verilator lint + Icarus elaboration
make unit_tests                    # design/simple_testbenches
make run_and_verify BENCH=ooo-smoke
make run_all_benchmarks SUITE=ooo  # ooo | individual | simple | superscalar | all
```

Until branching is implemented (plan.md Phase 6) only the branch-free tests in
`rv32-benchmarks/ooo-tests/` can run to completion.

## How verification differs from the in-order cores

The OoO core writes registers back out of program order, so instead of diffing
per-cycle FDXMW traces against golden traces it records an **event trace**
(`[F] [D] [I] [X] [M] [W] [S]` lines) and `verif/scripts/cmp_ooo_spike.py`
checks it against spike: per-register write sequences, final register values,
and the ordered store list. Details: `verif/README.md`.

## Dependencies

Same as `verilog/README.md`: Verilator (5.x), Icarus Verilog, Python 3.9+,
`spike`, and `riscv64-unknown-elf-gcc` for building benchmarks. The Docker image
in `verif/scripts/docker/` provides the toolchain and spike.
