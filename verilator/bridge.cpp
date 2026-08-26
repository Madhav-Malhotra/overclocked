/*
 * bridge.cpp — C Foreign Function Interface bridge between the Verilated 
 * RISC-V processor and C# (Unity).
 *
 * Exposes a flat C API (extern "C") so that C#'s P/Invoke can call into the
 * Verilated simulation without C++ name-mangling issues.  The shared library
 * produced from this file (.so / .dll) is loaded at runtime by CPU.cs.
 * (the bridge that Unity uses to talk to the Verilated model).
 *
 * Responsibilities:
 *   - Lifecycle management: init / cleanup the Verilated model instance.
 *   - Clock control: tick() drives one full rising+falling edge.
 *   - State snapshot: get_cpu_state() copies every observable wire/register
 *     into a flat CPUState struct that C# can marshal by value.
 *   - Memory access: clear_imem / set_imem / peek_imem / dump_imem / dump_dmem
 *     allow the host to load programs and inspect memory contents.
 *
 * ⚠️ Update this file whenever:
 *   - The Verilog design is re-Verilated (internal signal paths may change).
 *   - AND new signals need to be surfaced to the C# layer.
 *
 * See verilator/README.md for build instructions.
 */

#include "Vdesign_wrapper.h"
#include "Vdesign_wrapper___024root.h" // needed for internal ptrs
#include "verilated.h"
#include <cstdint>


static Vdesign_wrapper * design = nullptr;
static VerilatedContext* contextp = nullptr;

// Required by verilated.cpp (declared as a weak extern in verilated_funcs.h).
// We don't use SystemC, so simulation time isn't tracked here; some linkers
// (unfortunately macOS's ld) require this weak symbol to be resolved explicitly.
double sc_time_stamp() { return 0; }

extern "C" {
// Making sure memory alignment matches what C# in Unity expects
#pragma pack(push, 1)
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
    // fd stage
    uint32_t fd_pc;
    uint32_t fd_pc4;
    uint8_t  opcode_fd;      // combinatorial decode of instr_fd_w (opcode_w)
    uint8_t  addr_rd_fd;     // combinatorial decode of instr_fd_w (addr_rd_w)
    // dx stage (per-stage copies for validator)
    uint8_t  opcode_dx;
    uint8_t  addr_rd_dx;
    uint32_t dx_pc;
    // xm stage
    uint32_t dmem_data_in;
    uint8_t  opcode_xm;
    uint8_t  addr_rd_xm;
    uint32_t xm_pc;
    // mw stage
    uint32_t wb_in_alu;
    uint32_t mem;
    uint32_t mw_pc4;
    uint8_t  opcode_mw;
    uint8_t  addr_rd_mw;
    uint32_t mw_pc;

    // multi-cycle multiplier
    uint8_t mult_start_pulse;
    uint8_t mult_hold;
    uint8_t mult_busy;

    // superscalar inter-way stalls (stall_signals.v) — always 0 for this single-issue bridge
    uint8_t stall_0;
    uint8_t stall_1;
};
#pragma pack(pop)

/*
 * get_cpu_state — Snapshot every observable signal into a CPUState struct.
 *
 * To add a new signal: extend CPUState with a matching field, then assign it
 * here using the Verilated hierarchical path design_wrapper__DOT__core__DOT__<signal>.
 *
 * @param out_state  Caller-allocated struct to fill; no-op if null.
 */
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
    out_state->funct7 = design->rootp->design_wrapper__DOT__core__DOT__funct7_dx_r;
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
    // fd
    out_state->fd_pc    = design->rootp->design_wrapper__DOT__core__DOT__pc_fd_r;
    out_state->fd_pc4   = design->rootp->design_wrapper__DOT__core__DOT__pc4_f_w;
    out_state->opcode_fd   = design->rootp->design_wrapper__DOT__core__DOT__opcode_w;
    out_state->addr_rd_fd  = design->rootp->design_wrapper__DOT__core__DOT__addr_rd_w;
    // dx
    out_state->opcode_dx   = design->rootp->design_wrapper__DOT__core__DOT__opcode_dx_r;
    out_state->addr_rd_dx  = design->rootp->design_wrapper__DOT__core__DOT__addr_rd_dx_r;
    out_state->dx_pc       = design->rootp->design_wrapper__DOT__core__DOT__pc_dx_r;
    // xm
    out_state->dmem_data_in = design->rootp->design_wrapper__DOT__core__DOT__dmem_data_in;
    out_state->opcode_xm   = design->rootp->design_wrapper__DOT__core__DOT__opcode_xm_r;
    out_state->addr_rd_xm  = design->rootp->design_wrapper__DOT__core__DOT__addr_rd_xm_r;
    out_state->xm_pc       = design->rootp->design_wrapper__DOT__core__DOT__pc_xm_r;
    // mw
    out_state->wb_in_alu = design->rootp->design_wrapper__DOT__core__DOT__alu_mw_r;
    out_state->mem       = design->rootp->design_wrapper__DOT__core__DOT__data_mem_w_sized;
    out_state->mw_pc4    = design->rootp->design_wrapper__DOT__core__DOT__pc4_mw_r;
    out_state->opcode_mw   = design->rootp->design_wrapper__DOT__core__DOT__opcode_mw_r;
    out_state->addr_rd_mw  = design->rootp->design_wrapper__DOT__core__DOT__addr_rd_mw_r;
    out_state->mw_pc       = design->rootp->design_wrapper__DOT__core__DOT__pc_mw_r;

    // multi-cycle multiplier
    out_state->mult_start_pulse = design->rootp->design_wrapper__DOT__core__DOT__al1__DOT__mult_start_pulse;
    out_state->mult_hold = design->rootp->design_wrapper__DOT__core__DOT__al1__DOT__mult_hold;
    out_state->mult_busy = design->rootp->design_wrapper__DOT__core__DOT__al1__DOT__mult_busy;

    // single-issue design has no inter-way stalls
    out_state->stall_0 = 0;
    out_state->stall_1 = 0;
}


/*
 * tick — Advance the simulation by one full clock cycle (rising then falling edge).
 *
 * Drives clock high, evaluates combinational logic, then drives clock low and
 * evaluates again so that all flip-flops latch on the rising edge as in real
 * hardware.
 */
void tick() {
    design->clock = 1;
    design->eval();
    design->clock = 0;
    design->eval();
}

/*
 * init_design_wrapper — Create the Verilated CPU model (if needed) and
 * assert reset, without ticking the clock.
 *
 * Allocates the VerilatedContext and Vdesign_wrapper singletons on first
 * call only (they are process-lifetime singletons; see cleanup_design_wrapper
 * for why they are never torn down in normal operation). Does NOT drive a
 * clock edge here — the caller must load instruction memory (clear_imem +
 * set_imem) and then call finish_reset() to perform the reset clock edge.
 * This ordering guarantees the first synchronous imem read latches the
 * freshly-loaded program, not whatever was previously in mem[] (either the
 * compiled-in $readmemh contents on first construction, or a stale previous
 * level's instructions on subsequent Play Mode sessions/scene reloads).
 *
 * reset must be asserted BEFORE eval() here, not after. On a reused `design`
 * (second+ level load), the model still holds the previous level's live
 * pipeline state (non-zero PC/registers/control signals) going into this
 * call. Evaluating combinational logic first with reset still deasserted
 * re-derives outputs from that stale state, which was observed to corrupt
 * Verilator's internal eval scheduling and crash on the next level
 * transition (segfault inside eval_step, several frames deep).
 *
 * Must be called before any other bridge function.
 */
void init_design_wrapper() {
    if (!design) {
        contextp = new VerilatedContext;
        design = new Vdesign_wrapper(contextp);
    }
    design->reset = 1;
    design->eval();
}

/*
 * finish_reset — Perform the reset clock edge and deassert reset.
 *
 * Must be called after init_design_wrapper() AND after instruction memory
 * has been fully loaded (clear_imem + set_imem calls), so the reset tick's
 * synchronous imem read latches the correct first instruction.
 */
void finish_reset() {
    tick();
    design->reset = 0;
    design->eval();
    // don't tick here because it advances the clock
}

/*
 * eval — Re-evaluate combinational logic without advancing the clock.
 *
 * Useful after directly writing internal signals (e.g. imem contents)
 * to propagate the changes through combinational paths before
 * reading back state.
 */
void eval() {
    design->eval();
}

/*
 * cleanup_design_wrapper — Finalize and free the Verilated model.
 *
 * Calls Verilator's final() hook (flushes coverage/trace data) then deletes
 * the model and context.  Safe to call even if init was never called.
 * After this returns, init_design_wrapper() can be called again to start fresh.
 */
void cleanup_design_wrapper() {
    if (design) {
        design->final();
        delete design;
        delete contextp;
        design = nullptr;
        contextp = nullptr;
    }
}


/*
 * Instruction / data memory access utilities.
 *
 * These functions bypass the processor's normal fetch/store path and read or
 * write memory arrays directly.  Typical usage: call set_imem() for each word
 * of the program AFTER init_design_wrapper() ticks the CPU, then use
 * peek_imem() / dump_imem() / dump_dmem() for debugging.
 *
 * Address space: imem starts at START_ADDR = 0x01000000 (matches imemory.v).
 * Addresses are word-indexed internally ((addr - START_ADDR) >> 2).
 */

/*
 * set_imem — Write one 32-bit instruction word into instruction memory.
 *
 * @param real_addr   Byte address in the CPU's address space (>= 0x01000000).
 * @param instruction 32-bit encoded RISC-V instruction to store.
 *
 * No-op if real_addr is below START_ADDR (prevents out-of-bounds writes).
 */
void set_imem(uint32_t real_addr, uint32_t instruction) {
    const uint32_t START_ADDR = 0x01000000;

    // Safety check to ensure we don't write out of bounds
    if (real_addr >= START_ADDR) {
        uint32_t ea = (real_addr - START_ADDR) >> 2;
        design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[ea] = instruction;
    }
}

/*
 * clear_imem — Zero the entire instruction memory array.
 *
 * Must be called before set_imem() on every CPU construction (fresh or
 * reused `design` singleton) so addresses beyond the level's own program
 * read as zero instead of leftover words from the compiled-in $readmemh
 * program or a previously-loaded level. MEM_DEPTH/4 (word count) is
 * hardcoded here to match verilator/Makefile's MEM_DEPTH=1048576 — it is a
 * Verilog-only preprocessor define (passed via V_FLAGS to `verilator -cc`,
 * Makefile:18,46-47) and is not visible to this translation unit.
 */
void clear_imem() {
    const uint32_t MEM_WORDS = 1048576 / 4;
    for (uint32_t i = 0; i < MEM_WORDS; i++) {
        design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[i] = 0;
    }
}

/*
 * peek_imem — Read one 32-bit instruction word from instruction memory.
 *
 * @param real_addr  Byte address in the CPU's address space (>= 0x01000000).
 * @return           The stored instruction word, or 0 if address is out of range.
 */
uint32_t peek_imem(uint32_t real_addr) {
    const uint32_t START_ADDR = 0x01000000;
    if (real_addr >= START_ADDR) {
        uint32_t ea = (real_addr - START_ADDR) >> 2;
        return design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[ea];
    }
    return 0;
}

/*
 * dump_imem — Print the first `count` instruction memory words to stdout.
 *
 * Word indices (0-based) and hex values are printed.  Useful for verifying that
 * a program was loaded correctly before running the simulation.
 *
 * @param count  Number of words to display (starting from index 0).
 */
void dump_imem(uint32_t count) {
    printf("--- IMEM DUMP ---\n");
    for (uint32_t i = 0; i < count; i++) {
        uint32_t val = design->rootp->design_wrapper__DOT__core__DOT__imem1__DOT__mem[i];
        printf("Addr [%04d]: 0x%08X\n", i, val);
    }
    printf("-----------------\n");
}

/*
 * dump_dmem — Print the first `count` data memory words to stdout.
 *
 * Complements dump_imem for inspecting heap/stack state after a simulation run.
 *
 * @param count  Number of words to display (starting from index 0).
 */
void dump_dmem(uint32_t count) {
    printf("--- DMEM DUMP ---\n");
    for (uint32_t i = 0; i < count; i++) {
        uint32_t val = design->rootp->design_wrapper__DOT__core__DOT__dmem1__DOT__mem[i];
        printf("Addr [%04d]: 0x%08X\n", i, val);
    }
    printf("-----------------\n");
}

}
