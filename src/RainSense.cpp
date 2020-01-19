/*
 * RainSense.cpp
 */
#include <Arduino.h>
#include "RainSense.h"

RainSense::RainSense(uint8_t pin) {
  _pin = pin;
  pinMode(pin, INPUT_PULLUP);
}

byte RainSense::value(byte samples=16, byte readTimes=1) {
  double val = 0;
  int sumXY = 0;
  int sumX = 0;
  int sumY = 0;
  int sumX2 = 0;
  int Y;
  if(readTimes < 1){
    readTimes = 1;
  }
  for(int i = 0; i < samples; i++) {
    Y = 1023 * readTimes;
    for (size_t j = 0; j < readTimes; j++) {
      Y -= analogRead(_pin);
    }
    Y /= readTimes;
    sumXY += i * Y;
    sumX += i;
    sumY += Y;
    sumX2 += pow(i, 2);
  }
  val = (double)(samples * sumXY - sumX * sumY) / (samples * sumX2 - pow(sumX, 2));
  return constrain((byte)(abs(val) * 100), 0, 100);
}

boolean RainSense::rain(byte threshold, byte samples=16, byte readTimes=1) {
	if(value(samples, readTimes) >= threshold) {
		return 1;
	} else {
		return 0;
	}
	return ;
}
