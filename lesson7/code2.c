#include <MsTimer2.h>     
 
int tick = 0;
 

void onTimer()
{
  Serial.print("timer ");
  Serial.println(tick++);
}
 
void setup()
{
  Serial.begin(9600); 
  
  MsTimer2::set(1000, onTimer); 
  MsTimer2::start(); 
}
 
void loop()
{
  
}
