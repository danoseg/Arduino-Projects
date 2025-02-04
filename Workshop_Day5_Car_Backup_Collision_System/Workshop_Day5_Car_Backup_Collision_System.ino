#include <NewTone.h>
#include <NewPing.h>
#include <Smoothed.h>

//PLacement of pins on Arduino
int trigPin = 8;
int echoPin = 7;
int maxDistance = 4000;

long int distance;

int red = 11;
int blue = 10;
int green = 9;

int piezo = 12;
int potKnob = A0;

//Declare sonar variable from NewPing library
NewPing sonar(trigPin, echoPin, maxDistance);
//Declare myPot library from Smoothed library
Smoothed <int> myPot;

void setup() {
Serial.begin(9600);
//Smoothed library initiates
myPot.begin(SMOOTHED_AVERAGE, 10);

//Set pin modes
pinMode(7, INPUT);
for(int i = 8; i < 13; i++){
  pinMode(i, OUTPUT);
  }
}

void loop() {
  //Ultrasonic Sensor library NewPing
  delay(50);
  int distance = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.println(distance);

  //Smoothed Library
  float realSensorValue = analogRead(A0);
  myPot.add(realSensorValue);
  float smoothedSensorValue = myPot.get();
  Serial.print(realSensorValue); 
  Serial.print("\t"); 
  Serial.println(smoothedSensorValue); 
  
  //Use pot to set min distance at which Sensor buzzes
  int minDist = map(smoothedSensorValue, 0, 1023, 20, 45);
  Serial.println(minDist);

  if (distance <= minDist){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    NewTone(piezo, 3322, 250);
    }
  if (distance >= 80){
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    NewTone(piezo, 104, 250);
    }
  if (distance > minDist && distance < 80){
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    NewTone(piezo, 998, 250);
    }
  if (distance >= 200 || distance <=0){
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    noNewTone(piezo);
    //NewTone(piezo, 50, 250);
    } 
  delay(500);
}
