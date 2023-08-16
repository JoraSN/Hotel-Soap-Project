#include <ESP32Servo.h>
 
Servo myservo; 
 
const int servoPin = 2;
 
void setup() {
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
}
 
void loop() {
   for(int pos = 0; pos < 360; pos += 1) {
 myservo.write(pos); 
 delay(15);
 }

}
