// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root____Vdpiexp_top__DOT__clkg__DOT__toggleClock_TOP(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiexp_top__DOT__clkg__DOT__toggleClock_TOP\n"); );
    // Body
    vlSymsp->TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->TOP.top__DOT__clock = (1U & (~ (IData)(vlSymsp->TOP.top__DOT__clock)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VactTriggered
                                      [1U]) | (IData)((IData)(vlSelfRef.__Vdpi_export_trigger)));
    vlSelfRef.__Vdpi_export_trigger = 0U;
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.top__DOT__clock) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0))) 
                                                      << 1U) 
                                                     | ((~ (IData)(vlSelfRef.top__DOT__clock)) 
                                                        & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__clock__0 
        = vlSelfRef.top__DOT__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
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
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    IData/*17:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __VdlySet__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __VdlySet__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 = 0;
    IData/*19:0*/ __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = vlSelfRef.top__DOT__clkg__DOT__counter;
    __VdlySet__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0U;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_fd_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0U;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0U;
    __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0U;
    __VdlySet__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall)))) {
        if (vlSelfRef.top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2) {
            __VdlyVal__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = vlSelfRef.top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2;
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = (0x0003ffffU & ((vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r 
                                   - (IData)(0x01000000U)) 
                                  >> 2U));
            __VdlySet__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 1U;
        }
    }
    if (vlSelfRef.top__DOT__reset) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = 0x01000000U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr = 0U;
    } else if (vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_fd_r;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr 
            = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall_fd)
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w);
    } else {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r 
            = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken) 
                | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__pc4_f_w);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr 
            = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken)
                ? 0x00000013U : vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w);
    }
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall)))) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__imem1__DOT__mem
            [(0x0003ffffU & ((vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r 
                              - (IData)(0x01000000U)) 
                             >> 2U))];
    }
    if (((~ (IData)(vlSelfRef.top__DOT__reset)) & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r))) {
        if ((0U == (3U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r)))) {
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0x000fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r);
            __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 1U;
        } else if ((1U == (3U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r)))) {
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
                                  >> 8U));
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0x000fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 1U;
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0x000fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r);
        } else {
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
                   >> 0x00000018U);
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (0x000fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 1U;
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
                                  >> 0x00000010U));
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0x000fffffU & ((IData)(2U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0x000000ffU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
                                  >> 8U));
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0x000fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0x000000ffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0x000fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r);
        }
    }
    if ((1U & (~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19) 
                  | ((0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                     | ((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                        | ((IData)(vlSelfRef.top__DOT__reset) 
                           | (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))))))))) {
        __VdlyVal__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w;
        __VdlyDim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
        __VdlySet__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__reset)))) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc4_mw_r 
            = ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_xm_r);
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__data_mem_w 
        = (((vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
             [(0x000fffffU & ((IData)(3U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
             << 0x00000018U) | (vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                [(0x000fffffU & ((IData)(2U) 
                                                 + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
                                << 0x00000010U)) | 
           ((vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
             [(0x000fffffU & ((IData)(1U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
             << 8U) | vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
            [(0x000fffffU & vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r)]));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r));
    if (__VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    }
    if (__VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    }
    if (__VdlySet__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__stall_fd 
        = ((IData)(vlSelfRef.top__DOT__reset) || ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) 
                                                  || (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                         >> 0x0000000fU))];
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rs2_xm_r = 0U;
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_dx_r 
            = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) 
                | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken))
                ? 0U : vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_w);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r 
            = (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
               >> 0x00000019U);
        vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r 
            = (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                     >> 0x0000000cU));
        vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rs2_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r 
        = vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                         >> 0x00000014U))];
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (3U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (0x6fU == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
            ? 0U : (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                     | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                     ? 2U : 1U));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (0x67U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r 
        = ((1U & (~ (IData)(vlSelfRef.top__DOT__reset))) 
           && (0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    if (vlSelfRef.top__DOT__reset) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0U;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
    } else {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_mw_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_mw_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_mw_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_xm_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_dx_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_dx_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r;
        vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
        if (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall) 
             | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken))) {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0x00000013U;
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
        } else {
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                  >> 0x0000000fU));
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                  >> 0x00000014U));
            vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_dx_r 
                = (7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                         >> 0x0000000cU));
            vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r 
                = (0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr);
            vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
                = (0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                  >> 7U));
        }
        vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_dx_r 
            = vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_fd_r;
    }
    if (__VdlySet__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__VdlyDim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    }
    vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r = __Vdly__top__DOT__dut__DOT__core__DOT__pc_r;
    if (__VdlySet__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0) {
        vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__VdlyDim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0] 
            = __VdlyVal__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    }
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
    vlSelfRef.top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r);
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r))))) 
           & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13 
        = ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19) 
                  | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
              & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))));
    __VdfgRegularize_h4af1c392_0_5 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13));
    __VdfgRegularize_h4af1c392_0_3 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_13));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_fd_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r;
    vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = (((0x23U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
            & (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
               & ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                  & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14 
        = ((0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & ((~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
                  | ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                     | (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
              & (0U != (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))));
    __VdfgRegularize_h4af1c392_0_4 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14));
    __VdfgRegularize_h4af1c392_0_2 = (((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                                       == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
                                      & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_14));
    vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
        = ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w);
    vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12 
        = ((0x6fU == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
           | (0x67U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10 
        = ((0x17U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
           | (0x6fU == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel 
        = ((IData)(__VdfgRegularize_h4af1c392_0_2) ? 3U
            : ((IData)(__VdfgRegularize_h4af1c392_0_3)
                ? 2U : 0U));
    __Vdly__top__DOT__clkg__DOT__counter = ((IData)(1U) 
                                            + vlSelfRef.top__DOT__clkg__DOT__counter);
    vlSelfRef.top__DOT__reset = VL_GTS_III(32, 5U, vlSelfRef.top__DOT__clkg__DOT__counter);
    if (VL_UNLIKELY(((0x0000c350U == vlSelfRef.top__DOT__clkg__DOT__counter)))) {
        VL_FINISH_MT("/Users/eshaa/overclocked-test/overclocked/verilog/verif/tests/clockgen.sv", 40, "");
    }
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
    top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
        = ((2U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
            ? vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
                ? vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelfRef.top__DOT__clkg__DOT__counter = __Vdly__top__DOT__clkg__DOT__counter;
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel 
        = (((0x63U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
            | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_10))
            ? 1U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9) 
                     & (IData)(__VdfgRegularize_h4af1c392_0_2))
                     ? 3U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_9) 
                              & (IData)(__VdfgRegularize_h4af1c392_0_3))
                              ? 2U : 0U)));
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
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.top__DOT__reset)))))) {
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_r,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__instr_w);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_fd_r,
                      7,(0x0000007fU & vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 7U)),5,(0x0000001fU 
                                                   & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                      >> 0x0000000fU)),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 0x00000014U)),
                      3,(7U & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                               >> 0x0000000cU)),7,(vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                                   >> 0x00000019U),
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__imm_w,
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 0x00000014U)));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",0,
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 0x0000000fU)),
                      5,(0x0000001fU & (vlSelfRef.top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
                                        >> 0x00000014U)),
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_dx_r,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_out_w,
                      1,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__br_taken));
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_xm_r,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__alu_xm_r,
                      1,((~ (IData)(vlSelfRef.top__DOT__reset)) 
                         & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r)),
                      2,(3U & (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__funct3_xm_r)),
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__dmem_data_in);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
        VL_FWRITEF_NX(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",0,
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__pc_mw_r,
                      1,(1U & (~ ((IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19) 
                                  | ((0x73U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                                     | ((0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                                        | ((IData)(vlSelfRef.top__DOT__reset) 
                                           | (0U == (IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)))))))),
                      5,(IData)(vlSelfRef.top__DOT__dut__DOT__core__DOT__addr_rd_mw_r),
                      32,vlSelfRef.top__DOT__dut__DOT__core__DOT__data_rd_w);
        VL_FFLUSH_I(vlSelfRef.top__DOT__genblk1__DOT_____05Ftrace_fd);
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 2> &out, const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/eshaa/overclocked-test/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/eshaa/overclocked-test/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
