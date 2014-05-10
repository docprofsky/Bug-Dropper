from flask import Flask, render_template, url_for, request
app = Flask(__name__)

#########################
## TODO: Add comments! ##
#########################

BOOM_POITION_FILE = "boom-position.txt"
BUG_POSITION_FILE = "bug-position.txt"
UP = 1
STOP = 0
DOWN = -1

def write_file(filename, data):
    f = open(str(filename), "w")
    f.write(str(data))
    f.close()

def parse_data(formData):
    positions = dict()
    if "boom" in formData:
            if formData["boom"].lower() == "up":
                positions["boom"] = UP
            elif formData["boom"].lower() == "stop":
                positions["boom"] = STOP
        
    if "bug" in formData:
        if formData["bug"].lower() == "up":
            positions["bug"] = UP
        elif formData["bug"].lower() == "stop":
            positions["bug"] = STOP
        elif formData["bug"].lower() == "down":
            positions["bug"] = DOWN

    return positions

@app.route('/', methods=['POST', 'GET'])
@app.route('/<data>', methods=['POST', 'GET'])
def boom(data=0):
    if request.method == 'POST':
        if "boom" in request.form:
            print "The boom is", request.form["boom"]
        
        if "bug" in request.form:
            print "The bug is", request.form["bug"]

        print parse_data(request.form)
    
    return render_template('bug_control.html')

if __name__ == "__main__":
    app.debug = True
    app.run(host='0.0.0.0', port=80)
