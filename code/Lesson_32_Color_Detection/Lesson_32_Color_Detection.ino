/*********************************************************
 * name:Color Detection
 * function: you may see the color RGB value in the serial monitor
 * connection:
 * color sensor             uno r3
 * S0                       3
 * S1                       4
 * S2                       5
 * S3                       6
 * OUT                      2
 * GND                      GND
 * VCC                      5V
 ******************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

#include <TimerOne.h>  //the header file
#define S0     3   // Please notice the Pin's define
#define S1     4  //Combination of S0 and S1 decision output signal frequency scaling factor
#define S2     5  //The combination of S2 and S3 decided to let the red, green, blue, what kind of light through a filter
#define S3     6  
#define OUT    2  

int   g_count = 0;    // count the frequecy
int   g_array[3];     // store the RGB value
int   g_flag = 0;     // filter of RGB queue
float g_SF[3];        // save the RGB Scale factor

// Init TSC230 and setting Frequency.
void TSC_Init()
{
  //set the pins as OUTPUT
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  // OUTPUT Frequency Scaling 2%
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH); 
}

// Select the filter color
void TSC_FilterColor(int Level01, int Level02)
{
  if(Level01 != 0)
    Level01 = HIGH;

  if(Level02 != 0)
    Level02 = HIGH;

  digitalWrite(S2, Level01); 
  digitalWrite(S3, Level02); 
}
//interrupt function, calculate TCS3200 output signal of pulse number
void TSC_Count()
{
  g_count ++ ;
}
/*
name:TSC_Callback()
function:Timer interrupt function, each 1 s after the interruption, the time of the red, green, blue three kinds of light through a filter
 TCS3200 output signal of pulse number stored in the array g_array[3] in the corresponding element variables 
 */
void TSC_Callback()
{
  switch(g_flag)
  {
  case 0:
    Serial.println("->WB Start");
    TSC_WB(LOW, LOW);              //Filter output Red         
    break;
  case 1:
    Serial.print("->Frequency R=");
    Serial.println(g_count);
    g_array[0] = g_count;  //Stored within 1 s red light through the filter, TCS3200 output pulse number
    TSC_WB(HIGH, HIGH);            //Filter output Green        
    break;    
  case 2:
    Serial.print("->Frequency G=");        
    Serial.println(g_count);
    g_array[1] = g_count;  //Stored within 1s green light through the filter, TCS3200 output pulse number
    TSC_WB(LOW, HIGH);             //Filter output Blue
    break; 
  case 3:
    Serial.print("->Frequency B=");
    Serial.println(g_count);
    Serial.println("->WB End");
    g_array[2] = g_count;  //Stored within 1s blue light through the filter, TCS3200 output pulse number
    TSC_WB(HIGH, LOW);             //Clear(no filter)   
    break;
  default:     
    g_count = 0;  //clear count      
    break; 
  }
} 

void TSC_WB(int Level0, int Level1)  //White Balance
{
  g_count = 0;
  g_flag ++;
  TSC_FilterColor(Level0, Level1);
  Timer1.setPeriod(1000000);//1000000 microseconds(1s)
}
void setup()
{
  TSC_Init();
  Serial.begin(9600);
  Timer1.initialize();             // default is 1s
  Timer1.attachInterrupt(TSC_Callback);  
  attachInterrupt(0, TSC_Count, RISING);   
  delay(4000); 
  for(int i=0; i<3; i++)
    Serial.println(g_array[i]);
  g_SF[0] = 255.0/ g_array[0];     //R Scale factor
  g_SF[1] = 255.0/ g_array[1] ;    //G Scale factor
  g_SF[2] = 255.0/ g_array[2] ;    //B Scale factor
  Serial.println(g_SF[0]);
  Serial.println(g_SF[1]);
  Serial.println(g_SF[2]); 
}
void loop()
{
  g_flag = 0;
  for(int i=0; i<3; i++)
    Serial.println(int(g_array[i] * g_SF[i]));
  delay(4000); 
}

