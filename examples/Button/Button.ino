/* Program to print button status and turns on LED if button pressed */
#define LED_BUILTIN 8
#define BOOT_BUTTON 9

/* The setup function runs once when you press reset or power the board */
void setup() {
  Serial.begin(115200);
  pinMode(BOOT_BUTTON, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

/* The loop function runs repeatedly */
void loop() {

  if (digitalRead(BOOT_BUTTON) == LOW) {
    Serial.println("Button has been pressed!");
    digitalWrite(LED_BUILTIN, 1);
    delay(10);
  } 
  
  else {
    Serial.println("Button released.");
    digitalWrite(LED_BUILTIN, 0);
    delay(10);
  }
}
