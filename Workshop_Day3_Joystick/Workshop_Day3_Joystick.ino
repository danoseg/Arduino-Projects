int VRx = A0;
int VRy = A1;
int SW = 9;

//Variables to help map values
int xPosition = 0;
int yPosition = 0;
int SW_State = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  //Reading X and Y positions
  xPosition = analogRead(A0);
  yPosition = analogRead(A1);
  SW_State = digitalRead(SW);

  //Call map function
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  Serial.print("X value:");
  Serial.print(mapX);

  Serial.print(" | Y value:");
  Serial.print(mapY);

  Serial.print(" | Button:");
  Serial.print(SW_State);

  Serial.println();
  delay(500);
}
