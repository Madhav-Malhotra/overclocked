module functional_unit_status #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 1,
    parameter NUM_FU = NUM_ALU + NUM_MULTICYCLE_MULT + 2*NUM_LOAD_STORE + 1, // + 1 for branch_comparator
    parameter FUW = $clog2(NUM_FU + 1) // + 1 for None
)(
    input clock,
    input reset,

    // Check for WAW in dispatch
    input [FUW-1:0] ds_fu_type,
    output reg [FUW-1:0] ds_assigned_fu_id,

    // Populate row in dispatch
    input ds_en,
    input [FUW-1:0] ds_fu_id, // actual functional unit id
    input [DATAW-1:0] ds_pc,
    input [ADDRW-1:0] ds_rs1,
    input [ADDRW-1:0] ds_rs2, 
    input [ADDRW-1:0] ds_rd, 
    input [FUW-1:0] ds_rs1_tag,
    input [FUW-1:0] ds_rs2_tag,

    input iss_en,               // iss = issue
    input [FUW-1:0] iss_fu_id, // actual functional unit id
    input [DATAW-1:0] iss_rs1_data,
    input [DATAW-1:0] iss_rs2_data,

    input wb_en,
    input [FUW-1:0] wb_tag_clear,
    input [DATAW-1:0] wb_data,

    input busy [0:NUM_FU-1],   // connect to the FUs to get their real-time statuses
    output reg 
     // RAW hazard found, cannot issue
    // output w_complete
    // output busy_out,
    
);

// Declare reg arrays to hold the statuses for each row/functional unit
reg [DATAW-1:0] pc_arr [NUM_FU-1:0];
reg [NUM_FU-1:0] busy_arr;
reg [ADDRW-1:0] rs1_arr [NUM_FU-1:0];
reg [ADDRW-1:0] rs2_arr [NUM_FU-1:0];

reg [DATAW-1:0] rs1_data_arr [NUM_FU-1:0];
reg [DATAW-1:0] rs2_data_arr [NUM_FU-1:0];

reg [FUW-1:0] rs1_tag_arr [NUM_FU-1:0];
reg [FUW-1:0] rs2_tag_arr [NUM_FU-1:0];

// Row indexes
wire [FUW-1:0] ds_row_index = ds_fu_id - 1; // since 0 is N/A for the fu_id
wire [FUW-1:0] iss_row_index = iss_fu_id - 1;
wire [FUW-1:0] wb_row_index = wb_tag_clear - 1;

/* DS checks for structurual hazards */
// available FU types
localparam NONE = 0;
localparam BRANCH = 1;
localparam MCM = 2;
localparam LOAD = 3;
localparam STORE = 4;
localparam ALU = 5; 
localparam ALU_2 = 6; // id for second ALU

// Output the assigned functional_unit_id for the instruction to dispatch (a row will then be populated for it)
always @(*) begin
    if(reset) ds_assigned_fu_id = 0;
    else begin 
        case(ds_fu_type) 
            BRANCH: ds_assigned_fu_id = (busy_arr[BRANCH - 1] == 0) ? BRANCH : 0;
            MCM: ds_assigned_fu_id = (busy_arr[MCM - 1] == 0) ? MCM : 0; 
            LOAD: ds_assigned_fu_id = (busy_arr[LOAD - 1] == 0) ? LOAD : 0;
            STORE: ds_assigned_fu_id = (busy_arr[STORE - 1] == 0) ? STORE : 0;
            ALU: ds_assigned_fu_id = (busy_arr[ALU - 1] == 0) ? ALU : 
                                     (busy_arr[ALU_2 - 1] == 0) ? ALU_2  : 0;
            default: ds_assigned_fu_id = 0;
        endcase
    end
end


integer i;

// Row stays busy from dispatch until writeback (cleared in the wb_en block below)
always @(posedge clock) begin 
    if (reset) begin 
        busy_arr <= 0; // just set everything to not busy
        for(i = 0; i < NUM_FU; i = i + 1) begin
            rs1_tag_arr[i] <= 0;
            rs2_tag_arr[i] <= 0;
        end
    end else begin
        // In writeback stage --> clear the tags for any FUs waiting on it, and free the writing row
        if(wb_en) begin
            for(i = 0; i < NUM_FU; i = i + 1) begin
                if(rs1_tag_arr[i] == wb_tag_clear) begin
                    rs1_tag_arr[i] <= 0;
                    rs1_data_arr[i] <= wb_data;
                end

                if(rs2_tag_arr[i] == wb_tag_clear) begin
                    rs2_tag_arr[i] <= 0;
                    rs2_data_arr[i] <= wb_data;
                end
            end
            busy_arr[wb_row_index] <= 0;
        end

        // In issue stage --> update the row with rs1 and rs2 data values (if a tag is not found)
        if(iss_en && !iss_tag_found) begin
            rs1_data_arr[iss_row_index] <= iss_rs1_data;
            rs2_data_arr[iss_row_index] <= iss_rs2_data;
        end

        // In dispatch stage --> write new row (if not busy)
        if(ds_en && !busy_arr[ds_row_index]) begin
            pc_arr[ds_row_index] <= ds_pc;
            busy_arr[ds_row_index] <= 1;
            rs1_arr[ds_row_index] <= ds_rs1;
            rs2_arr[ds_row_index] <= ds_rs2;
            rs1_tag_arr[ds_row_index] <= ds_rs1_tag;
            rs2_tag_arr[ds_row_index] <= ds_rs2_tag;
        end
    end
end

// In issue stage --> RAW hazard if either source still has a producer tag
always @(*) begin
    iss_tag_found = 0;
    if(iss_en) begin
        iss_tag_found = (rs1_tag_arr[iss_row_index] != 0) || (rs2_tag_arr[iss_row_index] != 0);
    end
end




endmodule
