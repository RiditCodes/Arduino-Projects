#define BLYNK_TEMPLATE_NAME "IOT Servo"
#define BLYNK_TEMPLATE_ID "TMPL3hW3dTbQ4"
#define BLYNK_AUTH_TOKEN "FTOkEQRc_oTVk7V_Ap1_F6ca52DjYUZ-"

#include<Servo.h>
#include<WiFiS3.h>
#include<BlynkSimpleWifi.h>

int servoPin = 3;
Servo servo1;

char ssid[] = "RidAdi";
char pass[] = "Ridit@123";

BLYNK_WRITE(V0){
  int pinValue = param.asInt();

  servo1.write(pinValue);
}

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);

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
}
