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

class CPU : IDisposable
{
    private const string NativeLib = "design_wrapper";
    // Imports the function from our compiled shared library
    // required for each external function
    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void init_design_wrapper();

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void tick();

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void eval();

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void get_cpu_state(out CPUState state);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_fetch_en(bool val);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_fd_en(bool val);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_dx_en(bool val);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_xm_en(bool val);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_mw_en(bool val);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void set_imem(uint addr, uint instruction);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern uint peek_imem(uint addr);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void dump_imem(uint count);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void dump_dmem(uint count);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl)]
    public static extern void cleanup_design_wrapper();

    /*
     * writeIMem — Load a hex-encoded program file into instruction memory.
     *
     * Reads each line of the file at `path`, strips comments and optional "0x"
     * prefixes, parses the remaining text as a 32-bit hex instruction, and writes
     * it to imem via set_imem() starting at the base address 0x01000000.
     * Blank lines and comment-only lines are skipped.
     *
     * @param path  Path to the hex file (one instruction word per line).
     */
    public void writeIMem(string path) {
        try
        {
            string[] lines = File.ReadAllLines(path);
            uint currentAddr = 0x01000000; // Base addr of imem
            foreach (string line in lines)
            {
                // Clean the line (remove comments, whitespace, or '0x' prefix)
                string cleanLine = line.Split("//")[0].Trim(); 
                if (string.IsNullOrEmpty(cleanLine)) continue;
                if (cleanLine.StartsWith("0x")) cleanLine = cleanLine.Substring(2); // cut off 0x
                                                                                    // Parse hex string to 32-bit uint
                uint instruction = uint.Parse(cleanLine, System.Globalization.NumberStyles.HexNumber);
                set_imem(currentAddr, instruction);
                currentAddr += 4;
            }
            Console.WriteLine($"Successfully loaded {lines.Length} lines into IMEM.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error loading hex file: {ex.Message}");
        }
    }

    /*
     * PrintState — Print a human-readable summary of key CPU signals to stdout.
     *
     * Only a subset of fields (PC, instruction, ALU output, and a few registers)
     * is shown for brevity.  Calls get_cpu_state() internally to refresh state.
     * For the full signal snapshot use GetState().
     */
    public void PrintState() {
        get_cpu_state(out this.state);
        Console.WriteLine(
                $"PC: 0x{state.pc,-8:X} | " +
                $"Instr: 0x{state.instruction,-8:X} | " +
                $"ALU: {state.aluOut,-10} | " +
                $"x0: {state.regs[0],-3} | " +
                $"x5: {state.regs[5],-3} | " +
                $"x6: 0x{state.regs[6],-8:X} | " +
                $"x7: {state.regs[7],-3}"
                );
    }

    /*
     * GetState — Return a full snapshot of every observable CPU signal.
     *
     * Calls get_cpu_state() to refresh and returns the raw CPUState struct.
     * Prefer the typed stage helpers (GetFetch, GetFd, …) when only one
     * pipeline stage's signals are needed.
     *
     * @return  A CPUState struct populated with the current simulation state.
     */
    public CPUState GetState() {
        get_cpu_state(out this.state);
        return this.state;
    }

    /*
     * GetPC — Return the current program counter value.
     *
     * @return  The pc field from the refreshed CPUState.
     */
    public uint GetPC() {
        get_cpu_state(out this.state);
        return this.state.pc;
    }

    /*
     * GetInstruction — Return the instruction word currently in the Fetch/Decode register.
     *
     * @return  The instruction field from the refreshed CPUState.
     */
    public uint GetInstruction() {
        get_cpu_state(out this.state);
        return this.state.instruction;
    }

    /*
     * GetALUOut — Return the ALU result register value (alu_xm_r).
     *
     * @return  The alu_out field from the refreshed CPUState.
     */
    public uint GetALUOut() {
        get_cpu_state(out this.state);
        return this.state.alu_out;
    }

    /*
     * SetFetchEn — Enable/disable the Fetch stage and advance the clock.
     *
     * Ticks the clock before applying the enable so the prior stage's outputs
     * are latched before the new enable takes effect.
     *
     * @param val  true to enable the Fetch stage; false to stall it.
     */
    public void SetFetchEn(bool val) {
        tick();
        set_fetch_en(val);
    }

    /*
     * GetFetch — Return a typed snapshot of the Fetch stage outputs.
     *
     * @return  A Fetch record containing the current PC.
     */
    public Fetch GetFetch() {
        get_cpu_state(out this.state);
        return new Fetch {
            pc = this.state.pc
        };
    }

    /*
     * SetFdEn — Enable/disable the Fetch→Decode pipeline register and advance the clock.
     *
     * @param val  true to enable the FD register; false to stall it.
     */
    public void SetFdEn(bool val) {
        tick();
        set_fd_en(val);
    }

    /*
     * GetFd — Return a typed snapshot of the Fetch→Decode register contents.
     *
     * @return  An Fd record containing fd_pc, fd_pc4, and the instruction word.
     */
    public Fd GetFd() {
        get_cpu_state(out this.state);
        return new Fd {
            fd_pc = this.state.pc,
            fd_pc4 = this.state.pc4,
            instruction = this.state.instruction
        };
    }

    /*
     * SetDxEn — Enable/disable the Decode→Execute pipeline register and advance the clock.
     *
     * @param val  true to enable the DX register; false to stall it.
     */
    public void SetDxEn(bool val) {
        tick();
        set_dx_en(val);
    }

    /*
     * GetDx — Return a typed snapshot of the Decode→Execute register contents.
     *
     * @return  A Dx record containing the source register addresses (addr_rs1, addr_rs2).
     */
    public Dx GetDx() {
        get_cpu_state(out this.state);
        return new Dx {
            addr_rs1 = this.state.addr_rs1,
            addr_rs2 = this.state.addr_rs2,
        };
    }

    /*
     * SetXmEn — Enable/disable the Execute→Memory pipeline register and advance the clock.
     *
     * @param val  true to enable the XM register; false to stall it.
     */
    public void SetXmEn(bool val) {
        tick();
        set_xm_en(val);
    }

    /*
     * GetXm — Return a typed snapshot of the Execute→Memory register contents.
     *
     * @return  An Xm record containing alu_out and the data memory write value (dmem_data_in).
     */
    public Xm GetXm() {
        get_cpu_state(out this.state);
        return new Xm {
            alu_out = this.state.alu_out,
            dmem_data_in = this.state.dmem_data_in
        };
    }

    /*
     * SetMwEn — Enable/disable the Memory→Writeback pipeline register and advance the clock.
     *
     * @param val  true to enable the MW register; false to stall it.
     */
    public void SetMwEn(bool val) {
        tick();
        set_mw_en(val);
    }

    /*
     * GetMw — Return a typed snapshot of the Memory→Writeback register contents.
     *
     * @return  An Mw record containing pc4, wb_in_alu, and the memory read value (mem).
     */
    public Mw GetMw() {
        get_cpu_state(out this.state);
        return new Mw {
            pc4 = this.state.pc4,
            wb_in_alu = this.state.wb_in_alu,
            mem = this.state.mem
        };
    }

    private CPUState state; // TODO fix, the interface has the property, and this private var can't be used
    private bool disposed = false;

    /*
     * CPU — Initialize the Verilated model and load a program into instruction memory.
     *
     * Calls init_design_wrapper() to reset the simulation, then writeIMem() to
     * populate imem from the hex file at `path`.
     *
     * @param path  Path to the hex program file (see writeIMem for format details).
     */
    public CPU (string path) {
        this.state = new CPUState();
        init_design_wrapper();
        writeIMem(path);
    }

    // Diposable interface from https://learn.microsoft.com/en-us/dotnet/api/system.idisposable?view=net-10.0
    // Implement IDisposable.
    // Do not make this method virtual.
    // A derived class should not be able to override this method.
    public void Dispose()
    {
        Dispose(disposing: true);
        // This object will be cleaned up by the Dispose method.
        // Therefore, you should call GC.SuppressFinalize to
        // take this object off the finalization queue
        // and prevent finalization code for this object
        // from executing a second time.
        GC.SuppressFinalize(this);
    }

    // Dispose(bool disposing) executes in two distinct scenarios.
    // If disposing equals true, the method has been called directly
    // or indirectly by a user's code. Managed and unmanaged resources
    // can be disposed.
    // If disposing equals false, the method has been called by the
    // runtime from inside the finalizer and you should not reference
    // other objects. Only unmanaged resources can be disposed.
    protected virtual void Dispose(bool disposing)
    {
        // Check to see if Dispose has already been called.
        if(!this.disposed)
        {
            // If disposing equals true, dispose all managed
            // and unmanaged resources.
            if(disposing)
            {
                // Dispose managed resources.
                // nothing in this class is currently managed, just the unmanaged bridge memory below
            }
            cleanup_design_wrapper();
            // state stuct will be cleaned up after this function exits, don't set to null

            // Note disposing has been done.
            disposed = true;
        }
    }

    // Use C# finalizer syntax for finalization code.
    // This finalizer will run only if the Dispose method
    // does not get called.
    // It gives your base class the opportunity to finalize.
    // Do not provide finalizer in types derived from this class.
    ~CPU()
    {
        // Do not re-create Dispose clean-up code here.
        // Calling Dispose(disposing: false) is optimal in terms of
        // readability and maintainability.
        Dispose(disposing: false);
    }
}


