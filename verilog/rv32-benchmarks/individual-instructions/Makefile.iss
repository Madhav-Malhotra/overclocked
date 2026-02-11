# Makefile for rebuilding individual-instructions benchmarks for ISS verification
# Two-step process:
#  1. Extract .iss.s from .d files (one-time, via 'make extract')
#  2. Build .iss.elf from .iss.s files (via 'make all')

# Toolchain
RISCV_PREFIX = riscv64-unknown-elf-
AS = $(RISCV_PREFIX)as
CC = $(RISCV_PREFIX)gcc
OBJDUMP = $(RISCV_PREFIX)objdump

# Flags
ASFLAGS = -march=rv32i -mabi=ilp32
LDFLAGS = -T../riscv32.ld -nostdlib

# Source and target files
DISASM_FILES = $(wildcard *.d)
ASM_FILES = $(DISASM_FILES:.d=.iss.s)
TARGETS = $(ASM_FILES:.iss.s=.iss.elf)

# Default target: build ELFs from existing .iss.s files
all: $(TARGETS)
	@echo ""
	@echo "Built $(words $(TARGETS)) ISS-compatible instruction tests"
	@echo "Run with: spike --isa=rv32i -m0x01000000:0x200000 --log-commits <file>.iss.elf"

# Extract assembly from disassembly (one-time step)
extract: $(ASM_FILES)
	@echo ""
	@echo "Extracted $(words $(ASM_FILES)) assembly files from .d disassembly"

%.iss.s: %.d d_to_s.py
	@echo "Extracting $< -> $@..."
	@python3 d_to_s.py $< $@

# Build ELF from assembly
%.iss.elf: %.iss.s
	@echo "Building $@..."
	@$(CC) $(ASFLAGS) $(LDFLAGS) -o $@ $<

# Generate disassembly for debugging
%.dis: %.iss.elf
	$(OBJDUMP) -d $< > $@

# Clean build artifacts (keeps .iss.s source files)
clean:
	rm -f *.iss.elf *.dis

# Clean everything including extracted assembly
distclean: clean
	rm -f *.iss.s *.spike.log

# Build all with disassembly
debug: $(TARGETS) $(TARGETS:.iss.elf=.dis)

# Test one benchmark with spike
test-%: %.iss.elf
	@spike --isa=rv32i -m0x01000000:0x200000 --log-commits --instructions=10000 $< 2>$*.spike.log
	@echo "Spike log written to $*.spike.log ($(shell wc -l < $*.spike.log) instructions)"
	@echo "Last instruction:"
	@tail -1 $*.spike.log

.PHONY: all extract clean distclean debug
