#ifndef ICRS_101_H
#define ICRS_101_H

#include "Arduino.h"

/*  */
#define COPROCESSOR_I2C_ADDR 0x12

#define analogWrite customAnalogWrite
#define analogWriteResolution customAnalogWriteResolution

/* Pin definitions */

#define A0 15
static const uint8_t A1 = 27;
static const uint8_t A2 = 26;
#define A3 25
#define A4 33
#define A5 32

static const uint8_t D0 = 3;
static const uint8_t D1 = 1;
static const uint8_t D2 = 0;
static const uint8_t D3 = 23;
static const uint8_t D4 = 19;
static const uint8_t D5 = 18;
static const uint8_t D6 = 5;
static const uint8_t D7 = 17;
static const uint8_t D8 = 16;
static const uint8_t D9 = 4;
static const uint8_t D10 = 14;
static const uint8_t D11 = 12;
static const uint8_t D12 = 2;
static const uint8_t D13 = 13;

static const uint8_t LED_BUILTIN = 64;

static const uint8_t MOTOR1_EN  = 65;
static const uint8_t MOTOR1_DIR = 66;
static const uint8_t MOTOR2_EN  = 67;
static const uint8_t MOTOR2_DIR = 68;

static const uint8_t S0 = 69;
static const uint8_t S1 = 70;
static const uint8_t S2 = 71;
static const uint8_t S3 = 72;
static const uint8_t S4 = 73;
static const uint8_t S5 = 74;
static const uint8_t S6 = 75;
static const uint8_t S7 = 76;

/* Function overwrites */
void digitalWrite(uint8_t pin, uint8_t val);

void customAnalogWrite(uint8_t pin, int val);
void customAnalogWriteResolution(uint8_t bits);

#endif