int L1 = 2;
int L2 = 3;
int R1 = 4;
int R2 = 5;
int Up = 6;
int Down = 7;


void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);  
  pinMode(R1, OUTPUT);  
  pinMode(R2, OUTPUT);  
  pinMode(Up, OUTPUT);  
  pinMode(Down, OUTPUT); 
  Serial.begin(9600); 
  if(Serial.available())
  {
    Serial.println("Connected");
  }
}

void loop() {
if(Serial.available())
{
  switch(Serial.read())
  {
    case 'F': 
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);;
      break;
    case 'B': 
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      break;
    case 'L': 
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      break;
    case 'R': 
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
      break;
    case 'V': 
      digitalWrite(Up,HIGH);
      digitalWrite(Down,LOW);
      delay(80);
      break;
    case 'X': 
      digitalWrite(Up,LOW);
      digitalWrite(Down,HIGH);
      delay(80);
      break;
      
    default:
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,LOW);
      digitalWrite(Up,LOW);
      digitalWrite(Down,LOW);
  }
  delay(10);
}

}
