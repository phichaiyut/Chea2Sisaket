// #include <UNK03.h>

// #include "Motor.h"
#include <SPI.h>
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
#define NUM_SENSORS 8
#define MaxSpeed 255
#define MinSpeed -255
int LastError;
int MinValue[NUM_SENSORS];
int MaxValue[NUM_SENSORS];
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int LTurnSpdL, LTurnSpdR, TurnDelayL;
int RTurnSpdL, RTurnSpdR, TurnDelayR;
int LineColor = 0;
int LeftBaseSpeed ,RightBaseSpeed, BackLeftBaseSpeed , BackRightBaseSpeed;
float PID_Kp, PID_Kd , Kt,PID_KpB, PID_KdB ,KtB;
void setup() {
  RobotSetup();                                                                         // Setup หุ่นยนต์
   
SensorValue (58,58,59,57,58,57,59,57,681,658,650,640,512,597,635,659);  //ค่าแสง
  TurnSpeedLeft(150, 200, 30);                                                          // ค่าเลี้ยวซ้าย TurnSpeedLeft(มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TurnSpeedRight(200, 150, 30);                                                         // ค่าเลี้ยวขวา TurnSpeedRight(มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TrackLineColor(0);                                                                    //สีของเส้น 1 = ขาว , 0 = ดำ

  OK();        // รอจนกว่าจะกดปุ่ม OK
  delay(500);  // หน่วงเวลา 0.5 วินาที

  // SerialSensor();  // Serial Monitor ค่าของ Sensor
  // SerialCalibrate();  // Serial Monitor ค่าของ Sensor ที่ Calibrate แล้ว
  //CaliberateRobotSensor();  // Serial Monitor Calibrate ค่าแสงหุ่นยนต์

  // คำสั่งเจอแยก >> 'l'=เลี้ยวซ้าย ,'r'=เลี้ยวขวา ,'p'=ตรง ,'s'=หยุด  , 'L' = เลี้ยวซ้ายแบบไม่ใช้เซนเซอร์ , 'R' = เลี้ยวซ้ายแบบไม่ใช้เซนเซอร์
  // TrackCrossL(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่ซ้ายในการนับแยก
  // TrackCrossR(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่ขวาในการนับแยก
  // TrackCrossC(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่กลางในการนับแยก
  // TrackCross(100, 0.034, 0.34, 'r');   // PID จนกว่าจะเจอแยก TrackCross(Speed, Kp , Kd , 'คำสั่งเจอแยก'); 


  //TrackTime(180, 0.090, 0.90, 5500);      // PID ด้วยเวลา TrackTime(Speed, Kp , Kd, เวลา); >> 1000 = 1 วินาที
  // TrackCross(30, 0.009, 0.09, 'r');       // PID จนกว่าจะเจอสิ่งกีดขวาง TrackDistance(Speed, Kp , Kd);  >> ปรับระยะด้านข้างของเซนเซอร์ แล้วใช้ ฟังก์ชััน dodgeR(); หรือ dodgeL();
    // TrackDistance(100, 0.028 , 0.28);
  // dodgeR(); //เจอสิ่งกีดขวางแล้วหลบไปด้านขวา
  //  TrackTime(40, 0.034, 0.34, 2000);   
  // dodgeL(); //เจอสิ่งกีดขวางแล้วหลบไปด้านซ้าย
  // TurnLeft();
    //Left(180,200);                         //เลี้ยวซ้ายแบบหน่วงเวลา
    // Right(180,150);                        //เลี้ยวขวาแบบหน่วงเวลา
  
  
  // Program1();        // ทำงานโปรแกรม 1
  // Program2();        // ทำงานโปรแกรม 2
  // Program3();        // ทำงานโปรแกรม 3
  // Program4();        // ทำงานโปรแกรม 4
  round1();
  // TrackRawValue(100, 4000, 's');
}

void loop() {
  // Serial.println(Read_sumValue_sensor());
  MotorStop();  // หยุดการทำงานมอเตอร์
}
