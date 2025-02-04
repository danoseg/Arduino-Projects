// cm:esp32:spencer
#include <Arduino.h>
#include <CircuitOS.h>
#include <Spencer.h>

void setup() {
  Serial.begin(115200);
  Serial.println();
  Spencer.begin();
  Spencer.loadSettings();

  LEDmatrix.startAnimation(new Animation(new SerialFlashFileAdapter("GIF-fog.gif")), true);


}

void loop() {
  LoopManager::loop();


}
