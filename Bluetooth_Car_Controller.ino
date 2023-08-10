void setup() {
  pinMode(2,OUTPUT);   //left motors  forward
  pinMode(3,OUTPUT);   //left motors reverse
  pinMode(4,OUTPUT);   //right  motors forward
  pinMode(5,OUTPUT);   //right motors reverse
  Serial.begin(9600);
}

void loop() {
if(Serial.available())
{
  switch(Serial.read())
  {
    case 'F': 
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);;
      break;
    case 'B': 
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      break;
    case 'L': 
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      break;
    case 'R': 
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      break;
    default:
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
  }
  delay(10);
}

}
