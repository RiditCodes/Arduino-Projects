#define BLYNK_TEMPLATE_ID "TMPL328qnqfxy"
#define BLYNK_TEMPLATE_NAME "IOT Weather Station"
#define BLYNK_AUTH_TOKEN "bom0HS4IiyH3wCT4fpWREM6g391b62ku"

#include<WiFiS3.h>
#include<BlynkSimpleWifi.h>
#include<DHT.h>

#define DHTPIN 2 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "RidAdi";
char pass[] = "Ridit@123";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

  delay(2000);
}