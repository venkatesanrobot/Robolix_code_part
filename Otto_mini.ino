#include <Servo.h>

Servo Wheel1;
Servo Wheel2;
const int trigPin = 2;     
const int echoPin = 3;


long duration;
int distance;

int val = 90;

void setup() {
  Serial.begin(9600);
   Wheel1.attach(9);
   Wheel2.attach(8);

   Wheel1.write(val);
   Wheel2.write(val);

   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(0.02);
        // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(0.2);
    digitalWrite(trigPin, LOW);
   // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(10);

    if (distance < 14) {
    Wheel2.write(0);
    Wheel1.write(0); 
    Serial.println("left");
    delay(1500);  

    Wheel2.write(180);
    Wheel1.write(180); 
    Serial.println("right");
    delay(1500);  

    Wheel2.write(90);
    Wheel1.write(90);
  
    } else {
      if(Serial.available())
{
  switch(Serial.read())
  {
    case 'F': 
    Wheel2.write(0);
    Wheel1.write(180); 
    Serial.println("front");
    delay(1000);
    Wheel2.write(90);
    Wheel1.write(90);  
    break;

    case 'B': 
      Wheel2.write(180);
      Wheel1.write(0);
      Serial.println("back"); 
      delay(1000);
      Wheel2.write(90);
      Wheel1.write(90);  
      break;
    case 'L': 
      Wheel2.write(0);
      Wheel1.write(0); 
      Serial.println("left");
      delay(1000);  
      Wheel2.write(90);
      Wheel1.write(90);
      break;
    case 'R': 
      Wheel2.write(180);
      Wheel1.write(180); 
      Serial.println("right");
      delay(1000);
      Wheel2.write(90);
      Wheel1.write(90);  
      break;
    default:
      Wheel2.write(90);
      Wheel1.write(90);
      Serial.println("stop");
      delay(2);
    }
}  
else{
    }
    }

    
delay(10);

}
