int switchState = 0;

#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}
void loop() {
  //READ
  if (HC12.available()) {        // If HC-12 has data
    Serial.write(HC12.read());      // Send the data to Serial monitor
  }
//WRITE
Serial.write(digitalRead(4));
  if (Serial.available()) {      // If Serial monitor has data
    HC12.write(digitalRead(4));      // Send that data to HC-12
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
    }
}
