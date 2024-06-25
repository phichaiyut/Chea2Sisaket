void dodgeR(){
  Motor(180,-100);  delay(90);
  //Motor(47,70);  delay(350);
  Motor(50,130);  delay(300);
  while(1){
    ReadCalibrate();
    if (F[0] >= 600){

      break;
    }
    Motor(45,125);
}

}

void dodgeL(){
  Motor(-40,70);  delay(90);
  //Motor(70,40);  delay(350);
  Motor(50,35);  delay(200);
  while(1){
    ReadCalibrate();
    if (F[7] >= 600){

      break;
    }
    
}
Motor(50,30);
}