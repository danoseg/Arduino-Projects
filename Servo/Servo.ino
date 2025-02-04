#include <Servo.h>

//class   ojbect;
Servo myServo;

int const potPin = A0;   //read potentiometer voltage
int potVal;
int angle;

void setup() {
  myServo.attach(9);  //attach servo to Dpin
  Serial.begin(9600);
  }

void loop() {
  float voltage = analogRead(A0)*5/1024;    //analog input to input voltage (component's voltage)
  
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);  //map input read to range with lower maximum
  Serial.print(", angle: ");
  Serial.println(angle);
  
 // Serial.println(analogRead(A0));

  Serial.print("Voltage: "); // potentionmeter voltage 
  Serial.println(voltage);
 /* Serial.println(myServo.read());
  Serial.println(digitalRead(9));*/
  myServo.write(angle); 
  //myServo.write(75);

  delay(2000);
 }
