// =============================================================================
// Module:      load
// Description: Load functional unit (FU id 3). Two EX cycles, starting in the
//              cycle the issued instruction arrives (ex_valid):
//                EX cycle 1 (address): adds the ALU input operands (rs1 + imm,
//                         selected by control_signals' a_sel/b_sel in pd.v) to
//                         get the effective address, registered.
//                EX cycle 2 (memory):  reads dmemory combinationally at that
//                         address, size-selects and sign- or zero-extends the
//                         data (LB/LH/LW/LBU/LHU, same logic as the scalar
//                         core's pd.v) and registers it at the end of the cycle.
//              The loaded value is held (result_valid) until writeback takes
//              it (plan.md D3). Memory order against the store FU is enforced
//              at issue (plan.md D6).
// Inputs:      clock, reset
//              ex_valid       - an issued load is in this FU's EX cycle 1
//              idata1, idata2 - address operands (rs1 value, sign-extended offset)
//              pc             - PC of the load
//              funct3         - load type: [1:0] = size (0 byte, 1 half, 2 word),
//                               [2] = zero-extend (LBU/LHU)
//              dmem_r_data    - dmemory read data (combinational)
//              wb_ready       - writeback takes this FU's result this cycle
// Outputs:     fu_ready       - FU can accept an instruction (holds none)
//              dmem_r_*       - dmemory read port (driven in the memory cycle)
//              result_valid   - loaded value ready, waiting for writeback
//              result         - the extended loaded value
// =============================================================================
module load #(
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
    input      [DATAW-1:0] pc,
    input      [2:0]       funct3,
    output                 fu_ready,

    // ====================
    // dmemory read port (memory cycle)
    // ====================
    output                 dmem_r_en,           // read this cycle
    output     [DATAW-1:0] dmem_r_pc,           // PC of the load (dmemory store->load forward compare)
    output     [1:0]       dmem_r_access_size,  // 0 = byte, 1 = half, 2 = word
    output     [DATAW-1:0] dmem_r_address,      // effective address
    input      [DATAW-1:0] dmem_r_data,         // read data: bytes at the address, little-endian

    // ====================
    // FU -> writeback (ready/valid)
    // ====================
    output reg             result_valid,
    output reg [DATAW-1:0] result,
    input                  wb_ready
);

localparam BYTE_OP = 2'd0;
localparam HALF_OP = 2'd1;

// ====================
// EX CYCLE 1: ADDRESS
// ====================
wire [DATAW-1:0] effective_address = idata1 + idata2;  // address adder: rs1 + imm

// ====================
// EX CYCLE 2: MEMORY READ + EXTENSION
// ====================
reg             mem_valid;    // the load is in its memory cycle
reg [DATAW-1:0] mem_address;  // its effective address
reg [DATAW-1:0] mem_pc;       // its PC
reg [2:0]       mem_funct3;   // its load type

wire [1:0] mem_access_size = mem_funct3[1:0];  // 0 = byte, 1 = half, 2 = word
wire       load_unsigned   = mem_funct3[2];    // LBU/LHU zero-extend

assign dmem_r_en          = mem_valid;
assign dmem_r_pc          = mem_pc;
assign dmem_r_access_size = mem_access_size;
assign dmem_r_address     = mem_address;

wire [DATAW-1:0] load_value =   // loaded value after size select and extension
    (mem_access_size == BYTE_OP) ?
        (load_unsigned ? {24'b0, dmem_r_data[7:0]}  : {{24{dmem_r_data[7]}},  dmem_r_data[7:0]}) :   // LBU / LB
    (mem_access_size == HALF_OP) ?
        (load_unsigned ? {16'b0, dmem_r_data[15:0]} : {{16{dmem_r_data[15]}}, dmem_r_data[15:0]}) : // LHU / LH
    dmem_r_data;                                                                                     // LW

// ====================
// STAGE + RESULT REGISTERS (result held until writeback)
// ====================
always @(posedge clock) begin
    if (reset) begin
        mem_valid    <= 1'b0;
        result_valid <= 1'b0;
        result       <= {DATAW{1'b0}};
    end else begin
        // address cycle -> memory cycle
        mem_valid <= ex_valid;
        if (ex_valid) begin
            mem_address <= effective_address;
            mem_pc      <= pc;
            mem_funct3  <= funct3;
        end
        // memory cycle -> result
        if (wb_ready) result_valid <= 1'b0;
        if (mem_valid) begin
            result_valid <= 1'b1;
            result       <= load_value;
        end
    end
end

assign fu_ready = !mem_valid && !result_valid;

endmodule
