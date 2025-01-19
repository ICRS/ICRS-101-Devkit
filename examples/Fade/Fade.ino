/* LED Fade example: Digital PWM for GPIO Pins */
#define BUILTIN_LED 8

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Moving Forward");
  for (int i = 0; i < 255; i++) {  
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }

  for (int i = 255; i > 0; i--) {  
    analogWrite(BUILTIN_LED, i);
    delay(5);
  }
}
