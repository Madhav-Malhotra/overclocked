// any other c# source code, e.g. Unity, can now have the following interaction with the CPU wrapper:
// TODO: maybe wrap around the static functions imported from shared library. There should only be 1 instance at a time though
//
class Program {
    static void Main(string[] args) {
        var myCpu = new CPU("level1.txt");
        //uncomment for normal CPU operation
        //myCpu.SetFetchEn(true);
        //myCpu.SetFdEn(true);
        //myCpu.SetDxEn(true);
        //myCpu.SetXmEn(true);
        //myCpu.SetMwEn(true);
        //// now advance the instruction through the stages
        for(int i=0; i<20; i++) {
            //CPU.tick();
            if (i == 1) myCpu.SetFetchEn(true);
            // read pc_r wire output
            //Console.WriteLine(myCpu.GetFetch());
            // can also retrieve a specific field of the pipeline register
            // Console.WriteLine(myCpu.GetFetch().pc);
            if (i == 2) myCpu.SetFetchEn(false);

            if (i == 3) myCpu.SetFdEn(true);
            // read the instruction output
            //Console.WriteLine(myCpu.GetFd());
            if (i == 4) myCpu.SetFdEn(false);

            if (i == 5) myCpu.SetDxEn(true);
            // read reg file output
            //Console.WriteLine(myCpu.GetDx());
            if (i == 6) myCpu.SetDxEn(false);

            if (i == 7) myCpu.SetXmEn(true);
            // read the ALU output data w, addr input to DMEM
            //Console.WriteLine(myCpu.GetXm());
            if (i == 8) myCpu.SetXmEn(false);

            if (i == 9) myCpu.SetMwEn(true);
            // should read input to WB Mux: mem output, alu, pc +4
            //Console.WriteLine(myCpu.GetMw());
            if (i == 10) myCpu.SetMwEn(false);

            //myCpu.PrintState();
        }
    }
}
