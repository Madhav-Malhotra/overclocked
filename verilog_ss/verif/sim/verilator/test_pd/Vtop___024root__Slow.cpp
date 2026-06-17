// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*6:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__NOP_OPCODE;
constexpr CData/*6:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__LOAD_OPCODE;
constexpr CData/*6:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__STORE_OPCODE;
constexpr CData/*6:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__BRANCH_OPCODE;
constexpr CData/*6:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__ECALL_OPCODE;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__REG;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__PC;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__IMM;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__WX_BYPASS_0;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__WX_BYPASS_1;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__MX_BYPASS_0;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__MX_BYPASS_1;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__BYTE_OP;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__HALF_OP;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__WORD_OP;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__ADD;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SUB;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SLL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SRL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SRA;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SLT;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__SLTU;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__XOR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__OR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__AND;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__NOP;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__MUL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__DIV;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__DIVU;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__WB_MEM;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__WB_ALU;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__WB_PC4;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__REG;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__PC;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__WX_BYPASS_0;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__WX_BYPASS_1;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__MX_BYPASS_0;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__MX_BYPASS_1;
constexpr CData/*2:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__IMM;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__ADD;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SUB;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SLL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SRL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SRA;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SLT;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__SLTU;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__XOR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__OR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__AND;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__NOP;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__MUL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__DIV;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__DIVU;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__ADD;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SUB;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SLL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SRL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SRA;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SLT;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__SLTU;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__XOR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__OR;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__AND;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__NOP;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__MUL;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__DIV;
constexpr CData/*3:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__DIVU;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__wb1__DOT__WB_MEM;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__wb1__DOT__WB_ALU;
constexpr CData/*1:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__wb1__DOT__WB_PC4;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__DATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__BASE_ADDR;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__ADDRW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__N_BITS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__NOP_INSTR;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__imem1__DOT__START_ADDR;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec1__DOT__DATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec1__DOT__ADDRW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec1__DOT__N_BITS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec1__DOT__IMM_SIZE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec1__DOT__IMM_UJ_SIZE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec2__DOT__DATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec2__DOT__ADDRW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec2__DOT__N_BITS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec2__DOT__IMM_SIZE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dec2__DOT__IMM_UJ_SIZE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__rf1__DOT__DATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__rf1__DOT__ADDRW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__rf1__DOT__NUM_REGS;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__rf1__DOT__BASE_ADDR;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__DATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__cs1__DOT__ADDRW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__bc1__DOT__IDATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__bc2__DOT__IDATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__IDATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al1__DOT__ODATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__IDATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__al2__DOT__ODATAW;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__dmem1__DOT__BASE;
constexpr IData/*31:0*/ Vtop___024root::top__DOT__dut__DOT__core__DOT__wb1__DOT__DATAW;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop___024root::~Vtop___024root() {
}
