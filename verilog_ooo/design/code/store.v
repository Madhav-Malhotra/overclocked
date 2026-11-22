// =============================================================================
// Module:      store
// Description: Store functional unit (FU id 4). Writes memory in Execute
//              (plan.md D6), in two EX cycles starting in the cycle the issued
//              instruction arrives (ex_valid):
//                EX cycle 1 (address): adds the ALU input operands (rs1 + imm,
//                         selected by control_signals' a_sel/b_sel in pd.v) to
//                         get the effective address, registered with the data.
//                EX cycle 2 (memory):  drives the dmemory write port; the
//                         write lands at the end of the cycle, so the data is
//                         in memory by writeback.
//              A store writes no register, so its writeback only releases
//              scoreboard state: result_valid marks the store done until
//              writeback takes it (result is 0).
// Inputs:      clock, reset
//              ex_valid       - an issued store is in this FU's EX cycle 1
//              idata1, idata2 - address operands (rs1 value, sign-extended offset)
//              store_data     - data to store (rs2 value)
//              pc             - PC of the store
//              funct3         - store type: [1:0] = size (0 byte, 1 half, 2 word)
//              wb_ready       - writeback takes this FU's result this cycle
// Outputs:     fu_ready       - FU can accept an instruction (holds none)
//              dmem_w_*       - dmemory write port (driven in the memory cycle)
//              result_valid   - store done, waiting for writeback
//              result         - always 0 (no register result)
// =============================================================================
module store #(
    parameter DATAW = 32
)(
    input                  clock,
    input                  reset,

    // ====================
    // Issue -> FU (ready/valid)
    // ====================
    input                  ex_valid,
    input      [DATAW-1:0] idata1,
    input      [DATAW-1:0] idata2,
    input      [DATAW-1:0] store_data,
    input      [DATAW-1:0] pc,
    input      [2:0]       funct3,
    output                 fu_ready,

    // ====================
    // dmemory write port (memory cycle)
    // ====================
    output                 dmem_w_en,           // write at the end of this cycle
    output     [DATAW-1:0] dmem_w_pc,           // PC of the store (dmemory store->load forward compare)
    output     [1:0]       dmem_w_access_size,  // 0 = byte, 1 = half, 2 = word
    output     [DATAW-1:0] dmem_w_address,      // effective address
    output     [DATAW-1:0] dmem_w_data,         // data to write (rs2 value; low bytes used for sb/sh)

    // ====================
    // FU -> writeback (ready/valid)
    // ====================
    output reg             result_valid,
    output     [DATAW-1:0] result,
    input                  wb_ready
);

// ====================
// EX CYCLE 1: ADDRESS
// ====================
wire [DATAW-1:0] effective_address = idata1 + idata2;  // address adder: rs1 + imm

// ====================
// EX CYCLE 2: MEMORY WRITE
// ====================
reg             mem_valid;    // the store is in its memory cycle
reg [DATAW-1:0] mem_address;  // its effective address
reg [DATAW-1:0] mem_data;     // its data
reg [DATAW-1:0] mem_pc;       // its PC
reg [1:0]       mem_size;     // its access size

assign dmem_w_en          = mem_valid;
assign dmem_w_pc          = mem_pc;
assign dmem_w_access_size = mem_size;
assign dmem_w_address     = mem_address;
assign dmem_w_data        = mem_data;

// ====================
// STAGE REGISTERS + DONE FLAG (held until writeback)
// ====================
always @(posedge clock) begin
    if (reset) begin
        mem_valid    <= 1'b0;
        result_valid <= 1'b0;
    end else begin
        // address cycle -> memory cycle
        mem_valid <= ex_valid;
        if (ex_valid) begin
            mem_address <= effective_address;
            mem_data    <= store_data;
            mem_pc      <= pc;
            mem_size    <= funct3[1:0];
        end
        // memory cycle -> done
        if (wb_ready)  result_valid <= 1'b0;
        if (mem_valid) result_valid <= 1'b1;
    end
end

assign result   = {DATAW{1'b0}};
assign fu_ready = !mem_valid && !result_valid;

endmodule
