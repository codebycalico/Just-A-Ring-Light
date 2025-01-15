#include <Arduino.h>
#include <FastLED.h>

#define LED_RING_PIN 23
#define TOTAL_LEDS 12
CRGBArray <TOTAL_LEDS> ledRing;

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_RING_PIN>(ledRing, TOTAL_LEDS);

  Serial.begin(9600);
}

// A simple cycle through white LED and colors
// To show the design team for inside the tubes
// of HOW FAST
void loop() {
  fill_solid(ledRing, TOTAL_LEDS, CRGB::White);
  FastLED.show();
  delay(40);

  
}