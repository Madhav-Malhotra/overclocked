from typing import List, Optional

from fastapi import FastAPI
from hw_cfg import Board, ControlSignal
from pydantic import BaseModel, Field

""" This file contains the minimal fastAPI server used to set variables in memory shared with the FPGA """
app = FastAPI()

board = Board()
# var naming: snake_case within python variables, but presenting camelCase to API
# using camelCase in the API endpoints as well to keep consistency with the value


class IMem(BaseModel):
    """Schema containing instruction memory content"""

    mem: List[int] = []


class Outputs(BaseModel):
    """Schema containing modules' output signals, comprising the CPU state"""

    # trying to enforce a uint32_t type: ge=0, le=0xFFFFFFFF ensures Pydantic validates the 32-bit range
    pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="Program Counter")
    instruction: int = Field(0, ge=0, le=0xFFFFFFFF, description="Current Instruction")
    regs: List[int] = Field(
        default_factory=lambda: [0] * 32,
        min_items=32,
        max_items=32,
    )
    alu_out: int = Field(0, ge=0, le=0xFFFFFFFF, description="ALU Output")

    br_eq: bool = Field(False)
    br_lt: bool = Field(False)
    branch_comp_data1_sel: bool = Field(False)
    branch_comp_data2_sel: bool = Field(False)
    br_taken: bool = Field(False)
    pc_sel: bool = Field(False)
    br_un: bool = Field(False)
    a_sel: int = Field(
        0, ge=0, le=3, description="Forwarding/Execution Mux A Select [1:0]"
    )
    b_sel: int = Field(
        0, ge=0, le=3, description="Forwarding/Execution Mux B Select [1:0]"
    )
    alu_sel: int = Field(0, ge=0, le=15, description="ALU Operation Select [3:0]")
    mem_rw: bool = Field(False, description="Memory Read/Write Enable")
    reg_wen: bool = Field(False, description="Register File Write Enable")
    wb_sel: int = Field(0, ge=0, le=3, description="Write Back Select [1:0]")

    opcode: int = Field(0, ge=0, le=0x7F, description="Opcode [6:0]")
    addr_rd: int = Field(
        0, ge=0, le=31, description="Destination Register Address [4:0]"
    )
    addr_rs1: int = Field(0, ge=0, le=31, description="Source 1 Register Address [4:0]")
    addr_rs2: int = Field(0, ge=0, le=31, description="Source 2 Register Address [4:0]")
    funct3: int = Field(0, ge=0, le=7, description="Funct3 [2:0]")
    funct7: int = Field(0, ge=0, le=0x7F, description="Funct7 [6:0]")

    imm: int = Field(0, ge=0, le=0xFFFFFFFF, description="Immediate Value")
    # shift amount is [N_BITS-1:0], typically 5 bits)
    shamt: int = Field(0, ge=0, le=0x1F, description="Shift Amount Value (5 bits)")

    is_u_type_w: bool = Field(False)
    is_j_type_w: bool = Field(False)
    is_i_type_w: bool = Field(False)

    dmem_data_out: int = Field(
        0, ge=0, le=0xFFFFFFFF, description="Data Memory Data Out"
    )
    imem_data_out: int = Field(
        0, ge=0, le=0xFFFFFFFF, description="Instruction Memory Data Out"
    )
    data_rs1: int = Field(0, ge=0, le=0xFFFFFFFF, description="RegFile Data A")
    data_rs2: int = Field(0, ge=0, le=0xFFFFFFFF, description="RegFile Data B")
    wb_data: int = Field(0, ge=0, le=0xFFFFFFFF, description="Write Back Data")

    fd_pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="FD Stage PC")
    fd_pc4: int = Field(0, ge=0, le=0xFFFFFFFF, description="FD Stage PC+4")
    opcode_fd: int = Field(0, ge=0, le=0x7F, description="FD Stage Opcode")
    addr_rd_fd: int = Field(0, ge=0, le=31, description="FD Stage Destination Reg")

    opcode_dx: int = Field(0, ge=0, le=0x7F, description="DX Stage Opcode")
    addr_rd_dx: int = Field(0, ge=0, le=31, description="DX Stage Addr")
    dx_pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="DX Stage PC")

    dmem_data_in: int = Field(0, ge=0, le=0xFFFFFFFF, description="Data Memory Data In")
    opcode_xm: int = Field(0, ge=0, le=0x7F, description="XM Stage Opcode")
    addr_rd_xm: int = Field(0, ge=0, le=31, description="XM Stage Addr")
    xm_pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="XM Stage PC")

    wb_in_alu: int = Field(
        0, ge=0, le=0xFFFFFFFF, description="Write Back Input to ALU"
    )
    mem: int = Field(0, ge=0, le=0xFFFFFFFF, description="Data Memory To Write Back")
    mw_pc4: int = Field(
        0, ge=0, le=0xFFFFFFFF, description="Memory/Writeback Stage PC+4"
    )
    opcode_mw: int = Field(0, ge=0, le=0x7F, description="MW Stage Opcode")
    addr_rd_mw: int = Field(0, ge=0, le=31, description="MW Stage Addr")
    mw_pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="MW Stage PC")

    class Config:
        json_schema_extra = {
            "example": {"pc": 0x00004000, "instruction": 0x03E00008, "br_eq": False}
        }


""" in-memory instance of the IMem (instruction memory) contents """
imem = IMem(mem=[])

""" in-memory instance of the Outputs class """
outputs = Outputs(
    # populated with random values to test retrieval
    pc=0x10002000,
    instruction=0x10000000,
    regs=[1] * 32,
    alu_out=10,
    br_eq=True,
    br_lt=False,
    branch_comp_data1_sel=False,
    branch_comp_data2_sel=False,
    br_taken=False,
    pc_sel=False,
    br_un=False,
    a_sel=0x1,
    b_sel=0x2,
    alu_sel=0b1100,
    mem_rw=False,
    reg_wen=False,
    wb_sel=0x2,
    opcode=0x1,
    addr_rd=0x0,
    addr_rs1=0x0,
    addr_rs2=0x0,
    funct3=0x0,
    funct7=0x0,
    imm=0x0,
    # shift amount is [N_BITS-1:0], typically 5 bits)
    shamt=0x0,
    is_u_type_w=False,
    is_j_type_w=False,
    is_i_type_w=False,
    dmem_data_out=0x0,
    imem_data_out=0x0,
    data_rs1=0x0,
    data_rs2=0x0,
    wb_data=0x0,
    fd_pc=0x0,
    fd_pc4=0x4,
    opcode_fd=0x0,
    addr_rd_fd=0x0,
    opcode_dx=0x0,
    addr_rd_dx=0x0,
    dx_pc=0x0,
    dmem_data_in=0x0,
    opcode_xm=0x0,
    addr_rd_xm=0x0,
    xm_pc=0x0,
    mem=0x0,
    mw_pc4=0x0,
    opcode_mw=0x0,
    addr_rd_mw=0x0,
    mw_pc=0x0,
)


@app.get("/")
def read_root():
    """Test Function."""
    return {"Hello": "World"}


@app.get("/tick")
def tick():
    """Tick 1 clock cycle"""
    board.tick()


@app.get("/outputs/status", response_model=Outputs)
def get_state():
    """Return all modules' output signals"""
    # TODO (diana) retrieve outputs from FPGA board
    for signal, mmio in board.output_mmios.items():
        setattr(outputs, signal.value.field_name, mmio.read())
        print(signal.name, hex(mmio.read()))
    return outputs


# @app.post("/imem/update", response_model=IMem)
# def update_imem(payload: IMem):
@app.post("/imem/update", response_model=IMem)
def update_imem():
    """Update imem contents to payload"""
    # payload should contain the name of a level file, for which there is also a .bit and .hwh file copied onto the webserver
    # after calling Overlay(), this should call start(), which disables the tick()
    # right now, hard code this to the design_1_wrapper?
    # imem.mem = payload.mem
    board.setup()
    board.start()
    # print([f"0x{num:08X}" for num in imem.mem]) # debugging
    return imem


if __name__ == "__main__":
    import uvicorn

    # port 8080 matches our Dockerfile and curl command
    uvicorn.run(app, host="0.0.0.0", port=8080)
