#include <Wire.h>
#define PCF8591 (0x90 >> 1)
byte adcvalue0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(PCF8591);
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.requestFrom(PCF8591, 1);

  adcvalue0=Wire.read();

  Serial.print(adcvalue0);
  Serial.println();
  delay(500);
}
