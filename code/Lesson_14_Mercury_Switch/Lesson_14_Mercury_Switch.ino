/************************************************************
 * name:Mercury Switch
 * function:tilt the switch. 
 * Then the indicators on the switch and the LED attached to pin 13 on the SunFounder Uno board will light up.
 **************************************************************/
// Email: support@sunfounder.com
// website: www.sunfounder.com

const int mercuryPin = 7;     // the number of the Mercury Switch pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int mercuryState = 0;         // variable for reading the Mercury Switch status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the Mercury Switch pin as an input:
  pinMode(mercuryPin, INPUT); 
 Serial.begin(9600);  
}

void loop(){
  // read the state of the Mercury Switch value:
  mercuryState = digitalRead(mercuryPin);
  //print the value on serial monitor
  Serial.print("Vaule: ");
  Serial.println(mercuryState);
  if (mercuryState == LOW) 
  {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  delay(100);//delay
}

