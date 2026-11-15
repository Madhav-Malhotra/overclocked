# Docker

Builds and runs the RISC-V verification environment in a container.

## Commands

| Command | Description |
|---------|-------------|
| `make build` | Build the Docker image |
| `make run_all_benchmarks` | Run all benchmarks via `make run_all_benchmarks` |
| `make run_scripts` | Run the Python test orchestrator (`run_scripts.py`) |
| `make attach` | Attach an interactive shell to the container |
| `make clean` | Remove the Docker image |

## Usage

```bash
cd verilog/verif/scripts/docker

# First, build the image
make build

# Then run any of the commands above
make run_all_benchmarks
make run_scripts
make attach
```
