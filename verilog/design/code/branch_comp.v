// =============================================================================
// Module:      branch_comp
// Description: Evaluates branch conditions for RV32I branch instructions.
//              Computes equality and less-than (signed or unsigned).
// Inputs:      idata1, idata2 - 32-bit operands to compare
//              br_un          - 1 selects unsigned comparison, 0 selects signed
// Outputs:     br_eq          - asserted when idata1 == idata2
//              br_lt          - asserted when idata1 < idata2
// =============================================================================
module branch_comp #(
    parameter IDATAW = 32
) (
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    // Unsigned branch
    input br_un,
    // If !(br_eq || br_lt), then br_gt inferred
    output br_eq,
    output br_lt
);

    assign br_eq = (idata1 == idata2);
    assign br_lt = (br_un) ? 
        ( $unsigned(idata1) < $unsigned(idata2) ) : 
        ( idata1 < idata2 ); 

endmodule