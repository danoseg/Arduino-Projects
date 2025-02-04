

void setup() {
  for(int ledPin = 4; ledPin < 8; ledPin++)
  pinMode(ledPin,OUTPUT);
 // digitalWrite(9,HIGH);
}

void loop() {
  for(int x = 4; x < 8; x++){
    blinkLED(x);
    }
  int buzzer = 11;
  tone(buzzer,200);  
}

void blinkLED(int led){
  digitalWrite(led,150);
  delay(30);
  digitalWrite(led,0);
  delay(30);
}
