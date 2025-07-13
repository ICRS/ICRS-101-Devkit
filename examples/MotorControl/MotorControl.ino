// Motor A (left) pins
const int leftPin1 = 3;  // MOTORA1
const int leftPin2 = 4;  // MOTORA2

// Motor B (right) pins
const int rightPin1 = 1; // MOTORB1
const int rightPin2 = 2; // MOTORB2

void setup() {
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  moveForward();
  delay(500);
  turnLeft();
  delay(500);
  turnRight();
  delay(500);
  moveBackward();
  delay(500);
  stopMotors();
  delay(5000);
}

// Functions to control the motors
// Functions to control the motors
void moveForward() {
  Serial.println("Moving Forward");
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
}

void moveBackward() {
  Serial.println("Moving Backward");
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, HIGH);
}

void turnRight() {
  Serial.println("Turning Right");
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, HIGH);
}

void turnLeft() {
  Serial.println("Turning Left");
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
}

void stopMotors() {
  Serial.println("Stopping Motors");
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, LOW);
}