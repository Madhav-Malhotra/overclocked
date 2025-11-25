# SETUP
1. Run `git pull`
2. Run `git submodule init` and `git submodule update` to fetch the RV32 benchmarks
3. Run `chsh -s /bin/bash` and `exec bash`

# Testing
1. In `build/scripts`, run `make bitstream 2>&1 | tee bitstream.log` and Ctrl+F the bitstream.log file for `error`, `fail`, and `CRITICAL`.
  - Then, run `make post-synth-sim` and `make routed-sim` to see trace files for one individual instruction.
2. In `verif/scripts`, run `make help` and `make run_all_benchmarks XSIM=1` to run simulation checks across all instructions. Haven't verified this code - comes from Vincent. 

Running diff comparison in sim mode...
FAIL: BubbleSort.trace
FAIL: CheckVowel.trace
FAIL: Fibonacci.trace
FAIL: SimpleAdd.trace
FAIL: SimpleIf.trace
PASS: SumArray.trace
FAIL: Swap.trace
FAIL: SwapShift.trace
PASS: fact-short.trace
FAIL: gcd.trace
PASS: rv32ui-p-add.trace
PASS: rv32ui-p-addi.trace
PASS: rv32ui-p-and.trace
PASS: rv32ui-p-andi.trace
PASS: rv32ui-p-auipc.trace
PASS: rv32ui-p-beq.trace
PASS: rv32ui-p-bge.trace
PASS: rv32ui-p-bgeu.trace
PASS: rv32ui-p-blt.trace
PASS: rv32ui-p-bltu.trace
PASS: rv32ui-p-bne.trace
PASS: rv32ui-p-jal.trace
PASS: rv32ui-p-jalr.trace
PASS: rv32ui-p-lb.trace
FAIL: rv32ui-p-lbu.trace
PASS: rv32ui-p-lh.trace
FAIL: rv32ui-p-lhu.trace
PASS: rv32ui-p-lui.trace
PASS: rv32ui-p-lw.trace
PASS: rv32ui-p-or.trace
PASS: rv32ui-p-ori.trace
FAIL: rv32ui-p-sb.trace
FAIL: rv32ui-p-sh.trace
PASS: rv32ui-p-simple.trace
PASS: rv32ui-p-sll.trace
PASS: rv32ui-p-slli.trace
PASS: rv32ui-p-slt.trace
PASS: rv32ui-p-slti.trace
PASS: rv32ui-p-sltiu.trace
PASS: rv32ui-p-sltu.trace
PASS: rv32ui-p-sra.trace
PASS: rv32ui-p-srai.trace
PASS: rv32ui-p-srl.trace
PASS: rv32ui-p-srli.trace
PASS: rv32ui-p-sub.trace
FAIL: rv32ui-p-sw.trace
PASS: rv32ui-p-xor.trace
PASS: rv32ui-p-xori.trace
==========================================
SUMMARY
==========================================
Passed: 35
Failed: 13
==========================================