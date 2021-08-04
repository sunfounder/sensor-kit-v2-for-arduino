//function:buzzer beeping in different frequence

/*******************************************/
const int buzzerPin = 7;//the buzzer pin attach to
int fre;//set the variable to store the frequence value
/*******************************************/
void setup()
{
  pinMode(buzzerPin,OUTPUT);//set buzzerPin as OUTPUT
}
/*******************************************/ 
void loop()
{
  for(int i = 200;i <= 800;i++)   //frequence loop from 200 to 800
  {
    tone(7,i);   //in pin7 generate a tone,it frequence is i
    delay(5);    //wait for 5 milliseconds   
  }
  delay(4000);   //wait for 4 seconds on highest frequence
  for(int i = 800;i >= 200;i--)  //frequence loop from 800 downto 200
  {
    tone(7,i);  //in pin7 generate a tone,it frequence is i
    delay(10);  //delay 10ms
  }
}

