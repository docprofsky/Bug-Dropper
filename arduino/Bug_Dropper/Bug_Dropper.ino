#include <Servo.h>

const int up = 2;
const int halt = 0;
const int down = 1;
const int hold = 3;

const int bugUp = 70;
const int bugDown = 110;
const int bugHalt = 90;

const int boomCenter = 90;

const int bugServoPin = 9;
const int boomServoPin = 10;

Servo boomServo;
Servo bugServo;

int bugPosition = 0;
int boomPosition = 90;

void setup() {
  bugServo.attach(bugServoPin);
  bugServo.write(bugHalt);

  boomServo.attach(boomServoPin);
  boomServo.write(boomCenter);

  Serial.begin(115200);
}

void loop() {
  delay(200);
  bugPosition = getBug();
  Serial.print("The bug is: ");
  Serial.println(bugPosition);

  switch(bugPosition) {
  case up:
    Serial.println("Executing bug up");
    if(bugServo.attached() == false) {
      Serial.println("Reattaching the bug servo");
      bugServo.attach(bugServoPin);
    }
    bugServo.write(bugUp);
    break;

  case down:
      Serial.println("Executing bug down");
    if(bugServo.attached() == false) {
      Serial.println("Reattaching the bug servo");
      bugServo.attach(bugServoPin);
    }
    bugServo.write(bugDown);
    break;

  case halt:
    Serial.println("Executing bug halt");
    if(bugServo.attached() == false) {
      Serial.println("Bug servo already detached, nothing to do");
      break;
    }
    Serial.println("Bug servo will be detached");
    bugServo.write(bugHalt);
    bugServo.detach();
    break;
    
  case hold:
    Serial.println("Executing bug hold");
    if(!bugServo.attached() == false) {
      Serial.println("Reattaching the bug servo");
      bugServo.attach(bugServoPin);
    }
    bugServo.write(bugHalt);
    break;
    
//  default:
//    Serial.println("Error reading bug position.");
  }

  boomPosition = getBoom() * 10;
  
//  if(boomPosition == 0)
//    boomPosition += 1;
//  Serial.print("The boom is: ");
//  Serial.println(boomPosition);
  boomServo.write(boomPosition);
}

int getBug() {
  char output[5];
  FILE *fp; 
  fp = fopen("/home/root/Bug-Dropper/bug-position.txt", "r");
  if (fp == NULL) {
//    Serial.println("Error opening bug file.");
    return -1;
  }
  else { 
    fgets(output, sizeof(output), fp);
  }
  if (fclose(fp) != 0) {
//    Serial.println("Error closing the bug file.");
    return -1;
  }
  return atoi(output);
}

int getBoom() {
  char output[5];
  FILE *fp; 
  fp = fopen("/home/root/Bug-Dropper/boom-position.txt", "r");
  if (fp == NULL) {
//    Serial.println("Error opening bug file.");
    return -1;
  }
  else { 
    fgets(output, sizeof(output), fp);
  }
  if (fclose(fp) != 0) {
//    Serial.println("Error closing the bug file.");
    return -1;
  }
  return atoi(output);
}





