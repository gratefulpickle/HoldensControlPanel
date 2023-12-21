#include <Arduino.h>
#include <MagicPot.h>
#include "Global.h"

#define pot_r A1
#define pot_g A2
#define pot_b A3

MagicPot potR(pot_r, 0, 255);
MagicPot potG(pot_g, 0, 255);
MagicPot potB(pot_b, 0, 255);

void onChangeR()
{
  // Serial.print("R: ");
  // Serial.println(potR.getValue());
  uint8_t R = potR.getValue();
  auto c = ws2812fx.getColor();
  uint8_t r = (c >> 16) & 0xFF;
  uint8_t g = (c >> 8) & 0xFF;
  uint8_t b = c & 0xFF;
  ws2812fx.setColor(R, g, b);
}
void onChangeG()
{
  // Serial.print("G.: ");
  // Serial.println(potG.getValue());
  uint8_t G = potG.getValue();
  auto c = ws2812fx.getColor();
  uint8_t r = (c >> 16) & 0xFF;
  uint8_t g = (c >> 8) & 0xFF;
  uint8_t b = c & 0xFF;
  ws2812fx.setColor(r, G, b);
}
void onChangeB()
{
  // Serial.print("B: ");
  // Serial.println(potB.getValue());
  uint8_t B = potB.getValue();
  auto c = ws2812fx.getColor();
  uint8_t r = (c >> 16) & 0xFF;
  uint8_t g = (c >> 8) & 0xFF;
  uint8_t b = c & 0xFF;
  ws2812fx.setColor(r, g, B);
}

void RGBPotsSetup()
{
  potR.begin();
  potG.begin();
  potB.begin();
  potR.onChange(onChangeR);
  potG.onChange(onChangeG);
  potB.onChange(onChangeB);
}

void RGBLoop()
{
  potR.read(5);
  potG.read(5);
  potB.read(5);
}
