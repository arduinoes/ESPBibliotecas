// Biblotecas
#include "ESPAsyncWebServer.h"

#define Led 2

char paginaweb[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>ESP32 HTML</h1>
<h3> LED </h3>
<button onclick="window.location = 'http://'+location.hostname+'/led/on'">On</button>
<button onclick="window.location = 'http://'+location.hostname+'/led/off'">Off</button>
</center>
</body>
</html>
)=====";

// Instancia / constructor
AsyncWebServer server(80);

// Funciones / métodos
void initESPAsyncWebServer (){
  server.begin();
  server.on("/", [](AsyncWebServerRequest * request) { 
    request->send_P(200, "text/html", paginaweb);
    });
  server.on("/led/on", HTTP_GET, [](AsyncWebServerRequest * request) { 
    digitalWrite(Led, HIGH);
    request->send_P(200, "text/html", paginaweb);
    });
  server.on("/led/off", HTTP_GET, [](AsyncWebServerRequest * request) { 
    digitalWrite(Led, LOW);
    request->send_P(200, "text/html", paginaweb);
    });
}
