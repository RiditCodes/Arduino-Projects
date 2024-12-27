#define BLYNK_TEMPLATE_ID "TMPL3pe6kYnEs"
#define BLYNK_TEMPLATE_NAME "IOT Vents"
#define BLYNK_AUTH_TOKEN "jx4-o3_BbvwXx6mqITM7oixgt0EJM_Gt"

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "iPhone";
char pass[] = "hanu54321";

// Create Servo objects
Servo servo1;
Servo servo2;

// Servo control pins
#define SERVO1_SIGNAL_PIN D1
#define SERVO2_SIGNAL_PIN D2
const int relayPin = D3; 

// Variables to store servo positions
int servo1Angle = 0; // Initial position
int servo2Angle = 0;

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set the relayPin as an output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Make sure the relay is off initially

  // Attach servos to signal pins
  servo1.attach(SERVO1_SIGNAL_PIN);
  servo2.attach(SERVO2_SIGNAL_PIN);

  // Initialize servos at 0 degrees
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
}

BLYNK_WRITE(V1) {
  int switchState = param.asInt(); // Get switch state (0 or 1)
  
  if (switchState == 1) {
    // Switch is ON, increase angles by 90 degrees
    servo1Angle = 180;
    servo2Angle = 180;
  } else {
    // Switch is OFF, reset angles to 0 degrees
    servo1Angle = 0;
    servo2Angle = 0;
  }
  
  // Move servos to the desired positions
  servo1.write(servo1Angle);
  servo2.write(servo2Angle);
}

BLYNK_WRITE(V0) {  // Virtual Pin 1 controls the relay
  int pinValue = param.asInt();  // Get the state of the button (1 or 0)
  
  if(pinValue == 1) {
    digitalWrite(relayPin, HIGH);  // Turn on the relay
  } else {
    digitalWrite(relayPin, LOW);   // Turn off the relay
  }
}

void loop() {
  Blynk.run(); // Run Blynk
}