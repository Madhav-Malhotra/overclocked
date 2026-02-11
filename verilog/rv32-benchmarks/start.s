/* Minimal startup code for RISC-V bare-metal programs
 * Sets up stack pointer, calls main(), and signals exit via HTIF
 */

.section .text.init
.globl _start
_start:
    /* Initialize stack pointer to end of RAM (from linker script) */
    /* Load address using explicit lui/addi to avoid assembler issues */
    lui sp, %hi(_stack_top)
    addi sp, sp, %lo(_stack_top)

    /* Call main function */
    call main

    /* main returned a value in a0 (0=fail, 1=pass) */
    /* Write result to tohost and signal Spike to exit */
    la t0, tohost
    sw a0, 0(t0)
    ecall           /* Tell Spike to stop simulation */

    /* Safety fallback - should never reach here */
_hang:
    j _hang
