const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int testLight = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  for(int i = 9; i<12; i++){
  pinMode(i, OUTPUT);
  }
  pinMode(6,OUTPUT);
}

void loop() {
  redSensorValue = analogRead(A0);
  delay(5);
  greenSensorValue = analogRead(A1);
  delay(5);
  blueSensorValue = analogRead(A2);
  
 
  redValue = redSensorValue /4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  
  Serial.print("Red Sensor: ");
  Serial.println(redSensorValue);
  Serial.print("Mapped red: ");
  Serial.println(redValue);
  Serial.print("Green Sensor: ");
  Serial.println(greenSensorValue);
  Serial.print("Mapped green: ");
  Serial.println(greenValue);
  Serial.print("Blue Sensor: ");
  Serial.println(blueSensorValue);
  Serial.print("Mapped blue: ");
  Serial.println(blueValue);
  Serial.println();
  Serial.print("Mapped red LED: ");
  Serial.println(analogRead(A2)/4);

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(6, analogRead(A2)/4);

  delay(1000);

 }
