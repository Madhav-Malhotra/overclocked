// any other c# source code, e.g. Unity, can now have the following interaction with the CPU wrapper:
// TODO: maybe wrap around the static functions imported from shared library. There should only be 1 instance at a time though
//
class Program {
    static void Main(string[] args) {
        var myCpu = new CPU("level1.txt");
        CPU.dump_imem(10);
        // now advance the instruction through the stages
        for(int i=0; i<20; i++) {
            CPU.tick();
            myCpu.PrintState();
        }
        CPU.dump_dmem(10);
        CPU.dump_imem(10);
    }
}
