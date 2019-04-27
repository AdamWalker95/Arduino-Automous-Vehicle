#include "ultraSonic.h"

ultraSonic::ultraSonic(int echoPin, int trigPin)
{
  echo = echoPin;
  trig = trigPin;

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
int ultraSonic::scan()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  delay(100);
  return (duration * 0.034/2);
}
