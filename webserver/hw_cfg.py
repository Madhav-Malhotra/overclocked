from dataclasses import dataclass
from enum import Enum

from pynq import MMIO, Overlay

GPIO_RANGE = 0x10000
OFFSET = 0x0


@dataclass(frozen=True)
class SignalConfig:
    field_name: str
    base_address: int


class OutputSignal(Enum):
    # RO outputs
    # should have 1 output signal for each field of the Outputs model
    # PC = SignalConfig("pc", 0x4120_0000)
    FD_PC = SignalConfig("fd_pc", 0x413C0000)
    FD_PC4 = SignalConfig("fd_pc4", 0x413D0000)
    OPCODE_FD = SignalConfig("opcode_fd", 0x413E0000)
    ADDR_RD_FD = SignalConfig("addr_rd_fd", 0x413F0000)
    OPCODE_DX = SignalConfig("opcode_dx", 0x41400000)
    ADDR_RD_DX = SignalConfig("addr_rd_dx", 0x41410000)
    DX_PC = SignalConfig("dx_pc", 0x41430000)
    DMEM_DATA_IN = SignalConfig("dmem_data_in", 0x41440000)
    OPCODE_XM = SignalConfig("opcode_xm", 0x41450000)
    ADDR_RD_XM = SignalConfig("addr_rd_xm", 0x41460000)
    XM_PC = SignalConfig("xm_pc", 0x41470000)
    WB_IN_ALU = SignalConfig("wb_in_alu", 0x41480000)
    MEM = SignalConfig("mem", 0x41490000)
    MW_PC = SignalConfig("mw_pc", 0x41200000)
    MW_PC4 = SignalConfig("mw_pc4", 0x414A0000)
    OPCODE_MW = SignalConfig("opcode_mw", 0x414B0000)
    ADDR_RD_MW = SignalConfig("addr_rd_mw", 0x414C0000)

    def __init__(self, config: SignalConfig):
        self.config = config


class ControlSignal(Enum):
    # inputs
    CLK = SignalConfig("clk", 0x4122_0000)
    RST = SignalConfig("rst", 0x4121_0000)


class Board:
    def __init__(self):
        # Initialize Output MMIO mapping
        self.output_mmios = {
            sig: (MMIO(sig.config.base_address, GPIO_RANGE)) for sig in OutputSignal
        }

        # Initialize Control MMIO mapping
        self.ctrl_mmios = {
            ctrl: MMIO(ctrl.value.base_address, GPIO_RANGE) for ctrl in ControlSignal
        }

    def setup(self):
        # requires a design_1_wrapper.bit and design_1_wrapper.hwh in the same directory
        ol = Overlay("design_1_wrapper.bit")
        print(ol.ip_dict)

    def start(self):
        # RST is initially 1 (from Vivado)
        self.ctrl_mmios[ControlSignal.RST].write(OFFSET, 0x0)

    def tick(self):
        clk = self.ctrl_mmios[ControlSignal.CLK]
        clk.write(OFFSET, 0x1)
        clk.write(OFFSET, 0x0)
