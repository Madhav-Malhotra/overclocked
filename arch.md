# Pipeline Enable Architecture Analysis

## Architecture Summary

The enables (`fetch_en`, `fd_en`, `dx_en`, `xm_en`, `mw_en`) are hardwired to `1` in `pd.v` (lines 28-32) but the bridge exposes setters that write directly into the Verilated internal signal tree. The stall logic runs every cycle regardless, computing `load_stall`, `wd_stall`, etc. from whichever pipeline register values happen to be present at that moment.

**The core problem:** stall detection assumes all stages advance together or not at all. If the player enables `xm_en` but not `dx_en`, the XM register latches new data while DX holds stale data. Now `opcode_dx_r`, `addr_rd_dx_r`, etc. in the stall logic no longer reflect the instruction the player thinks is "in decode" — stall signals fire or suppress based on a phantom combination of stages. The same misfire happens to forwarding (`a_sel`, `b_sel`, `branch_comp_data*_sel`), and to branch resolution (`br_taken` causes a PC jump even if the FD register didn't advance).

---

## Option Analysis

### Option 1 — Keep per-stage enables, fix stall/forwarding logic

**What it requires:**

The stall signals are currently derived purely from pipeline register contents. With partial enables, you'd need the stall logic to be aware of which registers actually moved this cycle. Concretely:

- The hazard detection comparisons (`addr_rd_dx_r == addr_rs1_w`, etc.) would need to be gated — if `dx_en` was off last tick, `addr_rd_dx_r` doesn't represent a real "instruction in execute" anymore in the game-time sense.
- `br_taken` must only trigger a PC redirect when the FD and DX registers both hold valid, coherent state.
- `control_signals.v` takes `opcode_dx_r`, `opcode_xm_r`, `opcode_mw_r` — all three need to reflect game-consistent state for the output muxes (`a_sel`, `b_sel`, `wb_sel`, etc.) to produce correct values.
- The `stall_fd`/`prev_instr` mechanism (lines 195-226) already handles one kind of hold-and-replay, but it was designed for automatic stalls, not player-driven partial ticks.

The real difficulty: stall detection is inherently a function of *relative positions* of instructions across stages. If stage positions are player-controlled and can be inconsistent across a single `tick()`, you'd essentially be reimplementing a software-side "are these stages coherent enough to run hazard detection" check in C# before every `tick()`. That logic would be nearly as complex as the Verilog stall logic itself, and duplicated.

**Complexity: High.** The stall logic has 4 stall cases + 3 forwarding paths + branch forwarding. Each needs a coherence guard. Very easy to get subtly wrong and produce silent data corruption.

### Option 2 — Remove enables, require all stages to move each tick

**What it requires:**

- Remove the 5 enable wires (or just never set them false from Unity).
- Add a UI countdown visible to the player so they know the clock is about to tick.
- The game paces itself: clock only ticks when the player confirms all 5 moves, or on a timer.

**Complexity: Low on the Verilog/bridge side.** The enables are already `wire = 1` in the RTL — you'd just stop calling the setters. Unity-side you need a "commit round" UI instead of individual stage triggers.

**Gameplay problem:** With 5 stages all active at full pipeline capacity, the player can't realistically run to 5 stations in one tick window. This gets worse with stalls (the pipeline sometimes needs to *not* move certain stages, which brings back Option 1's problem).

### Option 3 — Explicit "game clock" separate from Verilog clock, move one instruction at a time

Rather than tying player actions to pipeline register enables, the game manages a *software pipeline state* in C# that mirrors the processor. The player moves instructions between stage slots in the Unity scene. When the player commits a full, valid pipeline advance (or a valid partial advance with stalls), C# calls `tick()` once with all enables set correctly for that committed state.

- C# tracks which instruction is in each stage.
- The player's job is to decide the correct enable pattern for the next tick (i.e., which instructions should advance and which should stall).
- C# validates the pattern against the actual hazard rules before allowing the tick.
- Only one `tick()` call per committed game action; the Verilog always sees a coherent state.

**Complexity: Medium.** You're moving the pipeline state management into C#, which is more testable than Verilog logic under partial enables. The Verilog runs correctly because it only ever sees consistent enable patterns. The hard part is that C# now needs to know enough about hazards to tell the player "you can't advance DX without advancing XM first" — but this can be exposed as gameplay rules rather than hidden logic.

**Gameplay upside:** This is the most educational option — the player *is* the hazard detection unit. They learn why stalls exist by experiencing the constraint.

---

## Recommendation

**Option 3** gives you the best combination: Verilog stays correct (no stall logic changes), the bridge stays simple, and the educational value is maximised. Option 1 is the most fragile because you'd be fighting the Verilog's assumptions about synchronous advancement from within an async game loop. Option 2 is safe but makes the game nearly unplayable at full pipeline depth.

---

## Decided Design

### Gameplay

- Player moves instruction "bricks" between stage stations (F/D/X/M/W) in the Unity scene.
- No per-stage enables. Verilog runs as a normal FDXMW processor, always ticked coherently.
- Player presses a manual **tick button** (no countdown timer). Score penalty for mistakes; average cycle time shown as a stat.

### Validation model

The Verilog simulation runs **one tick ahead** of the game state:

- **State A** — `get_cpu_state()` snapshot taken immediately after the previous `tick()`. Where instructions are at the start of the current cycle.
- **State B** — snapshot taken by calling `tick()` speculatively right after State A. Where instructions *should* be after a correct tick.

On the player's tick button press, C# validates brick positions against State B, then calls `tick()` again to advance to State C (which becomes the new State B for the next cycle). No second Verilator instance or state serialization needed — determinism makes re-ticking produce an identical result.

### Validation rules

1. If an instruction needed to stall (`State A register == State B register` at that stage), the player's brick must not have moved.
2. If an instruction did not need to stall (`State A register != State B register`), the player's brick must have advanced exactly one stage.

### Error UI

Errors are derived by comparing State A (where it was), State B (where it should be), and the player's brick position:

| Situation | Message |
|---|---|
| Brick didn't move but should have | "this brick should have advanced" |
| Brick moved but should have stalled | "this brick advanced when it should have stalled (data hazard)" |
| Brick moved more than one stage | "this brick moved too far" |
