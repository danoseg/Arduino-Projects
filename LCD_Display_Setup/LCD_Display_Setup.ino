#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(7, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Arduino version");
  lcd.setCursor(2,1);
  lcd.print("coming soon.");

}

void loop() {
 /*int myTime = millis()/1000;
 lcd.print(myTime);
 delay(500);*/
   
 /*lcd.setCursor(7, 1);
 lcd.print(temperature);
 
  delay(10000);*/
  
}
  
