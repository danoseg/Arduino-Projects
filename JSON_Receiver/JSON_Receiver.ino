#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<ArduinoJson.h>


RF24 radio(8, 7); // CE, CSN

const byte addresses[6] = {"00001"};

void setup() {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, addresses);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}

void loop() {
  while (!Serial) continue;
  StaticJsonDocument<200> doc;
  
if (radio.available()) {
    char data[] =
      "{\"data\":[analogRead(A0),analogRead(A1)]}";
    radio.read(&data, sizeof(data));
    Serial.println(data[1]);
/*  String n = data["North"];
  String s = data["South"];
  String e = data["East"];
  String w = data["West"];
  Serial.println(n);
  Serial.println(s);
  Serial.println(e);
  Serial.println(w);
  delay(1000);*/
 }
}
