//Analog Temperature Sensor
const int digitalPin = 7;     // Analog Temperature Sensor pin D0 to pin7
int analogPin = A0;           // Analog Temperature Sensor pin A0 to pin A0
const int ledPin =  13;      // pin 13 built-in LED light

// variables will change:
boolean Dstate = 0;          // variable for reading status of D0
int Astate = 0;            // variable for reading status of A0
void setup() 
{
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output:     
  pinMode(digitalPin, INPUT);  // initialize Analog Temperature Sensor D0 pin as an input
  Serial.begin(9600); // initialize serial communications at 9600 bps 

}

void loop()
{
  Astate = analogRead(analogPin);  // read Analog Temperature Sensor A0 value (set point)
  Dstate = digitalRead(digitalPin);  // read state of Analog Temperature Sensor D0
  Serial.print("D0: ");
  Serial.println(Dstate);//print the value of D0
  Serial.print("A0:");
  Serial.println(Astate);//print the value of A0
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (Dstate == HIGH)    // check if Analog Temperature Sensor D0 is HIGH
  {     
    // turn LED on:    
    digitalWrite(ledPin, LOW);  
  } 
  else 
  {
    // turn LED off:
    digitalWrite(ledPin, HIGH); 
  }
  delay(1000);                // controls speed of Analog Temperature Sensor and Serial Monitor display rate
}





