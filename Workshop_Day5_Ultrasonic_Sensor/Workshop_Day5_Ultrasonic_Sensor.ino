int echo = 11;
int trig = 10;

long duration;
int distance;
  
void setup() {
Serial.begin(9600);
Serial.println("Ultrasonic Sensor Test: ");

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}

void loop() {
  //Clear the Trigger Condition
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  //Set the Trig pin HIGH for 10 micro secs
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //Read eccho pin to determine duration it takes to read signal
  digitalRead(echo);
  duration = pulseIn(echo, HIGH);
  
  //calculate the distance using speed of sound 
  //and dividng by two because we only need one half of the path
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
}
