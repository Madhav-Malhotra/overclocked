# Superscalar Level — Implementation Spec

## Handoff status (2026-08-25, updated again)

All code-level pieces are implemented. The build/sync/compile step described as "the immediate next
step" in the prior handoff has now happened: the user ran the Verilator and bridge Makefiles and
reopened Unity, which surfaced several real bugs (compile errors, a tick-handling bug on Blackbox, a
UX issue with error-message formatting) — all fixed this session, see "Done (this session)" below.
**The project now compiles with zero errors** and the FiveStage/Blackbox regression checks in
"Verification steps" are believed fixed, though the user still needs to click through Play Mode to
confirm (Play Mode verification is the user's job per `unity/CLAUDE.md`, not Claude's). A new level
JSON for Superscalar (`level_04.json`) has also been created. **The Superscalar scene
(`Superscalar.unity`) itself is the next step and has not been created yet** — that's what the user
is about to start.

One design deviation from the original spec, made deliberately in this session: **there is no
separate `TickButtonHandlerSuperscalar.cs`.** The spec originally called for a file parallel to
`TickButtonHandler.cs` (mirroring the `BlackboxStation` precedent of a separate
architecture-specific driver). Instead, `TickButtonHandler.cs` itself was generalized to loop over
`CPUController.WayCount` (new property, `CPUController.cs`) and build a `CPUState[]` sized 1 or 2,
so one file now drives FiveStage, Blackbox, and Superscalar ticking. Rationale: unlike Blackbox
(a genuinely different interaction model — no per-stage stations, coroutine-driven), FiveStage vs.
Superscalar tick handling is the *same* algorithm parameterized by way-count, not a different flow;
duplicating ~80 lines to change only the array length was judged worse than a small loop. The
Superscalar scene should wire its tick-input GameObject to this same `TickButtonHandler` component,
not a new one.

### Done (this session)

- **`verilator/Makefile`**: `dll` target cross-compiles `design_wrapper_ss.dll` and copies both
  basic/superscalar libs to `$(UNITY_PLUGINS_DIR)` on all platforms. **Not yet built/tested.**
- **`bridge/Makefile`**: `SYNC_FILES` includes `VerilatorClientSuperscalar.cs
  FPGAClientSuperscalar.cs`. **Not yet run** — needs empty placeholder files with `.meta`s created
  in the Unity Editor first.
- **`CPUState` struct — `stall_0`/`stall_1` fields added** (`uint8_t`/`byte`), appended at the end
  in all three places (`verilator/bridge_superscalar.cpp`, `verilator/bridge.cpp` — hardcoded to
  `0` for the single-issue design, `bridge/CPU.cs`). **Keep these fields** — see "Stall signals"
  decision below. **Not yet built/tested** — binary layout change requires rebuilding both native
  libs.
- **`unity/Assets/Scripts/LevelData.cs`**: `cpuArchitecture` field + `GetCpuArchitecture()`.
- **`unity/Assets/CPUWrapper/CPUUnityExtensions.cs`**: `Create(...)` takes optional
  `CPUFactory.CPUArchitecture cpuArch = Basic`.
- **`unity/Assets/CPUWrapper/CPUController.cs`**: `stateB` → `CPUState[] statesB` (length 1 or 2),
  `GetStateB(int way = 0)`, `AdvanceTick()` ticks once then refreshes both ways' state, and a new
  `WayCount` property (`= statesB.Length`) that callers use instead of re-deriving the architecture
  check. **Not tested in Editor.**
- **`unity/Assets/Interactables/CPUStation.cs`**: `assignedWay` field + `AssignedWay` property
  (from prior session). **New this session**: `PlaceBrick(InstructionBrick brick)` now calls
  `brick.SetWay(assignedWay)` whenever `assignedStage == PipelineStage.Fetch`. This is re-run on
  every placement (not just the first), so moving a brick from the wrong Fetch station to the
  correct one after a validation error correctly overwrites its `Way`. **[BREAKING RISK — new
  serialized field `assignedWay` from prior session]**: confirm existing FiveStage/Blackbox
  prefabs default this to `0` harmlessly once the Editor is opened. The new `PlaceBrick` logic
  itself adds no serialized field and is a pure behavior addition (no-op on non-Fetch stations).
- **`unity/Assets/Interactables/InstructionBrick.cs`**: `Way` property + `SetWay(int way)`. Now
  wired up via `CPUStation.PlaceBrick` (see above) and consumed by `PipelineValidator` and
  `TickButtonHandler`.
- **`unity/Assets/CPUWrapper/PipelineValidator.cs`**: rewritten per the "what must change" section
  below. `Validate(CPUState[] statesB, CPUStation[] stations, uint nextSpawnPc)` is the core entry
  point; a single-`CPUState` overload is kept (wraps `new[] { stateB }`) for convenience/tests but
  is no longer used by `TickButtonHandler.cs` (see deviation note above — it now always calls the
  array overload directly, even for single-way scenes). Four helpers avoid duplicating per-way
  logic: `BuildExpectedMap`, `CheckStation`, `CheckReverseFetch`, `CheckFetchOrdering` (only runs
  when `statesB.Length > 1`). `stall_0`/`stall_1` are used **only** inside `StallLabel` to append
  `" (way <n> stalled)"` to error message strings — they never gate whether an error fires.
  **Not yet built/tested** — depends on `bridge/CPU.cs`'s `stall_0`/`stall_1` fields
  (`bridge/CPU.cs:99-100`) being synced to `unity/Assets/CPUWrapper/CPU.cs` via `make sync-unity`
  first (not yet run), so this file will not compile in Unity until that sync happens.
- **`unity/Assets/UI/TickButtonHandler.cs`**: generalized (see deviation note above) to build
  `CPUState[] statesB` of length `cpuController.WayCount`, call
  `PipelineValidator.Validate(statesB, stations, nextSpawnPc)`, and index
  `InstructionMonitorCapture.CaptureAtStage` / the Writeback-retirement check by
  `station.AssignedWay` instead of assuming way 0. On single-way scenes this is behaviorally
  identical to before (`AssignedWay` defaults to `0` for every station). **Not tested in Editor.**
  `InstructionMonitorCapture.cs` itself needed **no signature change** — it already took a
  `CPUState stateB` parameter; only the caller changed what it passes in.
- **`unity/Assets/Scripts/CircuitTraceSpawner.cs`**: rewritten to discover stations via
  `CPUStation.AssignedStage`/`AssignedWay` (through `FindObjectsByType<CPUStation>`) instead of
  `GameObject.Find` by fixed stage name, and now draws one trace chain per way (`wayCount` derived
  from the max `AssignedWay + 1` seen among scene stations). Start/End platforms are still located
  by name since they're shared across ways. **Not tested in Editor** — no scene with stations
  exists yet to verify against.
- **`verilator/README.md`**: documented the `dll` target and that `bridge` now builds both basic
  and superscalar libs. `bridge/README.md` needed no change — it already documents
  `make sync-unity` generically without hardcoding file names, so it already covers the new
  superscalar sync files.

### Done (this session, 2026-08-25 — post-build fixes)

The user ran `make` in `verilator/` and `make sync-unity` in `bridge/`, then reopened Unity in Safe
Mode and hit real compile errors, confirming several items above were genuinely untested until now.
Fixed, in the order encountered:

- **`LevelManager.currentLevelData` inaccessible** (`CS0122`, `CPUController.cs:56-57`): the field
  was `private` in `unity/Assets/Scripts/LevelManager.cs:28`. Added
  `public LevelData CurrentLevelData => currentLevelData;` (`LevelManager.cs:42`), matching the
  existing property pattern (`TimeRemaining`, `CompletedCount`, etc.). Updated `CPUController.cs`'s
  two reads to use the new property name. `LevelManager.cs` is hand-maintained (not synced from
  `bridge/`), so this fix is final as committed.
- **`HttpClient.Send` not found** (`CS1061`, `bridge/FPGAClientSuperscalar.cs:45,57`): the file used
  the .NET 5+ synchronous `client.Send(req)` API, unavailable in Unity's .NET profile. This was an
  oversight from writing the stub fresh rather than copying the working pattern. Fixed to
  `client.SendAsync(req).GetAwaiter().GetResult()`, matching `bridge/FPGAClient.cs:35,47` exactly.
  Fixed in `bridge/` (the source of truth); **requires `make sync-unity` to re-run** to propagate to
  `unity/Assets/CPUWrapper/FPGAClientSuperscalar.cs`.
- **Blackbox tick bug**: pressing T on the Blackbox level (`level_00`) before placing the brick on
  `BlackboxStation` showed a "should be at Fetch" validation error; after placing the brick, T did
  nothing. Root cause: `TickButtonHandler.OnTickPressed()` (`TickButtonHandler.cs`) ran
  unconditionally on every T press regardless of scene type, but Blackbox has no `CPUStation`s at
  all — `BlackboxStation` drives ticking itself via its own coroutine
  (`BlackboxStation.RunUntilRetired`), never through `TickButtonHandler`. Considered gating on
  `stations.Length == 0`, but rejected as fragile (an incidental fact about the current scene, not
  an intentional signal — a real station-wiring bug in FiveStage/Superscalar would silently
  no-op instead of erroring). Fixed instead by gating on scene identity: `TickButtonHandler.Start()`
  now caches `isBlackboxScene` by comparing `LevelManager.Instance.CurrentLevelData.sceneName ==
  "Blackbox"`, and `OnTickPressed()` returns immediately if true, before touching `stations` or
  calling `PipelineValidator.Validate`.
- **PC display format**: two changes to error/UI text, both purely cosmetic, no behavior change:
  1. `PipelineValidator.cs` was unconditionally appending `way={n}` to every message
     (`[pc=0x..., way=0]`), confusing on FiveStage/Blackbox where "way" is a meaningless concept to
     players. `Validate(CPUState[] statesB, ...)` now derives `bool showWay = statesB.Length > 1`
     once, threaded through `CheckStation`/`CheckReverseFetch`, so the way suffix only appears on
     Superscalar (`statesB.Length == 2`). `CheckFetchOrdering` was already superscalar-only
     (`statesB.Length > 1` gated) and needed no change.
  2. Both `PipelineValidator.cs` and `InstructionMonitorUI.cs` now show only the rightmost 4 hex
     digits of a PC instead of the full 8 (e.g. `0x0004` not `0x00000004`). Note `X4` format alone
     is a *minimum-width* specifier, not truncation — it still prints all significant digits padded
     to at least 4 wide, which does not achieve this on its own. The actual fix is a shared
     `PcHex(uint pc) => (pc & 0xFFFF).ToString("X4")` helper (defined once per file, used at every
     PC-formatting call site in that file) that masks to the low 16 bits before formatting.
     `InstructionMonitorUI.cs`'s separate `CapturedMemAddr` display was deliberately left at full
     `X8` width — only PC formatting was in scope.

### Not started / explicitly deferred

- **`StartPlatform.cs`**: no changes needed — confirmed spawning still leaves `Way` unset (default
  `int` value `0`) and the player-routing-at-Fetch behavior is now fully handled by
  `CPUStation.PlaceBrick` (see "Done" above). Nothing further to do here.
- **`Superscalar.unity` scene**: not created yet — this is the user's next step, about to start.
- **New level JSON**: `unity/Assets/Levels/Resources/JSON/level_04.json` has been created
  (`"levelName": "SuperscalarNoStall"`, `"sceneName": "Superscalar"`,
  `"cpuArchitecture": "Superscalar"`, 4 instructions — two `addi`s then two branches). Confirmed the
  `cpuArchitecture` enum wiring this level JSON depends on: `bridge/CPU.cs:247`
  (`public enum CPUArchitecture { Basic, Superscalar }`, inside `CPUFactory`, synced to
  `unity/Assets/CPUWrapper/CPU.cs:252`) is the source of truth for the two legal string values, and
  `LevelData.GetCpuArchitecture()` (`LevelData.cs:21-29`) does a case-sensitive `Enum.TryParse`
  against exactly those names, defaulting to `Basic` on empty/unrecognized input — this is why
  `level_00`–`level_03` (no `cpuArchitecture` field) correctly stay `Basic` without any code change
  needed. **No scene exists for this level yet** — it can't be loaded/played until
  `Superscalar.unity` exists with `"sceneName": "Superscalar"` matching.
- **Re-run `make sync-unity`** from `bridge/` to propagate the `FPGAClientSuperscalar.cs`
  `HttpClient.Send` → `SendAsync` fix (see "Done" above) into
  `unity/Assets/CPUWrapper/FPGAClientSuperscalar.cs` — not yet confirmed done since that fix.
- **Play Mode regression check not yet re-run** by the user since these fixes landed. The
  FiveStage/Blackbox checklist in "Verification steps" below (step 4) should be re-walked,
  especially the Blackbox T-press behavior (now expected to be a true no-op throughout) and the
  FiveStage error-message wording (now expected to omit `way=` and show 4-digit PCs).

---

## PipelineValidator.cs — what must change (DONE — kept for reference)

This section replaces the old "open questions" list. All design questions have been resolved by
tracing `pd.v`'s actual register-hold behavior. **This rewrite is implemented** — see the "Done"
entry for `PipelineValidator.cs` above for the actual structure. The subsections below are left
as-is for reference on *why* the design looks the way it does; treat the code itself as the
source of truth for exact behavior.

One correction vs. an earlier draft of this section: the stall bits cannot be used as an
"if stalled, skip this error" condition, because a stalled instruction never produces an
`expected > brick` mismatch in the first place — `BuildExpectedMap`'s `IsBubble` filter already
removes it from the map that cycle (see decision below). So there is nothing to suppress; `stall_0`/
`stall_1` only annotate message text via `StallLabel`, never gate an `errors.Add` call.

### Decision: keep `stall_0`/`stall_1`, use them for messaging only, not for stage-placement logic

Verified against `pd.v` register-by-register, for both `stall_0` and `stall_1`:

- **FD registers** (`pc_fd_r_0`, `pc_fd_r_1`): on a stall, these **hold their previous value**
  (`pd.v:337-354` for way 0, `pd.v:358-379` for way 1). A stalled instruction's PC keeps mapping
  to Decode with no special-case needed — this is exactly the "pre-tick snapshot" behavior the
  current single-issue validator already relies on.
- **DX registers** (`pc_dx_r_0/1`, `opcode_dx_r_0/1`): on a stall, these do **not** hold — they
  advance to the FD value but with `opcode_dx_r ← NOP_OPCODE` (`pd.v:409-418` way 0,
  `pd.v:468-478` way 1). This looks like an advance, but the injected NOP has `addr_rd = 0`, so
  the existing `IsBubble()` check already filters it out of the `expected` map. Net effect: the
  instruction simply has no expected slot at Execute that cycle — same outcome as if it had held,
  with zero new branching required.
- **XM/MW registers**: unaffected by `stall_0`/`stall_1` — they only bubble on `mul_stall_0/1`
  (a separate, already-out-of-scope signal; not part of this spec).

**Conclusion: the existing `expected`-map-from-registers approach is already stall-correct by
construction.** No new branch, no new `ValidationError` category for "advanced during a stall" or
"failed to advance during a stall" is needed — the pre-tick snapshot already encodes the right
answer. Do not add stall-conditional logic to the stage-matching code path.

**What `stall_0`/`stall_1` ARE needed for:** improving the *message text* of an existing error, not
changing whether an error fires. When a brick is correctly sitting still at a stage that matches
its expected stage, there is no error today (correct), and — because a stalled DX register never
produces an `expected` entry (see above), a stalled instruction can never trigger the
"should have advanced" branch in the first place — there is no error to suppress. So the stall
bits cannot gate any `errors.Add` call; there is nothing to condition on. The only useful
integration point is cosmetic: when any existing error fires for a brick in way `w`
(`PipelineValidator.cs`'s `CheckStation`/`CheckReverseFetch`), append a note if `stall_0`/`stall_1`
is set for that way, so a misdiagnosed error is easier to explain. **Implemented as** the
`StallLabel` helper, called from `CheckStation` and `CheckReverseFetch` to append
`" (way <n> stalled)"` to the message string — never used in a conditional.

Do **not** attempt to distinguish `two_way_write_use_case` from the other three OR'd causes of
`stall_1` (`load_stall_1`, `wd_stall_1`, `store_rs2_stall_1` — see `stall_signals.v:186`).
`CPUState` only exposes the combined `stall_1` bit. Per direction: no specific-cause wording is
needed — "way 1 stalled" is sufficient. Do not add a dedicated bridge signal for this; it is out of
scope.

### Required structural changes (all implemented — see `PipelineValidator.cs`)

1. **`Validate` signature**: core entry point takes `CPUState[] statesB` (length matches
   architecture — 1 or 2, index by way). A single-`CPUState` overload is kept (wraps
   `new[] { stateB }`) so `TickButtonHandler.cs` needed no change; the whole `Validate` method is
   not duplicated for single-issue vs. superscalar — both paths share `BuildExpectedMap`,
   `CheckStation`, `CheckReverseFetch`.

2. **Per-way `expected` maps**: `BuildExpectedMap(CPUState)` extracted, called once per way in a
   loop — same four-line bubble-filtered construction as the original single-issue version, no new
   logic.

3. **Per-way matching**: `CheckStation` looks up each brick in `expectedByWay[brick.Way]` (not a
   single shared map), and uses `wayState.pc` (i.e. `statesB[brick.Way].pc`) for the Fetch-stage
   "not yet in pipeline, but next to fetch" branch.

4. **Reverse-Fetch check**: `CheckReverseFetch` runs once per way in a loop, using
   `statesB[way].pc` and `nextSpawnPc`, and additionally filters candidate Fetch stations by
   `station.AssignedWay == way` so each way's check only looks at its own Fetch station.

5. **Stall labeling, not suppression** (corrected from the original draft of this decision — see
   note above the "Decision" section): stall bits never gate whether an error fires, since a
   stalled instruction never produces an `expectedOrdinal > brickOrdinal` mismatch to begin with.
   `StallLabel(wayState, way)` is called from inside `CheckStation` and `CheckReverseFetch` to
   append `" (way <n> stalled)"` to the message text when that way's stall bit is set — purely
   cosmetic.

6. **New Fetch-stage ordering check** (`CheckFetchOrdering`, only runs when `statesB.Length > 1`
   — independent of everything above, does not touch stall signals at all): way 1's Fetch-stage
   brick must not carry an older PC than way 0's Fetch-stage brick, compared directly when both
   Fetch stations are occupied. The "neither way's Fetch station may sit empty while that way has
   pending work" requirement did **not** need a separate check — the per-way `CheckReverseFetch`
   (item 4) already covers it once filtered by `AssignedWay`, since it fires whenever that way's
   Fetch station doesn't contain a brick matching `statesB[way].pc` and `pc < nextSpawnPc`. Both
   are ordinary blocking `ValidationError`s — no new `warnings`/non-blocking mechanism was added
   (the `two_way_write_use_case` non-blocking-warning idea from the earlier draft is dropped per
   the decision above).

### Explicitly out of scope for this rewrite

- No dedicated bridge signal for `two_way_write_use_case` or any other individual stall cause.
- No `mul_stall_0`/`mul_stall_1` handling — not mentioned in the original spec's gameplay
  requirements; XM/MW bubbling from multiply is a separate concern if it ever surfaces as a bug.
- No new `warnings` field on `ValidateResult` — everything here is a blocking `error`.
- Do not touch `stall_occured` (`pd.v:955`) or anything related to it — it's a pre-existing
  known-incomplete heuristic (see its own `!!!!` TODO comment in that file) used for WM-bypass
  data selection, unrelated to pipeline stage validation.

---

## Hardware facts that drive the design (verified in `verilog_ss/design/code/`)

- **Two independent PCs.** `pd.v:34-35,141-142,279-309`: `pc_r_0` starts at `BASE_ADDR`, `pc_r_1`
  starts at `BASE_ADDR + 4`; both advance by `+8` per cycle when not stalled/redirected. Way 0
  always fetches even-indexed instruction words, way 1 always fetches odd-indexed words, in fixed
  program order — the hardware does not let you choose which way an instruction issues on.
- **Shared, dual-ported IMem.** `imemory.v`: one `mem[]` array, two independent read/data ports.
- **Shared register file, duplicated ALUs/multipliers.** `bridge_superscalar.cpp:130-131,206-207`
  reads the same `rf1__DOT__regs[]` array for both ways; distinct `al1`/`al2` multiplier instances
  per way.
- **Every pipeline register is duplicated per way** (`pc_fd_r_0/1`, `opcode_dx_r_0/1`,
  `alu_xm_r_0/1`, `addr_rd_mw_r_0/1`, `mw_pc_0/1`, etc.). `get_cpu_state(out, way)` returns one
  way's full `CPUState` per call; there is no single call that returns both ways at once.
- **Inter-way stalls are real and asymmetric** (`stall_signals.v:183,186`). `stall_0` = load/WD/
  store-rs2 hazards affecting way 0's consumer only. `stall_1` = the same three, OR'd with
  `two_way_write_use_case` (way 0's FD instruction writes a register way 1's FD instruction reads
  — way 1 alone stalls even though way 0 proceeds). `stall_0` and `stall_1` are independent — one
  way can stall while the other issues normally. **As established above, this asymmetry does not
  require new stage-matching logic in the validator** — it only affects which stall bit to check
  when suppressing the "should have advanced" error for a given way.

## File-by-file changes (outside PipelineValidator.cs — unchanged from original spec)

### Backend / build (`verilator/`, `bridge/`)

**`verilator/Makefile`** — `dll` target cross-compiles `design_wrapper_ss.dll` from
`bridge_superscalar.cpp` + `$(SS_OBJ_DIR)`, copied to `$(UNITY_PLUGINS_DIR)`. Confirm Linux/macOS
`bridge` step also copies `libdesign_wrapper_ss.$(LIB_EXT)` to Unity.

**`bridge/Makefile`** — `SYNC_FILES` includes `VerilatorClientSuperscalar.cs
FPGAClientSuperscalar.cs` so `make sync-unity` keeps Unity copies in sync.

**`bridge/README.md` and `verilator/README.md`** — document the new build targets once added.

### CPU wrapper (`unity/Assets/CPUWrapper/`)

**`CPUUnityExtensions.cs`** — `Create(...)` takes a `CPUFactory.CPUArchitecture` param (default
`Basic`), threaded into `CPUFactory.Create(hexInstructions, type, cpu_arch)`.

**`CPUController.cs`** — needs the level's `CPUArchitecture` (from `LevelData`) to size
`CPUState[] statesB` (1 for Basic/Blackbox, 2 for Superscalar). `AdvanceTick()` calls `cpu.Tick()`
once (one native tick already advances both ways — `bridge_superscalar.cpp:286-291` has no way
param), then `cpu.GetState(way)` once per way. `GetALUOutput()` and other passthroughs need a
`way` parameter, defaulting to 0.

### Level data / scene selection

**`unity/Assets/Scripts/LevelData.cs`** — architecture hint field so `CPUController` knows which
`CPUArchitecture` to request.

**New level JSON(s)** under `unity/Assets/Levels/Resources/JSON/` with `"sceneName": "Superscalar"`.
No `way` field on individual instructions — way assignment is a player action.

### Scene (Editor work, not code)

**New `unity/Assets/Scenes/Superscalar.unity`** — two parallel straight lines of `CPUStation`
prefabs (Start → Fetch₀ → Decode₀ → Execute₀ → Memory₀ → Writeback₀ → End, and the same for way 1).
One shared `StartPlatform`/`EndPlatform` matching program-order completion. One shared instruction
monitor UI. Reuse the (now-generalized) `TickButtonHandler` component for T-key input — do **not**
create a separate Superscalar-specific handler; see the deviation note at the top of this doc.
Scene creation itself is a user/Editor task.

### Gameplay / pipeline logic (all done, see "Done" above for exact behavior)

**`CPUStation.cs`** — `assignedWay`/`AssignedWay`, plus `PlaceBrick` now assigns `brick.Way` on
Fetch placement. **`InstructionBrick.cs`** — `Way`/`SetWay`, now wired up.
**`PipelineValidator.cs`** — full per-way rewrite. **`TickButtonHandler.cs`** — generalized to
loop over `CPUController.WayCount`; no separate Superscalar file.
**`InstructionMonitorCapture.cs`** — no signature change was needed; callers just pass
`statesB[station.AssignedWay]` now. **`CircuitTraceSpawner.cs`** — discovers stations by
`AssignedStage`/`AssignedWay` instead of `GameObject.Find`, one trace chain per way.
`CircuitTrace.cs` itself needed no changes.

### FPGA compatibility (no code changes now, but constrains the above)

`FPGAClientSuperscalar.cs` implements `ICPU` with `way` params end-to-end but every method is a
`NOT IMPLEMENTED` stub — stays a stub for this milestone. Because all new gameplay logic is written
against `ICPU`/`CPUState`/`GetState(way)` — never against `VerilatorClientSuperscalar` directly —
swapping to `ImplementationType.FPGA` later requires no gameplay-layer changes.

---

## Verification steps

Do these **in order**. Steps 1–2 are build/sync steps (the user is running these — Claude does not
run Makefiles or the Unity Editor). Steps 3+ verify existing (FiveStage/Blackbox) functionality
still works before any Superscalar-specific asset (scene, level JSON) is created — regressing the
two shipped scenes would be a much worse failure than a missing new one.

### 1. Build the native plugins

From `verilator/`:
```
make          # or `make dll` on Windows, `make bridge` on Linux/macOS
```
**Look for:** both `design_wrapper` and `design_wrapper_ss` libraries (`.dll` or `.so`/`.dylib`)
built with no compiler/linker errors, and both copied into `unity/Assets/Plugins/`
(`$(UNITY_PLUGINS_DIR)`). If the superscalar lib fails to build, check `CPUState` layout parity
between `bridge_superscalar.cpp` and `bridge/CPU.cs`'s `[StructLayout(LayoutKind.Sequential,
Pack = 1)]` struct — a mismatched field order/size will not fail to compile, it will silently
corrupt every `GetState(way)` call at runtime, so struct-layout regressions can pass the build step
and only surface in step 5 below.

### 2. Sync the bridge files into Unity

Before running `make sync-unity`, open `unity/Assets/CPUWrapper/` in the Unity Editor and create
two empty placeholder files, `VerilatorClientSuperscalar.cs` and `FPGAClientSuperscalar.cs`, so
Unity generates `.meta` files for them (`Assets > Create > C# Script`, or copy an existing script
and rename). The Makefile's sync step warns and skips a file with no `.meta` rather than failing
loudly, so a skipped file can silently leave stale content in place — confirm the warning list is
empty on the run that matters.

Then, from `bridge/`:
```
make sync-unity
```
**Look for:** the four target files under `unity/Assets/CPUWrapper/` (`CPU.cs`, `VerilatorClient.cs`,
`FPGAClient.cs`, plus the two superscalar files) all show a fresh `AUTO-GENERATED` header timestamp
and no "skipped — no .meta" warnings. Confirm `CPU.cs` now contains `stall_0`/`stall_1` fields
(`grep -n "stall_0" unity/Assets/CPUWrapper/CPU.cs`) — until this lands, `PipelineValidator.cs`
cannot compile.

### 3. Confirm the project compiles with zero new errors

Open the Unity Editor (or let it auto-recompile if already open) and check `Unity_GetConsoleLogs` /
the Console window.

**Look for:**
- Zero compiler errors. In particular: `PipelineValidator.cs` referencing `stall_0`/`stall_1`,
  `CPUController.cs` referencing `WayCount`/`statesB`, `TickButtonHandler.cs` referencing
  `cpuController.WayCount` and `station.AssignedWay` — these are the lines most likely to break if
  the sync in step 2 didn't fully land.
- No new warnings about missing script references on existing prefabs (`CPUStation` prefabs used
  by FiveStage/Blackbox) — a serialization error here would show up as "type CPUStation could not
  be found" or similar, not just a plain compiler error.
- If Unity was mid-recompile when an MCP call is made, it will report "Unity not detected" — wait
  ~8 seconds and retry once before treating it as a real failure.

### 4. Regression-test FiveStage and Blackbox (existing scenes, must still work unmodified)

This is the critical regression gate: `TickButtonHandler.cs`, `CPUController.cs`,
`InstructionMonitorCapture.cs`, and `CircuitTraceSpawner.cs` all changed in ways meant to be
behaviorally invisible on single-way scenes (`AssignedWay` defaults to `0` everywhere in these
scenes' existing prefabs). Confirm that's actually true before trusting the new Superscalar path.

**FiveStage (`level_01`–`level_03`, `FiveStage.unity`):**
- Enter Play Mode from the Main Menu, load a FiveStage level.
- **Console check first:** confirm no new errors/warnings appear on scene load (this exercises
  `CPUController.InitCPU` → `WayCount` should read `1`).
- Pick up a brick, place it on Fetch, press T. **Expect:** tick advances, brick's stage-1 material
  applies, no error toast. This exercises the new `CPUStation.PlaceBrick` way-assignment code path
  (`assignedWay` should be `0` on every FiveStage `CPUStation` prefab instance) — confirm no error
  fires purely from `Way` being newly set to `0` when it always implicitly was `0` before.
- Carry the brick through Decode → Execute → Memory → Writeback, pressing T at each station.
  **Expect:** the brick reaches Writeback and gets marked processed (compare against `EndScreen` —
  it should accept the brick at `EndPlatform`), matching pre-existing behavior.
- Check the circuit trace lines render between all six stage stations (Start→Fetch→...→End) with no
  "Could not find station for stage X, way 0" warnings in the console — this exercises the
  rewritten `CircuitTraceSpawner`.
- Check the instruction monitor UI updates at Decode/Memory/Writeback as before (exercises
  `InstructionMonitorCapture.CaptureAtStage` receiving `statesB[0]`, same value as the old
  single-`CPUState` call).

**Blackbox (`level_00`, `Blackbox.unity`):**
- Enter Play Mode, load the Blackbox level.
- Place a brick on the single `BlackboxStation` and let it auto-advance via its coroutine.
  **Expect:** unchanged behavior — `BlackboxStation` does not go through `TickButtonHandler` or
  `CPUStation.PlaceBrick` at all, so this is a lower-risk check, but confirm no new console errors
  appear from `CPUController` (e.g. `WayCount` being read as `1` for a Basic-architecture level).

**Edge cases to playtest on both scenes:**
- Retry/reload a level mid-session (triggers `CPUController.InitCPU` a second time) — confirm no
  duplicate-init errors and `WayCount` is still correctly `1` on the reloaded level.
- Press T with no bricks placed anywhere — **expect:** either a no-op or a validation error
  referencing `way=0` in the message text (from `CheckReverseFetch`), never a null-reference
  exception or an error mentioning `way=1`.
- Place a brick on the wrong stage (skip Decode, put it straight on Execute) and press T —
  **expect:** the existing "not in the pipeline at this stage" validation error, unchanged wording
  apart from the new `[pc=..., way=0]` suffix now present in every message.

If any of the above regresses, stop and fix before creating the Superscalar scene — the new scene
will be much harder to debug against a already-broken shared code path.

---

## Tests to run once the Superscalar scene + level JSON exist (not yet — future work)

These cannot be executed until `Superscalar.unity` and a `"sceneName": "Superscalar"` level JSON
are created (both still deferred, Editor/user tasks — see "Not started" above). Recorded here so
the next session has a concrete checklist instead of re-deriving it.

1. **Scene load / console check.** Load the Superscalar level from the Main Menu. Confirm
   `CPUController.InitCPU` logs `cpuArchitecture = Superscalar` and no errors — this is the first
   real exercise of `WayCount == 2` and the two-way `statesB` array end-to-end.
2. **Both Fetch stations populate independently.** Two bricks should be spawnable and routable to
   Fetch₀ and Fetch₁ separately. Confirm `CPUStation.PlaceBrick` sets `Way` correctly on each
   (e.g. temporarily log `brick.Way` after placement, or infer it from whether validation passes).
3. **Correct routing passes validation.** Place the earlier-PC brick at Fetch₀ and the later-PC
   brick at Fetch₁ (per program order — way 0 is always the even-indexed instruction word, way 1
   the odd), press T. **Expect:** no validation error, both bricks advance.
4. **Swapped routing fails `CheckFetchOrdering`.** Place the later-PC brick at Fetch₀ and the
   earlier-PC brick at Fetch₁, press T. **Expect:** a validation error mentioning "Way 1 Fetch
   holds an older instruction than way 0" (from `PipelineValidator.CheckFetchOrdering`), and no
   tick advance.
5. **Recovery after a routing error.** From the failed state in test 4, pick the brick back up
   (`CPUStation.OnInteract` → `RemoveBrick`) and move it to the other way's Fetch station, press T
   again. **Expect:** validation now passes — confirms `PlaceBrick`'s way re-assignment (not just
   first-placement) works as designed (see the "Done" note on `CPUStation.cs` above).
6. **One Fetch station empty while the other has pending work.** Leave Fetch₁ empty while way 1
   still has unfetched instructions (`wayPc < nextSpawnPc`), press T. **Expect:** a "should be at
   Fetch" error from `CheckReverseFetch` for way 1 specifically (`way=1` in the message), not a
   silent pass.
7. **Stall labeling, not suppression.** Find or construct a scenario that triggers `stall_0` or
   `stall_1` (e.g. a load-use hazard across the two ways per `stall_signals.v:186`). **Expect:** if
   an unrelated validation error fires on that way that tick, its message includes the
   `" (way <n> stalled)"` suffix; confirm a *correctly placed* stalled brick produces **no** error
   at all (per the spec's "stall bits never gate whether an error fires" design decision) — this is
   the trickiest case to get wrong, since a naive re-implementation might be tempted to add
   stall-conditional branching that isn't needed.
8. **Program completion / EndPlatform.** Run a full short program to completion across both ways.
   **Expect:** every brick eventually reaches its way's Writeback station, gets marked processed via
   `TickButtonHandler.MarkRetiredWritebackBrick` comparing `statesB[station.AssignedWay].mw_pc`, and
   `EndPlatform` accepts all of them, triggering the level-complete flow same as FiveStage.
9. **Circuit traces render correctly for both ways.** Visual check — two parallel trace lines,
   Start→Fetch₀→...→Writeback₀→End and Start→Fetch₁→...→Writeback₁→End, with no console warnings
   about missing stations (exercises `CircuitTraceSpawner`'s `wayCount` auto-detection actually
   finding `2`).
10. **Instruction monitor UI shows the correct way's data.** With bricks on both ways
    simultaneously, confirm the monitor doesn't cross-contaminate — e.g. way 1's Memory-stage
    `alu_out` capture should never show way 0's value. Directly exercises the
    `statesB[station.AssignedWay]` indexing in `TickButtonHandler.CaptureMonitorData`.

claude --resume 9f9c39bc-775e-4301-a9b3-599d779deec2
