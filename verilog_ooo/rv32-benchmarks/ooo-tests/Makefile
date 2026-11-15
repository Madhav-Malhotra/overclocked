# Build OoO directed tests: *.s -> .elf (for Spike) + .x (for the core's $readmemh)
# Same flow as ../individual-instructions/Makefile.new.
#
# Phase 0-5 rule (plan.md D5): tests must be BRANCH-FREE (no b*, jal, jalr, j,
# call, ret) and end with the pass sequence (fence / la t0,tohost / sw / ecall).

RISCV_PREFIX = riscv64-unknown-elf-
CC      = $(RISCV_PREFIX)gcc
OBJCOPY = $(RISCV_PREFIX)objcopy
OBJDUMP = $(RISCV_PREFIX)objdump

ASFLAGS = -march=rv32im -mabi=ilp32
LDFLAGS = -T../riscv32.ld -nostdlib

TEST_FILES  = $(wildcard *.s)
ELF_TARGETS = $(TEST_FILES:.s=.elf)
X_TARGETS   = $(TEST_FILES:.s=.x)

all: $(ELF_TARGETS) $(X_TARGETS)
	@echo "Built $(words $(ELF_TARGETS)) ooo tests (.elf + .x)"

%.elf: %.s
	@echo "  AS  $@"
	@$(CC) $(ASFLAGS) $(LDFLAGS) -o $@ $<

%.x: %.elf
	@echo "  X   $@"
	@$(OBJCOPY) -O binary $< $*.bin
	@od -An -tx4 -v $*.bin | tr -s ' \t' '\n' | grep -v '^$$' > $@ || true
	@rm -f $*.bin

%.dis: %.elf
	$(OBJDUMP) -d $< > $@

# Fail if any test contains a control-transfer instruction (until Phase 6)
check_branch_free: $(ELF_TARGETS)
	@bad=0; for e in $(ELF_TARGETS); do \
	  if $(OBJDUMP) -d $$e | grep -qE '\s(beq|bne|blt|bge|bltu|bgeu|beqz|bnez|blez|bgez|bltz|bgtz|jal|jalr|j|jr|ret|call)\s'; then \
	    echo "  BRANCH FOUND: $$e"; bad=1; fi; done; \
	[ $$bad -eq 0 ] && echo "All ooo tests are branch-free"

clean:
	rm -f *.elf *.x *.bin *.dis

.PHONY: all clean check_branch_free
