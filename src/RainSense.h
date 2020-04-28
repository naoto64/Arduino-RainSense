/*
 * RainSense.h
 */
#ifndef _RAIN_SENSE_H
#define _RAIN_SENSE_H
#include <Arduino.h>

class RainSense {
public:
  RainSense(uint8_t pin);
  byte value(byte samples=1, byte sensitivity=16);
  boolean rain(byte threshold, byte samples=1, byte sensitivity=16);

private:
  uint8_t _pin;
  int getY(byte samples);
  void sum(byte samples, byte sensitivity, int *sumXY, int *sumX, int *sumY, int *sumX2);
};

#endif
