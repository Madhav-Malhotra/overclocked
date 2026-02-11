#!/bin/bash

echo "========================================="
echo "Testing Spike Compatibility"
echo "========================================="
echo ""

# Test 1: .x files
echo "========================================="
echo "1. Testing .x files (original binaries)"
echo "========================================="
x_passed=0
x_failed=0
x_failed_list=""

for xfile in rv32ui-p-*.x; do
    if spike --isa=rv32i -m0x01000000:0x200000 "$xfile" &>/dev/null; then
        ((x_passed++))
    else
        ((x_failed++))
        x_failed_list="$x_failed_list\n  - $xfile"
    fi
done

echo "PASSED: $x_passed tests"
echo "FAILED: $x_failed tests"
if [ $x_failed -gt 0 ]; then
    echo "Failed tests:"
    echo -e "$x_failed_list"
fi
echo ""

# Test 2: test-*.s files (template-based)
echo "========================================="
echo "2. Testing test-*.s files (template-based)"
echo "========================================="
template_passed=0
template_failed=0
template_failed_list=""

for sfile in test-*.s; do
    [ ! -f "$sfile" ] && continue
    elf="${sfile%.s}.elf"
    if [ -f "$elf" ]; then
        if spike --isa=rv32i -m0x01000000:0x200000 "$elf" &>/dev/null; then
            ((template_passed++))
        else
            ((template_failed++))
            template_failed_list="$template_failed_list\n  - $elf (from $sfile)"
        fi
    fi
done

echo "PASSED: $template_passed tests"
echo "FAILED: $template_failed tests"
if [ $template_failed -gt 0 ]; then
    echo "Failed tests:"
    echo -e "$template_failed_list"
fi
echo ""

# Test 3: C files compiled to .iss.elf
echo "========================================="
echo "3. Testing .c files (from simple-programs)"
echo "========================================="
cd ../simple-programs
c_passed=0
c_failed=0
c_failed_list=""

for elf in *.iss.elf; do
    [ ! -f "$elf" ] && continue
    if spike --isa=rv32i -m0x01000000:0x200000 "$elf" &>/dev/null; then
        ((c_passed++))
    else
        ((c_failed++))
        c_failed_list="$c_failed_list\n  - $elf"
    fi
done

echo "PASSED: $c_passed tests"
echo "FAILED: $c_failed tests"
if [ $c_failed -gt 0 ]; then
    echo "Failed tests:"
    echo -e "$c_failed_list"
fi
echo ""

# Summary
echo "========================================="
echo "OVERALL SUMMARY"
echo "========================================="
echo "Category 1 (.x files):           $x_passed passed, $x_failed failed"
echo "Category 2 (test-*.s files):     $template_passed passed, $template_failed failed"
echo "Category 3 (.c -> .iss.elf):     $c_passed passed, $c_failed failed"
echo ""
total_passed=$((x_passed + template_passed + c_passed))
total_failed=$((x_failed + template_failed + c_failed))
echo "TOTAL:                           $total_passed passed, $total_failed failed"
echo "========================================="
