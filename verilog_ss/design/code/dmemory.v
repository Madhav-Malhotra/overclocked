// =============================================================================
// Module:      dmemory
// Description: Byte-address_0able data memory for RV32I load/store instructions.
//              Supports byte (SB/LB), halfword (SH/LH), and word (SW/LW) access.
//              Initialised from MEM_PATH at simulation start.
// Inputs:      clock       - write clock
//              read_write_0  - 1 = write, 0 = read
//              access_size_0 - 2'b00 byte, 2'b01 halfword, 2'b10 word
//              address_0     - byte address_0 (absolute, BASE subtracted internally)
//              data_in_0     - data to write
// Outputs:     data_out_0    - data read from memory (registered, one-cycle latency)
// =============================================================================
module dmemory #(
    parameter integer BASE = 32'h01000000
)
(
    input         clock,
    input         read_write_0,
    input  [1:0]  access_size_0,
    input  [31:0] address_0,
    input  [31:0] data_in_0,
    output reg [31:0] data_out_0,

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
// Convert absolute byte address_0 to memory-relative offset
wire [31:0] addr = address_0 - BASE;
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
    if (read_write_0 == 1'b1) begin
        if (access_size_0 == 2'd0) begin
            mem[addr] <= data_in_0[7:0];
        end else if (access_size_0 == 2'd1) begin
            {mem[addr+1], mem[addr]} <= data_in_0[15:0];
        end else begin
            {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]} <= data_in_0;
        end
    end
    // Read always occurs; caller ignores data_out_0 on writes
    data_out_0 <= {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]};
end

// If way 0 = store and way 1 = load --> do store before load
// Same-cycle store->load forwarding between ways:
// way 0 (older) and way 1 (younger) are in the M stage in the SAME cycle.
// If way 0 is storing to bytes that way 1 is loading, way 1 must observe
// way 0's data (program order), not the stale memory contents.
wire [2:0] w0_store_nbytes = (access_size_0 == 2'd0) ? 3'd1 :
                             (access_size_0 == 2'd1) ? 3'd2 : 3'd4;

function [7:0] rd_byte_way1(input [31:0] a);
    begin
        if (read_write_0 && (a >= addr) && ((a - addr) < {29'b0, w0_store_nbytes}))
            rd_byte_way1 = data_in_0[8*(a - addr) +: 8];  // forward way 0's store data
        else
            rd_byte_way1 = mem[a];
    end
endfunction

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
    // Read always occurs; caller ignores data_out_0 on writes
    // data_out_1 <= {mem[addr_2+3], mem[addr_2+2], mem[addr_2+1], mem[addr_2]};
        data_out_1 <= {rd_byte_way1(addr_2+3), rd_byte_way1(addr_2+2), rd_byte_way1(addr_2+1), rd_byte_way1(addr_2)};

end

endmodule
