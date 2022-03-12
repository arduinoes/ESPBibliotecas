// Biblioteca
#include <WiFi.h>

const char* nombre_red = "studio";
const char* contrasena = "88888888";

// Función / método
void initWiFiAccessPoint () {
  WiFi.softAP(nombre_red, contrasena);
  Serial.println("soft Access Point: ");
  Serial.println(WiFi.softAPIP());
}

void initWiFiStation () {
  WiFi.begin(nombre_red, contrasena);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());
}

void initWiFiAccessPointStation () {
 WiFi.mode(WIFI_AP_STA);
  WiFi.begin( nombre_red, contrasena );
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("¡Conectando en modo estación!");
  }
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
