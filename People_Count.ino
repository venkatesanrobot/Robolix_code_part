const int irPin = 2;           // Pin connected to IR sensor
int peopleCount = 0;           // Variable to store people count

void setup() {
  pinMode(irPin, INPUT);
  Serial.begin(4800);
}

void loop() {
  int irState = digitalRead(irPin);  // Read IR sensor state
  if (irState == LOW) {
      peopleCount++;
      Serial.print("People Count: ");
      Serial.println(peopleCount);
      delay(2000);
  } else {
     peopleCount;
  }
}
