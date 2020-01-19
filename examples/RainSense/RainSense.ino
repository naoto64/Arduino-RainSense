#include <RainSense.h>
#define delayTime 10

RainSense rs = RainSense(A0);
unsigned long time = 0;
int rainBool = 0;

void setup() {
  Serial.begin(9600);
  if(rs.rain(40)){
    Serial.println("It's raining");
    rainBool = 1;
  }else{
    Serial.println("It is not raining.");
  }
}

void loop() {
  if(time >= 1000 * 60 * 5){
    time = 0;
    rainBool = 0;
    Serial.println("It is not raining.");
  }
  if(rs.rain(40)){
    if(rainBool == 0){
      Serial.println("It's raining");
      rainBool = 1;
    }
    time = 0;
  }else if(rainBool == 1){
    time += delayTime;
  }
  delay(delayTime);
}
