#include "WiFi.hpp"
#include "DHTesp.hpp"
#include "ESPAsyncWebServer.hpp"
#include "WebSocketsServerJsonDHTesp.hpp"


void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  initDHT ();

  initWiFiStation (); 
  initESPAsyncWebServer (); 
  initWebSocketsServer ();
}

void loop() {
  websockets.loop();
}
