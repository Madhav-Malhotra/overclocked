# use `make -n` to view constructed commands

# Variables for paths and flags
VERILATOR = verilator
CXX = g++
CXXFLAGS = -O3 -shared -fPIC
V_FLAGS = -DMEM_DEPTH=1048576 --public-flat-rw
VERILOG_SOURCE = code
VERILOG_TOP = design_wrapper.v

# Verilator paths (Adjust /usr/share if your install is elsewhere)
VERILATOR_INC = /usr/share/verilator/include
OBJ_DIR = obj_dir
LIB_NAME = libdesign_wrapper.so

# Default target
all: verilog bridge

# Step 1: Run Verilator to generate C++ headers/classes
verilog:
	$(VERILATOR) -cc $(VERILOG_TOP) \
		$(V_FLAGS) \
		-I$(VERILOG_SOURCE)

# Step 2: Compile the bridge into a shared library
bridge:
	$(CXX) $(CXXFLAGS) -o $(LIB_NAME) \
		-I $(OBJ_DIR) \
		-I $(VERILATOR_INC) \
		-I $(VERILATOR_INC)/vltstd \
		$(VERILATOR_INC)/verilated.cpp \
		$(VERILATOR_INC)/verilated_threads.cpp \
		$(OBJ_DIR)/Vdesign_wrapper*.cpp \
		bridge.cpp

# Utility to clean up generated verilator, shared library files (not Unity)
clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME)

.PHONY: all verilog bridge clean
