#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


void setup() {
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  sensors.begin();  
}

void loop() {
  Serial.println("Requesting temperatures...");
  sensors.requestTemperatures();

  Serial.print("Done");

  
  Serial.println("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));
delay(1000);
}
