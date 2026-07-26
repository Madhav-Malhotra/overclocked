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
    PC = SignalConfig("pc", 0x4120_0000)

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
