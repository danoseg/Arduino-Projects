int LED = 13; // UNO onboard LED
int distancePin = 2; // IR sensor signal;
int isObstacle = HIGH;

const int switchPin = 3;
const int motorPin = 9;
int switchState = 0;

int buzzer = 8;

void setup() {
  pinMode(LED,OUTPUT); // Set UNO onboard LED (pin13) as output to turn on(HIGH) or off(LOW) 
  pinMode(distancePin, INPUT); //Read Input IR Distance Signal 
  pinMode(buzzer, OUTPUT);

  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
 }

void loop() { 

  isObstacle = digitalRead(distancePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
    digitalWrite(motorPin, LOW);
    tone(buzzer,750);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
    digitalWrite(motorPin, HIGH);
    noTone(buzzer);
  }
  delay(200);
}
