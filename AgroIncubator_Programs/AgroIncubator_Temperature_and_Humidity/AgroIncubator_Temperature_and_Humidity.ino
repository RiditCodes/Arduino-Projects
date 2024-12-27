#include <Wire.h>                    // Required for I2C communication with the OLED
#include <Adafruit_GFX.h>             // Required for graphics functions on the OLED
#include <Adafruit_SSD1306.h>         // Required for OLED screen control
#include <DHT.h>                      // Library for DHT11 sensor

// Define DHT11 sensor pin
#define DHTPIN 2            // Data pin connected to the DHT11 sensor
#define DHTTYPE DHT11       // Define the sensor type as DHT11

// Create DHT object
DHT dht(DHTPIN, DHTTYPE);

// OLED display settings (change the address if needed)
#define SCREEN_WIDTH 128    // OLED display width
#define SCREEN_HEIGHT 64    // OLED display height
#define OLED_RESET    -1    // Reset pin not used for this display
#define OLED_ADDR      0x3D  // Default I2C address for most OLED screens (0x3C or 0x3D)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the DHT11 sensor
  dht.begin();
  
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Infinite loop if initialization fails
  }

  // Clear the display buffer
  display.clearDisplay();
  
  // Display startup message
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(F("Initializing..."));
  display.display();
  delay(2000);  // Wait for 2 seconds
}

void loop() {
  // Read temperature and humidity from the DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Check if the readings are valid (not NaN)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Sensor Error!"));
    display.display();
  } else {
    // Display the readings on the OLED screen
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F(" %\t"));
    Serial.print(F("Temperature: "));
    Serial.print(temperature);
    Serial.println(F(" *C"));
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Temperature: ");
    display.setTextSize(2);
    display.setCursor(0, 10);
    display.print(temperature);
    display.print(" ");
    display.setTextSize(1);
    display.cp437(true);
    display.write(167);
    display.setTextSize(2);
    display.print("C");
 
    display.setTextSize(1);
    display.setCursor(0, 35);
    display.print("Humidity: ");
    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print(humidity);
    display.print(" %");
    
    // Display the information
    display.display();
  }

  // Wait for 2 seconds before reading again
  delay(2000);
}