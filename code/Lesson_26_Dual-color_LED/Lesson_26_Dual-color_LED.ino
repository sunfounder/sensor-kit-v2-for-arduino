/***************************************************
name:Dual-color LED 
function:you can see the dual-color LED changes from red to green alternately,
as well as flashing a mixed color during the alternation.
connection:
Dual-color LED     Uno R3
R                  11
GND                GND
G                  10
****************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

int redPin = 11;    // select the pin for the red LED
int greenPin = 10;    // select the pin for the blueLED
int val = 0;    

void setup() 
{
  pinMode(redPin, OUTPUT); //set redPin as OUTPUT
  pinMode(greenPin, OUTPUT);//set greenPin as OUTPUT
  Serial.begin(9600); 
}
/******************************************************/
void loop() 
{
  for(val=255; val>0; val--) //
  {
   analogWrite(redPin, val); //red value decrease
   analogWrite(greenPin, 255-val);//green value increase
   Serial.println(val, DEC);//print the val on in serial monitor
   delay(30); //delay 30ms
  }
for(val=0; val<255; val++)
  {
   analogWrite(redPin, val); //red value increase
   analogWrite(greenPin, 255-val);//green value decrease
   Serial.println(val, DEC);//print the val on in serial monitor
   delay(30); //delay 30ms
  }
}
/********************************************************/
