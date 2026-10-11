module functional_unit_status #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter NUM_ALU = 2,
    parameter NUM_MULTICYCLE_MULT = 1,
    parameter NUM_LOAD_STORE = 1,
    parameter NUM_FU = NUM_ALU + NUM_MULTICYCLE_MULT + NUM_LOAD_STORE + 1; // + 1 for branch_comparator
    parameter FUW = $clog2(NUM_FU + 1) // + 1 for None
)(
    input clock,
    input reset,
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
    output iss_tag_found // RAW hazard found, cannot issue
    // output w_complete
    // output busy_out,
    
);

// Declare reg arrays to hold the statuses for each row/functional unit
reg [DATAW-1:0] pc_arr [NUM_FU-1:0];
reg busy_arr [NUM_FU-1:0];
reg [ADDRW-1:0] rs1_arr [NUM_FU-1:0];
reg [ADDRW-1:0] rs2_arr [NUM_FU-1:0];

reg [DATAW-1:0] rs1_data_arr [NUM_FU-1:0];
reg [DATAW-1:0] rs2_data_arr [NUM_FU-1:0];

reg [FUW-1:0] rs1_tag_arr [NUM_FU-1:0];
reg [FUW-1:0] rs2_tag_arr [NUM_FU-1:0];

// Row indexes
wire ds_row_index = ds_fu_id + 1; // since 0 is N/A for the fu_id
wire iss_row_index = iss_fu_id + 1; 

// TODO: implement some sort of clearing logic in execute stage (clear the functional unit row --> set it to not busy)
always @(posedge clock) begin 
    if (reset) begin 
        busy_arr <= 0; // just set everything to not busy
    end else begin 
        // In dispatch stage --> write new row (if not busy)
        if(ds_en && !busy[row_index]) begin 
            pc_arr[ds_row_index] <= pc;
            busy_arr[ds_row_index] <= 1;
            rs1_arr[ds_row_index] <= rs1;
            rs1_arr[ds_row_index] <= rs2;
            rs1_tag_arr[ds_row_index] <= rs1_tag;
            rs2_tag_arr[ds_row_index] <= rs2_tag;
        end
    end
end

integer i;

always @(*) begin
    // In writeback stage --> clear the tags for any FUs waiting on it (do this before trying to issue)
    if(wb_en) begin 
        for(i = 0; i < NUM_FU; i = i + 1) begin
            if(rs1_tag_arr[i] == wb_tag_clear) begin
                rs1_tag_arr[i] = 0;
                rs1_data_arr[i] = wb_data; 
            end

            if(rs2_tag_arr[i] == wb_tag_clear) begin
                rs2_tag_arr[i] = 0;
                rs2_data_arr[i] = wb_data;
            end
        end        
    end

    // In issue stage --> update the row with rs1 and rs2 data values (if a tag is not found)
    if(iss_en) begin
        if(rs1_tag_arr[iss_row_index] == 0 && rs2_tag_arr[iss_row_index] == 0) begin // No RAW detected
            rs1_data_arr[iss_row_index] = iss_rs1_data;
            rs2_data_arr[iss_row_index] = iss_rs2_data;
            iss_tag_found = 0; 
        end else begin
            iss_tag_found = 1;
        end
    end
end


endmodule
