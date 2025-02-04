#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup() {
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.csnPin = 10;
  Mirf.cePin = 9;
  Mirf.init();
  Mirf.setTADDR((byte *)"serv1");
  Mirf.payload = 32;
  Mirf.config();
  Serial.println("Beginning ... ");
}

void loop() {
  Mirf.send((byte *)"Hello");
  delay(500);
  }

  
