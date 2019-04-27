#include "Drive.h"

Drive::Drive(int *lWheel, int *rWheel)
{
  LeftWheel[0] = lWheel[0];
  LeftWheel[1] = lWheel[1];
  LeftWheel[2] = lWheel[2]; 
  RightWheel[0] = rWheel[0];
  RightWheel[1] = rWheel[1];
  RightWheel[2] = rWheel[2];

  for(int i = 1; i <=2; i++)
  {
    pinMode(LeftWheel[i], OUTPUT);
    pinMode(RightWheel[i], OUTPUT);
  }
  
}
void Drive::Stop()
{
  digitalWrite(LeftWheel[1], LOW);
  digitalWrite(LeftWheel[2], LOW);
  digitalWrite(RightWheel[1], LOW);
  digitalWrite(RightWheel[2], LOW);
}
void Drive::Forward(int distance)
{
  int Speed = map(distance, 0, 50, 0, 255);
  analogWrite(LeftWheel[0], Speed);
  analogWrite(RightWheel[0], Speed);

  digitalWrite(LeftWheel[1], HIGH);
  digitalWrite(RightWheel[1], HIGH);
}
void Drive::Reverse(int distance)
{  
  int Speed = map(distance, 0, 100, 255, 0);
  analogWrite(LeftWheel[0], Speed);
  analogWrite(RightWheel[0], Speed);
  
  digitalWrite(LeftWheel[2], HIGH);
  digitalWrite(RightWheel[2], HIGH); 
}
void Drive::Turn(int pos)
{
  if(pos < 9 && pos >= 0)
  {
    TurnLeft(pos);
  }
  else if(pos > 9 && pos <= 18)
  {
    TurnRight(pos);
  }
}
void Drive::TurnLeft(int pos)
{
  int preArc = pos*1500;
  double preAns = preArc/360;
  int arc = 69.12*preAns;
  analogWrite(LeftWheel[0], 255);
  digitalWrite(LeftWheel[1], HIGH);
  delay(arc);
  Stop();
}
void Drive::TurnRight(int pos)
{
  int preArc = (pos-9)*1500;
  double preAns = preArc/360;
  int arc = 69.12*preAns;
  analogWrite(RightWheel[0], 255);
  digitalWrite(RightWheel[1], HIGH);
  delay(arc);
  Stop(); 
}
