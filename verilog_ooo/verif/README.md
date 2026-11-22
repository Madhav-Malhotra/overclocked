# OoO Core Verification

Build, simulation and checking flow for the out-of-order core in `verilog_ooo/`.
Adapted from the scalar flow in `verilog/verif/` (copied, not shared — do not edit `verilog/`).
The folder layout matches `verilog/` and `verilog_ss/`.

```
.s test ──riscv gcc──> .elf ──spike──> spike trace (program order)
           │                                  │
           └──> .x ──Verilator sim of pd──> OoO event trace ──cmp_ooo_spike.py──> PASS/FAIL
```

## Quick start

```sh
# Everything at once (lint -> unit TBs -> build + simulate + spike-compare all suites)
python3 verilog_ooo/run_scripts.py              # --suite ooo|individual|simple|superscalar|all

# Or step by step, from verilog_ooo/verif/scripts:
make lint                          # Verilator lint + Icarus elaboration (errors + warning counts)
make unit_tests                    # design/simple_testbenches (Icarus)
make build_ooo_tests               # or build_benchmarks for all suites (needs riscv64-unknown-elf-*)
make run_and_verify BENCH=ooo-smoke
#    trace:  verilog_ooo/verif/sim/verilator/test_pd/ooo-smoke.trace
#    report: verilog_ooo/verif/diffs/spike/ooo-smoke.diff
make run_all_benchmarks SUITE=ooo  # parallel; reports in verif/diffs/spike/
```

`make help` lists every target and variable (`TIMEOUT`, `VCD`, `WARN`, `CMP_FLAGS`, ...).

## Layout

| Path | Purpose |
|---|---|
| `../design/signals.h` | Maps trace events to `pd` signals (`*_VALID` macros) |
| `../design/design_wrapper.v` | Instantiates `pd` as `dut.core` |
| `../design/simple_testbenches/` | Self-checking Icarus unit TBs (`make`, `make <name>`, `make RTL=<dir>`) |
| `tests/test_pd.{sv,cpp}`, `tests/clockgen.sv` | Top-level testbench (copied from the scalar flow) |
| `tests/tracegen.v`, `tests/trace_dump.h` | OoO event-trace writer + optional end-of-sim detection |
| `scripts/design.f` | **Single RTL file list** (used by `make lint` and `Makefile.verilator`) |
| `scripts/Makefile`, `scripts/Makefile.verilator` | Build/run/verify targets, incl. `make lint` (Verilator + Icarus) and `make unit_tests` |
| `scripts/run_benchmarks_parallel.py` | Parallel build → sim → spike → compare (`make run_all_benchmarks SUITE=...`) |
| `scripts/cmp_sim_trace.py` | Line-by-line diff of a sim trace vs a golden trace (`make diff_golden`) |
| `scripts/check_fatal.sh`, `scripts/check_warnings.sh` | Log checkers (as in the scalar flow) |
| `scripts/format.gtkw`, `scripts/waves.tcl` | GTKWave layout for OoO signals (`make waves_bench BENCH=...`); xsim VCD script |
| `scripts/docker/` | Docker image with toolchain + spike (`make -C docker build run_all_benchmarks`) |
| `scripts/spike_trace_gen.py` | Spike commit trace (register writes **and stores**) |
| `scripts/cmp_ooo_spike.py` | Order-insensitive compare (see below) |
| `golden_sim/` | Known-good OoO traces for regression (empty until benchmarks pass; see its README) |
| `data/rv32ui-p-add.x` | Same reference image as `verilog/` and `verilog_ss/` (contains branches: runs only once Phase 6 lands) |
| `spike_traces/` | Generated spike traces |
| `sim/`, `diffs/` | Generated (gitignored) |
| `../rv32-benchmarks/ooo-tests/` | OoO directed tests + `Makefile` (`make`, `make check_branch_free`) |

## Trace format

One line per **event** (not per cycle), each ending in `@<cycle>`:

```
[F] pc instr                                   fetch -> decode
[D] ist_idx pc fu rd rs1 rs2 rs1_tag rs2_tag   dispatch ("-" until ist_idx exists, Phase 2)
[D] - pc 0 nop                                 NONE-class instr (FENCE/unknown) consumed
[I] ist_idx pc fu op1 op2                      operands read, issued to its FU
[X] ist_idx pc fu result                       FU result valid
[M] pc addr size_bytes data                    data-memory write (store, D6: in EX)
[W] pc we rd data                              writeback (same fields as scalar [W])
[S] reason [reason...]                         dispatch stall started / reasons changed
[S] resume                                     dispatch stall ended
```

Values are hex except `fu`, `rd/rs*`, tags, `ist_idx`, `size_bytes` and the cycle (decimal).

**Adding events as stages land:** define the stage's macros in `design/signals.h`
(templates are there as `TODO(Phase N)` comments). An event whose `*_VALID` macro
is undefined is simply not printed — `trace_dump.h` does not need editing.
Defining `SIM_DONE` makes the run stop shortly after the core halts instead of
running to `TIMEOUT`.

## How the compare works (`cmp_ooo_spike.py`)

Writebacks are out of program order, so a commit-by-commit compare is wrong. Instead:

1. **Per-register sequences** — for each register, the ordered `(pc, value)` writes must equal spike's. Valid because the WAW dispatch stall keeps writes to one register in program order.
2. **Final register values** — summary of the last write per register.
3. **Stores** — the ordered `(pc, addr, size, data)` list must equal spike's (one store FU, reserved dispatch → WB, in-order dispatch ⇒ stores hit memory in program order).
4. Any write to `x0` fails.

Flags: `--allow-truncated` (sim stopped early: accept prefixes), `--skip-stores`
(before `[M]` exists). Pass through make with `CMP_FLAGS=...`.

## Writing OoO tests

- Until Phase 6 (branching), tests must be **branch-free**: no `b*`, `jal`, `jalr`, `j`, `call`, `ret`. `make check_branch_free` in `ooo-tests/` enforces this.
- End with the HTIF pass sequence, and write **1** (not 0) to `tohost` — spike only exits on an odd value:
  ```asm
  fence   iorw, iorw
  la      t0, tohost
  addi    a0, x0, 1
  sw      a0, 0(t0)
  ecall
  ```
  (`individual-instructions/template-test.s` writes 0 in `pass:`, which makes spike hang.)
- Put the expected out-of-order behaviour in the header comment (see `ooo-smoke.s`).

## Tools

Verilator ≥ 5, Icarus Verilog, Python 3.9+, `riscv64-unknown-elf-gcc`, `spike`.
The Docker image in `verilog/verif/scripts/docker/` provides the toolchain and spike if they are not installed locally.
