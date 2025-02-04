#include <Smoothed.h>



const int sensorPin = A0;

int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

Smoothed <int> myPot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myPot.begin(SMOOTHED_AVERAGE,10);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
// calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
// record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
// record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
// signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);

  myPot.add(sensorValue);

  int smoothedSensorAvg = myPot.get();

  // Output the smoothed values to the serial stream. Open the Arduino IDE Serial plotter to see the effects of the smoothing methods.
    Serial.print("Standard");
    Serial.print("\t"); 
    Serial.println("Smoothed"); 
    Serial.print(sensorValue);
    Serial.print("\t");
    Serial.println(smoothedSensorAvg); 
    
    delay(50);
}
