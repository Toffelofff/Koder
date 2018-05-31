#include <Stepper.h>

const int stepsPerRevolution = 200; 

const int potentiometer = 0;
const int buttonPin = 3;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

int pushCount = 0;
int SensoReading = 0;
int Speed = 0;
int on = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(potentiometer, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), Power_Button, FALLING);
}

void loop() {
  on = (pushCount==1);
  
  SensoReading = analogRead(potentiometer);
  Speed = map(SensoReading, 0, 1023, 0, 110); 

  if (on){
    if (Speed > 10) {
      myStepper.setSpeed(Speed);
      myStepper.step(stepsPerRevolution/100);
    }
  }
  if (on){
    if (Speed <= 10){
       myStepper.step(0);
  }
}
  if (pushCount > 1){
    pushCount=0;
  }
}

void Power_Button(){
  
  static unsigned long Last_Time = 0;
  unsigned long Time = millis();
  
  if (Time - Last_Time > 500){
    pushCount++;
  }
  Last_Time = Time;
}

