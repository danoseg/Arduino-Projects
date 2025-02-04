#include <NewPing.h>

//Ultrasonic
int echo = 6;
int trig = 5;
//H-Bridge
const int controlPin1 = 2; //Pin 7 on H-bridge
const int controlPin2 = 3; //Pin 2 on H-bridge
const int enablePin = 9;  //Pin 1 on H-bridge
const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown

long int distance;
int maxDistance = 4000;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int motorEnabled = 0;
int motorDirection = 1;

//Declare sonar variable from NewPing library -- declaring ultrasonic sensor
NewPing sonar(trig, echo, maxDistance);
  
void setup() {
//Ultrasonic pin setup
Serial.begin(9600);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

//H-Bridge pin setup
pinMode(enablePin, OUTPUT);  
pinMode(onOffSwitchStateSwitchPin, INPUT);
pinMode(3, OUTPUT);
pinMode(2, OUTPUT);  
digitalWrite(enablePin, LOW);
}

void loop() {
int distance = sonar.ping_cm();
onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);

    /*CODE FOR DATA EVALUATION/*
/*
Serial.println(onOffSwitchState); //0 is OFF
Serial.print("Ping: ");
Serial.println(distance);*/

   if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }
       if (motorEnabled == 1){
      analogWrite(enablePin, 255);
      }

      //DISTANCE THRESHOLDS FOR DC MOTOR CONTROL
if (motorDirection == 1){
    if(distance < 5){
      analogWrite(enablePin, 0);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
    }
    else{
    analogWrite(enablePin, 255);
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    }
}
    // SAVE CURRENT STATE OF SWITCHES BEFORE ENDING LOOP
    previousOnOffSwitchState = onOffSwitchState;
}
