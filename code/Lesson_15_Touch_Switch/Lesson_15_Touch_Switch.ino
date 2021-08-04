/***************************************************
name:Touch Switch
function:
************************************************/
//Email:support@sunfounder.com
//Website:www.sunfounder.com


const int SensorPin=7; //touch switch attach to pin7
const int ledPin = 13; //pin13 built-in led
int SensorState=0; //store the value of touch switch
const int ledPin = 1;
void setup()
{
  pinMode(SensorPin,INPUT);//set sensorPin as INPUT
  pinMode(ledPin,OUTPUT); // set ledPin as OUTPUT
  Serial.begin(9600); //initialize the serial monitor
  
}

void loop()
{
  SensorState=digitalRead(SensorPin);//read the value of pin7
  Serial.println( SensorState);//print it in serial monitor
  if(SensorState==HIGH) //if the value is HIGH
  {
    digitalWrite(ledPin,LOW); //turn off the led
  }
  else
  {
    digitalWrite(ledPin,HIGH); //turn on the led
  }
}
