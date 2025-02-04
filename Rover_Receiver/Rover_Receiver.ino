#include <SoftwareSerial.h>

 String input;
 int x;
 int xMapped = 0;

 int sw;

 int boundLow;
 int boundHigh;
 
 const char delimiter = ',';

const int controlPin1 = 2;  //Pin 7 on H-bridge - DIRECTION
const int controlPin2 = 3; //Pin 2 on H-bridge - DIRECTION
const int enablePin = 9;  //Pin 1 on H-bridge - ON/OFF
const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown
const int potPin = A0; //Potentiometer - SPEED

int onOffSwitchState = 0;
int directionState = 0;

int previousOnOffSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

 SoftwareSerial HC12(10, 11);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(enablePin, OUTPUT);  
  for(int pinNumber = 2; pinNumber < 4; pinNumber++){
  pinMode(pinNumber, OUTPUT);  
  }    
  pinMode(4, INPUT);      
  digitalWrite(enablePin, LOW);
  delay(2000);
}

void loop() {
  if (HC12.available()) {
    input = HC12.readStringUntil(",");
   if (input.length() > 0)
       {
        Serial.println(input);

       boundLow = input.indexOf(delimiter);
       x = input.substring(0, boundLow).toInt();

     //  delay(10);  
 }
 onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);   
  
 // directionState = map(x, 0, 1022, -512, 512);  
  motorSpeed = map(x, 0, 1022, 0, 255);

 
  /*Serial.print("Received Value: ");
  Serial.println(ySmooth);
  Serial.print("ON/OFF: ");
  Serial.println(onOffSwitchState);
  Serial.print("Direction Value: ");
  Serial.println(directionState);*/
  Serial.print("Speed Value: ");
  Serial.println(motorSpeed);

    if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }

    if (directionState >= -6 && directionState < 512){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    }
    else if(directionState < -8 && directionState > -512) {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
      }
    else if(directionState <= -7 && directionState >= -8) {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, LOW);
      }
    if (motorEnabled == 1){
      analogWrite(enablePin, motorSpeed);
      }
    else{
      analogWrite(enablePin,0);
      }
       // SAVE CURRENT STATE OF SWITCHES BEFORE ENDING LOOP
   previousOnOffSwitchState = onOffSwitchState;
}      
  //delay(500);
}
