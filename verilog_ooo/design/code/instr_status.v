// =============================================================================
// Module:      instr_status
// Description: Instruction Status Table (instruction buffer) for the scoreboard.
//              Holds up to NUM_BUFFER_ROWS dispatched instructions and their
//              decoded fields from dispatch until writeback. Rows are allocated
//              at the lowest free index (no FIFO order / age field).
//              Rows are currently matched by PC for issue/writeback; plan.md
//              Phase 2 (task 2.2) re-keys them by row index (ds_ist_idx).
// Inputs:      ds_*   - dispatch: allocate a row with these decoded fields
//              iss_*  - issue: mark the row holding iss_pc as IS
//              wb_*   - writeback: clear the row holding wb_pc
// Outputs:     buffer_full - no free row (dispatch must stall)
//              ds_ist_idx  - row index the next dispatch will be written to
// =============================================================================
module instr_status #(
    parameter DATAW  =  32,
    parameter ADDRW  =  $clog2(DATAW),
    parameter NUM_BUFFER_ROWS = 6,
    parameter N_BITS =  $clog2(NUM_BUFFER_ROWS), // width of a row index
    parameter NUM_FU = 6,
    parameter FUW = $clog2(NUM_FU)

)(
    input wire  clock, 
    input wire  reset,
    
    // input status in DS (can remove some of these values if they are unused)
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

    // update status: change stage to IS
    input iss_en,
    input [DATAW-1:0] iss_pc,

    // clear row in WB
    input wb_en,
    input [DATAW-1:0] wb_pc,

    output buffer_full,
    output [N_BITS-1:0] ds_ist_idx   // row the next dispatch is written to (valid when !buffer_full)
);

localparam DS = 'h0;
localparam IS = 'h1;
localparam EX = 'h2;
localparam WB = 'h3;

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

// Stage count
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
always @(posedge clock) begin
    if(reset) begin 
        // Mark everything as empty/invalid
        for(i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin
            valid_arr[i] <= 0;
        end

        num_instr <= 0;
    end else begin
        
        // Clear rows in WB (set valid to 0)
        if(wb_en) begin
            for(i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin
                if(pc_arr[i] == wb_pc) begin
                    valid_arr[i] <= 0;
                    stage_arr[i] <= WB; // for debugging purposes
                end
            end  
        end        

        // Update instruction status to IS in issue stage (instruction has been issued, reg values have been copied, no more RAWs)
        if(iss_en) begin
            for(i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin
                if(pc_arr[i] == iss_pc) begin 
                    stage_arr[i] <= IS;
                end

            end
        end

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

assign buffer_full = (num_instr == NUM_BUFFER_ROWS);
assign ds_ist_idx  = free_row_idx;

endmodule







