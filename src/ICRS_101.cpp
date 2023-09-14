#include "ICRS_101.h"
#include "Arduino.h"
#include "Wire.h"
#include "ICRS_101_Analog.h"

/*  */
uint8_t resolution = 8;

/* Function overwrites */

void digitalWrite(uint8_t pin, uint8_t val) {
  if ((pin >= 64) && (pin <= 76)) {
    Wire.begin();
    Wire.beginTransmission(COPROCESSOR_I2C_ADDR);
    Wire.write(pin);
    Wire.write(0x00 - val);
    Wire.endTransmission(true);
  }

  else {
    gpio_set_level((gpio_num_t)pin, val);
  }
}

void customAnalogWrite(uint8_t pin, int val){
  if ((pin >= 64) && (pin <= 76)){
    Wire.begin();
    Wire.beginTransmission(COPROCESSOR_I2C_ADDR);
    Wire.write(pin);
    Wire.write(val >> (resolution - 8));
    Wire.endTransmission(true);

    Serial.println(val >> (resolution - 8));
  }
  else{
    originalAnalogWrite(pin, val);
  }
}

void customAnalogWriteResolution(uint8_t bits){
  resolution = bits;
  originalAnalogWriteResolution(bits);
}