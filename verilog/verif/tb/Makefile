DESIGN_DIR := ../../design/code
BUILD_DIR  := build

VERILATOR_FLAGS := --binary --timing -Wall \
    +1364-2005ext+v +1800-2012ext+sv \
    -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-EOFNEWLINE

.PHONY: all tb_mult tb_div clean

all: tb_mult tb_div

tb_mult: $(BUILD_DIR)/Vtb_multiplier
	@echo ""
	@echo "===== Running Multiplier Testbench ====="
	@$(BUILD_DIR)/Vtb_multiplier

tb_div: $(BUILD_DIR)/Vtb_divider
	@echo ""
	@echo "===== Running Divider Testbench ====="
	@$(BUILD_DIR)/Vtb_divider

$(BUILD_DIR)/Vtb_multiplier: tb_multiplier.sv $(DESIGN_DIR)/fu_multiplier.v
	@mkdir -p $(BUILD_DIR)
	verilator $(VERILATOR_FLAGS) \
		--Mdir $(BUILD_DIR)/mult_obj \
		-o ../Vtb_multiplier \
		$(DESIGN_DIR)/fu_multiplier.v \
		tb_multiplier.sv

$(BUILD_DIR)/Vtb_divider: tb_divider.sv $(DESIGN_DIR)/fu_divider.v
	@mkdir -p $(BUILD_DIR)
	verilator $(VERILATOR_FLAGS) \
		--Mdir $(BUILD_DIR)/div_obj \
		-o ../Vtb_divider \
		$(DESIGN_DIR)/fu_divider.v \
		tb_divider.sv

clean:
	rm -rf $(BUILD_DIR)
