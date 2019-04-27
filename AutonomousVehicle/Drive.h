#include <Arduino.h>

class Drive
{
  int LeftWheel[3], RightWheel[3];
  void TurnLeft(int pos);
  void TurnRight(int pos);
  public:
  Drive(int *lWheel, int *rWheel);
  void Stop();
  void Forward(int distance);
  void Reverse(int distance);
  void Turn(int pos);
};
