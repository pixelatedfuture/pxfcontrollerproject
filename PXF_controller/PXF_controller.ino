#include "FastLED.h"
#include <OneButton.h>

#define DATA_PIN 11 //where is the LED data pin connect on your board
#define LED_TYPE WS2812B //what type of LED strip is it
#define COLOR_ORDER GRB //what is the color order of the strip 
#define NUM_LEDS 165 //how many LEDS are there on the strip 
#define BTN_PIN   3
#define MAX_BRIGHTNESS 185      // Thats full on, watch the power!
#define MIN_BRIGHTNESS 0       // set to a minimum of 0%
//#define FRAMES_PER_SECOND  120


const int vfxInPin = A1;  // The Analog input pin that the VFX control potentiometer is attached to.
const int hueInPin = A2;      // The Analog input pin that the hue control potentiometer is attached to.
const int saturationInPin = A3;      // The Analog input pin that the saturation control potentiometer is attached to.
const int brightnessInPin = A4;  // The Analog input pin that the brightness control potentiometer is attached to.


CRGB leds[NUM_LEDS];  //sets up an array to include all LEDS called NUM_LEDS
uint8_t paletteIndex = 0;
uint8_t patternCounter = 0; //sets up the pattern counter for the button
bool isRunning = false;
OneButton btn = OneButton(BTN_PIN, true, true); //setup the button to work


//this section is where you add the name of the class to include:
#include "ConcertPop.h"
#include "MovingDot.h"
#include "RainbowBeat.h"
#include "ThreeWaves.h"
#include "SpeedMarquee.h"
#include "EightDots.h"
#include "FillStripSparkle.h"
#include "NorthLight.h"




void setup() { //onto void setup- this code only runs 1 time during setup


  delay(3000); //delay during startup
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //add the LED information
  FastLED.setCorrection(TypicalPixelString); //color correction on the LED strip
  //  Serial.begin(57600); //begin the serial monitor
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000); // FastLED Power management set at 5V, 500mA.
  btn.attachClick(nextPattern);
}


void loop() {
  //this is the code that runs on loop. 
  
  //In this section this code is looking at what class is currently pulled up
  // and what is next when the button is pressed.


  switch (patternCounter) {
    case 0:
      runFillStripSparkle();
      break;
    case 1:
      runSpeedMarquee();
         break;
    case 2:
     runNorthLight();
      break;
    case 3:
      runMovingDot();
      break;
    case 4:
      runRainbowBeat();
      break;
    case 5:
      runConcertPop();
      break;
    case 6:
      runEightDots();
      break;
       case 7:
      runThreeWaves();
      break;
  }
}



//Here is where you add new patterns into the pattern counter currently 8 patterns - change if you add or subtract patterns to ensure button functions correctly.

void nextPattern() {
  isRunning = false;
  patternCounter = (patternCounter + 1) % 8;
}

void runMovingDot() {
  isRunning = true;
  MovingDot movingDot = MovingDot();
  while (isRunning) movingDot.runPattern();
}

void runRainbowBeat() {
  isRunning = true;
  RainbowBeat rainbowBeat = RainbowBeat();
  while (isRunning) rainbowBeat.runPattern();
}

void runThreeWaves() {
  isRunning = true;
  ThreeWaves threeWaves = ThreeWaves();
  while (isRunning) threeWaves.runPattern();
}

void runConcertPop() {
  isRunning = true;
  ConcertPop concertPop = ConcertPop();
  while (isRunning) concertPop.runPattern();
}

void runSpeedMarquee() {
  isRunning = true;
  SpeedMarquee speedMarquee = SpeedMarquee();
  while (isRunning) speedMarquee.runPattern();
}

void runEightDots() {
  isRunning = true;
  EightDots eightDots = EightDots();
  while (isRunning) eightDots.runPattern();
}

void runFillStripSparkle() {
  isRunning = true;
  FillStripSparkle fillStripSparkle = FillStripSparkle();
  while (isRunning) fillStripSparkle.runPattern();
}

void runNorthLight() {
  isRunning = true;
  NorthLight northLight = NorthLight();
  while (isRunning) northLight.runPattern();
}
