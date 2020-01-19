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
  double val = 0;
  int sumXY = 0;
  int sumX = 0;
  int sumY = 0;
  int sumX2 = 0;
  int Y;
  if(samples < 1){
    samples = 1;
  }
  for(int i = 0; i < sensitivity; i++) {
    Y = 1023 * samples;
    for (size_t j = 0; j < samples; j++) {
      Y -= analogRead(_pin);
    }
    Y /= samples;
    sumXY += i * Y;
    sumX += i;
    sumY += Y;
    sumX2 += pow(i, 2);
  }
  val = (double)(sensitivity * sumXY - sumX * sumY) / (sensitivity * sumX2 - pow(sumX, 2));
  return constrain((byte)(abs(val) * 100), 0, 100);
}

boolean RainSense::rain(byte threshold, byte samples, byte sensitivity) {
	if(value(sensitivity, samples) >= threshold) {
		return 1;
	} else {
		return 0;
	}
	return ;
}
