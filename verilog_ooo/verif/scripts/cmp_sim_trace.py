import sys

def compare_files(test_file_path, golden_file_path, output_file_path, mismatch_only=False, filter_prefix=None):
    """Compare first len(golden_file)-1 lines of test_file to golden_file side by side."""
    
    # Read files
    with open(golden_file_path, 'r') as f:
        golden_lines = f.readlines()
    
    with open(test_file_path, 'r') as f:
        test_lines = f.readlines()
    
    # Compare first len(golden_file)-1 lines
    num_lines = len(golden_lines) - 1
    
    with open(output_file_path, 'w') as out:
        # Write header
        out.write(f"{'Line':<6} | {'Golden':<50} | {'Test':<50} | {'Match'}\n")
        out.write("-" * 118 + "\n")
        
        # Compare line by line
        mismatches = 0
        total_compared = 0
        for i in range(num_lines):
            golden_line = golden_lines[i].rstrip('\n') if i < len(golden_lines) else ""
            test_line = test_lines[i].rstrip('\n') if i < len(test_lines) else ""
            
            # Skip if filter_prefix is specified and line doesn't start with it
            if filter_prefix and not golden_line.startswith(filter_prefix):
                continue

            if filter_prefix == '[W]':
                if golden_line.split()[3] == '00':
                    continue
            
            total_compared += 1
            match = "✓" if golden_line == test_line else "✗"
            if golden_line != test_line:
                mismatches += 1
            
            # Skip if mismatch_only is True and lines match
            if mismatch_only and golden_line == test_line:
                continue
            
            out.write(f"{i+1:<6} | {golden_line:<50} | {test_line:<50} | {match}\n")
        
        # Write summary
        out.write("\n" + "=" * 118 + "\n")
        if filter_prefix:
            out.write(f"Filter: Lines starting with '{filter_prefix}'\n")
        out.write(f"Total lines compared: {total_compared}\n")
        out.write(f"Matches: {total_compared - mismatches}\n")
        out.write(f"Mismatches: {mismatches}\n")

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Usage: python cmp_trace_2.py <test_file> <golden_file> <output_file> [--mismatch-only] [--filter PREFIX]")
        sys.exit(1)
    
    test_file = sys.argv[1]
    golden_file = sys.argv[2]
    output_file = sys.argv[3]
    
    mismatch_only = False
    filter_prefix = None
    
    # Parse optional arguments
    i = 4
    while i < len(sys.argv):
        if sys.argv[i] == "--mismatch-only":
            mismatch_only = True
            i += 1
        elif sys.argv[i] == "--filter" and i + 1 < len(sys.argv):
            filter_prefix = sys.argv[i + 1]
            i += 2
        else:
            i += 1
    
    compare_files(test_file, golden_file, output_file, mismatch_only, filter_prefix)
    print(f"Comparison written to {output_file}")