#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial HC12(10, 11);

int x;
int y;


void setup()
{ 
HC12.begin(9600);
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(2, OUTPUT);

}
void loop()
{
digitalWrite(A0,0);
digitalWrite(2, HIGH);
x = analogRead(A0);
y = analogRead(A1);

HC12.println("x: ");
HC12.print(x);
HC12.println("y: ");
HC12.print(y);

delay(100);
}
