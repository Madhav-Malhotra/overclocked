using System;
using System.Runtime.InteropServices;

class Program
{
    // Imports the function from our compiled shared library
    // required for each external function
    [DllImport("libdmem", CallingConvention = CallingConvention.Cdecl)]
    public static extern void init_dmem();

    [DllImport("libdmem", CallingConvention = CallingConvention.Cdecl)]
    public static extern void write_dmem(uint addr, uint data);

    [DllImport("libdmem", CallingConvention = CallingConvention.Cdecl)]
    public static extern uint read_dmem(uint addr);

    [DllImport("libdmem", CallingConvention = CallingConvention.Cdecl)]
    public static extern void cleanup_dmem();

    static void Main(string[] args)
    {
        Console.WriteLine("--- C# starting C++ Verilator call ---");
        
        try {
            init_dmem();
            uint baseAddr = 0x1000_0000;
            uint mem_data = read_dmem(baseAddr);
            Console.WriteLine("read data at 0x{0:X}, got: {1}", baseAddr, mem_data);
            // try writing data to the base address
            uint data = 1234;
            write_dmem(baseAddr, data);
            Console.WriteLine("writing data {0} to addr: {1:X}", data, baseAddr);

            // and then read it back!
            mem_data = read_dmem(baseAddr);
            Console.WriteLine("read data at 0x{0:X}, got: {1}", baseAddr, mem_data);

            cleanup_dmem();
        }
        catch (Exception ex) {
            Console.WriteLine($"Error: {ex.Message}");
        }

Console.WriteLine("--- C# call finished ---");
    }
}



