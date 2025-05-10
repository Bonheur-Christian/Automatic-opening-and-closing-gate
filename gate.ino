#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;

const int redLEDPin = 4;
const int blueLEDPin = 5;

const int redGND = 7;
const int blueGND = 8;

const int servoPin = 6;
const int buzzerPin = 12;

Servo gateServo;

long duration;
int distance;
bool isGateOpen = false;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redGND, OUTPUT);
  pinMode(blueGND, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0);
  delay(500);
  gateServo.detach(); // Prevent jitter

  digitalWrite(redLEDPin, HIGH);
  digitalWrite(redGND, LOW);

  digitalWrite(blueLEDPin, LOW);
  digitalWrite(blueGND, HIGH);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  int threshold =20;

if (distance > 0 && distance <= threshold && !isGateOpen) {
  gateServo.attach(servoPin);
  gateServo.write(90);
  delay(500);
  gateServo.detach();
  isGateOpen = true;

  Serial.println("Gate opening");

  digitalWrite(blueLEDPin, HIGH);
  digitalWrite(blueGND, LOW);

  digitalWrite(redLEDPin, LOW);
  digitalWrite(redGND, HIGH);

  // Continuous beeping for 3 seconds
  Serial.println("Buzzer ON (interval beeping)");
  unsigned long startTime = millis();
  while (millis() - startTime < 3000) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  }

  gateServo.attach(servoPin);
  gateServo.write(0);
  delay(1000);
  gateServo.detach();
  isGateOpen = false;

  Serial.println("Gate closing");

  digitalWrite(blueLEDPin, LOW);
  digitalWrite(blueGND, HIGH);

  digitalWrite(redLEDPin, HIGH);
  digitalWrite(redGND, LOW);

  digitalWrite(buzzerPin, LOW);
  Serial.println("Buzzer OFF");
}


  delay(500);
}
