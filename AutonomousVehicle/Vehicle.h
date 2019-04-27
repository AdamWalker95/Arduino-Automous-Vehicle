#include <Arduino.h>
#include <Servo.h>
#include "Drive.h"
#include "ultraSonic.h"

class Vehicle
{
  #define delayTime 200
  int distancePosition[18];
  Servo *servo;
  int leftAxis(int pos);
  int rightAxis(int pos);
  int findBestDirection();
  int scanForward(int i);
  void positionSight();

  ultraSonic *scanner;
  Drive *movement;
  public:
  Vehicle(int trigPin, int echoPin, Servo &servo, int* lWheel, int* rWheel);
  ~Vehicle();
  void driveCar(int pos);
  void turnCar(int pos);
};
