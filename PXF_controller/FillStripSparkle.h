#include "Arduino.h"

//setup the class
class FillStripSparkle {
  public:
    FillStripSparkle() {};
    void runPattern();
  private:
};

void FillStripSparkle::runPattern() {
  //Everything below here is specific to this pattern

  //this is the brightness controller

  int brightValue = analogRead(brightnessInPin);  // read the analog brightness value:
  int lightValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);  // map it to the range of the FastLED brightness:
  FastLED.setBrightness(constrain(lightValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS)); // now we set the brightness of the strip


  int mydelay = analogRead(vfxInPin);  // read the analog time value:
  int mappedVfx = map(analogRead(vfxInPin), 0, 1023, 1, 800);  // map it to the range of the speed:

  int mappedHue;  //declare mappedHue
  int hueValue = analogRead(hueInPin); //read the pot
  mappedHue = map(analogRead(hueInPin), 0, 1023, 0,  255); //mapp the pot to 0-255 hue

  int mappedSat; //declare mappedSat
  int satValue = analogRead(saturationInPin);  //read the pot
  mappedSat = map(analogRead(saturationInPin), 0, 1023, 0,  255); //map the pot to 0-255 sat


 
  uint8_t sinBeat = beatsin8(2, 60, 255, 0, 0);
  uint8_t sinBeatA = beatsin8(2, 60, 255, 0, 127);
 //uint16_t sinBeatB   = beatsin16(8, 0, NUM_LEDS - 1, 0, 0);

  fill_solid( leds, NUM_LEDS, CHSV(mappedHue, mappedSat, sinBeat));



EVERY_N_MILLIS_I( thistimer, 100 ) { // initial period = 100ms
    thistimer.setPeriod( mappedVfx ); //
    leds[random8(0, NUM_LEDS - 1)] = CHSV(0, 0, sinBeatA);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(leds, NUM_LEDS, 3);


  //leds[sinBeatB]   = CHSV(0, 0, 255);


  
  btn.tick();
  FastLED.show();
}
