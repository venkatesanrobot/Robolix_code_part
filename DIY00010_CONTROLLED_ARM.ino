#include <Servo.h>

Servo So1;
Servo So2;
Servo So3;
Servo So4;

int claw = 177;
int left = 90;
int right = 90;
int bottom = 90;

void setup() {
  So1.attach(7);
  So2.attach(6);
  So3.attach(5);
  So4.attach(4);
  Serial.begin(9600);
  Serial.println("Claw Adjustment -> C & S");
  Serial.println("Right Adjustment-> F & B");
  Serial.println("Left Adjustment -> X & T");
  Serial.println("Bottom Adjustment-> L & R");
  So1.write(bottom);
  So2.write(right);
  So3.write(left);
  So4.write(claw);
}

void loop() {
  if(Serial.available() > 0){
    char data = Serial.read();
    if(data == 'L' && (bottom < 180)){
      bottom++;
      So1.write(bottom);
      Serial.println(bottom);
    }
    if(data =='R' && (bottom > 0)){
      bottom--;
      So1.write(bottom);
      Serial.println(bottom);
    }
    if((data == 'F') && (right < 165)){
      right++;
      So2.write(right);
      Serial.println(right);
    }
    if((data =='B') && (right > 20)){
      right--;
      So2.write(right);
      Serial.println(right);
    }
    if((data == 'X') && (left <= 160)){
      left++;
      So3.write(left);
      Serial.println(left);
    }
    if((data =='T') && (left >= 30)){
      left--;
      So3.write(left);
      Serial.println(left);
    }
    if((data == 'S') && (claw < 177)){
      claw++;
      So4.write(claw);
      Serial.println(claw);
    }
    if((data =='C') && (claw >= 0)){
      claw--;
      So4.write(claw);
      Serial.println(claw);
    }
  }
  Serial.flush();
  delay(10);
}
