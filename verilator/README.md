## Verilator

Find signals in verilated output to use in CPU.cs (CPU wrapper class)
- get `output_port_name` from verilog source
```
grep "output_port_name" obj_dir/Vdesign_wrapper___024root.h
# e.g., if looking for the br_eq output port from code/branch_comp.v
grep "br_eq" obj_dir/Vdesign_wrapper___024root.h
```

Makefile:
```sh
# run verilator on the verilog source code
make verilog

# compile the shared library (Linux/macOS) — builds both the basic
# (libdesign_wrapper) and superscalar (libdesign_wrapper_ss) libs and
# copies both into $(UNITY_PLUGINS_DIR)
make bridge

# cross-compile both DLLs for Windows (basic design_wrapper.dll and
# superscalar design_wrapper_ss.dll) and copy both into $(UNITY_PLUGINS_DIR)
make dll

# do both steps above
make

# for debugging: view the constructed commands 
make -n
```


Then run the C# side, from `overclocked/bridge/`
```
dotnet build

dotnet run
```


full compilation

```sh
verilator -cc design_wrapper.v -Icode -DMEM_DEPTH=1048576 --public-flat-rw

g++ -O3 -shared -fPIC -o libdesign_wrapper.so \
-I obj_dir \
-I /usr/share/verilator/include \
-I /usr/share/verilator/include/vltstd \
/usr/share/verilator/include/verilated.cpp \
/usr/share/verilator/include/verilated_threads.cpp \
/usr/share/verilator/include/verilated_dpi.h \
obj_dir/Vdesign_wrapper*.cpp \
bridge.cpp
```
