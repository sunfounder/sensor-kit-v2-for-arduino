/***********************************************
 * name:Flame Alarm
 * function:ignite a lighter near the flame sensor.
 * Then the buzzer will beep, 
 * and the LED on the flame sensor module and that attached to pin 13 of the SunFounder board will light up.
 * connection:
 * flame sensor module             SunFounder Uno R3
 * D0                                   8
 * A0                                   A0
 * VCC                                  5V
 * GND                                  GND
 * Buzzer Module                        SunFounder Uno R3
 * SIG                                   7
 * VCC                                  5V
 * GND                                  GND
 ***************************************************/

const int analogInPin = A0;// A0 attach to A0
const int digitalInPin = 8; //D0 attach to digital 8
const int ledPin = 13; //pin13 built-in led
const int buzzerPin=7;  //buzzer attach to digital 7

void setup()
{
  //set the pins state
  pinMode(digitalInPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);//initialize serial
  
}

void loop()
{
  int analogVal = analogRead(analogInPin); //read the value of A0
  Serial.print("A0: "); 
  Serial.println(analogVal);//print to serial monitor 
  boolean stat = digitalRead(digitalInPin);
  Serial.print("D0: "); 
  Serial.println(stat); // print to serial monitor 
  Serial.println(" ");  
  if(stat == HIGH)
  {
    digitalWrite(ledPin,LOW);
    noTone(7);//if you want to play different pitches on multiple pins, you need to call noTone() on one pin before calling tone() on the next pin.
  }
  if(stat == LOW)
  {
    digitalWrite(ledPin,HIGH);
    tone(7,320,200);//in pin7 generate a tone ,it's frequency is 320hz and the duration of the tone is 500 milliseconds
  }
  delay(500); // used to slow down readings while calibrating 
}

