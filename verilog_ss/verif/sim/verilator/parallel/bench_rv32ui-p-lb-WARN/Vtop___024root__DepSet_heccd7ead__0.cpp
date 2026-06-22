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
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1 = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 = 0;
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
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12 = 0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13;
    __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13;
    __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13 = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = vlSelf->top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1 = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 = 0U;
    if (((~ (IData)(vlSelf->top__DOT__reset)) & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1))) {
        if ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1);
        } else if ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
                            >> 8U));
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1);
        } else {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
                   >> 0x18U);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10 
                = (0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11 
                = (0xfffffU & ((IData)(2U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1);
        }
    }
    if (((~ (IData)(vlSelf->top__DOT__reset)) & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0))) {
        if ((0U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0);
        } else if ((1U == (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0)))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
                            >> 8U));
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0);
        } else {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
                   >> 0x18U);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xfffffU & ((IData)(2U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0);
        }
    }
    if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
                  | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                     | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                        | ((IData)(vlSelf->top__DOT__reset) 
                           | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0))))))))) {
        __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0;
        __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0;
    }
    if ((1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
                  | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                     | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                        | ((IData)(vlSelf->top__DOT__reset) 
                           | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1))))))))) {
        __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1;
        __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 = 1U;
        __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_0 
        = ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
            [(0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0))] 
            << 0x18U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                          [(0xfffffU & ((IData)(2U) 
                                        + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0))] 
                          << 0x10U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                        [(0xfffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0))] 
                                        << 8U) | vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                       [(0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0)])));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_1 
        = ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
            [(0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1))] 
            << 0x18U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                          [(0xfffffU & ((IData)(2U) 
                                        + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1))] 
                          << 0x10U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                        [(0xfffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1))] 
                                        << 8U) | vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                       [(0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1)])));
    if ((1U & (~ (IData)(vlSelf->top__DOT__reset)))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_0 
            = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0);
        vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r_1 
            = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1);
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0));
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
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v7;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v8;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v9;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10) {
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v10;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v11;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v12;
        vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v13;
    }
    if (vlSelf->top__DOT__reset) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1 = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 = 0x1000000U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1 = 0x1000004U;
        vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 = 0U;
    } else {
        if (vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1) {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1;
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1 
                = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1;
        } else {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1 
                = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1)
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1
                    : vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1);
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1 
                = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0) 
                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1
                    : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1) 
                        | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0))
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1
                        : vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_1));
        }
        if (vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0) {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0;
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0;
            vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 = 0x13U;
        } else if (vlSelf->top__DOT__dut__DOT__core__DOT__stall_0) {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0;
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0;
            vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 
                = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0)
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0
                    : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0);
        } else {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0;
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0 
                = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0) 
                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0
                    : vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_0);
            vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0;
        }
    }
    if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0)))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem
            [(0x3ffffU & ((vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0 
                           - (IData)(0x1000000U)) >> 2U))];
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1 
        = ((IData)(vlSelf->top__DOT__reset) ? 0U : 
           ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1)
             ? 0x13U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1)
                         ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1)
                             ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1
                             : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1)
                         : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1)));
    if ((1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0)))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem
            [(0x3ffffU & ((vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1 
                           - (IData)(0x1000000U)) >> 2U))];
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0 
        = ((IData)(vlSelf->top__DOT__reset) || ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0) 
                                                || (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1 
        = ((IData)(vlSelf->top__DOT__reset) || ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1) 
                                                || (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                   >> 0xfU))];
    if (vlSelf->top__DOT__reset) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0 = 0U;
    } else {
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1 = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_1 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_1 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                   >> 0x19U);
        }
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0 = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r_0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r_0 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                   >> 0x19U);
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                   >> 0x14U))];
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                   >> 0xfU))];
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                   >> 0x14U))];
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    top__DOT__dut__DOT__core__DOT__wb_sel_1 = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_1)
                                                ? 0U
                                                : (
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_1) 
                                                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_1))
                                                    ? 2U
                                                    : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    top__DOT__dut__DOT__core__DOT__wb_sel_0 = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r_0)
                                                ? 0U
                                                : (
                                                   ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r_0) 
                                                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r_0))
                                                    ? 2U
                                                    : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_1) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_1));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r_0) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0 
        = ((1U & (~ (IData)(vlSelf->top__DOT__reset))) 
           && (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
    if (vlSelf->top__DOT__reset) {
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1 = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0 = 0U;
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1;
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_1) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1 = 0x13U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1 = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_1 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                            >> 0xfU));
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_1 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                            >> 0x14U));
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_1 
                = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                         >> 0xcU));
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1 
                = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1);
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_1 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                            >> 7U));
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0;
        if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_0) 
             | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0 = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0 = 0x13U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0 = 0U;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                            >> 0xfU));
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                            >> 0x14U));
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r_0 
                = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                         >> 0xcU));
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0 
                = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0);
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r_0 
                = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                            >> 7U));
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 
            = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0 = __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1 = __Vdly__top__DOT__dut__DOT__core__DOT__pc_r_1;
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v1;
    }
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
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_0 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w_1 
        = ((IData)(8U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1);
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_1))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1))));
    top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r_0))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hbba80790__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_1));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7baa0e25__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb45f84ab__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9da63728__0));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h9fe792d4__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg_0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h8d359ce2__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc4811cac__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9e136afe__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0 
        = __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_0;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1 
        = __Vdly__top__DOT__dut__DOT__core__DOT__pc_fd_r_1;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_hebd32f91__0 
        = ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
               & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)))) 
           & ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
                  | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1)) 
                     | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_1))))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_1) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_1)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1))));
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
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h6cad94ad__0 
        = ((~ ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
               & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)))) 
           & ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                  | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0)) 
                     | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r_0))))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0)) 
           & ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0) 
                  | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r_0) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r_0)))) 
              & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT__stall_occured 
        = (4U == (vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1 
                  - vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_1)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_1
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h604d6217__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h80aa62ad__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_1) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hea038032__0));
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
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd_0)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr_0
            : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0);
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he489310c__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h4101208a__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r_0) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r_0)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9185bfd__0));
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
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h7f8c3791__0 
        = ((0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)) 
           | (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_1)));
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
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hc82ee4e8__0 
        = ((0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
           | (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)));
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_he9247148__0 
        = (1U & (~ ((0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)) 
                    | (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r_0)))));
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
    __Vdly__top__DOT__clkg__DOT__counter = ((IData)(1U) 
                                            + vlSelf->top__DOT__clkg__DOT__counter);
    vlSelf->top__DOT__reset = VL_GTS_III(32, 5U, vlSelf->top__DOT__clkg__DOT__counter);
    if (VL_UNLIKELY((0xc350U == vlSelf->top__DOT__clkg__DOT__counter))) {
        VL_FINISH_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog_ss/verif/tests/clockgen.sv", 40, "");
    }
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
    vlSelf->top__DOT__clkg__DOT__counter = __Vdly__top__DOT__clkg__DOT__counter;
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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->top__DOT__reset))))) {
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_0,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_0);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_r_1,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__instr_w_1);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_0,
                   7,(0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                               >> 7U)),5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                   >> 0xfU)),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                               >> 0x14U)),3,(7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                                   >> 0xcU)),
                   7,(vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                      >> 0x19U),32,vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_0,
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                               >> 0x14U)));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r_1,
                   7,(0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                               >> 7U)),5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                   >> 0xfU)),
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                               >> 0x14U)),3,(7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                                   >> 0xcU)),
                   7,(vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                      >> 0x19U),32,vlSelf->top__DOT__dut__DOT__core__DOT__imm_w_1,
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                               >> 0x14U)));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                               >> 0xfU)),5,(0x1fU & 
                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_0 
                                             >> 0x14U)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",
                   5,(0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                               >> 0xfU)),5,(0x1fU & 
                                            (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w_1 
                                             >> 0x14U)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r_2,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r_2);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_0,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_0,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_0));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r_1,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w_1,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken_1));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_0,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_0,
                   1,((~ (IData)(vlSelf->top__DOT__reset)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_0)),
                   2,(3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_0)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_0);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r_1,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r_1,
                   1,((~ (IData)(vlSelf->top__DOT__reset)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r_1)),
                   2,(3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r_1)),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in_1);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_0,
                   1,(1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h6779d008__0) 
                               | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                                  | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_0)) 
                                     | ((IData)(vlSelf->top__DOT__reset) 
                                        | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0)))))))),
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_0),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_0);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r_1,
                   1,(1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hce7ac8ac__0) 
                               | ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                                  | ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r_1)) 
                                     | ((IData)(vlSelf->top__DOT__reset) 
                                        | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1)))))))),
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r_1),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w_1);
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
            VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog_ss/verif/tests/test_pd.sv", 4, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog_ss/verif/tests/test_pd.sv", 4, "", "Active region did not converge.");
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
