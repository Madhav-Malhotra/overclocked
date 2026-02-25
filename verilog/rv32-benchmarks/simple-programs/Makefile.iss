# Makefile for rebuilding simple-programs benchmarks for ISS verification
# Source of truth: *.c files -> .iss.elf (for Spike) + .x (for processor $readmemh)

# Toolchain
RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJCOPY = $(RISCV_PREFIX)objcopy
OBJDUMP = $(RISCV_PREFIX)objdump

# Compiler flags
CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -O2
LDFLAGS = -T../riscv32.ld

# Startup code
STARTUP = ../start.s

# Source files
SOURCES = $(wildcard *.c)
ELF_TARGETS = $(SOURCES:.c=.iss.elf)
X_TARGETS   = $(SOURCES:.c=.x)

# Default target: build both .iss.elf (Spike) and .x (processor)
all: $(ELF_TARGETS) $(X_TARGETS)
	@echo ""
	@echo "Built $(words $(ELF_TARGETS)) ISS-compatible benchmarks (.iss.elf + .x)"

# Pattern rule to build each .iss.elf from .c
%.iss.elf: %.c $(STARTUP)
	@echo "  CC  $@"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(STARTUP) $<

# Build .x from .iss.elf: binary dump -> one little-endian word per line
%.x: %.iss.elf
	@echo "  X   $@"
	@$(OBJCOPY) -O binary $< $*.bin
	@od -An -tx4 -v $*.bin | tr -s ' \t' '\n' | grep -v '^$$' > $@ || true
	@rm -f $*.bin

# Generate disassembly for debugging
%.dis: %.iss.elf
	$(OBJDUMP) -d $< > $@

# Clean ISS build artifacts (keep .c sources and original .elf/.x files are now generated)
clean:
	rm -f *.iss.elf *.x *.bin *.dis

# Build all with disassembly
debug: $(ELF_TARGETS) $(ELF_TARGETS:.iss.elf=.dis)

# Test one benchmark with spike
test-%: %.iss.elf
	spike --isa=rv32g -m0x01000000:0x200000 --log-commits $< 2>$*.spike.log
	@echo "Spike log written to $*.spike.log"
	@tail -5 $*.spike.log

.PHONY: all clean debug
