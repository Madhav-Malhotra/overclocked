# Overclocked

This is the monorepo for the Overclocked game, a Unity-based CPU simulator with a Verilator backend and an optional PYNQ-Z2 FPGA backend.

### Contents
- `unity/` - Unity project with game assets and C# scripts
- `verilog/` - Verilog implementation of the RV32I CPU and verification scripts
- `verilator/` - Notes on Verilating the Verilog source into a native plugin for Unity
- `bridge/` - Unified C# interface (`ICPU`) that talks to either the Verilator model or the FPGA webserver backend
- `webserver/` - REST API (FastAPI, dockerized) that runs on the PYNQ-Z2 to expose CPU control signals/state to the Bridge

See the respective folders for `README.md` files with more details on each component.