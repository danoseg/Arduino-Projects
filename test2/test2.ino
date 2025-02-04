void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

void loop() {
  Serial.print("PD Pin: ");
    Serial.println(digitalRead(5));
  Serial.print("TD Pin: ");
    Serial.println(digitalRead(6));
}
