#include <LiquidCrystal.h>

const int sensorPin = A0;
int switchPin = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Welcome Daniel");  
  lcd.setCursor(0,1);
  lcd.print("It is ");
  lcd.setCursor(12,1);
  lcd.print("C");

}

void loop() {
 /*int myTime = millis()/1000;
 lcd.print(myTime);
 delay(500);*/
   
 int sensorVal = analogRead(sensorPin);
 int switchPin = digitalRead(7); 
 
 Serial.println(switchPin);

 Serial.print("Sensor value: ");
 Serial.print(sensorVal);

//ADC reading
 float voltage = (sensorVal/1024.0) * 5.0; 
 Serial.print(" , Volts: ");
 Serial.print(voltage);

 float temperature = (voltage - .5) * 100;
 Serial.print(" , degrees C: ");
 Serial.println(temperature);
 lcd.setCursor(0,0);


 lcd.setCursor(7, 1);
 lcd.print(temperature);
 
  delay(10000);
  
}
  
