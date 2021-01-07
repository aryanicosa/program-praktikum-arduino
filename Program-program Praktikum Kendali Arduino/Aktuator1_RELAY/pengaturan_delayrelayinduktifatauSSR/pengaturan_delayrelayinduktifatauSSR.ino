const int PIN = 2;

void setup(){
pinMode(PIN, OUTPUT);
}

void loop() {
digitalWrite(PIN, HIGH);
delay(5000);
digitalWrite(PIN, LOW);
delay(5000);
}
