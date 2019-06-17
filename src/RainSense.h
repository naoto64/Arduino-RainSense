/*
 * RainSense.h
 */
#ifndef _RAIN_SENSE_H
#define _RAIN_SENSE_H
#include <Arduino.h>

class RainSense {
public:
  RainSense(uint8_t pin);
  byte value(byte samples);
  boolean rain(byte samples, byte threshold);
  
private:
  uint8_t _pin;
};

#endif