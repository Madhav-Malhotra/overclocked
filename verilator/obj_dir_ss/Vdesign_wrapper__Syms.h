// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDESIGN_WRAPPER__SYMS_H_
#define VERILATED_VDESIGN_WRAPPER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdesign_wrapper.h"

// INCLUDE MODULE CLASSES
#include "Vdesign_wrapper___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdesign_wrapper__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdesign_wrapper* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdesign_wrapper___024root      TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_design_wrapper;
    VerilatedScope __Vscope_design_wrapper__core;
    VerilatedScope __Vscope_design_wrapper__core__al1;
    VerilatedScope __Vscope_design_wrapper__core__al2;
    VerilatedScope __Vscope_design_wrapper__core__bc1;
    VerilatedScope __Vscope_design_wrapper__core__bc2;
    VerilatedScope __Vscope_design_wrapper__core__cs1;
    VerilatedScope __Vscope_design_wrapper__core__dec1;
    VerilatedScope __Vscope_design_wrapper__core__dec2;
    VerilatedScope __Vscope_design_wrapper__core__dmem1;
    VerilatedScope __Vscope_design_wrapper__core__imem1;
    VerilatedScope __Vscope_design_wrapper__core__rf1;
    VerilatedScope __Vscope_design_wrapper__core__u_stall_signals;
    VerilatedScope __Vscope_design_wrapper__core__wb1;

    // CONSTRUCTORS
    Vdesign_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vdesign_wrapper* modelp);
    ~Vdesign_wrapper__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
