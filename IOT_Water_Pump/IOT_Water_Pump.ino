#define BLYNK_TEMPLATE_ID "TMPL3CptHTfPO"
#define BLYNK_TEMPLATE_NAME "Water Pump"

#define BLYNK_SERIAL Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
// Replace with your network credentials  
char ssid[] = "iPhone";
char password[] = "hanu54321";

// Blynk authentication token (Copy this from the Blynk app)
char auth[] = "4t0NqCYQ3FP8pFjQqDQ6zOlqZlnPqD6i";

// Pin connected to relay
const int relayPin = D1;  // Use GPIO pin D1 (can change depending on your board)

BLYNK_WRITE(V1) {  // Virtual Pin 1 controls the relay
  int pinValue = param.asInt();  // Get the state of the button (1 or 0)
  
  if(pinValue == 1) {
    digitalWrite(relayPin, HIGH);  // Turn on the relay (water pump)
  } else {
    digitalWrite(relayPin, LOW);   // Turn off the relay (water pump)
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
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
}

void loop() {
  Blynk.run();  // Run Blynk commands
}
