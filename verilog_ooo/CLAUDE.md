# Out-of-Order RV32 CPU: Design Specification and Handoff

This document describes the intended scoreboarding architecture alongside the current RTL in `verilog_ooo/`. It separates the original design direction from what the source actually implements; it is not a claim that the core is complete.

## 1. Status at a glance

The design is an early out-of-order CPU using **scoreboarding**, not Tomasulo-style physical register renaming. Dispatch is in order; ready instructions should issue out of order through the functional-unit status table. The intended machine selects at most one instruction per cycle for fetch, issue, and writeback while independent functional units execute concurrently.

The core is **not yet a working processor**:

- The top-level `pd` does not instantiate execution units or connect their status/results.
- The data-memory interface is present but its inputs are unconnected.
- Writeback outputs are tied to constants; the writeback mux is not instantiated.
- Branch resolution, redirect, and wrong-path handling are unfinished.
- A build/verification flow exists (lint script, Verilator harness with an OoO event trace, spike compare, unit TBs — see `verif/README.md`), and the RTL now elaborates (plan.md Phase 1): lint is clean of errors and the table/decoder/ALU unit testbenches pass. No benchmark passes yet because nothing executes or writes back.
- The issue/read-operand handshake is an interim form (plan.md Phase 2 redesigns it); see §6.

The current producer-FU tags are scoreboard state, not physical-register names. Do not describe this as Tomasulo-style register renaming or claim reorder-buffer/precise-retirement guarantees; those structures are not established by the current RTL.

## 2. Processor variants in this repository

| Variant | Current architecture | Useful context |
|---|---|---|
| Scalar (`verilog/`) | Five-stage, single-issue pipeline: Fetch, Decode, Execute, Memory, Writeback. | Implements pipeline hazard stalls and forwarding; branches resolve in Execute with not-taken prediction. The scalar design is the clearest reference for existing ALU, memory, and writeback behavior, but its in-order pipeline control is not a template for out-of-order scheduling. |
| Superscalar (`verilog_ss/`) | Two-way, five-stage pipeline. | Fetches/processes two instruction ways with inter-way hazard handling and per-way execution state. It is still an in-order pipeline design, not the out-of-order core. |
| Out of order (`verilog_ooo/`) | Fetch plus single-instruction decode/dispatch and issue bookkeeping, with multiple FU slots intended to allow independent instructions to issue/execute out of order. | Execution, completion, writeback, and control-flow recovery remain incomplete. See the rest of this document. |

Use the scalar/superscalar sources for instruction-field conventions and existing datapath module behavior only. Keep the out-of-order control model distinct.

## 3. Architectural intent and current limits

### Parameters and resources

The defaults in `design/code/pd.v` are:

| Parameter | Default | Meaning |
|---|---:|---|
| `DATAW` | 32 | Data and PC width |
| `NUM_REGS` | 32 | Architectural integer registers |
| `BASE_ADDR` | `32'h01000000` | Instruction/data memory base |
| `NUM_BUFFER_ROWS` | 6 | Instruction-status table capacity |
| `NUM_ALU` | 2 | Integer ALU slots |
| `NUM_MULTICYCLE_MULT` | 1 | Intended multicycle-multiply slot |
| `NUM_LOAD_STORE` | 1 | One load slot and one store slot |
| `NUM_FU` | 6 | Branch + multiplier + load + store + two ALUs |
| `FUW` | 3 | Width for FU IDs, including the zero/none value |

FU IDs are defined in `func_unit_status.v`: `NONE=0`, `BRANCH=1`, `MCM=2`, `LOAD=3`, `STORE=4`, `ALU=5`, and `ALU_2=6`. These IDs are also used as producer tags. The first free ALU slot is selected before the second.

The resource parameters describe intended capacity, not proof of working execution hardware. In particular, the out-of-order directory has no `array_mult.v`; the top-level does not connect the `busy` vector to execution units.

### Scoreboarding model: intended behavior and current RTL

The original design direction calls for three scoreboarding tables. The distinction below is important: the target behavior is not all implemented yet.

| Structure | Intended responsibility | Current source state |
|---|---|---|
| Instruction Status Table (instruction buffer) | Hold dispatched instructions and their decoded state until writeback; dispatch is in order, and entries are considered for issue out of order. The original plan calls this a FIFO. | `instr_status.v` has six valid rows, each storing PC, opcode, function fields, immediate, shift amount, `rs1`, `rs2`, `rd`, FU ID, and a stage code. It allocates the first invalid array row and clears by PC; there are no FIFO head/tail pointers or explicit age field. |
| Functional Unit Status Table | Track each FU's assigned operation, source operands/readiness, and execution/completion state. | `func_unit_status.v` uses one row per FU ID. It stores PC, source register numbers, source tags, captured source values, forwarded-value flags, and an `issued` bit. `rd` is an input but is not stored there; decoded operation/destination fields live in `instr_status`. Its internal `busy_arr` reserves a row from dispatch until writeback, while the separate `busy` input is intended to report real FU occupancy. There is no result or execution-complete state yet. |
| Register Status Table | Maintain 32 architectural-register entries mapping a pending destination to its producer FU ID; use this for WAW prevention, RAW tracking, and the planned WAR check at writeback. | `reg_status_table.v` is a 32-entry register-to-FU-ID array. Dispatch stalls on a nonzero destination mapping (WAW); source mappings become FU tags. Writeback clear exists, but WAR checking is not implemented. |

Target stage behavior from the plan:

1. **Dispatch (in order):** inspect the next decoded instruction, stall on WAW or unavailable instruction/FU storage, allocate its instruction row and FU status row, and record its destination's FU ID in the register-status table.
2. **Issue (out of order):** scan buffered instructions, select a ready instruction whose source dependencies are satisfied and FU is available, then launch it. The intended issue bandwidth is one instruction per cycle.
3. **Execute:** functional units operate independently and may finish out of order. The plan says to mark the FU busy during execution and assert an execution-complete signal when its result is ready.
4. **Writeback (out of order, one per cycle):** among completed candidates, choose the one with the smallest PC value, perform the planned WAR check, write/forward its result as appropriate, and release its scoreboard state.

Items 2–4 describe the target, not working top-level behavior. The current RTL has no completion candidates, smallest-PC writeback selector, WAR check, or connected execution units. Also, current `busy_arr` reservation begins at dispatch and is cleared by writeback, unlike the plan's wording about freeing a unit at execution completion. If a completed unit is to be reused before writeback, its result and metadata need separate storage so the pending writeback is not lost.

The older plan says "5 Functional Units," but the current RTL defaults to **six FU IDs/slots**: one branch, one MCM, one load, one store, and two ALUs. Treat the current constants as authoritative unless the implementation is deliberately changed. The original five-FU count is not reconciled with the checked-in FU map.

The smallest-PC writeback rule is part of the stated target, not current behavior. A PC comparison does not always represent dynamic program age (for example, across loops); preserve the requested rule if it is intentional, but do not silently treat it as a ROB-age/precise-retirement mechanism.

### Instruction decode

`design/code/decoder.v` extracts RV32 instruction fields and constructs R/I/S/B/U/J immediates. It identifies register source use and destination writes, excluding x0 as a dependency or writable destination. Its FU classification is:

- Conditional branches and JAL/JALR -> `BRANCH`
- `MUL` (R-type, `funct7 == 7'h01`, `funct3 == 000`) -> `MCM` (the only multiply path)
- `DIV`/`DIVU` (`funct7 == 7'h01`, `funct3 == 100/101`) -> `ALU`
- `MULH`/`MULHSU`/`MULHU`/`REM`/`REMU` -> `NONE` (unsupported, plan.md D7/D7a)
- Loads -> `LOAD`
- Stores -> `STORE`
- Integer ALU, immediate ALU, U-type, and recognized ECALL -> `ALU`
- Other/default encodings -> `NONE`

This is decode/classification behavior, not a guarantee of implemented architectural semantics. For example, the actual execution support for multiply/divide variants, branches, loads/stores, and ECALL must be verified when the execution path is implemented.

`design/code/alu.v` is a combinational ALU (no clock/reset) with selector values `0..10`, `12`, `13`: ADD, SUB, SLL, SRL, SRA, SLT, SLTU, XOR, OR, AND, pass-operand-2 (named `NOP`), signed DIV, and DIVU. Selector `11` (formerly MUL) returns 0: multiplication is only done by the MCM unit. It defines divide-by-zero and signed overflow results. However, the out-of-order tree has no `control_signals.v` mapping instruction fields to these selectors, and this ALU has no multicycle start/busy/done interface. Do not equate the presence of an ALU operation or an `MCM` FU ID with a connected, working instruction path.

### Register and memory model from the shared RTL

- The register file in `design/code/register_file.v` has 32 32-bit entries, two registered read ports, and one write port. x2 is initialized to `BASE_ADDR + MEM_DEPTH`; x0 is not intrinsically hardwired in the module, so writes to x0 must be prevented by control.
- The instruction memory in `design/code/imemory.v` is word-addressed internally, reads a word per enabled clock, and starts at `0x01000000`. The current `pd` increments the fetch PC by four and does not redirect it.
- The data memory in `design/code/dmemory.v` is byte-addressable, supports byte/halfword/word accesses, and uses `MEM_PATH`, `LINE_COUNT`, and `MEM_DEPTH` macros supplied by the surrounding build. Its interface includes PC fields and a store-to-load forwarding path. The current top-level leaves its interface unconnected.
- Data-memory reads return a 32-bit word of bytes; load sign/zero extension and `funct3`-specific selection must be provided by the integrated datapath.
- `design/code/writeback.v` selects memory data (`wb_sel=0`), ALU data (`1`), or PC+4 (`2`); other selector values return zero. The top-level must supply the correct source and selector for each completing instruction.

## 4. Current top-level organization

The top module is `pd` in `design/code/pd.v`. The file list is `verif/scripts/design.f`.

### Fetch

`f_pc` initializes/resets to `BASE_ADDR`, advances by four when dispatch is not stalled, and drives the registered instruction-memory read. `f_instr_pc` and `f_valid` track the fetched instruction. There is no implemented taken-branch redirect; the source itself marks decode valid/redirect handling as a TODO.

### Decode and dispatch

`d_instr` is decoded into register indices, opcode/function fields, immediate, source-use/write-destination flags, and an FU type. A dispatch is accepted only when:

1. The instruction is valid.
2. The instruction-status buffer is not full.
3. A matching FU slot is available.
4. A destination-writing instruction has no existing producer tag for `rd` (WAW prevention).
5. The branch-drain flag is not blocking dispatch.

If dispatch is rejected for one of these reasons, `ds_stall` holds fetch/decode. `NONE` instructions are treated as no-FU/no-op dispatches by the current stall logic.

`br_busy` is set when a branch/jump is dispatched and cleared only by a writeback carrying the `BRANCH` tag. This is a branch-drain scaffold, not a complete branch policy: there is no resolution, redirect, or squash path. Branch strategy remains an open design decision; do not assume the scalar core's not-taken prediction applies here.

### Issue and operand readiness

`functional_unit_status` stores one row per FU slot. A row is allocated at dispatch and is intended to remain allocated until its FU completes and writeback clears it. A combinational select picks the lowest-index row that is allocated, not yet issued, whose FU is not busy, and whose two source tags are clear; the selection is registered (`iss_row_index`, `iss_fu_id`, one-cycle `iss_instr_found` pulse).

This is a fixed row-index priority, not an age/oldest-ready policy: the current code does not establish that the lowest row is the oldest instruction.

The register-status table maps each architectural register to one producer FU ID (zero means no outstanding producer). At dispatch:

- Source-register mappings become `rs1`/`rs2` tags unless the instruction does not use that source.
- A nonzero mapping on `rd` causes a WAW stall rather than allocating a new physical register.
- A matching writeback tag clears waiting source tags and records the broadcast value in the FU row.

When a row issues, `iss_rs1`/`iss_rs2` (from `iss_row_index`) drive the register file during the following cycle; the RF registers the data at the next edge, and one edge later it is captured into that row (`cap_valid`/`cap_row_index`) unless the operand was already forwarded from a writeback. Back-to-back issue is covered by `func_unit_status_tb`. There is no register-file write→read bypass yet (plan.md task 2.4).

The `instr_status` table stores up to six dispatched instructions, including PC, decoded fields, FU ID, valid bit, and a stage field (`DS`, `IS`, `EX`, `WB`). The current top updates `IS` on issue and clears an entry on writeback; it does not currently advance an entry to `EX`. It is keyed by PC; if multiple dynamic instances of the same PC can be in flight, matching by PC alone may be ambiguous and needs a deliberate solution.

### Intended execution and writeback connections (not implemented)

The top-level already declares a future writeback interface:

- `wb_en`: a completing instruction is being written back/cleared.
- `wb_tag`: the FU ID/producer tag being released.
- `wb_data`: result broadcast to waiting operands and the register file.
- `wb_rd`, `wb_writes_rd`: architectural destination and register-write control.
- `wb_pc`: instruction identity used to clear its status row.

These are currently tied to zero constants. The following connections are therefore absent:

- The issue row's opcode, function fields, immediate, destination, PC, and operand values are not collected into a complete execution request.
- No ALU, branch, multiply, load, or store execution unit is instantiated in `pd`.
- No FU drives/updates the `busy` vector.
- No result/valid/tag path returns from an FU.
- `dmemory` has no connected request path.
- `writeback.v` exists as a standalone selector for memory data, ALU data, or PC+4, but is not instantiated or controlled by this top.
- No instruction completion drives the status-table clears, producer-tag clears, register-file write, or writeback broadcast. The intended one-result-per-cycle, minimum-PC selection and WAR check are also absent.

When implementing these stages, keep producer tag, architectural `rd`, and instruction identity (`pc`) distinct. A completion that does not write a register (for example, a store or branch) still needs a defined way to release its FU slot and remove its instruction-status entry. A load must wait for memory data and apply the correct byte/halfword sign or zero extension before writeback.

## 5. Module map

| File | Current role |
|---|---|
| `design/code/pd.v` | Top-level fetch/decode/dispatch/issue scaffolding, table connections, branch-drain flag, and placeholder memory/writeback connections |
| `design/code/decoder.v` | Instruction field decode, immediate generation, register-use/write flags, and FU classification |
| `design/code/instr_status.v` | Six-row decoded-instruction/status storage, allocation/full tracking, issue-stage update, and writeback clear |
| `design/code/func_unit_status.v` | FU-slot allocation, pending source tags/values, issue-row selection, and writeback-tag wakeup/slot release |
| `design/code/reg_status_table.v` | Architectural-register-to-producer-FU mapping; dispatch WAW/source-tag queries and writeback clear |
| `design/code/register_file.v` | 32x32 register storage with registered reads and a single write port |
| `design/code/alu.v` | Combinational integer arithmetic/logic operations. It does not expose a multicycle handshake interface |
| `design/code/branch_comp.v` | Branch comparison helper; not connected by the current top |
| `design/code/imemory.v` | Registered instruction-memory read |
| `design/code/dmemory.v` | Byte-addressable data-memory interface and memory behavior; not connected by the current top |
| `design/code/writeback.v` | Result-source mux for memory, ALU, and PC+4; not connected by the current top |
| `verif/scripts/design.f` | Source list for the out-of-order design (single list: used by `make lint` and the Verilator build) |
| `verif/scripts/Makefile` | `make lint` (Verilator lint + Icarus elaboration of `pd`), `make unit_tests`, simulation/spike-compare targets (`make help`) |
| `run_scripts.py` | Top-level runner: lint → unit testbenches → parallel benchmarks vs spike |
| `design/signals.h` | Maps OoO trace events (`[F] [D] [I] [X] [M] [W] [S]`) to `pd` signals; define a stage's `*_FIRE` macros when it is implemented |
| `design/simple_testbenches/` | Self-checking Icarus unit testbenches for the scoreboard tables |
| `verif/` | Verilator harness, spike trace generation, `cmp_ooo_spike.py` (order-insensitive compare); see `verif/README.md` |

## 6. Important gaps and source inconsistencies

Resolve these as part of the relevant implementation work; do not silently paper over them in documentation or assume they are already fixed:

1. (Fixed in Phase 1) `instr_status.v` undeclared `FW`/`done`, wrong field widths, count corrupted by unmatched writebacks.
2. (Fixed in Phase 1) `func_unit_status.v` undeclared `iss_fu_id`, mixed blocking/non-blocking issue logic (`iss_instr_found` could never go high), mis-timed operand capture, stale forwarded-value flags.
3. (Fixed in Phase 1) `pd.v` 1-bit `iss_rs*_data`, use-before-declaration, trailing port comma, unknown `NUM_REGS` parameter.
4. `pd.v` ties the `functional_unit_status.busy` input to a zero placeholder (`fu_busy`). Its availability decisions cannot be meaningfully driven by real execution-unit occupancy until that interface is wired.
5. `wb_en`, `wb_tag`, `wb_data`, `wb_rd`, `wb_writes_rd`, and `wb_pc` are constants, and the data-memory request ports are open.
6. The OoO build/test harness exists (`make lint` / `make unit_tests` in `verif/scripts`, `run_scripts.py`, `design/simple_testbenches/`; see `verif/README.md`), and the RTL elaborates with all unit testbenches passing (Phase 1). No benchmark passes yet (no execution/writeback), so do not claim the OOO design passes simulation.
7. `dmemory.v` decides whether a store precedes a load using `w_pc < r_pc`. Confirm whether this is an acceptable dynamic instruction-order rule, particularly for loops, before relying on it as the OOO memory-order model.
8. `iss_valid` is now the one-cycle `iss_instr_found` pulse. The issue packet to an FU, smallest-PC selection, and the RF write→read bypass are still to be defined (plan.md Phase 2).

This list captures issues directly visible in the current sources; it is not an exhaustive lint report.

## 7. Open decisions for execution/writeback work

The present code and original notes do not settle the following. Keep the specified writeback bandwidth/priority as the target, and make other choices explicit rather than assuming a conventional implementation:

- How a completed FU result and its metadata are retained until selected for the single writeback slot, especially if FU capacity is released before writeback.
- What exactly the planned WAR check examines and how it delays a write without deadlocking issue or writeback.
- Whether minimum numeric PC is intentionally the writeback priority even when dynamic instruction order differs; the RTL currently has no age/sequence number.
- How instruction identity is represented if a PC can occur more than once among in-flight dynamic instructions.
- How branches redirect fetch, squash younger work, and release squashed FU/status/tag entries.
- How loads/stores are ordered against older memory operations and how partial-store forwarding is made correct.
- Which M-extension operations are required, and whether the `MCM` slot is truly multicycle or simply a classification placeholder.
- How ECALL and unsupported/reserved encodings should complete.

## 8. Guidance for Claude continuing this design

1. Read `pd.v`, `instr_status.v`, `func_unit_status.v`, and `reg_status_table.v` together before changing stage interfaces; these tables are tightly coupled.
2. Preserve the current distinction between producer FU tag, architectural register number, and instruction PC. Do not conflate any of them.
3. First make the existing interfaces well-typed and elaboratable, then connect a minimal execution/writeback path. Keep branch recovery and memory ordering explicit rather than implying they are solved by the current tables.
4. Add focused tests for dependencies/wakeup, WAW stalls, FU occupancy/release, register-file writes, loads/stores, and branch handling as each behavior is added. Compare architectural register/memory effects against the existing RISC-V benchmark/reference flow where it can be reused. New tests should be added to `rv32-benchmarks/ooo-tests`
5. Avoid any changes to `verilog/` or `verilog_ss/` while implementing the out-of-order core; share modules only when their interfaces and timing are verified for this design.
