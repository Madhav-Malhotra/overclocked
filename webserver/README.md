# FPGA webserver

This folder contains the contents of the simple webserver that will run on the FPGA's discrete CPU.

Currently, it creates a simple API to set and retrieve control signals, and retrieve CPU State. CPU State is populated by reading values from memory-mapped registers (AXI GPIO blocks).

The webserver should be run on the ARM core on the PYNQ-Z2.

```
# SSH to board
ssh xilinx@192.168.2.99
cd webserver-fastapi/
# virtul env's pyvenv.cfg must have
# include-system-site-packages = true
# to use the already-installed system-wide `pynq` pkg
source env/bin/activate
# run the webserver (sudo needed for mmio pkg)
sudo env/bin/python3 main.py

# output:
[sudo] password for xilinx:
INFO:     Started server process [2656]
INFO:     Waiting for application startup.
INFO:     Application startup complete.
INFO:     Uvicorn running on http://0.0.0.0:8080 (Press CTRL+C to quit)
```

Test out the endpoints from your local machine:

```
curl -X POST 192.168.2.99:8080/imem/update
curl -X POST 192.168.2.99:8080/tick
curl 192.168.2.99:8080/outputs/status
```

## Updating the webserver

The webserver source files and generated bitstream files must be copied to the board on every change.

```
scp main.py hw_cfg.py xilinx@192.168.2.99:/home/xilinx/webserver-fastapi/

# from the `wired` Vivado project root:
scp wired.gen/sources_1/bd/design_1/hw_handoff/design_1.hwh xilinx@192.168.2.99:/home/xilinx/webserver-fastapi/design_1_wrapper.hwh
scp wired.runs/impl_1/design_1_wrapper.bit xilinx@192.168.2.99:/home/xilinx/webserver-fastapi/design_1_wrapper.bit
```

## See API documentation

FastAPI generates Swagger UI documentation at `/docs`, so open [localhost:8080/docs](localhost:8080/docs) in your browser.

Alternatively, see [http://localhost:8080/openapi.json](http://localhost:8080/openapi.json) for the JSON specification.

## Previous Dockerfile-based development

TODO (diana) update the webserver if we want to support this method again (current unconditional mmio usage doesn't work with running the webserver locally)

The webserver was previously run in a docker container for development. Build and start the container with

```sh
# from this directory, overclocked/webserver/
docker build -t fpga-server .

# the container is listening on its 8080 port, so map a host port to the container port
docker run -p 8080:8080 fpga-server:latest
```

See all CPU state values:

```
curl localhost:8080/outputs/status
```
