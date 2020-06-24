/*
模拟读取序列

读取引脚0上的模拟输入（电位计），

将结果打印到串行监视器。



打开串行监视器查看

电位计>>



将电位计的中心销连接到销上

A0，外部引脚为+5V并接地。



此示例代码位于公共域中。
*/

int sensorValue = 0;//定义变量

void setup()
{
  pinMode(A0, INPUT);//设置端口A0为输入
  Serial.begin(9600);//设置串口波特率为9600

}

void loop()
{
  
  sensorValue = analogRead(A0);//读取端口A0的输入

  Serial.println(sensorValue);//将输入从串行输出数据
  delay(10); //延迟10毫秒
}