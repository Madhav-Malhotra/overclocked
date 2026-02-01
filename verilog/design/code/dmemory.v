module dmemory #(
    parameter integer BASE = 32'h01000000
)
(
    input         clock,
    input         read_write,
    input  [1:0]  access_size,
    input  [31:0] address,
    input  [31:0] data_in,
    output reg [31:0] data_out
);

reg  [31:0] temp [0:`LINE_COUNT-1];
reg  [7:0]  mem  [0:`MEM_DEPTH-1];
wire [31:0] addr = address - BASE;
integer i;

initial begin
    $readmemh(`MEM_PATH, temp);
    for (i = 0; i < `LINE_COUNT; i = i + 1) begin
        {mem[4*i+3], mem[4*i+2], mem[4*i+1], mem[4*i]} = temp[i];
    end
end

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
    data_out <= {mem[addr+3], mem[addr+2], mem[addr+1], mem[addr]};
end

endmodule
