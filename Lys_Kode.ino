const int Sensor = A0;
const int buttonPin = 2; 
const int buttonPin2 = 3;

const int lys[] = {6,7,8,9,10,11,12,13};   

const int BluePin = 15;
const int GreenPin = 16;
const int RedPin = 17; 
const int PowerLight = 18;

const int lysCount = 8;

int Mode = 0;
int pushCount1 = 0;
int SensoReading = 0;
int on = 0;

void setup() {
  
  for(int pin = 0; pin < lysCount; pin++){
    pinMode(lys[pin], OUTPUT);
  }
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(PowerLight, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(Sensor, INPUT);

  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), ModeChanger, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), PowerButton, FALLING);
}

void loop() {
  on=(pushCount1==1);
  setColor(LOW,LOW,LOW);
  digitalWrite(lys[0],LOW);
  digitalWrite(lys[1],LOW);
  digitalWrite(lys[2],LOW);
  digitalWrite(lys[3],LOW);
  digitalWrite(lys[4],LOW);
  digitalWrite(lys[5],LOW);
  digitalWrite(lys[6],LOW);
  digitalWrite(lys[7],LOW);
  digitalWrite(PowerLight,LOW);

  unsigned long Time = millis();
  static unsigned long Last_Time = 0;
  
  if (Time - Last_Time > 500){
    SensoReading=analogRead(Sensor);
    Serial.println(SensoReading);
    Last_Time=Time;
  }

  if(on){
    digitalWrite(PowerLight,HIGH);
  }

  if (on){
    if (Mode==1){
      setColor(HIGH,LOW,LOW);
      if (SensoReading>600){
        for(int pin = 0; pin < lysCount; pin++){
        digitalWrite(lys[pin],HIGH);
        delay(500);
        digitalWrite(lys[pin],LOW);
        }
      }
    }
  }

  if (on){
    if (Mode==2){
      setColor(LOW,HIGH,LOW);
      if (SensoReading>600){
        for(int pin = 7; pin >= 0; pin--){
          digitalWrite(lys[pin],HIGH);
          delay(100);
          digitalWrite(lys[pin],LOW);
        }
      }
    }
  }
  
  if (on){
    if (Mode==3){
      setColor(LOW,LOW,HIGH);
      if (SensoReading>600){
        for(int pin = 0; pin < lysCount; pin++){
          digitalWrite(lys[pin],HIGH);
          delay(100);
          digitalWrite(lys[pin],LOW);  
          }
        for(int pin = 7; pin >= 0; pin--){
          digitalWrite(lys[pin],HIGH);
          delay(100);
          digitalWrite(lys[pin],LOW); 
        }
      }
    }
  }
  
  if (on){  
    if (Mode==4){
      setColor(HIGH,HIGH,HIGH);
      if (SensoReading>600){
        for(int pin = 0; pin < lysCount; pin++){
        digitalWrite(lys[pin],HIGH);
        }
      }
    }
  }

  if (Mode>4){
    Mode=0;
  }

  if (pushCount1 > 1){
    pushCount1=0;
  }
}

void ModeChanger(){
  
  unsigned long Time = millis();
  static unsigned long Last_Time = 0;
  
  if (Time - Last_Time > 500){
    if (pushCount1==1){
    Mode++; 
    Serial.println(Mode);
  }
}
Last_Time = Time;
}

void PowerButton(){
  
  unsigned long Time = millis();
  static unsigned long Last_Time = 0;
  
  if (Time - Last_Time > 500){
    pushCount1++;
    Serial.println(pushCount1);
  }
  Last_Time = Time;
}

void setColor(int Blue, int Green, int Red){
  digitalWrite(BluePin, Blue);
  digitalWrite(GreenPin, Green);
  digitalWrite(RedPin, Red);
}


