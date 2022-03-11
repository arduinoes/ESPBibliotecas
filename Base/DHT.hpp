// Bibliotecas
#include "DHT.h"

// Configuraciones
#define DHTTYPE DHT22 
#define DHTPIN 27

// Instancia / constructor
DHT dht(DHTPIN, DHTTYPE);

// Variables
float temperatura;
float humedad;

void iniciarDHT () {
  Serial.println("¡Testeando el sensor DHT!");
  dht.begin();  
}

void leerSensoresDHT(){
  
   // La lectura del sensor tarda 250 milisegundos
   humedad = dht.readHumidity();
   temperatura = dht.readTemperature();

   if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("¿Error de lectura del sensor DHT!");
      return;
      }
}
