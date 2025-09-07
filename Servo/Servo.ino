#include <Servo.h>

int servoPin = 3;
int potPin = 0;
int val;
 
Servo Servo1; 
void setup() {  
   Servo1.attach(servoPin); 
}
void loop(){
   val = analogRead(potPin);
   val = map(val, 0, 1023, 0, 180);
   Servo1.write(val);
   delay(15);
}