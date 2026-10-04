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
        // ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.Verilator, CPUFactory.CPUArchitecture.Basic, false);
        ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.Verilator, CPUFactory.CPUArchitecture.Superscalar, false);
        // ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.FPGA, CPUFactory.CPUArchitecture.Superscalar);



        Action printAllStages = delegate () // use for pretty-printing all pipeline stages in debugging
        {
            // Console.WriteLine(
            //         $"{myCpu.GetFetch(0),-30}" + // only needs to be wide enough for the instruction in PC
            //         $"{myCpu.GetFd(0),-75}" +
            //         $"{myCpu.GetDx(0),-40}" +
            //         $"{myCpu.GetXm(0),-50}" +
            //         $"{myCpu.GetMw(0),-40}"
            //         );
            // Console.WriteLine("=============");

            // // for superscalar 
            // Console.WriteLine(
            //         $"{myCpu.GetFetch(1),-30}" + // only needs to be wide enough for the instruction in PC
            //         $"{myCpu.GetFd(1),-75}" +
            //         $"{myCpu.GetDx(1),-40}" +
            //         $"{myCpu.GetXm(1),-50}" +
            //         $"{myCpu.GetMw(1),-40}"
                    // );
            // Console.WriteLine("=============");
        };
        Action printOutput = delegate () // use for pretty-printing all outputs in debugging
        {
            myCpu.PrintState(0);

            // for superscalar
            // myCpu.PrintState(1);

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
