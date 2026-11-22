// =============================================================================
// signals.h - maps OoO trace events onto signals inside the `pd` core.
//
// Used by verif/tests/trace_dump.h (event trace) and verif/tests/tracegen.v
// (end-of-simulation detection). See verif/README.md for the trace format.
//
// Each trace event is printed only when its *_VALID macro is defined, so a
// stage that is not built yet simply produces no lines. When you implement a
// stage, define its macros here; do not edit trace_dump.h unless the format
// itself changes.
//
// All macros are evaluated at the NEGATIVE clock edge, i.e. they describe what
// the core will do at the next rising edge (dispatch, issue, writeback...).
// =============================================================================

`define CORE dut.core

// ----- [F] fetch: instruction handed from fetch to decode -------------------
`define F_VALID      (`CORE.f_valid && !`CORE.ds_stall)
`define F_PC        `CORE.f_instr_pc
`define F_INSN      `CORE.f_instr_out

// ----- [D] dispatch: instruction allocated into the scoreboard tables -------
`define D_VALID      `CORE.ds_en
`define D_PC        `CORE.d_pc
`define D_FU        `CORE.ds_assigned_fu_id
`define D_RD        `CORE.d_addr_rd
`define D_RS1       `CORE.d_addr_rs1
`define D_RS2       `CORE.d_addr_rs2
`define D_RS1_TAG   `CORE.ds_rs1_tag
`define D_RS2_TAG   `CORE.ds_rs2_tag
// instr_status row index the dispatched instruction is written to (Phase 1, task 1.6)
`define D_IST_IDX   `CORE.ds_ist_idx
// NONE-class instruction (FENCE/unknown) consumed as a no-op without a table row
`define D_NOP_VALID  (`CORE.d_valid && `CORE.ds_is_nop)

// ----- [I] issue: operands read, instruction issued to its FU ------------
// Valid in the issue cycle (N+1), one cycle after the row was selected.
// op1/op2 are the raw rs1/rs2 values read (forwarded or RF), even when the
// instruction does not use that source (e.g. op2 of an I-type).
`define I_VALID      `CORE.iss_valid
`define I_IST_IDX   `CORE.iss_ist_idx
`define I_PC        `CORE.iss_pc
`define I_FU        `CORE.iss_fu_id
`define I_OP1       `CORE.iss_op1
`define I_OP2       `CORE.iss_op2

// ----- [X] execute complete: an FU result became valid ----------------------
// Indexed by FU row i (FU id = i + 1): several FUs can complete in one cycle
// (e.g. the MCM and an ALU), so trace_dump.h loops over the rows and prints a
// line for each FU whose result_valid is high now and was low one cycle ago
// (the first cycle its result is valid).
`define X_NUM_FU      6
`define X_VALID(i)    `CORE.fu_result_valid[i]
`define X_IST_IDX(i)  `CORE.funcStatus.ist_idx_arr[i]
`define X_PC(i)       `CORE.funcStatus.pc_arr[i]
`define X_RESULT(i)   `CORE.fu_result[(i)*32 +: 32]

// ----- [M] memory write: store FU writes dmemory (D6: in Execute) -----------
// The store FU drives the dmemory write port in its memory cycle (the cycle
// after its issue cycle); the write lands at the next rising edge.
`define M_VALID     `CORE.dmem_w_en
`define M_PC        `CORE.dmem_w_pc
`define M_ADDR      `CORE.dmem_w_address
`define M_SIZE_ENC  `CORE.dmem_w_access_size
`define M_DATA      `CORE.dmem_w_data

// ----- [W] writeback ---------------------------------------------------------
// The wb_* bus exists in pd.v (tied to constants until Phase 4).
`define W_VALID      `CORE.wb_en
`define W_PC        `CORE.wb_pc
`define W_ENABLE    `CORE.wb_writes_rd
`define W_DEST      `CORE.wb_rd
`define W_DATA      `CORE.wb_data

// ----- [S] dispatch stall reasons -------------------------------------------
`define S_VALID      `CORE.ds_stall
`define S_BUF_FULL  `CORE.ds_instr_buffer_full
`define S_NO_FU     (`CORE.ds_assigned_fu_id == 0)
`define S_WAW       `CORE.ds_WAW_status
`define S_BR_DRAIN  `CORE.br_busy

// ----- end of simulation ----------------------------------------------------
// TODO(Phase 5): end-of-program condition. ECALL is a bubble with no halt
// (plan.md D8), so this cannot key off a halt flag.
// When defined, tracegen.v ends the simulation SIM_DONE_DELAY cycles after
// this goes high; otherwise the run ends at TIMEOUT (clockgen.sv).
// `define SIM_DONE  (<end-of-program condition> && <tables empty>)

// ----- design -----
`define TOP_MODULE  pd
`define IMEMORY     imem
`define DMEMORY     dmem
