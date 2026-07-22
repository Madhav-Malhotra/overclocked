/*
 * This is JUST A DEMO of how to use the bridge (CPU.cs)
 * You can write similar code within the Unity game engine to achieve desired
 * functionality.
 */

// any other c# source code, e.g. Unity, can now have the following interaction with the CPU wrapper:
class Program
{
    static void Main(string[] args)
    {
        //ICPU myCpu = CPUFactory.Create(CPUFactory.ImplementationType.Verilator, "level1.txt");
        // ICPU myCpu = CPUFactory.Create("level1.txt");
        //ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.Verilator);
        //ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.FPGA);

        // UPDATED EXAMPLES (with new CPUArchitecture selection):
        ICPU myCpu = CPUFactory.CPUArchitecture("level1.txt", CPUFactory.ImplementationType.Verilator, CPUFactory.CPUArchitecture.Basic);
        ICPU myCpu = CPUFactory.CPUArchitecture("level1.txt", CPUFactory.ImplementationType.Verilator, CPUFactory.CPUArchitecture.Superscalar);
        ICPU myCpu = CPUFactory.CPUArchitecture("level1.txt", CPUFactory.ImplementationType.FPGA, CPUFactory.CPUArchitecture.Superscalar);



        Action printAllStages = delegate () // use for pretty-printing all pipeline stages in debugging
        {
            Console.WriteLine(
                    $"{myCpu.GetFetch(),-30}" + // only needs to be wide enough for the instruction in PC
                    $"{myCpu.GetFd(),-75}" +
                    $"{myCpu.GetDx(),-40}" +
                    $"{myCpu.GetXm(),-50}" +
                    $"{myCpu.GetMw(),-40}"
                    );
            Console.WriteLine("=============");
        };
        Action printOutput = delegate () // use for pretty-printing all outputs in debugging
        {
            myCpu.PrintState();
            Console.WriteLine("=============");
        };
        printOutput();
        //// now advance the instruction through the stages
        for (int i = 1; i <= 20; i++)
        {
            Console.WriteLine($"running instruction: {i}");
            myCpu.Tick();
            printOutput();
        }
    }
}
