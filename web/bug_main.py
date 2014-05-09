from flask import Flask, render_template, url_for, request
app = Flask(__name__)

#@app.route('/', methods=['POST', 'GET'])
#def index():
#    if request.method == 'POST':
#        print "posting method used"
#    elif request.method == 'GET':
#        print "get method used"
#    
#    return render_template('bug_control.html')

@app.route('/', methods=['POST', 'GET'])
@app.route('/<data>', methods=['POST', 'GET'])
def boom(data=0):
    if request.method == 'POST':
        if "boom" in request.form:
            print "The boom is", request.form["boom"]
        
        if "bug" in request.form:
            print "The bug is", request.form["bug"]
        print "post method used: ", request.form
    elif request.method == 'GET':
        print "get method used: ", data
    
    return render_template('bug_control.html')

if __name__ == "__main__":
    app.debug = True
    app.run(host='0.0.0.0', port=80)

def write_file(filename, data):
    f = open(str(filename), "w")
    f.write(str(data))
    f.close()
