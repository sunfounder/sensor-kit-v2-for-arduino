#include "Wire.h"
#define PCF8591 (0x90 >> 1) // I2C bus address
byte value0, value1, value2, value3;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  Wire.beginTransmission(PCF8591); // wake up PCF8591
  Wire.write(0x04); // control byte - read ADC0 then auto-increment(binary 00000100)
  Wire.endTransmission(); // end tranmission
  Wire.requestFrom(PCF8591, 5);
  value0 = Wire.read();
  value1 = Wire.read();
  value2 = Wire.read();
  value3 = Wire.read();
  Serial.print("Chanel0:");Serial.print(value0); Serial.print("   ");
  Serial.print("Chanel1:");Serial.print(value1); Serial.print("   ");
  Serial.print("Chanel2:");Serial.print(value2); Serial.print("   ");
  Serial.print("Chanel3:");Serial.print(value3); Serial.print("   ");
  Serial.println();
  delay(1000);

  //dToAConvert();

}

void dToAConvert()
{
  for (int i = 0; i < 256; i++)
  {
    Wire.beginTransmission(PCF8591); // wake up PCF8591
    Wire.write(0x40); // control byte - turn on DAC (binary 1000000)
    Wire.write(i); // value to send to DAC
    Wire.endTransmission(); // end tranmission
    delay(10 * sin(i / 256.0 * 90 / 180 * PI));
    //Serial.println(100*sin(i/256.0*90/180*PI));
  }

  for (int i = 255; i >= 0; --i)
  {
    Wire.beginTransmission(PCF8591); // wake up PCF8591
    Wire.write(0x40); // control byte - turn on DAC (binary 1000000)
    Wire.write(i); // value to send to DAC
    Wire.endTransmission(); // end tranmission
    delay(10 * sin(i / 256.0 * 90 / 180 * PI));
    //Serial.println(100*sin(i/256.0*90/180*PI));
  }
}

