#include<DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print(F("Humidity: "));
  Serial.print(hum);
  Serial.print(F(" %\t"));
  Serial.print(F("Temperature: "));
  Serial.print(temp);
  Serial.println(F(" *C"));

  delay(2000);
}
