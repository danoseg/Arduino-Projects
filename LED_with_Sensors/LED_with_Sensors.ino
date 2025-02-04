#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 13     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.

DHT dht(DHTPIN, DHTTYPE);

// The pins being used to communicate with the LED Display
LiquidCrystal lcd(12, 11, 5, 4 ,3, 2);  // Pin 3 is variable resistor (Potentiometer), Pin 4 (RS) is MOSI pin (Master out Slave in [D12 in arduino])

void setup() {
  lcd.begin(16, 2);
  //Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
 // delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  /*if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print(F("Failed to read from DHT sensor!"));
    return;
  }*/

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.clear();
  lcd.print(" Humidity: ");
  //lcd.print(h);
  //Serial.print(h);
  /*Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));*/
}
