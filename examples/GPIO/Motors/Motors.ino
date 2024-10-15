/*  Example to show the motor interface. Spins motors forward for 1 second and stops motors for 1 second. */

#define MOTOR_LEFT_1 35
#define MOTOR_LEFT_2 33
#define MOTOR_RIGHT_1 39
#define MOTOR_RIGHT_2 37

/* The setup function runs once when you press reset or power the board */
void setup() {
  
  /* Set motor pins as outputs */
  pinMode(MOTOR_LEFT_1, OUTPUT);
  pinMode(MOTOR_LEFT_2, OUTPUT);
  pinMode(MOTOR_RIGHT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_2, OUTPUT);

  /* Set motor pins to a known state */
  digitalWrite(MOTOR_LEFT_1, LOW);
  digitalWrite(MOTOR_LEFT_2, LOW);
  digitalWrite(MOTOR_RIGHT_1, LOW);
  digitalWrite(MOTOR_RIGHT_2, LOW);
}

/* The loop function runs repeatedly */
void loop() {

  digitalWrite(MOTOR_LEFT_1, HIGH);
  digitalWrite(MOTOR_RIGHT_1, HIGH);
  delay(1000);

  digitalWrite(MOTOR_LEFT_1, LOW);
  digitalWrite(MOTOR_RIGHT_1, LOW);
  delay(1000);
}
