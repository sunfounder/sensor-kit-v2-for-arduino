/*****************************************************
 * name:Photoswitch
 * function: hold the photoresistor with your fingers and check the value at A0 on Serial Monitor. 
 * You can see when the resistance is up to 400ohm,
 * the normally open contact of the relay is closed and the LED connected to pin 13 on the SunFounder Uno board lights up;
 * or else, it keeps out.
 ************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

const int photocellPin = A0; //photoresistor module attach to A0
const int ledPin = 13; //pin 13 built-in led
const int relayPin=8; //relay module attach to digital 8
int outputValue = 0;
/*************************************************/
void setup()
{
  pinMode(relayPin,OUTPUT); //set relayPin as OUTPUT
  pinMode(ledPin,OUTPUT); //set ledPin as OUTPUT
  Serial.begin(9600); //initialize the serial communication as 9600bps
}
/*************************************************/
void loop()
{
  outputValue = analogRead(photocellPin);//read the value of photoresistor
  Serial.println(outputValue); //print it in serial monitor
  if(outputValue >= 400) //if the value of photoreisitor is greater than 400
  {
    digitalWrite(ledPin,HIGH); //turn on the led 
    digitalWrite(relayPin,LOW); //relay connected
  }
  else //else
  {
    digitalWrite(ledPin,LOW); //turn off the led
    digitalWrite(relayPin,HIGH); //and relay disconnected
  }
  delay(1000); //delay 1s
}
/*************************************************/

