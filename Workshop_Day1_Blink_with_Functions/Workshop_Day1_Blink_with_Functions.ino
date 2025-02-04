

void setup() {
  for(int ledPin = 4; ledPin < 8; ledPin++)
  pinMode(ledPin,OUTPUT);
 // digitalWrite(9,HIGH);
}

void loop() {
  for(int x = 4; x < 8; x++){
    blinkLED(x);
    }
}

void blinkLED(int led){
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}
