#include "ICRS_101.h"

/**
  Example to show the motor interface. Spins motors forward for 1 second and stops motors for 1 second.
*/

void setup() {
  // put your setup code here, to run once:
  digitalWrite(MOTOR1_DIR, LOW);
  digitalWrite(MOTOR2_DIR, LOW);

  digitalWrite(MOTOR1_EN, LOW);
  digitalWrite(MOTOR2_EN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR1_EN, HIGH);
  digitalWrite(MOTOR2_EN, HIGH);
  delay(1000);
  digitalWrite(MOTOR1_EN, LOW);
  digitalWrite(MOTOR2_EN, LOW);
  delay(1000);

}
