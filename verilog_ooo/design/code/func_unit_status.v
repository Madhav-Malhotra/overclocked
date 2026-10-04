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
    input read_write,
    input busy,
    input pc,
    input fu_id,
    input rs1,
    input rs2, 
    input rd, 
    input rs1_data,
    input rs2_data,
    output busy_out
);

wire row_index = fu_id + 1; // since 0 is N/A for the fu_id

// 1. Declare a reg array to hold the read_write signal for each row
reg [NUM_FU-1:0] row_read_write;


// 2. Drive the row_read_write array procedurally
always @(posedge clock) begin
    if (reset) begin 
        row_read_write <= '0; // Reset all rows to 0
    end else begin 
        // Example: Only enable the row matching 'index'
        row_read_write        <= '0;
        row_read_write[row_index] <= 1'b1; 
    end
end

// 3. Generate module instances and connect each row's control signal
genvar i;
generate
    for (i = 0; i < NUM_FU; i = i + 1) begin : gen_instr_buffer
        instr_row instr_buff_row (
            .clock     (clock),
            .reset     (reset),
            .read_write(row_read_write[i]) // Connected to array signal
        );
    end
endgenerate




endmodule

module functional_unit_row(
    input clock,
    input reset, 

    //Control inputs
    input read_write,
    input wire pc_in;
    input wire [FUW-1:0] fu_id,
    
    input wire exec_done_en,   //signal execution is complete
    input wire clear_en,        //clear row enable on wb



    //output
    output reg busy,
    output reg [31:0] pc_out,
    output reg exec_done

)

always @(posedge clock) begin
    if(reset) begin x
        busy <= 1'b0;
        pc_out <= 32'b0;

    end else if (read_write) begin 
        busy <= 1'b1;
        pc_out <= pc_in;
        

    end

end


endmodule