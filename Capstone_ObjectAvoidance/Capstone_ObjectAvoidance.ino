#include <NewPing.h>
#include <Smoothed.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Smoothed <int> smoothedDistance;

//PINOUT
const int controlPin1 = 2;  //Pin 7 on H-bridge
const int controlPin2 = 3; //Pin 2 on H-bridge

const int enablePin = 9;  //Pin 1 on H-bridge
const int enablePin2 =7;  // Pin 8 on H-Bridge

const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown

//VARIABLES
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int motorEnabled = 0;

void setup() {
  Serial.begin(9600);
  smoothedDistance.begin(SMOOTHED_AVERAGE, 10);
    
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(enablePin, LOW);
  digitalWrite(enablePin2, LOW);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int realDistance = sonar.ping_cm();
  smoothedDistance.add(realDistance);
  int distance = smoothedDistance.get();  
  Serial.println(distance);
  
 onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin); 
 delay(1);
  if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }  
  if(distance > 15 && distance <= 100 || distance == 0){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
  }  
  if(distance < 10 && distance > 0){
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
  }
   if(distance <= 15 && distance >= 10){
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, LOW);
  }  
  if (motorEnabled == 1){
      digitalWrite(enablePin, HIGH);
      digitalWrite(enablePin2, HIGH);
  }
   else{
    digitalWrite(enablePin, LOW);
      digitalWrite(enablePin2, LOW);
      }
// SAVE CURRENT STATE OF SWITCHES BEFORE ENDING LOOP
   previousOnOffSwitchState = onOffSwitchState;
}
