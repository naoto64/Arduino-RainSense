/*
 * RainSense.cpp
 */
#include <Arduino.h>
#include "RainSense.h"

RainSense::RainSense(uint8_t pin) {
  _pin = pin;
  pinMode(pin, INPUT_PULLUP);
}

byte RainSense::value(byte samples, byte sensitivity) {
  byte val = 0;
  int sumXY = 0;
  int sumX = 0;
  int sumY = 0;
  int sumX2 = 0;
  if(samples < 1){
    samples = 1;
  }
  for(int i = 0; i < sensitivity; i++) {
    int Y = getY(samples);
    sumXY += i * Y;
    sumX += i;
    sumY += Y;
    sumX2 += i * i;
  }
  val = (sensitivity * sumXY - sumX * sumY) / (sensitivity * sumX2 - sumX * sumX);
  if(val < 0) val *= -1;
  if(val > 100) val = 100;
  return val;
}

boolean RainSense::rain(byte threshold, byte sensitivity) {
  if(analogRead(_pin) / 4 >= 255 - threshold) {
    return 1;
  } else {
    return 0;
  }
}

int RainSense::getY(byte samples) {
  int Y = 1023 * samples;
  for (size_t j = 0; j < samples; j++) {
    Y -= analogRead(_pin);
  }
  Y /= samples;
  return Y;
}
