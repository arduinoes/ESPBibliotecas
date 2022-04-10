// Descarga la herramienta Sketch Data Upload
// https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/

// Biblotecas
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

#define Led 2

// Instancia / constructor
AsyncWebServer server(80);

// Funciones / métodos
void initESPAsyncWebServer (){
  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("A ocurrido un error al montando SPIFFS");
    return;
  }
  server.begin();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", "text/html");
    });
  server.on("/led/on", HTTP_GET, [](AsyncWebServerRequest * request) { 
    digitalWrite(Led, HIGH);
    request->send(SPIFFS, "/index.html", "text/html");
    });
  server.on("/led/off", HTTP_GET, [](AsyncWebServerRequest * request) { 
    digitalWrite(Led, LOW);
    request->send(SPIFFS, "/index.html", "text/html");
    });
}
