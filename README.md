Arduino-RainSense
====

## Overview

This is a rain sensor library for Arduino. Prepare two electrodes and connect them to GND and analog input pins.
This library can use a rain sensor to detect if it is raining. Since it is possible to detect each drop of raindrops, it is possible to measure precipitation intensity, etc. If you do not have a rainfall sensor, you can make your own using aluminum tape.

## Demo

````cpp:example.ino
#include <RainSense.h>
#define delayTime 10
RainSense rs = RainSense (A0);
unsigned long time = 0;
int rainBool = 0;
void setup () {
  Serial.begin (9600);
  if (rs.rain (40)) {
    Serial.println ("It's raining");
    rainBool = 1;
  } else {
    Serial.println ("It is not raining.");
  }
}
void loop () {
  if (time> = 1000 * 60 * 5) {
    time = 0;
    rainBool = 0;
    Serial.println ("It is not raining.");
  }
  if (rs.rain (40)) {
    if (rainBool == 0) {
      Serial.println ("It's raining");
      rainBool = 1;
    }
    time = 0;
  } else if (rainBool == 1) {
    time + = delayTime;
  }
  delay (delayTime);
}
````

## Usage

#### Method

````cpp:example.ino
RainSense RainSense (uint8_t pin)
````

    pin: Analog pin number
    Create an instance

````cpp:example.ino
value (byte samples=1, byte sensitivity=16)
````

    Returns the sensor value in bytes. Sensor values ​​range from 0 to 100. A higher value indicates a stronger response. It is recommended that you set a value of 40 or more because noise below 30 is affected by noise.

````cpp:example.ino
rain (byte threshold, byte samples=1, byte sensitivity=16)
````

Compares the value of the sensor with the threshold and returns the result as a boolean. The main specifications are the same as value. Returns 1 if the sensor value is above the threshold.

## License

MIT
