#!/bin/bash

if [ "$(basename -- "$0")" != "bash" ] && [ -z "$BASH_VERSION" ]; then
    printf "\033[0;31mERROR: Please run this script with bash. Run the following command, then log in again.\033[0m\n\n" >&2
    printf "\033[0;31m       chsh -s /bin/bash\033[0m\n\n" >&2
    (return 0 2>/dev/null) && return 1 || exit 1
fi

printf "================ Computer Architecture Course Environment Setup ================\n\n"

export PROJECT_ROOT=$(cd $(dirname ${BASH_SOURCE[0]}); pwd)
printf "%-40s%s\n" "Project Root (\$PROJECT_ROOT):" "$PROJECT_ROOT"

unset VERILATOR_ROOT
rm -rf $PROJECT_ROOT/bin_verilator
VERILATOR_DIR=/opt-src/Excluded/verilator4210 # change if verilator location moves
if [ -d "$VERILATOR_DIR" ]; then
    ln -sf $VERILATOR_DIR $PROJECT_ROOT/bin_verilator
    VERILATOR_PATH="$PROJECT_ROOT/bin_verilator/bin"
    if [[ ":$PATH:" != *":$VERILATOR_PATH:"* ]]; then
        export PATH="$VERILATOR_PATH:$PATH"
    fi
    export VERILATOR_ROOT=$PROJECT_ROOT/bin_verilator/
fi
export VERILATOR_VERSION=$(verilator --version 2>/dev/null | head -n 1)
printf "%-40s%s\n" "verilator Version (\$VERILATOR_VERSION):" "$VERILATOR_VERSION"

VIVADO_PATH="/opt/Xilinx/Vivado/2022.1/bin"
if [[ ":$PATH:" != *":$VIVADO_PATH:"* ]]; then
    export PATH="$VIVADO_PATH:$PATH"
fi
export VIVADO_VERSION=$(vivado -version 2>/dev/null | head -n 1)
printf "%-40s%s\n" "Vivado Version (\$VIVADO_VERSION):" "$VIVADO_VERSION"

printf "\n================ Computer Architecture Course Environment Done =================\n"

