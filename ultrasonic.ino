const int trigPin = 7;
const int echoPin = 8;
const int ledPin = 2;


long duration, cm;


// CHANGE MADE HERE: Set fixed target distance to 20 cm
int targetDistance = 20;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);


  // CHANGE MADE HERE: Removed user input prompt
  Serial.print("Fixed target distance: ");
  Serial.print(targetDistance);
  Serial.println(" cm");
}


void loop() {
  // CHANGE MADE HERE: Removed Serial input handling


  cm = readDistanceCM();


  Serial.print("Measured: ");
  Serial.print(cm);
  Serial.println(" cm");


  // Check if within ±2 cm of target
  if (abs(cm - targetDistance) <= 2) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }


  delay(300);
}


long readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  return microsecondsToCentimeters(duration);
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}



