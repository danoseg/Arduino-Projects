#include <NewTone.h>

int piezzo = 8;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  NewTone(piezzo, 50, 250);
  NewTone(piezzo, 100, 250);
  delay(150);
  NewTone(piezzo, 20, 250);
  NewTone(piezzo, 15, 250);
  delay(150);
  NewTone(piezzo, 30, 250);
  NewTone(piezzo, 30, 250);
  delay(150);
  NewTone(piezzo, 35, 250);
  NewTone(piezzo, 40, 250);
  delay(150);  
  NewTone(piezzo, 70, 250);
  NewTone(piezzo, 80, 250);
  delay(150);
  NewTone(piezzo, 110, 250);
  NewTone(piezzo, 115, 250);
  delay(150);
  NewTone(piezzo, 5, 250);
  NewTone(piezzo, 10, 250);
  delay(150);
  NewTone(piezzo, 70, 250);
  NewTone(piezzo, 80, 250);
  delay(150);
  NewTone(piezzo, 40, 250);
  NewTone(piezzo, 50, 250);
 // NewTone(piezzo, 60, 250);
  delay(150);
  }
