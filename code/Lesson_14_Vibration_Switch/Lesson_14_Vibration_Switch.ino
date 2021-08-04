const int vibswPin = 8; //the Vibration Switch attach to 
const int ledPin = 13; //the led attach to
int val = 0; //initialize the variable val as 0
/******************************************/
void setup()
{
  pinMode(vibswPin,INPUT); //initialize vibration switch as an input
  pinMode(ledPin,OUTPUT); //initialize ledPin switch as an output
  //Serial.begin(9600);
}
/*******************************************/
void loop()
{
  val = digitalRead(vibswPin); //read the value from vibration switch
  //Serial.println(val);
  if(val == LOW)  //without vibration signal
  {
    digitalWrite(ledPin,HIGH); //turn off the led
    delay(500);//delay 500ms,The LED will be on for 500ms
  }
  else
  {
    digitalWrite(ledPin,LOW); //turn on the led
  }
}
/*********************************************/

