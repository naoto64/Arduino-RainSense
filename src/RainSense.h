/*
 * RainSense.h
 */
#ifndef _RAIN_SENSE_H
#define _RAIN_SENSE_H
#include <Arduino.h>

class RainSense {
public:
  RainSense(uint8_t pin);
  byte value(byte samples, byte readTimes);
  boolean rain(byte threshold, byte samples, byte readTimes);

private:
  uint8_t _pin;
};

#endif
