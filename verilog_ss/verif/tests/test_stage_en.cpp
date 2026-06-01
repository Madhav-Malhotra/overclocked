// Verilator testbench
#include <iostream>
#include <verilated.h>
#ifdef VCD
#include "verilated_vcd_c.h"
#define mkstring(x) #x
#define mkstring2(x) mkstring(x)
#define VCD_FILE_STR mkstring2(VCD_FILE)
#endif
#include "Vtop.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include "Vtop___024root.h"

extern void toggleClock();

Vtop *top;
vluint64_t main_time;
double sc_time_stamp () {     // Called by $time in Verilog
    return main_time;           // converts to double, to match
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // Remember args
    top = new Vtop;
    top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
    top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 1;
    top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 1;
    top->rootp->top__DOT__dut__DOT__core__DOT__xm_en = 1;
    top->rootp->top__DOT__dut__DOT__core__DOT__mw_en = 1;

#ifdef VCD
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open(VCD_FILE_STR);
#endif

    // set the scope correctly so that we can access the clock in C testbench
    svSetScope(svGetScopeFromName("TOP.top.clkg"));
    while (!Verilated::gotFinish()) {
        if (Verilated::gotFinish()) break;
        int current_cycle = main_time/2;
        if (current_cycle == 10) {
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 0;
        }
        if (current_cycle == 15) {
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 0;
            top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 0;
            top->rootp->top__DOT__dut__DOT__core__DOT__xm_en = 0;
            top->rootp->top__DOT__dut__DOT__core__DOT__mw_en = 0;
        }
        // fetch instruction A, progress through the pipeline
        if (current_cycle == 16) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
        if (current_cycle == 17) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 0;
        if (current_cycle == 20) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 1;
        if (current_cycle == 21)
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 0;
        if (current_cycle == 25)
            top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 1;
        if (current_cycle == 26)
            top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 0;
        if (current_cycle == 28)
            top->rootp->top__DOT__dut__DOT__core__DOT__xm_en= 1;
        if (current_cycle == 29)
            top->rootp->top__DOT__dut__DOT__core__DOT__xm_en= 0;
        if (current_cycle == 32)
            top->rootp->top__DOT__dut__DOT__core__DOT__mw_en= 1;
        if (current_cycle == 33)
            top->rootp->top__DOT__dut__DOT__core__DOT__mw_en= 0;

        // imagine instruction A, B, and C are incoming
        // fetch instruction A
        if (current_cycle == 40)
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
        if (current_cycle == 41)
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 0;
        if (current_cycle == 43) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 1;
        if (current_cycle == 44)
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 0;
        if (current_cycle == 48)
            top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 1;
        if (current_cycle == 49)
            top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 0;
        // start fetching instruction B
        if (current_cycle == 56) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
        if (current_cycle == 57) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 0;
        if (current_cycle == 59) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en = 1;
        if (current_cycle == 60) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fd_en = 0;
        // start fetching instruction C
        if (current_cycle == 65) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
        if (current_cycle == 66) 
            top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 0;

        // uncomment for CPU to run "as usual" - behavior if there were no enable signals
        /*
        top->rootp->top__DOT__dut__DOT__core__DOT__fetch_en = 1;
        top->rootp->top__DOT__dut__DOT__core__DOT__fd_en= 1;
        top->rootp->top__DOT__dut__DOT__core__DOT__dx_en= 1;
        top->rootp->top__DOT__dut__DOT__core__DOT__xm_en = 1;
        top->rootp->top__DOT__dut__DOT__core__DOT__mw_en = 1;
        */

        top->eval();
        toggleClock();
#ifdef VCD
        tfp->dump(main_time);
#endif
        main_time += 1;
    }
#ifdef VCD
    tfp->close();
#endif
    delete top;
    return 0;
}

