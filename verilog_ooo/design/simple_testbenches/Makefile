# Unit testbenches for the OoO core (Icarus Verilog).
#   make            build + run every *_tb.v, print a summary (non-zero exit on any failure)
#   make <name>     run one TB, e.g. make reg_status_table
#   make RTL=<dir>  test RTL from another directory (default: ../code)
#
# Each TB lists the RTL files it needs in TB_SRCS_<name> below.

RTL   ?= ../code
BUILD ?= build
IVERILOG = iverilog -g2012 -Wall -Wno-timescale -I. -I$(RTL)
DEFS  = -DMEM_PATH=\"unit_tb_dummy.x\" -DLINE_COUNT=1 -DMEM_DEPTH=1048576

TB_SRCS_reg_status_table  = $(RTL)/reg_status_table.v
TB_SRCS_instr_status      = $(RTL)/instr_status.v
TB_SRCS_func_unit_status  = $(RTL)/func_unit_status.v $(RTL)/min_pc_select.v
TB_SRCS_min_pc_select     = $(RTL)/min_pc_select.v
TB_SRCS_decoder           = $(RTL)/decoder.v
TB_SRCS_alu               = $(RTL)/alu.v
TB_SRCS_branch_comp       = $(RTL)/branch_comp.v $(RTL)/control_signals.v
TB_SRCS_control_signals   = $(RTL)/control_signals.v
TB_SRCS_array_mult        = $(RTL)/array_mult.v
TB_SRCS_load              = $(RTL)/load.v $(RTL)/dmemory.v
TB_SRCS_store             = $(RTL)/store.v $(RTL)/dmemory.v

TBS = $(patsubst %_tb.v,%,$(wildcard *_tb.v))

.PHONY: all clean $(TBS)
all:
	@mkdir -p $(BUILD); pass=0; fail=0; failed=""; \
	for t in $(TBS); do \
	  if $(MAKE) -s $$t >$(BUILD)/$$t.log 2>&1; then pass=$$((pass+1)); grep -m1 "^PASS" $(BUILD)/$$t.log; \
	  else fail=$$((fail+1)); failed="$$failed $$t"; echo "FAIL: $$t (log: $(BUILD)/$$t.log)"; fi; \
	done; \
	echo "unit TBs: $$pass passed, $$fail failed$${failed:+ ->$$failed}"; \
	[ $$fail -eq 0 ]

$(TBS):
	@mkdir -p $(BUILD)
	$(IVERILOG) $(DEFS) -s $@_tb -o $(BUILD)/$@.vvp $@_tb.v $(TB_SRCS_$@)
	vvp -N $(BUILD)/$@.vvp

clean:
	rm -rf $(BUILD)
