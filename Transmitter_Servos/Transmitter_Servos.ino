#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myServo;
int const potPin = A0;   //read potentiometer voltage
int potVal;
int angle;

RF24 radio(8, 7); // CE, CSN
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 179);  //map input read to range with lower maximum
  radio.write(&angle, sizeof(angle));
  //delay(100);
  
}
