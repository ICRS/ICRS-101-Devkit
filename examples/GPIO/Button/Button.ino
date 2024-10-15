/* Program to print button status and turns on LED if button pressed */

/* The setup function runs once when you press reset or power the board */
void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

/* The loop function runs repeatedly */
void loop() {

  bool status = digitalRead(0) == LOW;

  if (status) {
    Serial.println("Button has been pressed!");
  } 
  
  else {
    Serial.println("Button released.");
  }

  digitalWrite(LED_BUILTIN, status);
  delay(10);
}
