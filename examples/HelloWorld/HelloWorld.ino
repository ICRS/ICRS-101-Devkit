/* Program to print Hello World once and Hi every second */

/* the setup function runs once when you press reset or power the board */
void setup() {
  
  /* initialise the baud rate */
  Serial.begin(115200);

  // waits for 1000 milliseconds
  delay(1000);

  Serial.println("Hello World");
}

/* this function repeats on loop*/
void loop() {
  Serial.println("Hi!");
  delay(1000);
}
