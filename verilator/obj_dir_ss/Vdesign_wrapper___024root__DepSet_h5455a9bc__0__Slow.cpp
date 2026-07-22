// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdesign_wrapper.h for the primary calling header

#include "Vdesign_wrapper__pch.h"
#include "Vdesign_wrapper___024root.h"

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_static(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_initial__TOP(Vdesign_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_initial(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_initial\n"); );
    // Body
    Vdesign_wrapper___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = vlSelf->clock;
}

extern const VlWide<9>/*287:0*/ Vdesign_wrapper__ConstPool__CONST_hff722346_0;

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_initial__TOP(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_initial__TOP\n"); );
    // Init
    CData/*7:0*/ design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9d5c65d5__0;
    design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9d5c65d5__0 = 0;
    IData/*23:0*/ design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0;
    design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0 = 0;
    // Body
    vlSelf->design_wrapper__DOT__core__DOT__imem_rw_w = 0U;
    VL_READMEM_N(true, 32, 262144, 0, VL_CVT_PACK_STR_NW(9, Vdesign_wrapper__ConstPool__CONST_hff722346_0)
                 ,  &(vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__mem)
                 , 0, ~0ULL);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 1U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[1U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 2U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[2U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 3U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[3U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 4U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[4U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 5U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[5U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 6U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[6U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 7U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[7U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 8U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[8U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 9U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[9U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xaU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xaU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xbU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xbU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xcU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xcU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xdU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xdU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xeU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xeU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0xfU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0xfU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x10U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x10U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x11U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x11U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x12U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x12U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x13U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x13U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x14U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x14U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x15U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x15U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x16U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x16U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x17U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x17U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x18U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x18U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x19U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x19U] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1aU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1aU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1bU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1bU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1cU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1cU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1dU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1dU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1eU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1eU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x1fU;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[0x1fU] = 0U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = 0x20U;
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[2U] = 0x1100000U;
    VL_READMEM_N(true, 32, 357, 0, VL_CVT_PACK_STR_NW(9, Vdesign_wrapper__ConstPool__CONST_hff722346_0)
                 ,  &(vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__temp)
                 , 0, ~0ULL);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x165U, vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)) {
        design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9d5c65d5__0 
            = (((0x164U >= (0x1ffU & vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i))
                 ? vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__temp
                [(0x1ffU & vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)]
                 : 0U) >> 0x18U);
        design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0 
            = ((0x164U >= (0x1ffU & vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i))
                ? (0xffffffU & vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__temp
                   [(0x1ffU & vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)])
                : 0U);
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                 & ((IData)(3U) 
                                                                    + 
                                                                    VL_MULS_III(32, (IData)(4U), vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)))] 
            = design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9d5c65d5__0;
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                 & ((IData)(2U) 
                                                                    + 
                                                                    VL_MULS_III(32, (IData)(4U), vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0 
                        >> 0x10U));
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                 & ((IData)(1U) 
                                                                    + 
                                                                    VL_MULS_III(32, (IData)(4U), vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0 
                        >> 8U));
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                 & VL_MULS_III(32, (IData)(4U), vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i))] 
            = (0xffU & design_wrapper__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h2cafa6b6__0);
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i 
            = ((IData)(1U) + vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i);
    }
}

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_final(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__stl(Vdesign_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdesign_wrapper___024root___eval_phase__stl(Vdesign_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_settle(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vdesign_wrapper___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../verilog_ss/design/design_wrapper.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdesign_wrapper___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__stl(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vdesign_wrapper___024root___ico_sequent__TOP__0(Vdesign_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_stl(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vdesign_wrapper___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdesign_wrapper___024root___eval_triggers__stl(Vdesign_wrapper___024root* vlSelf);

VL_ATTR_COLD bool Vdesign_wrapper___024root___eval_phase__stl(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdesign_wrapper___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vdesign_wrapper___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__ico(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__act(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdesign_wrapper___024root___dump_triggers__nba(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdesign_wrapper___024root___ctor_var_reset(Vdesign_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdesign_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdesign_wrapper___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__pc_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__instr_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__instr_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem_in_r = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem_rw_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__imem_en = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_w_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs1_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_w_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__funct7_w_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__imm_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__shamt_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__is_u_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_j_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_i_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_w_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs1_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_w_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__funct7_w_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__imm_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__shamt_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__is_u_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_j_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_i_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__stall_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__stall_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__instr_mw_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__instr_mw_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__reg_wen_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__pc_sel_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_un_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__a_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__b_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__branch_comp_data1_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__branch_comp_data2_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__alu_sel_0 = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__wb_sel_0 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__br_eq_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_lt_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__reg_wen_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__pc_sel_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_un_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__a_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__b_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__branch_comp_data1_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__branch_comp_data2_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__alu_sel_1 = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__br_eq_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_lt_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__br_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs1_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs2_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs1_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs2_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_in1_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_in2_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_out_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_in1_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_in2_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_out_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_rw_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_rw_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__data_rd_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rd_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc8_f_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc8_f_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc_fd_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc_dx_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc_fd_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc_dx_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_dx_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_dx_r_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__imm_dx_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs1_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__funct7_dx_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_dx_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_dx_r_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__imm_dx_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs1_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__funct7_dx_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__pc_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imm_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_xm_r_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__alu_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs2_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_xm_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__pc_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imm_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_xm_r_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__alu_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs2_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_xm_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rs2_xm_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_xm_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__pc_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_mw_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_mw_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__pc_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__opcode_mw_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__addr_rd_mw_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__stall_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__stall_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__stalled_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__prev_instr_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__prev_instr_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__instr_fd_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__instr_fd_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc4_xm_w_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc4_xm_w_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__pc4_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_mw_r_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__pc4_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__alu_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__funct3_mw_r_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs1_stall_w = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_rs2_stall_w = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc_data1_in_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc_idata2_in_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc_idata1_in_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc_idata2_in_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__mem_write_access_size_0 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__mem_write_access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__is_store_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_store_xm_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__stall_occured = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__wm_forward_way0_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__wm_forward_way1_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__wm_forward_way0_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__wm_forward_way1_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dmem_data_in_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem_data_in_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__mem_read_access_size_0 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__mem_read_access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__is_unsigned_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__is_unsigned_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_w_sized_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__data_mem_w_sized_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__address_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__address_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__data_in = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__read_write = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__enable = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__data_out_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__data_out_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__ea_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__ea_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->design_wrapper__DOT__core__DOT__imem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__addr_rd = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__addr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__addr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__shamt = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_u_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_j_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_i_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_i_shift = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___opcode = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___rd = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___funct3 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___rs1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___rs2 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___funct7 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___imm_i = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___imm_s = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___imm_b = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___imm_u = VL_RAND_RESET_I(20);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT___imm_j = VL_RAND_RESET_I(20);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_alu = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_alu_imm = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_load = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_store = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_jal = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_lui = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_auipc = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_r_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_s_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_b_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec1__DOT__is_j_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__addr_rd = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__addr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__addr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__shamt = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_u_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_j_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_i_type_w = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_i_shift = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___opcode = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___rd = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___funct3 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___rs1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___rs2 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___funct7 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___imm_i = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___imm_s = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___imm_b = VL_RAND_RESET_I(12);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___imm_u = VL_RAND_RESET_I(20);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT___imm_j = VL_RAND_RESET_I(20);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_alu = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_alu_imm = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_load = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_store = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_jal = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_lui = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_auipc = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_r_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_s_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_b_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dec2__DOT__is_j_type = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__stall_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__stall_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_w_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_dx_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_xm_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_mw_r_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_w_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_dx_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_xm_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__opcode_mw_r_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rs1_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rs2_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_w_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_mw_r_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rs1_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rs2_w_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_xm_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__addr_rd_mw_r_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_u_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_j_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_i_type_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_u_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_j_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_i_type_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__stall_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__stall_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_mw_writes_reg_0_op = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_mw_writes_reg_1_op = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_load_dx_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_store_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_load_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_nop_mw_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_nop_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_load_dx_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_store_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_load_xm_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_nop_mw_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__is_nop_xm_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__d0_uses_rs1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__d0_uses_rs2_x = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__d1_uses_rs1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__d1_uses_rs2_x = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__load_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__load_stall_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_mw_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_mw_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_xm_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_xm_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_dx_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__instr_dx_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__bypass_to_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__bypass_to_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__wd_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__wd_stall_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__store_rs2_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__store_rs2_stall_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__insn_writes_reg_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__u_stall_signals__DOT__two_way_write_use_case = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__write_enable_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rs1_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rs2_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rd_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rd_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs1_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs2_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__write_enable_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rs1_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rs2_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__addr_rd_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rd_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs1_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs2_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs1_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs2_r_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs1_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs2_r_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__rf1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_dx_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_xm_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_mw_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__funct3_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__funct7_0 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_eq_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_lt_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rs1_dx_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rs2_dx_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rd_xm_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rd_mw_0 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__pc_sel_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_un_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__a_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__b_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__alu_sel_0 = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__mem_rw_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__reg_wen_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__wb_sel_0 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_dx_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_xm_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__opcode_mw_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__funct3_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__funct7_1 = VL_RAND_RESET_I(7);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_eq_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_lt_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rs1_dx_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rs2_dx_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rd_xm_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__addr_rd_mw_1 = VL_RAND_RESET_I(5);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__m_pc_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__x_pc_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__pc_sel_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__br_un_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__a_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__b_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__alu_sel_1 = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__mem_rw_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__reg_wen_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_alu_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_alu_imm_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_auipc_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_lui_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_u_type_x_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_alu_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_alu_imm_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_auipc_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_lui_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_u_type_x_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__stall_occured = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__branch_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_store_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_load_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_wb_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_nop_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_ecall_wb_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__cs1__DOT__is_nop_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc1__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc1__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc1__DOT__br_un = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc1__DOT__br_eq = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc1__DOT__br_lt = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc2__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc2__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__bc2__DOT__br_un = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc2__DOT__br_eq = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__bc2__DOT__br_lt = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__al1__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al1__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al1__DOT__alu_sel = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__al1__DOT__odata = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al1__DOT__mask = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al2__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al2__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al2__DOT__alu_sel = VL_RAND_RESET_I(4);
    vlSelf->design_wrapper__DOT__core__DOT__al2__DOT__odata = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__al2__DOT__mask = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__read_write_0 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__access_size_0 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__address_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__data_in_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__data_out_0 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__read_write_1 = VL_RAND_RESET_I(1);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__address_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__data_in_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__data_out_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 357; ++__Vi0) {
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__temp[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__addr = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__addr_2 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__dmem1__DOT__w0_store_nbytes = VL_RAND_RESET_I(3);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__alu = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__pc4 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__mem = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__wb_sel = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__alu_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__pc4_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__mem_1 = VL_RAND_RESET_I(32);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->design_wrapper__DOT__core__DOT__wb1__DOT__wb_data_1 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
}
