#include "Arduino.h"

//setup the class

class EightDots {
  public:
    EightDots() {};
    void runPattern();
  private:
};

void EightDots::runPattern() {

  //Everything below here is specific to this pattern

  //this is the brightness controller

  int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip

  //this is the vfx controller

  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 1, 65);  // map it to the range of the speed:

  //this is the hue controller

  int mappedHue;  //declare mappedHue
  int hueValue = analogRead(hueInPin); //read the pot
  mappedHue = map(analogRead(hueInPin), 0, 1023, 1,  7); //mapp the pot to 0-255 hue

  //this is the saturation controller

  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat


  //this is the code telling the strip what to do:


// eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, mappedVfx);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+mappedHue, 0, NUM_LEDS-1 )] |= CHSV(dothue, mappedSat, 255);
    dothue += 32;
  }  


    btn.tick();
    FastLED.show();

}
