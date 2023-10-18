#include "ICRS_101.h"

/* LED Fade example: Digital PWM for GPIO Pins  */

void setup() {
  pinMode(D3, OUTPUT);
}

void loop() {
  for(int i = 0; i < 255; i++)
  {  
    analogWrite(D3, i);
    delay(50);
  }

  for(int i = 255; i > 0; i--)
  {  
    analogWrite(D3, i);
    delay(50);
  }
}
