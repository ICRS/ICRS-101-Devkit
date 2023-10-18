#include "ICRS_101.h"

/* Program to print Button Status and turns on led if button pressed */

/* the setup function runs once when you press reset or power the board */
void setup() {
  // INIT BAUD RATE
  Serial.begin(9600);
  pinMode(D2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  bool status = digitalRead(D2) == LOW;
  if( status )
  {
    Serial.println("Button has been pressed!");
  } else
  {
    Serial.println("Button released.");
  }

  digitalWrite(LED_BUILTIN, status);
  delay(10);
}
