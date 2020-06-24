#include <MsTimer2.h>     
 
int tick = 0; //计数值
byte count = 0;
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 6

#define LT 7
#define BT 8
 

void onTimer()
{
  Light(tick);  //调用七段显示程序
  tick++;
  if(tick==10)
    tick=0;
}

int pinInterrupt = 2; //接中断信号的脚
//中断服务程序 
void onChange()
{
   if ( digitalRead(pinInterrupt) == LOW )
      tick=0;
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4

  pinMode(S1, OUTPUT);//片选1
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  
  Serial.begin(9600); //初始化串口
  
  pinMode( pinInterrupt, INPUT);
  
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  
}
 
void Light(int tick)
{
  count=tick;
  count=count-'0';
  digitalWrite(S1,LOW);
  digitalWrite(IN1,count&0x1);
  digitalWrite(IN2,(count>>1)&0x1);
  digitalWrite(IN3,(count>>2)&0x1);
  digitalWrite(IN4,(count>>3)&0x1);
  digitalWrite(S1,HIGH);  
}

void loop()
{
  
}

