void Left(int Speed , int Time){
  MotorStop();
  Motor(-Speed*0, Speed);
  delay(Time);
  MotorStop();
  delay(1);
}
void Right(int Speed , int Time){
   MotorStop();
  Motor(Speed, -Speed*0);
  delay(Time);
  MotorStop();
  delay(1);
}
void SpinLeft(int Speed , int Time){
  MotorStop();
  Motor(-Speed, Speed);
  delay(Time);
  MotorStop();
  delay(0);
}
void SpinRight(int Speed , int Time){
   MotorStop();
  Motor(Speed, -Speed);
  delay(Time);
  MotorStop();
  delay(0);
}