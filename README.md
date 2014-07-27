Bug-Dropper
===========
This is a script for controlling an Intel Galileo to move a spider up and down on a winch.

Installing and running
=======
1. The only dependency needed by this is Flask. If you have pip then run ```pip install flask```. On the Intel Galileo pip is not available so you need to download Flask and its dependency setuptools from http://flask.pocoo.org/ and https://pypi.python.org/pypi/setuptools respectively.
2. Download or clone this repo. If you are running this on a Galileo then you need to download the files on a seperate computer and copy them over using scp or something else.
3. If you are running this on the Galileo then copy the Arduino sketch folder https://github.com/docprofsky/Bug-Dropper/tree/master/arduino (inside the arduino folder) from this repo to your sketchbook directory. Change the paths in the getBug() and getBoom() function to where you copied the repo to on the Gaileo.
4. To start the webserver run ```python web/bug_main.py``` as root from the main directory of the repo. On the Galileo the default user is root so  ```sudo``` is no needed.
5. Upload the sketch to the Galileo if you are using it. This only needs to be done once, as the Galileo will save the sketch across reboots. The first time you run this the web server should be started before the sketch is uploaded so it does not try to read a nonexistent file.

License
=======
This project uses the MIT License

The MIT License (MIT)

Copyright (c) 2014 Schuyler St. Leger

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
