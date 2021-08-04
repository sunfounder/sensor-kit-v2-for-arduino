/******************************************************
name:Raindrop Detection
function:drop some water onto the sensor,
When the quantities of the raindrops exceeds the threshold,
the LED on the raindrop sensor module and that hooked up with pin 13 of the SunFounder Uno board light up
*******************************************************/

const int analogPin=A0; //the AO of the module attach to A0
const int digitalPin=7;  //D0 attach to pin7
const int ledPin=13;  //pin 13 built-in led
int Astate=0; //store the value of A0
boolean Dstate=0;  //store the value of D0

void setup() 
{
 pinMode(ledPin,OUTPUT); //set the ledPin as OUTPUT 
 pinMode(digitalPin,INPUT);  //set digitalPin as INPUT
 Serial.begin(9600);  //initialize the serial monitor
}

void loop() 
{
  Astate=analogRead(analogPin);  //read the value of A0
  Serial.print("A0: ");
  Serial.println(Astate);  //print the value in the serial monitor
  Dstate=digitalRead(digitalPin);  //read the value of D0
  Serial.print("D0: ");
  Serial.println(Dstate);
  if(Dstate==HIGH)  
  {
   digitalWrite(ledPin,LOW);
  }
  else //if the value of D0 is LOW
  {
  digitalWrite(ledPin,HIGH); //turn on the led
  }
}
