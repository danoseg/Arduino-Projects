#include <Smoothed.h>

int led = 9;
int potKnob = A0;
Smoothed <int> myPot;

void setup() {
  Serial.begin(9600);
 //Smoothed Library requires Begin Function
  myPot.begin(SMOOTHED_AVERAGE, 10);
  pinMode(led, OUTPUT);
  pinMode(potKnob, INPUT);
}

void loop() {
  //Raw value from potentiometer
  int potVal = analogRead(potKnob);
    
  // Add this value to Smooth Average "Array"
  myPot.add(potVal);
  
  //Get the Smoothed Value
  int smoothedAvg = myPot.get();

  //Output the values to Serial monitor
  Serial.print("Raw value: ");
  Serial.println(potVal);
  Serial.print("Smoothed Sensor value: ");
  Serial.println(smoothedAvg);

  // Map smoothed values to LED
  int brightness = map(smoothedAvg, 0, 1023, 0, 255);
  analogWrite(led, brightness);
  delay(100);

  Serial.print("Brightness: ");
  Serial.println(brightness);
}
