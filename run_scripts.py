#!/usr/bin/env python3
"""
Run RISC-V instruction tests and generate diff reports.

This script processes rv32ui-p-*.x MEM files from the benchmarks directory,
runs simulations, compares golden and simulated trace files, and generates
annotated diff reports.
"""

import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path
from threading import Lock
from typing import List, Optional, Tuple


@dataclass
class Config:
    """Configuration for the test runner."""

    mem_dir: Path
    scripts_dir: Path
    golden_dir: Path
    sim_trace_dir: Path
    out_dir: Path
    max_workers: int = os.cpu_count() or 4


class OpcodeMapper:
    """Maps hex opcodes to human-readable instruction types."""

    OPCODE_MAP = {
        "63": "B",  # Branch
        "33": "R",  # R-type
        "13": "I",  # I-type
        "03": "L",  # Load
        "23": "S",  # Store
        "6f": "JAL",  # JAL
        "67": "JALR",  # JALR
        "37": "LUI",  # LUI
        "17": "AUIPC",  # AUIPC
        "73": "ECALL",  # ECALL
    }

    @classmethod
    def map_opcode(cls, hex_opcode: str) -> str:
        """Map hex opcode to instruction type."""
        return cls.OPCODE_MAP.get(hex_opcode, hex_opcode)


class TraceAnnotator:
    """Annotates trace files with labeled fields."""

    @staticmethod
    def annotate_line(line: str) -> str:
        """Annotate a single trace line with field labels."""
        # Extract prefix (before [X])
        match = re.match(r"^(.*?)(\[\w\])\s*(.*)", line)
        if not match:
            return line

        prefix, tag, rest = match.groups()
        fields = rest.split()

        if tag == "[D]":
            # Decode stage
            if len(fields) >= 9:
                opcode = OpcodeMapper.map_opcode(fields[1])
                return (
                    f"{prefix}{tag} pc_addr:{fields[0]} opcode:{opcode} "
                    f"rd:{fields[2]} rs1:{fields[3]} rs2:{fields[4]} "
                    f"funct3:{fields[5]} funct7:{fields[6]} imm:{fields[7]} "
                    f"shamt:{fields[8]}\n"
                )

        elif tag == "[F]":
            # Fetch stage
            if len(fields) >= 2:
                return f"{prefix}{tag} pc_addr:{fields[0]} content:{fields[1]}\n"

        elif tag == "[R]":
            # Register read stage
            if len(fields) >= 4:
                return (
                    f"{prefix}{tag} addr_rs1:{fields[0]} addr_rs2:{fields[1]} "
                    f"data_rs1:{fields[2]} data_rs2:{fields[3]}\n"
                )

        elif tag == "[E]":
            # Execute stage
            if len(fields) >= 3:
                return (
                    f"{prefix}{tag} pc_addr:{fields[0]} alu_result:{fields[1]} "
                    f"branch_taken:{fields[2]}\n"
                )

        elif tag == "[M]":
            # Memory stage
            if len(fields) >= 5:
                return (
                    f"{prefix}{tag} pc_addr:{fields[0]} mem_addr:{fields[1]} "
                    f"read_write:{fields[2]} access_size:{fields[3]} "
                    f"mem_data_in:{fields[4]}\n"
                )

        elif tag == "[W]":
            # Writeback stage
            if len(fields) >= 4:
                return (
                    f"{prefix}{tag} pc_addr:{fields[0]} write_enable:{fields[1]} "
                    f"write_rd:{fields[2]} data_rd:{fields[3]}\n"
                )

        return line

    @classmethod
    def annotate_file(cls, input_path: Path, output_path: Path) -> None:
        """Annotate an entire trace file."""
        with open(input_path, "r") as infile, open(output_path, "w") as outfile:
            for line in infile:
                annotated = cls.annotate_line(line)
                outfile.write(annotated)


class DiffFilter:
    """Filters diff output to remove irrelevant differences."""

    @staticmethod
    def extract_opcode(line: str) -> Optional[str]:
        """Extract opcode from a [D] stage line."""
        match = re.search(r"opcode:(\S+)", line)
        return match.group(1) if match else None

    @staticmethod
    def is_memory_read_diff(golden_line: str, actual_line: str) -> bool:
        """
        Check if the diff is a [M] stage with read_write=0 and only mem_data_in differs.
        Returns True if this is a memory read with different mem_data_in (should be filtered).
        """
        if "[M]" not in golden_line or "[M]" not in actual_line:
            return False

        # Check for GOLDEN and ACTUAL markers
        if "(GOLDEN):" not in golden_line or "(ACTUAL):" not in actual_line:
            return False

        # Extract all [M] fields from both lines
        # Fields: pc_addr, mem_addr, read_write, access_size, mem_data_in
        golden_match = re.search(
            r"\[M\]\s+pc_addr:(\S+)\s+mem_addr:(\S+)\s+read_write:(\S+)\s+access_size:(\S+)\s+mem_data_in:(\S+)",
            golden_line,
        )
        actual_match = re.search(
            r"\[M\]\s+pc_addr:(\S+)\s+mem_addr:(\S+)\s+read_write:(\S+)\s+access_size:(\S+)\s+mem_data_in:(\S+)",
            actual_line,
        )

        if not golden_match or not actual_match:
            return False

        golden_pc, golden_addr, golden_rw, golden_size, golden_data = (
            golden_match.groups()
        )
        actual_pc, actual_addr, actual_rw, actual_size, actual_data = (
            actual_match.groups()
        )

        # Check if both are reads (read_write=0)
        if golden_rw != "0" or actual_rw != "0":
            return False

        # If pc_addr, mem_addr, read_write, and access_size all match,
        # and only mem_data_in differs, this is a read operation diff we want to filter
        return (
            golden_pc == actual_pc
            and golden_addr == actual_addr
            and golden_size == actual_size
            and golden_data != actual_data
        )

    @staticmethod
    def is_i_format_rs2_only_diff(
        golden_d: str, golden_r: str, actual_d: str, actual_r: str
    ) -> bool:
        """
        Check if this is an I-format instruction where only rs2 fields differ.
        I-format instructions don't use rs2, so differences in rs2 should be ignored.

        Returns True if this is an I-format instruction with only rs2 differences.
        """
        # Verify all lines have correct markers
        if (
            "(GOLDEN):" not in golden_d
            or "(GOLDEN):" not in golden_r
            or "(ACTUAL):" not in actual_d
            or "(ACTUAL):" not in actual_r
        ):
            return False

        # Verify correct stages
        if "[D]" not in golden_d or "[D]" not in actual_d:
            return False
        if "[R]" not in golden_r or "[R]" not in actual_r:
            return False

        # Check if it's an I-format instruction (includes I, L, JALR)
        if (
            "opcode:I" not in golden_d
            and "opcode:L" not in golden_d
            and "opcode:JALR" not in golden_d
        ):
            return False

        # Extract [D] fields: pc_addr, opcode, rd, rs1, rs2, funct3, funct7, imm, shamt
        golden_d_match = re.search(
            r"\[D\]\s+pc_addr:(\S+)\s+opcode:(\S+)\s+rd:(\S+)\s+rs1:(\S+)\s+rs2:(\S+)\s+funct3:(\S+)\s+funct7:(\S+)\s+imm:(\S+)\s+shamt:(\S+)",
            golden_d,
        )
        actual_d_match = re.search(
            r"\[D\]\s+pc_addr:(\S+)\s+opcode:(\S+)\s+rd:(\S+)\s+rs1:(\S+)\s+rs2:(\S+)\s+funct3:(\S+)\s+funct7:(\S+)\s+imm:(\S+)\s+shamt:(\S+)",
            actual_d,
        )

        if not golden_d_match or not actual_d_match:
            return False

        (
            g_pc,
            g_opcode,
            g_rd,
            g_rs1,
            g_rs2,
            g_funct3,
            g_funct7,
            g_imm,
            g_shamt,
        ) = golden_d_match.groups()
        (
            a_pc,
            a_opcode,
            a_rd,
            a_rs1,
            a_rs2,
            a_funct3,
            a_funct7,
            a_imm,
            a_shamt,
        ) = actual_d_match.groups()

        # Check if all fields match except rs2
        if not (
            g_pc == a_pc
            and g_opcode == a_opcode
            and g_rd == a_rd
            and g_rs1 == a_rs1
            and g_funct3 == a_funct3
            and g_funct7 == a_funct7
            and g_imm == a_imm
            and g_shamt == a_shamt
        ):
            return False

        # Extract [R] fields: addr_rs1, addr_rs2, data_rs1, data_rs2
        golden_r_match = re.search(
            r"\[R\]\s+addr_rs1:(\S+)\s+addr_rs2:(\S+)\s+data_rs1:(\S+)\s+data_rs2:(\S+)",
            golden_r,
        )
        actual_r_match = re.search(
            r"\[R\]\s+addr_rs1:(\S+)\s+addr_rs2:(\S+)\s+data_rs1:(\S+)\s+data_rs2:(\S+)",
            actual_r,
        )

        if not golden_r_match or not actual_r_match:
            return False

        g_addr_rs1, g_addr_rs2, g_data_rs1, g_data_rs2 = golden_r_match.groups()
        a_addr_rs1, a_addr_rs2, a_data_rs1, a_data_rs2 = actual_r_match.groups()

        # Check if rs1 fields match and only rs2 fields differ
        return g_addr_rs1 == a_addr_rs1 and g_data_rs1 == a_data_rs1

    @staticmethod
    def is_sb_format_rd_only_diff(golden_d: str, actual_d: str) -> bool:
        """
        Check if this is an S-type or B-type instruction where only rd field differs.
        S-type and B-type instructions don't use rd, so differences in rd should be ignored.

        Returns True if this is an S/B-type instruction with only rd differences.
        """
        # Verify markers
        if "(GOLDEN):" not in golden_d or "(ACTUAL):" not in actual_d:
            return False

        # Verify correct stage
        if "[D]" not in golden_d or "[D]" not in actual_d:
            return False

        # Check if it's an S-type or B-type instruction
        if "opcode:S" not in golden_d and "opcode:B" not in golden_d:
            return False

        # Extract [D] fields: pc_addr, opcode, rd, rs1, rs2, funct3, funct7, imm, shamt
        golden_d_match = re.search(
            r"\[D\]\s+pc_addr:(\S+)\s+opcode:(\S+)\s+rd:(\S+)\s+rs1:(\S+)\s+rs2:(\S+)\s+funct3:(\S+)\s+funct7:(\S+)\s+imm:(\S+)\s+shamt:(\S+)",
            golden_d,
        )
        actual_d_match = re.search(
            r"\[D\]\s+pc_addr:(\S+)\s+opcode:(\S+)\s+rd:(\S+)\s+rs1:(\S+)\s+rs2:(\S+)\s+funct3:(\S+)\s+funct7:(\S+)\s+imm:(\S+)\s+shamt:(\S+)",
            actual_d,
        )

        if not golden_d_match or not actual_d_match:
            return False

        (
            g_pc,
            g_opcode,
            g_rd,
            g_rs1,
            g_rs2,
            g_funct3,
            g_funct7,
            g_imm,
            g_shamt,
        ) = golden_d_match.groups()
        (
            a_pc,
            a_opcode,
            a_rd,
            a_rs1,
            a_rs2,
            a_funct3,
            a_funct7,
            a_imm,
            a_shamt,
        ) = actual_d_match.groups()

        # Check if all fields match except rd
        return (
            g_pc == a_pc
            and g_opcode == a_opcode
            and g_rs1 == a_rs1
            and g_rs2 == a_rs2
            and g_funct3 == a_funct3
            and g_funct7 == a_funct7
            and g_imm == a_imm
            and g_shamt == a_shamt
        )

    @classmethod
    def filter_diff_lines_extreme(cls, lines: List[str]) -> List[str]:
        """
        Extreme filtering: Only keep lines that:
        1. Contain [W] (writeback stage)
        2. Contain write_enable:1
        3. Do NOT contain write_rd:00

        This focuses exclusively on meaningful writeback differences.
        """
        result = []
        for line in lines:
            # Keep header lines (first 4-5 lines before actual diffs)
            if not line.strip():
                result.append(line)
                continue
            if line.startswith("GOLDEN:") or line.startswith("ACTUAL:") or line.startswith("NOTE:"):
                result.append(line)
                continue

            # For diff content lines, only keep [W] lines with meaningful writes
            if "[W]" in line and "write_enable:1" in line and not "write_rd:00" in line:
                result.append(line)

        return result

    @classmethod
    def filter_diff_lines(cls, lines: List[str]) -> List[str]:
        """
        Filter diff lines to remove:
        1. LUI [D]/[R] diff patterns (4 lines)
        2. I-format [D]/[R] diff patterns where only rs2 differs (4 lines)
        3. S/B-format [D] diff patterns where only rd differs (2 lines)
        4. [M] diffs for non-load/store instructions (2 lines)
        5. [M] diffs where read_write=0 and only mem_data_in differs (2 lines)
        """
        # Find where the header ends (include NOTE: line and blank lines)
        header_end = 0
        found_blank = False
        found_note = False

        for i, line in enumerate(lines):
            if line.strip() == "" and not found_blank:
                # First blank line
                found_blank = True
                continue
            if found_blank and line.startswith("NOTE:"):
                # NOTE line after blank
                found_note = True
                header_end = i + 1
                continue
            if found_note and line.strip() == "":
                # Blank line after NOTE - include it in header
                header_end = i + 1
                break
            if found_blank and not found_note and line.strip() != "":
                # No NOTE, first non-blank after blank is where content starts
                header_end = i
                break

        # Default fallback if no blank/NOTE pattern found
        if header_end == 0:
            for i, line in enumerate(lines):
                if "line " in line and ("(GOLDEN):" in line or "(ACTUAL):" in line):
                    header_end = i
                    break

        if len(lines) <= header_end:
            return lines

        result = lines[:header_end]  # Keep header
        buffer: List[str] = []
        buffer_opcodes: List[Optional[str]] = []
        last_opcode: Optional[str] = None

        for line in lines[header_end:]:
            # Track opcode from [D] lines
            if "[D]" in line and "opcode:" in line:
                last_opcode = cls.extract_opcode(line)

            # Add to buffer
            buffer.append(line)
            buffer_opcodes.append(last_opcode)

            # Check 4-line patterns first (LUI and I-format rs2)
            if len(buffer) >= 4:
                # Pattern 1: LUI [D]/[R] pattern (4 lines)
                if (
                    buffer[0].find("(GOLDEN):") != -1
                    and "[D]" in buffer[0]
                    and "opcode:LUI" in buffer[0]
                    and buffer[1].find("(GOLDEN):") != -1
                    and "[R]" in buffer[1]
                    and buffer[2].find("(ACTUAL):") != -1
                    and "[D]" in buffer[2]
                    and "opcode:LUI" in buffer[2]
                    and buffer[3].find("(ACTUAL):") != -1
                    and "[R]" in buffer[3]
                ):
                    # Skip all 4 lines (disabled since FDXMW format changed)
                    # buffer.clear()
                    # buffer_opcodes.clear()
                    continue

                # Pattern 2: I-format [D]/[R] pattern where only rs2 differs (4 lines)
                if (
                    buffer[0].find("(GOLDEN):") != -1
                    and "[D]" in buffer[0]
                    and buffer[1].find("(GOLDEN):") != -1
                    and "[R]" in buffer[1]
                    and buffer[2].find("(ACTUAL):") != -1
                    and "[D]" in buffer[2]
                    and buffer[3].find("(ACTUAL):") != -1
                    and "[R]" in buffer[3]
                    and cls.is_i_format_rs2_only_diff(
                        buffer[0], buffer[1], buffer[2], buffer[3]
                    )
                ):
                    # Skip all 4 lines
                    buffer.clear()
                    buffer_opcodes.clear()
                    continue

            # Check 2-line patterns
            if len(buffer) >= 2:
                # Pattern 3: S/B-format [D] pattern where only rd differs (2 lines)
                if (
                    "(GOLDEN):" in buffer[0]
                    and "[D]" in buffer[0]
                    and "(ACTUAL):" in buffer[1]
                    and "[D]" in buffer[1]
                    and cls.is_sb_format_rd_only_diff(buffer[0], buffer[1])
                ):
                    # Skip first 2 lines, keep rest in buffer
                    buffer = buffer[2:]
                    buffer_opcodes = buffer_opcodes[2:]
                    continue

                # Pattern 4: [M] diffs for non-L/S instructions (2 lines at positions 0-1)
                if (
                    "(GOLDEN):" in buffer[0]
                    and "[M]" in buffer[0]
                    and "(ACTUAL):" in buffer[1]
                    and "[M]" in buffer[1]
                    and buffer_opcodes[0] not in ("L", "S")
                ):
                    # Skip first 2 lines, keep rest in buffer
                    buffer = buffer[2:]
                    buffer_opcodes = buffer_opcodes[2:]
                    continue

                # Pattern 5: [M] diffs for memory reads (read_write=0) with different mem_data_in
                if (
                    "(GOLDEN):" in buffer[0]
                    and "[M]" in buffer[0]
                    and "(ACTUAL):" in buffer[1]
                    and "[M]" in buffer[1]
                    and cls.is_memory_read_diff(buffer[0], buffer[1])
                ):
                    # Skip first 2 lines, keep rest in buffer
                    buffer = buffer[2:]
                    buffer_opcodes = buffer_opcodes[2:]
                    continue

            # No pattern matched, output first line if buffer is getting full
            if len(buffer) >= 4:
                result.append(buffer[0])
                buffer = buffer[1:]
                buffer_opcodes = buffer_opcodes[1:]

        # Output remaining buffer
        result.extend(buffer)

        return result


class InstructionTester:
    """Tests a single instruction and generates diff report."""

    def __init__(self, config: Config, make_lock: Lock):
        self.config = config
        self.make_lock = make_lock

    def run_simulation(self, mem_path: Path) -> bool:
        """Run simulation for a given MEM file."""
        try:
            # Source env.sh and run make in a bash subshell
            # We need to source env.sh to set up PROJECT_ROOT, VERILATOR_ROOT, etc.
            env_script = self.config.scripts_dir.parent.parent / "env.sh"
            command = f'source "{env_script}" -L 2>&1 > /dev/null && make -s run MEM_PATH="{mem_path}"'

            # Use lock to serialize make commands (avoid race conditions with shared build artifacts)
            with self.make_lock:
                result = subprocess.run(
                    command,
                    cwd=self.config.scripts_dir,
                    shell=True,
                    executable="/bin/bash",
                    capture_output=True,
                    text=True,
                    timeout=300,
                )

                # Check if simulation completed (look for trace file or $finish in output)
                # Return code might be non-zero even on success due to Verilator's $finish
                trace_file = (
                    self.config.sim_trace_dir
                    / f"rv32ui-p-{mem_path.stem.replace('rv32ui-p-', '')}.trace"
                )
                if trace_file.exists():
                    return True

                # Fall back to checking return code and output
                if (
                    result.returncode == 0
                    or "$finish" in result.stdout
                    or "$finish" in result.stderr
                ):
                    return True

            return False
        except (subprocess.TimeoutExpired, subprocess.SubprocessError) as e:
            print(f"WARNING: make failed for {mem_path.name}: {e}", file=sys.stderr)
            return False

    def generate_diff(self, golden_path: Path, sim_path: Path) -> List[str]:
        """Generate diff between golden and simulated traces."""
        try:
            # First, check line counts to handle mismatched file lengths
            with open(golden_path, "r") as f:
                golden_line_count = sum(1 for _ in f)
            with open(sim_path, "r") as f:
                sim_line_count = sum(1 for _ in f)

            # Add header
            header = [
                f"GOLDEN: {golden_path}\n",
                f"ACTUAL: {sim_path}\n",
                f"GOLDEN lines: {golden_line_count}, ACTUAL lines: {sim_line_count}\n",
                "\n",
            ]

            # If line counts differ significantly, create truncated temp files
            if golden_line_count != sim_line_count:
                min_lines = min(golden_line_count, sim_line_count)

                # Create temporary truncated files for diff
                with tempfile.NamedTemporaryFile(
                    mode="w", delete=False, suffix=".trace"
                ) as golden_temp:
                    golden_temp_path = Path(golden_temp.name)
                    with open(golden_path, "r") as f:
                        for i, line in enumerate(f):
                            if i >= min_lines:
                                break
                            golden_temp.write(line)

                with tempfile.NamedTemporaryFile(
                    mode="w", delete=False, suffix=".trace"
                ) as sim_temp:
                    sim_temp_path = Path(sim_temp.name)
                    with open(sim_path, "r") as f:
                        for i, line in enumerate(f):
                            if i >= min_lines:
                                break
                            sim_temp.write(line)

                # Run diff on truncated files
                result = subprocess.run(
                    [
                        "diff",
                        "--unchanged-line-format=",
                        "--old-line-format=line %dn (GOLDEN): %L",
                        "--new-line-format=line %dn (ACTUAL): %L",
                        str(golden_temp_path),
                        str(sim_temp_path),
                    ],
                    capture_output=True,
                    text=True,
                )

                # Clean up temp files
                golden_temp_path.unlink()
                sim_temp_path.unlink()

                # Add note about truncation
                extra_lines = abs(golden_line_count - sim_line_count)
                if golden_line_count > sim_line_count:
                    header.append(
                        f"NOTE: GOLDEN has {extra_lines} extra lines after line {min_lines} (not shown in diff)\n\n"
                    )
                else:
                    header.append(
                        f"NOTE: ACTUAL has {extra_lines} extra lines after line {min_lines} (not shown in diff)\n\n"
                    )

            else:
                # Files have same length, run normal diff
                result = subprocess.run(
                    [
                        "diff",
                        "--unchanged-line-format=",
                        "--old-line-format=line %dn (GOLDEN): %L",
                        "--new-line-format=line %dn (ACTUAL): %L",
                        str(golden_path),
                        str(sim_path),
                    ],
                    capture_output=True,
                    text=True,
                )

            # diff returns 1 when files differ (not an error)
            output_lines = result.stdout.split("\n")

            # Convert output to proper line format (add newlines)
            diff_lines = []
            for line in output_lines:
                if line:
                    # Ensure line ends with newline if it doesn't already
                    if not line.endswith("\n"):
                        line += "\n"
                    diff_lines.append(line)

            return header + diff_lines

        except subprocess.SubprocessError as e:
            print(f"ERROR: diff failed: {e}", file=sys.stderr)
            return []

    def process_instruction(
        self,
        mem_path: Path,
        instr_name: str,
        count: int,
        category: str = "instructions",
    ) -> Tuple[str, bool]:
        """
        Process a single instruction test.

        Args:
            mem_path: Path to the MEM file
            instr_name: Name of the instruction/program
            count: Test number
            category: Either 'instructions' or 'programs'

        Returns:
            Tuple of (instruction_name, success)
        """
        print(f"=== [{count}] Processing {category}: {instr_name} ===")
        print(f" MEM file: {mem_path}")

        # Run simulation
        sim_success = self.run_simulation(mem_path)
        if not sim_success:
            print(
                f"WARNING: make failed for {instr_name}. Continuing to diff if traces exist.",
                file=sys.stderr,
            )

        # Paths for traces and output - handle both rv32ui-p- prefix and plain names
        if category == "instructions":
            trace_gold = self.config.golden_dir / f"rv32ui-p-{instr_name}.trace"
            trace_sim = self.config.sim_trace_dir / f"rv32ui-p-{instr_name}.trace"
        else:
            trace_gold = self.config.golden_dir / f"{instr_name}.trace"
            trace_sim = self.config.sim_trace_dir / f"{instr_name}.trace"

        outfile = self.config.out_dir / f"{instr_name}.txt"

        # Check if traces exist
        if not trace_gold.exists():
            print(f"Missing golden trace: {trace_gold}", file=sys.stderr)
            outfile.write_text(f"MISSING_GOLD: {trace_gold}\n")
            return instr_name, False

        if not trace_sim.exists():
            print(f"Missing sim trace: {trace_sim}", file=sys.stderr)
            outfile.write_text(f"MISSING_SIM: {trace_sim}\n")
            return instr_name, False

        # STEP 1: Create annotated versions of BOTH traces
        trace_gold_annotated = (
            trace_gold.with_suffix(".trace").parent
            / f"{trace_gold.stem}-annotated.trace"
        )
        trace_sim_annotated = (
            trace_sim.with_suffix(".trace").parent / f"{trace_sim.stem}-annotated.trace"
        )

        # Annotate both golden and sim traces
        TraceAnnotator.annotate_file(trace_gold, trace_gold_annotated)
        TraceAnnotator.annotate_file(trace_sim, trace_sim_annotated)
        print(
            f" Created annotated traces: {trace_gold_annotated.name}, {trace_sim_annotated.name}"
        )

        # STEP 2: Generate diff from annotated traces (transparency - no filtering yet)
        diff_lines = self.generate_diff(trace_gold_annotated, trace_sim_annotated)

        # Immediately save the unfiltered diff for transparency
        outfile_original = self.config.out_dir / f"{instr_name}-diff.txt"
        outfile_original.write_text("".join(diff_lines))
        print(f" Saved unfiltered diff -> {outfile_original}")

        # STEP 3: Apply standard filtering to a COPY of the diff data
        filtered_lines = DiffFilter.filter_diff_lines(diff_lines.copy())

        # Write standard filtered diff
        outfile_filtered = self.config.out_dir / f"{instr_name}-diff-filtered.txt"

        # Check if there are actual diff lines beyond the header in filtered output
        # Header is now 4-5 lines (GOLDEN, ACTUAL, line counts, blank, optional NOTE)
        has_diffs = False
        for line in filtered_lines[4:]:  # Skip first 4 header lines
            if line.strip() and not line.startswith("NOTE:"):
                has_diffs = True
                break

        if has_diffs:
            # Found differences after filtering - write filtered version
            outfile_filtered.write_text("".join(filtered_lines))
            print(f" Filtered diff saved -> {outfile_filtered}")
        else:
            # No differences after filtering
            outfile_filtered.write_text("No differences detected after filtering\n")
            print(f" No differences after filtering -> {outfile_filtered}")

        # STEP 4: Apply extreme filtering (writeback-only) to original diff
        extreme_filtered_lines = DiffFilter.filter_diff_lines_extreme(diff_lines.copy())

        # Write extreme filtered diff (writeback-only)
        outfile_extreme = self.config.out_dir / f"{instr_name}-diff-filtered-wb-only.txt"

        # Check if there are actual diff lines in extreme filtered output
        has_wb_diffs = False
        for line in extreme_filtered_lines:
            if "[W]" in line:
                has_wb_diffs = True
                break

        if has_wb_diffs:
            outfile_extreme.write_text("".join(extreme_filtered_lines))
            print(f" Writeback-only diff saved -> {outfile_extreme}")
        else:
            outfile_extreme.write_text("No writeback differences detected\n")
            print(f" No writeback differences -> {outfile_extreme}")

        return instr_name, True


def find_mem_files(mem_dirs: List[Path]) -> List[Tuple[Path, str]]:
    """Find all .x MEM files in the specified directories.

    Returns:
        List of tuples (mem_file_path, category) where category is 'instructions' or 'programs'
    """
    all_mem_files = []

    for mem_dir in mem_dirs:
        if not mem_dir.exists():
            print(f"WARNING: Directory not found: {mem_dir}", file=sys.stderr)
            continue

        # Determine category based on directory name
        category = "programs" if "simple-programs" in str(mem_dir) else "instructions"

        # Find all .x files
        mem_files = sorted(mem_dir.glob("*.x"))

        for mem_file in mem_files:
            all_mem_files.append((mem_file, category))

    if not all_mem_files:
        print(f"ERROR: No .x MEM files found in any directory", file=sys.stderr)
        sys.exit(1)

    return all_mem_files


def main() -> None:
    """Main entry point for the test runner."""
    # Configuration
    base_dir = Path(__file__).parent
    # benchmarks_base = Path("/home/mdvmlhtr/ece320/e3mehta-pd5/rv32-benchmarks")
    benchmarks_base = Path("/home/e3mehta/ece320/rv32-benchmarks")

    config = Config(
        mem_dir=benchmarks_base
        / "individual-instructions",  # Still used for compatibility
        scripts_dir=base_dir / "verif" / "scripts",
        golden_dir=base_dir / "verif" / "golden_sim",
        sim_trace_dir=base_dir / "verif" / "sim" / "verilator" / "test_pd",
        out_dir=base_dir / "verif" / "sim" / "diff",
        max_workers=os.cpu_count() or 4,
    )

    # Define both directories to search
    mem_dirs = [
        benchmarks_base / "individual-instructions",
        benchmarks_base / "simple-programs",
    ]

    # Sanity checks - at least one directory should exist
    existing_dirs = [d for d in mem_dirs if d.exists()]
    if not existing_dirs:
        print(f"ERROR: No benchmark directories found:", file=sys.stderr)
        for d in mem_dirs:
            print(f"  {d}", file=sys.stderr)
        sys.exit(1)

    if not config.scripts_dir.exists():
        print(f"ERROR: scripts dir not found: {config.scripts_dir}", file=sys.stderr)
        sys.exit(1)

    # Check env.sh exists
    env_script = base_dir / "env.sh"
    if not env_script.exists():
        print(f"ERROR: env.sh not found: {env_script}", file=sys.stderr)
        print(
            "NOTE: Each simulation will source env.sh to set up the environment",
            file=sys.stderr,
        )
        sys.exit(1)

    # Ensure output directory exists
    config.out_dir.mkdir(parents=True, exist_ok=True)

    # Find all MEM files from both directories
    mem_files = find_mem_files(mem_dirs)
    print(f"Found {len(mem_files)} test(s) to process")
    print(f"NOTE: Each simulation will source env.sh before running make")

    # Create lock for serializing make commands and create tester
    make_lock = Lock()
    tester = InstructionTester(config, make_lock)

    # Process instructions in parallel
    with ThreadPoolExecutor(max_workers=config.max_workers) as executor:
        futures = []
        for count, (mem_path, category) in enumerate(mem_files, start=1):
            # Extract name - remove rv32ui-p- prefix if present
            instr_name = mem_path.stem
            if instr_name.startswith("rv32ui-p-"):
                instr_name = instr_name.replace("rv32ui-p-", "")

            # Submit task
            future = executor.submit(
                tester.process_instruction, mem_path, instr_name, count, category
            )
            futures.append(future)

        # Wait for all tasks to complete
        success_count = 0
        for future in as_completed(futures):
            try:
                instr_name, success = future.result()
                if success:
                    success_count += 1
            except Exception as e:
                print(f"ERROR: Task failed with exception: {e}", file=sys.stderr)

    print(f"\nDone. Processed {len(mem_files)} instruction(s).")
    print(f"Successfully processed: {success_count}/{len(mem_files)}")


if __name__ == "__main__":
    main()
