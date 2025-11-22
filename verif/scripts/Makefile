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
PATTERN_FILE          ?= $(MEM_PATH:x=pattern) # Replace MEM_PATH .x with .pattern by default
PATTERN_LINE_COUNT    ?= $(shell if [ ! -f $(PATTERN_FILE) ]; then echo -1; else echo `wc -l < $(PATTERN_FILE)`; fi)
PATTERN_FILE_STR      ?= \"$(abspath $(PATTERN_FILE))\"
PATTERN_DUMP_FILE			?= $(MEM_PATH_NOT_DIR:x=dump)# Replace MEM_PATH .x with .pattern by default
PATTERN_DUMP_FILE_STR ?= \"$(PATTERN_DUMP_FILE)\"
PATTERN_DUMP					?= 0
PATTERN_CHECK					?= 0
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

EXTRA_PACKAGE_FILES := ./build/design/imemory.v ./build/design/dmemory.v ./build/output/util_est_hier.txt

include ${PROJECT_ROOT}/common/verif/tb/scripts/Makefile.common.inc

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


# Diff mode: sim or board
DIFF_MODE ?= sim
DIFF_DIR := $(CL_ROOT)/verif/diffs
# Set directories for traces and the correct python script for mode
ifeq ($(DIFF_MODE),board)
	TEST_TRACE_DIR := $(CL_ROOT)/build/scripts
	GOLDEN_DIR := $(CL_ROOT)/verif/golden_board
	DIFF_GEN := $(SCRIPTS_DIR)/cmp_board_trace.py
	DIFF_SUBDIR := $(DIFF_DIR)/board
else
	TEST_TRACE_DIR := $(CL_ROOT)/verif/sim/$(SIMULATOR)/test_pd
	GOLDEN_DIR := $(CL_ROOT)/verif/golden_sim
	DIFF_GEN := $(SCRIPTS_DIR)/cmp_sim_trace.py
	DIFF_SUBDIR := $(DIFF_DIR)/sim
endif

# Run all benchmarks
# Run all benchmarks
.PHONY: run_all_benchmarks
run_all_benchmarks:
	@echo "Running all benchmarks..."
	@echo "Found $(words $(ALL_BENCHMARKS)) benchmarks"
	@if [ -z "$(ALL_BENCHMARKS)" ]; then \
		echo "ERROR: No benchmarks found!"; \
		echo "Check paths:"; \
		echo "  $(CL_ROOT)/../../../rv32-benchmarks/individual-instructions/*.x"; \
		echo "  $(CL_ROOT)/../../../rv32-benchmarks/simple-programs/*.x"; \
		exit 1; \
	fi
	@for bench in $(ALL_BENCHMARKS); do \
		echo "Running benchmark: $$bench"; \
		$(MAKE) -s run TEST=test_pd MEM_PATH=$$bench || exit 1; \
	done
	@echo "All benchmarks completed. Running diff comparison..."
	@$(MAKE) -s diff_all_benchmarks

# Pattern rule to run individual benchmarks
$(ALL_BENCHMARKS): %:
	@echo "Running benchmark: $@"
	@$(MAKE) -s run TEST=test_pd MEM_PATH=$@

# Compare all trace files against golden
.PHONY: diff_all_benchmarks
diff_all_benchmarks:
	@echo "Running diff comparison in $(DIFF_MODE) mode..."
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

# Help target
.PHONY: help
help:
	@echo "=========================================="
	@echo "Available Make Targets"
	@echo "=========================================="
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
	@echo "  make run_all_benchmarks     - Run all benchmarks found in rv32-benchmarks directory"
	@echo "  make list_benchmarks        - List all available benchmarks and their paths"
	@echo ""
	@echo "Diff/Comparison Targets:"
	@echo "  make diff_all_benchmarks    - Compare all trace files against golden references"
	@echo "                                Default mode: sim (simulation traces)"
	@echo "                                Board mode: make diff_all_benchmarks DIFF_MODE=board"
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
	@echo "  DIFF_MODE=<sim|board>       - Comparison mode (default: sim)"
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
	@echo "  # Compare board traces with golden files (without running simulation)"
	@echo "  make diff_all_benchmarks DIFF_MODE=board"
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
	@echo "  DIFF_MODE:      $(DIFF_MODE)"
	@echo "  Benchmarks:     $(words $(ALL_BENCHMARKS)) found"
	@echo "=========================================="

.DEFAULT_GOAL := help
