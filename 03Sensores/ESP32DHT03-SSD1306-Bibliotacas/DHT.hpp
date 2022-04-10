#include "DHT.h"            // Biblioteca
#define DHTTYPE DHT22       // Configuración sensor DHT11 - DHT21
#define DHTPIN 15           // Pin sensor
DHT dht(DHTPIN, DHTTYPE);   // Instancia de la biblioteca

float temperatura;          // Variables
float humedad;

void leerSensoresDHT(){     // Función/Método

   // La lectura del sensor tarda 250 milisegundos
  temperatura = dht.readTemperature(); 
  humedad = dht.readHumidity();
  
   if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("¡Error de lectura en el sensor DHT!");
      return;
   }
}

void iniciarDHT() {
  dht.begin();
}
