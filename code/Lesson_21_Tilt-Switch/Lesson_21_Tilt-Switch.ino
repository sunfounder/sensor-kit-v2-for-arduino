const int sigPin = 7;     // the number of the tilt switch pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
boolean sigState = 0;         // variable for reading the tilt switch status

void setup()
{
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the tilt switch pin as an input:
  pinMode(sigPin, INPUT);  
  Serial.begin(9600);  
}

void loop()
{
  // read the state of the tilt switch value:
  sigState = digitalRead(sigPin);
  Serial.println(sigState);

  if (sigState == HIGH) 
  {     
    // turn LED off:    
    digitalWrite(ledPin, LOW);  
  } 
  else 
  {
    // turn LED on:
    digitalWrite(ledPin, HIGH); 
  }
}

