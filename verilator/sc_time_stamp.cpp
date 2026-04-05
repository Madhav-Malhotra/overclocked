#include <cstdint>

// Verilator (especially on macOS) expects a sc_time_stamp symbol to exist,
// even when SystemC is not used.
double sc_time_stamp() { return 0.0; }

