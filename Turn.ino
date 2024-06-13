void Left(int Speed , int Time){
  MotorStop();
  Motor(-Speed, Speed);
  delay(Time);
  MotorStop();
  delay(0);
}
void Right(int Speed , int Time){
   MotorStop();
  Motor(Speed, -Speed);
  delay(Time);
  MotorStop();
  delay(0);
}