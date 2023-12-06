#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;
int distance;
int i;

Servo radarServo;

void setup() {
  radarServo.attach(9);
  radarServo.write(0);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  digitalWrite(trigPin, LOW);
  Serial.begin(9600);
}

void loop() {

  for (i=0; i<=180;i++) {
  radarServo.write(i);
  distance=Calc();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  delay(50);
  }
  for (i=179; i>=0;i--) {
  radarServo.write(i);
  distance=Calc();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  delay(50);
  }
}

int Calc(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance=pulseIn(echoPin, HIGH)*0.034/2;
  return distance;
}