module fu_multiplier #(
    parameter WIDTH = 32
) (
    input  wire                  clk,
    input  wire                  rst_n,
    input  wire [WIDTH-1:0]      rs1_data,
    input  wire [WIDTH-1:0]      rs2_data,
    input  wire                  is_signed_a,
    input  wire                  is_signed_b,
    output wire [2*WIDTH-1:0]    rd_data
);

    // Sign-extend operands for signed/unsigned handling
    wire signed [WIDTH:0] a_ext = is_signed_a ? {rs1_data[WIDTH-1], rs1_data} : {1'b0, rs1_data};
    wire signed [WIDTH:0] b_ext = is_signed_b ? {rs2_data[WIDTH-1], rs2_data} : {1'b0, rs2_data};

    // Sign-extend a_ext to full accumulator width so left shifts preserve sign
    wire signed [2*WIDTH:0] a_full = {{WIDTH{a_ext[WIDTH]}}, a_ext};

    // Partial products
    wire [2*WIDTH:0] partial [WIDTH:0];

    // First partial product
    assign partial[0] = (b_ext[0]) ? a_full : {(2*WIDTH+1){1'b0}};

    // Generate partial products and accumulate via left-shift-and-add.
    // Bit WIDTH of b_ext is the sign extension bit with weight -2^WIDTH,
    // so we subtract its partial product instead of adding.
    genvar i;
    generate
        for (i = 1; i <= WIDTH; i = i + 1) begin : gen_partial
            wire [2*WIDTH:0] shifted = (b_ext[i]) ? (a_full << i) : {(2*WIDTH+1){1'b0}};
            wire subtract = (i == WIDTH);
            assign partial[i] = subtract ? (partial[i-1] - shifted)
                                         : (partial[i-1] + shifted);
        end
    endgenerate

    assign rd_data = partial[WIDTH][2*WIDTH-1:0];

endmodule