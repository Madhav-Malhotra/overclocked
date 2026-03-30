#include "Vdesign_wrapper.h"
#include "Vdesign_wrapper___024root.h" // needed for internal ptrs
#include "verilated.h"
#include <cstdint>


static Vdesign_wrapper * design = nullptr;
static VerilatedContext* contextp = nullptr;


extern "C" {
struct CPUState {
    uint32_t pc;
    uint32_t instruction;
    uint32_t registers[32]; // register file
    // alu.v
    uint32_t alu_out; 
    // branch_comp.v
    uint8_t br_eq;
    uint8_t br_lt;
    // control_signals.v
    uint8_t branch_comp_data1_sel; // 
    uint8_t branch_comp_data2_sel; // 
    uint8_t br_taken;              // 
    uint8_t pc_sel;                // 
    uint8_t br_un;                 // 
    uint8_t a_sel;                 // [1:0]
    uint8_t b_sel;                 // [1:0]
    uint8_t alu_sel;               // [3:0]
    uint8_t mem_rw;                // 
    uint8_t reg_wen;               // 
    uint8_t wb_sel;                // [1:0]
    // decoder.v
    uint8_t opcode;         // [6:0]
    uint8_t addr_rd;        // [ADDRW-1:0]
    uint8_t addr_rs1;       // [ADDRW-1:0]
    uint8_t addr_rs2;       // [ADDRW-1:0]
    uint8_t funct3;         // [2:0]
    uint8_t funct7;         // [6:0]
    uint32_t imm;           // [DATAW-1:0] (32-bit)
    uint8_t shamt;          // [N_BITS-1:0] (Shift amount, typically 5 bits)
    uint8_t is_u_type_w;    // 1-bit
    uint8_t is_j_type_w;    // 1-bit
    uint8_t is_i_type_w;    // 1-bit
    // dmemory.v
    uint32_t dmem_data_out; // [31:0]
    // imemory.v
    uint32_t imem_data_out; // [31:0]
    // register_file.v
    uint32_t data_rs1;       // [DATAW-1:0]
    uint32_t data_rs2;       // [DATAW-1:0]
    // writeback.v
    uint32_t wb_data; // dependent on DATAW=32
    //
    // specific pipeline stages
    // xm stage
    uint32_t dmem_data_in;
    // mw stage
    uint32_t wb_in_alu;
    uint32_t mem;
    uint32_t pc4;
};
// CPU state := outputs of every module
// pick modules here to add to the state (can be incremental)
void get_cpu_state(CPUState* out_state) {
    if (!design || !out_state) return;
    out_state->pc          = design->rootp->design_wrapper__DOT__core__DOT__pc_r;
    out_state->instruction = design->rootp->design_wrapper__DOT__core__DOT__instr_fd_w;
    for (int i = 0; i < 32; i++) {
        out_state->registers[i] = design->rootp->design_wrapper__DOT__core__DOT__rf1__DOT__regs[i];
    }
    out_state->alu_out     = design->rootp->design_wrapper__DOT__core__DOT__alu_xm_r;
    // branch_comp.v
    out_state->br_eq = design->rootp->design_wrapper__DOT__core__DOT__br_eq;
    out_state->br_lt = design->rootp->design_wrapper__DOT__core__DOT__br_lt;
    // control_signals.v
    out_state->branch_comp_data1_sel = design->rootp->design_wrapper__DOT__core__DOT__branch_comp_data1_sel;
    out_state->branch_comp_data2_sel = design->rootp->design_wrapper__DOT__core__DOT__branch_comp_data2_sel;
    out_state->br_un = design->rootp->design_wrapper__DOT__core__DOT__br_un;
    out_state->a_sel = design->rootp->design_wrapper__DOT__core__DOT__a_sel;
    out_state->b_sel = design->rootp->design_wrapper__DOT__core__DOT__b_sel;
    out_state->alu_sel = design->rootp->design_wrapper__DOT__core__DOT__alu_sel;
    out_state->mem_rw = design->rootp->design_wrapper__DOT__core__DOT__data_mem_rw;
    out_state->reg_wen = design->rootp->design_wrapper__DOT__core__DOT__reg_wen;
    out_state->wb_sel = design->rootp->design_wrapper__DOT__core__DOT__wb_sel;
    // decoder.v
    // I think as long as we stay consistent in which pipeline stage to use, dx_r makes sense
    // and luckily it's pretty easy to change with the bridge
    out_state->opcode = design->rootp->design_wrapper__DOT__core__DOT__opcode_dx_r;
    out_state->addr_rd = design->rootp->design_wrapper__DOT__core__DOT__addr_rd_dx_r;
    out_state->addr_rs1 = design->rootp->design_wrapper__DOT__core__DOT__addr_rs1_dx_r;
    out_state->addr_rs2 = design->rootp->design_wrapper__DOT__core__DOT__addr_rs2_dx_r;
    out_state->funct3 = design->rootp->design_wrapper__DOT__core__DOT__funct3_dx_r;
    out_state->funct7 = design->rootp->design_wrapper__DOT__core__DOT__cs1__DOT__funct7_dx_r;
    out_state->imm = design->rootp->design_wrapper__DOT__core__DOT__imm_dx_r;
    out_state->shamt = design->rootp->design_wrapper__DOT__core__DOT__shamt_w;
    out_state->is_u_type_w = design->rootp->design_wrapper__DOT__core__DOT__cs1__DOT__is_u_type_x;
    out_state->is_j_type_w = design->rootp->design_wrapper__DOT__core__DOT__is_j_type;
    out_state->is_i_type_w = design->rootp->design_wrapper__DOT__core__DOT__is_i_type;
    // dmemory.v
    out_state->dmem_data_out = design->rootp->design_wrapper__DOT__core__DOT__dmem1__DOT__data_out;
    // imemory.v
    out_state->imem_data_out = design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__data_out;
    // register_file.v
    out_state->data_rs1 = design->rootp->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs1_r;
    out_state->data_rs2 = design->rootp->design_wrapper__DOT__core__DOT__rf1__DOT__data_rs2_r;
    // writeback.v
    out_state->wb_data = design->rootp->design_wrapper__DOT__core__DOT__data_rd_w;

    // more specific pipeline stage data:
    // xm
    out_state->dmem_data_in = design->rootp->design_wrapper__DOT__core__DOT__dmem_data_in;
    // mw
    out_state->wb_in_alu = design->rootp->design_wrapper__DOT__core__DOT__alu_mw_r;
    out_state->mem = design->rootp->design_wrapper__DOT__core__DOT__data_mem_w_sized;
    out_state->pc4 = design->rootp->design_wrapper__DOT__core__DOT__pc4_mw_r;
}


void tick() {
    design->clock = 1;
    design->eval();
    design->clock = 0;
    design->eval();
}

void init_design_wrapper() {
    if (!design) {
        contextp = new VerilatedContext;
        design = new Vdesign_wrapper(contextp);
    }
    design->eval();
    design->reset = 1;
    tick();
    design->reset = 0;
    design->eval(); 
    // don't tick here because it advances the clock
}

void eval() {
    design->eval();
}

void cleanup_design_wrapper() {
    if (design) {
        design->final();
        delete design;
        delete contextp;
        design = nullptr;
        contextp = nullptr;
    }
}


void set_fetch_en (bool val) {
    design->rootp->design_wrapper__DOT__core__DOT__fetch_en = val;
}

void set_fd_en (bool val) {
    design->rootp->design_wrapper__DOT__core__DOT__fd_en = val;
}

void set_dx_en (bool val) {
    design->rootp->design_wrapper__DOT__core__DOT__dx_en = val;
}

void set_xm_en (bool val) {
    design->rootp->design_wrapper__DOT__core__DOT__xm_en = val;
}

void set_mw_en (bool val) {
    design->rootp->design_wrapper__DOT__core__DOT__mw_en = val;
}

// instruction memory access
// load instructions for the level, then tick the CPU to advance
// utility functions to view the instruction memory contents
// Write an instruction to memory
void set_imem(uint32_t real_addr, uint32_t instruction) {
    const uint32_t START_ADDR = 0x01000000;

    // Safety check to ensure we don't write out of bounds
    if (real_addr >= START_ADDR) {
        uint32_t ea = (real_addr - START_ADDR) >> 2;
        design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[ea] = instruction;
    }
}

// Read an instruction from memory
uint32_t peek_imem(uint32_t real_addr) {
    const uint32_t START_ADDR = 0x01000000;
    if (real_addr >= START_ADDR) {
        uint32_t ea = (real_addr - START_ADDR) >> 2;
        return design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[ea];
    }
    return 0;
}

// Display the first `count` instructions in the imem 
void dump_imem(uint32_t count) {
    printf("--- IMEM DUMP ---\n");
    for (uint32_t i = 0; i < count; i++) {
        uint32_t val = design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[i];
        printf("Addr [%04d]: 0x%08X\n", i, val);
    }
    printf("-----------------\n");
}

// Display the first `count` entries in the data memory
void dump_dmem(uint32_t count) {
    printf("--- DMEM DUMP ---\n");
    for (uint32_t i = 0; i < count; i++) {
        uint32_t val = design->rootp->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[i];
        printf("Addr [%04d]: 0x%08X\n", i, val);
    }
    printf("-----------------\n");
}

}


