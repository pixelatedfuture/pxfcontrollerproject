#include "Arduino.h"

//setup the class
class NorthLight {
  public:
    NorthLight() {
      //Blank constructor
    };
    void runPattern();
  private:
};

void NorthLight::runPattern() {
  //Everything below here is specific to this pattern

CRGBPalette16 purplePalette = CRGBPalette16 (
    CRGB::DarkBlue,
    CRGB::DarkBlue,
    CRGB::DarkBlue,
    CRGB::DarkBlue,
    
    CRGB::DarkGreen,
    CRGB::DarkGreen,
    CRGB::DarkGreen,
    CRGB::DarkGreen,
    
    CRGB::DarkBlue,
    CRGB::DarkBlue,
    CRGB::DarkBlue,
    CRGB::DarkGreen,

    CRGB::DarkGreen,
    CRGB::DarkGreen,
    CRGB::DarkViolet,
    CRGB::DarkViolet
);


 int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip

  int mappedHue;  //declare mappedHue
  int hueValue = analogRead(hueInPin); //read the pot
  mappedHue = map(analogRead(hueInPin), 0, 1023, 0,  255); //mapp the pot to 0-255 hue

  //this is the saturation controller
  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat

  //this is the vfx controller

  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 80, 1);  // map it to the range of the speed:
 //Creat a sin wave with period of 2 seconds (30bpm) to change the brightness of the strip
  
  uint8_t sinBeat = beatsin8(8, mappedSat, 255, 0, 0);

  fill_palette(leds, NUM_LEDS, paletteIndex, mappedHue / NUM_LEDS, purplePalette, sinBeat, LINEARBLEND);

EVERY_N_MILLIS_I( thistimer, 100 ) { // initial period = 100ms
    thistimer.setPeriod( mappedVfx ); //
    paletteIndex++;
  }
 btn.tick();
  FastLED.show();
}
