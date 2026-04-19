from fastapi import FastAPI
from typing import Annotated, Optional
from pydantic import BaseModel, Field

""" This file contains the minimal fastAPI server used to set variables in memory shared with the FPGA """
app = FastAPI()

# var naming: snake_case within python variables, but presenting camelCase to API
# using camelCase in the API endpoints as well to keep consistency with the value

class ControlSignals(BaseModel):
    """ Schema containing all pipline register control signals """
    fetch_en: Optional[bool] = None
    fd_en: Optional[bool] = None
    dx_en: Optional[bool] = None
    xm_en: Optional[bool] = None
    mw_en: Optional[bool] = None

class ToggleUpdate(BaseModel):
    en: bool

class Outputs(BaseModel):
    """ Schema containing modules' output signals, comprising the CPU state """
    # trying to enforce a uint32_t type: ge=0, le=0xFFFFFFFF ensures Pydantic validates the 32-bit range
    pc: int = Field(0, ge=0, le=0xFFFFFFFF, description="Program Counter")
    instruction: int = Field(0, ge=0, le=0xFFFFFFFF, description="Current Instruction")
    br_eq: bool # = Field(description="Branch Equal value")
    br_lt: bool
    branch_comp_data1_sel: bool
    branch_comp_data2_sel: bool 
    br_taken: bool             
    pc_sel: bool              
    br_un: bool              
    a_sel: bool             
    b_sel: bool            
    alu_sel: bool         
    mem_rw: bool         
    reg_wen: bool       
    wb_sel: bool       
    opcode: bool
    addr_rd: bool
    addr_rs1: bool
    addr_rs2: bool
    funct3: bool
    funct7: bool
    imm: int = Field(0, ge=0, le=0xFFFFFFFF, description="Immediate Value")
    # shift amount is [N_BITS-1:0], typically 5 bits)
    shamt: int = Field(0, ge=0, le=0b11111, description="Shift Amount Value")
    is_u_type_w: bool
    is_j_type_w: bool
    is_i_type_w: bool
    dmem_data_out: int = Field(0, ge=0, le=0xFFFFFFFF, description="Data Memory Data Out")
    imem_data_out: int = Field(0, ge=0, le=0xFFFFFFFF, description="Instruction Memory Data Out")
    data_rs1: int = Field(0, ge=0, le=0xFFFFFFFF, description="RegFile Data A")
    data_rs2: int = Field(0, ge=0, le=0xFFFFFFFF, description="RegFile Data B")
    wb_data: int = Field(0, ge=0, le=0xFFFFFFFF, description="Write Back Data")
    dmem_data_in: int = Field(0, ge=0, le=0xFFFFFFFF, description="Data Memory Data In")
    wb_in_alu: int = Field(0, ge=0, le=0xFFFFFFFF, description="Write Back Input to ALU")
    mem: int = Field(0, ge=0, le=0xFFFFFFFF, description="Data Memory To Write Back Module")
    pc4: int = Field(0, ge=0, le=0xFFFFFFFF, description="Program Counter + 4")

    
    class Config:
        json_schema_extra = {
            "example": {
                "pc": 0x00004000,
                "instruction": 0x03E00008,
                "br_eq": False
            }
        }


""" in-memory instance of the ControlSignals class """
control_signals = ControlSignals(
    fetch_en=False,
    fd_en=False,
    dx_en=False,
    xm_en=False,
    mw_en=False
)

""" in-memory instance of the Outputs class """
outputs = Outputs(
    # populated with random values to test retrieval
    pc=0x10002000,
    instruction=0x10000000,
    br_eq=True,
    br_lt=False,
    branch_comp_data1_sel=False,
    branch_comp_data2_sel=False, 
    br_taken=False,             
    pc_sel=False,              
    br_un=False,              
    a_sel=False,             
    b_sel=False,            
    alu_sel=False,         
    mem_rw=False,         
    reg_wen=False,       
    wb_sel=False,       
    opcode=False,
    addr_rd=False,
    addr_rs1=False,
    addr_rs2=False,
    funct3=False,
    funct7=False,
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
    dmem_data_in=0x0,
    wb_in_alu=0x0,
    mem=0x0,
    pc4=0x0
)

@app.get("/")
def read_root():
    """ Test Function. """
    return {"Hello": "World"}


@app.get("/controls/status", response_model=ControlSignals)
def get_status():
    """ Return all control signals """
    return control_signals


@app.get("/outputs/status", response_model=Outputs) 
def get_state(): 
    """ Return all modules' output signals """
    return outputs

@app.post("/controls/update", response_model=ControlSignals)
def update_data(payload: ControlSignals):
    """ Update multiple control signals """
    data = payload.dict()
    for key, value in data.items():
        if key in control_signals:
            control_signals.update({key: value})
        else: 
            errMsg = f"{key} not in control signals object"
            print(errMsg)
            # TODO error message should be included in the model if we want to return one
            # return jsonify({"status": "failed", "error": errMsg})
    return control_signals


@app.post("/controls/fetchEn/update", response_model=ControlSignals)
def update_data(payload: ToggleUpdate):
    """ Update fetchEn control signal """
    print(control_signals)
    control_signals.fetch_en = payload.en
    return control_signals


@app.post("/controls/fdEn/update", response_model=ControlSignals)
def update_data(payload: ToggleUpdate):
    """ Update fdEn control signal """
    print(control_signals)
    control_signals.fd_en = payload.en
    return control_signals


@app.post("/controls/dxEn/update", response_model=ControlSignals)
def update_data(payload: ToggleUpdate):
    """ Update dxEn control signal """
    print(control_signals)
    control_signals.dx_en = payload.en
    return control_signals

@app.post("/controls/xmEn/update", response_model=ControlSignals)
def update_data(payload: ToggleUpdate):
    """ Update xmEn control signal """
    print(control_signals)
    control_signals.xm_en = payload.en
    return control_signals

@app.post("/controls/mwEn/update", response_model=ControlSignals)
def update_data(payload: ToggleUpdate):
    """ Update mwEn control signal """
    print(control_signals)
    control_signals.mw_en = payload.en
    return control_signals

if __name__ == "__main__":
    import uvicorn
    # port 8080 matches our Dockerfile and curl command
    uvicorn.run(app, host="0.0.0.0", port=8080)
