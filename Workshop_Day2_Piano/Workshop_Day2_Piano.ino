#include <Pitches.h>

int buttonA4 = 2;
int buttonA4State;
int lastButtonA4State = LOW;
int ledA4 = 3;

int buttonB4 = 6;
int buttonB4State;
int lastButtonB4State = LOW;
int ledB4 = 7;

int buzzer = 11;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
    
void setup() {
pinMode(buttonA4, INPUT);
pinMode(buttonB4, INPUT);
pinMode(ledA4, OUTPUT);
pinMode(ledB4, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
  noteA4();
  noteB4();
}

void noteA4(){
  int reading = digitalRead(buttonA4);

  if(reading != lastButtonA4State){
    lastDebounceTime = millis();
    }
  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonA4State){
      buttonA4State = reading;

      if(buttonA4State == HIGH){
        tone(buzzer, NOTE_A4, 550);
        digitalWrite(ledA4, HIGH);
        //delay(250);
      }
      else{
        digitalWrite(ledA4, LOW);
        }
        }
      }
      lastButtonA4State = reading;
    }

void noteB4(){
  int reading = digitalRead(buttonB4);

  if(reading != lastButtonB4State){
    lastDebounceTime = millis();
    }
  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonB4State){
      buttonB4State = reading;

      if(buttonB4State == HIGH){
        tone(buzzer, NOTE_B4, 550);
        digitalWrite(ledB4, HIGH);
        //delay(250);
      }
      else{
        digitalWrite(ledB4, LOW);
        }
        }
      }
      lastButtonB4State = reading;
    }
   
