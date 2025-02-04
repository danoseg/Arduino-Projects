
const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);

  for(int pinNumber = 8; pinNumber<11; pinNumber++)
{
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
}
}

void loop() {
  float sensorVal = analogRead(sensorPin);

 Serial.print("Sensor value: ");
 Serial.print(sensorVal);

//ADC reading
 float voltage = (sensorVal/1024.0) * 5.0; 
 Serial.print(" , Volts: ");
 Serial.print(voltage);

 float temperature = (voltage - .5) * 100;
 Serial.print(" , degrees C: ");
 Serial.println(temperature);

//LED's
 if(temperature < baselineTemp + 2){
 /* digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);*/
  for(int pinNumber = 8; pinNumber<11; pinNumber++)
  {
    digitalWrite(pinNumber, LOW);
    }
  }
 else if(temperature >= baselineTemp + 2 && temperature< baselineTemp +4){
  /*digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);*/
  for(int pinNumber = 8; pinNumber<11; pinNumber++)
  {
    if(pinNumber > 8){
    digitalWrite(pinNumber, LOW);
    }
    else{
    digitalWrite(pinNumber, HIGH);
    }
   }
  }
  else if(temperature >= baselineTemp + 4 && temperature< baselineTemp +6){
  /*digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);*/
  for(int pinNumber = 8; pinNumber<11; pinNumber++){
    if(pinNumber < 10){
    digitalWrite(pinNumber, HIGH);
    }
    else{
    digitalWrite(pinNumber, LOW);
    }
   }
  }
  else if(temperature >= baselineTemp + 6){
  /*   digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);*/
  for(int pinNumber = 8; pinNumber<11; pinNumber++){
      digitalWrite(pinNumber, HIGH);
    }
  }
  delay(1000);
}
  
