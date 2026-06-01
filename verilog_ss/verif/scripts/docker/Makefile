REPO_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../../..)
IMAGE     := overclocked-riscv
DOCKERFILE := $(dir $(lastword $(MAKEFILE_LIST)))Dockerfile

.PHONY: build run_all_benchmarks attach run_scripts clean

build:
	docker build -t $(IMAGE) -f $(DOCKERFILE) $(REPO_ROOT)

run_all_benchmarks:
	docker run --rm -v $(REPO_ROOT):/workspace $(IMAGE) \
		bash -c "cd /workspace/verilog/verif/scripts && make run_all_benchmarks"

attach:
	docker run --rm -it -v $(REPO_ROOT):/workspace $(IMAGE) bash

run_scripts:
	docker run --rm -v $(REPO_ROOT):/workspace $(IMAGE) \
		bash -c "cd /workspace/verilog && python3 run_scripts.py"

clean:
	docker rmi $(IMAGE)
