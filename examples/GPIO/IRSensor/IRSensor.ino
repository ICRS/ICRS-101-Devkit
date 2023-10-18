#include "ICRS_101.h"

/**
  Example code for showing how an IR Sensor Can be used (digital input)
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D2, INPUT_PULLDOWN);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D7) == LOW)
  {
    Serial.println("IR sensor detected obstacle!");
  }

  delay(100);
}
