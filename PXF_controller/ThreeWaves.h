#include "Arduino.h"

//setup the class

class ThreeWaves {
  public:
    ThreeWaves() {};
    void runPattern();
  private:
};


void ThreeWaves::runPattern() {
  //Everything below here is specific to this pattern

  //this is the brightness controller

  int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip

  //this is the vfx controller

  int mappedHue;  //declare mappedHue
  int hueValue = analogRead(hueInPin); //read the pot
  mappedHue = map(analogRead(hueInPin), 0, 1023, 0,  255); //mapp the pot to 0-255 hue

  //this is the saturation controller

  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat

  //this is the vfx controller

  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 400, 1);  // map it to the range of the speed:

  uint16_t sinBeat   = beatsin16(8, 0, NUM_LEDS - 1, 0, 0);
  uint16_t sinBeat2  = beatsin16(8, 0, NUM_LEDS - 1, 0, 21845);
  uint16_t sinBeat3  = beatsin16(8, 0, NUM_LEDS - 1, 0, 43690);

  leds[sinBeat]   = CHSV(mappedVfx, 255, 255);
  leds[sinBeat2]  = CHSV(mappedSat, 255, 255);
  leds[sinBeat3]  = CHSV(mappedHue, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 10);

  btn.tick();
  FastLED.show();
}
