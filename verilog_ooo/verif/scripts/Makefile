# =============================================================================
# OoO core simulation + verification Makefile
# Adapted from verilog/verif/scripts/Makefile (scalar core). Run from this dir.
#   make help
# =============================================================================
export TEST ?= test_pd

export SCRIPTS_DIR = $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
export CL_ROOT     = $(realpath $(SCRIPTS_DIR)/../..)
export TEST_NAME   = $(CL_ROOT)/verif/tests/$(TEST)

export SIMULATOR = verilator
export SIM_ROOT  = $(CL_ROOT)/verif/sim/$(SIMULATOR)
export SIM_DIR   = $(SIM_ROOT)/$(TEST)

BENCH_ROOT := $(CL_ROOT)/rv32-benchmarks

MEM_PATH              ?= $(BENCH_ROOT)/ooo-tests/ooo-smoke.x
MEM_PATH_NOT_DIR      := $(notdir $(MEM_PATH))
LINE_COUNT            ?= $(shell echo `wc -l < $(MEM_PATH)`)
MEM_PATH_STR          ?= \"$(abspath $(MEM_PATH))\"
MEM_DEPTH             ?= 1048576
TRACE_FILE            ?= $(MEM_PATH_NOT_DIR:x=trace)
VCD_FILE              ?= $(MEM_PATH_NOT_DIR:x=vcd)
VCD_FILE_STR          ?= \"$(VCD_FILE)\"
GEN_TRACE             ?= 1
TIMEOUT               ?= 2000
TRACE_FILE_STR        ?= \"$(TRACE_FILE)\"

# Warning check is OFF by default while the core is incomplete (unconnected
# EX/WB ports produce many warnings). Use WARN=1 to fail the build on warnings.
WARN ?= 0
ifeq ($(WARN), 1)
WARN_OUTPUT = 2>&1 | tee output.log
WARN_CHECK  = cat $(SIM_DIR)/output.log | bash $(SCRIPTS_DIR)/check_warnings.sh
else
WARN_OUTPUT =
WARN_CHECK  =
endif

all: make_sim_dir compile run

include Makefile.verilator

make_sim_dir:
	mkdir -p $(SIM_ROOT)

BENCH_INDIVIDUAL  := $(wildcard $(BENCH_ROOT)/individual-instructions/*.x)
BENCH_SIMPLE      := $(wildcard $(BENCH_ROOT)/simple-programs/*.x)
BENCH_SUPERSCALAR := $(wildcard $(BENCH_ROOT)/superscalar-tests/*.x)
BENCH_OOO         := $(wildcard $(BENCH_ROOT)/ooo-tests/*.x)
BENCH_DIRS        := ooo-tests individual-instructions simple-programs superscalar-tests
# first match of $(BENCH).x across the benchmark suites
BENCH_FILE         = $(firstword $(foreach d,$(BENCH_DIRS),$(wildcard $(BENCH_ROOT)/$(d)/$(BENCH).x)))

TEST_TRACE_DIR   := $(SIM_DIR)
SPIKE_TRACES_DIR := $(CL_ROOT)/verif/spike_traces
SPIKE_TRACE_GEN  := $(SCRIPTS_DIR)/spike_trace_gen.py
CMP_OOO_SPIKE    := $(SCRIPTS_DIR)/cmp_ooo_spike.py
SPIKE_DIFF_DIR   := $(CL_ROOT)/verif/diffs/spike
GOLDEN_DIR       := $(CL_ROOT)/verif/golden_sim
GOLDEN_DIFF_DIR  := $(CL_ROOT)/verif/diffs/sim
DIFF_GEN         := $(SCRIPTS_DIR)/cmp_sim_trace.py
PARALLEL_RUNNER  := $(SCRIPTS_DIR)/run_benchmarks_parallel.py
CMP_FLAGS        ?=
SUITE            ?= all

JOBS ?= $(shell nproc 2>/dev/null || sysctl -n hw.ncpu)

# =====================================================================
# Lint: Verilator --lint-only + Icarus elaboration of pd (RTL from design.f)
#   make lint | lint_verilator | lint_iverilog     VERBOSE=1 for full output
# Prints every %Error plus a per-category warning count; fails only on errors.
# =====================================================================
LINT_SRCS  = $(addprefix $(CL_ROOT)/design/code/, $(SRCLIST))
LINT_LOG   = $(SIM_ROOT)/lint_verilator.log
LINT_TOP  ?= pd
VERBOSE   ?= 0

.PHONY: lint lint_verilator lint_iverilog
lint:
	@status=0; $(MAKE) -s lint_verilator || status=1; echo; $(MAKE) -s lint_iverilog || status=1; exit $$status

lint_verilator:
	@mkdir -p $(SIM_ROOT)
	@echo "=== verilator --lint-only (top: $(LINT_TOP)) ==="
	@verilator --lint-only -Wall -Wno-fatal -Wno-DECLFILENAME -Wno-EOFNEWLINE \
		--top-module $(LINT_TOP) -I$(CL_ROOT)/design/code \
		+define+MEM_PATH='"lint_dummy.x"' +define+LINE_COUNT=1 +define+MEM_DEPTH=$(MEM_DEPTH) \
		$(LINT_SRCS) > $(LINT_LOG) 2>&1; \
	rc=$$?; \
	if [ "$(VERBOSE)" = "1" ]; then cat $(LINT_LOG); else \
		grep -E '^%Error' $(LINT_LOG) | sed 's|$(CL_ROOT)/design/code/||'; \
		echo "--- warning counts ---"; \
		grep -oE '^%Warning-[A-Z0-9_]+' $(LINT_LOG) | sort | uniq -c | sort -rn; fi; \
	nerr=$$(grep -cE '^%Error' $(LINT_LOG)); \
	if [ $$rc -eq 0 ] && [ $$nerr -eq 0 ]; then echo "verilator: OK (no errors)"; \
	else echo "verilator: $$nerr error line(s)  (full log: $(LINT_LOG))"; exit 1; fi

lint_iverilog:
	@echo "=== iverilog -g2012 elaboration (top: $(LINT_TOP)) ==="
	@if iverilog -g2012 -s $(LINT_TOP) -I$(CL_ROOT)/design/code \
		-DMEM_PATH='"lint_dummy.x"' -DLINE_COUNT=1 -DMEM_DEPTH=$(MEM_DEPTH) \
		-o /dev/null $(LINT_SRCS); then echo "iverilog: OK (no errors)"; \
	else echo "iverilog: ERRORS"; exit 1; fi

# Unit testbenches in design/simple_testbenches (Icarus)
.PHONY: unit_tests
unit_tests:
	@$(MAKE) -s -C $(CL_ROOT)/design/simple_testbenches

# =====================================================================
# Benchmarks
# =====================================================================
# Build benchmarks from source (.s/.c -> .elf + .x). Needs riscv64-unknown-elf-* in PATH.
.PHONY: build_benchmarks
build_benchmarks:
	@$(MAKE) -C $(BENCH_ROOT)/ooo-tests -j$(JOBS) all
	@$(MAKE) -C $(BENCH_ROOT)/individual-instructions -f Makefile.new -j$(JOBS) all
	@$(MAKE) -C $(BENCH_ROOT)/simple-programs -f Makefile.iss -j$(JOBS) all
	@$(MAKE) -C $(BENCH_ROOT)/superscalar-tests -f Makefile.new -j$(JOBS) all

# Full flow in parallel: build -> simulate -> spike -> cmp_ooo_spike.py
#   make run_all_benchmarks [SUITE=ooo|individual|simple|superscalar|all] [CMP_FLAGS=...]
.PHONY: run_all_benchmarks run_all_benchmarks_no_build
run_all_benchmarks:
	@python3 $(PARALLEL_RUNNER) --bench-root $(BENCH_ROOT) --scripts-dir $(SCRIPTS_DIR) \
		--cl-root $(CL_ROOT) --jobs $(JOBS) --suite $(SUITE) --timeout $(TIMEOUT) $(CMP_FLAGS)

run_all_benchmarks_no_build:
	@python3 $(PARALLEL_RUNNER) --bench-root $(BENCH_ROOT) --scripts-dir $(SCRIPTS_DIR) \
		--cl-root $(CL_ROOT) --jobs $(JOBS) --suite $(SUITE) --timeout $(TIMEOUT) --skip-build $(CMP_FLAGS)

# Compare a sim trace against its golden trace in verif/golden_sim (regression on OoO timing)
#   make diff_golden MEM_PATH=<x file>
.PHONY: diff_golden
diff_golden:
	@mkdir -p $(GOLDEN_DIFF_DIR)
	@g="$(GOLDEN_DIR)/$(MEM_PATH_NOT_DIR:x=trace)"; \
	if [ ! -f "$$g" ]; then echo "No golden trace: $$g"; exit 1; fi; \
	python3 $(DIFF_GEN) "$(TEST_TRACE_DIR)/$(MEM_PATH_NOT_DIR:x=trace)" "$$g" \
		"$(GOLDEN_DIFF_DIR)/$(MEM_PATH_NOT_DIR:x=diff)" --mismatch-only

.PHONY: build_ooo_tests
build_ooo_tests:
	@$(MAKE) -C $(BENCH_ROOT)/ooo-tests -j$(JOBS) all

# Run one benchmark by name (searches ooo-tests, individual-instructions, simple-programs, superscalar-tests)
# Usage: make run_bench BENCH=ooo-smoke
.PHONY: run_bench
run_bench:
	@if [ -z "$(BENCH)" ]; then echo "ERROR: Set BENCH=<name>"; exit 1; fi
	@if [ -z "$(BENCH_FILE)" ]; then echo "ERROR: $(BENCH).x not found (run make build_benchmarks?)"; exit 1; fi
	@$(MAKE) -s all MEM_PATH=$(BENCH_FILE)

# Spike commit trace for one benchmark. Usage: make gen_spike_trace BENCH=<name>
.PHONY: gen_spike_trace
gen_spike_trace:
	@if [ -z "$(BENCH)" ]; then echo "ERROR: Set BENCH=<name>"; exit 1; fi
	@python3 $(SPIKE_TRACE_GEN) --bench $(BENCH) --bench-root $(BENCH_ROOT) --out-dir $(SPIKE_TRACES_DIR)

# Compare processor trace vs spike for one benchmark. Usage: make diff_spike MEM_PATH=<x file>
.PHONY: diff_spike
diff_spike:
	@mkdir -p $(SPIKE_DIFF_DIR)
	@python3 $(CMP_OOO_SPIKE) $(CMP_FLAGS) \
		"$(TEST_TRACE_DIR)/$(MEM_PATH_NOT_DIR:x=trace)" \
		"$(SPIKE_TRACES_DIR)/$(MEM_PATH_NOT_DIR:x=trace)" \
		--out "$(SPIKE_DIFF_DIR)/$(MEM_PATH_NOT_DIR:x=diff)"

# Simulate + spike trace + compare for one benchmark. Usage: make run_and_verify BENCH=<name>
.PHONY: run_and_verify
run_and_verify:
	@if [ -z "$(BENCH)" ]; then echo "ERROR: Set BENCH=<name>"; exit 1; fi
	@if [ -z "$(BENCH_FILE)" ]; then echo "ERROR: $(BENCH).x not found (run make build_benchmarks?)"; exit 1; fi
	@$(MAKE) -s all MEM_PATH=$(BENCH_FILE)
	@$(MAKE) -s gen_spike_trace BENCH=$(BENCH)
	@$(MAKE) -s diff_spike MEM_PATH=$(BENCH_FILE)

# Waveforms (gtkwave, OoO signal layout in format.gtkw). Usage: make waves BENCH=<name>
.PHONY: waves_bench
waves_bench:
	@if [ -z "$(BENCH_FILE)" ]; then echo "ERROR: $(BENCH).x not found"; exit 1; fi
	@$(MAKE) waves MEM_PATH=$(BENCH_FILE)

.PHONY: list_benchmarks
list_benchmarks:
	@echo "ooo-tests:               $(words $(BENCH_OOO))"
	@for b in $(BENCH_OOO); do echo "  $$(basename $$b .x)"; done
	@echo "individual-instructions: $(words $(BENCH_INDIVIDUAL))"
	@echo "simple-programs:         $(words $(BENCH_SIMPLE))"
	@echo "superscalar-tests:       $(words $(BENCH_SUPERSCALAR))"

.PHONY: help
help:
	@echo "OoO core verification targets (run from verilog_ooo/verif/scripts)"
	@echo ""
	@echo "  make lint [VERBOSE=1]          Verilator lint + Icarus elaboration of pd"
	@echo "  make unit_tests                design/simple_testbenches (Icarus)"
	@echo "  make all [MEM_PATH=<x>]        compile + simulate (default: ooo-tests/ooo-smoke.x)"
	@echo "  make compile | run | clean     individual steps"
	@echo "  make waves_bench BENCH=<name>  simulate with VCD and open gtkwave (format.gtkw)"
	@echo "  make run_bench BENCH=<name>    simulate a benchmark by name"
	@echo "  make run_and_verify BENCH=<n>  simulate + spike trace + cmp_ooo_spike.py"
	@echo "  make gen_spike_trace BENCH=<n> spike commit trace -> verif/spike_traces/"
	@echo "  make diff_spike MEM_PATH=<x>   compare existing sim trace vs spike trace"
	@echo "  make run_all_benchmarks [SUITE=ooo|individual|simple|superscalar|all]"
	@echo "                                 parallel build + sim + spike compare"
	@echo "  make diff_golden MEM_PATH=<x>  compare sim trace vs verif/golden_sim/<bench>.trace"
	@echo "  make build_benchmarks          assemble all four benchmark suites"
	@echo "  make build_ooo_tests           assemble ooo-tests only"
	@echo "  make list_benchmarks"
	@echo ""
	@echo "Variables: TIMEOUT=<cycles> (default 2000)  GEN_TRACE=0|1  VCD=0|1  WARN=0|1"
	@echo "           CMP_FLAGS=--allow-truncated  (sim stopped early; accept a prefix of spike)"
	@echo ""
	@echo "Trace: verif/sim/verilator/test_pd/<bench>.trace  (format: verif/README.md)"

.DEFAULT_GOAL := help
