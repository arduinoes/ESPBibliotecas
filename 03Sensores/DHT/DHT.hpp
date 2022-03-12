// https://github.com/adafruit/DHT-sensor-library
// Bibliotecas
#include "DHT.h"

// Configuraciones
#define DHTTYPE DHT22 
#define DHTPIN 15

// Instancia / constructor
DHT dht(DHTPIN, DHTTYPE);

// Variables
float temperatura;
float humedad;

void initDHT () {
  Serial.println("¡Testeando el sensor DHT!");
  dht.begin();  
}

void leerSensoresDHT(){
  
   // La lectura del sensor tarda 250 milisegundos
   temperatura = dht.readTemperature();
   humedad = dht.readHumidity();
   if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("¡Error de lectura del sensor DHT!");
      return;
      }
}
