// Shared self-checking helpers for unit testbenches (include inside a module).
// Usage:  `CHECK(actual, expected, "message")   ...   `TB_FINISH
integer tb_errors = 0;
integer tb_checks = 0;

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
