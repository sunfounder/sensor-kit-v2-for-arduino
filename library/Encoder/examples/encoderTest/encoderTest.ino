#include "encoder.h"

ENCODER encoder;

void setup()
{
  encoder.Init(2, 3, 4);
  Serial.begin(9600);
}

void loop()
{
  static int num = 0;
  int change = encoder.turnSettle();
  num = num + change;
  if(encoder.pressed())
  {
    num = 0;
  }
  Serial.println(num);
}
