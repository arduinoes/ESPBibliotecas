#include "WiFi.hpp"
#include "ESPAsyncWebServer.hpp"
#include "WebSocketsServer.hpp"

void setup() {
  pinMode(Led, OUTPUT);
  Serial.begin(115200);

  initWiFiStation (); 
  initESPAsyncWebServer ();  
  initWebSocketsServer ();
}

void loop() { 
  websockets.loop();
}
