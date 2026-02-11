# Makefile for rebuilding simple-programs benchmarks for ISS verification
# Builds ELF files at 0x01000000 base address for Spike (no custom DTB needed)

# Toolchain
RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJDUMP = $(RISCV_PREFIX)objdump

# Compiler flags
CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -O2
LDFLAGS = -T../riscv32.ld

# Startup code
STARTUP = ../start.s

# Source files
SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=.iss.elf)

# Default target
all: $(TARGETS)
	@echo ""
	@echo "Built $(words $(TARGETS)) ISS-compatible benchmarks"
	@echo "Run with: spike --isa=rv32i -m0x01000000:0x200000 --log-commits <file>.iss.elf"

# Pattern rule to build each .iss.elf from .c
%.iss.elf: %.c $(STARTUP)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(STARTUP) $<

# Generate disassembly for debugging
%.dis: %.iss.elf
	$(OBJDUMP) -d $< > $@

# Clean ISS build artifacts only (preserve original .elf files)
clean:
	rm -f *.iss.elf *.dis

# Build all with disassembly
debug: $(TARGETS) $(TARGETS:.iss.elf=.dis)

# Test one benchmark with spike
test-%: %.iss.elf
	spike --isa=rv32i -m0x01000000:0x200000 --log-commits --instructions=10000 $< 2>$*.spike.log
	@echo "Spike log written to $*.spike.log"
	@tail -5 $*.spike.log

.PHONY: all clean debug
