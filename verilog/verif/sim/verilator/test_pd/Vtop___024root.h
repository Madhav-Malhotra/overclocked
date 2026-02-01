// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__clock;
        CData/*0:0*/ top__DOT__reset;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__br_taken;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__opcode_dx_r;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__funct3_dx_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rs1_dx_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rs2_dx_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rd_dx_r;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__funct3_xm_r;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__opcode_xm_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rs2_xm_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rd_xm_r;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__opcode_mw_r;
        CData/*4:0*/ top__DOT__dut__DOT__core__DOT__addr_rd_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__stall;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__stall_fd;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__funct3_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__imem1__DOT__read_write_2;
        CData/*2:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__funct3_dx_r;
        CData/*6:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__funct7_dx_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_xm_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_store_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_branch_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_ecall_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_load_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jal_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT__is_jalr_mw_r;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_12;
        CData/*0:0*/ top__DOT__dut__DOT__core__DOT__cs1__DOT____VdfgRegularize_hb4f1b3e3_0_19;
        CData/*0:0*/ __Vdpi_export_trigger;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__clock__0;
        IData/*31:0*/ top__DOT__genblk1__DOT_____05Ftrace_fd;
        IData/*31:0*/ top__DOT__clkg__DOT__counter;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__instr_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__imm_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_out_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__data_mem_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__data_rd_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc4_f_w;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc_fd_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc_dx_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__imm_dx_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc_xm_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_xm_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__data_rs2_xm_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc_mw_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__prev_instr;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__pc4_mw_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__alu_mw_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__dmem_data_in;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__imem1__DOT__data_in_2;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__dec1__DOT__instr;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs1_r;
        IData/*31:0*/ top__DOT__dut__DOT__core__DOT__rf1__DOT__data_rs2_r;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 262144> top__DOT__dut__DOT__core__DOT__imem1__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__dut__DOT__core__DOT__rf1__DOT__regs;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 357> top__DOT__dut__DOT__core__DOT__dmem1__DOT__temp;
        VlUnpacked<CData/*7:0*/, 1048576> top__DOT__dut__DOT__core__DOT__dmem1__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 2> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
