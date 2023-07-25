/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/
#define BLYNK_TEMPLATE_ID "TMPL3TNgyAtil"
#define BLYNK_TEMPLATE_NAME "Agriculture"
#define BLYNK_AUTH_TOKEN "mv9S0OeYjdMfZMJqj7YXP8NNAJuiS0FZ"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
BlynkTimer timer;



// Data wire is conntec to the Arduino digital pin 4
#define ONE_WIRE_BUS D4
#define M1_PIN D0
#define M2_PIN D1
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy M312698";
char pass[] = "opky7770";



void setup()
{
   
  // Debug console
  Serial.begin(115200);
  pinMode(M1_PIN , OUTPUT);
  pinMode(M2_PIN , OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  sensors.begin();

}

void loop()
{
  Blynk.run();
  
  sensors.requestTemperatures();
  int h=sensors.getTempCByIndex(0);


  int potvalue=analogRead(A0);
 
  Blynk.virtualWrite(V0,potvalue);
  delay(100);
  Blynk.virtualWrite(V1,h);
  delay(100);

  if(potvalue < 40){
    digitalWrite( M1_PIN, HIGH);
    digitalWrite( M2_PIN, LOW);
    Serial.println("pump ON");
  }
  else {
    digitalWrite( M1_PIN, LOW);
    digitalWrite( M2_PIN, LOW);
    Serial.println("pump OFF");
  }
  
}