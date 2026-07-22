// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdesign_wrapper.h for the primary calling header

#include "Vdesign_wrapper__pch.h"
#include "Vdesign_wrapper__Syms.h"
#include "Vdesign_wrapper___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__stl(Vdesign_wrapper___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_triggers__stl(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdesign_wrapper___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
