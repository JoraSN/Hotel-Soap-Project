#include <Stepper.h>

const int stepsPerRevolution = 523, steps = 175;

// counter clockwise Stepper object
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// clockwise Stepper object
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

#define power 6
#define rainLevelSensor 7
#define button 5
#define LED_Buzzer 4

void setup() {
  pinMode(power, OUTPUT);
  pinMode(rainLevelSensor, INPUT);
  digitalWrite(power, HIGH);
  
  myStepper.setSpeed(60);
  myStepper2.setSpeed(20);
  
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_Buzzer, OUTPUT);
  
}

void loop(){
  int but = digitalRead(button);
  int n = digitalRead(rainLevelSensor);
  if(but == LOW){
  if(n){
  myStepper.step(stepsPerRevolution);
  delay(5);
  while(n){
  n = digitalRead(rainLevelSensor);
  delay(5);
  }
  for(int i = 0; i < 3; i++){
  myStepper2.step(steps);
  delay(5);
  }
  tone(LED_Buzzer, 1000);
  delay(3000);
  noTone(LED_Buzzer);
  }
  else{
  tone(LED_Buzzer, 1000);
  delay(3000);
  noTone(LED_Buzzer);
  }
  }
}
