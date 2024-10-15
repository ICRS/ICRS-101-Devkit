/* LED Fade example: Digital PWM for GPIO Pins */

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) {  
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }

  for (int i = 255; i > 0; i--) {  
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }
}
