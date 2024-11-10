#include <FastLED.h>
#include "tables.h"

#define NUM_COLS 60
#define NUM_ROWS 10
#define NUM_LEDS NUM_COLS * NUM_ROWS

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, 3, GRB>(leds, NUM_LEDS);
}

void loop() {
  pacmanChaseWave();
  FastLED.show();
  FastLED.delay(60);
}

void pacmanChaseWave() {
  static byte pacmanPath = 0;
  static byte ghostPaths[3] = {10, 20, 30}; 
  byte yOffset;
  byte virtWidth = 60; 
  LEDS.clear();

  yOffset = (sin8(pacmanPath * 4) / 32); 
  displayWaveSprite(pacmanPath, Dots, yOffset, 2, CRGB::Yellow);

  for (int i = 0; i < 3; i++) {
    yOffset = (sin8((pacmanPath + ghostPaths[i]) * 4) / 32); 
    displayWaveSprite((pacmanPath + ghostPaths[i]) % virtWidth, Mask11 + i * 20, yOffset, 2, CRGB::Red); 
  }

  pacmanPath = (pacmanPath + 1) % virtWidth;
}

void displayWaveSprite(byte path, const uint32_t *sprite, byte yOffset, byte height, CRGB color) {
  for (int x = 0; x < 20; x++) {
    for (int y = 0; y < height; y++) {
      int ledIndex = XY((x + path) % NUM_COLS, y + yOffset);
      leds[ledIndex] = color; // Menggunakan warna yang diinginkan
    }
  }
}

uint16_t XY(byte x, byte y) {
  return (y * NUM_COLS + x);
}
