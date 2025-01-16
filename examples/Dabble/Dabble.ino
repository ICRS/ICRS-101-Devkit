// Must use a pre 3.0.0 version of the ESP32 board manager to use the DabbleESP32 library

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Motor pins for L298N
#define MOTOR1_IN1 5 // Direction 1 for Motor 1
#define MOTOR1_IN2 6 // Direction 2 for Motor 1
#define MOTOR2_IN3 7 // Direction 1 for Motor 2
#define MOTOR2_IN4 8 // Direction 2 for Motor 2

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize Dabble with a Bluetooth name (please change this to something unique)
  Dabble.begin("Robot");

  // Set motor pins as output
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
}

void loop() {
  // Process Dabble inputs
  Dabble.processInput();

  // Stop motors by default
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN3, LOW);
  digitalWrite(MOTOR2_IN4, LOW);

  // Gamepad directional controls
  if (GamePad.isUpPressed()) {
    // Move forward
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
  } 
  else if (GamePad.isDownPressed()) {
    // Move backward
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, HIGH);
  } 
  else if (GamePad.isLeftPressed()) {
    // Turn left
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, HIGH);
  } 
  else if (GamePad.isRightPressed()) {
    // Turn right
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
  }

  // Joystick controls (not implemented)
  float x_axis = GamePad.getXaxisData();
  float y_axis = GamePad.getYaxisData();
}
