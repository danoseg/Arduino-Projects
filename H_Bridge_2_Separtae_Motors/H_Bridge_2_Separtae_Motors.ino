//PINOUT
const int controlPin1 = 2;  //Pin 7 on H-bridge
const int controlPin2 = 3; //Pin 2 on H-bridge
const int controlPin3 = 5;  //Pin 14 on H-bridge
const int controlPin4 = 6; //Pin 9 on H-bridge

const int enablePin = 9;  //Pin 1 on H-bridge
const int enablePin2 =7;  // Pin 8 on H-Bridge

const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown

//VARIABLES
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int motorEnabled = 0;


void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(A0, INPUT);  // Potentiometre Test -- Distance Reading
  pinMode(4, INPUT);
  digitalWrite(enablePin, LOW);
  digitalWrite(enablePin2, LOW);
}

void loop()
{
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);   
  if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }
  
  if(analogRead(A0) > 511){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    
      digitalWrite(controlPin3, HIGH);
      digitalWrite(controlPin4, LOW);
  }
  
  if(analogRead(A0) < 511){
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
    
      digitalWrite(controlPin3, LOW);
      digitalWrite(controlPin4, HIGH);
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
