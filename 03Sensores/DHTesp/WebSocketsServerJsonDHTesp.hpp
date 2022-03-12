// Bibliotecas
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include <Ticker.h>

// Configuración
#define Led 2

void enviarDatosSensorWebsockets ();

// Instancia / constructor
WebSocketsServer websockets(81);
Ticker timer;

// Funciones / Métodos
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] ¡Desconectado!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Conectado en %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] Texto: %s\n", num, payload);
      String mensaje = String((char*)( payload));
      Serial.println(mensaje);
      DynamicJsonDocument doc(200); // documento (capacidad)
      DeserializationError error = deserializeJson(doc, mensaje);
        if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
        }  
      int estadoLed = doc["Led"]; // el estado será de 0 o 1
      digitalWrite(Led,estadoLed);
      }
}

void enviarDatosSensorWebsockets () {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  float t = data.temperature;
  float h = data.humidity;
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Fallo de lectura en sensor BME280!"));
    return;
    }
  String JSON_Data = "{\"temp\":";
         JSON_Data += t;
         JSON_Data += ",\"hum\":";
         JSON_Data += h;
         JSON_Data += "}";       
   Serial.println(JSON_Data);
   websockets.broadcastTXT(JSON_Data);  // envia datos a todos los clientes conectados
}
  
void initWebSocketsServer () {
  websockets.begin();
  websockets.onEvent(webSocketEvent);
  timer.attach(5,enviarDatosSensorWebsockets); 
}
