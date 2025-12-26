#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// --- TFT Display Pins (ESP32-S3 Hardware SPI) ---
#define TFT_CS   10
#define TFT_RST  11
#define TFT_DC   12
#define TFT_MOSI 13
#define TFT_SCK  14

// --- Node Pins (Potentiometers simulating UWB/BLE) ---
const int nodePins[] = {1, 2, 3, 4, 5}; 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

struct Product { String name; String loc; uint16_t color; };
Product mall[] = {
  {"FRUITS", "Aisle 1", ILI9341_GREEN},
  {"DAIRY",  "Aisle 2", ILI9341_WHITE},
  {"BAKERY", "Aisle 3", ILI9341_YELLOW},
  {"DRINKS", "Aisle 4", ILI9341_CYAN},
  {"MEAT",   "Aisle 5", ILI9341_RED}
};

void setup() {
  Serial.begin(115200);
  
  // Forcing the SPI to use your specific wired pins / it depends your pin config
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS); 

  // Initialize Large TFT Screen
  tft.begin();
  tft.setRotation(1); // Landscape view
  tft.fillScreen(ILI9341_BLACK);
  
  // Draw Static UI Header
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(15, 10);
  tft.println("MALL INDOOR NAVIGATION");
  tft.drawFastHLine(0, 35, 320, ILI9341_BLUE);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    // Read knob and map to 0.0m - 30.0m
    float dist = map(analogRead(nodePins[i]), 0, 4095, 0, 300) / 10.0;
    int yPos = 55 + (i * 35);

    // Update screen - clear specific value area only
    tft.fillRect(225, yPos, 85, 25, ILI9341_BLACK); 
    
    tft.setCursor(15, yPos);
    tft.setTextColor(mall[i].color);
    tft.setTextSize(2);
    tft.print(mall[i].name);

    tft.setCursor(225, yPos);
    tft.setTextColor(ILI9341_WHITE);
    tft.printf("%.1fm", dist);
  }
  
  delay(100); // Faster update for better simulation feel
}
