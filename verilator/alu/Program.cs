using System;
using System.Runtime.InteropServices;

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

class Program
{
    // Imports the function from our compiled shared library
    // required for each external function
    [DllImport("libalu", CallingConvention = CallingConvention.Cdecl)]
    public static extern void init_alu();
    [DllImport("libalu", CallingConvention = CallingConvention.Cdecl)]
    public static extern int execute_alu(int x, int y, byte op);
    [DllImport("libalu", CallingConvention = CallingConvention.Cdecl)]
    public static extern void cleanup_alu();

    static void Main(string[] args)
    {
        Console.WriteLine("--- C# starting C++ Verilator call ---");
        
        try {
            init_alu();
            int output = execute_alu(1,2,(byte)Operation.ADD);
            Console.WriteLine(output);
            Console.WriteLine(execute_alu(2,19,(byte)Operation.SUB));
            cleanup_alu();
        }
        catch (Exception ex) {
            Console.WriteLine($"Error: {ex.Message}");
        }

Console.WriteLine("--- C# call finished ---");
    }
}


