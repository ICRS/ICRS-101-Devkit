/* LED Fade example: Digital PWM for GPIO Pins */

#define BUILTIN_LED 8 // only necessary with the esp32 c3 super mini we are using

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  // repeats for all values of i from 0 to 255
  for (int i = 0; i < 255; i++) {
    // uses PWM to fade the LED depending on the value of i
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }

  // repeats for all values of i from 255 to 0
  for (int i = 255; i > 0; i--) {  
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }
}
