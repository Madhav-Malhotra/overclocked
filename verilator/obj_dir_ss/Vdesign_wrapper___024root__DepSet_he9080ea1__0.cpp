// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdesign_wrapper.h for the primary calling header

#include "Vdesign_wrapper__pch.h"
#include "Vdesign_wrapper__Syms.h"
#include "Vdesign_wrapper___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__ico(Vdesign_wrapper___024root* vlSelf);
#endif  // VL_DEBUG

void Vdesign_wrapper___024root___eval_triggers__ico(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdesign_wrapper___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__act(Vdesign_wrapper___024root* vlSelf);
#endif  // VL_DEBUG

void Vdesign_wrapper___024root___eval_triggers__act(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdesign_wrapper___024root___dump_triggers__act(vlSelf);
    }
#endif
}
