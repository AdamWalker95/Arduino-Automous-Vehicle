#include "Vehicle.h"
#include <Servo.h>

const int Trig = 13;
const int Echo = 12;
const int servoPin = 2;

//Left wheel pins
const int en1 = 0;
const int input1 = 10;
const int input2 = 11;

//Right wheel pins
const int en2 = 1;
const int input3 = 5;
const int input4 = 4;

const int LWheel[] = {en1, input1, input2};
const int RWheel[] = {en2, input3, input4};

Servo servo;

Vehicle car(Trig, Echo, servo, LWheel, RWheel);

void setup() {
  Serial.begin(115200);
  servo.attach(servoPin);
}

void loop() {
  car.driveCar(9);
  delay(2000);
}
