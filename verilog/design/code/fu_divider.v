module fu_divider #(
    parameter WIDTH = 32
) (
    input  wire                  clk,
    input  wire                  rst_n,
    input  wire [WIDTH-1:0]      rs1_data,       // dividend
    input  wire [WIDTH-1:0]      rs2_data,       // divisor
    input  wire                  is_signed,       // DIV/REM = signed, DIVU/REMU = unsigned
    output wire [WIDTH-1:0]      quotient,        // DIV/DIVU result
    output wire [WIDTH-1:0]      remainder        // REM/REMU result
);

    // RISC-V spec edge cases
    wire div_by_zero = (rs2_data == 0);
    wire signed_overflow = is_signed &&
                           (rs1_data == {1'b1, {(WIDTH-1){1'b0}}}) &&  // -2^(WIDTH-1)
                           (rs2_data == {WIDTH{1'b1}});                 // -1

    // Convert signed operands to absolute values for division
    wire dividend_neg = is_signed && rs1_data[WIDTH-1];
    wire divisor_neg  = is_signed && rs2_data[WIDTH-1];

    wire [WIDTH-1:0] dividend_abs = dividend_neg ? (~rs1_data + 1) : rs1_data;
    wire [WIDTH-1:0] divisor_abs  = divisor_neg  ? (~rs2_data + 1) : rs2_data;

    // Restoring division using generate loop
    // Each iteration: shift remainder left by 1, bring in next dividend bit,
    // subtract divisor, keep result if non-negative (restore if negative)
    wire [WIDTH-1:0] rem_iter [WIDTH:0];
    wire [WIDTH-1:0] quot_iter [WIDTH:0];

    assign rem_iter[0]  = 0;
    assign quot_iter[0] = 0;

    genvar i;
    generate
        for (i = WIDTH - 1; i >= 0; i = i - 1) begin : gen_div
            wire [WIDTH-1:0] rem_shifted = {rem_iter[WIDTH-1-i][WIDTH-2:0], dividend_abs[i]};
            wire [WIDTH:0]   rem_sub     = {1'b0, rem_shifted} - {1'b0, divisor_abs};

            // If subtraction is non-negative, keep it and set quotient bit
            assign rem_iter[WIDTH-i]  = rem_sub[WIDTH] ? rem_shifted : rem_sub[WIDTH-1:0];
            assign quot_iter[WIDTH-i] = {quot_iter[WIDTH-1-i][WIDTH-2:0], ~rem_sub[WIDTH]};
        end
    endgenerate

    wire [WIDTH-1:0] quot_abs = quot_iter[WIDTH];
    wire [WIDTH-1:0] rem_abs  = rem_iter[WIDTH];

    // Sign correction: quotient is negative if operand signs differ,
    // remainder takes the sign of the dividend (per RISC-V spec)
    wire quot_neg = dividend_neg ^ divisor_neg;
    wire [WIDTH-1:0] quot_signed = quot_neg ? (~quot_abs + 1) : quot_abs;
    wire [WIDTH-1:0] rem_signed  = dividend_neg ? (~rem_abs + 1) : rem_abs;

    // RISC-V spec results for edge cases:
    //   div by zero:  quotient = all 1s (-1 unsigned), remainder = dividend
    //   overflow:     quotient = -2^(WIDTH-1),         remainder = 0
    assign quotient  = div_by_zero     ? {WIDTH{1'b1}} :
                       signed_overflow ? {1'b1, {(WIDTH-1){1'b0}}} :
                       quot_signed;

    assign remainder = div_by_zero     ? rs1_data :
                       signed_overflow ? {WIDTH{1'b0}} :
                       rem_signed;

endmodule
