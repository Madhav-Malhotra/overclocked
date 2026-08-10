## Bridge

Unified C# interface to interact with each CPU backend. Supported backends: 
- verilator (verilated C++ model of verilog source)
- FPGA board (synthesized design running on PYNQ-Z2)

According to Project Specifications, this Bridge should automatically determine if a PYNQ-Z2 is connected to the host machine. While this functionality is being implemented, the desired `ImplementationType` can be specified when instantiating the bridge. 

The CPU Architecture can be selected with CPUFactory.CPUArchitecture.[Basic or Superscalar]

```
ICPU myCpu = CPUFactory.Create(CPUFactory.ImplementationType.Verilator, "level1.txt", CPUFactory.CPUArchitetcure.Basic);
```

## Example C# usage

`Program.cs` contains example usage of the Bridge.

To run, cd into the bridge directory and run:
```
dotnet build

dotnet run
```


## To use in Unity

The following files should be copied to the Unity assets folder, so the C# can be called from Unity scripts.
- CPU.cs 
- VerilatorClient.cs
- FPGAClient.cs
- VerilatorClientSuperscalar.cs
- FPGAClientSuperscalar.cs