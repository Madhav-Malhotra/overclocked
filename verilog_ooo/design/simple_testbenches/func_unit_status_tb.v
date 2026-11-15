// =============================================================================
// func_unit_status_tb - self-checking unit test for func_unit_status.v
//
// Targets the CURRENT port list. Checks behaviour at the contract level
// ("issues within a few cycles") rather than exact cycle timing, because
// plan.md Phase 2 (task 2.4) redefines the issue pipeline. Update this TB in
// the same change as any interface edit; Phase 2 adds exact-timing checks.
//
// Covers: FU-slot assignment per type (ALU before ALU_2, none when full);
// dispatch + issue of a ready row (iss_fu_id names the FU); the external
// `busy` input blocks issue; a row with a pending tag waits, then issues after
// the writeback broadcast and captures the broadcast value; register-file
// operands are captured into the right row, including back-to-back issues
// (RF model below has the real one-edge read latency); writeback frees the
// slot; re-dispatching a row clears its stale forwarded-value flags.
// =============================================================================
`timescale 1ns/1ps
module func_unit_status_tb;
  `include "tb_common.vh"

  localparam FUW = 3;
  localparam NUM_FU = 6;
  localparam NONE = 0, BRANCH = 1, MCM = 2, LOAD = 3, STORE = 4, ALU = 5, ALU_2 = 6;

  reg clock = 0, reset = 1;
  reg [FUW-1:0] ds_fu_type = 0;
  wire [FUW-1:0] ds_assigned_fu_id;
  reg ds_en = 0;
  reg [FUW-1:0] ds_fu_id = 0;
  reg [31:0] ds_pc = 0;
  reg [4:0] ds_rs1 = 0, ds_rs2 = 0, ds_rd = 0;
  reg [FUW-1:0] ds_rs1_tag = 0, ds_rs2_tag = 0;
  reg iss_en = 1;
  wire [31:0] iss_pc;
  wire [4:0] iss_rs1, iss_rs2;
  reg [31:0] iss_rs1_data = 0, iss_rs2_data = 0;
  wire issued;
  wire [FUW-1:0] iss_fu_id;
  reg wb_en = 0;
  reg [FUW-1:0] wb_tag_clear = 0;
  reg [31:0] wb_data = 0;
  reg [NUM_FU-1:0] busy = 0;
  wire iss_tag_found, iss_instr_found;

  functional_unit_status #(.NUM_ALU(2), .NUM_MULTICYCLE_MULT(1), .NUM_LOAD_STORE(1), .FUW(FUW)) dut (
    .clock(clock), .reset(reset),
    .ds_fu_type(ds_fu_type), .ds_assigned_fu_id(ds_assigned_fu_id),
    .ds_en(ds_en), .ds_fu_id(ds_fu_id), .ds_pc(ds_pc),
    .ds_rs1(ds_rs1), .ds_rs2(ds_rs2), .ds_rd(ds_rd),
    .ds_rs1_tag(ds_rs1_tag), .ds_rs2_tag(ds_rs2_tag),
    .iss_en(iss_en), .iss_fu_id(iss_fu_id), .iss_pc(iss_pc), .iss_rs1(iss_rs1), .iss_rs2(iss_rs2),
    .iss_rs1_data(iss_rs1_data), .iss_rs2_data(iss_rs2_data), .issued(issued),
    .wb_en(wb_en), .wb_tag_clear(wb_tag_clear), .wb_data(wb_data),
    .busy(busy), .iss_tag_found(iss_tag_found), .iss_instr_found(iss_instr_found)
  );

  always #5 clock = ~clock;

  // Register-file model: registered read, value of xN = 0x1000 + N (like register_file.v timing)
  always @(posedge clock) begin
    iss_rs1_data <= 32'h1000 + iss_rs1;
    iss_rs2_data <= 32'h1000 + iss_rs2;
  end

  task tick; begin @(posedge clock); #1; end endtask

  // Dispatch one instruction of FU type `t` into whatever slot the table assigns.
  // Returns the assigned FU id (0 if none was available; nothing is written then).
  task dispatch(input [FUW-1:0] t, input [31:0] pc, input [4:0] rs1, input [4:0] rs2,
                input [FUW-1:0] tag1, input [FUW-1:0] tag2, output [FUW-1:0] got);
    begin
      ds_fu_type = t; #1;
      got = ds_assigned_fu_id;
      if (got != NONE) begin
        ds_en = 1; ds_fu_id = got; ds_pc = pc; ds_rs1 = rs1; ds_rs2 = rs2; ds_rd = 5'd1;
        ds_rs1_tag = tag1; ds_rs2_tag = tag2;
        tick;
        ds_en = 0;
      end
    end
  endtask

  // Wait up to `max` cycles for the table to report an issue of `pc`.
  task wait_issue(input [31:0] pc, input integer max, output reg seen);
    integer k;
    begin
      seen = 0;
      for (k = 0; k < max && !seen; k = k + 1) begin
        if (iss_instr_found && iss_pc == pc) seen = 1;
        else tick;
      end
    end
  endtask

  task wb(input [FUW-1:0] tag, input [31:0] data); begin
    wb_en = 1; wb_tag_clear = tag; wb_data = data; tick; wb_en = 0; wb_tag_clear = 0;
  end endtask

  reg [FUW-1:0] got;
  reg seen;
  initial begin
    tick; tick; reset = 0; tick;

    // --- slot assignment when everything is free
    ds_fu_type = BRANCH; #1; `CHECK(ds_assigned_fu_id, BRANCH, "branch slot free")
    ds_fu_type = MCM;    #1; `CHECK(ds_assigned_fu_id, MCM,    "mcm slot free")
    ds_fu_type = LOAD;   #1; `CHECK(ds_assigned_fu_id, LOAD,   "load slot free")
    ds_fu_type = STORE;  #1; `CHECK(ds_assigned_fu_id, STORE,  "store slot free")
    ds_fu_type = ALU;    #1; `CHECK(ds_assigned_fu_id, ALU,    "first ALU preferred")
    ds_fu_type = NONE;   #1; `CHECK(ds_assigned_fu_id, NONE,   "NONE type gets no slot")

    // --- ready ALU instruction: dispatch, then it issues
    busy = 0;
    dispatch(ALU, 32'h0100_0000, 5'd2, 5'd3, 0, 0, got);
    `CHECK(got, ALU, "dispatch #1 -> ALU")
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, ALU_2, "second ALU used when first reserved")
    wait_issue(32'h0100_0000, 4, seen);
    `CHECK(seen, 1'b1, "ready row issues within 4 cycles")
    `CHECK(iss_fu_id, ALU, "iss_fu_id names the issuing FU")
    `CHECK(iss_rs1, 5'd2, "issue drives rs1 address")
    `CHECK(iss_rs2, 5'd3, "issue drives rs2 address")
    tick; tick;
    `CHECK(dut.issued_arr[ALU-1], 1'b1, "row marked issued")
    `CHECK(dut.rs1_data_arr[ALU-1], 32'h1002, "rs1 operand captured from RF (x2)")
    `CHECK(dut.rs2_data_arr[ALU-1], 32'h1003, "rs2 operand captured from RF (x3)")

    // --- busy input blocks issue of a ready row
    busy[ALU_2-1] = 1;
    dispatch(ALU, 32'h0100_0004, 5'd4, 5'd0, 0, 0, got);
    `CHECK(got, ALU_2, "dispatch #2 -> ALU_2")
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, NONE, "no ALU slot left")
    wait_issue(32'h0100_0004, 5, seen);
    `CHECK(seen, 1'b0, "row does not issue while its FU is busy")
    busy[ALU_2-1] = 0;
    wait_issue(32'h0100_0004, 4, seen);
    `CHECK(seen, 1'b1, "row issues once FU no longer busy")

    // --- tagged row (waits on MCM) issues after the broadcast and captures the value
    dispatch(LOAD, 32'h0100_0008, 5'd7, 5'd0, MCM, 0, got);
    `CHECK(got, LOAD, "dispatch #3 -> LOAD")
    wait_issue(32'h0100_0008, 5, seen);
    `CHECK(seen, 1'b0, "row waits while rs1 tag pending")
    wb(MCM, 32'hCAFE_F00D);
    `CHECK(dut.rs1_tag_arr[LOAD-1], 0, "tag cleared by matching writeback")
    `CHECK(dut.rs1_fwd_arr[LOAD-1], 1'b1, "value marked as forwarded")
    `CHECK(dut.rs1_data_arr[LOAD-1], 32'hCAFE_F00D, "broadcast value captured")
    wait_issue(32'h0100_0008, 4, seen);
    `CHECK(seen, 1'b1, "row issues after its producer writes back")

    tick; tick;
    `CHECK(dut.rs1_data_arr[LOAD-1], 32'hCAFE_F00D, "forwarded operand not overwritten by RF read")

    // --- writeback frees the producer's slot
    wb(ALU, 32'h1);
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, ALU, "ALU slot free after its writeback")
    wb(LOAD, 32'h2);
    ds_fu_type = LOAD; #1; `CHECK(ds_assigned_fu_id, LOAD, "LOAD slot free after its writeback")

    // --- re-dispatch into the LOAD row: stale forwarded flag must be cleared,
    //     so the operand comes from the RF this time
    dispatch(LOAD, 32'h0100_0010, 5'd9, 5'd0, 0, 0, got);
    `CHECK(got, LOAD, "re-dispatch -> LOAD")
    `CHECK(dut.rs1_fwd_arr[LOAD-1], 1'b0, "re-dispatch clears rs1 forwarded flag")
    wait_issue(32'h0100_0010, 4, seen);
    `CHECK(seen, 1'b1, "re-dispatched row issues")
    tick; tick;
    `CHECK(dut.rs1_data_arr[LOAD-1], 32'h1009, "re-dispatched row reads x9 from RF, not stale value")

    // --- back-to-back issue: two ready rows dispatched, then issued on consecutive
    //     cycles; each must capture its own RF operands
    wb(ALU_2, 32'h3);                 // free ALU_2 (ALU already free)
    dispatch(ALU, 32'h0100_0020, 5'd11, 5'd12, 0, 0, got);   // -> ALU
    `CHECK(got, ALU, "b2b dispatch #1 -> ALU")
    iss_en = 0;                       // hold issue so both rows are ready together
    dispatch(ALU, 32'h0100_0024, 5'd13, 5'd14, 0, 0, got);   // -> ALU_2
    `CHECK(got, ALU_2, "b2b dispatch #2 -> ALU_2")
    iss_en = 1;
    tick; `CHECK(iss_instr_found, 1'b1, "b2b: first issue")
    `CHECK(iss_fu_id, ALU, "b2b: ALU issues first (lower row)")
    tick; `CHECK(iss_instr_found, 1'b1, "b2b: second issue on the next cycle")
    `CHECK(iss_fu_id, ALU_2, "b2b: ALU_2 issues second")
    tick; tick;
    `CHECK(dut.rs1_data_arr[ALU-1],   32'h100b, "b2b: ALU row got x11")
    `CHECK(dut.rs2_data_arr[ALU-1],   32'h100c, "b2b: ALU row got x12")
    `CHECK(dut.rs1_data_arr[ALU_2-1], 32'h100d, "b2b: ALU_2 row got x13")
    `CHECK(dut.rs2_data_arr[ALU_2-1], 32'h100e, "b2b: ALU_2 row got x14")

    `TB_FINISH
  end
endmodule
