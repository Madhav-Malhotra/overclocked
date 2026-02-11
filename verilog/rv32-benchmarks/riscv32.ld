/* RISC-V RV32I Linker Script
 * Base address: 0x01000000 (matches processor BASE_ADDR)
 * Memory size: 1MB (matches processor default MEM_DEPTH)
 */

OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  ram (rwx) : ORIGIN = 0x01000000, LENGTH = 1M
}

SECTIONS
{
  /* Code section starting at base address */
  .text : {
    *(.text.init)
    *(.text)
    *(.text.*)
  } > ram

  /* Read-only data */
  .rodata : {
    *(.rodata)
    *(.rodata.*)
  } > ram

  /* Data section (initialized data) */
  .data : {
    *(.data)
    *(.data.*)
  } > ram

  /* BSS section (uninitialized data) */
  .bss : {
    *(.bss)
    *(.bss.*)
    *(COMMON)
  } > ram

  /* HTIF symbols for test pass/fail signaling */
  .htif : ALIGN(8) {
    . = ALIGN(8);
    tohost = .;
    . = . + 8;
    fromhost = .;
    . = . + 8;
  } > ram

  /* Stack grows downward from end of RAM */
  _stack_top = ORIGIN(ram) + LENGTH(ram);
}
