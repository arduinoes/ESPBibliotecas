#include "DHT.hpp"
#include "SSD1306.hpp"

void setup() {
  Serial.begin(115200);
  iniciarDHT();
  iniciarPantalla ();

}

void loop() {
  leerSensoresDHT();
  escribirPantalla();
   Serial.print("Humedad: ");
   Serial.print(humedad);
   Serial.println(" %\t");
   Serial.print("Temperatura: ");
   Serial.print(temperatura);
   Serial.println(" ºC ");
   delay(1000);
}
