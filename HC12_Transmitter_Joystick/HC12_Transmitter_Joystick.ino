#include <SoftwareSerial.h>
#include <Wire.h>

int x = 0;
int y = 0;
int sw = 0;

SoftwareSerial HC12(10, 11);

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
x = analogRead(A0);
y = analogRead(A1);
sw = digitalRead(2);


HC12.print(x);
HC12.print(",");
HC12.print(y);
HC12.print(",");
HC12.print(sw);
HC12.println("");

delay(150);
}
