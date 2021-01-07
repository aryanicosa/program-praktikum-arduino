const int IN1Pin = 6;
const int IN2Pin = 5;
 
void setup() 
{
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  // put your setup code here, to run once:
}

void loop() 
{
  digitalWrite(IN1Pin,HIGH); //kanan
  digitalWrite(IN2Pin,LOW);
  delay(2000);

  digitalWrite(IN1Pin,LOW); //kiri
  digitalWrite(IN2Pin,HIGH);
  delay(3000);

  digitalWrite(IN1Pin,LOW); //stop
  digitalWrite(IN2Pin,LOW);
  delay(3000);

}
