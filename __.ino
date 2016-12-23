int period = 5;
//float t1,t2,t3;


//--------------------红外
#include<IRremote.h>
#define IR_PIN 10
decode_results results;

IRrecv irrecv(IR_PIN);
#define irhead 33464415
#define irback 33478695
#define irleft 33480735
#define irright 33460335


//-------------------------------电机部分
//D6，D8控制1A，1B的电机
#define OUT1A 6
#define OUT1B 8
//D5，D7控制2A，2B的电机
#define OUT2A 5
#define OUT2B 7


//---------------------------------------------------------------
void left()
{
  digitalWrite(OUT1A, HIGH);
  digitalWrite(OUT1B, LOW);
  digitalWrite(OUT2A, HIGH);
  digitalWrite(OUT2B, LOW);
}
void right()
{
  digitalWrite(OUT1A, LOW);
  digitalWrite(OUT1B, HIGH);
  digitalWrite(OUT2A, LOW);
  digitalWrite(OUT2B, HIGH);
}

void back()
{
  digitalWrite(OUT1A, LOW);
  digitalWrite(OUT1B, HIGH);
  digitalWrite(OUT2A, HIGH);
  digitalWrite(OUT2B, LOW);

}

void head()
{
  digitalWrite(OUT1A, HIGH);
  digitalWrite(OUT1B, LOW);
  digitalWrite(OUT2A, LOW);
  digitalWrite(OUT2B, HIGH);


}

void STOP()
{
  digitalWrite(OUT1A, LOW);
  digitalWrite(OUT1B, LOW);
  digitalWrite(OUT2A, LOW);
  digitalWrite(OUT2B, LOW);


}
void period5()//红外遥控
{

  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    switch (results.value)
    {

      case irhead:
        head();
        Serial.println("HEAD");
        delay(300);
        STOP();
        break;

      case irback:
        back();
        Serial.println("BACK");
        delay(300);
        STOP();
        break;

      case irleft:
        left();
        Serial.println("LEFT");
        delay(300);
        STOP();
        break;

      case irright:
        right();
        Serial.println("RIGHT");
        delay(300);
        STOP();
        break;

      case 33441975:
        period = 1;
        break;
    }

    irrecv.resume();
  }
}



void setup()
{
  pinMode(OUT1A, OUTPUT);//驱动
  pinMode(OUT1B, OUTPUT);
  pinMode(OUT2A, OUTPUT);
  pinMode(OUT2B, OUTPUT);

  Serial.begin(9600);  // 初始化串口通信及连接SR04的引脚


  irrecv.enableIRIn();//启动遥控器
}

void loop()
{

  period5();

}












