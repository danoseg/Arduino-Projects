#include <Smoothed.h>

int potKnob = A0;

Smoothed <int> myPot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myPot.begin(SMOOTHED_AVERAGE,10);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potKnob);

  myPot.add(potVal);

  int smoothedSensorAvg = myPot.get();

  // Output the smoothed values to the serial stream. Open the Arduino IDE Serial plotter to see the effects of the smoothing methods.
    Serial.print("Standard");
    Serial.print("\t"); 
    Serial.println("Smoothed"); 
    Serial.print(potVal);
    Serial.print("\t");
    Serial.println(smoothedSensorAvg); 
    
    delay(500);
}
