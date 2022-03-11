#include "WiFi.hpp"
#include "BME280.hpp"
#include "ESPAsyncWebServer.hpp"
#include "WebSocketsServer.hpp"


void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  iniciarBME280 ();

  initWiFiStation (); 
  initESPAsyncWebServer (); 
  initWebSocketsServer ();
}

void loop() {
  websockets.loop();
}
