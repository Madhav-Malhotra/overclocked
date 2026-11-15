#!/usr/bin/env python3
"""
Top-level test runner for the out-of-order core (verilog_ooo).

Same entry point as verilog/run_scripts.py and verilog_ss/run_scripts.py, but the
OoO flow is: lint -> unit testbenches -> build benchmarks -> parallel
simulate + spike compare (verif/scripts/run_benchmarks_parallel.py, which uses
the order-insensitive verif/scripts/cmp_ooo_spike.py).

The scalar runners diff full per-cycle FDXMW traces against golden traces; that
does not apply to an out-of-order core, whose traces are compared against spike
instead (see verif/README.md).

Usage:
    python3 run_scripts.py                    # everything, all suites
    python3 run_scripts.py --suite ooo        # only rv32-benchmarks/ooo-tests
    python3 run_scripts.py --skip-lint --skip-unit --skip-build --jobs 4
    python3 run_scripts.py --allow-truncated  # accept runs that stopped at TIMEOUT

Exit: 0 if every step passed, 1 otherwise.
"""

import argparse
import os
import subprocess
import sys
from pathlib import Path

BASE = Path(__file__).resolve().parent
SCRIPTS = BASE / "verif" / "scripts"
BENCH_ROOT = BASE / "rv32-benchmarks"


def step(title: str, cmd: list) -> bool:
    print(f"\n========== {title} ==========", flush=True)
    r = subprocess.run(cmd)
    ok = r.returncode == 0
    print(f"---------- {title}: {'OK' if ok else 'FAILED'} ----------", flush=True)
    return ok


def main() -> int:
    ap = argparse.ArgumentParser(description="Run the OoO core verification flow")
    ap.add_argument("--suite", default="all",
                    choices=["ooo", "individual", "simple", "superscalar", "all"])
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--timeout", type=int, default=50000, help="simulation timeout in cycles")
    ap.add_argument("--skip-lint", action="store_true")
    ap.add_argument("--skip-unit", action="store_true")
    ap.add_argument("--skip-build", action="store_true")
    ap.add_argument("--allow-truncated", action="store_true")
    ap.add_argument("--skip-stores", action="store_true")
    args = ap.parse_args()

    results = {}
    if not args.skip_lint:
        results["lint"] = step("Lint (verilator + iverilog)", ["make", "-s", "-C", str(SCRIPTS), "lint"])
    if not args.skip_unit:
        results["unit tests"] = step("Unit testbenches", ["make", "-s", "-C", str(SCRIPTS), "unit_tests"])

    bench_cmd = [sys.executable, str(SCRIPTS / "run_benchmarks_parallel.py"),
                 "--bench-root", str(BENCH_ROOT), "--scripts-dir", str(SCRIPTS),
                 "--cl-root", str(BASE), "--suite", args.suite,
                 "--jobs", str(args.jobs), "--timeout", str(args.timeout)]
    if args.skip_build:
        bench_cmd.append("--skip-build")
    if args.allow_truncated:
        bench_cmd.append("--allow-truncated")
    if args.skip_stores:
        bench_cmd.append("--skip-stores")
    results["benchmarks"] = step(f"Benchmarks (suite: {args.suite})", bench_cmd)

    print("\n========== SUMMARY ==========")
    for name, ok in results.items():
        print(f"  {name:<12} {'PASS' if ok else 'FAIL'}")
    return 0 if all(results.values()) else 1


if __name__ == "__main__":
    sys.exit(main())
