from flask import Flask, render_template, url_for, request
app = Flask(__name__)

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        print "post method used"
    elif request.method == 'GET':
        print "get method used"
    
    return render_template('bug_control.html')

if __name__ == "__main__":
    app.debug = True
    app.run(host='0.0.0.0', port=80)

