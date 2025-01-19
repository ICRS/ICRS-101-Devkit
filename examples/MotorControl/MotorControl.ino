/* 
do yourself
get motors moving so it moves: 
forward for 0.5s
backwards for 0.5s
stop for 0.5s
repeat
*/

// Motor right pins
const int rightPin1 = 5;
const int rightPin2 = 6;

// Motor left pins
const int leftPin1 = 7;
const int leftPin2 = 8;


void setup() {
  //TODO: Set motor control pins as outputs
  pinMode(right1Pin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  moveForward()
  delay(500)
  moveBackward()
  delay(500)
  stopMotors()
  delay(500)
}

// Functions to control the motors
void moveForward() {
  Serial.println("Moving Forward");
  // TODO: Set motor control pins to move the robot forward
}

void moveBackward() {
  Serial.println("Moving Backward");
  // TODO: Set motor control pins to move the robot backward
}

void stopMotors() {
  Serial.println("Stopping Motors");
  digitalWrite(right1Pin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
}