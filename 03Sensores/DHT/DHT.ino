#include "WiFi.hpp"
#include "DHT.hpp"
#include "ESPAsyncWebServer.hpp"
#include "WebSocketsServerJsonDHT.hpp"


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
