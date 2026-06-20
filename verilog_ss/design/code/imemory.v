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
    input      [31:0] address_0,
    input      [31:0] address_1,
    input      [31:0] data_in,
    input             read_write,
    input             enable,
    output reg [31:0] data_out_0,
    output reg [31:0] data_out_1
    
);

// ====================
// SIGNALS + INIT
// ====================
// effective address (0 indexed)
wire       [31:0] ea_0;
wire       [31:0] ea_1;


localparam        START_ADDR = 32'h01000000;

(* ram_style = "block" *) reg [31:0] mem[0:`MEM_DEPTH / 4 - 1];

initial begin
    $readmemh(`MEM_PATH, mem);
end

// ====================
// READ LOGIC
// ====================
// Convert byte address to word index
assign ea_0 = (address_0 - START_ADDR) >> 2;
assign ea_1 = (address_1 - START_ADDR) >> 2;


always @(posedge clock) begin
    if (enable) begin
        // Write path unused in normal operation (read_write hardwired to 0)
        if (read_write == 1) begin
            mem[ea_0] <= data_in;
        end
        data_out_0 <= mem[ea_0];
        data_out_1 <= mem[ea_1];
    end
end

endmodule
