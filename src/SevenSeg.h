
#include <Arduino.h>
#include "Global.h"
#include <EasyButton.h>

#define button_pin 9 // D9

// 74HC595
#define data 2  // D2
#define latch 3 // D3
#define clock 4 // D4

EasyButton button(button_pin);
int currentDigit = 0;

//  A B C D E F G (discard)
// 1 = on
int digits[10] = {
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110  // 9
};

void WriteTo7Segment(int digitIndex)
{
    digitalWrite(latch, LOW);
    shiftOut(data, clock, LSBFIRST, digits[digitIndex]);
    digitalWrite(latch, HIGH);
}

void onPressed()
{
    // Serial.println("Button has been pressed!");
    currentDigit++;
    if (currentDigit == 10)
        currentDigit = 0;
    WriteTo7Segment(currentDigit);
}

void SevenSegSetup()
{
    // Serial.println("7seg setup");
    // set pins to output so you can control the shift register
    pinMode(data, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(latch, OUTPUT);
    // pinMode(LED_BUILTIN, OUTPUT);
    // digitalWrite(LED_BUILTIN, HIGH); // turn off onboard led
    WriteTo7Segment(0);

    // Initialize the button.
    button.begin();

    // Attach callback.
    button.onPressed(onPressed);
}

void SevenSegLoop()
{
    button.read();
}