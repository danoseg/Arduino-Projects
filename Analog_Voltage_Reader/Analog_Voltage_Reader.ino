void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage = analogRead(A0);
  Serial.print("Voltage: ");
  Serial.println(voltage/1024);
  Serial.print("Analog pin value: ");
  Serial.println(analogRead(A0));

}
