#include "workaround.h"


void originalAnalogWrite(uint8_t pin, int val){
  analogWrite(pin, val);
}

void originalAnalogWriteResolution(uint8_t bits){
  analogWriteResolution(bits);
}