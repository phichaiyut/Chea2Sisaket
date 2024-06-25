void TuneMotor(int BaseSpeed){
  
  
  if(BaseSpeed<=40)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.011;       //forward PID
    PID_Kd = 0.11;
    Kt = 10;
    PID_KpB = 0.011;       //Backward PID
    PID_KdB = 0.11;
    KtB = 10;
  }
  else if(BaseSpeed<=50)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.014;       //forward PID
    PID_Kd = 0.14;
    Kt = 10;
    PID_KpB = 0.014;       //Backward PID
    PID_KdB = 0.14;
    KtB = 10;
  }
  else if(BaseSpeed<=60)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.017;       //forward PID
    PID_Kd = 0.17;
    Kt = 10;
    PID_KpB = 0.017;       //Backward PID
    PID_KdB = 0.17;
    KtB = 10;
  }
  else if(BaseSpeed<=70)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.030;       //forward PID
    PID_Kd = 0.30;
    Kt = 10;
    PID_KpB = 0.030;       //Backward PID
    PID_KdB = 0.30;
    KtB = 10;
  }
  else if(BaseSpeed<=80)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.025;       //forward PID
    PID_Kd = 0.25;
    Kt = 10;
    PID_KpB = 0.040;       //Backward PID
    PID_KdB = 0.40;
    KtB = 10;
  }
  else if(BaseSpeed<=90)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=100)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.035;       //forward PID
    PID_Kd = 0.35;
    Kt = 10;
    PID_KpB = 0.060;       //Backward PID
    PID_KdB = 0.60;
    KtB = 10;
  }
   else if(BaseSpeed<=110)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=120)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.034;       //forward PID
    PID_Kd = 0.34;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=130)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=140)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=150)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=160)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=170)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=180)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=190)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
   else if(BaseSpeed<=200)
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp = 0.050;       //forward PID
    PID_Kd = 0.50;
    Kt = 10;
    PID_KpB = 0.050;       //Backward PID
    PID_KdB = 0.50;
    KtB = 10;
  }
  else
  {
    LeftBaseSpeed = BaseSpeed-0;
    RightBaseSpeed = BaseSpeed-0;
    BackLeftBaseSpeed = BaseSpeed-0;
    BackRightBaseSpeed = BaseSpeed-0;
    PID_Kp =0.25;       //forward PID
    PID_Kd = 4;
    Kt = 10;
    PID_KpB = 0.25;       //Backward PID
    PID_KdB = 0.25;
    KtB = 15;
  }



}