// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdesign_wrapper__pch.h"

//============================================================
// Constructors

Vdesign_wrapper::Vdesign_wrapper(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdesign_wrapper__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdesign_wrapper::Vdesign_wrapper(const char* _vcname__)
    : Vdesign_wrapper(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdesign_wrapper::~Vdesign_wrapper() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdesign_wrapper___024root___eval_debug_assertions(Vdesign_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
void Vdesign_wrapper___024root___eval_static(Vdesign_wrapper___024root* vlSelf);
void Vdesign_wrapper___024root___eval_initial(Vdesign_wrapper___024root* vlSelf);
void Vdesign_wrapper___024root___eval_settle(Vdesign_wrapper___024root* vlSelf);
void Vdesign_wrapper___024root___eval(Vdesign_wrapper___024root* vlSelf);

void Vdesign_wrapper::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdesign_wrapper::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdesign_wrapper___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdesign_wrapper___024root___eval_static(&(vlSymsp->TOP));
        Vdesign_wrapper___024root___eval_initial(&(vlSymsp->TOP));
        Vdesign_wrapper___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdesign_wrapper___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdesign_wrapper::eventsPending() { return false; }

uint64_t Vdesign_wrapper::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdesign_wrapper::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdesign_wrapper___024root___eval_final(Vdesign_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vdesign_wrapper::final() {
    Vdesign_wrapper___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdesign_wrapper::hierName() const { return vlSymsp->name(); }
const char* Vdesign_wrapper::modelName() const { return "Vdesign_wrapper"; }
unsigned Vdesign_wrapper::threads() const { return 1; }
void Vdesign_wrapper::prepareClone() const { contextp()->prepareClone(); }
void Vdesign_wrapper::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vdesign_wrapper::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdesign_wrapper::trace()' called on model that was Verilated without --trace option");
}
