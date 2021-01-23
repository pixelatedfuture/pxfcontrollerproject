#include "Arduino.h"

//setup the class
class MovingDot {
  public:
    MovingDot() {
      // Blank constructor
    };
    void runPattern();
  private:
};

void MovingDot::runPattern() {
  //Everything below here is specific to this pattern

  //this is the brightness controller

  int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip

  //this is the Sat controller

  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat

  //this is the vfx controller

  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 50, 0);  // map it to the range of the speed:

  uint16_t posBeat  = beatsin16(4, 0, NUM_LEDS - 1, 0, 0);
  uint16_t posBeat2 = beatsin16(10, 0, NUM_LEDS - 1, 0, 0);

  uint16_t posBeat3 = beatsin16(4, 0, NUM_LEDS - 1, 0, 32767);
  uint16_t posBeat4 = beatsin16(10, 0, NUM_LEDS - 1, 0, 32767);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, mappedSat, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, mappedSat, 255);

  fadeToBlackBy(leds, NUM_LEDS, mappedVfx);

  btn.tick();
  FastLED.show();
}
