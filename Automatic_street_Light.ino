const int ldrPin = A0;       // Pin connected to LDR
const int ledPin = 2;        // Pin connected to LED

int ldrThreshold = 580;      // Threshold value for light intensity

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read LDR value
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < ldrThreshold) {
    digitalWrite(ledPin, LOW);  // Turn OFF the LED
    Serial.println("Street light is ON");
  } else {
    digitalWrite(ledPin, HIGH);   // Turn ON the LED
    Serial.println("Street light is OFF");
  }
  
  delay(1000);  // Delay for 1 second
}
