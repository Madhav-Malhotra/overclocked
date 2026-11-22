#!/usr/bin/env python3
"""
Compare an out-of-order core trace against a spike commit trace.

The OoO core writes registers back out of program order, so the scalar
commit-by-commit comparison (verilog/verif/scripts/cmp_wb_spike.py) does not
apply. Instead this script checks three things:

  (a) Per-register write sequences. For every architectural register, the
      ordered list of (pc, value) writes in the core trace must equal spike's.
      This is valid because the WAW dispatch stall keeps all writes to one
      register in program order, even though writes to *different*
      registers interleave freely.
  (b) Final register values (last write per register). Mostly implied by (a);
      reported as a readable summary.
  (c) Stores. The ordered list of (pc, addr, size, data) memory writes must
      equal spike's. Stores reach memory in program order in this design
      (one store FU, reserved dispatch -> WB, in-order dispatch).

Inputs
  proc trace  : OoO event trace (verif/tests/trace_dump.h). Uses
                  [W] pc we rd data [@cycle]
                  [M] pc addr size_bytes data [@cycle]
  spike trace : verif/scripts/spike_trace_gen.py output
                  <pc> <rd_dec> <value>
                  S <pc> <addr> <size_bytes> <data>

Options
  --allow-truncated  the simulation stopped early (e.g. TIMEOUT): accept each
                     core sequence being a *prefix* of spike's. Extra or
                     different writes still fail.
  --skip-stores      do not compare stores (e.g. before the [M] event exists).

Exit: 0 = PASS, 1 = FAIL, 2 = usage / missing file.
"""

import argparse
import sys
from collections import OrderedDict, defaultdict
from pathlib import Path


def _hex8(s: str) -> str:
    return s.lower().removeprefix("0x").zfill(8)


def parse_proc_trace(path: Path):
    """Return (reg_writes, stores, x0_writes) from an OoO trace.

    reg_writes: list of (pc, rd, value) in trace order, we=1 and rd!=0 only
    stores:     list of (pc, addr, size, data) in trace order
    x0_writes:  list of (pc, value) for any we=1 write to x0 (always a bug)
    """
    reg_writes, stores, x0_writes = [], [], []
    with open(path) as f:
        for lineno, line in enumerate(f, 1):
            parts = line.split()
            if not parts:
                continue
            tag = parts[0]
            if tag == "[W]":
                if len(parts) < 5:
                    raise ValueError(f"{path}:{lineno}: malformed [W] line: {line.rstrip()}")
                pc, we, rd, val = parts[1], parts[2], parts[3], parts[4]
                if int(we, 16) == 0:
                    continue
                rd_i = int(rd, 16)
                if rd_i == 0:
                    x0_writes.append((_hex8(pc), _hex8(val)))
                    continue
                reg_writes.append((_hex8(pc), rd_i, _hex8(val)))
            elif tag == "[M]":
                if len(parts) < 5:
                    raise ValueError(f"{path}:{lineno}: malformed [M] line: {line.rstrip()}")
                stores.append((_hex8(parts[1]), _hex8(parts[2]), int(parts[3]), _hex8(parts[4])))
    return reg_writes, stores, x0_writes


def parse_spike_trace(path: Path):
    """Return (reg_writes, stores) in program order from a spike commit trace."""
    reg_writes, stores = [], []
    with open(path) as f:
        for lineno, line in enumerate(f, 1):
            parts = line.split()
            if not parts:
                continue
            if parts[0] == "S":
                if len(parts) < 5:
                    raise ValueError(f"{path}:{lineno}: malformed store line: {line.rstrip()}")
                stores.append((_hex8(parts[1]), _hex8(parts[2]), int(parts[3]), _hex8(parts[4])))
            else:
                if len(parts) < 3:
                    raise ValueError(f"{path}:{lineno}: malformed line: {line.rstrip()}")
                rd = int(parts[1])
                if rd == 0:
                    continue
                reg_writes.append((_hex8(parts[0]), rd, _hex8(parts[2])))
    return reg_writes, stores


def group_by_reg(writes):
    groups = defaultdict(list)
    for pc, rd, val in writes:
        groups[rd].append((pc, val))
    return groups


def compare_seq(proc, spike, allow_truncated):
    """Compare two sequences. Returns (ok, first_bad_index or None, reason)."""
    n = min(len(proc), len(spike))
    for i in range(n):
        if proc[i] != spike[i]:
            return False, i, "differs"
    if len(proc) > len(spike):
        return False, n, "extra in core"
    if len(proc) < len(spike) and not allow_truncated:
        return False, n, "missing in core"
    return True, None, ""


def main() -> int:
    ap = argparse.ArgumentParser(description="Compare OoO core trace vs spike (order-insensitive across registers)")
    ap.add_argument("proc_trace")
    ap.add_argument("spike_trace")
    ap.add_argument("--out", help="write a detailed report here")
    ap.add_argument("--allow-truncated", action="store_true",
                    help="accept core sequences that are prefixes of spike's (sim stopped early)")
    ap.add_argument("--skip-stores", action="store_true", help="do not compare stores")
    args = ap.parse_args()

    proc_path, spike_path = Path(args.proc_trace), Path(args.spike_trace)
    for p in (proc_path, spike_path):
        if not p.exists():
            print(f"ERROR: not found: {p}", file=sys.stderr)
            return 2

    try:
        p_regs, p_stores, p_x0 = parse_proc_trace(proc_path)
        s_regs, s_stores = parse_spike_trace(spike_path)
    except ValueError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 2

    bench = proc_path.stem
    report = [f"Benchmark: {bench}",
              f"Core reg writes: {len(p_regs)}   Spike reg writes: {len(s_regs)}",
              f"Core stores:     {len(p_stores)}   Spike stores:     {len(s_stores)}",
              f"Mode: {'allow-truncated' if args.allow_truncated else 'exact'}"
              f"{', stores skipped' if args.skip_stores else ''}",
              ""]
    failures = []

    # x0 must never be written
    for pc, val in p_x0:
        failures.append(f"x0 written: pc={pc} val={val}")

    # (a) per-register sequences
    p_by, s_by = group_by_reg(p_regs), group_by_reg(s_regs)
    report.append("(a) Per-register write sequences")
    for rd in sorted(set(p_by) | set(s_by)):
        p_seq, s_seq = p_by.get(rd, []), s_by.get(rd, [])
        ok, idx, why = compare_seq(p_seq, s_seq, args.allow_truncated)
        status = "OK" if ok else "MISMATCH"
        report.append(f"  x{rd:<2} {status:8} core={len(p_seq):<4} spike={len(s_seq):<4}"
                      + ("" if ok else f" first bad #{idx} ({why})"))
        if not ok:
            pc_c = p_seq[idx] if idx < len(p_seq) else None
            pc_s = s_seq[idx] if idx < len(s_seq) else None
            failures.append(f"x{rd} write #{idx} {why}: core={pc_c} spike={pc_s}  (pc, value)")

    # (b) final register values
    report.append("")
    report.append("(b) Final register values (last write)")
    for rd in sorted(set(p_by) | set(s_by)):
        p_last = p_by[rd][-1][1] if p_by.get(rd) else "--------"
        s_last = s_by[rd][-1][1] if s_by.get(rd) else "--------"
        mark = "" if p_last == s_last else "   <-- differs"
        report.append(f"  x{rd:<2} core={p_last} spike={s_last}{mark}")

    # (c) stores
    report.append("")
    if args.skip_stores:
        report.append("(c) Stores: SKIPPED")
    else:
        ok, idx, why = compare_seq(p_stores, s_stores, args.allow_truncated)
        report.append(f"(c) Stores (program order): {'OK' if ok else 'MISMATCH'}")
        if not ok:
            c = p_stores[idx] if idx < len(p_stores) else None
            s = s_stores[idx] if idx < len(s_stores) else None
            failures.append(f"store #{idx} {why}: core={c} spike={s}  (pc, addr, size, data)")
            if not p_stores and s_stores:
                failures.append("hint: core trace has no [M] lines; define M_VALID in design/signals.h "
                                "or pass --skip-stores")

    passed = not failures
    report.append("")
    report.append("RESULT: " + ("PASS" if passed else f"FAIL ({len(failures)} problem(s))"))
    report.extend(f"  - {f}" for f in failures)

    if args.out:
        Path(args.out).parent.mkdir(parents=True, exist_ok=True)
        Path(args.out).write_text("\n".join(report) + "\n")

    if passed:
        print(f"PASS: {bench} ({len(p_regs)} reg writes, {len(p_stores)} stores)")
    else:
        print(f"FAIL: {bench}")
        for f in failures[:8]:
            print(f"  - {f}")
        if len(failures) > 8:
            print(f"  ... {len(failures) - 8} more" + (f" (see {args.out})" if args.out else ""))
    return 0 if passed else 1


if __name__ == "__main__":
    sys.exit(main())
