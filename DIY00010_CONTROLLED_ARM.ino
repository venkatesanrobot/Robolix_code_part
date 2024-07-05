#include <Servo.h>

Servo So1;
Servo So2;
Servo So3;
Servo So4;
int d1,d2,d3,d4;
int claw = 177;
int bottom = 90;

void setup() {
  So1.attach(4);
  So2.attach(5);
  So3.attach(6);
  So4.attach(7);
  Normal();
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    char data = Serial.read();
    Serial.println(data);
    if(data == 'L' && (bottom <= 180)){
      int F = bottom+30;
      for(d4=bottom;d4<=F;d4++){
        bottom++;
        So4.write(bottom);
        delay(10);
      }
    }
    if(data =='R' && (bottom > 0)){
      int F = bottom-30;
      for(d4=bottom;d4>=F;d4--){
        bottom--;
        So4.write(bottom);
        delay(10);
      }
    }
    if((data == 'X') && (claw < 177)){
      claw = claw+3;
      So1.write(claw);
    }
    if((data =='Y') && (claw > 21)){
      claw = claw-3;
      So1.write(claw);
    }
    if(data == 'B'){
      UP();
    }
    if(data == 'F'){
      DOWN();
    }
    if (data == 'C') {
      Position();
    }
  }
}

void Normal(){
  So1.write(177);
  So2.write(120); 
  So3.write(60);
  So4.write(90);
}
void DOWN(){
  if((d2 != 60) && (d3 != 145)){
  for (int i=0 ; i<=100; i++) {
    if (i <= 60) {
      d2=120-i;
      So2.write(d2);    //60
    }
    if(i <= 85){
      d3=60+i;
      So3.write(d3);    //145
    }
    delay(10);
  }}
}
void UP(){
  if((d2 != 120) && (d3 != 60))
  for (int i=0 ; i<=100; i++) {
    if (i <=60) {
      d2=60+i;
      So2.write(d2);    //120 deg
    }
    if(i <= 85){
      d3=145-i;
      So3.write(d3);    //60 deg
    }
    delay(10);
  }
}
void Position(){
  for (d1 = claw; d1<+177; d1++) {
    So1.write(d1);
    }
  for (d4 = bottom; d4<90; d4++) {
    So4.write(d4);
  }
  for (d4 = bottom; d4>90; d4--) {
    So4.write(d4);
  }
  claw = d1;
  bottom = d4;

}
