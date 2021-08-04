//Turns on and off a LED ,when pressings button attach to pin7
/**********************************/
const int keyPin = 7; //the number of the key pin
const int ledPin = 13;//the number of the led pin
/**********************************/
void setup()
{
  pinMode(keyPin,INPUT);//initialize the key pin as input 
  pinMode(ledPin,OUTPUT);//initialize the led pin as output
}
/**********************************/
void loop()
{
  
  boolean Value=digitalRead(keyPin);//read the state of the key value
  //and check if the kye is pressed
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
/************************************/
