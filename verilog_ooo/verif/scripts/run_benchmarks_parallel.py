#!/usr/bin/env python3
"""
Parallel benchmark runner for the OoO core: build -> simulate -> spike compare.

OoO version of verilog/verif/scripts/run_benchmarks_parallel.py. Differences:
  * simulation goes through `make all` in this directory (one place for the
    Verilator flags), each benchmark in its own SIM_DIR so runs are parallel;
  * spike traces come from spike_trace_gen.py (register writes + stores);
  * comparison uses cmp_ooo_spike.py (order-insensitive across registers),
    not the scalar commit-by-commit compare;
  * suites: ooo-tests, individual-instructions, simple-programs,
    superscalar-tests (select with --suite).

Usage:
    python3 run_benchmarks_parallel.py --bench-root <rv32-benchmarks> \
        --scripts-dir <verif/scripts> --cl-root <verilog_ooo> \
        [--suite ooo|individual|simple|superscalar|all] [--jobs N] \
        [--timeout CYCLES] [--skip-build] [--allow-truncated] [--skip-stores]
        [--make-arg VAR=value ...]

Exit: 0 only if every benchmark PASSes; any FAIL or SKIP gives 1.
"""

import argparse
import os
import subprocess
import sys
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

SCRIPTS_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPTS_DIR))
import spike_trace_gen  # noqa: E402

SUITES = {
    "ooo": ("ooo-tests", "Makefile"),
    "individual": ("individual-instructions", "Makefile.new"),
    "simple": ("simple-programs", "Makefile.iss"),
    "superscalar": ("superscalar-tests", "Makefile.new"),
}

_print_lock = threading.Lock()


def tprint(*args, **kwargs):
    with _print_lock:
        print(*args, **kwargs, flush=True)


def build_benchmarks(bench_root: Path, suites: list, jobs: int):
    print("Building benchmarks from source...")
    for key in suites:
        d, makefile = SUITES[key]
        r = subprocess.run(["make", "-C", str(bench_root / d), "-f", makefile, f"-j{jobs}", "all"],
                           capture_output=True, text=True)
        if r.returncode != 0:
            print(f"WARNING: build failed in {d}: {r.stderr[-300:]}")
    print("Benchmarks built.")


def simulate(bench_x: Path, scripts_dir: Path, sim_dir: Path, timeout: int,
             make_args: list) -> tuple:
    """Run `make all` for one benchmark in its own SIM_DIR. Returns (ok, log_tail)."""
    sim_dir.mkdir(parents=True, exist_ok=True)
    cmd = ["make", "-s", "-C", str(scripts_dir), "all",
           f"MEM_PATH={bench_x.resolve()}", f"SIM_DIR={sim_dir}",
           f"TIMEOUT={timeout}", "WARN=0", *make_args]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
    return r.returncode == 0, (r.stdout + r.stderr)[-800:]


def process_benchmark(bench_x: Path, args, spike_traces_dir: Path, diff_dir: Path,
                      sim_base: Path) -> dict:
    name = bench_x.stem
    res = {"name": name}
    sim_dir = sim_base / f"bench_{name}"
    trace = sim_dir / f"{name}.trace"

    try:
        ok, log = simulate(bench_x, args.scripts_dir, sim_dir, args.timeout, args.make_arg)
    except subprocess.TimeoutExpired:
        ok, log = False, "wall-clock timeout"
    if not ok or not trace.exists():
        res.update(status="skip", message=f"SKIP: {name} (simulation failed)\n    {log.strip().splitlines()[-1] if log.strip() else ''}")
        tprint(res["message"])
        return res

    try:
        elf = spike_trace_gen.find_elf(name, args.bench_root)
        commits = spike_trace_gen.parse_spike_output(spike_trace_gen.run_spike(elf))
    except FileNotFoundError as e:
        res.update(status="skip", message=f"SKIP: {name} ({str(e).splitlines()[0]})")
        tprint(res["message"])
        return res
    except subprocess.TimeoutExpired:
        res.update(status="skip", message=f"SKIP: {name} (spike timeout)")
        tprint(res["message"])
        return res
    spike_trace = spike_traces_dir / f"{name}.trace"
    spike_trace_gen.write_spike_trace(commits, spike_trace)

    cmd = [sys.executable, str(SCRIPTS_DIR / "cmp_ooo_spike.py"), str(trace), str(spike_trace),
           "--out", str(diff_dir / f"{name}.diff")]
    if args.allow_truncated:
        cmd.append("--allow-truncated")
    if args.skip_stores:
        cmd.append("--skip-stores")
    r = subprocess.run(cmd, capture_output=True, text=True)
    out = r.stdout.strip()
    if r.returncode == 0:
        res.update(status="pass", message=out)
    elif r.returncode == 1:
        res.update(status="fail", message="\n".join(out.splitlines()[:4]))
    else:
        res.update(status="skip", message=f"SKIP: {name} (compare error: {r.stderr.strip()[:200]})")
    tprint(res["message"])
    return res


def main() -> int:
    ap = argparse.ArgumentParser(description="Run OoO benchmarks in parallel")
    ap.add_argument("--bench-root", required=True, type=Path)
    ap.add_argument("--scripts-dir", required=True, type=Path)
    ap.add_argument("--cl-root", required=True, type=Path)
    ap.add_argument("--suite", default="all", choices=list(SUITES) + ["all"])
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--timeout", type=int, default=50000, help="simulation timeout in cycles")
    ap.add_argument("--skip-build", action="store_true")
    ap.add_argument("--allow-truncated", action="store_true")
    ap.add_argument("--skip-stores", action="store_true")
    ap.add_argument("--make-arg", action="append", default=[],
                    help="extra VAR=value passed to `make all` (repeatable), e.g. SRC=... to test other RTL")
    args = ap.parse_args()
    args.bench_root = args.bench_root.resolve()
    args.scripts_dir = args.scripts_dir.resolve()
    cl_root = args.cl_root.resolve()

    suites = list(SUITES) if args.suite == "all" else [args.suite]
    spike_traces_dir = cl_root / "verif" / "spike_traces"
    diff_dir = cl_root / "verif" / "diffs" / "spike"
    sim_base = cl_root / "verif" / "sim" / "verilator" / "parallel"
    diff_dir.mkdir(parents=True, exist_ok=True)

    if not args.skip_build:
        build_benchmarks(args.bench_root, suites, args.jobs)

    benches = []
    for key in suites:
        benches += sorted((args.bench_root / SUITES[key][0]).glob("*.x"))
    if not benches:
        print("ERROR: no benchmarks found (build them first?)")
        return 1

    print(f"Running {len(benches)} benchmarks ({', '.join(suites)}) with {args.jobs} workers...\n")
    results = []
    with ThreadPoolExecutor(max_workers=args.jobs) as ex:
        futs = {ex.submit(process_benchmark, b, args, spike_traces_dir, diff_dir, sim_base): b
                for b in benches}
        for f in as_completed(futs):
            try:
                results.append(f.result())
            except Exception as e:  # keep going on unexpected errors
                b = futs[f]
                tprint(f"SKIP: {b.stem} (unexpected error: {e})")
                results.append({"name": b.stem, "status": "skip"})

    n = {s: sum(1 for r in results if r["status"] == s) for s in ("pass", "fail", "skip")}
    print("\n==========================================")
    print("SUMMARY")
    print("==========================================")
    print(f"  Passed:  {n['pass']}\n  Failed:  {n['fail']}\n  Skipped: {n['skip']}")
    print("==========================================")
    for status in ("fail", "skip"):
        names = sorted(r["name"] for r in results if r["status"] == status)
        if names:
            print(f"\n{status.capitalize()}ed benchmarks:" if status == "fail" else "\nSkipped benchmarks:")
            for nm in names:
                print(f"  {nm}")
    print(f"\nDiff reports: {diff_dir}")
    # Success only if every benchmark ran and passed (a skip is a build/sim/spike problem)
    return 0 if n["pass"] == len(results) else 1


if __name__ == "__main__":
    sys.exit(main())
