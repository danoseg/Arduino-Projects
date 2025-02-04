#include <dht.h>

int dataPin = 9;

dht DHT;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  int readData = DHT.read11(dataPin);

  float temp = DHT.temperature;
  float humd = DHT.humidity;

  Serial.print("Temperature :");
  Serial.print(temp);
  Serial.print((char)176);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humd);
  Serial.println(" %");

  delay(2000);
}
