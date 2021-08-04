const int analogPin = A0;//the analog input pin attach to
const int ledPin =13;//the led attach to
int inputValue = 0;//variable to store the value coming from sensor
/******************************************/
void setup()
{
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}
/******************************************/
void loop()
{
  inputValue = analogRead(analogPin);//read the value from the sensor
  //Serial.println(inputValue);
  digitalWrite(ledPin,HIGH);
  delay(inputValue);
  digitalWrite(ledPin,LOW);
  delay(inputValue);
}
/*******************************************/
