char str;
void setup()
{
  Serial.begin (9600);
  pinMode (5,1) ;
}
void loop()
{
  if (Serial.available()>0)
  {
    str = Serial.read() ;
    if (str=='A') digitalWrite (5,1) ;
    else if (str == 'B') digitalWrite (5,0) ;
  }
}
