module branch_comp #(
    parameter IDATAW = 32
) (
    input signed [IDATAW-1:0] idata1,
    input signed [IDATAW-1:0] idata2,
    input br_un,                             // Unsigned branch
    output br_eq,                            // If not br_eq/br_lt, then br_gt
    output br_lt
);

    assign br_eq = (idata1 == idata2);
    assign br_lt = (br_un) ? 
        ( $unsigned(idata1) < $unsigned(idata2) ) : 
        ( idata1 < idata2 ); 

endmodule