#!/usr/bin/env python3
"""
Convert .d disassembly files to .s assembly files for recompilation.
Extracts just the instructions, preserving labels and removing comments/addresses.
"""

import sys
import re

def convert_d_to_s(input_file, output_file):
    """Convert disassembly (.d) to assembly (.s)

    Automatically patches pass/fail sections to write to tohost before ecall.
    This makes tests compatible with both Spike (HTIF exit) and processor (timeout).
    """
    with open(input_file, 'r') as f:
        lines = f.readlines()

    asm_lines = []
    in_text_section = False
    in_data_section = False
    pending_ecall_patch = None  # Track if we need to inject HTIF write before next ecall

    for line in lines:
        line = line.rstrip()

        # Skip empty lines and file format lines (but not section headers)
        if not line or 'file format' in line:
            continue

        # Skip non-section disassembly headers
        if 'Disassembly of section' not in line and 'Disassembly' in line:
            continue

        # Skip objdump error messages
        if 'out of bounds' in line or 'Address 0x' in line:
            continue

        # Detect .text section start
        if 'Disassembly of section .text' in line:
            in_text_section = True
            in_data_section = False
            asm_lines.append('.section .text.init')
            asm_lines.append('.globl _start')
            continue

        # Detect .data section start
        if 'Disassembly of section .data' in line:
            in_text_section = False
            in_data_section = True
            # Add proper alignment to match original binary layout
            # The HTIF patches add extra instructions, so we need padding
            asm_lines.append('\n.section .data')
            asm_lines.append('.align 4')  # Align to 16-byte boundary
            continue

        # Process .text section
        if in_text_section:
            # Label lines (start at column 0, end with :)
            if line and line[0].isdigit() and '<' in line and '>' in line:
                # Extract label from format: "01000000 <_start>:"
                match = re.search(r'<(.+)>:', line)
                if match:
                    label = match.group(1)
                    asm_lines.append(f'\n{label}:')
                    # Track pass/fail labels to inject HTIF writes before ecall
                    if label in ['pass', 'fail']:
                        pending_ecall_patch = label
                continue

            # Instruction lines (have address and hex encoding)
            # Format: " 1000000:	00000093          	addi	x1,x0,0"
            if re.match(r'\s+[0-9a-f]+:\s+[0-9a-f]+\s+', line):
                # Extract instruction (everything after the hex encoding)
                parts = line.split('\t')
                if len(parts) >= 3:
                    # Parts: [' address:', 'hex', 'mnemonic', 'operands']
                    mnemonic = parts[2].strip()
                    operands = parts[3].strip() if len(parts) > 3 else ''
                    # Remove any trailing comments (starting with #)
                    operands = re.sub(r'\s*#.*$', '', operands)
                    # Fix branch targets: "addr <label>" -> "label"
                    # e.g., "x30,x29,10004e0 <fail>" -> "x30,x29,fail"
                    operands = re.sub(r'[0-9a-f]+\s*<([^>]+)>', r'\1', operands)
                    # Skip compressed instructions (c.* - we don't support RV32C)
                    if mnemonic.startswith('c.'):
                        continue

                    # Inject HTIF write before ecall in pass/fail sections
                    if mnemonic == 'ecall' and pending_ecall_patch:
                        # Write gp (x3) value to tohost before ecall
                        asm_lines.append('    # HTIF: Write test result to tohost for Spike compatibility')
                        asm_lines.append('    la      t0,tohost')
                        asm_lines.append('    sw      x3,0(t0)')
                        pending_ecall_patch = None

                    instruction = f'{mnemonic}\t{operands}' if operands else mnemonic
                    asm_lines.append(f'    {instruction}')

        # Process .data section
        elif in_data_section:
            # Data labels: "01000284 <tdat>:"
            if line and line[0].isdigit() and '<' in line and '>' in line:
                match = re.search(r'<(.+)>:', line)
                if match:
                    label = match.group(1)
                    asm_lines.append(f'\n{label}:')
                continue

            # Data lines: extract hex bytes from the encoding column
            # Format: " 10002c4:	00ff                	0xff"
            if re.match(r'\s+[0-9a-f]+:\s+[0-9a-f]+', line):
                parts = line.split('\t')
                if len(parts) >= 2:
                    # Extract hex bytes (second column)
                    hex_bytes = parts[1].strip()
                    # Convert to .byte directive (little-endian byte order)
                    # Objdump shows bytes in little-endian order, but we need to reverse
                    # for proper byte-by-byte storage. E.g., "00ff" at address N means:
                    # - Address N+0: 0xff
                    # - Address N+1: 0x00
                    bytes_list = []
                    for i in range(len(hex_bytes)-2, -1, -2):  # Reverse order
                        if i >= 0:
                            bytes_list.append(f'0x{hex_bytes[i:i+2]}')
                    if bytes_list:
                        asm_lines.append(f'    .byte {", ".join(bytes_list)}')

    # Write output
    with open(output_file, 'w') as f:
        for line in asm_lines:
            f.write(line + '\n')

    print(f"Converted {input_file} -> {output_file}")

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: d_to_s.py <input.d> <output.s>")
        sys.exit(1)

    convert_d_to_s(sys.argv[1], sys.argv[2])
