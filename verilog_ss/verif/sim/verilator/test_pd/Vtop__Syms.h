// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using Vtop__Vcb_toggleClock_t = void (*) (Vtop__Syms* __restrict vlSymsp);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_top;
    VerilatedScope __Vscope_top__clkg;
    VerilatedScope __Vscope_top__dut;
    VerilatedScope __Vscope_top__dut__core;
    VerilatedScope __Vscope_top__dut__core__al1;
    VerilatedScope __Vscope_top__dut__core__al2;
    VerilatedScope __Vscope_top__dut__core__bc1;
    VerilatedScope __Vscope_top__dut__core__bc2;
    VerilatedScope __Vscope_top__dut__core__cs1;
    VerilatedScope __Vscope_top__dut__core__dec1;
    VerilatedScope __Vscope_top__dut__core__dec2;
    VerilatedScope __Vscope_top__dut__core__dmem1;
    VerilatedScope __Vscope_top__dut__core__imem1;
    VerilatedScope __Vscope_top__dut__core__rf1;
    VerilatedScope __Vscope_top__dut__core__wb1;
    VerilatedScope __Vscope_top__genblk1;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
