#include <Stepper.h>
int jumstep=64;
Stepper msteper (jumstep, 5, 4, 3, 2);

void setup(){  
}

void loop() {
  msteper.setSpeed(60); //kecepatan 60 rpm
  msteper.step(-64); //putar kekanan 64 step (1x putaran)
  delay(100);
  msteper.setSpeed(30); // kec 30 rpm
  msteper.step(48); //putar kekiri 48 step
  delay(500);
}
