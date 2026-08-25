# use `make -n` to view constructed commands
# If you get errors related to verilator's included files not being found, run
# `verilator -V`, retrieve the VERILATOR_ROOT variable, and set the
# VERILATOR_INC variables below to
# VERILATOR_INC = ${VERILATOR_ROOT}/include

MEM_PATH   ?= "../verilog/verif/data/rv32ui-p-add.x"
LINE_COUNT := $(strip $(shell wc -l < $(MEM_PATH)))
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

SS_V_FLAGS = --public-flat-rw
SS_V_FLAGS += -DMEM_PATH="\$(MEM_PATH)\"
SS_V_FLAGS += -DMEM_DEPTH=$(MEM_DEPTH)
SS_V_FLAGS += -DLINE_COUNT=$(LINE_COUNT)
SS_V_FLAGS += -I../verilog_ss/design/ -I../verilog_ss/design/code/
SS_VERILOG_TOP = ../verilog_ss/design/design_wrapper.v
SS_OBJ_DIR = "obj_dir_ss"
SS_LIB_NAME = libdesign_wrapper_ss.$(LIB_EXT)

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
UNITY_PLUGINS_DIR ?= ../unity/Assets/Plugins
MINGW_CXX = x86_64-w64-mingw32-g++

# Default target
all: verilog bridge dll

# Step 1: Run Verilator to generate C++ headers/classes
verilog:
	# basic pipeline
	$(VERILATOR) -cc $(VERILOG_TOP) \
		$(V_FLAGS)
	# superscalar
	$(VERILATOR) -cc $(SS_VERILOG_TOP) -Mdir $(SS_OBJ_DIR)\
		$(SS_V_FLAGS)

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
	$(CXX) $(CXXFLAGS) -o $(SS_LIB_NAME) \
		-I $(SS_OBJ_DIR) \
		-I $(VERILATOR_INC) \
		-I $(VERILATOR_INC)/vltstd \
		$(VERILATOR_INC)/verilated.cpp \
		$(VERILATOR_INC)/verilated_threads.cpp \
		$(SS_OBJ_DIR)/Vdesign_wrapper*.cpp \
		bridge_superscalar.cpp
	cp $(SS_LIB_NAME) $(UNITY_PLUGINS_DIR)/$(SS_LIB_NAME)

# Build a Windows DLL (via MinGW cross-compiler) and copy it to Unity's Plugins folder.
# Run this from WSL when bridge.cpp changes and Unity is running on Windows.
# WARNING: Unity must be closed before this command will succeed
dll:
	$(MINGW_CXX) -O3 -shared -o design_wrapper.dll \
		-I $(OBJ_DIR) \
		-I $(VERILATOR_INC) \
		-I $(VERILATOR_INC)/vltstd \
		$(VERILATOR_INC)/verilated.cpp \
		$(VERILATOR_INC)/verilated_threads.cpp \
		$(OBJ_DIR)/Vdesign_wrapper*.cpp \
		bridge.cpp
	cp design_wrapper.dll $(UNITY_PLUGINS_DIR)/design_wrapper.dll
	$(MINGW_CXX) -O3 -shared -o design_wrapper_ss.dll \
		-I $(SS_OBJ_DIR) \
		-I $(VERILATOR_INC) \
		-I $(VERILATOR_INC)/vltstd \
		$(VERILATOR_INC)/verilated.cpp \
		$(VERILATOR_INC)/verilated_threads.cpp \
		$(SS_OBJ_DIR)/Vdesign_wrapper*.cpp \
		bridge_superscalar.cpp
	cp design_wrapper_ss.dll $(UNITY_PLUGINS_DIR)/design_wrapper_ss.dll

# Utility to clean up generated verilator, shared library files (not Unity)
clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME) design_wrapper.dll $(SS_OBJ_DIR) $(SS_LIB_NAME) design_wrapper_ss.dll

.PHONY: all verilog bridge dll clean
