int count = 1;
int waitTime = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Your counter is at: ");
  Serial.println(count);
  count += 1;
  delay(waitTime);
}