# Out-of-Order RV32 CPU — Implementation Plan

> Companion to `verilog_ooo/CLAUDE.md` (the design spec/handoff). CLAUDE.md describes *what exists and what is intended*; this file describes *the order of work to get there*. Update the checkboxes and the "Status log" at the bottom as phases land.
>
> **How to use this file when prompting Claude:** say e.g. *"Do Phase 1 of `verilog_ooo/plan.md`"* or *"Continue plan.md from task 3.4"*. Each phase lists its tasks, the files involved, and a "done when" check. Do phases in order: each one assumes the previous one compiles and passes its checks. Before starting any phase, re-read §1 (decisions) — they constrain every phase.

---

## 0. Context

**Branch:** `hw/ooo`. **Commit at time of writing:** `1737ab8` ("Worked on the issuing stage…").

The OoO core (`verilog_ooo/`) is a **scoreboarding** design (not Tomasulo, no ROB). What exists today:

| Piece | File | State |
|---|---|---|
| Fetch (PC+4, no redirect) | `design/code/pd.v` | Written; no redirect |
| Decode + FU classification | `design/code/decoder.v` | Done |
| Dispatch (in-order, WAW stall, FU-slot check, branch drain placeholder) | `design/code/pd.v` | Written, not verified |
| Instruction Status Table (6 rows) | `design/code/instr_status.v` | Keyed by `ist_idx`, issue read port; unit-tested (Phase 2) |
| Functional Unit Status Table (6 rows, one per FU) | `design/code/func_unit_status.v` | Smallest-PC issue select + `iss_valid`/`iss_*` issue signals; unit-tested (Phase 2) |
| Register Status Table (32 entries) | `design/code/reg_status_table.v` | Done |
| Register file, ALU, branch_comp, imem, dmem, writeback mux | `design/code/*.v` | ALU/dmem connected through the FUs (Phase 3); branch_comp and writeback mux not connected |
| Execution units | `design/code/alu.v` (ALU FU), `array_mult.v` (MCM FU), `load.v`, `store.v` (2-cycle, on `dmemory.v`); `control_signals.v` (Execute + Writeback controls) | Done (Phase 3); branch FU (`branch.v`) in Phase 6 |
| Completion / writeback | — | **Missing** (Phase 4) |
| Branching strategy + redirect | — | **Not decided, not implemented** |
| Build, testbench, trace compare | `verif/`, `design/simple_testbenches/`, `run_scripts.py` | **Done (Phase 0)** — see `verif/README.md` |

**Goal, in order:**
1. Build and connect the five stages — **Fetch, Decode/Dispatch, Issue, Execute, Writeback** — and prove them on straight-line (branch-free) programs, with independent instructions really executing/completing out of order.
2. Then decide and implement the scoreboard branching strategy.
3. Then run the full `rv32-benchmarks` suites and integrate the sequence-number test logic from `hw/ooo_spike`.

### Ground rules (see also the repo-root `AGENTS.md` — keep obeying)
- Never modify `verilog/` or `verilog_ss/`. **Copy** modules/harness pieces into `verilog_ooo/` instead.
- Keep **producer FU tag**, **architectural rd**, and **instruction identity** distinct.
- Read `pd.v`, `instr_status.v`, `func_unit_status.v`, `reg_status_table.v` together before changing interfaces.
- New assembly tests go in `rv32-benchmarks/ooo-tests/`.
- Keep the directory structure identical to `verilog/` and `verilog_ss/`, and follow their conventions (module header blocks, naming, `pd` top, `design.f`, `signals.h`).
- The multicycle multiplier (MCM) is mandatory: no `USE_MULTICYCLE_MULT`-style toggle, no ALU multiply (D7).
- **File names follow `verilog/` and `verilog_ss/`; each functional unit has its own file.** Where `verilog/` already has a file for the unit, its FU logic goes into that file (no duplicate wrapper): `alu.v` is the ALU FU, `array_mult.v` the MCM FU, `branch_comp.v` the branch FU (comparator + target adder in one file). FUs without a counterpart get their own file named after the unit, **without an `fu_` prefix**: `load.v`, `store.v`. Shared helpers keep their `verilog/` names and roles (`dmemory.v` = data memory, `writeback.v`). Other new files only for OoO-only structures (the three scoreboard tables, `min_pc_select.v`).
- **Shared code stays the same as in `verilog/` and `verilog_ss/`.** When a file contains logic that the other CPUs also have, keep that code identical (same signal names, structure, comments); change only what the OoO core needs, and say why in the module header. Do not re-implement or duplicate logic that a module already holds (e.g. no copy of the ALU op encoding in `pd.v`). Control decode lives in `control_signals.v`, organised like the scalar file (per-stage controls: `a_sel`, `b_sel`, `alu_sel`, `reg_wen`, `wb_sel`, with the same encodings); the ALU executes on `alu_sel` like `verilog/alu.v`. As of Phase 3, `branch_comp.v`, `writeback.v`, `register_file.v`, `imemory.v` are identical to `verilog/`; `alu.v`, `array_mult.v`, `control_signals.v`, `decoder.v`, `dmemory.v` differ only by their documented OoO changes.
- **No `.vh` include files** in `design/code/` or `design/simple_testbenches/` (only the existing harness headers `signals.h`/`trace_dump.h` are included, as in the other CPUs). Constants shared by several modules (e.g. FU ids) are a `localparam` copy in each module, with a comment saying which other modules must match. Unit TBs are self-contained `*_tb.v` files.
- **Explicit names, with a comment.** Every new signal/register/parameter gets a descriptive name and a short comment at its declaration saying what it is for. Names must not use "packet"/`pkt`, "launch" or "fire". The `iss_` prefix is only for issue-stage signals (in `pd.v`, `func_unit_status`, `instr_status`); inside an FU, ports and registers use execute-stage names: `ex_valid` for the handed-over instruction, operands like `idata1`/`idata2`/`pc`/`funct3`, and per-EX-cycle register prefixes `addr_` (address cycle), `mem_` (memory cycle), `cmp_` (branch compare cycle).
- **Ready/valid handshakes.** Stage-to-stage and stage-to-FU interfaces use the ready/valid convention: the producer drives `<name>_valid` plus its data signals, the consumer drives `<name>_ready`; a transfer happens in a cycle where both are high. Issue → FU: `iss_valid` + `iss_*` data, `fu_ready[id-1]`. FU → WB: `result_valid` + result, `wb_ready`. Trace-event macros in `signals.h` are `*_VALID`.
- **Build tests and docs once, not iteratively.** New tests target the behaviour and interfaces of the *finished* scoreboarding CPU. A unit testbench is written/updated when its module's interface is final in this plan. `CLAUDE.md`, the READMEs and `verif/README.md` are **not** edited per phase — they are refreshed once in Phase 9. During Phases 2–8, record progress only in this file (checkboxes, "as built" notes, status log).

### Tools available locally
- `iverilog` and `verilator` (both in `/opt/homebrew/bin`).
- `riscv64-unknown-elf-gcc` (`~/riscv/bin`) and `spike` (`/opt/homebrew/bin`) are installed (found in Phase 0). Build images with `make build_benchmarks` in `verif/scripts`. Fallback: the docker flow in `verilog/verif/scripts/docker/`.

---

## 1. Design decisions

These are the decisions every phase assumes. **Team-confirmed** items are fixed; **default** items are this plan's choice and may be changed (update here first, then the affected phases).

| ID | Decision | Status |
|---|---|---|
| D1 | **Instruction identity = instr_status row index (`ist_idx`).** Tables are keyed by `ist_idx`, not by PC matching. **Sequence numbers are for testing only** — they must not drive any hardware decision (issue, writeback priority, memory ordering, clearing). A proof-of-concept of the seq-number test logic exists on the **`hw/ooo_spike`** branch (implemented in the scalar CPU); it is integrated into the OoO core later (Phase 8), test-only. | **Team-confirmed** |
| D2 | **Ordering/priority uses PC.** Writeback picks the **smallest PC** among WB-ready instructions (the original spec rule). Issue also picks the smallest-PC ready row, and memory ordering (D6) compares PCs. This is a correct program-order proxy **only while no instruction is dispatched past an unresolved branch** (true with the current branch-drain placeholder: all in-flight instructions are from one straight-line run, so PC increases with program order). **Phase 6 must re-check this** if the branching strategy lets instructions past a branch be in flight (loops ⇒ PC ≠ age). Both issue and WB use one shared `min_pc_select` module (task 2.4a). | **Team-confirmed** (issue + WB) |
| D3 | **Result holding.** Each FU keeps its result in an output register with a `done` flag until WB grants it. The FU row stays reserved (`busy_arr`) dispatch → WB, as `func_unit_status` already does. | Default |
| D4 | **WAR check at WB.** A completing instruction writing `rd` waits while **any other reserved FU row has not yet read its operands, uses `rd` as a source, and that source's tag is 0** (i.e. it intends to read the *old* value from the RF). No age compare is needed because the WAW dispatch stall guarantees a single producer per register. | Default |
| D5 | **Branches: strategy not decided.** The current `br_busy` branch drain in `pd.v` is a **placeholder** and may change. The **branch FU set-up is built early (Phase 3, task 3.10)**: `branch.v` computes the target and decides taken/not taken, but the outcome is **not yet used**: no fetch redirect, no flushing, no stalling on it. The branching *strategy* (redirect, what happens past an unresolved branch, squash) is designed and implemented **only after all five stages are implemented and connected** (Phase 6). Until then, test programs are **branch-free** (ending in `ecall`). | **Team-confirmed** |
| D6 | **Stores write memory in Execute.** Loads and stores take **two EX cycles after their issue cycle**: EX cycle 1 computes the effective address (`rs1 + imm`) with the FU's own adder, EX cycle 2 accesses `dmemory`. The store FU asserts `dmemory.w_en` in EX cycle 2; the write completes at the end of that cycle, so **the written data is visible in memory by WB**. The store's WB only releases its scoreboard state (no `rd`). Because memory is modified at EX, memory ordering is enforced **at issue** (both FUs take the same two cycles, so the older access reaches memory first): a load may not issue while a smaller-PC store is reserved and hasn't executed (memory RAW), and a store may not issue while a smaller-PC load is reserved and hasn't executed (memory WAR). Store→store order is automatic (one store FU, reserved until WB, in-order dispatch). With this rule a load and a store never access `dmemory` in the same cycle, so its `w_pc < r_pc` store→load forward is never used (that PC compare would only be valid under D2's assumption). | **Team-confirmed** (EX write); ordering rule is default |
| D7 | **MCM is a core FU and the only multiply path.** **Only `MUL` is implemented** (low 32 bits of the product); it always dispatches to the MCM slot. `MULH/MULHSU/MULHU` are **out of scope** — programs never contain them, so the decoder has no special handling for them. **All multiply logic is removed from `alu.v`** (the unused `MUL` selector and the stale `array_mult`/`multicyc_sel`/`mult_*` header text) — the ALU is never used for multiply, not even as a fallback. MCM uses a copy of `verilog/design/code/array_mult.v` (multicycle, `start_pulse`/`busy`). | **Team-confirmed** |
| D7a | **Divide executes in the ALU; remainder is not supported.** `DIV/DIVU` dispatch to an ALU slot (`ALU`/`ALU_2`) and execute in `alu.v`. MCM handles **multiplication only**. `REM/REMU` are **out of scope** — programs never contain them. Decoder: `is_mcm` matches `MUL` only (`funct7 == 0x01 && funct3 == 000`); `DIV/DIVU` reach `ALU` through the normal R-type path. | **Team-confirmed** |
| D8 | **ECALL / FENCE / unknown.** **ECALL is a bubble that executes as an ADD of zeros:** it dispatches to an ALU slot (`ALU`/`ALU_2`), uses no source registers (rs1 field = x0, imm = 0, so the ALU computes 0 + 0) and writes no `rd` (`writes_rd = 0`). It goes through issue, execute and writeback like any ALU op and frees its rows at WB with no effect on state. There is **no halt**: fetch continues after an ECALL; no trap or environment call is performed. The decoder already implements this (`is_ecall` → `ALU`, `uses_rs1/2 = 0`, `writes_rd = 0`). FENCE/unknown → existing `NONE` no-op path (no table rows). | **Team-confirmed** |

---

## Phase 0 — Build & verification scaffolding

Every later phase needs a compile + sim check, so do this first.

- [x] **0.1 Lint/elaborate target.** Add a lint step (now `make lint` in `verif/scripts`) that runs:
  `verilator --lint-only -Wall -Wno-fatal --top-module pd -DMEM_PATH='"dummy.x"' -DLINE_COUNT=1 -DMEM_DEPTH=1048576 -f ../../verif/scripts/design.f`
  and `iverilog -g2012 -s pd -o /dev/null …`. Commit `verif/scripts/design.f`.
- [x] **0.2 Copy the scalar harness.** Copy `verilog/verif/{tests,scripts}` → `verilog_ooo/verif/`, and `verilog/design/{design_wrapper.v,signals.h}` → `verilog_ooo/design/`. Fix paths in `verif/scripts/Makefile`, `Makefile.verilator`, `design.f` to point at `verilog_ooo/design/code`.
- [x] **0.3 OoO trace format.** Replace the in-order FDXMW `trace_dump.h`/`fields.h` with event lines (printed only when the event happens):
  - `[F] pc instr`
  - `[D] ist_idx pc fu_id rd rs1 rs2 rs1_tag rs2_tag` (dispatch)
  - `[I] ist_idx pc fu_id op1 op2` (operands read / issued to the FU)
  - `[X] ist_idx pc fu_id result` (FU done; stores also print `addr size data`)
  - `[W] pc we rd data` — **same format as the scalar `[W]` line** so `cmp_wb_spike.py` parsing can be reused
  - `[S] reason` optional stall reason (WAW / FU busy / buffer full / branch drain / WAR / mem order)
  
  (No seq field yet — seq numbers arrive in Phase 8, test-only.)
- [x] **0.4 Program images.** Get a RISC-V toolchain (docker in `verilog/verif/scripts/docker/`, or local) and build `.x` + `.elf` with `rv32-benchmarks/individual-instructions/Makefile.new` and `simple-programs/Makefile`. Copy `verilog/verif/scripts/spike_trace_gen.py` for spike commit traces. Without a toolchain, hand-assemble tiny `.x` files for the Phase 5 tests.
- [x] **0.5 OoO-aware compare** `verif/scripts/cmp_ooo_spike.py`: writebacks are out of program order, so compare **(a)** the per-register sequence of written values (must match spike exactly — the WAW stall keeps writes to one register ordered), **(b)** the final register file, **(c)** per-address store sequences. Exit 0/1.
- [x] **0.6 Unit testbenches** (iverilog, `verilog_ooo/design/simple_testbenches/`): `reg_status_table_tb.v`, `instr_status_tb.v`, `func_unit_status_tb.v`. Self-checking (`$fatal` on mismatch); `make` in that directory runs all of them.

**Done when:** `make lint` runs (it will report the Phase 1 errors) and `make` in `verilog_ooo/verif/scripts` builds a Verilator sim of `pd`.

**Phase 0 as built (2026-11-15)** — full usage in `verif/README.md`:
- `make lint` in `verif/scripts` (prints errors + per-category warning counts; `VERBOSE=1` for everything; also `lint_verilator`, `lint_iverilog`). `verif/scripts/design.f` is the **single** RTL list; `verif/scripts/Makefile.verilator` reads it too.
- Trace: `[F] [D] [I] [X] [M] [W] [S]` event lines ending in `@cycle`. Each event is enabled by `*_VALID` macros in `design/signals.h` (named `*_FIRE` until 2026-11-22); `[I] [X] [M]` and `SIM_DONE` are `TODO(Phase N)` templates there. `[S]` logs only on stall start/change plus `[S] resume`. Stores are a separate `[M]` event (not part of `[X]`).
- `verif/scripts/spike_trace_gen.py` (copy) also emits store lines `S pc addr size data` and searches `ooo-tests/`. `cmp_ooo_spike.py` options: `--allow-truncated`, `--skip-stores`, `--out`.
- `rv32-benchmarks/ooo-tests/`: `Makefile` (`make`, `make check_branch_free`) + `ooo-smoke.s` (branch-free smoke test). Toolchain + spike turned out to be installed locally (`~/riscv/bin`, `/opt/homebrew/bin/spike`); all 41 individual-instruction and 10 simple-program images build.
- Unit TBs: `design/simple_testbenches/` (`make`; `make RTL=<dir>` to test another RTL copy). `reg_status_table` passes. `instr_status` and `func_unit_status` **fail to compile until Phase 1** — expected. Each TB was validated against a scratch RTL copy with the minimal Phase 1 fixes applied (all 3 then pass).
- **Layout:** directory structure is identical to `verilog/` and `verilog_ss/` (`design/{code,simple_testbenches}`, `verif/{data,diffs,golden_sim,scripts/docker,spike_traces,tests}`, root `README.md` + `run_scripts.py`). Scalar-only files with no OoO meaning (`test_stage_en.*`, `fields.h`, `cmp_wb_spike.py`) are intentionally absent; OoO-only additions: `cmp_ooo_spike.py`, `ooo-tests/`, `simple_testbenches/Makefile`. `verif/data/rv32ui-p-add.x` matches the other CPUs, but the Makefile default `MEM_PATH` stays `ooo-tests/ooo-smoke.x` because rv32ui-p-add needs branches.
- `make all` in `verif/scripts` **cannot build `pd` until Phase 1** (compile errors). Validated against the same scratch-fixed RTL: Verilator builds, sim runs to TIMEOUT, trace shows 2 dispatches then a permanent `fu_busy` stall (nothing writes back yet), and `cmp_ooo_spike.py` reports the missing writes. That is the expected Phase 0 baseline.
- Note: `individual-instructions/template-test.s` writes 0 to `tohost` in `pass:`, which makes spike hang; OoO tests must write 1.

---

## Phase 1 — Make the existing RTL elaborate and well-typed

Fixes only; no new features.

**`instr_status.v`**
- [x] 1.1 `reg [FW-1:0] fu_arr` → `FUW`.
- [x] 1.2 `num_instr <= … (done ? 1:0) …` → `done_ds`; delete the earlier `num_instr <= num_instr - 1` inside `if (wb_en)` (it is overridden by the later assignment anyway).
- [x] 1.3 `rs1_arr/rs2_arr/rd_arr` are `[DATAW-1:0]` → `[ADDRW-1:0]`.
- [x] 1.4 `num_instr` width `$clog2(6)=3` → `$clog2(NUM_BUFFER_ROWS+1)` so "full" is representable for any size.
- [x] 1.5 `initial` block uses `<=` → `=` (or drop it; reset covers it).
- [x] 1.6 `done_ds` is a module-level `reg` written with `=` in a clocked block → compute the free row combinationally (`ds_free_idx` priority encoder as a wire) and export it as `ds_ist_idx` (needed for D1).

**`func_unit_status.v`**
- [x] 1.7 Declare `output reg [FUW-1:0] iss_fu_id` (assigned but undeclared).
- [x] 1.8 `iss_row_index`, `iss_fu_id`, `iss_instr_found`, `iss_tag_found`, `issued_arr[i]` mix `=` and `<=` in one clocked block → split into a **combinational issue-select block** (`always @(*)` → `sel_valid`, `sel_idx`) and a **clocked block** using only `<=`.
- [x] 1.9 `if (issued[iss_row_index])` indexes the 1-bit output `issued` → `issued_arr` (block is redesigned in Phase 2 anyway).
- [x] 1.9a **Confirmed by `func_unit_status_tb`:** `iss_instr_found <= 0` (non-blocking default, ~line 143) overrides the later blocking `iss_instr_found = 1` in the same block, so **`iss_instr_found` never goes high** (same for `iss_fu_id`, `iss_tag_found`). Task 1.8's restructure fixes this; re-run `make` in `design/simple_testbenches` to confirm.
- [x] 1.10 ~~Guard dispatch writes with `ds_fu_id != NONE`~~ — dropped: `ds_en` already requires an assigned FU, so no extra check is needed.

**`pd.v`**
- [x] 1.11 `wire iss_rs1_data; wire iss_rs2_data;` are 1-bit and declared after use → `wire [DATAW-1:0]`, move to the Issue declarations.
- [x] 1.12 `iss_valid` is used (in the `instrStatus` port list) before it is declared → move the declaration up.
- [x] 1.13 Trailing comma after `.wb_data(wb_data),` in the `funcStatus` instance → remove; connect `.busy(fu_busy)` with a `wire [NUM_FU-1:0] fu_busy = 0;` placeholder until Phase 3.
- [x] 1.14 Connect `.iss_instr_found(...)` and `.iss_tag_found(...)` to declared wires.
- [x] 1.15 Fill in the `pd` header comment.
- [x] 1.15a `pd.v` passes `.NUM_REGS(NUM_REGS)` to `functional_unit_status`, which has no `NUM_REGS` parameter → remove it (elaboration error once the syntax error is fixed).
- [x] 1.16 Make `reg_status_table`'s default `NUM_LOAD_STORE` (2) consistent with the rest (1).

**`alu.v`** (D7, D7a)
- [x] 1.17 Remove the `MUL` localparam and the stale header text about `array_mult`, `multicyc_sel`, `mult_start_pulse`, `mult_hold`, `mult_busy`. Drop the unused `clock`/`reset` ports if nothing needs them. **Keep `DIV`/`DIVU`.**
- [x] 1.18 Update `alu.v`'s header comment op list to match (RV32I ops + `DIV`/`DIVU`; no multiply).

**`decoder.v`** (D7a)
- [x] 1.19 Narrow `is_mcm` to `MUL` only: `opcode == 0110011 && funct7 == 7'h01 && funct3 == 3'b000`. `DIV/DIVU` (`funct7 == 7'h01`, `funct3 = 100/101`) fall through to `ALU` (they already satisfy `is_alu`). No handling for `MULH*`/`REM*` (programs never contain them). (The FU-classification list in CLAUDE.md §3 was updated during Phase 1, before the "docs once" rule; Phase 9 re-checks it.)

**Done when:** `make lint` has no errors (warnings about unconnected EX/WB are fine); `make unit_tests` in `verif/scripts` passes all 3 TBs; `make all` in `verif/scripts` (default `ooo-smoke`) reaches TIMEOUT and the trace shows `[D]` lines until the FU slots fill (nothing completes yet — expected).

**Phase 1 as built (2026-11-15):**
- `make lint`: no errors (remaining warnings: unused fields/ports that Phases 2–3 consume, `dmemory`/`imemory` width/undriven from the shared modules, `initial`-value regs in `pd.v`).
- `make unit_tests`: 5/5 pass — added `decoder_tb.v` (MUL→MCM, DIV/DIVU→ALU, MULH*/REM*→NONE, all RV32I classes, x0 rules) and `alu_tb.v` (all selectors, DIV edge cases, old MUL selector returns 0). `func_unit_status_tb` now models the register file's one-edge read latency and checks operand capture (incl. back-to-back issue).
- `make all` (ooo-smoke): builds, runs to TIMEOUT; trace shows `[D] 0 …`, `[D] 1 …` (ist_idx now traced via `D_IST_IDX`), then `[S] fu_busy` because nothing writes back yet. `run_scripts.py --suite ooo`: lint PASS, unit PASS, benchmark FAIL (missing writes) — expected until Phase 4.
- Extra fixes made while touching the same code (beyond the listed tasks):
  - `func_unit_status`: register-file read data is captured one edge after the address is driven, into the row that was read (`rf_capture_valid`/`rf_capture_row`) — previously it was captured a cycle early into the wrong row. Dispatch clears the row's `rs*_fwd` flags (stale forwarded values were reused). `iss_tag_found` now means "some otherwise-ready row waits on a tag".
  - `pd`: `iss_valid` = `iss_instr_found` (one pulse per issue) instead of the sticky `issued` flag.
- Still open for Phase 2 (unchanged by design): no RF write→read bypass (a WB in the same cycle as an RF read returns the old value), row-index issue priority (not smallest PC), PC-keyed `instr_status`.

---

## Phase 2 — Instruction identity + a clean issue/read-operands handshake

**Files:** `instr_status.v`, `func_unit_status.v`, `pd.v`, new `min_pc_select.v`.

- [x] 2.1 **FU-ID constants.** ~~Shared `ooo_defs.vh` include~~ — dropped: `.vh` include files are not part of the repo convention. Each module that needs the FU ids (`NONE, BRANCH, MCM, LOAD, STORE, ALU, ALU_2`) declares its own `localparam` copy with the same values (as `verilog/` does for the ALU ops in `alu.v` and `control_signals.v`), with a comment naming the other modules that must match.
- [x] 2.2 **Key instr_status by `ist_idx` (D1).** At dispatch, write `ds_ist_idx` into the FU row. Replace the PC-match loops (`iss_pc`, `wb_pc`) with direct `iss_ist_idx` / `wb_ist_idx` indexing. PC stays stored (used for D2 priority and tracing). Add a combinational read port: given `iss_ist_idx`, output `opcode, funct3, funct7, imm, shamt, rd, pc` (the commented-out `iss_*` ports in `pd.v`). Stage field: `DS` on dispatch, `IS` on select, `EX` when it is issued to its FU (`iss_valid`), `WB` at writeback (the row's valid bit is cleared at the same time). `WB` is a real stage value and stays in the final design; it is not debug-only.
- [x] 2.3 **FU row additions** (`func_unit_status.v`): store `uses_rs1`, `uses_rs2`, `rd`, `writes_rd`, `ist_idx`, `pc` (already), `ops_read` (operands captured). Keep `rs*_tag`, `rs*_data`, `rs*_fwd`.
- [x] 2.4 **Issue pipeline (fixes CLAUDE.md §6 item 8):**
  - **Cycle N — select (comb):** among rows with `busy_arr && !issued && fu_ready[i] && rs1_tag==0 && rs2_tag==0` (+ D6 memory-order gating, added in 3.6), pick the **smallest PC** (D2) via `min_pc_select` (2.4a). Drive `iss_rs1/iss_rs2` to the RF combinationally from that row.
  - **Edge N→N+1:** RF registers its read data; FU status registers `iss_row_idx <= issue_sel_row`, `iss_valid <= iss_sel_valid`, sets `issued_arr[issue_sel_row]`.
  - **Cycle N+1 — read operands:** `op = rs_fwd ? rs_data_arr : (rf_bypass ? wb_data_q : rf_data)`. **RF bypass is required:** if a WB in cycle N wrote the register being read, the RF's registered output is stale, so register `wb_en && wb_writes_rd && wb_rd == src` and `wb_data` alongside the read. Drive the **issue signals** (`iss_valid` + `iss_*` data: fu_id, ist_idx, op1, op2, decoded fields) to the FU; set `ops_read`.
  - One issue per cycle; back-to-back issue must work (read stage of N+1 overlaps select of N+1).
- [x] 2.4a **`design/code/min_pc_select.v`** — reusable combinational selector: inputs `valid[N-1:0]` and `pc[N]` (flattened `N*DATAW` bus), outputs `min_pc_valid`, `min_pc_idx`, `min_pc_onehot`. Implement as a **balanced comparison tree** (6 rows → 3 → 2 → 1: 5 full-width 32-bit `<` comparators, 3 comparator levels deep), with invalid inputs losing every compare; ties are impossible under D2 but break toward the lower index. Parameterised on `N`, `DATAW`. Use full-width PCs — do **not** truncate to low bits: a 33-cycle `MUL` can stay in flight while many younger instructions dispatch and retire, so the PC distance between in-flight rows is not tightly bounded. Replaces the current first-found `for` loop / `done_is` flag in `func_unit_status.v`. Own unit TB `min_pc_select_tb.v` (random valid masks/PCs vs. a behavioural reference).
- [x] 2.5 Phase 2 fixes the table interfaces for the rest of the plan, so rewrite `instr_status_tb.v` / `func_unit_status_tb.v` against them **once** here (ist_idx keying, issue signals), plus new `min_pc_select_tb.v`. Unit-test in `func_unit_status_tb.v`: two independent rows issue on consecutive cycles with correct operands; a tagged row waits, then issues after a WB broadcast with the forwarded value; same-cycle WB + read of one register returns the new value; the smaller-PC ready row wins.

**Done when:** unit TBs pass; full sim shows `[I]` lines with correct operand values (still no writeback).

**Phase 2 as built (2026-11-22):**
- `make lint`: no errors. `make unit_tests`: 6/6 pass (`func_unit_status_tb` 120 checks, `instr_status_tb` 73, new `min_pc_select_tb` 11 900 incl. 2 000 random trials at N=6 and N=5). Both new TBs were confirmed to fail on mutated RTL (selector picking the larger PC; forwarding removed).
- Full sim: `ooo-smoke` shows `[I] 0 …` and `[I] 1 …` and then stalls on `fu_busy` (no WB yet). A scratch program (`add x5,x2,x2; lw x6,4(x2); sw x2,8(x2); ecall`) showed the right operands (sp = `0x01100000`) on every `[I]` line, and ECALL dispatched to `ALU_2`.
- FU ids: a `localparam` copy in `decoder.v`, `func_unit_status.v`, `pd.v` and `func_unit_status_tb.v` (no `.vh` file, see 2.1). The unit TBs' `CHECK`/`TB_FINISH` helper (`tb_common.vh` from Phase 0) was also inlined into each `*_tb.v` and the `.vh` deleted, so no `.vh` files remain.
- **Interfaces (final for the rest of the plan):**
  - `instr_status`: `iss_sel_valid/iss_sel_ist_idx` (stage IS), `iss_valid/iss_ist_idx` (stage EX + combinational read port `iss_{opcode,funct3,funct7,imm,shamt}`), `wb_en/wb_ist_idx` (clear). The read port does **not** return `rd`/`pc`: the issue signals take them from the FU row, which already has to store them for WAR/WB, so they only come from one place.
  - `functional_unit_status`: dispatch adds `ds_ist_idx, ds_uses_rs1/2, ds_writes_rd`. Select drives `iss_sel_valid, iss_sel_ist_idx, iss_rf_rs1/2` (RF addresses, combinational). The issue outputs are `iss_valid` + `iss_{fu_id,ist_idx,pc,rd,writes_rd,op1,op2}`; the FU-occupancy input is `fu_ready` (ready/valid; was `busy`, inverted). `wb_tag_clear` was renamed `wb_tag`. Removed: `iss_en`, `issued`, `iss_tag_found`, `iss_instr_found`, `iss_pc`, the RF capture registers, and the redundant `!busy_arr` dispatch guard / `wb_tag != NONE` guard.
  - `pd.v`: `wb_ist_idx` placeholder added to the `wb_*` bus. The `iss_*` issue signals are complete (FU row fields + instr_status fields) and unconsumed until Phase 3; `fu_ready` is an all-ones placeholder.
- **Operands go straight to the issue outputs.** The FU row keeps only forwarded values (`rs*_fwd_data_arr`); the RF value is not stored in the row.
- **`ops_read` = `issued_arr`.** The bit is set at the select edge, the same edge at which the RF latches the operands. Phase 4's WAR check (4.2) uses `!issued_arr[j]`.
- **No RF write→read bypass (deviation from 2.4).** A writeback in cycle N cannot be the producer of a source of the row selected in N, because that row would still hold the producer's tag. A dispatch whose producer writes back that cycle gets tag 0 and is selected after the RF write. The only same-cycle writer left is a younger WAR writer, which D4 holds at WB until the reader has issued; a bypass would return the wrong (new) value in that case. `func_unit_status_tb` case C checks the masked-dispatch timing instead of a bypass.
- **Notes for later phases:**
  - 4.2: a source whose value was captured from a broadcast (`rs*_fwd_arr`) no longer reads the RF, so the WAR term can also require `!rs*_fwd_arr[j]`. That removes needless WB stalls; it is optional.
  - 3.8: under D3 a row is reserved dispatch→WB and its FU only ever runs that row's instruction, so `fu_ready[i]` is always 1 for a row that has not issued. The `fu_ready[i]` issue term only matters if Phase 10.1 frees FUs before WB.

---

## Phase 3 — Execute stage (functional units)

Each FU has its own file (see ground rules): `alu.v` (ALU FU, merged into the existing ALU), `array_mult.v` (MCM FU, merged into the existing multiplier), `load.v`, `store.v` (new; both use `dmemory.v`, which stays plain data memory) and `branch_comp.v` (branch FU, merged into the existing comparator). Control decode is in `control_signals.v` (Execute controls for the issuing instruction; Branch controls for the branch FU's compare-cycle instruction; Writeback controls for the instruction writing back). Common FU interface (as built; the result's `ist_idx`/`rd`/`writes_rd`/`pc` are not carried by the FU — WB reads them from the FU's `func_unit_status` row, which holds them until WB):

```verilog
input             clock, reset,
// issue -> FU (ready/valid); pd.v drives ex_valid = fu_iss_valid[id-1] (iss_valid && iss_fu_id == id)
input             ex_valid,       // the issuing instruction is handed to this FU (its issue cycle)
input  [..]       operands,       // idata1/idata2 (pd.v a_sel/b_sel mux), plus per FU: alu_sel; op_a/op_b (MCM);
                                  //   pc, funct3, store_data (store); rs1_data/rs2_data, opcode, funct3 (branch)
output            fu_ready,       // FU can accept an instruction (feeds func_unit_status.fu_ready)
// FU -> WB (ready/valid)
output reg        result_valid,   // result computed, waiting for WB
output reg [31:0] result,         // branch: taken + target instead
input             wb_ready        // WB takes this FU's result this cycle (WB grant)
```

**EX timing after the issue cycle** (issue = the cycle `ex_valid` is high): ALU executes in the issue cycle (1 cycle); MCM starts in the issue cycle (34 cycles to `result_valid`); **load, store and branch hand the instruction over at the end of the issue cycle and then take two EX cycles** — EX 1: address/target adder on `idata1 + idata2`, EX 2: memory access (load/store) or compare (branch) — with `result_valid` from the cycle after EX 2.

- [x] 3.1 **`control_signals.v`** (adapted from `verilog/design/code/control_signals.v`, same structure and encodings). **Execute** controls from the issuing instruction (`iss_opcode/funct3/funct7`): `alu_sel`, `a_sel` (`REG`/`PC`: PC for branch, AUIPC, JAL), `b_sel` (`REG`/`IMM`: rs2 only for R-type). **Branch** controls from the instruction in the branch FU's compare cycle (`cmp_opcode/cmp_funct3`, `br_eq`/`br_lt`): `br_un`, `br_taken`, `pc_sel` — the scalar logic (BEQ/BNE/BLT/BGE/BLTU/BGEU; JAL/JALR always taken); `pc_sel` is for the Phase 6 redirect and not connected. **Writeback** controls from the instruction writing back (`wb_opcode` from `instr_status`'s writeback read port, `wb_rd`): `reg_wen`, `wb_sel` (`WB_MEM`/`WB_ALU`/`WB_PC4`), identical to the scalar logic; consumed in Phase 4. **ECALL → ADD** (`a_sel`=REG → x0, `b_sel`=IMM → 0; D8). **No multiply mapping** (D7); **`DIV/DIVU`** map to the ALU divide selectors (D7a). Not carried over from the scalar file: XM/MW pipeline registers (each stage's instruction is given directly), MX/WX bypass selects (the scoreboard forwards through tags), `mem_rw` (the store FU writes for every instruction it receives). `pd.v` does the ALU input mux (`alu_in1/alu_in2` from `a_sel/b_sel`) like the scalar `pd.v`; the mux feeds the ALUs and the load/store/branch address adders.
- [x] 3.2 **`alu.v` = ALU FU** ×2 (FU IDs 5, 6): 1 cycle. Handles RV32I R/I-type, LUI (pass imm), AUIPC (pc + imm), ECALL (ADD of zeros, result discarded: `writes_rd = 0`; D8), and **`DIV/DIVU` (D7a)**. Never receives a multiply (the decoder sends `MUL` to MCM).
- [x] 3.3 **`array_mult.v` = MCM FU** (FU ID 2) — **the only multiply path (D7):** adapted from `verilog/design/code/array_mult.v` (same shift-and-add algorithm, operands `op_a`/`op_b`). Handles **`MUL` only** (low 32 bits). Starts on `ex_valid` and raises `result_valid` with the product when the last bit is done (34 cycles from the issue cycle). **No divide logic in MCM (D7a).**
- [x] 3.4 **`load.v` = load FU** (FU ID 3): issue cycle, then **EX 1** — address adder `idata1 + idata2` (rs1 + imm), registered; **EX 2** — read `dmemory` at that address, byte/half select + sign/zero extension by `funct3` (LB/LH/LW/LBU/LHU, logic copied from the scalar core's `pd.v`), registered at the end of the cycle.
- [x] 3.5 **`store.v` = store FU** (FU ID 4) — **writes in EX (D6):** issue cycle, then **EX 1** — address adder `idata1 + idata2`, registered with `store_data` (rs2), size and PC; **EX 2** — `w_en=1`, `w_address`, `w_data_in`, `w_access_size`. The write lands at the end of EX 2, so the data is in memory by WB. Then `result_valid=1` with `writes_rd=0`; WB only releases state.
- [x] 3.6 **Memory ordering at issue (D6):** in the issue select, block a LOAD row while the STORE row is reserved with a smaller PC and has not executed; block the STORE row while the LOAD row is reserved with a smaller PC and has not executed. `issued_arr` is the "executed" bit (load and store have the same timing, so the older one reaches memory first).
- [x] 3.7 **`dmemory.v` forwarding.** Its store→load forward uses `w_pc < r_pc`. Under 3.6 a load and an older store are never in EX together (one issue/cycle, older one executes first), so the forward path is never used. Left as is; recorded under D6 that the PC compare is only valid under the D2 assumption; CLAUDE.md picks it up in Phase 9.
- [x] 3.8 **Wire up in `pd.v`:** route `iss_valid` + `iss_*` to the FU whose ID matches (`fu_iss_valid[id-1] = iss_valid && iss_fu_id == id`, connected to the FU's `ex_valid`); build `fu_ready[NUM_FU-1:0]` from the FUs (bit `id-1`) and connect it to `functional_unit_status.fu_ready`.
- [x] 3.9 Unit TBs: `array_mult_tb` (latency + results incl. negative operands), `alu_tb` (all selectors, DIV/DIVU edge cases: divide by zero, `INT_MIN / -1`), `control_signals_tb` (all Execute, Branch and Writeback controls), `load_tb` (issue + 2 EX cycles, all 5 widths), `store_tb` (issue + 2 EX cycles, sb/sh/sw, data visible the cycle after EX 2), `branch_comp_tb` (issue + 2 EX cycles, every B-type taken/not taken, JAL, JALR) — `load_tb`/`store_tb` use `dmemory.v`, `branch_comp_tb` uses `control_signals.v`.
- [x] 3.10 **`branch_comp.v` = branch FU** (FU ID 1; one file: the scalar comparator plus the FU logic) — brought forward from Phase 6 (task 6.2), **set-up only**: issue cycle, then **EX 1** — its own adder computes the target `target_in1 + target_in2` (pc + imm for B/JAL, rs1 + imm for JALR via `a_sel`/`b_sel`; bit 0 cleared for JALR), registered; **EX 2** — the scalar compare (`br_eq`/`br_lt`, `br_un` from `control_signals`) on the registered rs1/rs2 (`idata1`/`idata2`, the scalar port meaning) and `control_signals` returns `br_taken`; `taken` and `target` are registered (`result_valid`). JAL/JALR's rd = pc + 4 is written through `writeback.v`'s `WB_PC4` in Phase 4 (as in the scalar core). **Not done yet (Phase 6):** using the outcome — fetch redirect, flush, stall.

**Done when:** all FUs lint clean, unit TBs pass, and full sim shows correct `[X]` results (still no writeback).

**Phase 3 as built (2026-11-22; restructured the same day, see status log):**
- `make lint`: no errors (remaining `pd.v` warnings are the WB-side signals Phase 4 consumes: `fu_result*`, `iss_rd`, `iss_writes_rd`, `wb_pc`, `reg_wen`, `wb_sel`, plus `uses_rs*` for 4.2, and `pc_sel`/`branch_outcome_taken` for Phase 6). `make unit_tests`: 11/11 pass — `alu_tb` (120 checks), `array_mult_tb` (361), `control_signals_tb` (151), `load_tb` (157), `store_tb` (78), `branch_comp_tb` (169); `func_unit_status_tb` has D6 cases G1–G3 (176). Mutation check — each caught by the matching TB: dropping the D6 gate, LB sign extension, finishing the MUL early, SRAI decoded as SRL, the `b_sel` rule, ECALL → ADD, x0 write suppression, BGE condition, a load/store/branch skipping its address cycle, the store writing rs1, JALR not clearing bit 0, `br_un` not connected.
- Full sim: `ooo-smoke` shows `[X] 0 … 5 00000005` and `[X] 1 … 6 00000007`, then stalls (no WB). Scratch program 1 (`addi x1,x2,3; auipc x5,1; mul x6,x2,x0; sw x2,-8(x2); lw x7,-8(x2); ecall`): the right `[X]` for every FU; the store issued @7, address @8, wrote memory @9 (`[M] 0100000c 010ffff8 4 01100000`), done @10; the load issued @8 (D6: after the store), address @9, read memory @10 (after the write), valid @11 (`0x01100000`); the MUL (issued @6) completed @40 after the younger store and load — out-of-order completion. Scratch program 2 (`addi x1,x2,3; bne x2,x0,skip; …`): the branch issued @5, target @6, compare @7, outcome @8 with target `0x0100000c` (taken); further dispatch waits on the `br_busy` drain placeholder (D5).
- **`dmemory.v`** is plain data memory; its internal offset adder (`r_offset`/`w_offset` ports) was removed because the load/store FUs compute the effective address. Its header describes the combinational read (it said "registered").
- **Control decode in `control_signals.v`** (instance `ctrl` in `pd.v`); `pd.v` muxes `alu_in1`/`alu_in2` from `a_sel`/`b_sel`. `instr_status` gained the writeback read port `wb_opcode` (opcode of row `wb_ist_idx`). `iss_shamt` is not used: the decoder already puts the shift amount in `imm` for I-type shifts.
- **Matching `verilog/`:** `alu.v` is the scalar file with its MUL/`array_mult` path removed (D7) and the FU handshake added (`ex_valid`, `fu_ready`, `result_valid`, `result`, `wb_ready`) — `idata1`/`idata2`/`alu_sel`, the operation `case` and `mask` are unchanged. `array_mult.v` is the scalar file with `ex_valid`/`fu_ready`/`result_valid`/`wb_ready` in place of `start_pulse`/`hold`/`busy` outputs (`op_a`/`op_b`, `go`, `busy`, the algorithm unchanged) and no hold/abort path (no squash yet, Phase 6). `branch_comp.v` is the scalar comparator (`br_un`/`br_eq`/`br_lt`, `idata1`/`idata2` = compared values) with the FU's target adder, two EX cycles and handshake added. `decoder.v` gained only the OoO outputs (`uses_rs*`, `writes_rd`, `fu_id`).
- **`pd.v`:** instances `alu1`, `alu2`, `mcm` (`array_mult`), `load_unit`, `store_unit`, `branch_unit` (`branch_comp`), `dmem`, `ctrl`. Vectors `fu_iss_valid`, `fu_ready`, `fu_result_valid`, `fu_result` (flattened, FU id i+1 at `[i*DATAW +: DATAW]`; the branch slot carries the target PC, shown in `[X]`), `fu_wb_ready` (all-zero placeholder until Phase 4); `dmem_r_*` / `dmem_w_*` wires between the FUs and `dmemory`; `br_cmp_opcode/br_cmp_funct3`, `br_un/br_eq/br_lt/br_taken` between `branch_unit` and `ctrl`; `branch_outcome_taken` and `pc_sel` unused until Phase 6.
- **3.6:** gate `load_waits_for_store` / `store_waits_for_load` in `func_unit_status`, one shared 32-bit PC compare. With the memory FUs taking issue + 2 EX cycles, a row selected in N accesses memory in N+3 and the younger one in N+4 or later.
- **3.7:** `dmemory`'s `w_pc < r_pc` forward is never used; noted in `dmemory.v` and under D6.
- **Trace:** `[M]` comes from the dmemory write port (`dmem_w_*`, the store's EX 2). `[X]` is indexed per FU (`X_NUM_FU`, `X_VALID(i)`, … in `signals.h`); `trace_dump.h` loops over the FUs and prints a line for each FU in the first cycle its `result_valid` is high, so several FUs can complete in one cycle.
- **Open question:** the ALU still executes in its issue cycle (operands → ALU → result register in one cycle). If the ALU should also hand the instruction over at the end of the issue cycle and execute in the next cycle (like load/store/branch), that is a small change to `alu.v`.

---

## Phase 4 — Writeback stage

Writeback select goes into the existing `design/code/writeback.v` (same file name as in `verilog/`; its old result-source mux is not needed because each FU produces final data), instantiated in `pd.v`.

- [ ] 4.1 **Candidates:** `wb_candidate[i] = result_valid[i] && !war_block[i]`.
- [ ] 4.2 **WAR (D4)** computed in `func_unit_status` (it owns the source fields): for FU `i` with `writes_rd`, `war_block[i] = OR over rows j≠i of (busy_arr[j] && !ops_read[j] && ((uses_rs1[j] && rs1[j]==rd_i && rs1_tag[j]==0) || (uses_rs2[j] && rs2[j]==rd_i && rs2_tag[j]==0)))`. Export `war_block[NUM_FU-1:0]`.
- [ ] 4.3 **Select** the candidate with the **smallest PC** (D2) using a second `min_pc_select` instance (2.4a); its `min_pc_onehot` is `wb_ready[NUM_FU-1:0]` (one FU's result is taken per cycle).
- [ ] 4.4 **Drive the `wb_*` bus** (replace the constant assigns in `pd.v`): `wb_en`, `wb_tag` (= ID of the FU whose `wb_ready` is high), `wb_data` from the existing `writeback.v` mux exactly as in the scalar core (`wb_sel` from `control_signals`: `mem` = load FU result, `alu` = the granted FU's `fu_result`, `pc4` = `wb_pc + 4`), `wb_rd`, `wb_writes_rd` (= `control_signals.reg_wen`), `wb_ist_idx` (also drives `instr_status.wb_opcode` for `control_signals`), `wb_pc` (trace, D2, PC+4).
- [ ] 4.5 **Clear state on WB:** RF write (`wb_en && wb_writes_rd`; x0 excluded by `reg_wen`); `reg_status_table` clear of `wb_rd`; `instr_status` row by `wb_ist_idx`; FU row free + tag broadcast (existing `func_unit_status` logic); FU `result_valid` cleared by its `wb_ready`. Non-writing instructions (store, ecall) still release everything.
- [ ] 4.6 **Same-cycle dispatch vs WB:** keep the `ds_rs*_tag` masking in `pd.v` (a dispatching instruction whose producer writes back this cycle gets tag 0 and reads the RF later — verify in a TB that the RF already holds the value by its issue, and comment why). A WAW-stalled instruction must dispatch the cycle after its blocker's WB.
- [ ] 4.7 **Deadlock check:** with WAR blocking, confirm the blocked reader can always issue (its own tags only depend on other producers that are not WAR-blocked by it). Add a sim watchdog: `$error` if no dispatch/issue/WB happens for N cycles while tables are non-empty.

**Done when:** the five stages are all connected; full sim of a branch-free program shows `[F] [D] [I] [X] [W]` for every instruction and `cmp_ooo_spike.py` passes on it.

---

## Phase 5 — Straight-line integration tests (`rv32-benchmarks/ooo-tests/`)

All tests here are **branch-free** and end with `ecall` (D5, D8). Each `.s` has a header comment stating the expected OoO behaviour. Check correctness with `cmp_ooo_spike.py` **and** the expected event order in the trace.

- [ ] 5.1 `ooo-alu-basic.s`: every RV32I ALU/imm op + LUI/AUIPC (straight-line rewrite of the rv32ui ALU tests' arithmetic).
- [ ] 5.2 `ooo-mul-overlap.s`: `mul` then independent `add`s → adds write back before the mul.
- [ ] 5.3 `ooo-mcm.s`: mul with negative/zero/large operands; div/divu (on the ALUs) with divide-by-zero and overflow cases, interleaved with a mul to show divides finishing before it.
- [ ] 5.4 `ooo-raw-chain.s`: dependency chain through both ALUs and the MCM.
- [ ] 5.5 `ooo-waw.s`: two writers to one `rd` → second stalls at dispatch until the first WBs.
- [ ] 5.6 `ooo-war.s`: slow producer feeds an older reader of `rX`; a younger fast op writes `rX` → its WB waits until the reader reads operands.
- [ ] 5.7 `ooo-fu-full.s`: three independent ALU ops → third stalls (2 ALUs).
- [ ] 5.8 `ooo-buffer-full.s`: >6 in flight → buffer-full stall.
- [ ] 5.9 `ooo-mem.s`: sw/lw, sb/lbu, sh/lh, store then load same address, load then store same address, sb then lw (partial overlap) — checks D6 ordering and EX-stage store timing.
- [ ] 5.10 `ooo-x0.s`: writes to x0 never change the RF or reg_status.
- [x] 5.11 `verilog_ooo/run_scripts.py` exists (lint → unit TBs → `verif/scripts/run_benchmarks_parallel.py` with `cmp_ooo_spike.py`; `--suite ooo` for `ooo-tests/`). Done early, during the layout alignment.

**Done when:** all of 5.1–5.10 pass via `run_scripts.py`; the 5.2 trace shows out-of-order completion. Record cycles per test in the status log.

---

## Phase 6 — Branching (design, then implement)

Starts only after Phase 5 is green. The current `br_busy` drain is a placeholder (D5) and may be replaced.

- [ ] 6.1 **Design first.** Write the chosen scoreboard branching strategy into §1 of this file (update D2/D5/D6, add a decision row) before writing RTL; CLAUDE.md is updated from it in Phase 9. It must answer:
  - Where a branch resolves (branch FU completion vs. WB) and how fetch is redirected.
  - Whether dispatch continues past an unresolved branch (prediction) or drains (current placeholder).
  - If it continues: how wrong-path instructions are squashed and how their FU rows, instr_status rows, reg_status entries, and pending tags are released/restored; and how stores are prevented from writing memory in EX on the wrong path (D6 writes in EX!).
  - Whether smallest-PC priority (D2) and PC-based memory ordering (D6) still equal program order (they don't once instructions from two loop iterations can be in flight) — and what replaces them in hardware (**not** seq numbers, per D1).
- [x] 6.2 **Done early as task 3.10** (set-up: target adder + taken; outcome not used yet). Original task: **branch FU** (FU ID 1, now `branch_comp.v`). It **contains its own adder** to calculate the new PC to branch to: target = (`a_sel`: `pc` for B/JAL, `rs1` for JALR) + `imm` (`b_sel` = IMM), `& ~1` for JALR. Compare for B-type with `branch_comp.v` (unchanged role, same file name as in `verilog/`). Outputs `taken`, `target`. JAL/JALR write `pc+4` through `writeback.v`'s `WB_PC4` (as in the scalar core), so the branch FU needs no register result. Add the scalar branch controls (`br_un`, `br_taken`, `pc_sel`) to `control_signals.v`. Hook into `fu_ready`, the issue signals (`iss_valid`/`iss_*`), WB (`result_valid`/`wb_ready`).
- [ ] 6.3 Redirect (uses `branch_outcome_taken`/target and `control_signals.pc_sel`): update `f_pc`, invalidate `f_valid`/`d_valid`, drop the stale imem read the cycle after redirect.
- [ ] 6.4 Implement the squash/recovery logic from 6.1 (if any).
- [ ] 6.5 Directed tests in `ooo-tests/`: taken/not-taken for each B-type, `jal`, `jalr`, a tight loop (same PC in flight repeatedly if the strategy allows it), a branch depending on a slow `mul`, a store just after a branch.

**Done when:** 6.5 passes, plus all Phase 5 tests still pass.

---

## Phase 7 — Full benchmark suites

- [ ] 7.1 Run all `rv32-benchmarks/individual-instructions` (incl. `-WARN` load/store tests, `mul`, `div`, `divu`) through `run_scripts.py`.
- [ ] 7.2 Run all `simple-programs` (`SimpleAdd`, `SimpleIf`, `Swap`, `SumArray`, `Fibonacci`, `fact-short`, `gcd`, `BubbleSort`, `CheckVowel`).
- [ ] 7.3 Record IPC per program in the status log; compare with the scalar core's cycle counts.

**Done when:** all pass.

---

## Phase 8 — Integrate sequence-number test logic (from `hw/ooo_spike`)

Seq numbers are **testing infrastructure only** (D1).

- [ ] 8.1 Fetch `hw/ooo_spike` (not in this local clone yet — `git fetch` it) and read the scalar-CPU proof of concept: how seq is assigned, traced, and compared against spike.
- [ ] 8.2 Port it to the OoO core behind a testbench/`ifdef` guard (e.g. `` `ifdef OOO_SEQ_TRACE``): assign seq at dispatch, carry it to FU rows/trace only, print it on `[D] [I] [X] [W]`.
- [ ] 8.3 **Guard rule:** no hardware decision (issue select, WB select, WAR, memory order, clearing) may read a seq signal. Add a lint/grep check (e.g. in the `make lint` target) that seq signals appear only in trace/test code.
- [ ] 8.4 Upgrade `cmp_ooo_spike.py` (or the ported compare from `hw/ooo_spike`) to match each `[W]` to its exact spike commit by seq.

**Done when:** all Phase 5–7 tests pass with seq tracing on, and identically with it off.

---

## Phase 9 — Final documentation and test refresh (once, after Phase 8)

All documentation and any tests written against interim behaviour are brought
in line with the finished core here, in one pass (AGENTS.md "build once" rule).

- [ ] 9.0 **Review `control_signals.v` against `verilog/` and `verilog_ss/`** once the OoO core works end to end: every scalar control it does not carry has a documented OoO reason (header), and the encodings still match `alu.v` and `writeback.v`.
- [ ] 9.1 **`verilog_ooo/CLAUDE.md`:** rewrite to describe the finished design — final stage behaviour, table fields, FU interfaces, issue/WB selection, WAR check, memory ordering, the chosen branching strategy, supported ISA (RV32I + MUL/DIV/DIVU), and the remaining limitations. Drop the interim "gaps" list; keep a short "known limitations" section.
- [ ] 9.2 **`verilog_ooo/README.md`, `verif/README.md`, `rv32-benchmarks/README.md`:** final commands, final trace format (all `[F] [D] [I] [X] [M] [W] [S]` events defined in `design/signals.h`, `SIM_DONE` set), seq-trace option from Phase 8, pass/fail status of each suite.
- [ ] 9.3 **`design/signals.h`:** no `TODO(Phase N)` entries left; every macro points at a final signal.
- [ ] 9.4 **Unit testbenches:** make every `design/simple_testbenches/*_tb.v` match final interfaces; remove checks of interim behaviour; `make unit_tests` all PASS.
- [ ] 9.5 **Directed tests:** review `rv32-benchmarks/ooo-tests/` — branch-free restriction lifted (Phase 6), headers describe final expected OoO behaviour, `check_branch_free` target removed or kept only for the tests that need it.
- [ ] 9.6 **Golden traces:** copy passing traces into `verif/golden_sim/` (see its README) so `make diff_golden` guards future timing changes.
- [ ] 9.7 **Consistency check against `verilog/` and `verilog_ss/`:** directory tree identical, module header blocks present, `make help` targets named like the other CPUs where they overlap.
- [ ] 9.8 Update the repo-root `AGENTS.md` "Current focus" section (OoO core complete; next steps such as bridge/Unity integration).

**Done when:** `python3 run_scripts.py` passes everything it ran in Phases 5–8, docs describe the code as it is, and no interim/TODO notes remain outside this plan.

---

## Phase 10 — Optional performance work (after Phase 9)

- 10.1 Free an FU at completion with a completion buffer so it can accept a new instruction before WB.
- 10.2 Address-based load/store disambiguation instead of D6's blanket ordering.
- 10.3 Branch improvements beyond the Phase 6 strategy.
- 10.4 Unity bridge integration (`verilator/`, `bridge/`) for an OoO variant — outside `verilog_ooo/`, coordinate with the team first.

---

## Verification summary

| Phase | Command | Pass criterion |
|---|---|---|
| 0–1 | `make lint` in `verif/scripts` | No errors |
| 1–3 | `make` in `design/simple_testbenches` (iverilog TBs) | All TBs PASS |
| 4–5 | `python3 verilog_ooo/run_scripts.py` on `ooo-tests/` | All PASS |
| 6–7 | `run_scripts.py` on `ooo-tests/`, `individual-instructions/`, `simple-programs/` | All PASS |
| 8 | Same, with `OOO_SEQ_TRACE` on and off | Identical PASS |
| 9 | `python3 run_scripts.py` + doc/TB review | All PASS; no TODOs left in docs/`signals.h` |

---

## Critical files

- **Modify:** `design/code/pd.v`, `instr_status.v`, `func_unit_status.v`, `reg_status_table.v`, `alu.v` (ALU FU; no multiply; divide), `control_signals.v` (Execute + Writeback controls; branch controls in Phase 6), `array_mult.v` (MCM FU), `dmemory.v` (offset adder removed), `writeback.v` (WB select, Phase 4), `decoder.v` (multiply-only MCM routing), `verif/scripts/design.f`, `CLAUDE.md`
- **New:** `array_mult.v` (copied from `verilog/`, then adapted), `load.v`, `store.v`, `min_pc_select.v`, `design/simple_testbenches/*`, `verif/**` (copied + adapted), `verif/scripts/cmp_ooo_spike.py`, `run_scripts.py`, `rv32-benchmarks/ooo-tests/*.s`
- **Reference only (do not edit):** `verilog/design/code/{array_mult,control_signals,pd}.v`, `verilog/verif/**`, `verilog/run_scripts.py`, branch `hw/ooo_spike`

---

## Open questions for the team

None currently.

---

## Status log

| Date | Phase/Task | Notes |
|---|---|---|
| 2026-11-15 | Plan written | Based on commit `1737ab8`. No phases started. |
| 2026-11-15 | Plan revised | Team input: seq numbers test-only (from `hw/ooo_spike`, Phase 8); branch strategy deferred to Phase 6, drain is a placeholder; stores write in EX, data visible by WB; MCM is the only multiply path, multiply removed from ALU. |
| 2026-11-15 | Plan revised | D7a confirmed: divide executes in the ALU; MCM is multiply-only; decoder `is_mcm` to be narrowed (task 1.19). |
| 2026-11-15 | Plan revised | REM/REMU dropped from scope (decoded as `NONE`); only DIV/DIVU on the ALU. |
| 2026-11-15 | Plan revised | Only `MUL` implemented on the MCM; MULH/MULHSU/MULHU dropped from scope (decoded as `NONE`). |
| 2026-11-15 | Plan revised | D2 confirmed: issue (and WB) pick the smallest PC via shared `min_pc_select` tree (task 2.4a). |
| 2026-11-15 | Phase 0 done | Lint script, OoO harness + event trace, spike store capture, `cmp_ooo_spike.py`, `ooo-tests/` + smoke test, 3 unit TBs. `pd`/2 TBs blocked on Phase 1 compile errors (validated on a scratch-fixed copy). Added Phase 1 tasks 1.9a, 1.15a. |
| 2026-11-15 | Layout aligned | Moved `scripts/{design.f,lint.sh}` → `verif/scripts/`, `design/unit_tb/` → `design/simple_testbenches/`; added `verif/data/rv32ui-p-add.x` to match `verilog/` and `verilog_ss/`. |
| 2026-11-15 | Layout identical | Added root `README.md` + `run_scripts.py`, `verif/golden_sim/`, `verif/scripts/{check_fatal.sh,cmp_sim_trace.py,run_benchmarks_parallel.py,format.gtkw,waves.tcl,docker/}`, `rv32-benchmarks/{README.md,ISS_ARCHITECTURE.md}`; folded `lint.sh` into `make lint`; superscalar-tests added to all runners. |
| 2026-11-15 | Phase 1 done | RTL elaborates (lint clean of errors), 5/5 unit TBs pass (new: decoder, alu), full sim runs to TIMEOUT with dispatch trace. Extra fixes: no-hit WB count, operand-capture alignment, stale fwd flags, `iss_valid` pulse. |
| 2026-11-15 | Plan revised | Added repo-root `AGENTS.md`. New rule: build tests/docs once — docs refreshed only in new Phase 9 (final documentation and test refresh); optional performance work renumbered to Phase 10. Ground rules updated (identical layout, conventions, mandatory MCM). |
| 2026-11-15 | Cleanup | Explanatory names/comments for new RTL signals (`free_row_idx`, `ready_row_found/idx`, `row_waiting_on_tag`, `issue_now`, `rf_capture_valid/row`, `INSTR_ROW_W`, ...). Removed unnecessary checks: `is_m_unsupported` decode, no-hit WB guard, free-row-found guard, `ds_fu_id != NONE` guard, row-count size guards; dropped planned sim assertions (3.2, 3.3, 3.7) and the defensive reg_status check (4.5). |
| 2026-11-22 | Plan revised | D8 team-confirmed: ECALL is a bubble executed as an ADD of zeros on an ALU slot, writes nothing, no halt (fetch continues). Already matches the decoder; tasks 3.1/3.2 updated. |
| 2026-11-22 | Phase 2 done | `min_pc_select` (balanced tree), instr_status keyed by `ist_idx` with IS/EX stages + read port, FU rows store identity/uses/rd, 2-cycle issue (select → issue) with smallest-PC priority. No RF bypass (not needed under D4 + dispatch tag masking; see as-built). 6/6 TBs pass; full sim shows correct `[I]` operands. |
| 2026-11-22 | Convention fixes | Removed `ooo_defs.vh` (FU ids are per-module localparams again) and `tb_common.vh` (helper inlined in each TB): no `.vh` files. Renamed `iss_pkt_*` → `iss_launch_*` (no "packet" naming), `min_pc_select` outputs `sel_valid/sel_idx/sel_onehot` → `min_pc_found/min_pc_idx/min_pc_onehot`, `sel_row` → `issue_sel_row`. Added per-declaration comments for the new signals. Ground rules updated. Lint clean, 6/6 TBs pass, `make all` trace unchanged. |
| 2026-11-22 | Ready/valid naming | No "launch"/"fire" in names: `iss_launch_*` → `iss_valid` + `iss_*`, `launch_row` → `iss_row_idx`, FU `busy` → `fu_ready` (inverted), `row_ready` → `row_can_issue`, `min_pc_found` → `min_pc_valid`, trace macros `*_FIRE` → `*_VALID`. Phase 3/4 FU interface rewritten as ready/valid (`iss_valid`/`fu_ready`, `result_valid`/`wb_ready`). Lint clean, 6/6 TBs pass, trace unchanged. |
| 2026-11-22 | instr_status stage | `WB` stage value is part of the design (set at writeback with the valid clear), not debug-only; comments and task 2.2 updated. |
| 2026-11-22 | Phase 3 done | `control_signals` (one instance at issue), `fu_alu` ×2, `fu_mcm` (+ `array_mult` copy, 35-cycle MUL), `fu_load`, `fu_store` (writes in EX), D6 issue gate on `issued_arr`, FUs wired in `pd.v` with `fu_iss_valid`/`fu_ready`/`fu_result_valid`/`fu_result`/`fu_wb_ready`. Per-FU `[X]` trace + `[M]`. 10/10 TBs pass (4 new FU TBs + D6 cases); full sim shows correct `[X]`/`[M]` and out-of-order completion. |
| 2026-11-22 | Phase 3 restructured | File-name convention: merged `fu_alu.v` into `alu.v`, `fu_mcm.v` into `array_mult.v` (FSM drives `result_valid` directly: MUL 34 cycles), `fu_load.v`/`fu_store.v` into `dmemory.v`; removed `control_signals.v` (decode now in `pd.v`; separate file in new task 9.0). TBs: `alu_tb`, `array_mult_tb`, `dmemory_tb`. Phase 4 WB select → `writeback.v`, Phase 6 branch FU → `branch_comp.v`. Lint clean, 8/8 TBs pass, same `[X]`/`[M]` trace. |
| 2026-11-22 | Load/store FU files | Each FU has its own file: `load.v`, `store.v` (no `fu_` prefix); `alu.v`/`array_mult.v` stay merged. Load/store are 2 cycles (address adder, then memory); `dmemory.v` back to plain memory (offset adder removed). D6 text and memory-order comment updated for the 2-cycle FUs. Plan: branch FU in its own `branch.v` with its own adder for the target PC (6.2). TBs `load_tb`, `store_tb` replace `dmemory_tb`. Lint clean, 9/9 TBs pass. |
| 2026-11-22 | Match verilog/ conventions | Removed the ALU op encoding/decode from `pd.v`: `alu.v` decodes its own operation and operand selects (one copy of ADD..DIVU); `load.v`/`store.v` take `funct3`. `alu.v` and `array_mult.v` rebuilt from the scalar files so only documented OoO changes differ; `decoder.v` comment, `register_file.v`/`imemory.v` trailing newline restored. New ground rule: shared code stays the same as in `verilog/`/`verilog_ss/`. Task 9.0 → decode placement review. 9/9 TBs (alu_tb now drives opcode/funct3/funct7), lint clean, trace unchanged. |
| 2026-11-22 | control_signals.v back | Decode moved out of `alu.v` into `control_signals.v`, organised like the scalar file: Execute (`alu_sel`, `a_sel`, `b_sel`) and Writeback (`reg_wen`, `wb_sel`) controls; branch controls in Phase 6. `alu.v` executes on `idata1/idata2/alu_sel` again (scalar ports); ALU input mux in `pd.v` as in the scalar core. `instr_status` writeback read port `wb_opcode`. Plan: Phase 4 WB data through the scalar `writeback.v` mux; 6.2 JAL/JALR `pc+4` via `WB_PC4`, branch adder uses `a_sel`/`b_sel`. 10/10 TBs (new `control_signals_tb`), lint clean, trace unchanged. |
| 2026-11-22 | EX timing + branch FU | Load/store: issue cycle, then 2 EX cycles (address adder, memory access); address operands from the `a_sel`/`b_sel` mux. Branch FU `branch.v` built early (task 3.10): issue, EX 1 target adder, EX 2 compare (`branch_comp.v` inside, `br_un`/`br_taken`/`pc_sel` in `control_signals.v`, scalar logic); outcome not used yet (no redirect/flush/stall, Phase 6). FU ports no longer use `iss_` (`ex_valid`, `idata1/2`, `op_a/op_b`, `pc`, `funct3`; stage regs `addr_`/`mem_`/`cmp_`). D5/D6 updated. 11/11 TBs (new `branch_tb`), lint clean. |
| 2026-11-22 | Branch FU in one file | Merged `branch.v` into `branch_comp.v` (one file for the branch FU, like `alu.v`): scalar comparator kept (`idata1`/`idata2` = compared values, `br_un`/`br_eq`/`br_lt`), target operands `target_in1`/`target_in2`. TB `branch_comp_tb`. 11/11 TBs, lint clean, branch trace unchanged. |
