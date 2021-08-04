/***********************************************************
 * name:Thermostatic Water Tank
 * function:after the startup, the LCD1602 first displays Thermostatic Water Tank and then the value of the current temperature.
 * Press the button on the Button module to enter setup mode.
 * Then rotate the Rotary Encoder to change the threshold of temperature value. 
 * After setting a value, for example, 30℃, you can press the switch on the Rotary Encoder module to confirm. 
 * If the current temperature is lower than 30℃ (the threshold you just set), the normally open contact of the relay is closed.
 **********************************************************/
//Email:support@sunfounder.com
//website:www.sunfounder.com

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "encoder.h"
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27,16,2);
ENCODER encoder;
#define buttonPin 10  //the key attach to
#define temPin  A0  //the thermistor attach to 
#define relayPin 2   //the relay attach to
#define ledPin 13
float upperTem = 0.00;
#define beta 3950  //the beta of the thermistor
#define resistance 10  //the value of the pull-down resistor
float hysteresis = 0.25;
void setup()
{
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(relayPin, HIGH); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Thermostatic  ");
  lcd.setCursor(0, 1);
  lcd.print("   water tank   ");
  encoder.Init(7, 6, 5);// Init(CLKPIN, DTPIN, SWPIN)
  pinMode(buttonPin, INPUT);
  upperTem = EEPROM.read(0);
  delay(1000);
}

void loop()
{
  if(digitalRead(buttonPin) == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Set Mode    ");
    lcd.setCursor(0, 1);
    lcd.print("    start...    ");
    delay(500);
    lcd.clear();
    while(1)
    {          
      lcd.setCursor(0, 0);
      lcd.print("Adjust: ");
      float change = encoder.turnSettle();
      upperTem = upperTem + change;
      lcd.print(upperTem);
      if(encoder.pressed())
      {
        EEPROM.write(0, upperTem);
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print("Upper Tem: ");
        lcd.print((float) EEPROM.read(0));
        delay(1000);
        lcd.clear();
        break;
      }
    }
  }
  else
  {
    //read thermistor value 
    long a = 1024 - analogRead(temPin);
    //the calculating formula of temperature
    float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
    float tempF = 1.8*tempC + 32.0;
    // Print a message of "Temp: "to the LCD.
    // set the cursor to column 0, line 0  
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    // Print a centigrade temperature to the LCD.
    lcd.print(tempC);
    // Print the unit of the centigrade temperature to the LCD.
     lcd.print(char(223));
    lcd.print(" C");
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    lcd.print("Fahr: ");
    // Print a Fahrenheit temperature to the LCD.
    lcd.print(tempF);
    // Print the unit of the Fahrenheit temperature to the LCD.
     lcd.print(char(223));
    lcd.print(" F");
    delay(100); //wait for 100 milliseconds 
    if(tempC >= upperTem + hysteresis)
    {
      digitalWrite(relayPin, HIGH); 
      digitalWrite(ledPin, HIGH);
    }
    else if(tempC < upperTem - hysteresis)
    {
      digitalWrite(relayPin, LOW); 
      digitalWrite(ledPin, LOW);
    }
  }
}


