#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define analogPin  A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor
#define resistance 10 //the value of the pull-up resistor

void setup()
{
  // set up the LCD's number of columns and rows: 
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
  Serial.begin(9600);
}

void loop()
{
  long a =1023 - analogRead(analogPin);  //read thermistor value 
  Serial.print("Raw reading ");
  Serial.println(a); 
  //the calculating formula of temperature
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  float tempF = 1.8*tempC + 32.0;
  Serial.print("Centigrade ");
  Serial.println(tempC); 
  Serial.print("Fahrenheit ");
  Serial.println(tempF); 
  Serial.println("");

  // Print a message of "Temp: "to the LCD.
  lcd.setCursor(0, 0);// set the cursor to column 0, line 0
  lcd.print("Temp: ");  // Print a message of "Temp: "to the LCD.
  lcd.print(tempC); // Print a centigrade temperature to the LCD.
  // Print the unit of the centigrade temperature to the LCD.
  lcd.write(char(223));
  lcd.print("C");//print the unit" ℃  "
  lcd.setCursor(0, 1);// set the cursor to column 0, line 1
  lcd.print("Fahr: ");
  lcd.print(tempF);// Print a Fahrenheit temperature to the LCD.
  lcd.write(char(223)); // Print the unit of the Fahrenheit temperature to the LCD.
  lcd.print(" F");//print the unit"°F"
  delay(200); //wait for 100 milliseconds
}


