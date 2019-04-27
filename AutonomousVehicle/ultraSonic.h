#include <Arduino.h>

class ultraSonic
{
  int echo, trig;
  public:
  ultraSonic(int echoPin, int trigPin);
  int scan();
};
