#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;
int pos = 0;    // variable to store the servo position

RF24 radio(8, 7); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int angle = 0;
    radio.read(&angle, sizeof(angle));
    Serial.println(angle);
    myservo.write(angle);              // tell servo to go to position in variable 'pos'
    myservo2.write(angle);
  }
}
