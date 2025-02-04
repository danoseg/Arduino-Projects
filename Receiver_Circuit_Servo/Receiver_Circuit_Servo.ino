#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// OBJECTS & ADDRESS
RF24 radio(5,3);
const byte addresses[][6] = {"00001", "00002"};
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(9600);

  myservo.attach(9);
  myservo2.attach(6);

  radio.begin();
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  radio.startListening();
  if(radio.available()){
    while(radio.available()){
      int angleValue = 0;
      radio.read(&angleValue, sizeof(angleValue));
      myservo.write(angleValue);
      myservo2.write(angleValue);
        Serial.println(angleValue);
      }
  }

  delay(5);/*

    
    int smoothedSensorAvg = 0;
    radio.read(smoothedSensorAvg, sizeof(&smoothedSensorAvg));
    Serial.println(smoothedSensorAvg);
    }
  void smoothedSensorAvg = radio.read(smoothedSensorAvg, sizeof(&smoothedSensorAvg));   
  int mapVal = map(smoothedSensorAvg, 0, 1023, 0 , 180);
  
  myservo.write(mapVal);
  myservo2.write(mapVal);
  delay(15);*/
}
