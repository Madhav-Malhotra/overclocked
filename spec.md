# spec.md — Pipeline Tick Validation

## Overview

Replace the per-stage enable architecture with a manual tick button. The Verilog processor runs one step ahead of the game state. When the player presses the tick button, C# validates brick positions against the pre-computed expected state and either advances the game or shows an error.

---

## Phase 1 — CPU state tracking in CPUController

**Goal:** CPUController maintains State A and State B and exposes them to the rest of the game.

**`unity/Assets/CPUWrapper/CPU.cs`**
- Add P/Invoke import for `get_cpu_state` (already present) — verify `CPUState` struct includes `fd_pc`, `opcode_dx_r`, `opcode_xm_r`, `opcode_mw_r`, `addr_rd_dx_r`, `addr_rd_xm_r`, `addr_rd_mw_r` fields needed for stage-occupancy comparison. Add any missing fields and keep in sync with `bridge.cpp`.

**`verilator/bridge.cpp`**
- Ensure `CPUState` exposes per-stage opcode and `addr_rd` registers for all four pipeline registers (FD, DX, XM, MW). These are needed to identify which stage each instruction occupies and whether it moved between State A and State B.

**`unity/Assets/CPUWrapper/CPUController.cs`**
- Add `CPUState stateA` and `CPUState stateB` fields.
- On `Start`, after CPU init and IMEM load: capture `stateA` via `get_cpu_state`, then call `tick()`, then capture `stateB`. The sim is now one step ahead.
- Add `GetStateA()` and `GetStateB()` public accessors.
- Remove the `TickCPU()` call currently in `CPUStation.PlaceBrick` — ticking will be driven by the tick button, not brick placement.
- Add `AdvanceTick()`: validates externally (called by the tick button handler after validation passes), calls `tick()`, promotes `stateB → stateA`, captures new `stateB` via `get_cpu_state`.

---

## Phase 2 — Remove station placement restrictions

**Goal:** Give the player full freedom to place bricks at any station so the validator (not the station) is the arbiter of correctness.

**`unity/Assets/Interactables/CPUStation.cs`**
- `CanInteract()`: remove the `!IsInvalidPlacementForHeldBrick()` guard so empty stations always accept a brick.
- `GetOutlineColor()`: remove the `IsInvalidPlacementForHeldBrick()` condition so the red outline only triggers for `IsProcessing`.
- Delete `IsInvalidPlacementForHeldBrick()` and `GetRequiredInputStage()` entirely.

---

## Phase 3 — Tick button and validation logic

**Goal:** A button calls the validator; on pass it advances the sim; on fail it surfaces errors.

**`unity/Assets/CPUWrapper/PipelineValidator.cs`** *(new)*
- `ValidateResult` struct: `bool isValid`, `List<ValidationError> errors`.
- `ValidationError` struct: `PipelineStage stage`, `string message`.
- `Validate(CPUState stateA, CPUState stateB, CPUStation[] stations) → ValidateResult`:
  - For each pipeline stage (F, D, X, M, W), compare the instruction present in `stateA` vs `stateB` at that stage's register to determine whether a stall occurred (registers equal) or an advance was expected (registers differ).
  - Compare expected outcome against the brick currently placed at each `CPUStation` (via `CPUStation.AssignedStage` and `InstructionBrick.CurrentStage`).
  - Emit error messages (associated with the mistaken stage): "instruction should have advanced", "instruction advanced when it should have stalled (data hazard)", "instruction moved too far".

**`unity/Assets/UI/TickButtonHandler.cs`** *(new)*
- `MonoBehaviour` wired to the tick button's `onClick`.
- Holds references to `CPUController` and `PipelineValidator`.
- On button press: call `PipelineValidator.Validate(stateA, stateB, stations)`. If valid, call `CPUController.AdvanceTick()`. If invalid, forward errors to `TickFeedbackUI` (Phase 4).

**`unity/Assets/UI/GameHUD.cs`**
- Add a reference to `TickButtonHandler` and wire the tick button UI element to it.

---

## Phase 4 — Error feedback UI

**Goal:** Surface validation errors to the player in a readable way.

**`unity/Assets/UI/TickFeedbackUI.cs`** *(new)*
- `ShowErrors(List<ValidationError> errors)`: displays each error message, highlights the offending station (calls `CPUStation.SetHighlighted(true)` with a distinct error color).
- `Hide()`: clears messages and resets station highlights.
- Auto-hides after a configurable duration or on the next tick attempt.

**`unity/Assets/Interactables/CPUStation.cs`**
- Add `SetErrorHighlight(bool active)`: applies a distinct error outline color (separate from the existing `blockedOutlineColor`) so validation failures are visually distinct from the "can't place here" state.

---

## Phase 5 — Remove per-stage enable infrastructure

**Goal:** Delete dead code now that the enable architecture is confirmed unused.

**`verilog/design/code/pd.v`**
- Remove `fetch_en`, `fd_en`, `dx_en`, `xm_en`, `mw_en` wire declarations (lines 28-32).
- Remove all `!fetch_en`, `!fd_en`, etc. branches from every pipeline register `always` block.
- Re-Verilate after the change.

**`verilator/bridge.cpp`**
- Remove `set_fetch_en`, `set_fd_en`, `set_dx_en`, `set_xm_en`, `set_mw_en` functions.

**`unity/Assets/CPUWrapper/CPU.cs`**
- Remove P/Invoke imports for the five enable setters.

**`unity/Assets/CPUWrapper/CPUController.cs`**
- Remove any remaining calls to enable setters.
