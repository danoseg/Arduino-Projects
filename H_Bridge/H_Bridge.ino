// Motor direction control, ON/OFF, Motor speed

const int controlPin1 = 2;  //Pin 7 on H-bridge
const int controlPin2 = 3; //Pin 2 on H-bridge
const int enablePin = 9;  //Pin 1 on H-bridge
const int directionSwitchPin = 5; //Switch with pulldown
const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown
const int potPin = A0; //Potentiometer (speed of motor)

int onOffSwitchState = 0;
int directionSwitchState = 0;

int previousOnOffSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  Serial.begin(9600);
  pinMode(enablePin, OUTPUT);  
  for(int pinNumber = 2; pinNumber < 4; pinNumber++){
  pinMode(pinNumber, OUTPUT);  
  }    
  for(int pinNumber = 4; pinNumber < 6; pinNumber++){
  pinMode(pinNumber, INPUT);  
  }  
  digitalWrite(enablePin, LOW);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
    delay(1);   
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;

Serial.println(onOffSwitchState);
Serial.println(directionSwitchState);
Serial.println(motorSpeed);

    if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }
    if (directionSwitchState != previousDirectionSwitchState) {
      if (directionSwitchState == HIGH){
        motorDirection = !motorDirection;
        }
      }
    if (motorDirection == 1){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    }
    else {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
      }
    if (motorEnabled == 1){
      analogWrite(enablePin, motorSpeed);
      }
    else{
      analogWrite(enablePin,0);
      }

    // SAVE CURRENT STATE OF SWITCHES BEFORE ENDING LOOP
    previousDirectionSwitchState = directionSwitchState;
    previousOnOffSwitchState = onOffSwitchState;
}
