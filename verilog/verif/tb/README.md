# Unit Testbenches

This directory contains standalone unit testbenches for individual design modules. Each testbench instantiates a single DUT, applies test vectors, and reports PASS/FAIL per case.

## Running All Testbenches

```bash
make all
```

## Running Individual Testbenches

```bash
make tb_mult   # Multiplier (fu_multiplier)
make tb_div    # Divider (fu_divider)
```

## Cleaning Build Artifacts

```bash
make clean
```
