// =============================================================================
// Module:      instr_status
// Description: Instruction Status Table (instruction buffer) for the scoreboard.
//              Holds up to NUM_BUFFER_ROWS dispatched instructions and their
//              decoded fields from dispatch until writeback. Rows are allocated
//              at the lowest free index (no FIFO order / age field). A row's
//              index (ist_idx) is the instruction's identity in hardware
//              (plan.md D1): issue, execute and writeback address the row by it.
//              Stage field per row: DS (dispatched) -> IS (selected for issue)
//              -> EX (operands read, issued to its FU) -> WB (written back;
//              the row's valid bit is cleared, so the row is free again).
// Inputs:      ds_*          - dispatch: allocate row ds_ist_idx with these fields
//              iss_sel_*     - issue select: mark row iss_sel_ist_idx as IS
//              iss_*         - issue: mark row iss_ist_idx as EX and
//                              read its decoded fields (combinational read port)
//              wb_en, wb_ist_idx - writeback: clear that row; read its opcode
// Outputs:     buffer_full   - no free row (dispatch must stall)
//              ds_ist_idx    - row the next dispatch is written to
//              iss_opcode/funct3/funct7/imm/shamt - fields of row iss_ist_idx
//              wb_opcode     - opcode of row wb_ist_idx
// =============================================================================
module instr_status #(
    parameter DATAW  =  32,
    parameter ADDRW  =  $clog2(DATAW),
    parameter NUM_BUFFER_ROWS = 6,
    parameter N_BITS =  $clog2(NUM_BUFFER_ROWS), // width of a row index (ist_idx)
    parameter NUM_FU = 6,
    parameter FUW = $clog2(NUM_FU + 1)
)(
    input wire  clock,
    input wire  reset,

    // ====================
    // Dispatch: write a new row
    // ====================
    input ds_en,
    input [DATAW-1:0] ds_pc,
    input [6:0] ds_opcode,
    input [2:0] ds_funct3,
    input [6:0] ds_funct7,
    input [DATAW-1:0] ds_imm,
    input [4:0] ds_shamt,
    input [ADDRW-1:0] ds_rs1,
    input [ADDRW-1:0] ds_rs2,
    input [ADDRW-1:0] ds_rd,
    input [FUW-1:0] ds_fu_id,
    output buffer_full,
    output [N_BITS-1:0] ds_ist_idx,     // row the next dispatch is written to (valid when !buffer_full)

    // ====================
    // Issue: select (cycle N) and issue (cycle N+1)
    // ====================
    input iss_sel_valid,                    // a row was selected for issue this cycle
    input [N_BITS-1:0] iss_sel_ist_idx,     // the selected row (stage -> IS)
    input iss_valid,                        // a row reads its operands / issues to its FU this cycle
    input [N_BITS-1:0] iss_ist_idx,         // the issuing row (stage -> EX; drives the read port)
    output [6:0] iss_opcode,                // opcode of row iss_ist_idx
    output [2:0] iss_funct3,                // funct3 of that row
    output [6:0] iss_funct7,                // funct7 of that row
    output [DATAW-1:0] iss_imm,             // immediate of that row
    output [4:0] iss_shamt,                 // shift amount of that row

    // ====================
    // Writeback: clear the row
    // ====================
    input wb_en,                            // an instruction writes back this cycle
    input [N_BITS-1:0] wb_ist_idx,          // its row (cleared; drives the writeback read port)
    output [6:0] wb_opcode                  // opcode of row wb_ist_idx (writeback control decode)
);

localparam DS = 2'h0;
localparam IS = 2'h1;
localparam EX = 2'h2;
localparam WB = 2'h3;

localparam INSTR_COUNT_W = $clog2(NUM_BUFFER_ROWS + 1); // width of num_instr: counts 0..NUM_BUFFER_ROWS inclusive

// Valid bits
reg valid_arr [NUM_BUFFER_ROWS-1:0];

// PC Values
reg [DATAW-1:0] pc_arr [NUM_BUFFER_ROWS-1:0];

// Opcode + func3 + func7
reg [6:0] opcode_arr [NUM_BUFFER_ROWS-1:0];
reg [2:0] func3_arr [NUM_BUFFER_ROWS-1:0];
reg [6:0] func7_arr [NUM_BUFFER_ROWS-1:0];

// Imm + shamt
reg [DATAW-1:0] imm_arr [NUM_BUFFER_ROWS-1:0];
reg [4:0] shamt_arr [NUM_BUFFER_ROWS-1:0];

// rs1, rs2, rd (register numbers)
reg [ADDRW-1:0] rs1_arr [NUM_BUFFER_ROWS-1:0];
reg [ADDRW-1:0] rs2_arr [NUM_BUFFER_ROWS-1:0];
reg [ADDRW-1:0] rd_arr [NUM_BUFFER_ROWS-1:0];

// Stage of the row's instruction: DS / IS / EX / WB (WB = written back, row freed)
reg [1:0] stage_arr [NUM_BUFFER_ROWS-1:0];

// Assigned functional unit
reg [FUW-1:0] fu_arr [NUM_BUFFER_ROWS-1:0];

reg [INSTR_COUNT_W-1:0] num_instr; // number of valid rows

integer i;

// Empty table at beginning
initial begin
    for(i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin
        valid_arr[i] = 0;
    end

    num_instr = 0;
end

// ====================
// FREE ROW LOOKUP
// ====================
// Lowest-index free row: where the next dispatch is written. The loop runs from
// the highest row down so the last (lowest) free row found wins.
reg [N_BITS-1:0] free_row_idx;

always @(*) begin
    free_row_idx = {N_BITS{1'b0}};
    for (i = NUM_BUFFER_ROWS - 1; i >= 0; i = i - 1) begin
        if (!valid_arr[i]) free_row_idx = i[N_BITS-1:0];
    end
end

// +1 / -1 terms for num_instr, sized to its width
wire [INSTR_COUNT_W-1:0] dispatch_count_inc  = {{(INSTR_COUNT_W-1){1'b0}}, ds_en};  // a dispatch adds a row
wire [INSTR_COUNT_W-1:0] writeback_count_dec = {{(INSTR_COUNT_W-1){1'b0}}, wb_en};  // a writeback frees a row

// ====================
// TABLE UPDATES
// ====================
// Select, issue, writeback and dispatch in one cycle always address different
// rows: a row is selected once, issues the cycle after, writes back only after
// executing, and dispatch only writes a row that is not valid.
always @(posedge clock) begin
    if(reset) begin
        // Mark everything as empty/invalid
        for(i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin
            valid_arr[i] <= 0;
        end

        num_instr <= 0;
    end else begin

        // Clear the row in WB
        if (wb_en) begin
            valid_arr[wb_ist_idx] <= 0;
            stage_arr[wb_ist_idx] <= WB; // instruction written back
        end

        // Issue select: the row's operands are read next cycle
        if (iss_sel_valid) stage_arr[iss_sel_ist_idx] <= IS;

        // Issue: operands read, instruction sent to its FU
        if (iss_valid) stage_arr[iss_ist_idx] <= EX;

        // populate the lowest free row (a row being cleared this cycle is not free yet)
        if (ds_en) begin
            valid_arr[free_row_idx] <= 1;
            pc_arr[free_row_idx] <= ds_pc;
            opcode_arr[free_row_idx] <= ds_opcode;
            func3_arr[free_row_idx] <= ds_funct3;
            func7_arr[free_row_idx] <= ds_funct7;
            imm_arr[free_row_idx] <= ds_imm;
            shamt_arr[free_row_idx] <= ds_shamt;
            rs1_arr[free_row_idx] <= ds_rs1;
            rs2_arr[free_row_idx] <= ds_rs2;
            rd_arr[free_row_idx] <= ds_rd;
            stage_arr[free_row_idx] <= DS;
            fu_arr[free_row_idx] <= ds_fu_id;
        end

        // combine DS insert and WB clear so neither update overwrites the other
        num_instr <= num_instr + dispatch_count_inc - writeback_count_dec;
    end
end

// ====================
// OUTPUTS
// ====================
assign buffer_full = (num_instr == NUM_BUFFER_ROWS);
assign ds_ist_idx  = free_row_idx;

// Read port: decoded fields of the row issuing to its FU this cycle
assign iss_opcode = opcode_arr[iss_ist_idx];
assign iss_funct3 = func3_arr[iss_ist_idx];
assign iss_funct7 = func7_arr[iss_ist_idx];
assign iss_imm    = imm_arr[iss_ist_idx];
assign iss_shamt  = shamt_arr[iss_ist_idx];

// Read port: opcode of the row writing back this cycle (control_signals.v)
assign wb_opcode = opcode_arr[wb_ist_idx];

endmodule
