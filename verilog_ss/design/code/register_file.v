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
    // way 1
    input write_enable_0,
    input  [ADDRW-1:0] addr_rs1_0,
    input  [ADDRW-1:0] addr_rs2_0,
    input  [ADDRW-1:0] addr_rd_0,
    input  [DATAW-1:0] data_rd_0,
    output [DATAW-1:0] data_rs1_0,
    output [DATAW-1:0] data_rs2_0,
    
    // way 2
    input write_enable_1,
    input  [ADDRW-1:0] addr_rs1_1,
    input  [ADDRW-1:0] addr_rs2_1,
    input  [ADDRW-1:0] addr_rd_1,
    input  [DATAW-1:0] data_rd_1,
    output [DATAW-1:0] data_rs1_1,
    output [DATAW-1:0] data_rs2_1
);

// ====================
// SIGNALS + INIT
// ====================
(* ram_style = "block" *) reg [DATAW-1:0] regs [0:NUM_REGS-1];

// way 1
reg [DATAW-1:0] data_rs1_r_0;
reg [DATAW-1:0] data_rs2_r_0;
// way 2
reg [DATAW-1:0] data_rs1_r_1;
reg [DATAW-1:0] data_rs2_r_1;
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
    
    // way 1
    if (write_enable_0) begin
        regs[addr_rd_0] <= data_rd_0;
    end
    data_rs1_r_0 <= regs[addr_rs1_0];
    data_rs2_r_0 <= regs[addr_rs2_0];

    // way 2
    if (write_enable_1) begin
        regs[addr_rd_1] <= data_rd_1;
    end
    data_rs1_r_1 <= regs[addr_rs1_1];
    data_rs2_r_1 <= regs[addr_rs2_1];


end

// way 1
assign data_rs1_0 = data_rs1_r_0;
assign data_rs2_0 = data_rs2_r_0;

// way 2
assign data_rs1_1 = data_rs1_r_1;
assign data_rs2_1 = data_rs2_r_1;

endmodule
