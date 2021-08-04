/*****************************************************
 * name:Reed Switch
 * function:use a magnet to approach the reed switch, and the LED on the reed switch module and that on the SunFounder board light up. Move the magnet farther and the LED will go out.
 **************************************************/
// Email: support@sunfounder.com
// website: www.sunfounder.com

const int digitalInPin = 7;// reed switch attach to pin7
const int ledPin = 13;// pin13 built-in led

void setup()
{
  pinMode(digitalInPin,INPUT);// set digitalInPin as INPUT
  pinMode(ledPin,OUTPUT); // set ledPin as OUTPUT
}

void loop()
{
  boolean stat = digitalRead(digitalInPin);//read the value of pin7 to stat
  if(stat == HIGH)// if it it HIGH
  { 
    digitalWrite(ledPin,LOW);// then turn off the led
  }
  else //else
  {
    digitalWrite(ledPin,HIGH); // turn on the led
  } 
}

