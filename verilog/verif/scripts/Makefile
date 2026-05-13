export TEST ?= test_pd

export SCRIPTS_DIR = $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export CL_ROOT     = $(realpath $(SCRIPTS_DIR)/../..)
export TEST_NAME   = $(CL_ROOT)/verif/tests/$(TEST)

export SIM_ROOT = $(CL_ROOT)/verif/sim/$(SIMULATOR)
export SIM_DIR  = $(SIM_ROOT)/$(TEST)

all: make_sim_dir compile run

# surround path with quotes
MEM_PATH              ?= $(CL_ROOT)/verif/data/rv32ui-p-add.x
MEM_PATH_NOT_DIR			:= $(notdir $(MEM_PATH))
LINE_COUNT            ?= $(shell echo `wc -l < $(MEM_PATH)`)
MEM_PATH_STR          ?= \"$(abspath $(MEM_PATH))\"
MEM_DEPTH             ?= 1048576
TEST_VECTOR           ?= $(CL_ROOT)/verif/data/test_vector.x
TEST_VECTOR_STR       ?= \"$(TEST_VECTOR)\"
TRACE_FILE				    ?= $(MEM_PATH_NOT_DIR:x=trace)
VCD_FILE				      ?= $(MEM_PATH_NOT_DIR:x=vcd)
VCD_FILE_STR			    ?= \"$(VCD_FILE)\"
GEN_TRACE             ?= 1
TIMEOUT               ?= 50000
TRACE_FILE_STR        ?= \"$(TRACE_FILE)\"

WARN ?= 1

ifeq ($(WARN), 1)
WARN_OUTPUT = 2>&1 | tee output.log
WARN_CHECK  = cat $(SIM_DIR)/output.log | bash $(CL_ROOT)/verif/scripts/check_warnings.sh
else
WARN_OUTPUT =
WARN_CHECK  =
endif

# Use Verilator as the simulator
export SIMULATOR = verilator
include Makefile.verilator

make_sim_dir:
	mkdir -p $(SIM_ROOT)

# Benchmark paths - try to find the benchmarks directory
BENCH_ROOT := $(shell if [ -d "$(CL_ROOT)/../../../rv32-benchmarks" ]; then \
		echo "$(CL_ROOT)/../../../rv32-benchmarks"; \
	elif [ -d "$(CL_ROOT)/../../rv32-benchmarks" ]; then \
		echo "$(CL_ROOT)/../../rv32-benchmarks"; \
	elif [ -d "$(CL_ROOT)/../rv32-benchmarks" ]; then \
		echo "$(CL_ROOT)/../rv32-benchmarks"; \
	elif [ -d "$(CL_ROOT)/rv32-benchmarks" ]; then \
		echo "$(CL_ROOT)/rv32-benchmarks"; \
	else \
		echo "NOT_FOUND"; \
	fi)

BENCH_INDIVIDUAL := $(wildcard $(BENCH_ROOT)/individual-instructions/*.x)
BENCH_SIMPLE := $(wildcard $(BENCH_ROOT)/simple-programs/*.x)
ALL_BENCHMARKS := $(BENCH_INDIVIDUAL) $(BENCH_SIMPLE)

# Debug: print benchmark list
.PHONY: list_benchmarks
list_benchmarks:
	@echo "CL_ROOT: $(CL_ROOT)"
	@echo "BENCH_ROOT: $(BENCH_ROOT)"
	@echo "Individual benchmarks path: $(BENCH_ROOT)/individual-instructions/"
	@echo "Simple benchmarks path: $(BENCH_ROOT)/simple-programs/"
	@echo "Individual benchmarks found: $(words $(BENCH_INDIVIDUAL))"
	@echo "Simple benchmarks found: $(words $(BENCH_SIMPLE))"
	@echo "Total benchmarks: $(words $(ALL_BENCHMARKS))"
	@echo ""
	@echo "All benchmarks:"
	@for bench in $(ALL_BENCHMARKS); do \
		echo "  $$bench"; \
	done
	@echo ""
	@echo "Directory check:"
	@ls -la $(BENCH_ROOT)/individual-instructions/ 2>&1 | head -10 || echo "Directory not found"
	@ls -la $(BENCH_ROOT)/simple-programs/ 2>&1 | head -10 || echo "Directory not found"


# Diff configuration - compare simulation traces against golden references
DIFF_DIR := $(CL_ROOT)/verif/diffs
TEST_TRACE_DIR := $(CL_ROOT)/verif/sim/$(SIMULATOR)/test_pd
GOLDEN_DIR := $(CL_ROOT)/verif/golden_sim
DIFF_GEN := $(SCRIPTS_DIR)/cmp_sim_trace.py
DIFF_SUBDIR := $(DIFF_DIR)/sim

# Spike-based verification configuration
SPIKE_TRACES_DIR := $(CL_ROOT)/verif/spike_traces
SPIKE_TRACE_GEN  := $(SCRIPTS_DIR)/spike_trace_gen.py
CMP_WB_SPIKE     := $(SCRIPTS_DIR)/cmp_wb_spike.py
SPIKE_DIFF_DIR   := $(CL_ROOT)/verif/diffs/spike

PARALLEL_RUNNER := $(SCRIPTS_DIR)/run_benchmarks_parallel.py
JOBS            ?= $(shell sysctl -n hw.ncpu)
# JOBS            ?= $(shell nproc)

# Build benchmarks from source (.s and .c -> .elf + .x)
# Always cleans first to ensure .elf and .x are both derived from current .s/.c sources
.PHONY: build_benchmarks
build_benchmarks:
	@echo "Building benchmarks from source ($(JOBS) jobs)..."
	@$(MAKE) -C $(BENCH_ROOT)/individual-instructions -f Makefile.new clean
	@$(MAKE) -C $(BENCH_ROOT)/individual-instructions -f Makefile.new -j$(JOBS) all
	@$(MAKE) -C $(BENCH_ROOT)/simple-programs -f Makefile.iss clean
	@$(MAKE) -C $(BENCH_ROOT)/simple-programs -f Makefile.iss -j$(JOBS) all
	@echo "Benchmarks built."

# Run all benchmarks end-to-end: build -> simulate -> spike traces -> compare (all parallel)
.PHONY: run_all_benchmarks
run_all_benchmarks: build_benchmarks
	@python3 $(PARALLEL_RUNNER) \
		--bench-root $(BENCH_ROOT) \
		--scripts-dir $(SCRIPTS_DIR) \
		--cl-root $(CL_ROOT) \
		--jobs $(JOBS) \
		--skip-build

# Same as run_all_benchmarks but skip the build step (benchmarks already built)
.PHONY: run_all_benchmarks_no_build
run_all_benchmarks_no_build:
	@python3 $(PARALLEL_RUNNER) \
		--bench-root $(BENCH_ROOT) \
		--scripts-dir $(SCRIPTS_DIR) \
		--cl-root $(CL_ROOT) \
		--jobs $(JOBS) \
		--skip-build

# Pattern rule to run individual benchmarks
$(ALL_BENCHMARKS): %:
	@echo "Running benchmark: $@"
	@$(MAKE) -s run TEST=test_pd MEM_PATH=$@

# Compare all trace files against golden
.PHONY: diff_all_benchmarks
diff_all_benchmarks:
	@echo "Running diff comparison..."
	@mkdir -p $(DIFF_SUBDIR)
	@pass=0; fail=0; \
	for trace in $(TEST_TRACE_DIR)/*.trace; do \
		[ -f "$$trace" ] || continue; \
		golden="$(GOLDEN_DIR)/$$(basename $$trace)"; \
		if [ -f "$$golden" ]; then \
			python3 $(DIFF_GEN) "$$trace" "$$golden" \
				"$(DIFF_SUBDIR)/$$(basename $$trace .trace).diff" \
				--mismatch-only --filter "[W]" > /dev/null 2>&1; \
			if grep -q "Mismatches: 0" "$(DIFF_SUBDIR)/$$(basename $$trace .trace).diff"; then \
				echo "PASS: $$(basename $$trace)"; \
				pass=$$((pass + 1)); \
			else \
				echo "FAIL: $$(basename $$trace)"; \
				fail=$$((fail + 1)); \
			fi; \
		else \
			echo "SKIP: $$(basename $$trace) (no golden file found)"; \
		fi; \
	done; \
	echo "=========================================="; \
	echo "SUMMARY"; \
	echo "=========================================="; \
	echo "Passed: $$pass"; \
	echo "Failed: $$fail"; \
	echo "=========================================="

# =====================================================================
# Spike-based verification targets
# =====================================================================

# Generate spike commit trace for a single benchmark
# Usage: make gen_spike_trace BENCH=rv32ui-p-add
.PHONY: gen_spike_trace
gen_spike_trace:
	@if [ -z "$(BENCH)" ]; then echo "ERROR: BENCH not set. Usage: make gen_spike_trace BENCH=<name>"; exit 1; fi
	@echo "Generating spike trace for: $(BENCH)"
	@python3 $(SPIKE_TRACE_GEN) \
		--bench $(BENCH) \
		--bench-root $(BENCH_ROOT) \
		--out-dir $(SPIKE_TRACES_DIR)

# Generate spike commit traces for ALL benchmarks
.PHONY: gen_all_spike_traces
gen_all_spike_traces:
	@echo "Generating spike traces for all benchmarks..."
	@mkdir -p $(SPIKE_TRACES_DIR)
	@pass=0; fail=0; \
	for bench in $(ALL_BENCHMARKS); do \
		name=$$(basename $$bench .x); \
		echo "  $$name"; \
		python3 $(SPIKE_TRACE_GEN) \
			--bench $$name \
			--bench-root $(BENCH_ROOT) \
			--out-dir $(SPIKE_TRACES_DIR) || fail=$$((fail + 1)); \
		pass=$$((pass + 1)); \
	done; \
	echo "=========================================="; \
	echo "Generated: $$pass  Failed: $$fail"; \
	echo "=========================================="

# Compare processor [W] output vs spike commits for one benchmark
# Usage: make diff_spike MEM_PATH=<path/to/bench.x>
.PHONY: diff_spike
diff_spike:
	@mkdir -p $(SPIKE_DIFF_DIR)
	@bench_name=$(MEM_PATH_NOT_DIR:x=trace); \
	spike_trace="$(SPIKE_TRACES_DIR)/$(MEM_PATH_NOT_DIR:x=trace)"; \
	proc_trace="$(TEST_TRACE_DIR)/$(MEM_PATH_NOT_DIR:x=trace)"; \
	python3 $(CMP_WB_SPIKE) \
		"$$proc_trace" \
		"$$spike_trace" \
		--out "$(SPIKE_DIFF_DIR)/$(MEM_PATH_NOT_DIR:x=diff)"

# Run a benchmark then generate spike trace and compare
# Usage: make run_and_verify MEM_PATH=<path/to/bench.x>
.PHONY: run_and_verify
run_and_verify:
	$(MAKE) run MEM_PATH=$(MEM_PATH)
	$(MAKE) gen_spike_trace BENCH=$(MEM_PATH_NOT_DIR:.x=)
	$(MAKE) diff_spike MEM_PATH=$(MEM_PATH)

# verify_all: alias for run_all_benchmarks (full pipeline from source)
.PHONY: verify_all
verify_all: run_all_benchmarks

# Run single benchmark by name
.PHONY: run_bench
run_bench:
	@if [ "$(BENCH_ROOT)" = "NOT_FOUND" ]; then \
		echo "Error: Benchmark directory not found"; \
		exit 1; \
	fi
	@if [ -f "$(BENCH_ROOT)/individual-instructions/$(BENCH).x" ]; then \
		$(MAKE) -s run TEST=test_pd MEM_PATH="$(BENCH_ROOT)/individual-instructions/$(BENCH).x"; \
	elif [ -f "$(BENCH_ROOT)/simple-programs/$(BENCH).x" ]; then \
		$(MAKE) -s run TEST=test_pd MEM_PATH="$(BENCH_ROOT)/simple-programs/$(BENCH).x"; \
	else \
		echo "Error: Benchmark $(BENCH) not found"; \
		echo "Searched in:"; \
		echo "  $(BENCH_ROOT)/individual-instructions/$(BENCH).x"; \
		echo "  $(BENCH_ROOT)/simple-programs/$(BENCH).x"; \
		exit 1; \
	fi

# Usage: make run_stage_test BENCH=rv32ui-p-add
.PHONY: run_stage_test
run_stage_test:
	@if [ -z "$(BENCH)" ]; then echo "ERROR: Set BENCH=<name>"; exit 1; fi
	@# Find path and call make all in one go
	@BENCH_FILE=$$(find $(BENCH_ROOT) -name "$(BENCH).x" | head -n 1); \
	if [ -z "$$BENCH_FILE" ]; then \
		echo "ERROR: Benchmark $(BENCH) not found in $(BENCH_ROOT)"; \
		exit 1; \
	fi; \
	$(MAKE) all TEST=test_stage_en MEM_PATH=$$BENCH_FILE

# Usage: make waves_stage_test BENCH=rv32ui-p-add
.PHONY: waves_stage_test
waves_stage_test:
	@# Find the benchmark path to ensure we point to the right VCD filename
	$(eval UNIT_PATH := $(shell find $(BENCH_ROOT) -name "$(BENCH).x" | head -n 1))
	@if [ -z "$(UNIT_PATH)" ]; then echo "ERROR: BENCH=$(BENCH) not found"; exit 1; fi
	@# Run the waves target with the TEST and MEM_PATH overrides
	$(MAKE) waves TEST=test_stage_en MEM_PATH=$(UNIT_PATH) VCD=1

# Help target
.PHONY: help
help:
	@echo "=========================================="
	@echo "Available Make Targets"
	@echo "=========================================="
	@echo ""
	@echo "Main Targets:"
	@echo "  make run_all_benchmarks          - Full pipeline: build -> simulate -> spike compare (parallel)"
	@echo "  make run_all_benchmarks_no_build - Same but skip rebuild (benchmarks already built)"
	@echo "  make verify_all                  - Alias for run_all_benchmarks"
	@echo "  make build_benchmarks            - Compile .s/.c sources into .elf + .x (no simulation)"
	@echo "  JOBS=N make run_all_benchmarks   - Override parallelism (default: sysctl -n hw.ncpu=$(JOBS))"
# 	@echo "  JOBS=N make run_all_benchmarks   - Override parallelism (default: nproc=$(JOBS))"
	@echo ""
	@echo "Build & Run Targets:"
	@echo "  make all                    - Build simulation directory, compile, and run (default target)"
	@echo "  make compile                - Compile the design"
	@echo "  make run                    - Run simulation with specified benchmark"
	@echo "                                Usage: make run MEM_PATH=<path/to/benchmark.x>"
	@echo ""
	@echo "Benchmark Targets:"
	@echo "  make run_bench BENCH=<name> - Run a single benchmark by name (without .x extension)"
	@echo "                                Example: make run_bench BENCH=rv32ui-p-add"
	@echo "  make list_benchmarks        - List all available benchmarks and their paths"
	@echo ""
	@echo "Spike-based Verification Targets (manual):"
	@echo "  make gen_spike_trace BENCH=<name>  - Generate spike commit trace for one benchmark"
	@echo "  make gen_all_spike_traces           - Generate spike commit traces for all benchmarks"
	@echo "  make diff_spike MEM_PATH=<path>     - Compare processor [W] trace vs spike (one bench)"
	@echo "  make run_and_verify MEM_PATH=<path> - Run simulation + compare vs spike (one bench)"
	@echo ""
	@echo "Utility Targets:"
	@echo "  make clean                  - Clean simulation files"
	@echo "  make help                   - Show this help message"
	@echo ""
	@echo "=========================================="
	@echo "Common Variables:"
	@echo "=========================================="
	@echo "  TEST=<test_name>            - Specify test name (default: test_pd)"
	@echo "  MEM_PATH=<path>             - Path to benchmark file (default: verif/data/rv32ui-p-add.x)"
	@echo "  BENCH=<name>                - Benchmark name for run_bench target"
	@echo "  GEN_TRACE=<0|1>             - Enable/disable trace generation (default: 1)"
	@echo "  TIMEOUT=<cycles>            - Simulation timeout in cycles (default: 50000)"
	@echo "  WARN=<0|1>                  - Enable/disable warning checks (default: 1)"
	@echo ""
	@echo "=========================================="
	@echo "Examples:"
	@echo "=========================================="
	@echo "  # Run a specific benchmark"
	@echo "  make run MEM_PATH=../rv32-benchmarks/individual-instructions/rv32ui-p-add.x"
	@echo ""
	@echo "  # Run a benchmark by name"
	@echo "  make run_bench BENCH=rv32ui-p-add"
	@echo ""
	@echo "  # Run all benchmarks and compare with golden files"
	@echo "  make run_all_benchmarks"
	@echo ""
	@echo "  # Compare simulation traces with golden files"
	@echo "  make diff_all_benchmarks"
	@echo ""
	@echo "  # List all available benchmarks"
	@echo "  make list_benchmarks"
	@echo ""
	@echo "=========================================="
	@echo "Current Configuration:"
	@echo "=========================================="
	@echo "  CL_ROOT:        $(CL_ROOT)"
	@echo "  BENCH_ROOT:     $(BENCH_ROOT)"
	@echo "  TEST:           $(TEST)"
	@echo "  Benchmarks:     $(words $(ALL_BENCHMARKS)) found"
	@echo "=========================================="

.DEFAULT_GOAL := help
