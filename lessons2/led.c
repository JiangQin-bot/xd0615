void setup()
{
  int i;
  for(i=0;i<7;i=i+2){
  pinMode(i, OUTPUT);
  }
}

void loop()
{
  int i;
  for(i=0;i<7;i=i+2){
  digitalWrite(i, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  }
}