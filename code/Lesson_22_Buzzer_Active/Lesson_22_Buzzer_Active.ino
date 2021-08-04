/************************************************
 * function:you can hear the active buzzer beeping.
 * But it won't work if you use a passive one here. 
 *************************************************/

int buzzerPin = 7;//the pin of the active buzzer attach to pin7
void setup()
{
  pinMode(buzzerPin,OUTPUT);//set the buzzer as as OUTPUT
  digitalWrite(buzzerPin,LOW);//initialize the buzzerPin as LOW level
}
void loop()
{

} 

