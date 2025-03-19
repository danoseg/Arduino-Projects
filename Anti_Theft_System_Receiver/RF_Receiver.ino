#include <SoftwareSerial.h>

const int powerPin = 2;

/*int boundLow;
int boundHigh;*/
const char delimiter = ',';

String key; //input

SoftwareSerial HC12(10,11);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, LOW);
 }

void loop() {
  if (HC12.available()){
    key = HC12.readStringUntil(',');
   if (key.length() > 0)
       {
       if (key == "ABC"){
       digitalWrite(powerPin,HIGH);
       Serial.println(key);
       }
       else {
        digitalWrite(powerPin,LOW);
        }
  }
  
  //delay(100);

  //SECURITY MEASURE - CONFIRMATION
 /* while (Serial.available()){
    HC12.Write("RECEIVED")
    }*/
  }
}
