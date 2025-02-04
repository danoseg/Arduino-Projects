 #include <SoftwareSerial.h>

//H-Bridge
const int controlPin1 = 2;  //Pin 7 on H-bridge
const int controlPin2 = 3; //Pin 2 on H-bridge
const int enablePin = 9;  //Pin 1 on H-bridge
const int onOffSwitchStateSwitchPin = 4; //Switch with pulldown

int onOffSwitchState = 0;
int directionSwitchState = 0;

int previousOnOffSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

//HC-12
 String input;
 int x;
 int y;

 int boundLow;
 int boundHigh;
 const char delimiter = ',';
 
 SoftwareSerial HC12(10, 11);
 
 void setup()
 {
 Serial.begin(9600);
 HC12.begin(9600);  
   pinMode(enablePin, OUTPUT);  
  for(int pinNumber = 2; pinNumber < 4; pinNumber++){
  pinMode(pinNumber, OUTPUT);  
  }    
  for(int pinNumber = 4; pinNumber < 6; pinNumber++){
  pinMode(pinNumber, INPUT);  
  }  
  digitalWrite(enablePin, LOW);
 delay(2000);
 }

 
 void loop()
 {
 if(HC12.available())
   {
   onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
   delay(1);
   input = HC12.readStringUntil(',');
   if (input.length() > 0)
       {
       Serial.println(input);
      
      if(onOffSwitchState != previousOnOffSwitchState){
      if(onOffSwitchState == HIGH){
        motorEnabled = !motorEnabled;
        }
      }
      if (motorDirection == 1){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    }
       boundLow = input.indexOf(delimiter);
       x = input.substring(0, boundLow).toInt();
       motorSpeed = map(x, 0, 1023, 0, 255);
       
       delay(10);  
           
      if (motorEnabled == 1){
        if(motorSpeed > 150)
      analogWrite(enablePin, motorSpeed);
      if(motorSpeed < 130)
      analogWrite(enablePin, 0);
      }
      else{
      analogWrite(enablePin,0);
      }
      previousOnOffSwitchState = onOffSwitchState;
 }
 }
 }
