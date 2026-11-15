#!/usr/bin/env python3
"""
Generate spike commit traces for RISC-V benchmarks.

Runs spike --log-commits on a benchmark ELF and writes a commit trace file.

OoO copy of verilog/verif/scripts/spike_trace_gen.py. Differences:
  * also searches rv32-benchmarks/ooo-tests/ and superscalar-tests/
  * also records committed stores (needed by cmp_ooo_spike.py)

Output format (one commit per line, program order):
  register write : <pc_hex> <rd_dec> <value_hex>        e.g. 01000000 1 00000000
  store          : S <pc_hex> <addr_hex> <size_bytes> <data_hex>
                                                         e.g. S 0100000c 01000230 1 000000aa
Register-write lines keep the scalar format, so older tools that only read
those lines still work if they skip lines starting with "S".

Usage:
    python3 spike_trace_gen.py --bench rv32ui-p-add --bench-root /path/to/rv32-benchmarks --out-dir /path/to/spike_traces
    python3 spike_trace_gen.py --bench SimpleAdd --bench-root /path/to/rv32-benchmarks --out-dir /path/to/spike_traces
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path


# Spike log-commits line pattern:
# core   0: 3 0x01000000 (0x00000093) x1  0x00000000
# core   0: 3 0x01000014 (0x4ddf1663)                  <- no reg write
# core   0: 3 0x0100000c (0x0182a283) x5  0x01000000 mem 0x00001018
SPIKE_LINE_RE = re.compile(
    r"core\s+\d+:\s+\d+\s+"      # "core   0: 3 "
    r"(0x[0-9a-fA-F]+)\s+"       # pc
    r"\([^)]+\)"                  # instruction encoding in parens
    r"(?:\s+x(\d+)\s+(0x[0-9a-fA-F]+))?"  # optional: reg write (x<rd> <value>)
    r"(?:\s+mem\s+(0x[0-9a-fA-F]+)(?:\s+(0x[0-9a-fA-F]+))?)?"  # optional: mem <addr> [<store data>]
)


def find_elf(bench: str, bench_root: Path) -> Path:
    """Find the ELF file for a benchmark.

    For individual-instructions: looks for <bench>.elf
    For simple-programs: looks for <bench>.iss.elf first, then <bench>.elf
    """
    individual = bench_root / "individual-instructions" / f"{bench}.elf"
    if individual.exists():
        return individual

    ooo = bench_root / "ooo-tests" / f"{bench}.elf"
    if ooo.exists():
        return ooo

    superscalar = bench_root / "superscalar-tests" / f"{bench}.elf"
    if superscalar.exists():
        return superscalar

    simple_iss = bench_root / "simple-programs" / f"{bench}.iss.elf"
    if simple_iss.exists():
        return simple_iss

    simple_elf = bench_root / "simple-programs" / f"{bench}.elf"
    if simple_elf.exists():
        return simple_elf

    raise FileNotFoundError(
        f"ELF not found for benchmark '{bench}'.\n"
        f"Searched:\n"
        f"  {individual}\n"
        f"  {ooo}\n"
        f"  {superscalar}\n"
        f"  {simple_iss}\n"
        f"  {simple_elf}"
    )


def run_spike(elf_path: Path) -> str:
    """Run spike --log-commits and return stdout+stderr combined output."""
    cmd = [
        "spike",
        "--log-commits",
        "--isa=rv32g",
        "-m0x01000000:0x200000",
        str(elf_path),
    ]
    result = subprocess.run(
        cmd,
        capture_output=True,
        text=True,
        timeout=120,
    )
    # spike --log-commits writes to stderr; stdout may have program output
    return result.stderr


def parse_spike_output(spike_output: str) -> list:
    """Parse spike --log-commits output.

    Returns a list in program order of:
      ("R", pc_hex, rd_num, value_hex)               register writes
      ("S", pc_hex, addr_hex, size_bytes, data_hex)  stores
    Skips:
    - Instructions with neither a register write nor a store
    - Writes to x0 (always 0, not meaningful)
    - Instructions from the boot ROM (pc < 0x01000000)
    """
    commits = []
    for line in spike_output.splitlines():
        m = SPIKE_LINE_RE.match(line)
        if not m:
            continue
        pc_str, rd_str, val_str = m.group(1), m.group(2), m.group(3)
        mem_addr, mem_data = m.group(4), m.group(5)

        if int(pc_str, 16) < 0x01000000:
            continue

        # Store: "mem <addr> <data>" with no register write. Spike prints the
        # data at the access width (0xaa = 1 byte, 0x00aa = 2, 8 digits = 4).
        if rd_str is None and mem_addr is not None and mem_data is not None:
            ndigits = len(mem_data) - 2
            size = max(1, ndigits // 2)
            commits.append((
                "S",
                pc_str[2:].lower().zfill(8),
                mem_addr[2:].lower().zfill(8),
                size,
                mem_data[2:].lower().zfill(8),
            ))
            continue

        # Skip instructions with no register write
        if rd_str is None:
            continue

        rd_num = int(rd_str)

        # Skip writes to x0
        if rd_num == 0:
            continue

        # Normalize pc: strip 0x prefix, lowercase, zero-pad to 8 digits
        pc_hex = pc_str[2:].lower().zfill(8)

        # Skip boot ROM instructions (pc < 0x01000000) - processor doesn't execute these
        if int(pc_hex, 16) < 0x01000000:
            continue

        # Normalize value: strip 0x prefix, lowercase, zero-pad to 8 digits
        val_hex = val_str[2:].lower().zfill(8)

        commits.append(("R", pc_hex, rd_num, val_hex))

    return commits


def write_spike_trace(commits: list, out_path: Path) -> None:
    """Write spike commit trace to file."""
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, "w") as f:
        for c in commits:
            if c[0] == "S":
                _, pc_hex, addr_hex, size, data_hex = c
                f.write(f"S {pc_hex} {addr_hex} {size} {data_hex}\n")
            else:
                _, pc_hex, rd_num, val_hex = c
                f.write(f"{pc_hex} {rd_num} {val_hex}\n")


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate spike commit trace for a benchmark"
    )
    parser.add_argument("--bench", required=True, help="Benchmark name (stem of .x file)")
    parser.add_argument(
        "--bench-root",
        required=True,
        type=Path,
        help="Root of rv32-benchmarks directory",
    )
    parser.add_argument(
        "--out-dir",
        required=True,
        type=Path,
        help="Output directory for spike trace files",
    )
    args = parser.parse_args()

    bench_root = args.bench_root.resolve()
    out_dir = args.out_dir.resolve()

    # Find ELF
    try:
        elf_path = find_elf(args.bench, bench_root)
    except FileNotFoundError as e:
        print(f"ERROR: {e}", file=sys.stderr)
        return 1

    print(f"  ELF: {elf_path}")

    # Run spike
    try:
        spike_output = run_spike(elf_path)
    except FileNotFoundError:
        print("ERROR: spike not found. Install with: sudo apt install spike", file=sys.stderr)
        return 1
    except subprocess.TimeoutExpired:
        print(f"ERROR: spike timed out for {args.bench}", file=sys.stderr)
        return 1

    # Parse output
    commits = parse_spike_output(spike_output)
    if not commits:
        print(f"WARNING: No committed register writes found for {args.bench}", file=sys.stderr)

    # Write trace
    out_path = out_dir / f"{args.bench}.trace"
    write_spike_trace(commits, out_path)
    print(f"  Wrote {len(commits)} commits -> {out_path}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
