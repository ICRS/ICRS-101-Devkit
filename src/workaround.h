#ifndef WORKAROUND_H
#define WORKAROUND_H

#include "Arduino.h"

void originalAnalogWrite(uint8_t pin, int val);
void originalAnalogWriteResolution(uint8_t bits);

#endif