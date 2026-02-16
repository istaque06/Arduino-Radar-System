#include <Servo.h>

Servo myServo;

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(11);   // Servo signal pin
  Serial.begin(9600);
}

void loop() {

  for(int angle = 15; angle <= 165; angle++) {
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }

  for(int angle = 165; angle > 15; angle--) {
    myServo.write(angle);
    delay(30);
    distance = calculateDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}