

void Beep(int delayb) {
  digitalWrite(8, 1);
  delay(delayb);
  digitalWrite(8, 0);
  delay(10);
}
void RobotSetup() {
  Serial.begin(9600);
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  Beep(100);
  delay(50);
  Beep(100);
}

void TrackLineColor(int Col) {
  LineColor = Col;
}

void TurnSpeedLeft(int l, int r, int de) {
  LTurnSpdL = l;
  LTurnSpdR = r;
  TurnDelayL = de;
}

void TurnSpeedRight(int l, int r, int de) {
  RTurnSpdL = l;
  RTurnSpdR = r;
  TurnDelayR = de;
}

void ReadSensor() {
  adc.begin(13, 11, 12, 10);
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    F[_sensor] = adc.readADC(F_PIN[_sensor]);
  }
}

int analog(int ch){
	ReadSensor();
	return F[ch];
}


void ReadCalibrate() {
  if (LineColor == 0) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      unsigned int calmin, calmax;
      int x = 0;
      calmin = MinValue[i];
      calmax = MaxValue[i];
      x = map(F[i], calmin, calmax, 0, 1000);
      if (x < 0) x = 0;
      if (x > 1000) x = 1000;
      F[i] = x;
    }
  } else {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      unsigned int calmin, calmax;
      int x = 0;
      calmin = MinValue[i];
      calmax = MaxValue[i];
      x = map(F[i], calmin, calmax, 0, 1000);
      x = 800 - x;
      if (x < 0) x = 0;
      if (x > 1000) x = 1000;
      F[i] = x;
    }
  }
}

void CalibrateSensor(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    MinValue[i] = 1023;
    MaxValue[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      MinValue[i] = (F[i] <= MinValue[i] ? F[i] : MinValue[i]);
      MaxValue[i] = (F[i] >= MaxValue[i] ? F[i] : MaxValue[i]);
    }
    delay(pauseTime);
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    MinValue[i] += 20;
    MaxValue[i] -= 80;
  }
}

void SensorValue(uint16_t minF0, uint16_t minF1, uint16_t minF2, uint16_t minF3, uint16_t minF4, uint16_t minF5, uint16_t minF6, uint16_t minF7, uint16_t maxF0, uint16_t maxF1, uint16_t maxF2, uint16_t maxF3, uint16_t maxF4, uint16_t maxF5, uint16_t maxF6, uint16_t maxF7) {
  MinValue[0] = minF0;
  MinValue[1] = minF1;
  MinValue[2] = minF2;
  MinValue[3] = minF3;
  MinValue[4] = minF4;
  MinValue[5] = minF5;
  MinValue[6] = minF6;
  MinValue[7] = minF7;

  MaxValue[0] = maxF0;
  MaxValue[1] = maxF1;
  MaxValue[2] = maxF2;
  MaxValue[3] = maxF3;
  MaxValue[4] = maxF4;
  MaxValue[5] = maxF5;
  MaxValue[6] = maxF6;
  MaxValue[7] = maxF7;
}

void OK() {
  while (1) {
    if (analogRead(A7) < 700) {
      break;
    }
  }
  Beep(100);
}

void swOK() {
  while (1) {
    if (analogRead(A7) < 200) {
      break;
    }
  }
  Beep(100);
}

int OK_PUSH() {
  if (analogRead(A7) > 200) return 0;
  else {
    return 1;
  }
}


void CaliberateRobotSensor() {
  Serial.println("Press OK to start caribrate Front Sensor");
  OK();
  Serial.println("Caribrating");
  Beep(100);
  delay(500);
  CalibrateSensor(20, 200);
  Beep(100);
  delay(500);
  Serial.println("Finish");
  Serial.println("  ");
  Serial.print("SensorValue (");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MinValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.print(",");
  }
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MaxValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println(");");
  }
  while (1)
    ;
}


void SerialSensor() {
  while (1) {
    ReadSensor();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
    if (OK_PUSH() == 1) {
      Beep(40);
      break;
    }
  }
}

void SerialCalibrate() {
  while (1) {
    ReadCalibrate();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(100);
    if (OK_PUSH() == 1) {
      Beep(40);
      break;
    }
  }
}

void TurnLeft() {
  Motor(-LTurnSpdL, LTurnSpdR);
  delay(TurnDelayL);
  while (1) {
    Motor(-LTurnSpdL, LTurnSpdR);
    ReadCalibrate();
    if (F[0] >= 500) {
      MotorStop();
      break;
    }
  }
}

void TurnRight() {
  Motor(RTurnSpdL, -RTurnSpdR);
  delay(TurnDelayR);
  while (1) {
    Motor(RTurnSpdL, -RTurnSpdR);
    ReadCalibrate();
    if (F[7] >= 500) {
      MotorStop();
      break;
    }
  }
}


int readPosition(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrate();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void PID(int Speed, float Kp, float Kd) {
  int Pos = readPosition(300, 50);
  int Error = Pos - ((NUM_SENSORS - 1) * 1000 / 2);
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError));
  LastError = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
  if (LeftPower < MinSpeed) LeftPower = MinSpeed;
  if (RightPower > MaxSpeed) RightPower = MaxSpeed;
  if (RightPower < MinSpeed) RightPower = MinSpeed;
  Motor(LeftPower, RightPower);
}

void TrackSelect(int spd, char x) {
  if (x == 's') {
    MotorStop();
  } else if (x == 'p') {
    Motor(spd, spd);
    delay(30);
    while (1) {
      Motor(spd, spd);
      ReadCalibrate();
      if (F[0] < 550 && F[7] < 550) {
        Motor(spd, spd);
        delay(5);
        break;
      }
    }

  } else if (x == 'l') {
    TurnLeft();
  } else if (x == 'r') {
    TurnRight();
  }
    else if (x == 'L') {
    Left(180,150);
  } else if (x == 'R') {
    Right(180,150);
  }
}

void TrackCross(int Speed, float Kp, float Kd, char select) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if ((F[1] > 550 && F[6] > 550) || (F[0] > 550 && F[3] > 550) || (F[4] > 550 && F[7] > 550)) {
	   
      break;
    }
  }
Beep(10);
  TrackSelect(Speed, select);
}

void TrackCrossC(int Speed, float Kp, float Kd, char select) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if ((F[1] > 550 && F[6] > 550)) {
      break;
    }
  }
	 Beep(10);
  TrackSelect(Speed, select);
}

void TrackCrossR(int Speed, float Kp, float Kd, char select) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if ((F[4] > 550 && F[7] > 550)) {
      break;
    }
  }
	 Beep(10);
  TrackSelect(Speed, select);
}

void TrackCrossL(int Speed, float Kp, float Kd, char select) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if ((F[0] > 550 && F[3] > 550)) {
      break;
    }
  }
	 Beep(10);
  TrackSelect(Speed, select);
}

void TrackCrossLeftTime(int Speed, float Kp, float Kd, int delay) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[0] > 550 ) {
      break;
    }
  }
  Left(180 ,delay);
}

void TrackDistance(int Speed, float Kp, float Kd) {
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (analogRead(A0) < 550) {
      MotorStop();
	     Beep(10);
      break;
    }
  }
}

void TrackDist() {
  while (analogRead(A0) < 550) {
      MotorStop();
	     Beep(10);
  }
}

void TrackTime(int Speed, float Kp, float Kd, int TotalTime) {
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID(Speed, Kp, Kd);
  }
	 Beep(10);
}
