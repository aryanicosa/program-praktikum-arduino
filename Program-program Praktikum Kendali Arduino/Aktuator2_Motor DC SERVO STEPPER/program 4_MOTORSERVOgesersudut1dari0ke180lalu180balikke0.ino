#include <Servo.h>
Servo mservo;
int pos = 0;
void setup ()
{
  int pinservo = 3;
  mservo.attach(pinservo);
}

void loop ()
{
  for(pos = 0; pos<=180; pos += 1)
  {
    mservo.write(pos);
    delay(15);
  }
  for(pos = 180; pos>=0; pos-=1)
  {
    mservo.write(pos);
    delay(100);
  }
  
}
