char t;
 
void setup() {
pinMode(2,OUTPUT);   //left motors  forward
pinMode(3,OUTPUT);   //left motors reverse
pinMode(4,OUTPUT);   //right  motors forward
pinMode(5,OUTPUT);   //right motors reverse
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);

}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
 
else{      //STOP (all motors stop)
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}
delay(10);
}