#include "WiFi.hpp"
#include "DHTesp.hpp"
#include "ESPAsyncWebServer.hpp"
#include "WebSocketsServerJsonDHTesp.hpp"
#include "SSD1306.hpp"


void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  initDHT ();
  iniciarPantalla ();
  initWiFiStation (); 
  initESPAsyncWebServer (); 
  initWebSocketsServer ();
  
}

void loop() {
  websockets.loop();
  escribirPantalla ();
  delay(1000);
  
  
}
