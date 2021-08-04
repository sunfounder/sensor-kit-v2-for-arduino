/****************************************************
name:Digital Temperature Sensor-ds18b20
function:you can see the value of current temperature displayed on the LCD.
****************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

/****************************************/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define ONE_WIRE_BUS 7 //ds18b20 module attach to pin7
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{

  // start serial port
  Serial.begin(9600);
  sensors.begin(); // initialize the bus
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight
}
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  lcd.setCursor(0, 0);
  lcd.print("TemC: "); //print "Tem: " on lcd1602
  lcd.print(sensors.getTempCByIndex(0));//print the temperature on lcd1602
  //Serial.print("Tem: ");
  //Serial.print(sensors.getTempCByIndex(0));
  //Serial.println(" C");
  lcd.print(char(223));//print the unit" ℃ "
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("TemF: ");
  lcd.print(1.8*sensors.getTempCByIndex(0) + 32.0);//print the temperature on lcd1602
  lcd.print(char(223));//print the unit" ℉ "
  lcd.print(" F");
  //Serial.print("Tem: ");
  //Serial.print(1.8*sensors.getTempCByIndex(0) + 32.0);
  //Serial.println(" F");
  //Serial.println("");
  //Serial.print("Temperature for the device 1 (index 0) is: ");
  //Serial.println(sensors.getTempCByIndex(0));  //print the temperature on serial monitor
}
