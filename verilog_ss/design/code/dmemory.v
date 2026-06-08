// =============================================================================
// Module:      dmemory
// Description: Byte-addressable data memory for RV32I load/store instructions.
//              Supports byte (SB/LB), halfword (SH/LH), and word (SW/LW) access.
//              Initialised from MEM_PATH at simulation start.
// Inputs:      clock       - write clock
//              read_write  - 1 = write, 0 = read
//              access_size - 2'b00 byte, 2'b01 halfword, 2'b10 word
//              address     - byte address (absolute, BASE subtracted internally)
//              data_in     - data to write
// Outputs:     data_out    - data read from memory (registered, one-cycle latency)
// =============================================================================
module dmemory #(
    parameter integer BASE = 32'h01000000
)
(
    input         clock,
    input         read_write,
    input  [1:0]  access_size,
    input  [31:0] address,
    input  [31:0] data_in,
    output reg [31:0] data_out,
    
    //way 2
    input         read_write_1,
    input  [1:0]  access_size_1,
    input  [31:0] address_1,
    input  [31:0] data_in_1,
    output reg [31:0] data_out_1

);

// ====================
// SIGNALS + INIT
// ====================
reg  [31:0] temp [0:`LINE_COUNT-1];
reg  [7:0]  mem  [0:`MEM_DEPTH-1];
// Convert absolute byte address to memory-relative offset
wire [31:0] addr = address - BASE;
wire [31:0] addr_2 = address_1 - BASE;

integer i;

// Load word-packed hex file then unpack into byte array (little-endian)
initial begin
    $readmemh(`MEM_PATH, temp);
    for (i = 0; i < `LINE_COUNT; i = i + 1) begin
        {mem[4*i+3], mem[4*i+2], mem[4*i+1], mem[4*i]} = temp[i];
    end
end

// ====================
// READ/WRITE LOGIC
// ====================
// way 1
always @(posedge clock) begin
    if (read_write == 1'b1) begin
        if (access_size == 2'd0) begin
            mem[addr] <= data_in[7:0];
        end else if (access_size == 2'd1) begin
            {mem[addr+1], mem[addr]} <= data_in[15:0];
        end else begin
            {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]} <= data_in;
        end
    end
    // Read always occurs; caller ignores data_out on writes
    data_out <= {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]};
end

// way 2
always @(posedge clock) begin
    if (read_write_1 == 1'b1) begin
        if (access_size_1 == 2'd0) begin
            mem[addr_2] <= data_in_1[7:0];
        end else if (access_size_1 == 2'd1) begin
            {mem[addr_2+1], mem[addr_2]} <= data_in_1[15:0];
        end else begin
            {mem[addr_2+3], mem[addr_2+2], mem[addr_2+1], mem[addr_2]} <= data_in_1;
        end
    end
    // Read always occurs; caller ignores data_out on writes
    data_out_1 <= {mem[addr_2+3], mem[addr_2+2], mem[addr_2+1], mem[addr_2]};
end

endmodule
