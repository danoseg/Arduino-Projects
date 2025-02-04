#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <ArduinoJson.h>

RF24 radio(8, 7); // CE, CSN
const byte address[6] = "00001";

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  pinMode(9, INPUT);
  


  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  while (!Serial) continue;
  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<200> doc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);
  //{"X-val": analogRead(0),"Y-val":1351824120,"PushB : digitalRead(9)"}

  // Add values in the document
  //
 /* doc["X-val: "] = analogRead(A0);
  doc["Y-val"] = analogRead(A1);
  ////////////////////////////////////NOT READING PIN 9 ////////////
  doc["PushB"] = digitalRead(9);*/

  // Add an array.
  //
  JsonArray data = doc.createNestedArray("data");
  data.add(analogRead(A0));
  data.add(analogRead(A1));
  data.add(digitalRead(9));
  
  // Generate the minified JSON and send it to the Serial port.
  //
  serializeJson(data, Serial);
  Serial.println();
  //serializeJsonPretty(doc, Serial);
  // The above line prints:
  // {
  //   "sensor": "gps",
  //   "time": 1351824120,
  //   "data": [
  //     48.756080,
  //     2.302038
  //   ]

  //const char text[] = "Hello from the other computer";
  radio.write(&data, sizeof(data));
  delay(1000);
}
