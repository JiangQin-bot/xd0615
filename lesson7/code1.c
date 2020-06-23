void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop()
{
 	int income=0;
  	int i;
  	for(i=0;i<10;i++)
    {
      	income=i;
      	income=income-'0';
      	digitalWrite(6,LOW);
      	digitalWrite(7,HIGH);
      	digitalWrite(8,HIGH);
  		digitalWrite(2, income&0x1);
  		digitalWrite(3,(income>>1)&0x1);
   	 	digitalWrite(4,(income>>2)&0x1);
   	 	digitalWrite(5,(income>>3)&0x1);
    	delay(1000);
  }
}