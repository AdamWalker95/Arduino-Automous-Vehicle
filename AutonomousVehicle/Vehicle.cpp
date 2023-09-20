#include "Vehicle.h"
#include <Servo.h>

Vehicle::Vehicle(int trigPin, int echoPin, Servo &servo, int* lWheel, int* rWheel)
{
  this->servo = &servo;

  scanner = new ultraSonic(echoPin, trigPin);
  movement = new Drive(lWheel, rWheel);
}
Vehicle::~Vehicle()
{
  delete scanner;
  delete movement;
}
void Vehicle::driveCar(int pos)
{
  while(scanForward(pos) > 40)
  {
    movement->Forward(distancePosition[pos]);
  }
  movement->Stop();
  delay(delayTime);
  int newDir = findBestDirection();
  movement->Turn(newDir);
}
int Vehicle::scanForward(int i)
{
  distancePosition[i] = scanner->scan();
  return distancePosition[i];
}
int Vehicle::leftAxis(int pos)
{
  //if ultra-sonic sensor records zero, obstacles are so far away they've become unrecorded.
  //in terms of navigation, this is ideal, thus system should stop looking
  for(int  i = 0; i < 9 && distancePosition[pos] > 0; i++)
  {
    servo->write((i*10));
    scanForward(i);
    if(distancePosition[i] == 0)
      pos = i;
    else if(distancePosition[i] > distancePosition[pos])
      pos = i;
    delay(delayTime);
  }
  return pos;
}
int Vehicle::rightAxis(int pos)
{
  //if ultra-sonic sensor records zero, obstacles are so far away they've become unrecorded.
  //in terms of navigation, this is ideal, thus system should stop looking
  for(int  i = 10; i < 18 && distancePosition[pos] > 0; i++)
  {
    servo->write((i*10));
    scanForward(i);
    if(distancePosition[i] == 0)
      pos = i;
    else if(distancePosition[i] > distancePosition[pos])
      pos = i;
    delay(delayTime);
  }
  return pos;
}
void Vehicle::positionSight()
{
  servo->write(90);
  delay(delayTime);
}
int Vehicle::findBestDirection()
{
  int pos = 0;
  pos = leftAxis(pos);
  pos = rightAxis(pos);
  positionSight();
  return pos;
}
