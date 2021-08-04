
/**********************************/
const int photoPin = 7; //the number of the key pin
const int ledPin = 13;//the number of the led pin
/**********************************/
void setup()
{
  pinMode(photoPin,INPUT); 
  pinMode(ledPin,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
  
  boolean Value=digitalRead(photoPin);
 
  //if it is,the state is HIGH 
  if(Value ==HIGH )
  {
    digitalWrite(ledPin,LOW);//turn on the led
  }
  else
  {
    digitalWrite(ledPin,HIGH);//turn off the led
  }
}

