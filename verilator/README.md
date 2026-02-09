# Verilator

This folder contains exploratory work to connect components of the Verilog CPU design <-> verilator <-> C#. Currently connected components are the ALU and Data Memory.

## Prerequisites
- dotnet-sdk
- dotnet-runtime

## Instructions

To try the existing standalone modules, from each module folder (`overclocked/verilator/alu` and `overclocked/verilator/dmem`)
1. verilate the `top.v` file which contains the module copied from `overclocked/verilog/design/code/`
  - this generates the `obj_dir` directory
2. compile the `bridge.cpp` to create the shared library
  - this generates the `lib*.so` shared object
3. build and run the C# program
  - this generates the `bin/` and `obj` directories

```sh
verilator -cc top.v

# for alu/
g++ -O3 -shared -fPIC -o libalu.so \
-I obj_dir \
-I /usr/share/verilator/include \
/usr/share/verilator/include/verilated.cpp \
/usr/share/verilator/include/verilated_threads.cpp \
obj_dir/Vtop*.cpp \
bridge.cpp

# for dmem/
g++ -O3 -shared -fPIC -o libalu.so \
-I obj_dir \
-I /usr/share/verilator/include \
/usr/share/verilator/include/verilated.cpp \
/usr/share/verilator/include/verilated_threads.cpp \
obj_dir/Vtop*.cpp \
bridge.cpp

dotnet build

dotnet run
```

## Expected output from `dotnet run`: 

alu: 
```
--- C# starting C++ Verilator call ---
3
-17
--- C# call finished ---
```

dmem: 
```
--- C# starting C++ Verilator call ---
read data at 0x10000000, got: 0
writing data 1234 to addr: 10000000
read data at 0x10000000, got: 1234
--- C# call finished ---
```

## Troubleshooting

`Symbol lookup error: ... undefined symbol: _ZN12VlThreadPoolC1EP16VerilatedContextj`
- the included paths (`usr/share/verilator/include/*`)  might differ by system

```
 The command could not be loaded, possibly because:

  * You intended to execute a .NET application:

      The application 'run' does not exist or is not a managed .dll or .exe.

  * You intended to execute a .NET SDK command:

      No .NET SDKs were found.
```
- missing .NET SDK


Next steps: 
- [ ] look into exposing module signals as `verilator public`
- [ ] verilating the entire CPU design and creating a wrapper C# class
- [ ] clean up steps above into a Makefile
- [ ] use C# class in Unity
