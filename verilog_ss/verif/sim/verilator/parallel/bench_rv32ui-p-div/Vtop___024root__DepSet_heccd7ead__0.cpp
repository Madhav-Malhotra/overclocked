// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
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
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r = 0;
    IData/*17:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = vlSelf->top__DOT__clkg__DOT__counter;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0U;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)))) {
        if (vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2;
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = (0x3ffffU & ((vlSelf->top__DOT__dut__DOT__core__DOT__pc_r 
                                - (IData)(0x1000000U)) 
                               >> 2U));
        }
    }
    if (vlSelf->top__DOT__reset) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r = 0x1000000U;
        vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr = 0U;
    } else if (vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w;
        vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr = 0x13U;
    } else if (vlSelf->top__DOT__dut__DOT__core__DOT__stall) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr 
            = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
                ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
                : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
    } else {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r 
            = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) 
                | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w
                : vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w);
        vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr 
            = vlSelf->top__DOT__dut__DOT__core__DOT__instr_w;
    }
    if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__instr_w 
            = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem
            [(0x3ffffU & ((vlSelf->top__DOT__dut__DOT__core__DOT__pc_r 
                           - (IData)(0x1000000U)) >> 2U))];
    }
    if (((~ (IData)(vlSelf->top__DOT__reset)) & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r))) {
        if ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r);
        } else if ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 8U));
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r);
        } else {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                   >> 0x18U);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xfffffU & ((IData)(2U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r);
        }
    }
    if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                  | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                     | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                        | ((IData)(vlSelf->top__DOT__reset) 
                           | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))))))))) {
        __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
        __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    }
    if ((1U & (~ (IData)(vlSelf->top__DOT__reset)))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r 
            = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w 
        = ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
            [(0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
            << 0x18U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                          [(0xfffffU & ((IData)(2U) 
                                        + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
                          << 0x10U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                        [(0xfffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r))] 
                                        << 8U) | vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                       [(0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)])));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r));
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd 
        = ((IData)(vlSelf->top__DOT__reset) || ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) 
                                                || (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                   >> 0xfU))];
    if (vlSelf->top__DOT__reset) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r = 0U;
    } else {
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                   >> 0x19U);
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                   >> 0x14U))];
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    top__DOT__dut__DOT__core__DOT__wb_sel = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
                                              ? 0U : 
                                             (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                                               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                                               ? 2U
                                               : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
    if (vlSelf->top__DOT__reset) {
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0x13U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                            >> 0xfU));
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                            >> 0x14U));
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r 
                = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                         >> 0xcU));
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r 
                = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w);
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                            >> 7U));
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r = __Vdly__top__DOT__dut__DOT__core__DOT__pc_r;
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    }
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
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r);
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = (((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
            & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
               & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                  & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
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
    __VdfgTmp_h556d0b02__0 = ((0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                              | (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)));
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
    top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0)
                     ? 2U : 0U));
    __Vdly__top__DOT__clkg__DOT__counter = ((IData)(1U) 
                                            + vlSelf->top__DOT__clkg__DOT__counter);
    vlSelf->top__DOT__reset = VL_GTS_III(32, 5U, vlSelf->top__DOT__clkg__DOT__counter);
    if (VL_UNLIKELY((0xc350U == vlSelf->top__DOT__clkg__DOT__counter))) {
        VL_FINISH_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog/verif/tests/clockgen.sv", 40, "");
    }
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 
        = (1U & (~ ((0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r)) 
                    | (IData)(__VdfgTmp_h556d0b02__0))));
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
    top__DOT__dut__DOT__core__DOT__idata1_in = ((2U 
                                                 == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel))
                                                 ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                                                 : 
                                                ((3U 
                                                  == (IData)(top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel))
                                                  ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                                                  : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelf->top__DOT__clkg__DOT__counter = __Vdly__top__DOT__clkg__DOT__counter;
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
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->top__DOT__reset))))) {
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r,
                   7,(0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                               >> 7U)),5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                   >> 0xfU)),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                               >> 0x14U)),3,(7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                   >> 0xcU)),
                   7,(vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                      >> 0x19U),32,vlSelf->top__DOT__dut__DOT__core__DOT__imm_w,
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                               >> 0x14U)));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                               >> 0xfU)),5,(0x1fU & 
                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                             >> 0x14U)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r,
                   1,((~ (IData)(vlSelf->top__DOT__reset)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r)),
                   2,(3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r,
                   1,(1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                               | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                                  | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                                     | ((IData)(vlSelf->top__DOT__reset) 
                                        | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)))))))),
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
