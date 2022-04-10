#include "DHTesp.h"

#define DHT_PIN 15

DHTesp dhtSensor;

float temperatura;
float humedad;

void initDHT () {
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void dataDHT () {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  temperatura = dhtSensor.getTemperature();
  humedad = dhtSensor.getHumidity();
  Serial.println("Temperatura: " + String(data.temperature, 2) + "°C");
  Serial.println("Humedad: " + String(data.humidity, 1) + "%");
  Serial.println("---");
  delay(1000);
}
