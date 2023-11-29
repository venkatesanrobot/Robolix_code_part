#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

Servo rfidServo;

MFRC522 mfrc522(10, 9); //ss_pin = 10 & rst pin = 9
bool state = false;
const char* cardID="965cb96";
const char* cardNames="ROBOLIX";

void setup() {
  Serial.begin(9600);
  rfidServo.attach(6);
  rfidServo.write(0);
  SPI.begin();
  mfrc522.PCD_Init();
}

// the loop function runs over and over again forever
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    bool cardFound = false;
    if (strcmp(cardID, cardUID.c_str())==0)
    {
      state=!state;
      if (state == true) 
        {
          rfidServo.write(180);
          Serial.print("welcome, ");
          Serial.println(cardNames);
          Serial.println("Please close the door...");
          delay(500);
        }
      else 
        {
          rfidServo.write(0);
          Serial.print("Have a Nice day... ");
          Serial.println(" (´◡`) ");
          delay(500);
        }
      cardFound = true;
    }

    if (!cardFound) {
      Serial.println("You are not authorized person (►__◄) .");
    }
  mfrc522.PICC_HaltA();
  }
}