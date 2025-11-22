# SETUP
1. Run `git pull`
2. Run `git submodule init` and `git submodule update` to fetch the RV32 benchmarks

# Testing
1. In `build/scripts`, run `make bitstream 2>&1 | tee bitstream.log` and Ctrl+F the bitstream.log file for `error`, `fail`, and `CRITICAL`.
  - Then, run `make post-synth-sim` and `make routed-sim` to see trace files.
2. In `verif/scripts`, run `make help` and `make all` to run simulation checks. Haven't verified this code - comes from Vincent. 
