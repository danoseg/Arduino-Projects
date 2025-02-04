const int onOffSwitchStateSwitchPin = 5; //Switch with pulldown
int previousOnOffSwitchState = 0;
int onOffSwitchState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
}

void loop() {  
 onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      Serial.println("State Changed");   
    //}
  }    
 
  previousOnOffSwitchState = onOffSwitchState;
  Serial.println(previousOnOffSwitchState);
  Serial.print("\t");
  Serial.println(onOffSwitchState);
  delay(500);
}
