#include "retrieval.h"

const int laserPin = 7; //laser attach to 

static int dotDelay = 200; //

void setup()
{
  pinMode(laserPin, OUTPUT);  //initialize laser as an output
  Serial.begin(9600);  
}

void loop()
{
  char ch = 0; //store the  character or digit read from the serial monitor
  if(Serial.available() > 0) //is there anything to be read
  {
    ch = Serial.read(); //read a single letter from serial monitor
  }
  morseSignal(ch); //flashes depend on the letter 
}
//
void flashDot(char cha)
{
  digitalWrite(laserPin, HIGH); //turn the laser on
  if(cha == '.') //
  {
    delay(dotDelay);
  }
  else
  {
    delay(dotDelay * 3);  //gap between letters
  }
  digitalWrite(laserPin, LOW);
  delay(dotDelay);  //gap between flashes
}
//
void flashSequence(char *sequence)
{
  int i = 0;
  while(sequence[i] != NULL)
  {
    flashDot(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}
//
void morseSignal(char ch)
{
  if(ch >= 'a' && ch <= 'z')  
  {
    flashSequence(letters[ch - 'a']);
  }
  else if(ch >= 'A' && ch <= 'Z')
  {
    flashSequence(letters[ch - 'A']);
  }
  else if(ch >= '0' && ch <= '9')
  {
    flashSequence(numbers[ch - '0']);
  }
  else if(ch == ' ')
  {
    delay(dotDelay * 4);  //gap between words
  }
}


