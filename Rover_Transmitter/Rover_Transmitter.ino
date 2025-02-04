#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Smoothed.h>

int ledPin = 5;

//Joystick pins
int VRx = A0;
int VRy = A1;
int SW = 9;

//Variables to help map values
int xPosition = 0;
int yPosition = 0;
int SW_State = 0;
int mapX = 0;
int mapY = 0;

Smoothed <int> yPos;

RF24 radio(8, 7); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  yPos.begin(SMOOTHED_AVERAGE, 10);
  radio.begin();
  radio.stopListening();
  radio.setPALevel(RF24_PA_MIN);
  radio.openWritingPipe(address);
}

void loop() {
 //Reading X and Y positions
  xPosition = analogRead(A0);
  yPosition = analogRead(A1);
  SW_State = digitalRead(SW);

  yPos.add(yPosition);
  int ySmooth = yPos.get();
  Serial.println(ySmooth);
  
  //int joyVal [3] = {mapX, mapY, SW_State};

  radio.write(&ySmooth, sizeof(ySmooth));
  
 /* Serial.print(joyVal[0]);
  Serial.print("\t");
  Serial.print(joyVal[1]);
  Serial.print("\t");
  Serial.println(joyVal[2]);*/

 /*Serial.print("X value:");
  Serial.print(xPosition);

  Serial.print(" | Y value:");
  Serial.print(yPosition);

  Serial.print(" | Button:");
  Serial.print(SW_State);

  Serial.println();*/
  

  //delay(100);
  
}
