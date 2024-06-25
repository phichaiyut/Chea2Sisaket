void TrackRawValue(int Speed, int value,char select) {
  while (1) {
    PID1(Speed);
    
    if (Read_sumValue_sensor() > value) {
      break;
    }
  }
  TrackSelect(Speed, select);
}
void TrackTime(int Speed,int TotalTime) {
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID1(Speed);
  }
}