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
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = 0U;
}

extern const VlWide<28>/*895:0*/ Vtop__ConstPool__CONST_hfd257b65_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT__i;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0;
    CData/*7:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hffbf6eb7__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hffbf6eb7__0 = 0;
    IData/*23:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0 = 0;
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x72616365U;
    __Vtemp_1[1U] = 0x524e2e74U;
    __Vtemp_1[2U] = 0x752d5741U;
    __Vtemp_1[3U] = 0x702d6c62U;
    __Vtemp_1[4U] = 0x3275692dU;
    __Vtemp_1[5U] = 0x727633U;
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(6, __Vtemp_1)
                      , std::string{"w"});
    ;
    vlSelf->top__DOT__clock = 0U;
    vlSelf->top__DOT__reset = 1U;
    VL_READMEM_N(true, 32, 262144, 0, VL_CVT_PACK_STR_NW(28, Vtop__ConstPool__CONST_hfd257b65_0)
                 ,  &(vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem)
                 , 0, ~0ULL);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[1U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[3U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[4U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[5U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[6U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[7U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[8U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[9U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xaU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xbU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xcU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xdU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xeU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0xfU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x10U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x11U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x12U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x13U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x14U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x15U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x16U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x17U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x18U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x19U] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1aU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1bU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1cU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1dU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1eU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1fU] = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0x1100000U;
    VL_READMEM_N(true, 32, 145, 0, VL_CVT_PACK_STR_NW(28, Vtop__ConstPool__CONST_hfd257b65_0)
                 ,  &(vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp)
                 , 0, ~0ULL);
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x91U, top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)) {
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hffbf6eb7__0 
            = (((0x90U >= (0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                 ? vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                [(0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)]
                 : 0U) >> 0x18U);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0 
            = ((0x90U >= (0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                ? (0xffffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                   [(0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)])
                : 0U);
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(3U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hffbf6eb7__0;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(2U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0 
                        >> 0x10U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(1U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0 
                        >> 8U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))] 
            = (0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h9254a72b__0);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT__i 
            = ((IData)(1U) + top__DOT__dut__DOT__core__DOT__dmem1__DOT__i);
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
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_u_type_0;
    top__DOT__dut__DOT__core__DOT__is_u_type_0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_i_type_0;
    top__DOT__dut__DOT__core__DOT__is_i_type_0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_u_type_1;
    top__DOT__dut__DOT__core__DOT__is_u_type_1 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_i_type_1;
    top__DOT__dut__DOT__core__DOT__is_i_type_1 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__a_sel_0;
    top__DOT__dut__DOT__core__DOT__a_sel_0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__b_sel_0;
    top__DOT__dut__DOT__core__DOT__b_sel_0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0;
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0;
    top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0 = 0;
    CData/*3:0*/ top__DOT__dut__DOT__core__DOT__alu_sel_0;
    top__DOT__dut__DOT__core__DOT__alu_sel_0 = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__wb_sel_0;
    top__DOT__dut__DOT__core__DOT__wb_sel_0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_eq_0;
    top__DOT__dut__DOT__core__DOT__br_eq_0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_lt_0;
    top__DOT__dut__DOT__core__DOT__br_lt_0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__a_sel_1;
    top__DOT__dut__DOT__core__DOT__a_sel_1 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__b_sel_1;
    top__DOT__dut__DOT__core__DOT__b_sel_1 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1;
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1 = 0;
    CData/*3:0*/ top__DOT__dut__DOT__core__DOT__alu_sel_1;
    top__DOT__dut__DOT__core__DOT__alu_sel_1 = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__wb_sel_1;
    top__DOT__dut__DOT__core__DOT__wb_sel_1 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_eq_1;
    top__DOT__dut__DOT__core__DOT__br_eq_1 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_lt_1;
    top__DOT__dut__DOT__core__DOT__br_lt_1 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in1_w_0;
    top__DOT__dut__DOT__core__DOT__alu_in1_w_0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in2_w_0;
    top__DOT__dut__DOT__core__DOT__alu_in2_w_0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in1_w_1;
    top__DOT__dut__DOT__core__DOT__alu_in1_w_1 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in2_w_1;
    top__DOT__dut__DOT__core__DOT__alu_in2_w_1 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0;
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1;
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc_data1_in_0;
    top__DOT__dut__DOT__core__DOT__bc_data1_in_0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc_idata2_in_0;
    top__DOT__dut__DOT__core__DOT__bc_idata2_in_0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc_idata1_in_1;
    top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc_idata2_in_1;
    top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_hcdb0a71f__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hcdb0a71f__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_hbd812b30__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hbd812b30__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured = 0;
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
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0 = 0;
    CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc88387d2__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc88387d2__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__al1__DOT__mask;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__al2__DOT__mask;
    top__DOT__dut__DOT__core__DOT__al2__DOT__mask = 0;
    CData/*0:0*/ __VdfgTmp_h23a26853__0;
    __VdfgTmp_h23a26853__0 = 0;
    // Body
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_0 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_1 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0 
        = ((0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
           | (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0 
        = ((0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
           | (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    top__DOT__dut__DOT__core__DOT__alu_sel_0 = ((0x37U 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0))
                                                 ? 0xaU
                                                 : 
                                                (((0x17U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                  | ((0x6fU 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                     | ((0x67U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                        | ((3U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                           | ((0x23U 
                                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                              | (0x63U 
                                                                 == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)))))))
                                                  ? 0U
                                                  : 
                                                 (((0x33U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                   & (1U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                    ? 0xbU
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                     ? 0xcU
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                      ? 0xdU
                                                      : 0xaU)))
                                                   : 
                                                  (((0x33U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                    & (0x20U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                     ? 1U
                                                     : 4U)
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                     | (0x13U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))
                                                      ? 0U
                                                      : 
                                                     ((1U 
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
    top__DOT__dut__DOT__core__DOT__alu_sel_1 = ((0x37U 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1))
                                                 ? 0xaU
                                                 : 
                                                (((0x17U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                  | ((0x6fU 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                     | ((0x67U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                        | ((3U 
                                                            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                           | ((0x23U 
                                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                              | (0x63U 
                                                                 == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)))))))
                                                  ? 0U
                                                  : 
                                                 (((0x33U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                   & (1U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                    ? 0xbU
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                     ? 0xcU
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                      ? 0xdU
                                                      : 0xaU)))
                                                   : 
                                                  (((0x33U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                    & (0x20U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                     ? 1U
                                                     : 4U)
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                     | (0x13U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))
                                                      ? 0U
                                                      : 
                                                     ((1U 
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
    __VdfgTmp_h23a26853__0 = ((0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                              | (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0 
        = (1U & (~ ((0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                    | (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0 
        = ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
               & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)))) 
           & ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                  | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                     | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0))))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0 
        = ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
               & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)))) 
           & ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
                  | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
                     | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1))))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1))));
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)));
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured 
        = (4U == (vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 
                  - vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1);
    top__DOT__dut__DOT__core__DOT__wb_sel_0 = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_0)
                                                ? 0U
                                                : (
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0) 
                                                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0))
                                                    ? 2U
                                                    : 1U));
    top__DOT__dut__DOT__core__DOT__wb_sel_1 = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_1)
                                                ? 0U
                                                : (
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1) 
                                                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1))
                                                    ? 2U
                                                    : 1U));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_1));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0 
        = (1U & (~ ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)) 
                     | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
                        | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
                           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1))))) 
                    & ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)))) 
                       & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1)))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0 
        = (1U & (~ ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
                     | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)) 
                        | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
                           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0))))) 
                    & ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)))) 
                       & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0)))));
    top__DOT__dut__DOT__core__DOT__is_i_type_0 = ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                  | ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                     | ((0x67U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                        | (IData)(
                                                                  (0x73U 
                                                                   == 
                                                                   (0xfff0707fU 
                                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0))))));
    top__DOT__dut__DOT__core__DOT__is_u_type_0 = ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                  | (0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)));
    top__DOT__dut__DOT__core__DOT__is_i_type_1 = ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                  | ((3U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                     | ((0x67U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                        | (IData)(
                                                                  (0x73U 
                                                                   == 
                                                                   (0xfff0707fU 
                                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1))))));
    top__DOT__dut__DOT__core__DOT__is_u_type_1 = ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                  | (0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0 
        = ((0U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_0))
            ? ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0)))
                ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0))
                    ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 
                                          >> 7U)))) 
                        << 8U) | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0)))
                : ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0)))
                    ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0))
                        ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0)
                        : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0)))
                    : vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0))
            : ((1U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0
                : ((2U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0
                    : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1 
        = ((0U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_1))
            ? ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1)))
                ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1))
                    ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 
                                          >> 7U)))) 
                        << 8U) | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1)))
                : ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1)))
                    ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1))
                        ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1)
                        : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1)))
                    : vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1))
            : ((1U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_1))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1
                : ((2U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel_1))
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1))));
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0 
        = ((0x33U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0))
            ? 0U : (((0x13U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                     & ((1U == (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                      >> 0xcU))) | 
                        (5U == (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                      >> 0xcU))))) ? 
                    (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                              >> 0x14U)) : ((IData)(top__DOT__dut__DOT__core__DOT__is_i_type_0)
                                             ? (((- (IData)(
                                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                   >> 0x14U))
                                             : ((0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0))
                                                 ? 
                                                (((- (IData)(
                                                             (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                          >> 7U))))
                                                 : 
                                                ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                               >> 0x1fU))) 
                                                   << 0xdU) 
                                                  | ((0x1000U 
                                                      & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                         >> 0x13U)) 
                                                     | ((0x800U 
                                                         & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                            << 4U)) 
                                                        | ((0x7e0U 
                                                            & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                               >> 0x14U)) 
                                                           | (0x1eU 
                                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                                 >> 7U))))))
                                                  : 
                                                 ((IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                                 >> 0x1fU))) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                           >> 0xbU)) 
                                                       | ((0xff000U 
                                                           & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0) 
                                                          | ((0x800U 
                                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                                 >> 9U)) 
                                                             | (0x7feU 
                                                                & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                                   >> 0x14U))))))
                                                    : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0 
        = ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
           & (0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1 
        = ((0x33U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1))
            ? 0U : (((0x13U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                     & ((1U == (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                      >> 0xcU))) | 
                        (5U == (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                      >> 0xcU))))) ? 
                    (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                              >> 0x14U)) : ((IData)(top__DOT__dut__DOT__core__DOT__is_i_type_1)
                                             ? (((- (IData)(
                                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                   >> 0x14U))
                                             : ((0x23U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1))
                                                 ? 
                                                (((- (IData)(
                                                             (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                          >> 7U))))
                                                 : 
                                                ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                               >> 0x1fU))) 
                                                   << 0xdU) 
                                                  | ((0x1000U 
                                                      & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                         >> 0x13U)) 
                                                     | ((0x800U 
                                                         & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                            << 4U)) 
                                                        | ((0x7e0U 
                                                            & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                               >> 0x14U)) 
                                                           | (0x1eU 
                                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                                 >> 7U))))))
                                                  : 
                                                 ((IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                                 >> 0x1fU))) 
                                                     << 0x15U) 
                                                    | ((0x100000U 
                                                        & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                           >> 0xbU)) 
                                                       | ((0xff000U 
                                                           & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1) 
                                                          | ((0x800U 
                                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                                 >> 9U)) 
                                                             | (0x7feU 
                                                                & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                                   >> 0x14U))))))
                                                    : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hcdb0a71f__0 
        = ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
           & (0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
        = (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
            & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0)) 
               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0)))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1
            : (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0)) 
                   & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0)))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0
                : vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hbd812b30__0 
        = (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
            & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1)) 
               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0)))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc88387d2__0 
        = ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
             == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1)) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0))
            ? 4U : ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1)) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0))
                     ? 3U : ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1)) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0))
                              ? 2U : 0U)));
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
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_0 
        = (((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
            & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                 == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                              >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0)) 
               | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                    == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                 >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h16e56402__0)) 
                  | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                       == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                    >> 0x14U))) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                       >> 0x14U)))) 
                     & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
                        & ((0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                           & ((0x23U != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                              & (~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_0))))))))) 
           | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                             >> 0xfU))) & ((0U != (0x1fU 
                                                   & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                      >> 0xfU))) 
                                           & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
                                              & ((0x6fU 
                                                  != 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0))))) 
              | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                   == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                >> 0xfU))) & ((0U != 
                                               (0x1fU 
                                                & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                   >> 0xfU))) 
                                              & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
                                                 & ((0x6fU 
                                                     != 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                    & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0))))) 
                 | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                      == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                   >> 0x14U))) & ((0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                       >> 0x14U))) 
                                                  & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
                                                     & ((0x6fU 
                                                         != 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                                                        & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_0)) 
                                                           & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0)))))) 
                    | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                         == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                      >> 0x14U))) & 
                        ((0U != (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                          >> 0x14U))) 
                         & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_0)) 
                            & ((0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                               & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_0)) 
                                  & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0)))))) 
                       | ((0x23U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0)) 
                          & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
                               == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                            >> 0x14U))) 
                              & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0)) 
                             | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
                                 == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                              >> 0x14U))) 
                                & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0)))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_1 
        = (((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
            & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                 == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                              >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hcdb0a71f__0)) 
               | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                    == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                 >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hcdb0a71f__0)) 
                  | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                       == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                    >> 0x14U))) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                       >> 0x14U)))) 
                     & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                        & ((0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                           & ((0x23U != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                              & (~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_1))))))))) 
           | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                             >> 0xfU))) & ((0U != (0x1fU 
                                                   & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                      >> 0xfU))) 
                                           & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                                              & ((0x6fU 
                                                  != 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0))))) 
              | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                   == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                >> 0xfU))) & ((0U != 
                                               (0x1fU 
                                                & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                   >> 0xfU))) 
                                              & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                                                 & ((0x6fU 
                                                     != 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                    & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0))))) 
                 | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
                      == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                   >> 0x14U))) & ((0U 
                                                   != 
                                                   (0x1fU 
                                                    & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                       >> 0x14U))) 
                                                  & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                                                     & ((0x6fU 
                                                         != 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                                        & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_1)) 
                                                           & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h1f64f326__0)))))) 
                    | ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                         == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                      >> 0x14U))) & 
                        ((0U != (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                          >> 0x14U))) 
                         & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                            & ((0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                               & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_1)) 
                                  & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_ha52ea22b__0)))))) 
                       | (((0x23U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                           & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
                                == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                             >> 0x14U))) 
                               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0)) 
                              | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
                                  == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                               >> 0x14U))) 
                                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0)))) 
                          | ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                 | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                    | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0))))) 
                             & ((0U != (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                 >> 7U))) 
                                & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type_1)) 
                                   & ((0x6fU != (0x7fU 
                                                 & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1)) 
                                      & ((((0x1fU & 
                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                             >> 7U)) 
                                           == (0x1fU 
                                               & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                  >> 0xfU))) 
                                          & (0U != 
                                             (0x1fU 
                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                 >> 0x14U)))) 
                                         | (((0x1fU 
                                              & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                 >> 7U)) 
                                             == (0x1fU 
                                                 & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                    >> 0x14U))) 
                                            & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type_1)) 
                                               & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                      >> 0x14U))))))))))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
        = ((4U == (vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1 
                   - vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_0))
            ? top__DOT__dut__DOT__core__DOT____VdfgTmp_hbd812b30__0
            : (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
                & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1)) 
                   & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0)))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1
                : top__DOT__dut__DOT__core__DOT____VdfgTmp_hbd812b30__0));
    top__DOT__dut__DOT__core__DOT__b_sel_1 = ((0x33U 
                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1))
                                               ? ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured)
                                                   ? (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc88387d2__0)
                                                   : 
                                                  ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1)) 
                                                    & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0))
                                                    ? 5U
                                                    : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc88387d2__0)))
                                               : 1U);
    top__DOT__dut__DOT__core__DOT__b_sel_0 = (((0x33U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                               & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0))
                                               ? 5U
                                               : ((
                                                   (0x33U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                   & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0))
                                                   ? 4U
                                                   : 
                                                  (((0x33U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                    & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0))
                                                    ? 3U
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0))
                                                     ? 2U
                                                     : 
                                                    ((0x33U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0))
                                                      ? 0U
                                                      : 1U)))));
    top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0)
            ? 5U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0)
                     ? 4U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0)
                              ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0)
                                       ? 2U : 0U))));
    top__DOT__dut__DOT__core__DOT__a_sel_0 = (((0x63U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                               | ((0x17U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                                  | (0x6fU 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0))))
                                               ? 1U
                                               : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0) 
                                                   & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0))
                                                   ? 5U
                                                   : 
                                                  (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0) 
                                                    & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0))
                                                    ? 4U
                                                    : 
                                                   (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0) 
                                                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0))
                                                     ? 3U
                                                     : 
                                                    (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0) 
                                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0))
                                                      ? 2U
                                                      : 0U)))));
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0 
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
    top__DOT__dut__DOT__core__DOT__alu_in2_w_1 = ((1U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_1))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1
                                                   : 
                                                  ((2U 
                                                    == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_1))
                                                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                                                    : 
                                                   ((3U 
                                                     == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_1))
                                                     ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                                                     : 
                                                    ((4U 
                                                      == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_1))
                                                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                                                      : 
                                                     ((5U 
                                                       == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_1))
                                                       ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                                                       : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2)))));
    top__DOT__dut__DOT__core__DOT__alu_in2_w_0 = ((1U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_0))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0
                                                   : 
                                                  ((2U 
                                                    == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_0))
                                                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                                                    : 
                                                   ((3U 
                                                     == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_0))
                                                     ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                                                     : 
                                                    ((4U 
                                                      == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_0))
                                                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                                                      : 
                                                     ((5U 
                                                       == (IData)(top__DOT__dut__DOT__core__DOT__b_sel_0))
                                                       ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                                                       : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r)))));
    top__DOT__dut__DOT__core__DOT__bc_idata2_in_0 = 
        ((2U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0))
          ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
          : ((3U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0))
              ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
              : ((4U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0))
                  ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                  : ((5U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel_0))
                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                      : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r))));
    top__DOT__dut__DOT__core__DOT__alu_in1_w_0 = ((1U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_0))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0
                                                   : 
                                                  ((2U 
                                                    == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_0))
                                                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                                                    : 
                                                   ((3U 
                                                     == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_0))
                                                     ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                                                     : 
                                                    ((4U 
                                                      == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_0))
                                                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                                                      : 
                                                     ((5U 
                                                       == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_0))
                                                       ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                                                       : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r)))));
    top__DOT__dut__DOT__core__DOT__bc_data1_in_0 = 
        ((2U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0))
          ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
          : ((3U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0))
              ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
              : ((4U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0))
                  ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                  : ((5U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_0))
                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                      : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r))));
    top__DOT__dut__DOT__core__DOT__a_sel_1 = (((0x63U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                               | (IData)(__VdfgTmp_h23a26853__0))
                                               ? 1U
                                               : ((
                                                   (~ 
                                                    ((0x37U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                                     | (IData)(__VdfgTmp_h23a26853__0))) 
                                                   & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured))
                                                   ? (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0)
                                                   : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0)));
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured)
            ? (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h1cd51c1b__0)
            : (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h3e522eca__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 = 0U;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
            = ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                ? ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                    ? 0U : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                             ? ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                                 ? 0xffffffffU : VL_DIV_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_0, top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                             : ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == top__DOT__dut__DOT__core__DOT__alu_in1_w_0) 
                                                   & (0xffffffffU 
                                                      == top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_0, top__DOT__dut__DOT__core__DOT__alu_in2_w_0)))))
                : ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                    ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                        ? VL_MULS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_0, top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        : top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                        ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                           & top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        : (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                           | top__DOT__dut__DOT__core__DOT__alu_in2_w_0))));
    } else if ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))) {
        if ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
                = ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       ^ top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : ((top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                        < top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                        ? 1U : 0U));
        } else if ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
                = (VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_0, top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
                = (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                   >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_0));
            if ((top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                 >> 0x1fU)) {
                top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_0)));
                vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
                       | top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 
            = ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_0))
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       << (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_0)))
                : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_0))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       - top__DOT__dut__DOT__core__DOT__alu_in2_w_0)
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w_0 
                       + top__DOT__dut__DOT__core__DOT__alu_in2_w_0)));
    }
    top__DOT__dut__DOT__core__DOT__br_eq_0 = (top__DOT__dut__DOT__core__DOT__bc_data1_in_0 
                                              == top__DOT__dut__DOT__core__DOT__bc_idata2_in_0);
    top__DOT__dut__DOT__core__DOT__br_lt_0 = (((0x63U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                                               & ((6U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                                                  | (7U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))))
                                               ? (top__DOT__dut__DOT__core__DOT__bc_data1_in_0 
                                                  < top__DOT__dut__DOT__core__DOT__bc_idata2_in_0)
                                               : VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__bc_data1_in_0, top__DOT__dut__DOT__core__DOT__bc_idata2_in_0));
    top__DOT__dut__DOT__core__DOT__alu_in1_w_1 = ((1U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_1))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1
                                                   : 
                                                  ((2U 
                                                    == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_1))
                                                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0
                                                    : 
                                                   ((3U 
                                                     == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_1))
                                                     ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1
                                                     : 
                                                    ((4U 
                                                      == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_1))
                                                      ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0
                                                      : 
                                                     ((5U 
                                                       == (IData)(top__DOT__dut__DOT__core__DOT__a_sel_1))
                                                       ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1
                                                       : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2)))));
    if ((2U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1))) {
        top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
        top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
    } else if ((3U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1))) {
        top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
        top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
    } else if ((4U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1))) {
        top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
        top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
    } else if ((5U == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel_1))) {
        top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
        top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
    } else {
        top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
        top__DOT__dut__DOT__core__DOT__bc_idata2_in_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0 
        = (((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                & (IData)(top__DOT__dut__DOT__core__DOT__br_eq_0)) 
               | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_eq_0)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                      & (IData)(top__DOT__dut__DOT__core__DOT__br_lt_0)) 
                     | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt_0)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0)) 
                            & (IData)(top__DOT__dut__DOT__core__DOT__br_lt_0)) 
                           | ((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt_0)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0))))))))) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 = 0U;
    top__DOT__dut__DOT__core__DOT__al2__DOT__mask = 0U;
    if ((8U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
            = ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                ? ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                    ? 0U : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                             ? ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                                 ? 0xffffffffU : VL_DIV_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_1, top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                             : ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == top__DOT__dut__DOT__core__DOT__alu_in1_w_1) 
                                                   & (0xffffffffU 
                                                      == top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_1, top__DOT__dut__DOT__core__DOT__alu_in2_w_1)))))
                : ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                    ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                        ? VL_MULS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_1, top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        : top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                        ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                           & top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        : (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                           | top__DOT__dut__DOT__core__DOT__alu_in2_w_1))));
    } else if ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))) {
        if ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
                = ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       ^ top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : ((top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                        < top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                        ? 1U : 0U));
        } else if ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
                = (VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w_1, top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
                = (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                   >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_1));
            if ((top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                 >> 0x1fU)) {
                top__DOT__dut__DOT__core__DOT__al2__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_1)));
                vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
                       | top__DOT__dut__DOT__core__DOT__al2__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 
            = ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_1))
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       << (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w_1)))
                : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel_1))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       - top__DOT__dut__DOT__core__DOT__alu_in2_w_1)
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w_1 
                       + top__DOT__dut__DOT__core__DOT__alu_in2_w_1)));
    }
    top__DOT__dut__DOT__core__DOT__br_eq_1 = (top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
                                              == top__DOT__dut__DOT__core__DOT__bc_idata2_in_1);
    top__DOT__dut__DOT__core__DOT__br_lt_1 = (((0x63U 
                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
                                               & ((6U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                                                  | (7U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))))
                                               ? (top__DOT__dut__DOT__core__DOT__bc_idata1_in_1 
                                                  < top__DOT__dut__DOT__core__DOT__bc_idata2_in_1)
                                               : VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__bc_idata1_in_1, top__DOT__dut__DOT__core__DOT__bc_idata2_in_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1 
        = (((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                & (IData)(top__DOT__dut__DOT__core__DOT__br_eq_1)) 
               | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_eq_1)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                      & (IData)(top__DOT__dut__DOT__core__DOT__br_lt_1)) 
                     | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt_1)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1)) 
                            & (IData)(top__DOT__dut__DOT__core__DOT__br_lt_1)) 
                           | ((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt_1)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1))))))))) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0));
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
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge top.clock)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge top.clock)\n");
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
    vlSelf->top__DOT__clkg__DOT__counter = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 = VL_RAND_RESET_I(32);
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
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0 = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1 = VL_RAND_RESET_I(32);
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
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2 = VL_RAND_RESET_I(32);
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
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 145; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = VL_RAND_RESET_I(1);
}
