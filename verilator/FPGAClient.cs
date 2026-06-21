using System; 
using System.Collections.Generic; 
using System.Net.Http;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

// TODO docstrings
public class FPGAClient : IDisposable, ICPU
{
    public CPUState state { get; private set; }
    private bool disposed = false;
    private static HttpClient client = new()
    { // define 1 HttpClient to reuse over multiple requests
        BaseAddress = new Uri("http://localhost:8080"),
    };
    // docstring: each API request that has to be made to implement a function in the interface, add here as a switch 
    // @return A JSON string containing the webserver's API repsonse
    private string makeRequest(string endpoint, string json = "") {
        HttpRequestMessage req;
        HttpResponseMessage res = new HttpResponseMessage();
        try 
        {
            switch (endpoint) 
            {
                // GET endpoints
                case "/controls/status":
                case "/outputs/status":
                    req = new HttpRequestMessage(HttpMethod.Get, endpoint);
                    res = client.Send(req);
                    break;
                    // POST endpoints
                case "/imem/update":
                case "/controls/update":
                case "/controls/fetchEn/update":
                case "/controls/fdEn/update":
                case "/controls/dxEn/update":
                case "/controls/xmEn/update":
                case "/controls/mwEn/update":
                    req = new HttpRequestMessage(HttpMethod.Post, endpoint);
                    req.Content = new StringContent(json, Encoding.UTF8, "application/json");
                    res = client.Send(req);
                    break;
                default: 
                    Console.WriteLine($"unsupported endpoint: {endpoint}");
                    break;
            }
            res.EnsureSuccessStatusCode();
        } 
        catch (Exception ex) 
        {
            Console.WriteLine($"API Error on {endpoint}: {ex.Message}");
            return string.Empty;
        }
        return res.Content.ReadAsStringAsync().Result;
    }


    /*
     * Tick - Advances the clock.
     *
     * TODO (diana) We want to synchronize the hardware clock with the in-game clock.
     * This can be achieved by combining a game-clock with the hardware clk signal, but requires changes to verilog.
     * Stub function added here as a placeholder to satisfy the ICPU interface.
     */
    public void Tick()
    {
        Console.WriteLine("NOT IMPLEMENTED");
        return;
    }

    /*
     * writeIMem - Load a hex-encoded program file into instruction memory.
     * 
     * Reads each line of the file at `path`, strips comments and optional "0x"
     * prefixes, parses the remaining text as a 32-bit hex instruction.
     * Calls the /imem/update endpoint with the list of 32-bit hex instructions as JSON content.
     * Blank lines and comment-only lines are skipped.
     *
     * @param path  Path to the hex file (one instruction word per line).
     */
    public void writeIMem(string path) 
    {
        List<uint> instructions  = new List<uint>();
        try
        {
            string[] lines = File.ReadAllLines(path);
            foreach (string line in lines) 
            {
                string cleanLine = line.Split("//")[0].Trim(); 
                if (string.IsNullOrEmpty(cleanLine)) continue;
                if (cleanLine.StartsWith("0x")) cleanLine = cleanLine.Substring(2); // cut off 0x
                // Parse hex string to 32-bit uint
                uint instruction = uint.Parse(cleanLine, System.Globalization.NumberStyles.HexNumber);
                instructions.Add(instruction);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error loading hex file: {ex.Message}");

        }
        Dictionary<string, List<uint>> args = new() { ["mem"] = instructions };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/imem/update", argsJson);
        return;
    }

    /*
     * PrintState — Print a human-readable summary of key CPU signals to stdout.
     *
     * Calls GetState() internally to refresh state.
     */
    public void PrintState() 
    {
        GetState();
        Console.WriteLine(this.state);
        return;
    }

    /*
     * GetState — Return a full snapshot of CPU signals in CPUState.
     *
     * Makes /outputs/status request to refresh and returns the raw CPUState struct.
     * Prefer the typed stage helpers (GetFetch, GetFd, …) when only one
     * pipeline stage's signals are needed.
     *
     * @return  A CPUState struct populated with the current simulation state.
     */
    public CPUState GetState() 
    {
        string res = makeRequest("/outputs/status");
        var opts = new JsonSerializerOptions 
        { 
            PropertyNameCaseInsensitive = true,
            IncludeFields = true
        };
        opts.Converters.Add(new JsonBooleanToByteConverter());
        this.state = JsonSerializer.Deserialize<CPUState>(res, opts);
        return this.state;
    }

    /*
     * GetPC — Return the current program counter value.
     *
     * @return  The pc field from the refreshed CPUState.
     */
    public uint GetPC() 
    {
        return GetState().pc;
    }

    /*
     * GetInstruction — Return the instruction word currently in the Fetch/Decode register.
     *
     * @return  The instruction field from the refreshed CPUState.
     */
    public uint GetInstruction() 
    {
        return GetState().instruction;
    }

    /*
     * GetALUOut — Return the ALU result register value (alu_xm_r).
     *
     * @return  The alu_out field from the refreshed CPUState.
     */
    public uint GetALUOut()
    {
        return GetState().alu_out;
    }


    /*
     * SetFetchEn — Enable/disable the Fetch stage and advance the clock.
     *
     * Make a request to /controls/fetchEn/update with the desired enable value.
     * This function call should typically be followed by a GetFetch() to 
     * retrieve the outputs of the Fetch stage.
     * Each SetFetchEn(true) must have a corresponding SetFetchEn(false).
     *
     * @param val  true to enable the Fetch stage; false to stall it.
     */
    public void SetFetchEn(bool val) 
    {
        Dictionary<string, bool> args = new () { ["en"] = val };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/controls/fetchEn/update", argsJson);
        return;
    }

    /*
     * GetFetch — Return a typed snapshot of the Fetch stage outputs.
     *
     * @return  A Fetch record containing the current PC.
     */
    public Fetch GetFetch() 
    {
        return new Fetch {
            pc = this.state.pc,
        };
    }

    /*
     * SetFdEn — Enable/disable the Fetch→Decode pipeline register and advance the clock.
     *
     * Make a request to /controls/fdEn/update with the desired enable value.
     * This function call should typically be followed by a GetFd() to 
     * retrieve the outputs of the Fetch-Decode stage.
     * Each SetFdEn(true) must have a corresponding SetFdEn(false).
     *
     * @param val  true to enable the FD register; false to stall it.
     */
    public void SetFdEn(bool val) 
    {
        Dictionary<string, bool> args = new () { ["en"] = val };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/controls/fdEn/update", argsJson);
        return;
    }

    /*
     * GetFd — Return a typed snapshot of the Fetch→Decode register contents.
     *
     * @return  An Fd record containing fd_pc, fd_pc4, and the instruction word.
     */
    public Fd GetFd() 
    {
        return new Fd {
            fd_pc = this.state.pc,// FIXME (diana) is this missing a separate fd-stage pc?
            fd_pc4 = this.state.pc4,
            instruction = this.state.instruction,
        };
    }

    /*
     * SetDxEn — Enable/disable the Decode→Execute pipeline register and advance the clock.
     *
     * Make a request to /controls/dxEn/update with the desired enable value.
     * This function call should typically be followed by a GetDx() to 
     * retrieve the outputs of the Decode-Execute stage.
     * Each SetDxEn(true) must have a corresponding SetDxEn(false).
     *
     * @param val  true to enable the DX register; false to stall it.
     */
    public void SetDxEn(bool val) 
    {
        Dictionary<string, bool> args = new () { ["en"] = val };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/controls/dxEn/update", argsJson);
        return;
    }

    /*
     * GetDx — Return a typed snapshot of the Decode→Execute register contents.
     *
     * @return  A Dx record containing the source register addresses (addr_rs1, addr_rs2).
     */
    public Dx GetDx() 
    {
        getControls();
        return new Dx {
            addr_rs1 = this.state.addr_rs1,
            addr_rs2 = this.state.addr_rs2,
        };
    }

    /*
     * SetXmEn — Enable/disable the Execute→Memory pipeline register and advance the clock.
     *
     *
     * Make a request to /controls/xmEn/update with the desired enable value.
     * This function call should typically be followed by a GetXm() to 
     * retrieve the outputs of the Execute-Memory stage.
     * Each SetXmEn(true) must have a corresponding SetXmEn(false).
     *
     * @param val  true to enable the XM register; false to stall it.
     */
    public void SetXmEn(bool val) 
    {
        Dictionary<string, bool> args = new () { ["en"] = val };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/controls/xmEn/update", argsJson);
        return;
    }

    /*
     * GetXm — Return a typed snapshot of the Execute→Memory register contents.
     *
     * @return  An Xm record containing alu_out and the data memory write value (dmem_data_in).
     */
    public Xm GetXm() 
    {
        return new Xm {
            alu_out = this.state.alu_out,
            dmem_data_in = this.state.dmem_data_in,
        };
    }

    /*
     * SetMwEn — Enable/disable the Memory→Writeback pipeline register and advance the clock.
     *
     *
     * Make a request to /controls/mwEn/update with the desired enable value.
     * This function call should typically be followed by a GetMw() to 
     * retrieve the outputs of the Memory-Writeback stage.
     * Each SetMwEn(true) must have a corresponding SetMwEn(false).
     *
     * @param val  true to enable the MW register; false to stall it.
     */
    public void SetMwEn(bool val) 
     {
        Dictionary<string, bool> args = new () { ["en"] = val };
        string argsJson = JsonSerializer.Serialize(args);
        makeRequest("/controls/mwEn/update", argsJson);
        return;
    }

    /*
     * GetMw — Return a typed snapshot of the Memory→Writeback register contents.
     *
     * @return  An Mw record containing pc4, wb_in_alu, and the memory read value (mem).
     */
    public Mw GetMw() 
     {
        return new Mw {
            pc4 = this.state.pc4, // FIXME (diana) is this missing a separate mw_pc4?
            wb_in_alu = this.state.wb_in_alu,
        };
    }

    /* getControls - private helper debugging function for outputting current control signals. 
     *
     * Only used in this file and added to a Set<stage> function for inspecting control signals.
     *
     */
    private void getControls() {
        string res = makeRequest("/controls/status");
        Console.WriteLine(res);
        return;
    }

    /*
     * FPGAClient - Load a program into instruction memory with an /imem/update API call and initialize CPU state.
     *
     * @param path Path to the hex program file.
     */
    public FPGAClient(string path) {
        this.state = new CPUState();
        writeIMem(path);
        this.state = GetState();
        Console.WriteLine(this.state);
    }

    // Implement IDisposable.
    // Diposable interface from https://learn.microsoft.com/en-us/dotnet/api/system.idisposable?view=net-10.0
    public void Dispose()
    {
        Dispose(disposing: true);
        GC.SuppressFinalize(this);
    }
    protected virtual void Dispose(bool disposing)
    {
        if(!this.disposed)
        {
            disposed = true;
        }
    }
    ~FPGAClient()
    {
        Dispose(disposing: false);
    }

    /* JsonBooleanToByteConverter for conversion because the webserver stores JSON types (bool) but CPUState is explicitly defined in bytes and uint32 for alignment.
     * Without this conversion, we will encounter
     * > The JSON value could not be converted to System.Byte.
     * > Cannot get the value of a token type 'True' as a number.
     */
    private class JsonBooleanToByteConverter : JsonConverter<byte>
    {
        public override byte Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options)
        {
            // If the JSON value is boolean 'true', return 1
            if (reader.TokenType == JsonTokenType.True) return 1;
            // If the JSON value is boolean 'false', return 0
            if (reader.TokenType == JsonTokenType.False) return 0;
            // If it's already a standard number, read it normally
            if (reader.TokenType == JsonTokenType.Number) return reader.GetByte();
            throw new JsonException($"Unexpected token type {reader.TokenType} when converting to byte.");
        }
        public override void Write(Utf8JsonWriter writer, byte value, JsonSerializerOptions options)
        {
            // When sending data back, write it as a normal number
            writer.WriteNumberValue(value);
        }
    }
}


