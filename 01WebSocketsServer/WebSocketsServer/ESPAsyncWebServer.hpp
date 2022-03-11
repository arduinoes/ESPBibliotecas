// Biblotecas
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"

// Instancia / constructor
AsyncWebServer server(80);

// Funciones / métodos
void initESPAsyncWebServer (){
  if(!SPIFFS.begin(true)){
    Serial.println("A ocurrido un error al montando SPIFFS");
    return;
    }
  server.begin();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request)
  { request->send(SPIFFS, "/index.html", "text.html");
  });
}
