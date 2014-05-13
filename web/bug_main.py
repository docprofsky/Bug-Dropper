from flask import Flask, render_template, url_for, request
app = Flask(__name__)

#########################
## TODO: Add comments! ##
#########################

BOOM_POITION_FILE = "boom-position.txt"
BUG_POSITION_FILE = "bug-position.txt"
UP = 2
STOP = 0
DOWN = 1

positions = {"bug": STOP, "boom": 9}

def write_file(filename, data):
    f = open(str(filename), "w")
    f.write(str(data))
    f.close()

def parse_data(formData):
    new_positions = dict()
    data_submitted = list()

    if "boom" in formData:
        new_positions["boom"] = formData["boom"]
        data_submitted.append("boom")

    if "bug" in formData:
        if formData["bug"].lower() == "up":
            new_positions["bug"] = UP
            data_submitted.append("bug")
        elif formData["bug"].lower() == "stop":
            new_positions["bug"] = STOP
            data_submitted.append("bug")
        elif formData["bug"].lower() == "down":
            new_positions["bug"] = DOWN
            data_submitted.append("bug")
        else:
            raise RuntimeError("Value for the bug position is not defined.")

    return new_positions, data_submitted

@app.route('/', methods=['POST', 'GET'])
@app.route('/<data>', methods=['POST', 'GET'])
def boom(data=0):
    global positions
    if request.method == 'POST':
        new_position, data_submitted = parse_data(request.form)

        for i in data_submitted:
            if new_position[i] != positions[i]:
                positions[i] = new_position[i]

        print "The boom is", positions["boom"]
        print "The bug is", positions["bug"]
        print "The positions are :", positions

        write_file(BOOM_POITION_FILE, positions["boom"])
        write_file(BUG_POSITION_FILE, positions["bug"])
        
    return render_template('bug_control.html', boom=positions["boom"],
            bug=positions["bug"])

if __name__ == "__main__":
    write_file(BOOM_POITION_FILE, positions["boom"])
    write_file(BUG_POSITION_FILE, positions["bug"])
    app.debug = True
    print "The Bug Dropper Control web app is running!"
    app.run(host='0.0.0.0', port=80)
