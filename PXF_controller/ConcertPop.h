#include "Arduino.h"

//setup the class
class ConcertPop {
  public:
    ConcertPop() {};
    void runPattern();
  private:
};

void ConcertPop::runPattern() {
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

  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat



  EVERY_N_MILLIS_I( thistimer, 100 ) { // initial period = 100ms
    thistimer.setPeriod( mappedVfx ); //
    leds[random8(0, NUM_LEDS - 1)] = CHSV(mappedHue, mappedSat, 255);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(leds, NUM_LEDS, 3);


  btn.tick();
  FastLED.show();
}
