# use `make -n` to view constructed commands
# If you get errors related to verilator's included files not being found, run
# `verilator -V`, retrieve the VERILATOR_ROOT variable, and set the
# VERILATOR_INC variables below to
# VERILATOR_INC = ${VERILATOR_ROOT}/include

MEM_PATH   ?= "../verilog/verif/data/rv32ui-p-add.x"
LINE_COUNT := $(shell wc -l < $(MEM_PATH) | tr -d ' ')
MEM_DEPTH  ?= 1048576

# Variables for paths and flags
VERILATOR = verilator
CXX = g++
CXXFLAGS = -O3 -shared -fPIC
V_SOURCE = "../verilog/design"
V_FLAGS = --public-flat-rw
V_FLAGS += -DMEM_PATH="\$(MEM_PATH)\"
V_FLAGS += -DMEM_DEPTH=$(MEM_DEPTH)
V_FLAGS += -DLINE_COUNT=$(LINE_COUNT)
V_FLAGS += -I../verilog/design/ -I../verilog/design/code/
VERILOG_TOP = ../verilog/design/design_wrapper.v

# Detect OS and set Verilator paths accordingly
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS (Homebrew)
    VERILATOR_INC = /opt/homebrew/share/verilator/include
    CXXFLAGS = -O3 -fPIC -dynamiclib
    LIB_EXT = dylib
else
    # Linux (or other Unix-like systems)
    VERILATOR_INC = /usr/share/verilator/include
    CXXFLAGS = -O3 -shared -fPIC
    LIB_EXT = so
endif
OBJ_DIR = obj_dir
LIB_NAME = libdesign_wrapper.$(LIB_EXT)

# Default target
all: verilog bridge

# Step 1: Run Verilator to generate C++ headers/classes
verilog:
	$(VERILATOR) -cc $(VERILOG_TOP) \
		$(V_FLAGS)

# Step 2: Compile the bridge into a shared library
bridge:
	$(CXX) $(CXXFLAGS) -o $(LIB_NAME) \
		-I $(OBJ_DIR) \
		-I $(VERILATOR_INC) \
		-I $(VERILATOR_INC)/vltstd \
		$(VERILATOR_INC)/verilated.cpp \
		$(VERILATOR_INC)/verilated_threads.cpp \
		$(OBJ_DIR)/Vdesign_wrapper*.cpp \
		bridge.cpp sc_time_stamp.cpp

# Utility to clean up generated verilator, shared library files (not Unity)
clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME)

.PHONY: all verilog bridge clean
