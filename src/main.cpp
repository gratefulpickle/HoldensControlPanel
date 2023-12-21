#include <Arduino.h>

#include "Global.h"
#include "LEDs.h"
#include "RGBPots.h"
#include "Rotary.h"
#include "SevenSeg.h"

void setup()
{
  Serial.begin(57600);
  LEDSetup();
  RGBPotsSetup();
  RotarySetup();
  SevenSegSetup();
}

void loop()
{
  LEDLoop();
  RGBLoop();
  RotaryLoop();
  SevenSegLoop();
}