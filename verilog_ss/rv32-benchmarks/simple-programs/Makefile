SOURCES= $(wildcard *.c)
ELFS=$(SOURCES:.c=.elf)
ASM=$(SOURCES:.c=.s)
DMP=$(SOURCES:.c=.d)
DMPNAT=$(SOURCES:.c=.dnum)
RAW=$(SOURCES:.c=.raw)
BIN=$(SOURCES:.c=.bin)
X=$(SOURCES:.c=.x)

CC = mips-linux-gnu-gcc 
OBJDUMP = mips-linux-gnu-objdump
OBJCOPY = mips-linux-gnu-objcopy


# 2016-05 version
CC = riscv32-unknown-elf-gcc
OBJDUMP = riscv32-unknown-elf-objdump 
OBJCOPY = riscv32-unknown-elf-objcopy
# Old version of toolchain

CFLAGS = -static -nostdlib -O0 -fno-delayed-branch -fomit-frame-pointer -nostartfiles #-Ttext=0x10000000
CORE = -march=rv32i

LINKERFILE= -T ece320.ld

all: $(ELFS) $(ASM) $(DMP) $(DMPNAT) $(BIN) $(RAW) $(X)

%.elf: %.c
	@echo "ELF-ing $^"
	$(CC) $(CORE) $(CFLAGS) -o $@ $^ $(LINKERFILE)

%.s: %.c
	@echo "S-ing $^"
	$(CC) $(CORE) $(CFLAGS) -S $^ $(LINKERFILE)

%.dnum: %.elf
	$(OBJDUMP) --disassembler-options=no-aliases,numeric -D $^ > $@

%.d: %.elf
	$(OBJDUMP) -D $^ > $@

%.bin: %.elf
	$(OBJCOPY) -O binary $^ $@

%.raw: %.bin
	od -Ax -tx $^ > $@

%.x: %.raw
	./mk-bin.py $^ > $@

clean:
	rm -f *.o core *.elf *.bin *.raw *.x  *.d *.s 

(rebuild: clean build
