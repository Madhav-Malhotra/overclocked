#include "Vtop.h"
#include "verilated.h"


static Vtop* dmem = nullptr;
static VerilatedContext* contextp = nullptr;

enum Mode {
    // TODO maybe use this in read_write below
    READ = 0, 
    WRITE = 1,
};

extern "C" {
    void tick() {
        dmem->clock = 1;
        dmem->eval();
        dmem->clock = 0;
        dmem->eval();
    }

    void init_dmem() {
        if (!dmem) {
            contextp = new VerilatedContext;
            dmem = new Vtop{contextp};
        }
    }

    void write_dmem(unsigned int addr, unsigned int data) {
        if (!dmem) return; // Guard against uninitialized calls
        dmem->read_write = 1; // write mode is 1
        // for now, only support word-sized write
        dmem->access_size = 2;
        dmem->address = addr;
        dmem->data_in = data;
        
        tick(); // this func handles advancing the clock, but in a full CPU
    // we don't want individual bridge functions to handle tick, only game logic
    // should tick the entire system
    // so expose a system wide tick function to the c# wrapper class, but don't 
    // call it in any of the bridging functions
    }

    unsigned int read_dmem(unsigned int addr) {
        if (!dmem) return 0;
        dmem->read_write = 0;
        dmem->address = addr;
        tick();
        return dmem->data_out;
    }

    

    // 3. Cleanup: Call this before the C# program exits
    void cleanup_dmem() {
        if (dmem) {
            dmem->final();
            delete dmem;
            delete contextp;
            dmem = nullptr;
            contextp = nullptr;
        }
    }

}

