// =============================================================================
// Module:      register_file
// Description: 32x32-bit register file with two read ports and one write port.
//              x0 is not hardwired here; the write-enable gate is in pd.v.
//              x2 (stack pointer) is initialised to BASE_ADDR + MEM_DEPTH.
//              Reads and writes are registered (one-cycle latency).
// Inputs:      clock        - clock
//              write_enable - enables write to addr_rd on rising edge
//              addr_rs1     - read address for port 1
//              addr_rs2     - read address for port 2
//              addr_rd      - write address
//              data_rd      - data to write
// Outputs:     data_rs1     - data from register addr_rs1 (registered)
//              data_rs2     - data from register addr_rs2 (registered)
// =============================================================================
module register_file #(
    parameter DATAW     = 32,
    parameter ADDRW     = $clog2(DATAW),
    parameter NUM_REGS  = 32,
    parameter BASE_ADDR = 32'h01000000
)
(
    input clock,
    input write_enable,
    input  [ADDRW-1:0] addr_rs1,
    input  [ADDRW-1:0] addr_rs2,
    input  [ADDRW-1:0] addr_rd,
    input  [DATAW-1:0] data_rd,
    output [DATAW-1:0] data_rs1,
    output [DATAW-1:0] data_rs2
);

// ====================
// SIGNALS + INIT
// ====================
(* ram_style = "block" *) reg [DATAW-1:0] regs [0:NUM_REGS-1];
reg [DATAW-1:0] data_rs1_r;
reg [DATAW-1:0] data_rs2_r;
integer i;

initial begin
    for (i = 0; i < NUM_REGS; i = i + 1) begin
        regs[i] = 32'h0;
    end
    // x2 is the stack pointer; initialise to top of memory
    regs[2] = BASE_ADDR + `MEM_DEPTH;
end

// ====================
// READ/WRITE LOGIC
// ====================
always @(posedge clock) begin
    // x0 write guard is handled by reg_wen in control_signals.v
    if (write_enable) begin
        regs[addr_rd] <= data_rd;
    end
    data_rs1_r <= regs[addr_rs1];
    data_rs2_r <= regs[addr_rs2];
end

assign data_rs1 = data_rs1_r;
assign data_rs2 = data_rs2_r;

endmodule
