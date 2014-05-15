#include <Wire.h>
#include <Servo.h>

const int up = 2;
const int halt = 0;
const int down = 1;

const int bugUp = 70;
const int bugDown = 110;
const int bugHalt = 90;

const int boomCenter = 90;

Servo boomServo;
Servo bugServo;

int bugPosition = 0;
int boomPosition = 90;

void setup() {
  // put your setup code here, to run once:
  bugServo.attach(9);
  bugServo.write(bugHalt);

  boomServo.attach(10);
  boomServo.write(boomCenter);

//  Serial.begin(115200);
}

void loop() {
  delay(200);
  bugPosition = getBug();
//  Serial.print("The bug is: ");
//  Serial.println(bugPosition);

  switch(bugPosition) {
  case up:
    bugServo.write(bugUp);
    break;

  case down:
    bugServo.write(bugDown);
    break;

  case halt:
    bugServo.write(bugHalt);
    break;

  default:
    Serial.println("Error reading bug position.");
    bugServo.write(90);
  }

  boomPosition = getBoom() * 10;
  if(boomPosition == 0)
    boomPosition += 1;
//  Serial.print("The boom is: ");
//  Serial.println(boomPosition);
  boomServo.write(boomPosition);
}

int getBug() {
  char output[5];
  FILE *fp; 
  fp = fopen("/home/root/Bug-Dropper/bug-position.txt", "r");
  if (fp == NULL) {
    Serial.println("Error opening bug file.");
    return -1;
  }
  else { 
    fgets(output, sizeof(output), fp);
  }
  if (fclose(fp) != 0) {
    Serial.println("Error closing the bug file.");
    return -1;
  }
  return atoi(output);
}

int getBoom() {
  char output[5];
  FILE *fp; 
  fp = fopen("/home/root/Bug-Dropper/boom-position.txt", "r");
  if (fp == NULL) {
    Serial.println("Error opening bug file.");
    return -1;
  }
  else { 
    fgets(output, sizeof(output), fp);
  }
  if (fclose(fp) != 0) {
    Serial.println("Error closing the bug file.");
    return -1;
  }
  return atoi(output);
}





