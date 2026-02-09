#include "Vtop.h"
#include "verilated.h"


static Vtop* alu = nullptr;
static VerilatedContext* contextp = nullptr;

extern "C" {
    void init_alu() {
        if (!alu) {
            contextp = new VerilatedContext;
            alu = new Vtop{contextp};
        }
    }

    // 2. Operation: Call this as many times as you want
    int execute_alu(int a, int b, uint8_t sel) {
        if (!alu) return 0; // Guard against uninitialized calls

        alu->idata1 = a;
        alu->idata2 = b;
        alu->alu_sel = sel;
        
        alu->eval(); 
        
        return alu->odata;
    }

    // 3. Cleanup: Call this before the C# program exits
    void cleanup_alu() {
        if (alu) {
            alu->final();
            delete alu;
            delete contextp;
            alu = nullptr;
            contextp = nullptr;
        }
    }

}

