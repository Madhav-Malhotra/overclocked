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
| Instruction Status Table (6 rows) | `design/code/instr_status.v` | Elaborates; unit-tested (Phase 1) |
| Functional Unit Status Table (6 rows, one per FU) | `design/code/func_unit_status.v` | Elaborates; issue select + operand capture unit-tested (Phase 1); handshake redesign in Phase 2 |
| Register Status Table (32 entries) | `design/code/reg_status_table.v` | Done |
| Register file, ALU, branch_comp, imem, dmem, writeback mux | `design/code/*.v` | Present; EX/WB not connected |
| Execution units / completion / writeback | — | **Missing** |
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
| D5 | **Branches: strategy not decided.** The current `br_busy` branch drain in `pd.v` is a **placeholder** and may change. Branching is designed and implemented **only after all five stages are implemented and connected** (Phase 6). Until then, test programs are **branch-free** (ending in `ecall`), and no branch FU / redirect logic is built. | **Team-confirmed** |
| D6 | **Stores write memory in Execute.** The store FU asserts `dmemory.w_en` during its EX cycle; the write is 1 cycle, so it completes at the EX→WB clock edge and **the written data is visible in memory by WB**. The store's WB only releases its scoreboard state (no `rd`). Because memory is modified at EX, memory ordering is enforced **at issue**: a load may not issue while a smaller-PC store is reserved and hasn't executed (memory RAW), and a store may not issue while a smaller-PC load is reserved and hasn't executed (memory WAR). Store→store order is automatic (one store FU, reserved until WB, in-order dispatch). | **Team-confirmed** (EX write); ordering rule is default |
| D7 | **MCM is a core FU and the only multiply path.** **Only `MUL` is implemented** (low 32 bits of the product); it always dispatches to the MCM slot. `MULH/MULHSU/MULHU` are **out of scope** — programs never contain them, so the decoder has no special handling for them. **All multiply logic is removed from `alu.v`** (the unused `MUL` selector and the stale `array_mult`/`multicyc_sel`/`mult_*` header text) — the ALU is never used for multiply, not even as a fallback. MCM uses a copy of `verilog/design/code/array_mult.v` (multicycle, `start_pulse`/`busy`). | **Team-confirmed** |
| D7a | **Divide executes in the ALU; remainder is not supported.** `DIV/DIVU` dispatch to an ALU slot (`ALU`/`ALU_2`) and execute in `alu.v`. MCM handles **multiplication only**. `REM/REMU` are **out of scope** — programs never contain them. Decoder: `is_mcm` matches `MUL` only (`funct7 == 0x01 && funct3 == 000`); `DIV/DIVU` reach `ALU` through the normal R-type path. | **Team-confirmed** |
| D8 | **ECALL / FENCE / unknown.** ECALL → ALU slot, writes nothing, **and stops fetch** (`halt` flag) so tests end cleanly. FENCE/unknown → existing `NONE` no-op path. | Default |

---

## Phase 0 — Build & verification scaffolding

Every later phase needs a compile + sim check, so do this first.

- [x] **0.1 Lint/elaborate target.** Add a lint step (now `make lint` in `verif/scripts`) that runs:
  `verilator --lint-only -Wall -Wno-fatal --top-module pd -DMEM_PATH='"dummy.x"' -DLINE_COUNT=1 -DMEM_DEPTH=1048576 -f ../../verif/scripts/design.f`
  and `iverilog -g2012 -s pd -o /dev/null …`. Commit `verif/scripts/design.f`.
- [x] **0.2 Copy the scalar harness.** Copy `verilog/verif/{tests,scripts}` → `verilog_ooo/verif/`, and `verilog/design/{design_wrapper.v,signals.h}` → `verilog_ooo/design/`. Fix paths in `verif/scripts/Makefile`, `Makefile.verilator`, `design.f` to point at `verilog_ooo/design/code`.
- [x] **0.3 OoO trace format.** Replace the in-order FDXMW `trace_dump.h`/`fields.h` with event lines (printed only when the event fires):
  - `[F] pc instr`
  - `[D] ist_idx pc fu_id rd rs1 rs2 rs1_tag rs2_tag` (dispatch)
  - `[I] ist_idx pc fu_id op1 op2` (operands read / FU launched)
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
- Trace: `[F] [D] [I] [X] [M] [W] [S]` event lines ending in `@cycle`. Each event is enabled by `*_FIRE` macros in `design/signals.h`; `[I] [X] [M]` and `SIM_DONE` are `TODO(Phase N)` templates there. `[S]` logs only on stall start/change plus `[S] resume`. Stores are a separate `[M]` event (not part of `[X]`).
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

**Files:** `instr_status.v`, `func_unit_status.v`, `pd.v`, new `ooo_defs.vh`.

- [ ] 2.1 **Shared defines.** Create `design/code/ooo_defs.vh` with the FU-ID localparams (`NONE, BRANCH, MCM, LOAD, STORE, ALU, ALU_2`) and include it in `decoder.v`, `func_unit_status.v`, `pd.v` instead of duplicating them.
- [ ] 2.2 **Key instr_status by `ist_idx` (D1).** At dispatch, write `ds_ist_idx` into the FU row. Replace the PC-match loops (`iss_pc`, `wb_pc`) with direct `iss_ist_idx` / `wb_ist_idx` indexing. PC stays stored (used for D2 priority and tracing). Add a combinational read port: given `iss_ist_idx`, output `opcode, funct3, funct7, imm, shamt, rd, pc` (the commented-out `iss_*` ports in `pd.v`). Stage field: `IS` on select, `EX` when the FU launches; clear on WB.
- [ ] 2.3 **FU row additions** (`func_unit_status.v`): store `uses_rs1`, `uses_rs2`, `rd`, `writes_rd`, `ist_idx`, `pc` (already), `ops_read` (operands captured). Keep `rs*_tag`, `rs*_data`, `rs*_fwd`.
- [ ] 2.4 **Issue pipeline (fixes CLAUDE.md §6 item 8):**
  - **Cycle N — select (comb):** among rows with `busy_arr && !issued && !fu_busy[i] && rs1_tag==0 && rs2_tag==0` (+ D6 memory-order gating, added in 3.6), pick the **smallest PC** (D2) via `min_pc_select` (2.4a). Drive `iss_rs1/iss_rs2` to the RF combinationally from that row.
  - **Edge N→N+1:** RF registers its read data; FU status registers `rd_idx <= sel_idx`, `rd_valid <= sel_valid`, sets `issued_arr[sel_idx]`.
  - **Cycle N+1 — read operands:** `op = rs_fwd ? rs_data_arr : (rf_bypass ? wb_data_q : rf_data)`. **RF bypass is required:** if a WB in cycle N wrote the register being read, the RF's registered output is stale, so register `wb_en && wb_writes_rd && wb_rd == src` and `wb_data` alongside the read. Emit an **issue packet** `{valid, fu_id, ist_idx, op1, op2, decoded fields}` to the FU; set `ops_read`.
  - One issue per cycle; back-to-back issue must work (read stage of N+1 overlaps select of N+1).
- [ ] 2.4a **`design/code/min_pc_select.v`** — reusable combinational selector: inputs `valid[N-1:0]` and `pc[N]` (flattened `N*DATAW` bus), outputs `sel_valid`, `sel_idx`, `sel_onehot`. Implement as a **balanced comparison tree** (6 rows → 3 → 2 → 1: 5 full-width 32-bit `<` comparators, 3 comparator levels deep), with invalid inputs losing every compare; ties are impossible under D2 but break toward the lower index. Parameterised on `N`, `DATAW`. Use full-width PCs — do **not** truncate to low bits: a 33-cycle `MUL` can stay in flight while many younger instructions dispatch and retire, so the PC distance between in-flight rows is not tightly bounded. Replaces the current first-found `for` loop / `done_is` flag in `func_unit_status.v`. Own unit TB `min_pc_select_tb.v` (random valid masks/PCs vs. a behavioural reference).
- [ ] 2.5 Phase 2 fixes the table interfaces for the rest of the plan, so rewrite `instr_status_tb.v` / `func_unit_status_tb.v` against them **once** here (ist_idx keying, issue packet), plus new `min_pc_select_tb.v`. Unit-test in `func_unit_status_tb.v`: two independent rows issue on consecutive cycles with correct operands; a tagged row waits, then issues after a WB broadcast with the forwarded value; same-cycle WB + read of one register returns the new value; the smaller-PC ready row wins.

**Done when:** unit TBs pass; full sim shows `[I]` lines with correct operand values (still no writeback).

---

## Phase 3 — Execute stage (functional units)

One wrapper per FU type in `design/code/fu_*.v`. **No branch FU in this phase (D5).** Common interface:

```verilog
input             clock, reset,
input             start,          // issue packet valid for this FU
input  [..]       packet fields,  // op1, op2, imm, pc, funct3, funct7, opcode, ist_idx, rd, writes_rd
input             wb_grant,       // WB selected this FU this cycle
output            busy,           // start -> wb_grant (feeds func_unit_status.busy)
output reg        done,           // result valid, waiting for WB
output reg [31:0] result,
output reg [..]   meta            // ist_idx, rd, writes_rd, pc
```

- [ ] 3.1 **Control decode.** Copy `verilog/design/code/control_signals.v` → `verilog_ooo/design/code/control_signals.v`; trim to what EX needs (ALU selector, op1 = pc/rs1, op2 = imm/rs2, mem size/sign). **Remove any multiply mapping** from it (D7); **keep the mapping for `DIV/DIVU`** to the ALU selectors (D7a). Add to `design.f`.
- [ ] 3.2 `fu_alu.v` ×2 (FU IDs 5, 6): 1 cycle, wraps `alu.v`. Handles RV32I R/I-type, LUI (pass imm), AUIPC (pc + imm), ECALL (no write), and **`DIV/DIVU` (D7a)**. Never receives a multiply (the decoder sends `MUL` to MCM).
- [ ] 3.3 `fu_mcm.v` (FU ID 2) — **the only multiply path (D7):** copy `verilog/design/code/array_mult.v` → `verilog_ooo/design/code/array_mult.v`. Handles **`MUL` only**: pulse `start_pulse`, `hold` high while in flight, `done` when `busy` falls (~33 cycles; low 32 bits — exactly what `array_mult` produces, so no changes to it are needed). **No divide logic in MCM (D7a).**
- [ ] 3.4 `fu_load.v` (FU ID 3): address = `op1 + imm` (pass `op1` and `imm[11:0]` as `r_address`/`r_offset` to `dmemory`); 1 cycle; byte/half select + sign/zero extension by `funct3` (LB/LH/LW/LBU/LHU) — copy the extension logic from the scalar core.
- [ ] 3.5 `fu_store.v` (FU ID 4) — **writes in EX (D6):** in its EX cycle drive `w_en=1`, `w_address = op1`, `w_offset = imm[11:0]`, `w_data_in = op2`, `w_access_size` from `funct3`. The write lands on the EX→WB edge, so the data is in memory by WB. Then `done=1` with `writes_rd=0`; WB only releases state.
- [ ] 3.6 **Memory ordering at issue (D6):** in the issue select, block a LOAD row while the STORE row is reserved with a smaller PC and has not executed; block the STORE row while the LOAD row is reserved with a smaller PC and has not executed. Add a `executed` (or reuse `ops_read`/`done`) bit per row for this.
- [ ] 3.7 **`dmemory.v` forwarding.** Its store→load forward uses `w_pc < r_pc`. Under 3.6 a load and an older store are never in EX together (one issue/cycle, older one executes first), so the forward path should never fire. Leave it as is, and record (here, under D6) that the PC compare is only valid under the D2 assumption; CLAUDE.md picks it up in Phase 9.
- [ ] 3.8 **Wire up in `pd.v`:** route the issue packet to `start` of the FU whose ID matches; build `fu_busy[NUM_FU-1:0]` (bit `id-1`; BRANCH bit tied 0 for now) and connect it to `functional_unit_status.busy`; connect load/store FUs to `dmem`.
- [ ] 3.9 Unit TBs: `fu_mcm` (latency + results incl. negative operands), `fu_alu` (incl. DIV/DIVU edge cases: divide by zero, `INT_MIN / -1`), `fu_load` (all 5 widths), `fu_store` (sb/sh/sw, data visible the cycle after EX).

**Done when:** all FUs lint clean, unit TBs pass, and full sim shows correct `[X]` results (still no writeback).

---

## Phase 4 — Writeback stage

New module `design/code/wb_select.v`, instantiated in `pd.v`.

- [ ] 4.1 **Candidates:** `cand[i] = fu_done[i] && !war_block[i]`.
- [ ] 4.2 **WAR (D4)** computed in `func_unit_status` (it owns the source fields): for FU `i` with `writes_rd`, `war_block[i] = OR over rows j≠i of (busy_arr[j] && !ops_read[j] && ((uses_rs1[j] && rs1[j]==rd_i && rs1_tag[j]==0) || (uses_rs2[j] && rs2[j]==rd_i && rs2_tag[j]==0)))`. Export `war_block[NUM_FU-1:0]`.
- [ ] 4.3 **Select** the candidate with the **smallest PC** (D2) using a second `min_pc_select` instance (2.4a); its `sel_onehot` is `wb_grant[NUM_FU-1:0]`.
- [ ] 4.4 **Drive the `wb_*` bus** (replace the constant assigns in `pd.v`): `wb_en`, `wb_tag` (= granted FU ID), `wb_data` (FUs already produce final data, so `writeback.v` can be dropped from `design.f`), `wb_rd`, `wb_writes_rd`, `wb_ist_idx`, `wb_pc` (trace + D2 only).
- [ ] 4.5 **Clear state on WB:** RF write (`wb_en && wb_writes_rd`; x0 excluded by decoder); `reg_status_table` clear of `wb_rd`; `instr_status` row by `wb_ist_idx`; FU row free + tag broadcast (existing `func_unit_status` logic); FU `done` cleared by `wb_grant`. Non-writing instructions (store, ecall) still release everything.
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
- [ ] 6.2 `fu_branch.v` (FU ID 1): `branch_comp.v` for B-type; target `pc+imm` (B/JAL) or `(rs1+imm) & ~1` (JALR); `taken`, `target`, `result = pc+4` with `writes_rd` for JAL/JALR. Hook into `fu_busy`, issue packet, WB.
- [ ] 6.3 Redirect: update `f_pc`, invalidate `f_valid`/`d_valid`, drop the stale imem read the cycle after redirect.
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

- **Modify:** `design/code/pd.v`, `instr_status.v`, `func_unit_status.v`, `reg_status_table.v`, `alu.v` (remove multiply; keep divide), `dmemory.v` (unchanged; see 3.7), `decoder.v` (shared defines; multiply-only MCM routing), `verif/scripts/design.f`, `CLAUDE.md`
- **New:** `design/code/ooo_defs.vh`, `control_signals.v` (copy), `array_mult.v` (copy), `fu_alu.v`, `fu_mcm.v`, `fu_load.v`, `fu_store.v`, `min_pc_select.v`, `wb_select.v`, `fu_branch.v` (Phase 6), `design/simple_testbenches/*`, `verif/**` (copied + adapted), `verif/scripts/cmp_ooo_spike.py`, `run_scripts.py`, `rv32-benchmarks/ooo-tests/*.s`
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
