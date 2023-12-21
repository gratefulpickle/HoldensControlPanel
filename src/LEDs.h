#include <WS2812FX.h>
#include "Global.h"

void LEDSetup(){

  ws2812fx.init();
  ws2812fx.setBrightness(64);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(0x007BFF);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.start();
  // ws2812fx.setMode(FX_MODE_SCAN);
  ws2812fx.setColor(0xff0000);
}

void LEDLoop(){
  ws2812fx.service();
}