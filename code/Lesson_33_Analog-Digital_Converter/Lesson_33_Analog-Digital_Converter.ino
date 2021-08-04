/***********************************************
name:Analog-Digital Converter -PCF8591
function:the indicator light D2 on the  PCF8591 gradually lights up and goes out alternately.
The same happens to the LED attached to pin 13 of the SunFounder Uno board 
***************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

#include "Wire.h"
#define PCF8591 (0x90 >> 1) // I2C bus address
void setup()
{
 Wire.begin();
 Serial.begin(9600);
 Serial.println(sin(PI/2));
 
}
void loop()
{
 for (int i=0; i<256; i++)
 {
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(0x40); // control byte - turn on DAC (binary 01000000),analog OUTPUT
 Wire.write(i); // value to send to DAC
 Wire.endTransmission(); // end tranmission
 delay(10*sin(i/256.0*90/180*PI));
 Serial.println(100*sin(i/256.0*90/180*PI));
 }

 for (int i=255; i>=0; --i)
 {
 Wire.beginTransmission(PCF8591); // wake up PCF8591
 Wire.write(0x40); // control byte - turn on DAC (binary 1000000)
 Wire.write(i); // value to send to DAC
 Wire.endTransmission(); // end tranmission
 delay(10*sin(i/256.0*90/180*PI));
 Serial.println(100*sin(i/256.0*90/180*PI));
 }
}
