#include <SoftwareSerial.h>

#define setPin 6
#define button1 4

SoftwareSerial HC12(10, 11);

byte incomingByte;
String readBuffer = "";
int button1State = 0;

void setup() {
Serial.begin(9600);                   // Open serial port to computer
  HC12.begin(9600);                     // Open serial port to HC12
  pinMode(setPin, OUTPUT);
  pinMode(button1, INPUT); 
  digitalWrite(setPin, HIGH);
}

void loop() {
  while (HC12.available()) {        // If HC-12 has data
    incomingByte = HC12.read();
    readBuffer += char(incomingByte);
  }
  delay(100);
  while (Serial.available()) {
    HC12.write(digitalRead(4));
  }
}
