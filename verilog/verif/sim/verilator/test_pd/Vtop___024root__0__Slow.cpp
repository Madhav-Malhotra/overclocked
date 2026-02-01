// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0 
        = vlSelfRef.top__DOT__clock;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__clkg__DOT__counter = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT__i;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0;
    CData/*7:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc100b205__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc100b205__0 = 0;
    IData/*23:0*/ top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0;
    top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0 = 0;
    // Body
    vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd 
        = VL_FOPEN_NN("rv32ui-p-add.trace"s, "w"s);
    ;
    vlSelfRef.top__DOT__clock = 0U;
    vlSelfRef.top__DOT__reset = 1U;
    VL_READMEM_N(true, 32, 262144, 0, "/Users/eshaa/overclocked-test/overclocked/verilog/verif/data/rv32ui-p-add.x"s
                 ,  &(vlSelfRef.top__DOT__dut__DOT__core__DOT__imem1__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[1U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[3U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[4U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[5U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[6U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[7U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[8U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[9U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0aU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0bU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0cU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0dU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0eU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x0fU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x10U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x11U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x12U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x13U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x14U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x15U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x16U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x17U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x18U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x19U] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1aU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1bU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1cU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1dU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1eU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[0x1fU] = 0U;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[2U] = 0x01100000U;
    VL_READMEM_N(true, 32, 357, 0, "/Users/eshaa/overclocked-test/overclocked/verilog/verif/data/rv32ui-p-add.x"s
                 ,  &(vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp)
                 , 0, ~0ULL);
    top__DOT__dut__DOT__core__DOT__dmem1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000165U, top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)) {
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc100b205__0 
            = (((0x0164U >= (0x000001ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                 ? vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                [(0x000001ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)]
                 : 0U) >> 0x00000018U);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0 
            = ((0x0164U >= (0x000001ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))
                ? (0x00ffffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp
                   [(0x000001ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)])
                : 0U);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0x000fffffU 
                                                                  & ((IData)(3U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc100b205__0;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0x000fffffU 
                                                                  & ((IData)(2U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0x000000ffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0 
                              >> 0x00000010U));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0x000fffffU 
                                                                  & ((IData)(1U) 
                                                                     + 
                                                                     VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i)))] 
            = (0x000000ffU & (top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0 
                              >> 8U));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[(0x000fffffU 
                                                                  & VL_MULS_III(32, (IData)(4U), top__DOT__dut__DOT__core__DOT__dmem1__DOT__i))] 
            = (0x000000ffU & top__DOT__dut__DOT__core__DOT__dmem1__DOT____Vconcswap_1_hc3ac4278__0);
        top__DOT__dut__DOT__core__DOT__dmem1__DOT__i 
            = ((IData)(1U) + top__DOT__dut__DOT__core__DOT__dmem1__DOT__i);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/eshaa/overclocked-test/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ top__DOT__dut__DOT__core__DOT__alu_sel;
    top__DOT__dut__DOT__core__DOT__alu_sel = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in1_w;
    top__DOT__dut__DOT__core__DOT__alu_in1_w = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_in2_w;
    top__DOT__dut__DOT__core__DOT__alu_in2_w = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg;
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_5;
    top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_5 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6;
    top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel = 0;
    CData/*1:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1;
    top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2;
    top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt = 0;
    IData/*31:0*/ top__DOT__dut__DOT__core__DOT__al1__DOT__mask;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_2;
    __VdfgRegularize_h4af1c392_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_3;
    __VdfgRegularize_h4af1c392_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_4;
    __VdfgRegularize_h4af1c392_0_4 = 0;
    CData/*0:0*/ __VdfgRegularize_h4af1c392_0_5;
    __VdfgRegularize_h4af1c392_0_5 = 0;
    // Body
    vlSelfRef.top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12 
        = ((0x6fU == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
           | (0x67U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r))))) 
           & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10 
        = ((0x17U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
           | (0x6fU == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
            ? 0U : (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                     | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                     ? 2U : 1U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14 
        = ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
                  | ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                     | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
              & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    top__DOT__dut__DOT__core__DOT__alu_sel = ((0x37U 
                                               == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r))
                                               ? 0x0aU
                                               : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10) 
                                                   | ((0x67U 
                                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                      | ((3U 
                                                          == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                         | ((0x23U 
                                                             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                            | (0x63U 
                                                               == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r))))))
                                                   ? 0U
                                                   : 
                                                  (((0x33U 
                                                     == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                    & (0x20U 
                                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r)))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                     ? 1U
                                                     : 4U)
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                                                     | (0x13U 
                                                        == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                       ? 2U
                                                       : 
                                                      ((2U 
                                                        == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                        ? 5U
                                                        : 
                                                       ((3U 
                                                         == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                         ? 6U
                                                         : 
                                                        ((4U 
                                                          == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                          ? 7U
                                                          : 
                                                         (((5U 
                                                            == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
                                                           & (0U 
                                                              == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r)))
                                                           ? 3U
                                                           : 
                                                          (((5U 
                                                             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
                                                            & (0x20U 
                                                               == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r)))
                                                            ? 4U
                                                            : 
                                                           ((6U 
                                                             == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                             ? 8U
                                                             : 
                                                            ((7U 
                                                              == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))
                                                              ? 9U
                                                              : 0x0aU)))))))))
                                                     : 0x0aU))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9 
        = (1U & (~ ((0x37U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                    | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w 
        = ((0U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
            ? ((0U == (3U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r)))
                ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r))
                    ? (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w)
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w 
                                          >> 7U)))) 
                        << 8U) | (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w)))
                : ((1U == (3U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r)))
                    ? ((4U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r))
                        ? (0x0000ffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w)
                        : (((- (IData)((1U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w 
                                              >> 0x0000000fU)))) 
                            << 0x00000010U) | (0x0000ffffU 
                                               & vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w)))
                    : vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w))
            : ((1U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_mw_r
                : ((2U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                    ? vlSelfRef.top__DOT__dut__DOT__core__DOT__pc4_mw_r
                    : 0U)));
    top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_5 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
           == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                              >> 0x00000014U)));
    top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w 
        = ((0x13U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
           | ((3U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
              | ((0x67U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                 | (IData)((0x00000073U == (0xfff0707fU 
                                            & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr))))));
    top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w 
        = ((0x37U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
           | (0x17U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)));
    __VdfgRegularize_h4af1c392_0_4 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14));
    __VdfgRegularize_h4af1c392_0_2 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13 
        = ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19) 
                  | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
              & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = (((0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
            & (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
               & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                  & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_w 
        = ((0x33U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr))
            ? 0U : (((0x13U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                     & ((1U == (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                      >> 0x0000000cU))) 
                        | (5U == (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 0x0000000cU)))))
                     ? (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                       >> 0x00000014U))
                     : ((IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)
                         ? (((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                         >> 0x0000001fU))) 
                             << 0x0000000cU) | (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                >> 0x00000014U))
                         : ((0x23U == (0x0000007fU 
                                       & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr))
                             ? (((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                             >> 0x0000001fU))) 
                                 << 0x0000000cU) | 
                                ((0x00000fe0U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                 >> 0x00000014U)) 
                                 | (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                   >> 7U))))
                             : ((0x63U == (0x0000007fU 
                                           & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr))
                                 ? (((- (IData)((vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                 >> 0x0000001fU))) 
                                     << 0x0000000dU) 
                                    | ((((2U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                >> 0x0000001eU)) 
                                         | (1U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                  >> 7U))) 
                                        << 0x0000000bU) 
                                       | ((0x000007e0U 
                                           & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                              >> 0x00000014U)) 
                                          | (0x0000001eU 
                                             & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                >> 7U)))))
                                 : ((IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)
                                     ? (0xfffff000U 
                                        & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)
                                     : ((0x6fU == (0x0000007fU 
                                                   & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr))
                                         ? ((((0x00000ffeU 
                                               & ((- (IData)(
                                                             (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                              >> 0x0000001fU))) 
                                                  << 1U)) 
                                              | (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                 >> 0x0000001fU)) 
                                             << 0x00000014U) 
                                            | ((((0x000001feU 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                     >> 0x0000000bU)) 
                                                 | (1U 
                                                    & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                       >> 0x00000014U))) 
                                                << 0x0000000bU) 
                                               | (0x000007feU 
                                                  & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                     >> 0x00000014U))))
                                         : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6 
        = ((~ (IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
           & (0x6fU != (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)));
    __VdfgRegularize_h4af1c392_0_5 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13));
    __VdfgRegularize_h4af1c392_0_3 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__stall 
        = (((3U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            & ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                 == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                    >> 0x0000000fU))) 
                & (IData)(top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6)) 
               | (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                   == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                      >> 0x00000014U))) 
                  & ((IData)(top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6) 
                     & ((0x23U != (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                        & (~ (IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w))))))) 
           | (((~ ((0x13U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                   & (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)))) 
               & (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                   != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
                  & (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                      != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r)) 
                     & ((IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg) 
                        & ((((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                             == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                >> 0x0000000fU))) 
                            & ((0U != (0x0000001fU 
                                       & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                          >> 0x0000000fU))) 
                               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_6))) 
                           | (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                               == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                  >> 0x00000014U))) 
                              & ((~ (IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                                 & ((0U != (0x0000001fU 
                                            & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                               >> 0x00000014U))) 
                                    & ((0x6fU != (0x0000007fU 
                                                  & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                                       & (~ (IData)(top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w))))))))))) 
              | (((3U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                  & ((0x23U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                     & (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                         == (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                            >> 0x0000000fU))) 
                        & (IData)(top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_5)))) 
                 | ((0x23U == (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr)) 
                    & ((~ (((0x13U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                            & (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))) 
                           | ((0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                              | ((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                                 | ((0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                                    | (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))))))) 
                       & (IData)(top__DOT__dut__DOT__core__DOT____VdfgRegularize_h5d521ce4_0_5))))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel 
        = (((0x33U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            & (IData)(__VdfgRegularize_h4af1c392_0_4))
            ? 3U : (((0x33U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                     & (IData)(__VdfgRegularize_h4af1c392_0_5))
                     ? 2U : ((0x33U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r))
                              ? 0U : 1U)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel 
        = ((IData)(__VdfgRegularize_h4af1c392_0_4) ? 3U
            : ((IData)(__VdfgRegularize_h4af1c392_0_5)
                ? 2U : 0U));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel 
        = (((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10))
            ? 1U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9) 
                     & (IData)(__VdfgRegularize_h4af1c392_0_2))
                     ? 3U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9) 
                              & (IData)(__VdfgRegularize_h4af1c392_0_3))
                              ? 2U : 0U)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel 
        = ((IData)(__VdfgRegularize_h4af1c392_0_2) ? 3U
            : ((IData)(__VdfgRegularize_h4af1c392_0_3)
                ? 2U : 0U));
    top__DOT__dut__DOT__core__DOT__alu_in2_w = ((0U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                                                 ? vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r
                                                 : 
                                                ((1U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                                                  ? vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_dx_r
                                                  : 
                                                 ((2U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                                                   ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
                                                   : vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 
        = ((2U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r));
    top__DOT__dut__DOT__core__DOT__alu_in1_w = ((0U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                                                 ? vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r
                                                 : 
                                                ((1U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                                                  ? vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_dx_r
                                                  : 
                                                 ((2U 
                                                   == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                                                   ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
                                                   : vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
        = ((2U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w = 0U;
    top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
            = ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                ? 0U : ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                         ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                             ? 0U : top__DOT__dut__DOT__core__DOT__alu_in2_w)
                         : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                             ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                                & top__DOT__dut__DOT__core__DOT__alu_in2_w)
                             : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                                | top__DOT__dut__DOT__core__DOT__alu_in2_w))));
    } else if ((4U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
        if ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
                = ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       ^ top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((top__DOT__dut__DOT__core__DOT__alu_in1_w 
                        < top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        ? 1U : 0U));
        } else if ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
                = (VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__alu_in1_w, top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    ? 1U : 0U);
        } else {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
                = (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                   >> (0x0000001fU & top__DOT__dut__DOT__core__DOT__alu_in2_w));
            if ((top__DOT__dut__DOT__core__DOT__alu_in1_w 
                 >> 0x1fU)) {
                top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x0000001fU 
                                          & top__DOT__dut__DOT__core__DOT__alu_in2_w)));
                vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
                    = (vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
                       | top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w 
            = ((2U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                ? ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       >> (0x0000001fU & top__DOT__dut__DOT__core__DOT__alu_in2_w))
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       << (0x0000001fU & top__DOT__dut__DOT__core__DOT__alu_in2_w)))
                : ((1U & (IData)(top__DOT__dut__DOT__core__DOT__alu_sel))
                    ? (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       - top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : (top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       + top__DOT__dut__DOT__core__DOT__alu_in2_w)));
    }
    top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq 
        = (top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
           == top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2);
    top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt 
        = (((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            & ((6U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
               | (7U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))))
            ? (top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
               < top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2)
            : VL_LTS_III(32, top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1, top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken 
        = (((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            & (((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
                & (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
               | (((~ (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
                   & (1U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))) 
                  | (((4U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
                      & (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                     | (((~ (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                         & (5U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))) 
                        | (((6U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r)) 
                            & (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                           | ((~ (IData)(top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                              & (7U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r))))))))) 
           | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(negedge top.clock)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge top.clock)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'act' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->top__DOT__clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5844775645289313205ull);
    vlSelf->top__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4457194187413456923ull);
    vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14329879011005447780ull);
    vlSelf->top__DOT__clkg__DOT__counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7673510899991897937ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13240766548018108947ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4052484987634210976ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 431685746357426064ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8980076183680390469ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9048645052328910710ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 849597735165605403ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 930766119171137495ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10760766648416922082ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16964940685551598529ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11413296696856369733ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7358664989046931424ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1985358467874483628ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7941358132075939916ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15950552035093181720ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5524449395865768706ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4261148752156021734ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12582379480445908928ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1063866193267392018ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8038660022393365163ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6652120819890057602ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 10229913718269901378ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4275879670385366343ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12290153299683083936ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5586899296965494084ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2809559615077096711ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13435670385813617839ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8058744004537542797ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9650671808757833961ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10991154579416179214ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8720185498421853200ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17543164617610772787ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11037743317134777767ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2060056238320381451ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9572878716051721546ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9682582511035375404ull);
    for (int __Vi0 = 0; __Vi0 < 262144; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17652197707930889920ull);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3906767887180398732ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 78312098317345711ull);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6709884466761393434ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16341668744566730203ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7170951682214054549ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3994349490260790814ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4644110261301005728ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15796146016500116329ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2348149615452875701ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17899851286484746263ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9060460794828390315ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18400985866207492619ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14693768985280390785ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14286995850827575524ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2974307937144021011ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5665256482205827648ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13962563309930945802ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14573246695558848558ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7404165166871259234ull);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 144064040553593563ull);
    for (int __Vi0 = 0; __Vi0 < 357; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14055122953989473189ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3895673634067618210ull);
    }
    vlSelf->__Vdpi_export_trigger = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__top__DOT__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14234138457933551086ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
