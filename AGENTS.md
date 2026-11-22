# AGENTS.md

Guidance for AI coding agents (Claude Code, Copilot, etc.) working in this repository.
Per-CPU details live in each CPU's `CLAUDE.md`; the out-of-order work plan is
`verilog_ooo/plan.md`. Read those before changing RTL.

## What this project is

**Overclocked** is a game similar to Overcooked in which players move
instructions through a CPU to learn computer architecture. The game (Unity)
drives a real Verilog CPU model, either through Verilator (native plugin) or
an FPGA (PYNQ-Z2) behind a web API.

| Directory | Contents |
|---|---|
| `unity/` | Unity game project (C#) |
| `bridge/` | C# `ICPU` interface + clients for the Verilator model and the FPGA webserver (scalar and superscalar variants) |
| `verilator/` | Builds a Verilog CPU into a native library for Unity (`design_wrapper.v`, `signals.h`, `bridge*.cpp`) |
| `webserver/` | FastAPI service on the PYNQ-Z2 exposing CPU control/state |
| `verilog/` | **5-stage pipelined** RV32I(+MUL) CPU — done |
| `verilog_ss/` | **2-way superscalar** in-order CPU — done |
| `verilog_ooo/` | **Out-of-order CPU using scoreboarding** — in progress (current focus) |

## Current focus: the out-of-order CPU (`verilog_ooo/`)

- **Microarchitecture:** scoreboarding — in-order fetch and dispatch,
  out-of-order issue, execute and writeback; three tables (instruction status,
  functional-unit status, register status). Not Tomasulo, no register
  renaming, no reorder buffer.
- **ISA:** RV32I plus a subset of the M extension: `MUL`, `DIV`, `DIVU`.
  `MULH`/`MULHSU`/`MULHU`/`REM`/`REMU` are not supported; programs never contain them.
  `ECALL` is a bubble: it runs on an ALU slot as an ADD of zeros, writes no
  register, and does not halt or trap (plan.md D8).
- **Multiplier:** the multicycle multiplier (`array_mult`, the MCM functional
  unit) is **mandatory**. Every `MUL` executes on the MCM; the ALU never
  multiplies, not even as a fallback. This differs from `verilog/` and
  `verilog_ss/`, where `USE_MULTICYCLE_MULT` selects between the multicycle
  unit and a single-cycle ALU multiply — do not add that parameter to the OoO
  core. `DIV`/`DIVU` execute in the ALU.
- **Functional units:** branch, MCM, load, store, ALU, ALU_2 (FU ids 1–6; 0 = NONE).
- **Plan and design decisions:** `verilog_ooo/plan.md` §1 (decisions D1–D8) and
  its phases. Work phase by phase; each phase has a "done when" check. Branching
  is designed and implemented only after all five stages are connected (Phase 6).
- **Sequence numbers are for testing only** — never use them in hardware decisions.

## Rules

### Directory structure
Keep `verilog_ooo/` **structurally identical** to `verilog/` and `verilog_ss/`:

```
verilog_*/
├── CLAUDE.md, README.md, run_scripts.py
├── design/
│   ├── code/                 # RTL (top module `pd` in pd.v)
│   ├── simple_testbenches/   # standalone unit testbenches
│   ├── design_wrapper.v      # instantiates `pd` as `core`
│   └── signals.h             # signal names used by the trace/bridge
├── rv32-benchmarks/          # individual-instructions, simple-programs, superscalar-tests (+ ooo-tests)
└── verif/
    ├── data/  diffs/  golden_sim/  spike_traces/  tests/
    └── scripts/              # Makefile, Makefile.verilator, design.f, docker/, python tools
```

New files go into the matching existing folder. Do not create new top-level
folders inside a CPU directory. OoO-only additions (for example
`rv32-benchmarks/ooo-tests/`, `verif/scripts/cmp_ooo_spike.py`) sit inside the
standard folders.

### Do not touch the finished CPUs
Do not modify `verilog/` or `verilog_ss/` while working on the OoO core. To
reuse a module or script, **copy** it into `verilog_ooo/` and adapt the copy.

### Keep conventions consistent with `verilog/` and `verilog_ss/`
- Top module `pd`, wrapped by `design/design_wrapper.v` as `dut.core`; the
  RTL file list is `verif/scripts/design.f`.
- Every module starts with the header block used across the repo:
  ```verilog
  // =============================================================================
  // Module:      <name>
  // Description: <what it does>
  // Inputs:      <port> - <meaning>
  // Outputs:     <port> - <meaning>
  // =============================================================================
  ```
  and uses `// ====================` section banners inside.
- Parameters `DATAW`, `ADDRW`, `BASE_ADDR` (`32'h01000000`); `localparam`s in
  UPPER_CASE; signals in `snake_case` with a stage prefix (`f_`, `d_`/`ds_`,
  `iss_`, `wb_`; the in-order cores use `_fd/_dx/_xm/_mw`).
- Clocked blocks use non-blocking assignments only; combinational logic in
  `always @(*)` or `assign`. Synchronous active-high `reset`.
- Memory macros `MEM_PATH`, `LINE_COUNT`, `MEM_DEPTH` come from the build.
- No `.vh` include files in `design/code/` or `design/simple_testbenches/`. A
  constant needed by several modules (for example the FU ids) is a `localparam`
  copy in each module, with a comment naming the other modules that must match.
  Unit testbenches are self-contained `*_tb.v` files. (The existing harness
  headers `design/signals.h` and `verif/tests/trace_dump.h`, shared with the
  other CPUs, are the only included files.)
- Writes to `x0` are prevented by control logic, not by the register file.
- Keep internal state in clearly named registers/wires: the game and the
  bridge read internal signals (via `signals.h` / Verilator public signals) to
  show instructions moving through the CPU.

### Naming and checks
- Give new signals, registers and parameters explicit, explanatory names (for
  example `free_row_idx`, `iss_row_idx`, `iss_ist_idx`) **and** put a short
  comment beside each declaration saying what it is for.
- Names must not use "packet"/`pkt`, "launch" or "fire".
- Use the **ready/valid** convention for handshakes: the producer drives
  `<name>_valid` and its data, the consumer drives `<name>_ready`, and a
  transfer happens when both are high (issue → FU: `iss_valid` + `iss_*`,
  `fu_ready`; FU → writeback: `result_valid`, `wb_ready`). Trace-event macros
  in `signals.h` are `*_VALID`.
- Do not add checks for values or conditions that the design already
  guarantees (for example re-checking that a dispatched FU id is not NONE when
  `ds_en` already requires it, or guarding against instructions the programs
  never contain). Do not add simulation assertions for such cases either.

### Tests and documentation: build once, not iteratively
Do not keep re-editing tests or docs after every small change.
- **Tests:** write new tests against the behaviour and interfaces of the
  **fully complete scoreboarding CPU** (as specified in `plan.md`), so they do
  not need rewriting later. Directed programs go in
  `rv32-benchmarks/ooo-tests/` and are checked against spike. Until branching
  exists (Phase 6), they must be branch-free (`make check_branch_free`).
- **Unit testbenches** for a module are written or updated when that module's
  interface is final for the plan, not at every intermediate step.
- **Documentation** (`verilog_ooo/CLAUDE.md`, `README.md`s, `verif/README.md`)
  is refreshed once in the final documentation phase of `plan.md`, not after
  every phase. During the work, record progress only in `plan.md`
  (checkboxes and the status log).

## Commands (OoO core)

```sh
cd verilog_ooo/verif/scripts
make help                          # all targets
make lint                          # Verilator lint + Icarus elaboration (VERBOSE=1 for full log)
make unit_tests                    # design/simple_testbenches (Icarus)
make build_benchmarks              # assemble all benchmark suites (needs riscv64-unknown-elf-*)
make run_and_verify BENCH=ooo-smoke
make run_all_benchmarks SUITE=ooo  # ooo | individual | simple | superscalar | all

cd verilog_ooo && python3 run_scripts.py   # lint -> unit tests -> all benchmarks
```

Verification compares the core's event trace with spike using
`verif/scripts/cmp_ooo_spike.py`. Because writeback is out of order, it compares
per-register write sequences, final register values and the store order — not
a commit-by-commit order. Trace format and flow: `verilog_ooo/verif/README.md`.

Tools: Verilator 5.x, Icarus Verilog, Python 3.9+, `spike`,
`riscv64-unknown-elf-gcc` (or the Docker image in `verif/scripts/docker/`).

## Working practices
- Before changing the scoreboard, read `pd.v`, `instr_status.v`,
  `func_unit_status.v` and `reg_status_table.v` together; they are tightly coupled.
- Keep the producer FU tag, the architectural register number and the
  instruction identity distinct.
- A phase is done only when its "done when" check in `plan.md` passes; report
  failing checks as failures.
- Commit or push only when asked. Work happens on the `hw/ooo` branch; PRs
  target `main` and use `pull_request_template.md`.
- Bridge/Unity integration of the OoO core (`verilator/`, `bridge/`, `unity/`)
  is out of scope until the core is complete; coordinate with the team first.
