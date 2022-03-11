// Bibliotecas
#include <WebSocketsServer.h>

// Configuración
#define Led 2

// Instancia / constructor
WebSocketsServer websockets(81);

// Funciones / Métodos
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] ¡Desconectado!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Conectado en %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        websockets.sendTXT(num, "Conectado en servidor:");
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] Recibe el texto: %s\n", num, payload);
      String mensaje = String((char*)( payload));
      Serial.println(mensaje);
      if(mensaje == "Led esta en OFF"){
        digitalWrite(Led,LOW);
      }
      if(mensaje == "Led esta en ON"){
        digitalWrite(Led,HIGH);
      }
  }
}
  
void initWebSocketsServer () {
  websockets.begin();
  websockets.onEvent(webSocketEvent);
}
