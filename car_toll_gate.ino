#include <Servo.h>

Servo gateServo;
const int irSensorPin = 2;   // IR sensor output pin
const int irSensorPin1 = 3 ; 
const int servoOpenAngle = 110;  // Servo angle for open position
const int servoCloseAngle = 0;  // Servo angle for close position



void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(irSensorPin1, INPUT);
  gateServo.attach(9);  // Attach servo to pin 9
}

void loop() {
  int sensorValue = digitalRead(irSensorPin); 
  int sensorValue1 = digitalRead(irSensorPin1);
  if (sensorValue == HIGH) {
    // Gate is closed, open it
    gateServo.write(servoOpenAngle);
    delay(0.1);  // Adjust delay as needed
  } else {
    // Gate is open, close it
    gateServo.write(servoCloseAngle);
    delay(2500);  // Adjust delay as needed
  }
  if (sensorValue1 == HIGH) {
    // Gate is closed, open it
    gateServo.write(servoOpenAngle);
    delay(0.1);  // Adjust delay as needed
  } else {
    // Gate is open, close it
    gateServo.write(servoCloseAngle);
    delay(4000);
    }  // Adjust delay as needed


}
