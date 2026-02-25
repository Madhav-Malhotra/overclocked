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

# compile the shared library
make bridge

# do both steps above
make

# for debugging: view the constructed commands 
make -n
```


Then run the C# side:
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
