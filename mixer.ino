#include <ESP32Servo.h>
 
Servo myservo; 

const int custom = 10000; //enter custom duration in ms
const int servoPin = 2;
int cond = 1;
 
void setup() {
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
}
 
void loop() {
 while(cond){
   for(int pos = 0; pos < 360; pos += 1) {
 myservo.write(pos); 
 delay(15);
 }
 }
 delay(custom);
cond = 0;
}
