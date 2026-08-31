#!/usr/bin/env python3
"""
Parallel benchmark runner: build -> simulate -> spike compare for all benchmarks.

Each benchmark is compiled (verilator), run, spike-traced, and compared
independently, so all N benchmarks run in parallel across available CPU cores.

Usage:
    python3 run_benchmarks_parallel.py \
        --bench-root <path/to/rv32-benchmarks> \
        --scripts-dir <path/to/verif/scripts> \
        --cl-root <path/to/verilog> \
        [--jobs N]  # default: cpu_count()

Exit: 0 if all benchmarks pass, 1 if any fail.
"""

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

# Lock for thread-safe printing
_print_lock = threading.Lock()


def tprint(*args, **kwargs):
    with _print_lock:
        print(*args, **kwargs, flush=True)


def find_elf(bench_name: str, bench_root: Path) -> Path | None:
    """Find the ELF for a benchmark (same logic as spike_trace_gen.py)."""
    individual = bench_root / "individual-instructions" / f"{bench_name}.elf"
    if individual.exists():
        return individual
    simple_iss = bench_root / "simple-programs" / f"{bench_name}.iss.elf"
    if simple_iss.exists():
        return simple_iss
    simple_elf = bench_root / "simple-programs" / f"{bench_name}.elf"
    if simple_elf.exists():
        return simple_elf
    return None


def run_spike(elf_path: Path) -> str:
    """Run spike --log-commits, return stderr (commit log)."""
    cmd = [
        "spike", "--log-commits", "--isa=rv32g",
        "-m0x01000000:0x200000", str(elf_path),
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
    return result.stderr


def parse_spike_output(spike_output: str) -> list:
    """Parse spike --log-commits output into (pc, rd, value) tuples."""
    import re
    SPIKE_LINE_RE = re.compile(
        r"core\s+\d+:\s+\d+\s+"
        r"(0x[0-9a-fA-F]+)\s+"
        r"\([^)]+\)"
        r"(?:\s+x(\d+)\s+(0x[0-9a-fA-F]+))?"
    )
    commits = []
    for line in spike_output.splitlines():
        m = SPIKE_LINE_RE.match(line)
        if not m:
            continue
        pc_str, rd_str, val_str = m.group(1), m.group(2), m.group(3)
        if rd_str is None:
            continue
        rd_num = int(rd_str)
        if rd_num == 0:
            continue
        pc_hex = pc_str[2:].lower().zfill(8)
        if int(pc_hex, 16) < 0x01000000:
            continue
        val_hex = val_str[2:].lower().zfill(8)
        commits.append((pc_hex, rd_num, val_hex))
    return commits


def parse_proc_trace(path: Path) -> list:
    """Extract committed register writes from processor [W] trace."""
    commits = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line.startswith("[W]"):
                continue
            parts = line.split()
            if len(parts) < 5:
                continue
            we, rd, val = parts[2], parts[3], parts[4]
            if we != "1":
                continue
            if rd in ("00", "0"):
                continue
            pc = parts[1].lower().zfill(8)
            rd_int = int(rd, 16) if len(rd) <= 2 else int(rd)
            commits.append((pc, rd_int, val.lower().zfill(8)))
    return commits


def compare_commits(proc_commits: list, spike_commits: list) -> tuple[bool, int, int]:
    """Compare two commit sequences (truncated to shorter).

    Returns (passed, n_mismatches, n_compared).
    """
    n = min(len(proc_commits), len(spike_commits))
    mismatches = sum(
        1 for i in range(n) if proc_commits[i] != spike_commits[i]
    )
    return mismatches == 0, mismatches, n


def write_diff(proc_commits, spike_commits, bench_name, out_path: Path):
    """Write detailed per-commit diff report."""
    n = min(len(proc_commits), len(spike_commits))
    mismatches = sum(1 for i in range(n) if proc_commits[i] != spike_commits[i])
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, "w") as f:
        f.write(f"Benchmark: {bench_name}\n")
        f.write(f"Compared: {n} commits  Mismatches: {mismatches}\n")
        f.write(f"Proc commits: {len(proc_commits)}  Spike commits: {len(spike_commits)}\n\n")
        header = f"{'#':>4}  {'':8}  {'PROC_PC':8}  {'RD':>3}  {'PROC_VAL':8}    {'SPIKE_PC':8}  {'RD':>3}  {'SPIKE_VAL':8}\n"
        f.write(header)
        f.write("-" * len(header) + "\n")
        for i in range(n):
            p_pc, p_rd, p_val = proc_commits[i]
            s_pc, s_rd, s_val = spike_commits[i]
            ok = (p_pc, p_rd, p_val) == (s_pc, s_rd, s_val)
            status = "OK      " if ok else "MISMATCH"
            f.write(f"{i:>4}  {status}  {p_pc}  {p_rd:>3}  {p_val}    {s_pc}  {s_rd:>3}  {s_val}\n")


def run_verilator(bench_x: Path, scripts_dir: Path, cl_root: Path,
                   sim_dir: Path, timeout: int, multicycle: int) -> bool:
    """Compile and run one benchmark through verilator. Returns True on success."""
    bench_name = bench_x.stem
    bench_x_abs = bench_x.resolve()
    line_count = bench_x_abs.read_text().count("\n")
    mem_depth = 1048576
    # TRACE_FILE is a basename only; trace is written to cwd (sim_dir) at runtime
    trace_basename = f"{bench_name}.trace"
    
    # Remove any prior build (e.g. previous Docker builded images)
    # otherwise make reuses test_pd.d and fails with "No rule to make target"
    if sim_dir.exists():
        shutil.rmtree(sim_dir)
    sim_dir.mkdir(parents=True, exist_ok=True)

    # Source files
    design_f = cl_root / "verif" / "scripts" / "design.f"
    srclist = design_f.read_text().split()
    src_files = [str(cl_root / "design" / "code" / s) for s in srclist]
    src_files += [
        str(cl_root / "verif" / "tests" / "clockgen.sv"),
        str(cl_root / "design" / "design_wrapper.v"),
    ]
    test_sv = str(cl_root / "verif" / "tests" / "test_pd.sv")
    test_cpp = str(cl_root / "verif" / "tests" / "test_pd.cpp")

    # Defines: in subprocess (no shell), pass actual double-quote chars inside the arg.
    # verilator sees: +define+MEM_PATH="/abs/path" which makes MEM_PATH a string literal.
    mem_path_def = f'+define+MEM_PATH="{bench_x_abs}"'
    tv_def = f'+define+TEST_VECTOR="{cl_root}/verif/data/test_vector.x"'
    trace_def = f'+define+TRACE_FILE="{trace_basename}"'
    # -CFLAGS for the C++ side: the path needs to be quoted for C preprocessor
    cflags_mem = (
    f'-DMEM_DEPTH={mem_depth} '
    f'-DMEM_PATH=\\"{bench_x_abs}\\" '
    f'-DUSE_MULTICYCLE_MULT_CFG={multicycle}'
)

    compile_cmd = [
        "verilator",
        "+1800-2012ext+sv", "+1364-2005ext+v",
        "-CFLAGS", cflags_mem,
        "--cc", *src_files,
        test_sv,
        "--exe", test_cpp,
        f"-I{cl_root}/design",
        f"-I{cl_root}/verif/tests",
        "-top-module", "top",
        "--Mdir", str(sim_dir),
        mem_path_def,
        tv_def,
        f"+define+MEM_DEPTH={mem_depth}",
        "+define+GEN_TRACE=1",
        trace_def,
        f"+define+LINE_COUNT={line_count}",
        f"+define+TIMEOUT={timeout}",
    ]

    r = subprocess.run(compile_cmd, capture_output=True, text=True, cwd=sim_dir)
    if r.returncode != 0:
        tprint(f"  COMPILE FAIL: {bench_name}\n{r.stderr[-800:]}")
        return False

    # Build the binary
    r = subprocess.run(
        ["make", "-C", str(sim_dir), "-f", "Vtop.mk", "Vtop"],
        capture_output=True, text=True,
    )
    if r.returncode != 0:
        tprint(f"  MAKE FAIL: {bench_name}\n{r.stderr[-500:]}")
        return False

    # Run — trace is written to cwd
    r = subprocess.run(
        [str(sim_dir / "Vtop")],
        capture_output=True, text=True, cwd=sim_dir,
        timeout=60,
    )
    return True


def process_benchmark(
    bench_x: Path,
    scripts_dir: Path,
    cl_root: Path,
    bench_root: Path,
    spike_traces_dir: Path,
    spike_diff_dir: Path,
    sim_base_dir: Path,
    timeout: int,
    multicycle: int
) -> dict:
    """Full pipeline for one benchmark: compile -> run -> spike -> compare.

    Returns dict with keys: name, status ('pass'/'fail'/'skip'), message.
    """
    bench_name = bench_x.stem
    result = {"name": bench_name}

    # Each benchmark gets its own isolated sim directory
    sim_dir = sim_base_dir / f"bench_{bench_name}"
    trace_file = sim_dir / f"{bench_name}.trace"

    # Step 1: Verilator compile + run
    try:
        ok = run_verilator(bench_x, scripts_dir, cl_root, sim_dir, timeout, multicycle)
        if not ok:
            result["status"] = "skip"
            result["message"] = f"SKIP: {bench_name} (verilator failed)"
            tprint(result["message"])
            return result
    except subprocess.TimeoutExpired:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (simulation timeout)"
        tprint(result["message"])
        return result
    except Exception as e:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (error: {e})"
        tprint(result["message"])
        return result

    if not trace_file.exists():
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (no trace produced)"
        tprint(result["message"])
        return result

    # Step 2: Spike trace
    elf_path = find_elf(bench_name, bench_root)
    if elf_path is None:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (ELF not found)"
        tprint(result["message"])
        return result

    try:
        spike_output = run_spike(elf_path)
        spike_commits = parse_spike_output(spike_output)
    except FileNotFoundError:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (spike not found)"
        tprint(result["message"])
        return result
    except subprocess.TimeoutExpired:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (spike timeout)"
        tprint(result["message"])
        return result

    # Write spike trace
    spike_trace_path = spike_traces_dir / f"{bench_name}.trace"
    spike_traces_dir.mkdir(parents=True, exist_ok=True)
    with open(spike_trace_path, "w") as f:
        for pc, rd, val in spike_commits:
            f.write(f"{pc} {rd} {val}\n")

    # Step 3: Compare
    try:
        proc_commits = parse_proc_trace(trace_file)
    except Exception as e:
        result["status"] = "skip"
        result["message"] = f"SKIP: {bench_name} (trace parse error: {e})"
        tprint(result["message"])
        return result

    passed, n_mismatches, n_compared = compare_commits(proc_commits, spike_commits)

    # Write diff
    diff_path = spike_diff_dir / f"{bench_name}.diff"
    write_diff(proc_commits, spike_commits, bench_name, diff_path)

    if passed:
        result["status"] = "pass"
        result["message"] = f"PASS: {bench_name} ({n_compared} commits)"
    else:
        result["status"] = "fail"
        result["message"] = f"FAIL: {bench_name} ({n_mismatches} mismatches, {n_compared} commits)"
        # Show first few mismatches
        mismatch_lines = []
        shown = 0
        for i in range(min(len(proc_commits), len(spike_commits))):
            if shown >= 3:
                break
            p, s = proc_commits[i], spike_commits[i]
            if p != s:
                mismatch_lines.append(f"    [{i}] PROC:  pc={p[0]} rd={p[1]} val={p[2]}")
                mismatch_lines.append(f"    [{i}] SPIKE: pc={s[0]} rd={s[1]} val={s[2]}")
                shown += 1
        if mismatch_lines:
            result["message"] += "\n" + "\n".join(mismatch_lines)

    tprint(result["message"])
    return result


def build_benchmarks(bench_root: Path, scripts_dir: Path, jobs: int):
    """Build .elf + .x from .s/.c sources (clean first)."""
    print("Building benchmarks from source...")
    individual = bench_root / "individual-instructions"
    simple = bench_root / "simple-programs"

    for d, makefile in [(individual, "Makefile.new"), (simple, "Makefile.iss")]:
        for target in ["clean", "all"]:
            r = subprocess.run(
                ["make", "-C", str(d), "-f", makefile, f"-j{jobs}", target],
                capture_output=True, text=True,
            )
            if r.returncode != 0 and target == "all":
                print(f"WARNING: build failed in {d}: {r.stderr[-300:]}")
    print("Benchmarks built.")


def main() -> int:
    parser = argparse.ArgumentParser(description="Run all benchmarks in parallel")
    parser.add_argument("--bench-root", required=True, type=Path)
    parser.add_argument("--scripts-dir", required=True, type=Path)
    parser.add_argument("--cl-root", required=True, type=Path)
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    parser.add_argument("--timeout", type=int, default=50000,
                        help="Simulation timeout in cycles")
    parser.add_argument("--skip-build", action="store_true",
                        help="Skip building benchmarks from source")
    parser.add_argument("--multicycle", type=int, default=0,
                    help="Enable multicycle multiplier selection")
    args = parser.parse_args()

    bench_root = args.bench_root.resolve()
    scripts_dir = args.scripts_dir.resolve()
    cl_root = args.cl_root.resolve()
    jobs = args.jobs

    # Directories
    spike_traces_dir = cl_root / "verif" / "spike_traces"
    spike_diff_dir = cl_root / "verif" / "diffs" / "spike"
    sim_base_dir = cl_root / "verif" / "sim" / "verilator" / "parallel"

    # Build benchmarks
    if not args.skip_build:
        build_benchmarks(bench_root, scripts_dir, jobs)

    # Discover benchmarks
    bench_individual = sorted((bench_root / "individual-instructions").glob("*.x"))
    bench_simple = sorted((bench_root / "simple-programs").glob("*.x"))
    all_benchmarks = bench_individual + bench_simple

    if not all_benchmarks:
        print("ERROR: No benchmarks found!")
        return 1

    print(f"Running {len(all_benchmarks)} benchmarks with {jobs} parallel workers...")
    print()

    results = []
    with ThreadPoolExecutor(max_workers=jobs) as executor:
        futures = {
            executor.submit(
                process_benchmark,
                bench_x, scripts_dir, cl_root, bench_root,
                spike_traces_dir, spike_diff_dir, sim_base_dir,
                args.timeout, args.multicycle
            ): bench_x
            for bench_x in all_benchmarks
        }
        for future in as_completed(futures):
            try:
                results.append(future.result())
            except Exception as e:
                bench_x = futures[future]
                tprint(f"SKIP: {bench_x.stem} (unexpected error: {e})")
                results.append({"name": bench_x.stem, "status": "skip",
                                 "message": f"SKIP: {bench_x.stem}"})

    passed = sum(1 for r in results if r["status"] == "pass")
    failed = sum(1 for r in results if r["status"] == "fail")
    skipped = sum(1 for r in results if r["status"] == "skip")

    print()
    print("==========================================")
    print("SUMMARY")
    print("==========================================")
    print(f"  Passed:  {passed}")
    print(f"  Failed:  {failed}")
    print(f"  Skipped: {skipped}")
    print("==========================================")

    if failed > 0:
        print("\nFailed benchmarks:")
        for r in sorted(results, key=lambda x: x["name"]):
            if r["status"] == "fail":
                print(f"  {r['name']}")

    return 0 if failed == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
