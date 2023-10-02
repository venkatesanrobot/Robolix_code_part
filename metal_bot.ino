//#include <BTAddress.h>
//#include <BTAdvertisedDevice.h>
//#include <BTScan.h>
//#include <BluetoothSerial.h>
#include <DHT.h>
const int sensorPin = A6;
const int flameSensorPin = A0;
const int soundSensorPin = 8;  // Digital pin to which the sound sensor is connected


#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int L1=2;
int L2=3;
int R1=4;
int R2=5;

void setup() {
  dht.begin();
  pinMode(L1,OUTPUT);   //left motors  forward
  pinMode(L2,OUTPUT);   //left motors reverse
  pinMode(R1,OUTPUT);   //right  motors forward
  pinMode(R2,OUTPUT);   //right motors reverse
  pinMode(flameSensorPin, INPUT);
  pinMode(sensorPin, INPUT);
  pinMode(soundSensorPin, INPUT);
  Serial.begin(9600);
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
      digitalWrite(R2,LOW);
      delay(1000);
      Magnetic_Sensor();
      break;
    case 'B': 
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      delay(1000);
      Magnetic_Sensor();
      break;
    case 'L': 
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      delay(1000);
      Magnetic_Sensor();
      break;
    case 'R': 
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
      delay(1000);
      Magnetic_Sensor();
      break;
    default:
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,LOW);
      Magnetic_Sensor();
      
  }
  delay(10);
}
else {
  Magnetic_Sensor();
}

}




void Magnetic_Sensor() {
  int sensorValue = analogRead(sensorPin);  // Read the sensor value
  Serial.print("    Magnetic value: ");
  Serial.print(sensorValue);
  delay(5); 
  Sound_Sensor();
}

void fire_Sensor() {
  int flameValue = analogRead(flameSensorPin); 
  int flame = map(flameValue,1023,0,0,100);
    Serial.print("                Fire sensor: "); 
  Serial.print(flame);
  delay(5);
  DHTtemp();
}

void DHTtemp() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float temperatureF = temperatureC * 1.8 + 32;
  Serial.print("                Humidity: ");
  Serial.print(humidity);
  Serial.print("%               Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");
  
}

void Sound_Sensor() {
  int soundValue = digitalRead(soundSensorPin);
  Serial.print("                soundValue: ");
  Serial.print(soundValue);
  delay(5);
  fire_Sensor();
}


