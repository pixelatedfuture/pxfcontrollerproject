#include "Arduino.h"

//setup the class
class RainbowBeat {
  public:
    RainbowBeat() {};
    void runPattern();
  private:
};

void RainbowBeat::runPattern() {
  //Everything below here is specific to this pattern

  //this is the brightness controller

  int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip

  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 0, 255);  // map it to the range of the speed:

  int mappedHue;  //declare mappedHue
  int hueValue = analogRead(hueInPin); //read the pot
  mappedHue = map(analogRead(hueInPin), 0, 1023, 0,  400); //mapp the pot to 0-255 hue




  EVERY_N_MILLIS_I( thistimer, 100 ) { // initial period = 100ms
    thistimer.setPeriod( mappedHue ); //

    uint16_t beatA = beatsin16(30, mappedVfx, 255);
    uint16_t beatB = beatsin16(20, mappedVfx, 255);
    fill_rainbow(leds, NUM_LEDS, (beatA + beatB) / 2, 8);
    fadeToBlackBy(leds, NUM_LEDS, 1);

  }
  btn.tick();
  FastLED.show();
}
