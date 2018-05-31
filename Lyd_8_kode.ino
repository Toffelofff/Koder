const int durationPin = 0;
const int button[] = {1,2,3,4,5,6,7,8}; 
const int lydPin =  13;      
    
const int lydCount = 8;

const int NOTE_C = 262;
const int NOTE_D = 294;
const int NOTE_E = 330;
const int NOTE_F = 349;
const int NOTE_G = 392;
const int NOTE_A = 440;
const int NOTE_H = 493;
const int NOTE_C2 = 523;

int varighet = 5;
int durationState = 0;
int buttonState[] = {0,0,0,0,0,0,0,0};         


void setup() {

  pinMode(lydPin, OUTPUT);
  pinMode(durationPin, INPUT_PULLUP);

  for(int pin = 0; pin < lydCount; pin++){
    pinMode(button[pin], INPUT_PULLUP);
  }
}

void loop() {
 
  durationState = digitalRead(durationPin);
  
  for(int pin = 0; pin < lydCount; pin++){
    buttonState[pin] = digitalRead(button[pin]);
  }
  
  if (durationState == LOW){
    varighet=700;
  }else{
    varighet=5;
  }
  
  if (buttonState[0] == LOW){
    tone(lydPin,NOTE_C,varighet);
}
  if (buttonState[1] == LOW){
    tone(lydPin,NOTE_D,varighet);
}
  if (buttonState[2] == LOW){
    tone(lydPin,NOTE_E,varighet);
}
  if (buttonState[3] == LOW){
    tone(lydPin,NOTE_F,varighet);
}
  if (buttonState[4] == LOW){
    tone(lydPin,NOTE_G,varighet);
}
  if (buttonState[5] == LOW){
    tone(lydPin,NOTE_A,varighet);
}
  if (buttonState[6] == LOW){
    tone(lydPin,NOTE_H,varighet);
}
  if (buttonState[7] == LOW){
    tone(lydPin,NOTE_C2,varighet);
}
}

