#include <Arduino.h>
#include <FastLED.h>
#include <Bounce2.h>

#define LED_RING_PIN 15
#define TOTAL_LEDS 12
#define BTN_PIN 3

Bounce2::Button stateButton = Bounce2::Button();
CRGBArray <TOTAL_LEDS> ledRing;
int state = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_RING_PIN>(ledRing, TOTAL_LEDS);

  stateButton.attach(BTN_PIN, INPUT_PULLUP);
  stateButton.interval(5);
  stateButton.setPressedState(LOW);

  Serial.begin(9600);
}

void rainbow_wave(uint8_t thisSpeed, uint8_t deltaHue) {     // The fill_rainbow call doesn't support brightness levels.
 
// uint8_t thisHue = beatsin8(thisSpeed,0,255);                // A simple rainbow wave.
 uint8_t thisHue = beat8(thisSpeed,255);                     // A simple rainbow march.
  
 fill_rainbow(ledRing, TOTAL_LEDS, thisHue, deltaHue);            // Use FastLED's fill_rainbow routine.
 
}

// A simple cycle through white LED and colors
// To show the design team for inside the tubes
// of HOW FAST
void loop() {
  stateButton.update();

  if(stateButton.pressed()){
    if(state >=4){
      state = 0;
    } else {
      state++;
    }
  }

  switch(state){
    case 0:
      fill_solid(ledRing, TOTAL_LEDS, CRGB::White);
      FastLED.show();
      break;
    
    case 1:
      fill_solid(ledRing, TOTAL_LEDS, CRGB::Red);
      FastLED.show();
      break;

    case 2:
      fill_solid(ledRing, TOTAL_LEDS, CRGB::Green);
      FastLED.show();
      break;

    case 3:
      fill_solid(ledRing, TOTAL_LEDS, CRGB::Blue);
      FastLED.show();
      break;

    case 4:
      rainbow_wave(10, 10);
      FastLED.show();
      break;
  }
}