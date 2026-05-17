/*
 * V0.1.0
 * CPU.cs — C# wrapper around the Verilated RISC-V processor shared library.
 *
 * Provides a managed, object-oriented interface to the flat C API exported by
 * bridge.cpp.  P/Invoke is used to call into the compiled shared library
 * (libdesign_wrapper.so / design_wrapper.dll).
 *
 * Key responsibilities:
 *   - Declare [DllImport] bindings for every extern "C" function in bridge.cpp.
 *   - Expose per-stage helper structs (Fetch, Fd, Dx, Xm, Mw) so callers get
 *     strongly-typed snapshots of each pipeline register.
 *   - Wrap raw enable-setter calls in SetXxxEn() methods that also tick the
 *     clock, matching the game's "advance one stage at a time" usage pattern.
 *   - Implement IDisposable so cleanup_design_wrapper() is always called even
 *     if an exception occurs.
 *
 * ⚠️ Keep this file in sync with bridge.cpp: whenever a new signal is added to
 * CPUState in C++ or a new extern "C" function is added, mirror the change here.
 *
 * See verilator/README.md for build instructions.
 */

using System;
using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Sequential, Pack = 1)]
public struct CPUState {
    // MUST stay sync'ed with CPUState in C++, since we pass the struct ptr
    // order must match the CPUState definition
    public uint pc;          // Maps to uint32_t
    public uint instruction; // Maps to uint32_t

    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
    public uint[] regs;
    public uint alu_out;     // Maps to uint32_t
                             // branch_comp.v output ports
    public byte br_eq;
    public byte br_lt;
    public byte branch_comp_data1_sel; // 
    public byte branch_comp_data2_sel; // 
    public byte br_taken;              // 
    public byte pc_sel;                // 
    public byte br_un;                 // 
    public byte a_sel;                 // [1:0]
    public byte b_sel;                 // [1:0]
    public byte alu_sel;               // [3:0]
    public byte mem_rw;                // 
    public byte reg_wen;               // 
    public byte wb_sel;                // [1:0]
                                       // decoder.v output ports
    public byte opcode;         // [6:0]
    public byte addr_rd;        // [ADDRW-1:0]
    public byte addr_rs1;       // [ADDRW-1:0]
    public byte addr_rs2;       // [ADDRW-1:0]
    public byte funct3;         // [2:0]
    public byte funct7;         // [6:0]
    public uint imm;           // [DATAW-1:0] (32-bit)
    public byte shamt;          // [N_BITS-1:0] (Shift amount, typically 5 bits)
    public byte is_u_type_w;    // 1-bit
    public byte is_j_type_w;    // 1-bit
    public byte is_i_type_w;    // 1-bit
                                // dmemory.v output ports
    public uint dmem_data_out; // [31:0]
                               // imemory.v output ports
    public uint imem_data_out; // [31:0]
                               // register_file.v output ports
    public uint data_rs1;       // [DATAW-1:0]
    public uint data_rs2;       // [DATAW-1:0]
                                // writeback.v output ports
    public uint wb_data; // dependent on DATAW=32

    public uint dmem_data_in;
    public uint wb_in_alu;
    public uint mem;
    public uint pc4;
}

// output structs after each corresponding enable signal is high
// returned in the get_${stage} functions
public record struct Fetch(uint pc);

public record struct Fd(
    uint fd_pc,
    uint fd_pc4,
    uint instruction
);

public record struct Dx(
    uint addr_rs1,
    uint addr_rs2
);

public record struct Xm(
    uint alu_out,
    uint dmem_data_in
);

public record struct Mw(
    uint pc4,
    uint wb_in_alu,
    uint mem
);
enum Operation : byte {
    ADD = 0,
    SUB = 1,
    SLL = 2,
    SRL = 4,
    SLT = 5,
    SLTU = 6,
    XOR = 7,
    OR = 8,
    AND = 9,
    NOP = 10,
}

// Bridge CPU interface to abstract FPGA/Verilator backend from Unity.
public interface ICPU {
    // CPUState struct representing all module outputs.
    CPUState state { get; } // TODO make this var name uppercase
    // writeIMem loads a hex-encoded program file into instruction memory.
    void writeIMem(string path);
    // PrintState outputs the `state` for debugging.
    void PrintState();
    // GetState() retrieves `state` from CPU.
    CPUState GetState();
    // DON'T USE (deprecated):  retrieve the PC from the appropriate pipeline stage struct
    uint GetPC();
    // DON'T USE (deprecated):  retrieve the Instruction from the appropriate pipeline stage struct
    uint GetInstruction();
    // DON'T USE (deprecated):  retrieve the ALU output from the appropriate pipeline stage struct
    uint GetALUOut();
    // SetFetchEn enable/disable the Fetch stage.
    void SetFetchEn(bool val);
    // GetFetch retrieves a snapshot of Fetch stage outputs.
    Fetch GetFetch();
    // SetFdEn enable/disable the Fd stage.
    void SetFdEn(bool val);
    // GetFd retrieves a snapshot of Fd stage outputs.
    Fd GetFd();
    // SetDxEn enable/disable the Dx stage.
    void SetDxEn(bool val);
    // GetDx retrieves a snapshot of Dx stage outputs.
    Dx GetDx();
    // SetXmEn enable/disable the Xm stage.
    void SetXmEn(bool val);
    // GetXm retrieves a snapshot of Xm stage outputs.
    Xm GetXm();
    // SetMwEn enable/disable the Mw stage.
    void SetMwEn(bool val);
    // GetMw retrieves a snapshot of Mw stage outputs.
    Mw GetMw();
}

public static class CPUFactory
{
    // We use an Enum instead of a string to avoid typos.
    public enum ImplementationType { Verilator, FPGA }

    public static ICPU Create(ImplementationType type, string levelPath)
    {
        return type switch
        {
            ImplementationType.Verilator => new VerilatorClient(levelPath),
            //ImplementationType.FPGA      => new FPGAClient(levelPath),
            _ => throw new System.ArgumentException("Invalid Implementation Type")
        };
    }
}
