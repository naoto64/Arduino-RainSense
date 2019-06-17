/*
 * RainSense.cpp
 */
#include <Arduino.h>
#include "RainSense.h"

RainSense::RainSense(uint8_t pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

byte RainSense::value(byte samples) {
  double val = 0;
  int sumXY = 0;
  int sumX = 0;
  int sumY = 0;
  int sumX2 = 0;
  int Y;
  for(int i = 0; i < samples; i++) {
    Y = analogRead(_pin);
    sumXY += i * Y;
    sumX += i;
    sumY += Y;
    sumX2 += pow(i, 2);
  }
  val = (double)(samples * sumXY - sumX * sumY) / (samples * sumX2 - pow(sumX, 2));
  return constrain((byte)(abs(val) * 100), 0, 100);
}

boolean RainSense::rain(byte samples, byte threshold) {
	if(value(samples) >= threshold) {
		return 1;
	} else {
		return 0;
	}
	return ;
}