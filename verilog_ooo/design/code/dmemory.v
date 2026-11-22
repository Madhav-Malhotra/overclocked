// =============================================================================
// Module:      dmemory
// Description: Byte-addressable data memory for RV32I load/store instructions.
//              Supports byte (SB/LB), halfword (SH/LH), and word (SW/LW) access.
//              Separate read port (used by the load FU, load.v) and write port
//              (used by the store FU, store.v); both FUs compute the effective
//              address themselves. Initialised from MEM_PATH at simulation start.
//              The store->load forward (w_pc < r_pc) is never used in the OoO
//              core: memory order is enforced at issue (plan.md D6), so a load
//              and a store never access the memory in the same cycle.
// Inputs:      clock          - write clock
//              r_en           - read enable (r_data_out is 0 when low)
//              r_pc, w_pc     - PCs of the load / store (store->load forward compare)
//              r_access_size, w_access_size - 2'b00 byte, 2'b01 halfword, 2'b10 word
//              r_address, w_address - effective byte address (absolute, BASE subtracted internally)
//              w_en           - write at the next rising edge
//              w_data_in      - data to write
// Outputs:     r_data_out     - 4 bytes at r_address, little-endian (combinational, same cycle)
// =============================================================================
module dmemory #(
    parameter integer BASE = 32'h01000000,
    parameter DATAW = 32
)
(
    input         clock,

    // For load unit
    input r_en,
    input [DATAW-1:0] r_pc,
    input  [1:0]  r_access_size,
    input  [31:0] r_address,

    // For store unit
    input w_en,
    input [DATAW-1:0] w_pc,
    input  [1:0]  w_access_size,
    input  [31:0] w_address,
    input  [31:0] w_data_in,

    output [31:0] r_data_out
);

// ====================
// SIGNALS + INIT
// ====================
reg  [31:0] temp [0:`LINE_COUNT-1];
reg  [7:0]  mem  [0:`MEM_DEPTH-1];

// Convert absolute byte address to memory-relative offset (33-bit to prevent overflow checks)
wire [32:0] r_addr_33 = {1'b0, r_address - BASE};
wire [32:0] w_addr_33 = {1'b0, w_address - BASE};

wire [31:0] r_addr = r_addr_33[31:0];
wire [31:0] w_addr = w_addr_33[31:0];

// Determine number of bytes being written by the store instruction
wire [2:0] w_num_bytes =  (w_access_size == 2'd0) ? 3'd1 : // sb
                          (w_access_size == 2'd1) ? 3'd2 : // sh
                                                    3'd4;  // sw

// Load word-packed hex file then unpack into byte array (little-endian)
integer i;
initial begin
    $readmemh(`MEM_PATH, temp);
    for (i = 0; i < `LINE_COUNT; i = i + 1) begin
        {mem[4*i+3], mem[4*i+2], mem[4*i+1], mem[4*i]} = temp[i];
    end
end

// ====================
// READ/WRITE LOGIC
// ====================
always @(posedge clock) begin
// 1. Perform Write
    if (w_en) begin
        if (w_access_size == 2'd0) begin
            mem[w_addr] <= w_data_in[7:0];
        end else if (w_access_size == 2'd1) begin
            {mem[w_addr+1], mem[w_addr]} <= w_data_in[15:0];
        end else begin
            {mem[w_addr+3], mem[w_addr+2], mem[w_addr+1], mem[w_addr]} <= w_data_in;
        end
    end
end

// 2. Perform Read with Store-to-Load Forwarding and PC Check (w_pc < r_pc)
// If we have a store happening before a load, forward update value to the load
    // This should happen even if store is only partially modifying the data being read by load (e.g. sb and lw --> use updated byte by sb)
assign r_data_out = r_en ? {
    // Byte 3 (r_addr + 3)
    (w_en && (w_pc < r_pc) && ((r_addr_33 + 33'd3) >= w_addr_33) && ((r_addr_33 + 33'd3) < (w_addr_33 + w_num_bytes))) ?
        w_data_in[31:24] : mem[r_addr+3],

    // Byte 2 (r_addr + 2)
    (w_en && (w_pc < r_pc) && ((r_addr_33 + 33'd2) >= w_addr_33) && ((r_addr_33 + 33'd2) < (w_addr_33 + w_num_bytes))) ?
        w_data_in[23:16] : mem[r_addr+2],

    // Byte 1 (r_addr + 1)
    (w_en && (w_pc < r_pc) && ((r_addr_33 + 33'd1) >= w_addr_33) && ((r_addr_33 + 33'd1) < (w_addr_33 + w_num_bytes))) ?
        w_data_in[15:8] : mem[r_addr+1],

    // Byte 0 (r_addr)
    (w_en && (w_pc < r_pc) && (r_addr_33 >= w_addr_33) && (r_addr_33 < (w_addr_33 + w_num_bytes))) ?
        w_data_in[7:0] : mem[r_addr]
} :32'b0;

endmodule
