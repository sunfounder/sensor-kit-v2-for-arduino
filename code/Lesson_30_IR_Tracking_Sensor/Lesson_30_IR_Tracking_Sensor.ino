/*******************************************
name:IR Tracking Sensor
function:draw two black bold lines on the paper.
If the rays emitted by the sensor encounter the black lines, 
the LED attached to pin 13 on the SunFounder Uno board will light up;
otherwise, it is off.
*****************************************/

const int trackingPin = 7; //the tracking module attach to pin 7
const int ledPin = 13; //pin13 built-in led

void setup()
{
  pinMode(trackingPin, INPUT); // set trackingPin as INPUT
  pinMode(ledPin, OUTPUT);  //set ledPin as OUTPUT
}

void loop()
{
  boolean val = digitalRead(trackingPin); // read the value of tracking module
  if(val == HIGH) //if it is HiGH
  { 
    digitalWrite(ledPin, LOW); //turn off the led
  }
  else
  {
    digitalWrite(ledPin, HIGH); //turn on the led
  }
}
