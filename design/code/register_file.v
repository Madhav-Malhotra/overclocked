module register_file #(
    parameter DATAW = 32,
    parameter ADDRW = $clog2(DATAW),
    parameter NUM_REGS = 32,
    parameter BASE_ADDR = 32'h01000000
)
(
    input clock,
    input write_enable,
    input [ADDRW-1:0] addr_rs1,
    input [ADDRW-1:0] addr_rs2,
    input [ADDRW-1:0] addr_rd,
    input [DATAW-1:0] data_rd,
    output reg [DATAW-1:0] data_rs1,
    output reg [DATAW-1:0] data_rs2
);

// Signal declarations
reg [DATAW-1:0] regs [0:NUM_REGS-1];
integer i;
initial begin
    for (i = 0; i < NUM_REGS; i = i + 1) begin
        regs[i] = 32'h00000000;
    end
    regs[2] = BASE_ADDR + `MEM_DEPTH; // stack pointer
end

// For debugging PD4 only
wire [DATAW-1:0] r10 = regs[10];
wire [DATAW-1:0] r3 = regs[3];

// Sequential writes
always @(posedge clock) begin
    // Write to any register except x0
    if (write_enable && addr_rd != 0) begin
        regs[addr_rd] <= data_rd;
    end
end

// Combinational reads
always @(*) begin
    // if writing to same register as read, treat as read-after-write
    // ensure not overwriting x0
    // data_rs1 = (write_enable && addr_rs1 == addr_rd && addr_rs1 != 0) ? data_rd : regs[addr_rs1];
    // data_rs2 = (write_enable && addr_rs2 == addr_rd && addr_rs2 != 0) ? data_rd : regs[addr_rs2];
    data_rs1 = regs[addr_rs1];
    data_rs2 = regs[addr_rs2];
end

endmodule
