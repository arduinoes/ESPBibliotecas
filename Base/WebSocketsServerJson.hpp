// Bibliotecas
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

// Instancia / constructor
WebSocketsServer websockets(81);

// Función de conexión websocket
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

  switch (type) 
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] ¡Desconectado!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = websockets.remoteIP(num);
        Serial.printf("[%u] Conectado en %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] Recibe el texto: %s\n", num, payload);
      String mensaje = String((char*)( payload));
      Serial.println(mensaje);
      
      DynamicJsonDocument doc(200); // documento (capacidad)
      DeserializationError error = deserializeJson(doc, mensaje);
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
        }
        
      float ter = doc["termostato"];
      termostato = ter;
      Serial.println("Termostato: "); 
      Serial.println(termostato); 
      }
}

// Función envío datos por websocket en formato Json
void enviarDatosSensorWebSockets() {
   String JSON_Data = "{\"temperatura\":";
          JSON_Data += temperatura;
          JSON_Data += ",\"humedad\":";
          JSON_Data += humedad;
          JSON_Data += ",\"termostato\":";
          JSON_Data += termostato;
          JSON_Data += ",\"altitud\":";
          JSON_Data += altitud;
          JSON_Data += ",\"rele\":";
          JSON_Data += rele;
          JSON_Data += "}";
   Serial.println(JSON_Data);
   websockets.broadcastTXT(JSON_Data);  // envia datos a todos los clientes conectados
}


void iniciarWebSocket () {
  websockets.begin();
  websockets.onEvent(webSocketEvent);
}
