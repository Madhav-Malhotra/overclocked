## Bridge

Unified C# interface to interact with each CPU backend. Supported backends: 
- verilator (verilated C++ model of verilog source)
- FPGA board (synthesized design running on PYNQ-Z2)

According to Project Specifications, this Bridge should automatically determine if a PYNQ-Z2 is connected to the host machine. While this functionality is being implemented, the desired `ImplementationType` can be specified when instantiating the bridge. 

The CPU Architecture can be selected with CPUFactory.CPUArchitecture.[Basic or Superscalar]

```
<<<<<<< HEAD
ICPU myCpu = CPUFactory.Create(CPUFactory.ImplementationType.Verilator, "level1.txt", CPUFactory.CPUArchitetcure.Basic);
=======
ICPU myCpu = CPUFactory.Create("level1.txt", CPUFactory.ImplementationType.Verilator);
>>>>>>> origin/main
```

`CPUFactory.Create` also has a `string[]` overload for callers that already have assembled hex
instructions in memory (rather than a file path) — see `CPUUnityExtensions.Create` in Unity for
an example (`unity/Assets/CPUWrapper/CPUUnityExtensions.cs`).

## Example C# usage

`Program.cs` contains example usage of the Bridge.

To run, cd into the bridge directory and run:
```
dotnet build

dotnet run
```


## To use in Unity

<<<<<<< HEAD
The following files should be copied to the Unity assets folder, so the C# can be called from Unity scripts.
- CPU.cs 
- VerilatorClient.cs
- FPGAClient.cs
- VerilatorClientSuperscalar.cs
- FPGAClientSuperscalar.cs
=======
`bridge/` is the sole source of truth for `CPU.cs`, `VerilatorClient.cs`, and `FPGAClient.cs` —
never hand-edit the copies under `unity/Assets/CPUWrapper/`. To publish changes to Unity, run
from this directory:
```
make sync-unity
```
This copies the three files into `unity/Assets/CPUWrapper/`, prepending an
AUTO-GENERATED/DO-NOT-EDIT header and rewriting `Console.WriteLine(` calls to `Debug.Log(` (Unity
doesn't route `Console.WriteLine` to its Console window). If a destination file has no `.meta` yet
(i.e. it's a brand-new file), the Makefile prints a warning — open the file once in the Unity
Editor (Project window) first so a `.meta` is generated, then re-run `make sync-unity`.

Unity-only needs (e.g. adapting `InstructionData[]`, a Unity level-JSON type, into the generic
`string[]` hex overloads above) live in a separate, hand-maintained, non-generated file,
`unity/Assets/CPUWrapper/CPUUnityExtensions.cs` — add new Unity-specific logic there, not inside
the generated files.
>>>>>>> origin/main
