const int IN1Pin = 6;
const int IN2Pin = 5;

void setup ()
{
  pinMode (IN1Pin, OUTPUT);
  pinMode (IN2Pin, OUTPUT);
}

void loop ()
{
  digitalWrite(IN1Pin,LOW);
  for(int i=1; i<256; i++) {
    analogWrite(IN1Pin,i);
    delay (25);
  }

  digitalWrite(IN2Pin,LOW);
  digitalWrite(IN1Pin,LOW);
  delay(500);

  digitalWrite(IN1Pin,LOW);
  for(int i=255; i>=0; i--) {
    analogWrite(IN2Pin,i);
    delay (25);
  }

  digitalWrite(IN2Pin,LOW);
  digitalWrite(IN1Pin,LOW);
  delay(500);

}
