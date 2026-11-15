FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Core build tools, RISC-V cross-compiler, Verilator, Python
RUN apt-get update && apt-get install -y \
    build-essential \
    python3 \
    git \
    gcc-riscv64-unknown-elf \
    binutils-riscv64-unknown-elf \
    verilator \
    device-tree-compiler \
    && rm -rf /var/lib/apt/lists/*

# Build Spike (RISC-V ISS) from source — not in Ubuntu apt repos
RUN git clone --depth=1 https://github.com/riscv-software-src/riscv-isa-sim /tmp/spike \
    && mkdir /tmp/spike/build \
    && cd /tmp/spike/build \
    && ../configure --prefix=/usr/local \
    && make -j$(nproc) \
    && make install \
    && rm -rf /tmp/spike

WORKDIR /workspace
