#include <LiquidCrystal.h>

// The pins being used to communicate with the LED Display
LiquidCrystal lcd(12, 11, 5, 4 ,3, 2);  // Pin 3 is variable resistor (Potentiometer), Pin 4 is MOSI pin (Master out Slave in [D12 in arduino])

// Variables used
const int switchPin = 6;  // pin of the switch pin
int switchStateLED = 0;     //current state of tilt switch
int switchState = 0;     //current state of tilt switch
int prevSwitchState = 0; // previous state of switch
int reply;               // choose which reply the screen will show
 
void setup() {

  // Instantiate LCD Display (16, 2) is size of LCD Display (rows, columns)
  lcd.begin(16, 2);

  // pinMode is the command for configuring pins and whether they are inputs or outputs
  pinMode(switchPin, INPUT);   // MISO Pin D11 goes into pin 6 of LCD Display - therefore pin 6 is input)
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  lcd.print("Love Each Other!");   // print function writes to the LCD screen because it has been initialized as the INPUT
  //lcd.setCursor(0, 1);  // Coordinates of LCD display, where 0,0 is the first column of the first row
  //lcd.print("John 15:12");

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState){
    if(switchState == LOW){  // loop starts if the switchState pin has no voltage (LOW)
      reply = random(5);
      lcd.clear();
      lcd.print("Love Each Other!");
      lcd.setCursor(0,1);

      switch(reply){
        case 0:
        lcd.print("John 15:12");
        break;
        case 1:
        lcd.print("1 Peter 4:8");
        break;
        case 2:
        lcd.print("Ephesians 5:21");
        break;
        case 3:
        lcd.print("1 John 4:8");
        break;
        case 4:
        lcd.print("Luke 6:31");
        break;
        case 5:
        lcd.print("Proverbs 17:17");
        break; 
        }
      }
    }
prevSwitchState = switchState;

      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10,HIGH);
      
      // Add blinking to LEDS - delay is a pause in the loop of a quarter second
      delay(50);
      digitalWrite(8, LOW); //Blue LED
      digitalWrite(9, HIGH);  // Red LED
      digitalWrite(10, LOW);
      delay(50);

}
