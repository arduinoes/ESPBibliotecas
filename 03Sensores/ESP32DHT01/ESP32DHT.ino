#include "DHT.h"            // Bibliotecas
#define DHTTYPE DHT22       // Configuración sensor DHT11 - DHT21
#define DHTPIN 15           // Pin sensor

DHT dht(DHTPIN, DHTTYPE);   // Instancia de la biblioteca

float temperatura;          // Variables
float humedad;

void leerSensoresDHT(){     // Funciónes/Métodos

   // La lectura del sensor tarda 250 milisegundos
  temperatura = dht.readTemperature(); 
  humedad = dht.readHumidity();
  
   if (isnan(humedad) || isnan(temperatura)) {
      Serial.println("¡Error de lectura en el sensor DHT!");
      return;
   }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  leerSensoresDHT();
   Serial.print("Humedad: ");
   Serial.print(humedad);
   Serial.println(" %\t");
   Serial.print("Temperatura: ");
   Serial.print(temperatura);
   Serial.println(" ºC ");
   delay(1000);
}
