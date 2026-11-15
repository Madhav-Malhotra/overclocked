# golden_sim

Known-good OoO event traces (`<bench>.trace`, format in `../README.md`), used as
regression references once the core passes a benchmark against spike.

Empty until the OoO core runs end to end (plan.md Phase 5+). To add one, after a
benchmark passes `make run_and_verify BENCH=<name>`:

```sh
cp ../sim/verilator/test_pd/<name>.trace <name>.trace
```

Compare a new run against it (cycle numbers included, so this flags timing changes too):

```sh
cd ../scripts && make diff_golden MEM_PATH=<path/to/name.x>
```

Correctness is always judged against spike (`cmp_ooo_spike.py`); golden traces
only detect unintended changes in OoO timing/ordering.
