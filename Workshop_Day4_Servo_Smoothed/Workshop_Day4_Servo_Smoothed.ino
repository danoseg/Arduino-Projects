#include <Servo.h>
#include <Smoothed.h>

//Create Servo Object
Servo myservo;
Servo myservo2;
Smoothed <int> myPot;

//Declare variables
int potpin = A0;
int pos = 0;

void setup() {
  myservo.attach(9);
  myservo2.attach(6);
  pinMode(potpin, INPUT);

  myPot.begin(SMOOTHED_AVERAGE, 10);
}

void loop() {
  pos = analogRead(potpin);
  myPot.add(pos);
  int smoothedPos = myPot.get();

  int mapVal = map(smoothedPos, 0, 1023, 0 , 180);
  
  myservo.write(mapVal);
  myservo2.write(mapVal);
  delay(15);
}
