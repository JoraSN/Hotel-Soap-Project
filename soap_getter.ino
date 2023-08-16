#include <Stepper.h>

const int stepsPerRevolution = 350, steps = 175;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  digitalWrite(6, HIGH);
  
  myStepper.setSpeed(60);
  myStepper2.setSpeed(20);
  
  Serial.begin(9600);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  
}

void loop(){
  int but = digitalRead(5);
  int n = digitalRead(7);
  if(but == LOW){
  if(n){
  for(int i = 0; i < 1; i++){
  myStepper.step(stepsPerRevolution);
  delay(5);
  myStepper.step(173);
  }
  n = 1;
  while(n){
  n = digitalRead(7);
  delay(5);
  }
  for(int i = 0; i < 3; i++){
  myStepper2.step(steps);
  delay(5);
  }
  tone(4, 1000);
  delay(3000);
  noTone(4);
  }
  else{
  tone(4, 1000);
  delay(3000);
  noTone(4);
  }
  }
}
