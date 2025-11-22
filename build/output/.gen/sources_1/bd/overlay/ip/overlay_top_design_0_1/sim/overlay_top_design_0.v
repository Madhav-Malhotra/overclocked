// (c) Copyright 1995-2025 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:module_ref:top:1.0
// IP Revision: 1

`timescale 1ns/1ps

(* IP_DEFINITION_SOURCE = "module_ref" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module overlay_top_design_0 (
  clk,
  rst,
  TRACE_tdata,
  TRACE_tvalid,
  TRACE_tready,
  TRACE_tlast,
  MEM_tdata,
  MEM_tvalid,
  MEM_tready,
  MEM_tlast
);

(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME clk, ASSOCIATED_BUSIF MEM:TRACE, ASSOCIATED_RESET rst, FREQ_HZ 50000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN overlay_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 clk CLK" *)
input wire clk;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME rst, POLARITY ACTIVE_LOW, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 rst RST" *)
input wire rst;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 TRACE TDATA" *)
output wire [127 : 0] TRACE_tdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 TRACE TVALID" *)
output wire TRACE_tvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 TRACE TREADY" *)
input wire TRACE_tready;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME TRACE, TDATA_NUM_BYTES 16, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 50000000, PHASE 0.0, CLK_DOMAIN overlay_processing_system7_0_0_FCLK_CLK0, LAYERED_METADATA undef, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 TRACE TLAST" *)
output wire TRACE_tlast;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 MEM TDATA" *)
input wire [63 : 0] MEM_tdata;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 MEM TVALID" *)
input wire MEM_tvalid;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 MEM TREADY" *)
output wire MEM_tready;
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME MEM, TDATA_NUM_BYTES 8, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 50000000, PHASE 0.0, CLK_DOMAIN overlay_processing_system7_0_0_FCLK_CLK0, LAYERED_METADATA undef, INSERT_VIP 0" *)
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 MEM TLAST" *)
input wire MEM_tlast;

  top inst (
    .clk(clk),
    .rst(rst),
    .TRACE_tdata(TRACE_tdata),
    .TRACE_tvalid(TRACE_tvalid),
    .TRACE_tready(TRACE_tready),
    .TRACE_tlast(TRACE_tlast),
    .MEM_tdata(MEM_tdata),
    .MEM_tvalid(MEM_tvalid),
    .MEM_tready(MEM_tready),
    .MEM_tlast(MEM_tlast)
  );
endmodule
