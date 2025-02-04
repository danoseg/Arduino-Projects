const int ledPin1 =  5;// the number of the LED pin
const int ledPin2 =  6;// the number of the LED pin

// Variables will change:
int ledState1 = LOW;             // ledState used to set the LED
int ledState2 = HIGH;  

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 50;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (ledState1 == LOW) {
      ledState1 = HIGH;
      ledState2 = LOW;
    } else {
      ledState1 = LOW;
      ledState2 = HIGH;
    }
    digitalWrite(ledPin1, ledState1);
    digitalWrite(ledPin2, ledState2);
  }
}
