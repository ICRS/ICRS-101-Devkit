/* Program to print Hello World once and Hi every second */

/* the setup function runs once when you press reset or power the board */
void setup() {
  
  /* Initialise the baud rate */
  Serial.begin(9600);
  delay(1000);

  Serial.println("Hello World");
}

void loop() {
  Serial.println("Hi!");
  delay(1000);
}
