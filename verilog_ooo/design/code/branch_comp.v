// =============================================================================
// Module:      branch_comp
// Description: Evaluates branch conditions for RV32I branch instructions.
//              Computes equality and less-than (signed or unsigned).
//              In the OoO core this is the branch functional unit (FU id 1):
//              conditional branches, JAL and JALR.
//
//              OoO differences from verilog/design/code/branch_comp.v:
//              - Two EX cycles, starting in the cycle the issued instruction
//                arrives (ex_valid):
//                  EX cycle 1 (address): the FU's adder computes the target PC
//                           target_in1 + target_in2 (pc + imm for branches
//                           and JAL, rs1 + imm for JALR with bit 0 cleared;
//                           selected by control_signals' a_sel/b_sel in pd.v),
//                           registered with rs1/rs2.
//                  EX cycle 2 (compare): the comparison below (br_eq/br_lt,
//                           br_un from control_signals) on the registered
//                           rs1/rs2 values; control_signals turns it into
//                           br_taken (JAL/JALR always taken). taken and target
//                           are registered at the end of the cycle.
//              - The outcome is held (result_valid) until writeback takes it.
//                JAL/JALR's rd = pc + 4 is written through writeback.v's
//                WB_PC4 (as in the scalar core), so the FU has no register
//                result.
//              - Fetch redirect, flushing and stalling on the outcome are not
//                implemented yet (plan.md Phase 6).
// Inputs:      clock, reset
//              ex_valid       - an issued branch/jump is in this FU's EX cycle 1
//              idata1, idata2 - 32-bit operands to compare (rs1, rs2 values)
//              target_in1, target_in2 - target adder operands (pc or rs1 value, immediate)
//              opcode, funct3 - instruction fields (registered for the compare cycle -> control_signals)
//              br_un          - 1 selects unsigned comparison, 0 selects signed
//                               (control_signals, compare cycle)
//              br_taken       - branch/jump taken (control_signals, compare cycle)
//              wb_ready       - writeback takes this FU's result this cycle
// Outputs:     fu_ready       - FU can accept an instruction (holds none)
//              cmp_opcode, cmp_funct3 - fields of the instruction in its compare cycle
//              br_eq          - asserted when idata1 == idata2 (compare cycle)
//              br_lt          - asserted when idata1 < idata2 (compare cycle)
//              result_valid   - outcome ready, waiting for writeback
//              taken          - the branch/jump is taken
//              target         - target PC (pc + imm, or (rs1 + imm) & ~1 for JALR)
// =============================================================================
module branch_comp #(
    parameter IDATAW = 32
) (
    input                   clock,
    input                   reset,

    // ====================
    // Issue -> FU (ready/valid)
    // ====================
    input                   ex_valid,
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    input      [IDATAW-1:0] target_in1,
    input      [IDATAW-1:0] target_in2,
    input      [6:0]        opcode,
    input      [2:0]        funct3,
    output                  fu_ready,

    // ====================
    // Compare cycle <-> control_signals
    // ====================
    output reg [6:0]        cmp_opcode,
    output reg [2:0]        cmp_funct3,
    // Unsigned branch
    input br_un,
    // If !(br_eq || br_lt), then br_gt inferred
    output br_eq,
    output br_lt,
    input                   br_taken,

    // ====================
    // FU -> writeback (ready/valid)
    // ====================
    output reg              result_valid,
    output reg              taken,
    output reg [IDATAW-1:0] target,
    input                   wb_ready
);

localparam OP_JALR = 7'b1100111;

// ====================
// EX CYCLE 1: TARGET ADDRESS
// ====================
wire [IDATAW-1:0] target_sum     = target_in1 + target_in2;  // target adder: pc + imm or rs1 + imm
wire [IDATAW-1:0] target_address = (opcode == OP_JALR) ? {target_sum[IDATAW-1:1], 1'b0} : target_sum;  // JALR clears bit 0

// ====================
// EX CYCLE 2: COMPARE
// ====================
reg                     cmp_valid;    // the branch is in its compare cycle
reg signed [IDATAW-1:0] cmp_rs1;      // values compared (registered idata1 / idata2)
reg signed [IDATAW-1:0] cmp_rs2;
reg        [IDATAW-1:0] cmp_target;   // its target PC

assign br_eq = (cmp_rs1 == cmp_rs2);
assign br_lt = (br_un) ?
    ( $unsigned(cmp_rs1) < $unsigned(cmp_rs2) ) :
    ( cmp_rs1 < cmp_rs2 );

// ====================
// STAGE + OUTCOME REGISTERS (outcome held until writeback)
// ====================
always @(posedge clock) begin
    if (reset) begin
        cmp_valid    <= 1'b0;
        cmp_opcode   <= 7'b0;
        cmp_funct3   <= 3'b0;
        result_valid <= 1'b0;
        taken        <= 1'b0;
        target       <= {IDATAW{1'b0}};
    end else begin
        // address cycle -> compare cycle
        cmp_valid <= ex_valid;
        if (ex_valid) begin
            cmp_rs1    <= idata1;
            cmp_rs2    <= idata2;
            cmp_target <= target_address;
            cmp_opcode <= opcode;
            cmp_funct3 <= funct3;
        end
        // compare cycle -> outcome
        if (wb_ready) result_valid <= 1'b0;
        if (cmp_valid) begin
            result_valid <= 1'b1;
            taken        <= br_taken;
            target       <= cmp_target;
        end
    end
end

assign fu_ready = !cmp_valid && !result_valid;

endmodule
