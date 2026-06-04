// =============================================================================
// Module:      imemory
// Description: Read-only instruction memory implemented as block RAM.
//              Word-addressed internally; byte address translated by subtracting
//              START_ADDR and dividing by 4. Stalls fetch when enable is low.
//              Initialised from MEM_PATH at simulation start.
// Inputs:      clock      - read clock
//              address    - byte address of instruction to fetch
//              data_in    - unused (write port kept for interface symmetry)
//              read_write - unused (hardwired to 0 in pd.v)
//              enable     - gates the memory read; output holds when low
// Outputs:     data_out   - 32-bit instruction word (registered, one-cycle latency)
// =============================================================================
module imemory(
    input             clock,
    input      [31:0] address,
    input      [31:0] data_in,
    input             read_write,
    input             enable,
    output reg [63:0] data_out
);

// ====================
// SIGNALS + INIT
// ====================
wire       [31:0] address_2;
// effective address (0 indexed)
wire       [31:0] ea;
wire       [31:0] data_in_2;
wire              read_write_2;
localparam        START_ADDR = 32'h01000000;

(* ram_style = "block" *) reg [31:0] mem[0:`MEM_DEPTH / 4 - 1];

initial begin
    $readmemh(`MEM_PATH, mem);
end

// ====================
// READ LOGIC
// ====================
// Convert byte address to word index
assign ea = (address - START_ADDR) >> 2;

always @(posedge clock) begin
    if (enable) begin
        // Write path unused in normal operation (read_write hardwired to 0)
        if (read_write_2 == 1) begin
            mem[ea] <= data_in_2;
        end
        data_out <= mem[ea];
    end
end

endmodule
