//  Biblietecas pantalla OLED "SSD1306"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configuración
#define SCREEN_WIDTH 128 // Pantalla OLED ancho, en pixeles
#define SCREEN_HEIGHT 64 // Pantalla OLED alto, en pixeles
#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3c

// Instancia / constructor
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Función / método
void escribirPantalla() {
  display.clearDisplay();
  display.fillRect(0, 0, 128, 16, WHITE);
  display.setTextSize(2);
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(10, 0);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(37, 5);
  display.setTextColor(SSD1306_BLACK);
  display.print(F("ARDUINOES"));
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(10, 30);
  display.print(F("Temperatura: ")); 
  display.println(temperatura);
  display.setCursor(20, 50);
  display.print(F("Humedad: ")); 
  display.println(humedad); 
  display.display();
}
void iniciarPantalla () {
  // SSD1306_SWITCHCAPVCC = ajusta el vontaje a 3.3V 
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 error de asignación"));
    for(;;); // bucle infinito => while(true)
  }
}
