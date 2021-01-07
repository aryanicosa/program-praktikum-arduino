#include "max6675.h"
#include <OneWire.h>
#include<DallasTemperature.h>
#define ONE_WIRE_PIN 3          // pin DS18B20

int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;

MAX6675 sensorMAX6675(thermoCLK, thermoCS, thermoDO);
OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensorDS18B20(&oneWire);
float suhu_DS18B20=0;
float suhu_MAX6675=0;

void setup () {
  Serial.begin(9600);
  sensorDS18B20.begin();
  delay(500); //delay penstabil MAX6675
}

void loop() {
  //pembacaan suhu melalui sensor DS18B20
  sensorDS18B20.requestTemperatures();
  suhu_DS18B20=sensorDS18B20.getTempCByIndex(0);

  //pembacaan suhu melalui sensor MAX6675
  suhu_MAX6675= sensorMAX6675.readCelsius();

  Serial.print("suhu MAX6675 = ");
  Serial.println(suhu_MAX6675);
  Serial.print("Suhu DS18B20 = ");
  Serial.println(suhu_DS18B20);
  Serial.println();
  delay(500);
}
