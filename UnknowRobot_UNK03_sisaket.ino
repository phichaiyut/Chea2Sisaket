// #include <UNK03.h>

// #include "Motor.h"
#include <SPI.h>
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
#define NUM_SENSORS 8
#define MaxSpeed 255
#define MinSpeed -120
int LastError;
int MinValue[NUM_SENSORS];
int MaxValue[NUM_SENSORS];
uint8_t F_PIN[NUM_SENSORS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int F[NUM_SENSORS];
int LTurnSpdL, LTurnSpdR, TurnDelayL;
int RTurnSpdL, RTurnSpdR, TurnDelayR;
int LineColor = 0;
void setup() {
  RobotSetup();                                                                         // Setup หุ่นยนต์
  SensorValue(39, 38, 39, 39, 37, 38, 38, 38, 710, 650, 749, 688, 640, 630, 667, 636);  //ค่าแสง
  TurnSpeedLeft(150, 200, 50);                                                          // ค่าเลี้ยวซ้าย TurnSpeedLeft(มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TurnSpeedRight(200, 150, 50);                                                         // ค่าเลี้ยวขวา TurnSpeedRight(มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TrackLineColor(1);                                                                    //สีของเส้น 1 = ขาว , 0 = ดำ

  OK();        // รอจนกว่าจะกดปุ่ม OK
  delay(500);  // หน่วงเวลา 0.5 วินาที

  // SerialSensor();  // Serial Monitor ค่าของ Sensor
  // SerialCalibrate();  // Serial Monitor ค่าของ Sensor ที่ Calibrate แล้ว
  // CaliberateRobotSensor();  // Serial Monitor Calibrate ค่าแสงหุ่นยนต์

  // คำสั่งเจอแยก >> 'l'=เลี้ยวซ้าย ,'r'=เลี้ยวขวา ,'p'=ตรง ,'s'=หยุด  , 'L' = เลี้ยวซ้ายแบบไม่ใช้เซนเซอร์ , 'R' = เลี้ยวซ้ายแบบไม่ใช้เซนเซอร์
  // TrackCrossL(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่ซ้ายในการนับแยก
  // TrackCrossR(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่ขวาในการนับแยก
  // TrackCrossC(100, 0.034, 0.34, 'r');  // ใช้เซนเซอร์คู่กลางในการนับแยก
  // TrackCross(100, 0.034, 0.34, 'r');   // PID จนกว่าจะเจอแยก TrackCross(Speed, Kp , Kd , 'คำสั่งเจอแยก'); 


  // TrackTime(120, 0.034, 0.34, 1000);      // PID ด้วยเวลา TrackTime(Speed, Kp , Kd, เวลา); >> 1000 = 1 วินาที
  // TrackDistance(100, 0.034, 0.34);       // PID จนกว่าจะเจอสิ่งกีดขวาง TrackDistance(Speed, Kp , Kd);  >> ปรับระยะด้านข้างของเซนเซอร์ แล้วใช้ ฟังก์ชััน dodgeR(); หรือ dodgeL();
  //dodgeR(); //เจอสิ่งกีดขวางแล้วหลบไปด้านขวา
  //dodgeL(); //เจอสิ่งกีดขวางแล้วหลบไปด้านซ้าย

    //Left(180,200);                         //เลี้ยวซ้ายแบบหน่วงเวลา
    //Right(180,200);                        //เลี้ยวขวาแบบหน่วงเวลา
  
  
  // Program1();        // ทำงานโปรแกรม 1
  // Program2();        // ทำงานโปรแกรม 2
  // Program3();        // ทำงานโปรแกรม 3
  // Program4();        // ทำงานโปรแกรม 4
  
}

void loop() {
  MotorStop();  // หยุดการทำงานมอเตอร์
}
