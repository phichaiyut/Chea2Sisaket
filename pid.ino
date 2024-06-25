int Read_sumValue_sensor(){
	int x = 0;
    if (LineColor == 0) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      unsigned int calmin, calmax;
      
      calmin = MinValue[i];
      calmax = MaxValue[i];
      x += map(F[i], calmin, calmax, 0, 1000);
        }
  } else {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      unsigned int calmin, calmax;
      
      calmin = MinValue[i];
      calmax = MaxValue[i];
      x += map(F[i], calmin, calmax, 0, 1000);
      }
     
  } 
  return x;
}

void PID1(int Speed) {
  TuneMotor(Speed);
  int Pos = readPosition(300, 50);
  int Error = Pos - ((NUM_SENSORS - 1) * 1000 / 2);
  int PID_Value = (PID_Kp * Error) + (PID_Kd * (Error - LastError));
  LastError = Error;
  int LeftPower = LeftBaseSpeed + PID_Value;
  int RightPower = RightBaseSpeed - PID_Value;
  if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
  if (LeftPower < MinSpeed) LeftPower = MinSpeed;
  if (RightPower > MaxSpeed) RightPower = MaxSpeed;
  if (RightPower < MinSpeed) RightPower = MinSpeed;
  Motor(LeftPower, RightPower);
}
  
