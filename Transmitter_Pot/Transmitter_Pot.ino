#include <Smoothed.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int sensorPin = A0;

int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

Smoothed <int> myPot;
RF24 radio(5, 3);

//Transmitter antenna address
const byte addresses[][6] = {"00001", "00002"};

void setup() {
  Serial.begin(9600);
  
  myPot.begin(SMOOTHED_AVERAGE,10);
    
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, HIGH);
  
// CALIBRATION - calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }  
  digitalWrite(13, LOW);

  radio.begin();
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  radio.stopListening();
  int sensorValue = analogRead(sensorPin);
  myPot.add(sensorValue);
  int smoothedSensorAvg = myPot.get();

  int angleValue = map(sensorValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));

  Serial.println(angleValue);

  // Output the smoothed values to the serial stream. Open the Arduino IDE Serial plotter to see the effects of the smoothing methods.
   /* Serial.print("Standard");
    Serial.print("\t"); 
    Serial.println("Smoothed"); 
    Serial.print(sensorValue);
    Serial.print("\t");
    Serial.println(smoothedSensorAvg); */
    
    //delay(50);
}
