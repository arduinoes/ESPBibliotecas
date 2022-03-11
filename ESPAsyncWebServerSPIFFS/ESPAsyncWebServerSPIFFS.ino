#include "WiFi.hpp"
#include "ESPAsyncWebServer.hpp"

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);

  initWiFiStation (); 
  initESPAsyncWebServer ();  
}

void loop() {
}
