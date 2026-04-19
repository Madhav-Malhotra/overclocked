from flask import Flask, request, jsonify


app = Flask(__name__)

control1 = False
# initialize fake register file contents 
# and imem and dmem!
# don't forget docstrings ! 
controls = {
        "fetchEn": False, 
        "fdEn": False,
        "dxEn": False,
        "xmEn": False,
        "mwEn": False,
}


@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"


@app.route("/controls", methods = ['GET', 'POST'])
def get_controls(): 
    if request.method == 'POST':
        """  
            specify which key of controls and the value
            returns 
        """
        data = request.json
        for key, value in data.items():
            if key in controls:
                controls[key] = value
            else: 
                errMsg = f"{key} not in control signals object"
                return jsonify({"status": "failed", "error": errMsg})
        return jsonify({"status": "updated", "controls": controls}), 200

    return jsonify(controls)


