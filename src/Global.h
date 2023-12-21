#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include <WS2812FX.h>

#define LED_COUNT 41
#define LED_PIN 12 //D12

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#endif