module instr_status #(
    parameter NUM_BUFFER_ROWS = 5,
    parameter INDEX_WIDTH     = 3
)(
    input wire  clock, 
    input wire  reset,
    input  wire [31:0] pc_in,         // PC of instruction
    input wire read_write,
    input wire issue_en
);

genvar i;

generate
    for (i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin : gen_instr_buffer
        instr_row instr_buff_row (
            .clock(clock),
            .reset(reset),
            .read_write(read_write)
        );
    end
endgenerate

always @(posedge clock) begin
    if(reset) begin 
        gen_instr_buffer[index].read_write = 0;
    end else begin 
        gen_instr_buffer[index].read_write;

    end

end
endmodule

//****************************************************************************

module instr_row(
    input clock,
    input reset, 

    //Control inputs
    input read_write,
    input wire [31:0] pc_in,  // for overwriting values
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