/* This is the test program uploaded to the ICRS 101 Devkit by default. */

#include "ICRS_101.h"

void setup() {
  pinMode(D2, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLDOWN);
  pinMode(D6, INPUT_PULLDOWN);
  pinMode(D7, INPUT_PULLDOWN);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  digitalWrite(MOTOR1_DIR, LOW);
  digitalWrite(MOTOR2_DIR, LOW);

  digitalWrite(MOTOR1_EN, LOW);
  digitalWrite(MOTOR1_EN, LOW);
}

void loop() {
  if ((digitalRead(D2) == LOW) || (digitalRead(D7) == HIGH)) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(MOTOR1_EN, HIGH);
    digitalWrite(MOTOR2_EN, HIGH);
  } else if (digitalRead(D6) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(MOTOR1_EN, LOW);
    digitalWrite(MOTOR2_EN, HIGH);
  } else if (digitalRead(D5) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(MOTOR1_EN, HIGH);
    digitalWrite(MOTOR2_EN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(MOTOR1_EN, LOW);
    digitalWrite(MOTOR2_EN, LOW);
  }
  delay(100);
}