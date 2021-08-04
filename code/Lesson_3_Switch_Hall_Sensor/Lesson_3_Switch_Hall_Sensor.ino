// Hall Switch Sensor 
const int hallPin = 8; //the SIG of hall sensor attach to 
const int ledPin = 13; //pin 13 built-in LED light
const int buzzerPin=7;// Passive Buzzer SIG 
int val = 0; //the variable to store the value read from Hall Switch
/********************************/
void setup()
{
  pinMode(hallPin,INPUT); //initialize the hall as an input
  pinMode(ledPin,OUTPUT); //initialize the led as an output
  pinMode(buzzerPin,OUTPUT);// initialize The Passive Buzzer as an output
  Serial.begin(9600);// initialize serial communications at 9600 bps

}
/**********************************/
void loop()
{
  val = digitalRead(hallPin); //read the value from hall Switch
  Serial.println(val);//print the value
  if(val == HIGH)
  {
    digitalWrite(ledPin,LOW);//turn off led
    noTone(7);//if you want to play different pitches on multiple pins, you need to call noTone() on one pin before calling tone() on the next pin.
  }
  if(val == LOW)
  {
    digitalWrite(ledPin,HIGH);//turn on led
    tone(7,320,200);//generate a tone on pin 7 ,with a frequency of 320hz and the duration of the tone is 200 milliseconds
  }
  delay(500);//to get a beeping tone 
}
/*************************************/

