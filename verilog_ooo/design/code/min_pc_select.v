// =============================================================================
// Module:      min_pc_select
// Description: Combinational selector: among the valid inputs, picks the one
//              with the smallest PC (plan.md D2). Shared by issue select and
//              writeback select. Built as a balanced comparison tree over the
//              inputs padded to a power of two; padding leaves are invalid
//              constants and are optimised away (N = 6: 5 full-width 32-bit
//              comparators, 3 levels deep). An invalid input loses every
//              compare; on equal PCs the lower index wins.
// Inputs:      valid - one bit per candidate
//              pc    - candidate PCs, flattened: candidate i at [i*DATAW +: DATAW]
// Outputs:     min_pc_valid  - at least one candidate is valid
//              min_pc_idx    - index of the smallest-PC valid candidate
//              min_pc_onehot - one-hot of min_pc_idx (all zero when !min_pc_valid)
// =============================================================================
module min_pc_select #(
    parameter N     = 6,
    parameter DATAW = 32,
    parameter IDXW  = (N > 1) ? $clog2(N) : 1   // width of min_pc_idx
)(
    input  [N-1:0]       valid,
    input  [N*DATAW-1:0] pc,
    output               min_pc_valid,
    output [IDXW-1:0]    min_pc_idx,
    output [N-1:0]       min_pc_onehot
);

localparam LEVELS = (N > 1) ? $clog2(N) : 1;  // comparator levels
localparam LEAVES = 1 << LEVELS;              // inputs padded to a power of two

// ====================
// TREE NODES (heap order)
// ====================
// Node 1 is the root, node k has children 2k (lower indices) and 2k+1; the
// leaves are nodes LEAVES .. 2*LEAVES-1. Each node carries the winner so far.
wire [2*LEAVES-1:0]       node_valid;
wire [2*LEAVES*DATAW-1:0] node_pc;
wire [2*LEAVES*IDXW-1:0]  node_idx;

genvar g;
generate
    for (g = 0; g < LEAVES; g = g + 1) begin : leaf
        if (g < N) begin : real_input
            assign node_valid[LEAVES + g]                  = valid[g];
            assign node_pc[(LEAVES + g)*DATAW +: DATAW]    = pc[g*DATAW +: DATAW];
            assign node_idx[(LEAVES + g)*IDXW +: IDXW]     = g[IDXW-1:0];
        end else begin : padding
            assign node_valid[LEAVES + g]                  = 1'b0;
            assign node_pc[(LEAVES + g)*DATAW +: DATAW]    = {DATAW{1'b0}};
            assign node_idx[(LEAVES + g)*IDXW +: IDXW]     = {IDXW{1'b0}};
        end
    end

    for (g = 1; g < LEAVES; g = g + 1) begin : cmp
        // left child wins if it is valid and the right one is not, or its PC is not larger
        wire take_left = node_valid[2*g] &&
                         (!node_valid[2*g+1] ||
                          node_pc[(2*g)*DATAW +: DATAW] <= node_pc[(2*g+1)*DATAW +: DATAW]);
        assign node_valid[g]               = node_valid[2*g] || node_valid[2*g+1];
        assign node_pc[g*DATAW +: DATAW]   = take_left ? node_pc[(2*g)*DATAW +: DATAW]
                                                       : node_pc[(2*g+1)*DATAW +: DATAW];
        assign node_idx[g*IDXW +: IDXW]    = take_left ? node_idx[(2*g)*IDXW +: IDXW]
                                                       : node_idx[(2*g+1)*IDXW +: IDXW];
    end
endgenerate

// node 0 is unused (heap order starts at 1)
assign node_valid[0]          = 1'b0;
assign node_pc[0 +: DATAW]    = {DATAW{1'b0}};
assign node_idx[0 +: IDXW]    = {IDXW{1'b0}};

// ====================
// OUTPUTS
// ====================
assign min_pc_valid  = node_valid[1];
assign min_pc_idx    = node_idx[IDXW +: IDXW];
assign min_pc_onehot = min_pc_valid ? ({{(N-1){1'b0}}, 1'b1} << min_pc_idx) : {N{1'b0}};

endmodule
