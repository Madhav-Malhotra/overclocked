// =============================================================================
// func_unit_status_tb - self-checking unit test for func_unit_status.v
//
// Exact-timing checks of the issue pipeline (plan.md task 2.4):
//   cycle N   : iss_sel_valid / iss_sel_ist_idx / iss_rf_rs1/2 for the selected row
//   cycle N+1 : iss_* (instruction + operands issued to its FU)
// The register-file model below has the real one-edge read latency and a write
// port (write lands at the edge, a same-edge read returns the old value).
//
// Covers: FU-slot assignment per class (ALU before ALU_2, none when full);
// dispatch stores identity/fields; two independent rows issue on consecutive
// cycles with correct operands and the smaller-PC row wins; three ready rows
// issue in PC order, one per cycle; a low `fu_ready` blocks issue; a tagged
// row waits, then issues after the writeback broadcast with the forwarded
// value (not the RF value); a row dispatched in the same cycle its source is
// written to the RF reads the new value; writeback frees the slot;
// re-dispatching a row clears its stale forwarded-value flags; memory order
// (plan.md D6): an older store that has not issued holds back a younger load,
// an older load holds back a younger store, a younger store does not hold
// back an older load.
// =============================================================================
`timescale 1ns/1ps
module func_unit_status_tb;
  // ====================
  // Self-checking helpers (each TB carries its own copy; no shared include files)
  // Usage:  `CHECK(actual, expected, "message")   ...   `TB_FINISH
  // ====================
  integer tb_errors = 0;  // number of failed CHECKs
  integer tb_checks = 0;  // number of CHECKs run

`define CHECK(act, exp, msg) \
  begin \
    tb_checks = tb_checks + 1; \
    if ((act) !== (exp)) begin \
      tb_errors = tb_errors + 1; \
      $display("  FAIL @%0t: %s: got %0h, expected %0h", $time, msg, (act), (exp)); \
    end \
  end

`define TB_FINISH \
  begin \
    if (tb_errors == 0) $display("PASS: %m (%0d checks)", tb_checks); \
    else begin \
      $display("FAIL: %m (%0d of %0d checks failed)", tb_errors, tb_checks); \
      $fatal(1); \
    end \
    $finish; \
  end

  localparam FUW = 3;
  localparam NUM_FU = 6;
  localparam NONE = 0, BRANCH = 1, MCM = 2, LOAD = 3, STORE = 4, ALU = 5, ALU_2 = 6;  // FU ids (as in func_unit_status.v)

  reg clock = 0, reset = 1;
  reg [FUW-1:0] ds_fu_type = 0;
  wire [FUW-1:0] ds_assigned_fu_id;
  reg ds_en = 0;
  reg [FUW-1:0] ds_fu_id = 0;
  reg [31:0] ds_pc = 0;
  reg [2:0] ds_ist_idx = 0;
  reg [4:0] ds_rs1 = 0, ds_rs2 = 0, ds_rd = 0;
  reg ds_uses_rs1 = 0, ds_uses_rs2 = 0, ds_writes_rd = 0;
  reg [FUW-1:0] ds_rs1_tag = 0, ds_rs2_tag = 0;
  reg [NUM_FU-1:0] fu_ready = {NUM_FU{1'b1}};  // per-FU ready (1 = can accept an instruction)
  wire iss_sel_valid;
  wire [2:0] iss_sel_ist_idx;
  wire [4:0] iss_rf_rs1, iss_rf_rs2;
  reg [31:0] iss_rf_rs1_data = 0, iss_rf_rs2_data = 0;
  wire iss_valid;
  wire [FUW-1:0] iss_fu_id;
  wire [2:0] iss_ist_idx;
  wire [31:0] iss_pc;
  wire [4:0] iss_rd;
  wire iss_writes_rd;
  wire [31:0] iss_op1, iss_op2;
  reg wb_en = 0;
  reg [FUW-1:0] wb_tag = 0;
  reg [31:0] wb_data = 0;

  functional_unit_status #(.NUM_ALU(2), .NUM_MULTICYCLE_MULT(1), .NUM_LOAD_STORE(1),
                           .FUW(FUW), .IST_W(3)) dut (
    .clock(clock), .reset(reset),
    .ds_fu_type(ds_fu_type), .ds_assigned_fu_id(ds_assigned_fu_id),
    .ds_en(ds_en), .ds_fu_id(ds_fu_id), .ds_pc(ds_pc), .ds_ist_idx(ds_ist_idx),
    .ds_rs1(ds_rs1), .ds_rs2(ds_rs2), .ds_uses_rs1(ds_uses_rs1), .ds_uses_rs2(ds_uses_rs2),
    .ds_rd(ds_rd), .ds_writes_rd(ds_writes_rd),
    .ds_rs1_tag(ds_rs1_tag), .ds_rs2_tag(ds_rs2_tag),
    .fu_ready(fu_ready),
    .iss_sel_valid(iss_sel_valid), .iss_sel_ist_idx(iss_sel_ist_idx),
    .iss_rf_rs1(iss_rf_rs1), .iss_rf_rs2(iss_rf_rs2),
    .iss_rf_rs1_data(iss_rf_rs1_data), .iss_rf_rs2_data(iss_rf_rs2_data),
    .iss_valid(iss_valid), .iss_fu_id(iss_fu_id), .iss_ist_idx(iss_ist_idx),
    .iss_pc(iss_pc), .iss_rd(iss_rd), .iss_writes_rd(iss_writes_rd),
    .iss_op1(iss_op1), .iss_op2(iss_op2),
    .wb_en(wb_en), .wb_tag(wb_tag), .wb_data(wb_data)
  );

  always #5 clock = ~clock;

  // Register-file model (register_file.v timing): xN = 0x1000 + N initially,
  // registered reads, write lands at the edge (a same-edge read sees the old value).
  reg [31:0] rf [0:31];
  reg        rf_we = 0;     // TB-driven RF write enable
  reg [4:0]  rf_waddr = 0;
  reg [31:0] rf_wdata = 0;
  integer r;  // RF init loop counter
  initial for (r = 0; r < 32; r = r + 1) rf[r] = 32'h1000 + r;
  always @(posedge clock) begin
    if (rf_we) rf[rf_waddr] <= rf_wdata;
    iss_rf_rs1_data <= rf[iss_rf_rs1];
    iss_rf_rs2_data <= rf[iss_rf_rs2];
  end

  task tick; begin @(posedge clock); #1; end endtask

  // Drive the dispatch inputs for an instruction of FU class `t`; returns the
  // assigned slot (NONE if none free). Does not clock: call tick (or
  // dispatch) to write the row. uses_rs* = source register != x0; writes rd.
  task set_ds(input [FUW-1:0] t, input [31:0] pc, input [2:0] ist, input [4:0] rs1, input [4:0] rs2,
              input [4:0] rd, input [FUW-1:0] tag1, input [FUW-1:0] tag2, output [FUW-1:0] got);
    begin
      ds_fu_type = t; #1;
      got = ds_assigned_fu_id;
      ds_en = (got != NONE); ds_fu_id = got; ds_pc = pc; ds_ist_idx = ist;
      ds_rs1 = rs1; ds_rs2 = rs2; ds_uses_rs1 = (rs1 != 0); ds_uses_rs2 = (rs2 != 0);
      ds_rd = rd; ds_writes_rd = 1; ds_rs1_tag = tag1; ds_rs2_tag = tag2;
    end
  endtask

  task dispatch(input [FUW-1:0] t, input [31:0] pc, input [2:0] ist, input [4:0] rs1, input [4:0] rs2,
                input [4:0] rd, input [FUW-1:0] tag1, input [FUW-1:0] tag2, output [FUW-1:0] got);
    begin
      set_ds(t, pc, ist, rs1, rs2, rd, tag1, tag2, got);
      tick; ds_en = 0;
    end
  endtask

  // Writeback broadcast for one cycle (no RF write)
  task wb(input [FUW-1:0] tag, input [31:0] data); begin
    wb_en = 1; wb_tag = tag; wb_data = data; tick; wb_en = 0; wb_tag = 0;
  end endtask

  // Check the iss_* outputs (instruction issuing to its FU this cycle)
  task check_issue(input [FUW-1:0] fu, input [2:0] ist, input [31:0] pc, input [4:0] rd,
                 input [31:0] op1, input [31:0] op2, input [255:0] msg);
    begin
      `CHECK(iss_valid, 1'b1, msg)
      `CHECK(iss_fu_id, fu, msg)
      `CHECK(iss_ist_idx, ist, msg)
      `CHECK(iss_pc, pc, msg)
      `CHECK(iss_rd, rd, msg)
      `CHECK(iss_writes_rd, 1'b1, msg)
      `CHECK(iss_op1, op1, msg)
      `CHECK(iss_op2, op2, msg)
    end
  endtask

  reg [FUW-1:0] got;   // FU id the table assigned to the last dispatch (0 = none free)
  integer k;           // wait loop counter
  initial begin
    tick; tick; reset = 0; tick;

    // --- slot assignment when everything is free
    ds_fu_type = BRANCH; #1; `CHECK(ds_assigned_fu_id, BRANCH, "branch slot free")
    ds_fu_type = MCM;    #1; `CHECK(ds_assigned_fu_id, MCM,    "mcm slot free")
    ds_fu_type = LOAD;   #1; `CHECK(ds_assigned_fu_id, LOAD,   "load slot free")
    ds_fu_type = STORE;  #1; `CHECK(ds_assigned_fu_id, STORE,  "store slot free")
    ds_fu_type = ALU;    #1; `CHECK(ds_assigned_fu_id, ALU,    "first ALU preferred")
    ds_fu_type = NONE;   #1; `CHECK(ds_assigned_fu_id, NONE,   "NONE class gets no slot")
    `CHECK(iss_sel_valid, 1'b0, "nothing to select in an empty table")
    `CHECK(iss_valid, 1'b0, "no issue in an empty table")

    // --- A: two independent ALU rows; the smaller PC (in ALU_2) issues first,
    //     the other on the next cycle; each issue carries its own operands
    fu_ready = {NUM_FU{1'b0}};                     // hold issue while both dispatch
    dispatch(ALU, 32'h0100_0100, 3'd0, 5'd2, 5'd3, 5'd10, NONE, NONE, got);
    `CHECK(got, ALU, "A: first ALU instr -> ALU")
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, ALU_2, "A: second ALU used when first reserved")
    dispatch(ALU, 32'h0100_00fc, 3'd1, 5'd4, 5'd5, 5'd11, NONE, NONE, got);
    `CHECK(got, ALU_2, "A: second ALU instr -> ALU_2")
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, NONE, "A: no ALU slot left")
    `CHECK(dut.ist_idx_arr[ALU_2-1], 3'd1, "A: ist_idx stored")
    `CHECK(dut.uses_rs1_arr[ALU_2-1], 1'b1, "A: uses_rs1 stored")
    `CHECK(dut.writes_rd_arr[ALU_2-1], 1'b1, "A: writes_rd stored")
    `CHECK(dut.rd_arr[ALU_2-1], 5'd11, "A: rd stored")
    `CHECK(iss_sel_valid, 1'b0, "A: FUs not ready block select")
    fu_ready = {NUM_FU{1'b1}}; #1;
    `CHECK(iss_sel_valid, 1'b1, "A: select once FUs ready")
    `CHECK(iss_sel_ist_idx, 3'd1, "A: smaller-PC row selected first")
    `CHECK(iss_rf_rs1, 5'd4, "A: RF rs1 address of selected row")
    `CHECK(iss_rf_rs2, 5'd5, "A: RF rs2 address of selected row")
    tick;
    check_issue(ALU_2, 3'd1, 32'h0100_00fc, 5'd11, 32'h1004, 32'h1005, "A: issue 1 (ALU_2)");
    `CHECK(iss_sel_valid, 1'b1, "A: second row selected while first issues")
    `CHECK(iss_sel_ist_idx, 3'd0, "A: second select = other row")
    `CHECK(iss_rf_rs1, 5'd2, "A: RF rs1 address of second row")
    tick;
    check_issue(ALU, 3'd0, 32'h0100_0100, 5'd10, 32'h1002, 32'h1003, "A: issue 2 (ALU), next cycle");
    `CHECK(iss_sel_valid, 1'b0, "A: nothing left to select")
    tick;
    `CHECK(iss_valid, 1'b0, "A: no issue after both issued")
    `CHECK(dut.issued_arr[ALU-1] && dut.issued_arr[ALU_2-1], 1'b1, "A: both rows marked issued")

    // --- writeback frees the slots
    wb(ALU, 32'h1);
    ds_fu_type = ALU; #1; `CHECK(ds_assigned_fu_id, ALU, "ALU slot free after its writeback")
    wb(ALU_2, 32'h2);

    // --- B: tagged row waits, issues after the broadcast with the forwarded value
    dispatch(LOAD, 32'h0100_0200, 3'd2, 5'd7, 5'd0, 5'd12, MCM, NONE, got);
    `CHECK(got, LOAD, "B: -> LOAD")
    for (k = 0; k < 4; k = k + 1) begin
      `CHECK(iss_sel_valid, 1'b0, "B: row waits while rs1 tag pending")
      tick;
    end
    wb(MCM, 32'hCAFE_F00D);              // RF x7 still holds 0x1007
    `CHECK(dut.rs1_tag_arr[LOAD-1], NONE, "B: tag cleared by matching writeback")
    `CHECK(dut.rs1_fwd_arr[LOAD-1], 1'b1, "B: value marked as forwarded")
    `CHECK(iss_sel_valid, 1'b1, "B: selected the cycle after the broadcast")
    `CHECK(iss_sel_ist_idx, 3'd2, "B: selected row")
    tick;
    check_issue(LOAD, 3'd2, 32'h0100_0200, 5'd12, 32'hCAFE_F00D, 32'h1000, "B: issue uses forwarded value");

    // --- C: dispatch in the same cycle the source register is written to the RF
    //     (pd.v masks the tag of a producer writing back this cycle): reads the new value
    set_ds(STORE, 32'h0100_0300, 3'd3, 5'd8, 5'd9, 5'd0, NONE, NONE, got);
    `CHECK(got, STORE, "C: -> STORE")
    wb_en = 1; wb_tag = ALU; wb_data = 32'hBEEF;            // producer of x8 writes back
    rf_we = 1; rf_waddr = 5'd8; rf_wdata = 32'hBEEF;
    tick; ds_en = 0; wb_en = 0; wb_tag = 0; rf_we = 0;
    `CHECK(iss_sel_valid, 1'b1, "C: selected the cycle after dispatch")
    tick;
    check_issue(STORE, 3'd3, 32'h0100_0300, 5'd0, 32'hBEEF, 32'h1009, "C: issue reads the new RF value");

    // --- D: fu_ready low blocks a row that can issue; it issues once the FU is ready
    wb(STORE, 32'h0);
    fu_ready[STORE-1] = 0;
    dispatch(STORE, 32'h0100_0310, 3'd4, 5'd1, 5'd2, 5'd0, NONE, NONE, got);
    for (k = 0; k < 4; k = k + 1) begin
      `CHECK(iss_sel_valid, 1'b0, "D: no select while FU not ready")
      tick;
    end
    fu_ready[STORE-1] = 1; #1;
    `CHECK(iss_sel_valid, 1'b1, "D: select once FU ready")
    tick;
    check_issue(STORE, 3'd4, 32'h0100_0310, 5'd0, 32'h1001, 32'h1002, "D: issue once FU ready");

    // --- E: re-dispatch into the LOAD row: stale forwarded flag cleared, operand from RF
    wb(LOAD, 32'h3);
    dispatch(LOAD, 32'h0100_0400, 3'd5, 5'd9, 5'd0, 5'd13, NONE, NONE, got);
    `CHECK(got, LOAD, "E: re-dispatch -> LOAD")
    `CHECK(dut.rs1_fwd_arr[LOAD-1], 1'b0, "E: re-dispatch clears rs1 forwarded flag")
    tick;
    check_issue(LOAD, 3'd5, 32'h0100_0400, 5'd13, 32'h1009, 32'h1000, "E: operand from RF, not stale value");

    // --- F: three ready rows issue in PC order, one per cycle
    wb(LOAD, 32'h4); wb(STORE, 32'h5);
    fu_ready = {NUM_FU{1'b0}};
    dispatch(MCM,  32'h0100_0530, 3'd0, 5'd3, 5'd4, 5'd14, NONE, NONE, got);
    dispatch(LOAD, 32'h0100_0510, 3'd1, 5'd5, 5'd0, 5'd15, NONE, NONE, got);
    dispatch(ALU,  32'h0100_0520, 3'd2, 5'd6, 5'd7, 5'd16, NONE, NONE, got);
    fu_ready = {NUM_FU{1'b1}}; #1;
    `CHECK(iss_sel_ist_idx, 3'd1, "F: smallest PC (LOAD) selected first")
    tick;
    check_issue(LOAD, 3'd1, 32'h0100_0510, 5'd15, 32'h1005, 32'h1000, "F: issue 1 = LOAD");
    tick;
    check_issue(ALU,  3'd2, 32'h0100_0520, 5'd16, 32'h1006, 32'h1007, "F: issue 2 = ALU");
    tick;
    check_issue(MCM,  3'd0, 32'h0100_0530, 5'd14, 32'h1003, 32'h1004, "F: issue 3 = MCM");
    tick;
    `CHECK(iss_valid, 1'b0, "F: one issue per ready row")

    // --- G1: older store (waiting on MCM) holds back a younger ready load
    wb(LOAD, 32'h6); wb(ALU, 32'h7);
    fu_ready = {NUM_FU{1'b0}};
    dispatch(STORE, 32'h0100_0600, 3'd3, 5'd1, 5'd2, 5'd0, NONE, MCM, got);
    dispatch(LOAD,  32'h0100_0604, 3'd4, 5'd3, 5'd0, 5'd17, NONE, NONE, got);
    fu_ready = {NUM_FU{1'b1}};
    for (k = 0; k < 4; k = k + 1) begin
      `CHECK(iss_sel_valid, 1'b0, "G1: younger load waits for the older store")
      tick;
    end
    wb(MCM, 32'h0000_0ABC);                // store's data operand arrives
    `CHECK(iss_sel_ist_idx, 3'd3, "G1: store selected first")
    tick;
    check_issue(STORE, 3'd3, 32'h0100_0600, 5'd0, 32'h1001, 32'h0000_0ABC, "G1: store issues");
    `CHECK(iss_sel_valid, 1'b1, "G1: load selected the cycle after the store")
    `CHECK(iss_sel_ist_idx, 3'd4, "G1: then the load")
    tick;
    check_issue(LOAD, 3'd4, 32'h0100_0604, 5'd17, 32'h1003, 32'h1000, "G1: load issues after the store");

    // --- G2: older load (waiting on ALU_2) holds back a younger ready store
    wb(LOAD, 32'h8); wb(STORE, 32'h9);
    fu_ready = {NUM_FU{1'b0}};
    dispatch(LOAD,  32'h0100_0700, 3'd0, 5'd4, 5'd0, 5'd18, ALU_2, NONE, got);
    dispatch(STORE, 32'h0100_0704, 3'd1, 5'd5, 5'd6, 5'd0, NONE, NONE, got);
    fu_ready = {NUM_FU{1'b1}};
    for (k = 0; k < 4; k = k + 1) begin
      `CHECK(iss_sel_valid, 1'b0, "G2: younger store waits for the older load")
      tick;
    end
    wb(ALU_2, 32'h0100_0F00);              // load's base address arrives
    `CHECK(iss_sel_ist_idx, 3'd0, "G2: load selected first")
    tick;
    check_issue(LOAD, 3'd0, 32'h0100_0700, 5'd18, 32'h0100_0F00, 32'h1000, "G2: load issues");
    `CHECK(iss_sel_ist_idx, 3'd1, "G2: store selected the cycle after the load")
    tick;
    check_issue(STORE, 3'd1, 32'h0100_0704, 5'd0, 32'h1005, 32'h1006, "G2: store issues after the load");

    // --- G3: a younger store (waiting on MCM) does not hold back an older load
    wb(LOAD, 32'hA); wb(STORE, 32'hB);
    dispatch(LOAD,  32'h0100_0800, 3'd2, 5'd7, 5'd0, 5'd19, NONE, NONE, got);
    `CHECK(iss_sel_valid, 1'b1, "G3: load can issue")
    `CHECK(iss_sel_ist_idx, 3'd2, "G3: load selected")
    set_ds(STORE, 32'h0100_0804, 3'd5, 5'd1, 5'd2, 5'd0, NONE, MCM, got);  // dispatch while the load issues
    tick; ds_en = 0;
    check_issue(LOAD, 3'd2, 32'h0100_0800, 5'd19, 32'h1007, 32'h1000, "G3: older load issues");
    `CHECK(iss_sel_valid, 1'b0, "G3: younger store still waits on its tag")

    `TB_FINISH
  end
endmodule
