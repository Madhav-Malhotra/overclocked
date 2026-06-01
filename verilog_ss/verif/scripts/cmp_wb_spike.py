#!/usr/bin/env python3
"""
Compare processor writeback trace vs spike commit trace.

Reads [W] lines from a processor trace and a spike commit trace,
then compares register write sequences commit-by-commit.

The spike trace is truncated to the length of the processor trace
to naturally handle the trailing HTIF writes (la t0,tohost writes x5
which the processor never commits after ecall timeout).

Usage:
    python3 cmp_wb_spike.py <proc_trace> <spike_trace> [--out <report>]

Exit: 0 = PASS, 1 = FAIL
"""

import argparse
import sys
from pathlib import Path


def parse_proc_trace(path: Path) -> list:
    """Extract register commits from processor [W] trace lines.

    Looks for lines like:
        [W] 01000004 1 1 00000005
        prefix pc write_enable rd value

    Returns list of (pc, rd, value) tuples where write_enable=1 and rd != 0.
    """
    commits = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line.startswith("[W]"):
                continue
            parts = line.split()
            # [W] pc write_enable rd value
            if len(parts) < 5:
                continue
            we = parts[2]
            rd = parts[3]
            val = parts[4]
            if we != "1":
                continue
            if rd == "00" or rd == "0":
                continue
            pc = parts[1].lower().zfill(8)
            rd_int = int(rd, 16) if len(rd) <= 2 else int(rd)
            val_norm = val.lower().zfill(8)
            commits.append((pc, rd_int, val_norm))
    return commits


def parse_spike_trace(path: Path) -> list:
    """Load spike commit trace.

    Format: <pc_hex8> <rd_dec> <value_hex8>
    Returns list of (pc, rd, value) tuples.
    """
    commits = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 3:
                continue
            pc = parts[0].lower().zfill(8)
            rd_int = int(parts[1])
            val = parts[2].lower().zfill(8)
            commits.append((pc, rd_int, val))
    return commits


def compare(proc_commits: list, spike_commits: list, bench_name: str, out_path=None):
    """Compare two commit sequences, truncated to shorter length.

    Returns (passed: bool, n_mismatches: int, n_compared: int).
    """
    n = min(len(proc_commits), len(spike_commits))
    mismatches = 0
    rows = []

    for i in range(n):
        p_pc, p_rd, p_val = proc_commits[i]
        s_pc, s_rd, s_val = spike_commits[i]
        ok = (p_pc == s_pc) and (p_rd == s_rd) and (p_val == s_val)
        if not ok:
            mismatches += 1
        rows.append((i, ok, p_pc, p_rd, p_val, s_pc, s_rd, s_val))

    passed = mismatches == 0

    if out_path:
        Path(out_path).parent.mkdir(parents=True, exist_ok=True)
        with open(out_path, "w") as f:
            f.write(f"Benchmark: {bench_name}\n")
            f.write(f"Compared: {n} commits  Mismatches: {mismatches}\n")
            f.write(f"Proc commits: {len(proc_commits)}  Spike commits: {len(spike_commits)}\n")
            f.write("\n")
            header = f"{'#':>4}  {'':6}  {'PROC_PC':8}  {'RD':>3}  {'PROC_VAL':8}    {'SPIKE_PC':8}  {'RD':>3}  {'SPIKE_VAL':8}\n"
            f.write(header)
            f.write("-" * len(header) + "\n")
            for i, ok, p_pc, p_rd, p_val, s_pc, s_rd, s_val in rows:
                status = "OK     " if ok else "MISMATCH"
                f.write(f"{i:>4}  {status}  {p_pc}  {p_rd:>3}  {p_val}    {s_pc}  {s_rd:>3}  {s_val}\n")

    return passed, mismatches, n


def main() -> int:
    parser = argparse.ArgumentParser(description="Compare processor vs spike register commits")
    parser.add_argument("proc_trace", help="Processor trace file (FDXMW format)")
    parser.add_argument("spike_trace", help="Spike commit trace file")
    parser.add_argument("--out", help="Write detailed report to this file")
    args = parser.parse_args()

    proc_path = Path(args.proc_trace)
    spike_path = Path(args.spike_trace)
    bench_name = proc_path.stem

    if not proc_path.exists():
        print(f"ERROR: processor trace not found: {proc_path}", file=sys.stderr)
        return 1
    if not spike_path.exists():
        print(f"ERROR: spike trace not found: {spike_path}", file=sys.stderr)
        return 1

    proc_commits = parse_proc_trace(proc_path)
    spike_commits = parse_spike_trace(spike_path)

    passed, mismatches, n = compare(proc_commits, spike_commits, bench_name, args.out)

    if passed:
        print(f"PASS: {bench_name} ({n} commits)")
    else:
        print(f"FAIL: {bench_name} ({mismatches} mismatches, {n} commits)")
        # Print first few mismatches for quick diagnosis
        n_show = min(len(proc_commits), len(spike_commits))
        shown = 0
        for i in range(n_show):
            if shown >= 5:
                break
            p = proc_commits[i]
            s = spike_commits[i]
            if p != s:
                print(f"  [{i}] PROC: pc={p[0]} rd={p[1]} val={p[2]}")
                print(f"  [{i}] SPIKE: pc={s[0]} rd={s[1]} val={s[2]}")
                shown += 1

    return 0 if passed else 1


if __name__ == "__main__":
    sys.exit(main())
