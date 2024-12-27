#define BLYNK_TEMPLATE_ID "TMPL3sPb-Yw7P"
#define BLYNK_TEMPLATE_NAME "IOT Peltier"
#define BLYNK_AUTH_TOKEN "em2KsbWOehv0sAZReH29ATjsyRVP65fj"

#define BLYNK_SERIAL Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char ssid[] = "iPhone";
char password[] = "hanu54321";

const int relayPin = D1; 
BLYNK_WRITE(V1) {  // Virtual Pin 1 controls the relay
  int pinValue = param.asInt();  // Get the state of the button (1 or 0)
  
  if(pinValue == 1) {
    digitalWrite(relayPin, HIGH);  // Turn on the relay
  } else {
    digitalWrite(relayPin, LOW);   // Turn off the relay
  }
}

void setup() {
  // Start the serial monitor
  Serial.begin(115200);

  // Set the relayPin as an output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Make sure the relay is off initially

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi.SSID().c_str(), WiFi.psk().c_str());
}

void loop() {
  Blynk.run();  // Run Blynk commands
}