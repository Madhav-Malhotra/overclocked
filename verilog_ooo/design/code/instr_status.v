module instr_status #(
    parameter NUM_BUFFER_ROWS = 5,
    parameter INDEX_WIDTH     = 3
)(
    input wire  clock, 
    input wire  reset,
    input wire [INDEX_WIDTH-1:0] index, // Added missing index input
    input wire [31:0] pc_in,            // PC of instruction
    input wire read_write,
    input wire issue_en,
    input wire exec_done_en,
    input wire clear_en
);

    // 1. Declare a reg array to hold the read_write signal for each row
    reg [NUM_BUFFER_ROWS-1:0] row_read_write;

    // 2. Drive the row_read_write array procedurally
    always @(posedge clock) begin
        if (reset) begin 
            row_read_write <= '0; // Reset all rows to 0
        end else begin 
            // Example: Only enable the row matching 'index'
            row_read_write        <= '0;
            if (read_write) begin
                row_read_write[index] <= 1'b1; 
            end
        end
    end

    // 3. Generate module instances and connect each row's control signal
    genvar i;
    generate
        for (i = 0; i < NUM_BUFFER_ROWS; i = i + 1) begin : gen_instr_buffer
            instr_row instr_buff_row (
                .clock       (clock),
                .reset       (reset),
                .read_write  (row_read_write[i]), // Connected to array signal
                .pc_in       (pc_in),
                .exec_done_en(exec_done_en),
                .clear_en    (clear_en),
                .busy        (),
                .pc_out      (),
                .exec_done   ()
            );
        end
    endgenerate
    
endmodule




module fifo_buffer #(
    parameter DATA_WIDTH = 8,       // Width of each data word (in bits)
    parameter ADDR_WIDTH = 3        // 2^3 = 8 depths / locations
)(
    input  wire                  clk,      // System clock
    input  wire                  rst_n,    // Active-low asynchronous reset
    input  wire                  wr_en,    // Write enable signal
    input  wire                  rd_en,    // Read enable signal
    input  wire [DATA_WIDTH-1:0] din,      // Data input bus
    output reg  [DATA_WIDTH-1:0] dout,     // Data output bus
    output wire                  full,     // FIFO full status flag
    output wire                  empty     // FIFO empty status flag
);

    // Local constant for FIFO depth calculation
    localparam DEPTH = 1 << ADDR_WIDTH;

    // Memory array (Register File)
    reg [DATA_WIDTH-1:0] memory [0:DEPTH-1];

    // Pointers use an extra bit (ADDR_WIDTH) to distinguish full vs empty
    reg [ADDR_WIDTH:0] wr_ptr;
    reg [ADDR_WIDTH:0] rd_ptr;

    // --- Status Flags Logic ---
    // If all pointer bits match, the buffer is empty
    assign empty = (wr_ptr == rd_ptr);
    
    // If the MSBs differ but the lower address bits match, the buffer is full
    assign full  = (wr_ptr[ADDR_WIDTH] != rd_ptr[ADDR_WIDTH]) && 
                   (wr_ptr[ADDR_WIDTH-1:0] == rd_ptr[ADDR_WIDTH-1:0]);

    // --- Memory Write Logic ---
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= 0;
        end else if (wr_en && !full) begin
            memory[wr_ptr[ADDR_WIDTH-1:0]] <= din;
            wr_ptr <= wr_ptr + 1'b1;
        end
    end

    // --- Memory Read Logic ---
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_ptr <= 0;
            dout   <= 0;
        end else if (rd_en && !empty) begin
            dout   <= memory[rd_ptr[ADDR_WIDTH-1:0]];
            rd_ptr <= rd_ptr + 1'b1;
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
);

always @(posedge clock) begin
    if(reset || clear_en) begin
        busy <= 1'b0;
        pc_out <= 32'b0;
        exec_done <= 1'b0;

    end else if (read_write) begin 
        busy <= 1'b1;
        pc_out <= pc_in;
        exec_done <= 1'b0;

    end else if (exec_done_en) begin
        exec_done <= 1'b1;
    end

end


endmodule