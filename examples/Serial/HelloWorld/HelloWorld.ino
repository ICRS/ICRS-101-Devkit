#include "ICRS_101.h"

/* Program to Print Hello World Once and Hi every second */

/* the setup function runs once when you press reset or power the board */
void setup() {
  // INIT BAUD RATE
  Serial.begin(9600);
  delay(1000);

  Serial.println("Hello World");
}

void loop() {
  Serial.println("Hi!");
  delay(1000);
}
