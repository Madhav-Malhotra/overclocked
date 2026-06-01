// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
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
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 = 0;
    // Body
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_in_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_rw_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__dx_en 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dx_en;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__xm_en 
        = vlSelf->top__DOT__dut__DOT__core__DOT__xm_en;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mw_en 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mw_en;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r 
           - (IData)(0x1000000U));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea 
        = VL_SHIFTR_III(32,32,32, (vlSelf->top__DOT__dut__DOT__core__DOT__pc_r 
                                   - (IData)(0x1000000U)), 2U);
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw 
        = ((~ (IData)(vlSelf->top__DOT__clkg__DOT__rst)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r));
    vlSelf->top__DOT__reset = vlSelf->top__DOT__clkg__DOT__rst;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop 
        = (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned 
        = (1U & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r) 
                 >> 2U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
            ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                     ? 2U : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
               | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw;
    vlSelf->top__DOT__dut__DOT__reset = vlSelf->top__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
           & ((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
              | (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x)
            ? 0xaU : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x) 
                          | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x) 
                             | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x) 
                                | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x) 
                                   | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x))))))
                       ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                    ? 0xbU : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                               ? 0xcU
                                               : ((5U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                   ? 0xdU
                                                   : 0xaU)))
                                : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                    & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                    ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                        ? 1U : 4U) : 
                                   (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x))
                                     ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                         ? 0U : ((1U 
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x));
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size))
            ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned)
                ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                      >> 7U)))) << 8U) 
                   | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size))
                ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned)
                    ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
                : vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out));
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg));
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                    | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop) 
                          | ((IData)(vlSelf->top__DOT__clkg__DOT__rst) 
                             | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
        = vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b 
        = ((0x800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                      >> 0x14U)) | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                               << 3U)) 
                                    | ((0x3f0U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 8U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0xcU);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
        = ((0x80000U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                        >> 0xcU)) | ((0x7f800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                            >> 0x15U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 7U));
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0x19U);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 0xfU));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0x14U);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w 
        = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                 >> 0xcU));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 0x14U));
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w 
        = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w);
    vlSelf->top__DOT__dut__DOT__core__DOT__reset = vlSelf->top__DOT__dut__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
              & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x) 
                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x))));
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_un 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r
                    : 0U)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w) 
            << 5U) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__shamt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall 
        = ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w)) 
           & ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w)) 
              & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reset 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_r_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_b_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_fd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_s_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
           & ((IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0) 
              & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg))));
    vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm) 
           & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           & ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w)) 
              | (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load) 
              | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jal 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0))
            ? 3U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0))
                     ? 2U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x)
                              ? 0U : 1U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0)
                     ? 2U : 0U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x)))
            ? 1U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0))
                     ? 3U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0))
                              ? 2U : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0)
                     ? 2U : 0U));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w = 
        ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu)
          ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift)
                   ? (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)
                   : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)
                       ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                       >> 0x1fU))) 
                           << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))
                       : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)
                           ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                           >> 0x1fU))) 
                               << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s))
                           : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch)
                               ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                               >> 0x1fU))) 
                                   << 0xdU) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b) 
                                               << 1U))
                               : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)
                                   ? (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
                                      << 0xcU) : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                >> 0x1fU))) 
                                                    << 0x15U) 
                                                   | (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
                                                      << 1U))
                                                   : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                 & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w))));
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                    : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                    : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__imm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__load_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x) 
           & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0)) 
              | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                 & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                    & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                       & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)) 
                          & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw)) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
               != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                  != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r)) 
                 & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg) 
                    & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                        & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                           & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0))) 
                       | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                          & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                             & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                                & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                                   & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)))))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                ? ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? 0U : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                             ? ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : VL_DIV_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                             : ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w) 
                                                   & (0xffffffffU 
                                                      == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)))))
                : ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                        ? VL_MULS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                        ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           | vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))));
    } else if ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
        if ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       ^ vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                        < vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        ? 1U : 0U));
        } else if ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                   >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w));
            if ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                 >> 0x1fU)) {
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)));
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                       | vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       << (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)))
                : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       - vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       + vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)));
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
           == vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un)
            ? (vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
               < vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in)
            : VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in, vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = 
        ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_stall) 
         | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
               | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                     | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                            & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                           | ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))))))))) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable 
        = (1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel;
}

VL_INLINE_OPT void Vtop___024root___ico_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_comb__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__clock = vlSelf->top__DOT__clkg__DOT__clk;
    vlSelf->top__DOT__dut__DOT__clock = vlSelf->top__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__clock = vlSelf->top__DOT__dut__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__clock 
        = vlSelf->top__DOT__dut__DOT__core__DOT__clock;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop___024root___ico_comb__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtop___024root___ico_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
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
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 = 0;
    CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr;
    __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr = 0;
    CData/*0:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd;
    __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd = 0;
    CData/*6:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0;
    CData/*4:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0;
    CData/*4:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0;
    CData/*2:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r = 0;
    IData/*31:0*/ __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r = 0;
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
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 0U;
    __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 0U;
    __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
    __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 0U;
    __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
    __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd;
    __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr 
        = vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr;
    if (vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable) {
        if (vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2;
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0 
                = (0x3ffffU & vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea);
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out 
            = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem
            [(0x3ffffU & vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea)];
    }
    if (vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw) {
        if ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v0 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr);
        } else if ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size))) {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 8U));
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v1 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v2 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr);
        } else {
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                   >> 0x18U);
            __Vdlyvset__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 = 1U;
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v3 
                = (0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v4 
                = (0xfffffU & ((IData)(2U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xffU & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v5 
                = (0xfffffU & ((IData)(1U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr));
            __Vdlyvval__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
            __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem__v6 
                = (0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr);
        }
    }
    if (vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen) {
        __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
        __Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0 
            = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    }
    if (vlSelf->top__DOT__reset) {
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_r = 0x1000000U;
        __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr = 0U;
        __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd = 1U;
        vlSelf->top__DOT__dut__DOT__core__DOT__imem_in_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r = 0U;
        vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r = 0U;
    } else {
        if (vlSelf->top__DOT__dut__DOT__core__DOT__mw_en) {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r;
        } else {
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
        }
        if (vlSelf->top__DOT__dut__DOT__core__DOT__xm_en) {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w;
            vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x;
            vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x;
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r = 0U;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r = 0U;
        }
        if (vlSelf->top__DOT__dut__DOT__core__DOT__dx_en) {
            vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
            if (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken))) {
                vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r = 0U;
                vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r = 0U;
                __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r = 0U;
                vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r = 0U;
                vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r = 0U;
                __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r = 0U;
                __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r = 0x13U;
            } else {
                vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w;
                vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w;
                __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w;
                vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w;
                vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
                __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
                __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w;
            }
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r;
            vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
        }
        if (vlSelf->top__DOT__dut__DOT__core__DOT__fd_en) {
            if (vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) {
                vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
                __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr = 0x13U;
                __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd = 1U;
            } else if (vlSelf->top__DOT__dut__DOT__core__DOT__stall) {
                vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
                __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr 
                    = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
                        : vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
                __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd = 1U;
            } else {
                vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
                __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr 
                    = vlSelf->top__DOT__dut__DOT__core__DOT__instr_w;
                __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd = 0U;
            }
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r;
            __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr 
                = vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr;
            __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd 
                = vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd;
        }
        vlSelf->top__DOT__dut__DOT__core__DOT__pc_r 
            = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken)
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w
                : ((1U & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall) 
                          | (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__fetch_en))))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_r
                    : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel)
                        ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w
                        : vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w)));
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
        = ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
            [(0xfffffU & ((IData)(3U) + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr))] 
            << 0x18U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                          [(0xfffffU & ((IData)(2U) 
                                        + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr))] 
                          << 0x10U) | ((vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                        [(0xfffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr))] 
                                        << 8U) | vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem
                                       [(0xfffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr)])));
    if ((1U & (~ (IData)(vlSelf->top__DOT__reset)))) {
        if (vlSelf->top__DOT__dut__DOT__core__DOT__mw_en) {
            vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r 
                = vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w;
        }
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w];
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs
        [vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w];
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__pc_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__funct3_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr 
        = __Vdly__top__DOT__dut__DOT__core__DOT__prev_instr;
    vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd 
        = __Vdly__top__DOT__dut__DOT__core__DOT__stall_fd;
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
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
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__regs[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__rf1__DOT__regs__v0;
    }
    if (__Vdlyvset__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0) {
        vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__mem[__Vdlyvdim0__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__dut__DOT__core__DOT__imem1__DOT__mem__v0;
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_xm_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__pc4_f_w 
        = ((IData)(4U) + vlSelf->top__DOT__dut__DOT__core__DOT__pc_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__ea 
        = VL_SHIFTR_III(32,32,32, (vlSelf->top__DOT__dut__DOT__core__DOT__pc_r 
                                   - (IData)(0x1000000U)), 2U);
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs1_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size 
        = (3U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned 
        = (1U & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_mw_r) 
                 >> 2U));
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__alu 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_mw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop 
        = (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_mw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_in_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rs2_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__pc4 
        = vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r)
            ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r) 
                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r))
                     ? 2U : 1U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out;
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall_fd)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__prev_instr
            : vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__data_out);
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__access_size 
        = vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size))
            ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned)
                ? (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                      >> 7U)))) << 8U) 
                   | (0xffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__mem_read_access_size))
                ? ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_unsigned)
                    ? (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)
                    : (((- (IData)((1U & (vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out)))
                : vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_out));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg 
        = ((~ ((0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_mw_r)) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__opcode_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r 
        = __Vdly__top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_stall_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__instr 
        = vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b 
        = ((0x800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                      >> 0x14U)) | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                               << 3U)) 
                                    | ((0x3f0U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 0x15U)) 
                                       | (0xfU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 8U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0xcU);
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
        = ((0x80000U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                        >> 0xcU)) | ((0x7f800U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                  >> 1U)) 
                                     | ((0x400U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                   >> 0xaU)) 
                                        | (0x3ffU & 
                                           (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                            >> 0x15U)))));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 7U));
    vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0x19U);
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 0xfU));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
           >> 0x14U);
    vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w 
        = (7U & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                 >> 0xcU));
    vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w 
        = (0x1fU & (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                    >> 0x14U));
    vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w 
        = (0x7fU & vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w);
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__mem 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized;
    vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_w_sized
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_mw_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__wb_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__pc4_mw_r
                    : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__address 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__addr 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r 
           - (IData)(0x1000000U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_xm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__opcode_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_x 
        = (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_dx_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__addr_rd_xm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm 
        = ((0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
           & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_mw_writes_reg));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r) 
               | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r) 
                  | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r)))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct7 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w) 
            << 5U) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___funct3 
        = vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__addr_rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__shamt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___rs2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w;
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___opcode 
        = vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu 
        = (0x33U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch 
        = (0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load 
        = (3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr 
        = (0x67U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall 
        = ((0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w)) 
           & ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w)) 
              & (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store 
        = (0x23U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm 
        = (0x13U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w 
        = (0x6fU == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui 
        = (0x37U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc 
        = (0x17U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w));
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__wb1__DOT__wb_data 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
               == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r)) 
              & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg))));
    vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg 
        = ((~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_store_xm) 
               | ((0x63U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r)) 
                  | (0x73U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_xm_r))))) 
           & (0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_load_dx 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
           & ((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
              | (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_lui_x)
            ? 0xaU : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x) 
                          | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x) 
                             | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x) 
                                | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_x) 
                                   | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x))))))
                       ? 0U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                    ? 0xbU : ((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                               ? 0xcU
                                               : ((5U 
                                                   == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                                   ? 0xdU
                                                   : 0xaU)))
                                : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                    & (0x20U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct7_dx_r)))
                                    ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                        ? 1U : 4U) : 
                                   (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                                     | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_imm_x))
                                     ? ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))
                                         ? 0U : ((1U 
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
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_x));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h951a12e9__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0 
        = ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__insn_xm_writes_reg));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_r_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_b_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_store_fd 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_s_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store;
    vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_load_xm) 
           & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                 & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           & ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w)) 
              | (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu_imm) 
           | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_load) 
              | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jalr) 
                 | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_ecall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_jal 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_lui) 
           | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_auipc));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wm_forward)
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_xm_r);
    vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store) 
           & ((IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h4744d89e__0) 
              & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_xm)) 
                 & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_xm_writes_reg))));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_u_type_x) 
                    | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x))));
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_un 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_un = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel;
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r) 
            == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r)) 
           & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h9104b25d__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__imm_w = 
        ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_alu)
          ? 0U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_shift)
                   ? (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)
                   : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)
                       ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                       >> 0x1fU))) 
                           << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_i))
                       : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)
                           ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                           >> 0x1fU))) 
                               << 0xcU) | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_s))
                           : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_branch)
                               ? (((- (IData)((vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                               >> 0x1fU))) 
                                   << 0xdU) | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_b) 
                                               << 1U))
                               : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)
                                   ? (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_u 
                                      << 0xcU) : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)
                                                   ? 
                                                  (((- (IData)(
                                                               (vlSelf->top__DOT__dut__DOT__core__DOT__instr_fd_w 
                                                                >> 0x1fU))) 
                                                    << 0x15U) 
                                                   | (vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT___imm_j 
                                                      << 1U))
                                                   : 0U)))))));
    top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0 
        = (1U & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                 & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__data_in 
        = vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
            & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0))
            ? 3U : (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0))
                     ? 2U : ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_alu_x)
                              ? 0U : 1U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h20741ef7__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_h51a6acf9__0)
                     ? 2U : 0U));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_auipc_x) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_x)))
            ? 1U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                     & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0))
                     ? 3U : (((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hdb338dc9__0) 
                              & (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0))
                              ? 2U : 0U)));
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel 
        = ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf11b8838__0)
            ? 3U : ((IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_ha99d47c9__0)
                     ? 2U : 0U));
    vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__imm 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imm_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__load_stall 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_x) 
           & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
               & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0)) 
              | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r) 
                  == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                 & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                    & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                       & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_store)) 
                          & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall 
        = ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__is_nop_mw)) 
           & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
               != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_xm_r)) 
              & (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                  != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_dx_r)) 
                 & ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__instr_mw_writes_reg) 
                    & ((((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                         == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                        & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w)) 
                           & (IData)(top__DOT__dut__DOT__core__DOT____VdfgTmp_h410314a4__0))) 
                       | (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r) 
                           == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                          & ((0U != (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w)) 
                             & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_u_type_w)) 
                                & ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_j_type_w)) 
                                   & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__dec1__DOT__is_i_type_w)))))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__b_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__imm_dx_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__b_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                    : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data2_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data2_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__a_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
        = ((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r
            : ((1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r
                : ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__a_sel))
                    ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
                    : vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r)));
    vlSelf->top__DOT__dut__DOT__core__DOT__branch_comp_data1_sel 
        = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel;
    vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
        = ((2U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
            ? vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w
            : ((3U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_comp_data1_sel))
                ? vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r
                : vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__stall = 
        ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_stall) 
         | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__wd_stall) 
            | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__load_store_stall) 
               | (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__store_rs2_stall))));
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata2 
        = vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata = 0U;
    vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask = 0U;
    if ((8U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                ? ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? 0U : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                             ? ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : VL_DIV_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                             : ((0U == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                                 ? 0xffffffffU : ((
                                                   (0x80000000U 
                                                    == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w) 
                                                   & (0xffffffffU 
                                                      == vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)))))
                : ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                        ? VL_MULS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                        ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                           | vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))));
    } else if ((4U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
        if ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       ^ vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                        < vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                        ? 1U : 0U));
        } else if ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))) {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w, vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    ? 1U : 0U);
        } else {
            vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                = (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                   >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w));
            if ((vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                 >> 0x1fU)) {
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask 
                    = (~ (0xffffffffU >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)));
                vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                    = (vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
                       | vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__mask);
            }
        }
    } else {
        vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata 
            = ((2U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                ? ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       >> (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w))
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       << (0x1fU & vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)))
                : ((1U & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__alu_sel))
                    ? (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       - vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)
                    : (vlSelf->top__DOT__dut__DOT__core__DOT__alu_in1_w 
                       + vlSelf->top__DOT__dut__DOT__core__DOT__alu_in2_w)));
    }
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__idata1 
        = vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in;
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq 
        = (vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
           == vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in);
    vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_un)
            ? (vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in 
               < vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in)
            : VL_LTS_III(32, vlSelf->top__DOT__dut__DOT__core__DOT__idata1_in, vlSelf->top__DOT__dut__DOT__core__DOT__idata2_in));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable 
        = (1U & (~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__stall)));
    vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w 
        = vlSelf->top__DOT__dut__DOT__core__DOT__al1__DOT__odata;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_eq 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_eq = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_lt 
        = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_lt = vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt;
    vlSelf->top__DOT__dut__DOT__core__DOT__br_taken 
        = (((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_x) 
            & (((0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
               | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_eq)) 
                   & (1U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                  | (((4U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                      & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                     | (((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                         & (5U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))) 
                        | (((6U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r)) 
                            & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                           | ((~ (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__bc1__DOT__br_lt)) 
                              & (7U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_dx_r))))))))) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__imem1__DOT__enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__imem_enable;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__br_taken 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__branch_taken 
        = vlSelf->top__DOT__dut__DOT__core__DOT__br_taken;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel 
        = ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken) 
           | (IData)(top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hf8f22c03__0));
    vlSelf->top__DOT__dut__DOT__core__DOT__pc_sel = vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__pc_sel;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vdly__top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = 0;
    // Body
    __Vdly__top__DOT__clkg__DOT__counter = vlSelf->top__DOT__clkg__DOT__counter;
    __Vdly__top__DOT__clkg__DOT__counter = ((IData)(1U) 
                                            + vlSelf->top__DOT__clkg__DOT__counter);
    vlSelf->top__DOT__clkg__DOT__rst = VL_GTS_III(32, 5U, vlSelf->top__DOT__clkg__DOT__counter);
    if (VL_UNLIKELY((0xc350U == vlSelf->top__DOT__clkg__DOT__counter))) {
        VL_FINISH_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog/verif/tests/clockgen.sv", 40, "");
    }
    vlSelf->top__DOT__clkg__DOT__counter = __Vdly__top__DOT__clkg__DOT__counter;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->top__DOT__reset))))) {
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[F] %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__instr_w);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[D] %x %x %x %x %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_fd_r,
                   7,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__opcode_w),
                   5,vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_w,
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w),
                   5,vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w,
                   3,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__funct3_w),
                   7,vlSelf->top__DOT__dut__DOT__core__DOT__funct7_w,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__imm_w,
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__shamt_w));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[R] %x %x %x %x\n",
                   5,vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs1_w,
                   5,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rs2_w),
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rs1_w,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rs2_w);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[E] %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_dx_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_out_w,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__br_taken));
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[M] %x %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_xm_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__alu_xm_r,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw),
                   2,vlSelf->top__DOT__dut__DOT__core__DOT__mem_write_access_size,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__dmem_data_in);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
        VL_FWRITEF(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd,"[W] %x %x %x %x\n",
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__pc_mw_r,
                   1,(IData)(vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen),
                   5,vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r,
                   32,vlSelf->top__DOT__dut__DOT__core__DOT__data_rd_w);
        if (vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd) { VL_FFLUSH_I(vlSelf->top__DOT__genblk1__DOT_____05Ftrace_fd); }
    }
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw 
        = ((~ (IData)(vlSelf->top__DOT__clkg__DOT__rst)) 
           & (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r));
    vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen 
        = (1U & (~ ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgTmp_hb2d03f01__0) 
                    | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_wb) 
                       | ((IData)(vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__is_nop) 
                          | ((IData)(vlSelf->top__DOT__clkg__DOT__rst) 
                             | (0U == (IData)(vlSelf->top__DOT__dut__DOT__core__DOT__addr_rd_mw_r))))))));
    vlSelf->top__DOT__dut__DOT__core__DOT__dmem1__DOT__read_write 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__mem_rw 
        = vlSelf->top__DOT__dut__DOT__core__DOT__data_mem_rw;
    vlSelf->top__DOT__dut__DOT__core__DOT__rf1__DOT__write_enable 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reg_wen 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reg_wen;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__reset = vlSelf->top__DOT__clkg__DOT__rst;
    vlSelf->top__DOT__dut__DOT__reset = vlSelf->top__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__reset = vlSelf->top__DOT__dut__DOT__reset;
    vlSelf->top__DOT__dut__DOT__core__DOT__cs1__DOT__reset 
        = vlSelf->top__DOT__dut__DOT__core__DOT__reset;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0xcULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/peri/Desktop/CAPSTONE/overclocked/verilog/verif/tests/test_pd.sv", 4, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
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
