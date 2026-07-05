# FPGA webserver

This folder contains the contents of the simple webserver that will run on the FPGA's discrete CPU.

Currently, it creates a simple API to set and retrieve control signals, and retrieve CPU State. CPU State values are hardcoded but should be updated to use the [Xilinx MMIO library](https://pynq.readthedocs.io/en/v2.1/pynq_libraries/mmio.html) to store variables at physical addresses shared with the FPGA chip. 


The webserver is currently run in a docker container. Build and start the container with 
```sh
# from this directory, overclocked/webserver/
docker build -t fpga-server .

# the container is listening on its 8080 port, so map a host port to the container port
docker run -p 8080:8080 fpga-server:latest
```

## See API documentation

FastAPI generates Swagger UI documentation at `/docs`, so open [localhost:8080/docs](localhost:8080/docs) in your browser.

Alternatively, see [http://localhost:8080/openapi.json](http://localhost:8080/openapi.json) for the JSON specification.


## Try some endpoints

See all CPU state values:
```
curl localhost:8080/outputs/status
```

Set the `fetchEn` signal to true:
```
curl -X POST localhost:8080/controls/fetchEn/update  -H "Content-Type: application/json" -d '{"en": true}'
```
Use a similar endpoint for any other control signal:
```
/controls/fetchEn/update
/controls/fdEn/update
/controls/dxEn/update
/controls/xmEn/update
/controls/mwEn/update
```


See all control signals: 
```
curl localhost:8080/controls/status
```
