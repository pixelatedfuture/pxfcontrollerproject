#include "Arduino.h"

//setup the class
class SpeedMarquee {
  public:
    SpeedMarquee() {
      //Blank constructor
    };
    void runPattern();
  private:
};

void SpeedMarquee::runPattern() {
  //Everything below here is specific to this pattern

  //first lets setup what the  knobs do:

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
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 10, 300);  // map it to the range of the speed:



  EVERY_N_MILLIS_I( thistimer, 100 ) { // initial period = 100ms
    thistimer.setPeriod( mappedVfx ); //
    //create a new pixel for led[0]
    leds[0] = CHSV (mappedHue, mappedSat, random8(100, 255)); //note mappedHue & mappedSat placed here for controller

    //Copy each pixel to the next one, starting at the far end
    //therby 'moving' the pattern along the strip

    for (int i = NUM_LEDS - 1; i > 0; i--) {
      leds[i] = leds [i - 1];
    }
  }

  btn.tick();
  FastLED.show();
}
