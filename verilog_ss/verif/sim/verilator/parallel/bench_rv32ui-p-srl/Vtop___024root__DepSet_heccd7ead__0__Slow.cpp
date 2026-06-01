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

extern const VlWide<27>/*863:0*/ Vtop__ConstPool__CONST_h3bb99f68_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT__i;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0;
    CData/*7:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h0ccad997__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h0ccad997__0 = 0;
    IData/*23:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0 = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x72616365U;
    __Vtemp_1[1U] = 0x726c2e74U;
    __Vtemp_1[2U] = 0x2d702d73U;
    __Vtemp_1[3U] = 0x33327569U;
    __Vtemp_1[4U] = 0x7276U;
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                      , std::string{"w"});
    ;
    vlSelf->top__DOT__clock = 0U;
    vlSelf->top__DOT__reset = 1U;
    VL_READMEM_N(true, 32, 262144, 0, VL_CVT_PACK_STR_NW(27, Vtop__ConstPool__CONST_h3bb99f68_0)
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
    VL_READMEM_N(true, 32, 368, 0, VL_CVT_PACK_STR_NW(27, Vtop__ConstPool__CONST_h3bb99f68_0)
                 ,  &(vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp)
                 , 0, ~0ULL);
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x170U, top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)) {
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h0ccad997__0 
            = (((0x16fU >= (0x1ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                 ? vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                [(0x1ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)]
                 : 0U) >> 0x18U);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0 
            = ((0x16fU >= (0x1ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                ? (0xffffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                   [(0x1ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)])
                : 0U);
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(3U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_h0ccad997__0;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(2U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0 
                        >> 0x10U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & ((IData)(1U) 
                                                                   + 
                                                                   VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0xffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0 
                        >> 8U));
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0xfffffU 
                                                                & VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))] 
            = (0xffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hf7eb1029__0);
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
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_u_type;
    top__DOT__dut__DOT__core__DOT__is_u_type = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__is_i_type;
    top__DOT__dut__DOT__core__DOT__is_i_type = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__a_sel;
    top__DOT__dut__DOT__core__DOT__a_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__b_sel;
    top__DOT__dut__DOT__core__DOT__b_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel;
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel;
    top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel = 0;
    CData/*3:0*/ top__DOT__dut__DOT__core__DOT__alu_sel;
    top__DOT__dut__DOT__core__DOT__alu_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__wb_sel;
    top__DOT__dut__DOT__core__DOT__wb_sel = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_eq;
    top__DOT__dut__DOT__core__DOT__br_eq = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_lt;
    top__DOT__dut__DOT__core__DOT__br_lt = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in1_w;
    top__DOT__dut__DOT__core__DOT__alu_in1_w = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in2_w;
    top__DOT__dut__DOT__core__DOT__alu_in2_w = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg;
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__idata1_in;
    top__DOT__dut__DOT__core__DOT__idata1_in = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__idata2_in;
    top__DOT__dut__DOT__core__DOT__idata2_in = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__al1__DOT__mask;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0;
    CData/*0:0*/ __VdfgTmp_h556d0b02__0;
    __VdfgTmp_h556d0b02__0 = 0;
    // Body
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 
        = ((0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
           | (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__alu_sel = ((0x37U 
                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r))
                                               ? 0xaU
                                               : ((
                                                   (0x17U 
                                                    == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                   | ((0x6fU 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                      | ((0x67U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                         | ((3U 
                                                             == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                            | ((0x23U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                               | (0x63U 
                                                                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)))))))
                                                   ? 0U
                                                   : 
                                                  (((0x33U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                    & (1U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                     ? 0xbU
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                      ? 0xcU
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                       ? 0xdU
                                                       : 0xaU)))
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                     & (0x20U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                      ? 1U
                                                      : 4U)
                                                     : 
                                                    (((0x33U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                      | (0x13U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)))
                                                      ? 
                                                     ((0U 
                                                       == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                       ? 0U
                                                       : 
                                                      ((1U 
                                                        == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                        ? 2U
                                                        : 
                                                       ((2U 
                                                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                         ? 5U
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                          ? 6U
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                           ? 7U
                                                           : 
                                                          (((5U 
                                                             == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                                                            & (0U 
                                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                                            ? 3U
                                                            : 
                                                           (((5U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                                                             & (0x20U 
                                                                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                                             ? 4U
                                                             : 
                                                            ((6U 
                                                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                              ? 8U
                                                              : 
                                                             ((7U 
                                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                               ? 9U
                                                               : 0xaU)))))))))
                                                      : 0xaU)))));
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    __VdfgTmp_h556d0b02__0 = ((0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                              | (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__wb_sel = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
                                              ? 0U : 
                                             (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                                               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                                               ? 2U
                                               : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 
        = (1U & (~ ((0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                    | (IData)(__VdfgTmp_h556d0b02__0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w 
        = ((0U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel))
            ? ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r)))
                ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r))
                    ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w 
                                          >> 7U)))) 
                        << 8U) | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w)))
                : ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r)))
                    ? ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r))
                        ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w)
                        : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w)))
                    : vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w))
            : ((1U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r
                : ((2U == (IData)(top__DOT__dut__DOT__core__DOT__wb_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r
                    : 0U)));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
           == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                        >> 0x14U)));
    top__DOT__dut__DOT__core__DOT__is_i_type = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                | ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                   | ((0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                      | (IData)(
                                                                (0x73U 
                                                                 == 
                                                                 (0xfff0707fU 
                                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w))))));
    top__DOT__dut__DOT__core__DOT__is_u_type = ((0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
            & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
               & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                  & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w = 
        ((0x33U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w))
          ? 0U : (((0x13U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                   & ((1U == (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                    >> 0xcU))) | (5U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                      >> 0xcU)))))
                   ? (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                               >> 0x14U)) : ((IData)(top__DOT__dut__DOT__core__DOT__is_i_type)
                                              ? (((- (IData)(
                                                             (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                    >> 0x14U))
                                              : ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w))
                                                  ? 
                                                 (((- (IData)(
                                                              (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                               >> 0x1fU))) 
                                                   << 0xcU) 
                                                  | ((0xfe0U 
                                                      & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                           >> 7U))))
                                                  : 
                                                 ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w))
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                >> 0x1fU))) 
                                                    << 0xdU) 
                                                   | ((0x1000U 
                                                       & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                          >> 0x13U)) 
                                                      | ((0x800U 
                                                          & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                             << 4U)) 
                                                         | ((0x7e0U 
                                                             & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                >> 0x14U)) 
                                                            | (0x1eU 
                                                               & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                  >> 7U))))))
                                                   : 
                                                  ((IData)(top__DOT__dut__DOT__core__DOT__is_u_type)
                                                    ? 
                                                   (0xfffff000U 
                                                    & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                  >> 0x1fU))) 
                                                      << 0x15U) 
                                                     | ((0x100000U 
                                                         & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                            >> 0xbU)) 
                                                        | ((0xff000U 
                                                            & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w) 
                                                           | ((0x800U 
                                                               & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                  >> 9U)) 
                                                              | (0x7feU 
                                                                 & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                    >> 0x14U))))))
                                                     : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0 
        = ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type)) 
           & (0x6fU != (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = 
        (((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
          & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
               == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                            >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0)) 
             | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                 == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                              >> 0x14U))) & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type)) 
                                             & ((0x6fU 
                                                 != 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                & ((0x23U 
                                                    != 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                                   & (~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type)))))))) 
         | (((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                 & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)))) 
             & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                 != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
                & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                    != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r)) 
                   & ((IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg) 
                      & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                           == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                        >> 0xfU))) 
                          & ((0U != (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                              >> 0xfU))) 
                             & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0))) 
                         | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                             == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                          >> 0x14U))) 
                            & ((0U != (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                >> 0x14U))) 
                               & ((~ (IData)(top__DOT__dut__DOT__core__DOT__is_u_type)) 
                                  & ((0x6fU != (0x7fU 
                                                & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                                     & (~ (IData)(top__DOT__dut__DOT__core__DOT__is_i_type))))))))))) 
            | (((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                & ((0x23U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                   & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                       == (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                    >> 0xfU))) & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0)))) 
               | ((0x23U == (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w)) 
                  & ((IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0) 
                     & ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                            & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)))) 
                        & ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r))))) 
                           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)))))))));
    top__DOT__dut__DOT__core__DOT__b_sel = (((0x33U 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                             & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0))
                                             ? 3U : 
                                            (((0x33U 
                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0))
                                              ? 2U : 
                                             ((0x33U 
                                               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r))
                                               ? 0U
                                               : 1U)));
    top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0)
                     ? 2U : 0U));
    top__DOT__dut__DOT__core__DOT__a_sel = (((0x63U 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                             | (IData)(__VdfgTmp_h556d0b02__0))
                                             ? 1U : 
                                            (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0))
                                              ? 3U : 
                                             (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                                               & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0))
                                               ? 2U
                                               : 0U)));
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0)
                     ? 2U : 0U));
    top__DOT__dut__DOT__core__DOT__alu_in2_w = ((0U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__b_sel))
                                                 ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r
                                                 : 
                                                ((1U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__b_sel))
                                                  ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r
                                                  : 
                                                 ((2U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__b_sel))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                                                   : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    top__DOT__dut__DOT__core__DOT__idata2_in = ((2U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel))
                                                 ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                                                 : 
                                                ((3U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel))
                                                  ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                                                  : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r));
    top__DOT__dut__DOT__core__DOT__alu_in1_w = ((0U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__a_sel))
                                                 ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r
                                                 : 
                                                ((1U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__a_sel))
                                                  ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r
                                                  : 
                                                 ((2U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__a_sel))
                                                   ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                                                   : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    top__DOT__dut__DOT__core__DOT__idata1_in = ((2U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel))
                                                 ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                                                 : 
                                                ((3U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel))
                                                  ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                                                  : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w = 0U;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
            = ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                ? ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? 0U : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                             ? ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : VL_DIV_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w, top__DOT__dut__DOT__core__DOT__alu_in2_w))
                             : ((0U == top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == top__DOT__dut__DOT__core__DOT__alu_in1_w) 
                                                   & (0xffffffffU 
                                                      == top__DOT__dut__DOT__core__DOT__alu_in2_w))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w, top__DOT__dut__DOT__core__DOT__alu_in2_w)))))
                : ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                        ? VL_MULS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w, top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                        ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           & top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           | top__DOT__dut__DOT__core__DOT__alu_in2_w))));
    } else if ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
        if ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
                = ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       ^ top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((top__DOT__dut__DOT__core__DOT__alu_in1_w 
                        < top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        ? 1U : 0U));
        } else if ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
                = (VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w, top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
                = (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                   >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w));
            if ((top__DOT__dut__DOT__core__DOT__alu_in1_w 
                 >> 0x1fU)) {
                top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w)));
                vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
                       | top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
            = ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       >> (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w))
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       << (0x1fU & top__DOT__dut__DOT__core__DOT__alu_in2_w)))
                : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       - top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       + top__DOT__dut__DOT__core__DOT__alu_in2_w)));
    }
    top__DOT__dut__DOT__core__DOT__br_eq = (top__DOT__dut__DOT__core__DOT__idata1_in 
                                            == top__DOT__dut__DOT__core__DOT__idata2_in);
    top__DOT__dut__DOT__core__DOT__br_lt = (((0x63U 
                                              == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                             & ((6U 
                                                 == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                                                | (7U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))))
                                             ? (top__DOT__dut__DOT__core__DOT__idata1_in 
                                                < top__DOT__dut__DOT__core__DOT__idata2_in)
                                             : VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__idata1_in, top__DOT__dut__DOT__core__DOT__idata2_in));
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken 
        = (((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                & (IData)(top__DOT__dut__DOT__core__DOT__br_eq)) 
               | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_eq)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                      & (IData)(top__DOT__dut__DOT__core__DOT__br_lt)) 
                     | (((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                            & (IData)(top__DOT__dut__DOT__core__DOT__br_lt)) 
                           | ((~ (IData)(top__DOT__dut__DOT__core__DOT__br_lt)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))))))))) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0));
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
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r = VL_RAND_RESET_I(7);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 = 0;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 368; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = VL_RAND_RESET_I(1);
}
