int lamp = 7;

void setup() {
  pinMode(lamp, OUTPUT);
}

void loop() {
  digitalWrite(lamp, HIGH);
  delay(500);
  digitalWrite(lamp, LOW);
  delay(500);
}
