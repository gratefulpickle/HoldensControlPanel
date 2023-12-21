#include <Arduino.h>
#include "Global.h"
#include "SimpleRotary.h"

#define rclock 5
#define rdata 6
#define rswitch 7

static const int MAXMODES = 56; // 65 minus the custom ones

int currentEffect = 0;

// Pin A, Pin B, Button Pin
SimpleRotary rotary(rdata, rclock, rswitch);

void RotarySetup(){

}



void IncrementEffect()
{
  if (currentEffect++ == MAXMODES)
    currentEffect = 0;
  ws2812fx.setMode(currentEffect);
  Serial.println(currentEffect);
  Serial.print("mode is ");
  Serial.println(ws2812fx.getModeName(ws2812fx.getMode()));
}

void DecrementEffect()
{
  if (currentEffect-- == 0)
    currentEffect = MAXMODES;
  ws2812fx.setMode(currentEffect);
  Serial.println(currentEffect);
  Serial.print("mode is ");
  Serial.println(ws2812fx.getModeName(ws2812fx.getMode()));
}


void RotaryLoop(){
  // 0 = not turning, 1 = CW, 2 = CCW
  byte sw = rotary.push();
  byte i = rotary.rotate();

  if (i == 1)
  {
    Serial.println("CW");
    IncrementEffect();
  }

  if (i == 2)
  {
    Serial.println("CCW");
    DecrementEffect();
  }
  if (sw == 1)
  {
    Serial.println("pushed");
    rotary.resetPush();
  }
}