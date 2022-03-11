// Biblotecas
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Configuraciones
#define SEALEVELPRESSURE_HPA (1013.25) 
// Presión nivel del mar (presión => temperatura)

#define RELEPIN 2

// Variables
float temperatura;
float humedad;
float presion;
float altitud;

bool rele;
float termostato = 22;


// Instancia / constructor
Adafruit_BME280 bme;

// Funciones / métodos
void activarRele() {  
  if (temperatura > termostato) {
    digitalWrite (RELEPIN, LOW);
    Serial.println( "Relé desactivado");
    rele = false;
    }
    else {
      digitalWrite(RELEPIN, HIGH);
      Serial.println( "Relé activado");
      rele = true;
      }
}
void leerSensorBME280 () {
  temperatura = bme.readTemperature();
  humedad = bme.readHumidity();
  presion = bme.readPressure();
  altitud = bme.readAltitude(SEALEVELPRESSURE_HPA);
  activarRele();
}

void imprimirValores() {
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  
  // Temperatura en Fahrenheit
  Serial.print("Temperatura = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");
  
  Serial.print("Presión = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa - hectopascal");

  Serial.print("Altitud aproximada = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humedad = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}

void iniciarBME280 () {
  Serial.println(F("BME280 test"));
  bool status;
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("¡Sensor BME280 no detectado, revisa las conexiones!");
    while (1);
    }
    Serial.println("-- Test De Prueba --");
    delay(1000);
    Serial.println();
    imprimirValores();
}
