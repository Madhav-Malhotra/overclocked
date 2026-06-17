// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->top__DOT__clkg__DOT__counter = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 
        = vlSelf->top__DOT__clock;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clkg__DOT__clk__0 
        = vlSelf->top__DOT__clkg__DOT__clk;
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9c72a080_0;
extern const VlWide<29>/*927:0*/ Vtop__ConstPool__CONST_h506d871a_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    CData/*7:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h87dbd9f2__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h87dbd9f2__0 = 0;
    IData/*23:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0 = 0;
    // Body
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(8, Vtop__ConstPool__CONST_h9c72a080_0)
                      , std::string{"w"});
    ;
    vlSelf->top__DOT__clkg__DOT__clk = 0U;
    vlSelf->top__DOT__clkg__DOT__rst = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch_en = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__fd_en_0 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__fd_en_1 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_0 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_1 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_0 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_1 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_0 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_1 = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_rw_w = 0U;
    VL_READMEM_N(true, 32, 262144, 0, VL_CVT_PACK_STR_NW(29, Vtop__ConstPool__CONST_h506d871a_0)
                 ,  &(vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem)
                 , 0, ~0ULL);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 1U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[1U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 2U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 3U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[3U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 4U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[4U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 5U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[5U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 6U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[6U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 7U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[7U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 8U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[8U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 9U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[9U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xaU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xaU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xbU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xbU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xcU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xcU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xdU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xdU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xeU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xeU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0xfU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xfU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x10U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x10U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x11U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x11U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x12U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x12U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x13U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x13U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x14U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x14U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x15U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x15U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x16U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x16U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x17U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x17U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x18U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x18U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x19U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x19U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1aU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1aU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1bU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1bU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1cU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1cU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1dU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1dU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1eU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1eU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x1fU;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1fU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = 0x20U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0x1100000U;
    VL_READMEM_N(true, 32, 1024, 0, VL_CVT_PACK_STR_NW(29, Vtop__ConstPool__CONST_h506d871a_0)
                 ,  &(vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp)
                 , 0, ~0ULL);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)) {
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h87dbd9f2__0 
            = (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
               [(0x3ffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)] 
               >> 0x18U);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0 
            = (0xffffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
               [(0x3ffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)]);
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(3U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h87dbd9f2__0;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(2U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0 
                        >> 0x10U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(1U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0 
                        >> 8U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & VL_MULS_III(32, (IData)(4U), vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))] 
            = (0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h789fa2b3__0);
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i 
            = ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
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
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog_ss/verif/tests/test_pd.sv", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h15995b96__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h15995b96__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0 = 0;
    // Body
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_in_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_rw_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__dx_en_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__xm_en_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mw_en_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__dx_en_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__xm_en_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mw_en_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__m_pc_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__x_pc_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w_0 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x_0 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x_1 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0 
           - (IData)(0x1000000U));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr_2 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1 
           - (IData)(0x1000000U));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_0 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_1 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w_1 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea 
        = VL_SHIFTR_III(32,32,32, (vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0 
                                   - (IData)(0x1000000U)), 2U);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_0 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_1 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_0 
        = ((~ (IData)(vlSelf->top__DOT__clkg__DOT__rst)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_1 
        = ((~ (IData)(vlSelf->top__DOT__clkg__DOT__rst)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1));
    vlSelf->top__DOT__reset = vlSelf->top__DOT__clkg__DOT__rst;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_0 
        = (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_1 
        = (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_1 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1));
    vlSelf->top__DOT__clock = vlSelf->top__DOT__clkg__DOT__clk;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm_0 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm_0 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw_0 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_0 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_1 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_1 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_0 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_1 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_1 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_0 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_0 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_0 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_0 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_1 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_1 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_0 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_0 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_1 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_0 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured 
        = (4U == (vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 
                  - vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_0 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_0 
        = (1U & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0) 
                 >> 2U));
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_1 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_1 
        = (1U & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1) 
                 >> 2U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_0)
            ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0))
                     ? 2U : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_1)
            ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1))
                     ? 2U : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_1 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1) 
               | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_lower 
        = (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_0 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0) 
               | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_upper 
        = (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out 
                   >> 0x20U));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea2 
        = ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_1;
    vlSelf->top__DOT__dut__DOT__reset = vlSelf->top__DOT__reset;
    vlSelf->top__DOT__dut__DOT__clock = vlSelf->top__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_1)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg_0 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_0) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_dx_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_0)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_1));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_0) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_1) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_0) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_1)
            ? 0xaU : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_1) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1) 
                          | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_1) 
                             | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_1) 
                                | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_1) 
                                   | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1))))))
                       ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                    ? 0xbU : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                               ? 0xcU
                                               : ((5U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                   ? 0xdU
                                                   : 0xaU)))
                                : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1) 
                                    & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                    ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                        ? 1U : 4U) : 
                                   (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1) 
                                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_1))
                                     ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                         ? 0U : ((1U 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                  ? 2U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                   ? 5U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                    ? 6U
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                     ? 7U
                                                     : 
                                                    (((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                                                      & (0U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                                      ? 3U
                                                      : 
                                                     (((5U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                                                       & (0x20U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                                       ? 4U
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                        ? 8U
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                         ? 9U
                                                         : 0xaU)))))))))
                                     : 0xaU)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1) 
           & ((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
              | (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_0)
            ? 0xaU : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_0) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_0) 
                          | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_0) 
                             | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_0) 
                                | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_0) 
                                   | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0))))))
                       ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                    ? 0xbU : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                               ? 0xcU
                                               : ((5U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                   ? 0xdU
                                                   : 0xaU)))
                                : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                                    & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                    ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                        ? 1U : 4U) : 
                                   (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_0))
                                     ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                         ? 0U : ((1U 
                                                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                  ? 2U
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                   ? 5U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                    ? 6U
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                     ? 7U
                                                     : 
                                                    (((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                                                      & (0U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                                      ? 3U
                                                      : 
                                                     (((5U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                                                       & (0x20U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                                       ? 4U
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                        ? 8U
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                         ? 9U
                                                         : 0xaU)))))))))
                                     : 0xaU)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0) 
           & ((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
              | (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_0 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_0))
            ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_0)
                ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                      >> 7U)))) << 8U) 
                   | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_0))
                ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_0)
                    ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
                : vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_1 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_1))
            ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_1)
                ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1)
                : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1 
                                      >> 7U)))) << 8U) 
                   | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1)))
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_1))
                ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_1)
                    ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1)))
                : vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_lower);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_0 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
                    | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_0) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_0) 
                          | ((IData)(vlSelf->top__DOT__clkg__DOT__rst) 
                             | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_0 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_1 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
                    | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_1) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_1) 
                          | ((IData)(vlSelf->top__DOT__clkg__DOT__rst) 
                             | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_1 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_upper);
    vlSelf->top__DOT__dut__DOT__core__DOT__reset = vlSelf->top__DOT__dut__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__clock = vlSelf->top__DOT__dut__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_1) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1)) 
              & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1))));
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_0) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0)) 
              & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_un 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_un 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_0
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0
                    : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_1
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_1
                    : 0U)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__instr 
        = vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_1 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                    >> 0xfU));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_b 
        = ((0x800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                      >> 0x14U)) | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                               << 3U)) 
                                    | ((0x3f0U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                  >> 8U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_u 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
           >> 0xcU);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_j 
        = ((0x80000U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                        >> 0xcU)) | ((0x7f800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                            >> 0x15U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_1 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                    >> 7U));
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_1 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
           >> 0x19U);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                    >> 0x14U));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_i 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
           >> 0x14U);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1 
        = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                 >> 0xcU));
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1 
        = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_1;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
        = vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b 
        = ((0x800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                      >> 0x14U)) | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                               << 3U)) 
                                    | ((0x3f0U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                  >> 8U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
           >> 0xcU);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
        = ((0x80000U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                        >> 0xcU)) | ((0x7f800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                            >> 0x15U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_0 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                    >> 7U));
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_0 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
           >> 0x19U);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                    >> 0xfU));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
           >> 0x14U);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0 
        = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                 >> 0xcU));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                    >> 0x14U));
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0 
        = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reset 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_0)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_1)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_s 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_1) 
            << 5U) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__shamt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_store 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_branch 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_lui 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_auipc 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_load 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_jalr 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_ecall 
        = ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1)) 
           & ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1)) 
              & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_i))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu_imm 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0 
        = ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
             == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1)) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0))
            ? 4U : ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1)) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0))
                     ? 3U : ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1)) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0))
                              ? 2U : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_0) 
            << 5U) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__shamt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h15995b96__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall 
        = ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0)) 
           & ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0)) 
              & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_r_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_s_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_b_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_branch;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_jal 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_lui) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_auipc));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_shift 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu_imm) 
           & ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1)) 
              | (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu_imm) 
           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_load) 
              | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_jalr) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_ecall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0))
            ? 5U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0))
                     ? 4U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0))
                              ? 3U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0) 
                                       & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0))
                                       ? 2U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0)
                                                ? 0U
                                                : 1U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0)
            ? 5U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0)
                     ? 4U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0)
                              ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0)
                                       ? 2U : 0U))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_0)))
            ? 1U : (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0)) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0))
                     ? 5U : (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0)) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0))
                              ? 4U : (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0)) 
                                       & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0))
                                       ? 3U : (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0)) 
                                                & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0))
                                                ? 2U
                                                : 0U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0)
            ? 5U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0)
                     ? 4U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0)
                              ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0)
                                       ? 2U : 0U))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0 
        = ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
             == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1)) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0))
            ? 5U : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_r_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_b_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_fd_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_s_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
           & ((IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h15995b96__0) 
              & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm_0)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm_0) 
           & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0)) 
                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h15995b96__0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           & ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0)) 
              | (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load) 
              | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jal 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu)
            ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_shift)
                     ? (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1)
                     : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type_w)
                         ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                         >> 0x1fU))) 
                             << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_i))
                         : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_store)
                             ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                             >> 0x1fU))) 
                                 << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_s))
                             : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_branch)
                                 ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                 >> 0x1fU))) 
                                     << 0xdU) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_b) 
                                                 << 1U))
                                 : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type_w)
                                     ? (vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_u 
                                        << 0xcU) : 
                                    ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w)
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                      >> 0x1fU))) 
                                          << 0x15U) 
                                         | (vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_j 
                                            << 1U))
                                      : 0U)))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0 
        = ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0
            : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                    : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                        : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0))
                            ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                            : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                    : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                        : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
        = ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0
            : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                    : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                        : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0))
                            ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                            : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                    : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                        : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_1) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1)))
            ? 1U : (((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_1) 
                         | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1))) 
                     & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured))
                     ? (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0)
                     : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured)
            ? (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0)
            : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu)
            ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift)
                     ? (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0)
                     : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)
                         ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                         >> 0x1fU))) 
                             << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))
                         : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)
                             ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                             >> 0x1fU))) 
                                 << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s))
                             : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch)
                                 ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                 >> 0x1fU))) 
                                     << 0xdU) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b) 
                                                 << 1U))
                                 : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)
                                     ? (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
                                        << 0xcU) : 
                                    ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                      >> 0x1fU))) 
                                          << 0x15U) 
                                         | (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
                                            << 1U))
                                      : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                 & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__imm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                ? ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                    ? 0U : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                             ? ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                                 ? 0xffffffffU : VL_DIV_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                             : ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0) 
                                                   & (0xffffffffU 
                                                      == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)))))
                : ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                    ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                        ? VL_MULS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        : vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                        ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                           & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                           | vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0))));
    } else if ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))) {
        if ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       ^ vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                        < vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        ? 1U : 0U));
        } else if ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                   >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0));
            if ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                 >> 0x1fU)) {
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)));
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                       | vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       << (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)))
                : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       - vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       + vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0)));
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0 
           == vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_0)
            ? (vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0 
               < vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0)
            : VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0, vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
        = ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1
            : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                    : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                        : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1))
                            ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                            : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1)
            ? (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1)
            : 1U);
    if ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
    } else if ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
    } else if ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
    } else if ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__imm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__load_stall_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_0) 
           & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0)) 
               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0)) 
              | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0)) 
                 & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                    & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                       & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)) 
                          & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall_0 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw_0)) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
               != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                  != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0)) 
                 & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0) 
                    & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0)) 
                        & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0)) 
                           & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0))) 
                       | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0)) 
                          & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0)) 
                             & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                                & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                                   & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)))))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
               | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                     | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                            & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                           | ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))))))))) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1 
        = ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1
            : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                    : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                        : ((5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1))
                            ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                            : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
           == vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_1)
            ? (vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
               < vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1)
            : VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1, vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = 
        ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_stall_0) 
         | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall_0) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall_0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__mask = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
            = ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                ? ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                    ? 0U : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                             ? ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                                 ? 0xffffffffU : VL_DIV_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                             : ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1) 
                                                   & (0xffffffffU 
                                                      == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)))))
                : ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                    ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                        ? VL_MULS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        : vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                        ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                           & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                           | vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1))));
    } else if ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))) {
        if ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
                = ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       ^ vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                        < vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        ? 1U : 0U));
        } else if ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
                = (VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                   >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1));
            if ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                 >> 0x1fU)) {
                vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)));
                vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
                       | vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata 
            = ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       << (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)))
                : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       - vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       + vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1)));
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq)) 
               | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt)) 
                     | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                            & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt)) 
                           | ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))))))))) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable 
        = (1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_1;
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: Internal 'ico' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: Internal 'act' trigger - DPI export trigger\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge top.clock)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge top.clkg.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge top.clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: Internal 'nba' trigger - DPI export trigger\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge top.clock)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge top.clkg.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge top.clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->top__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__clkg__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__clkg__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__clkg__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__fetch_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__fd_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__fd_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dx_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__xm_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__mw_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_upper = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_lower = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_in_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_rw_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel_0 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel_0 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel_1 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_dx_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__load_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_stall_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_stall_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_data1_in_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_0 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_0 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__enable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__address_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__shamt = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___opcode = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct7 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u = VL_RAND_RESET_I(20);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j = VL_RAND_RESET_I(20);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jal = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_r_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_s_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_b_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__addr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__shamt = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type_w = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_shift = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___opcode = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___funct3 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___funct7 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_i = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_s = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_b = VL_RAND_RESET_I(12);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_u = VL_RAND_RESET_I(20);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT___imm_j = VL_RAND_RESET_I(20);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_alu_imm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_load = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_store = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_jal = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_lui = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_auipc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_ecall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_r_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_s_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_b_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_u_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec2__DOT__is_j_type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__dx_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__xm_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mw_en_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_0 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_0 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__dx_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__xm_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mw_en_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_1 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw_1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__m_pc_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__x_pc_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel_1 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_un = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_un = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_eq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc2__DOT__br_lt = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__alu_sel = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__idata1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__idata2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__alu_sel = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__odata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__al2__DOT__mask = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel_1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data_1 = VL_RAND_RESET_I(32);
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clkg__DOT__clk__0 = VL_RAND_RESET_I(1);
}
