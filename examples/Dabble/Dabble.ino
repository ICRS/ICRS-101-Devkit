// Must use a pre 3.0.0 version of the ESP32 board manager to use the DabbleESP32 library

// Challenge: implement joystick controls for the robot

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Motor right pins
const int rightPin1 = 4;
const int rightPin2 = 3;

// Motor left pins
const int leftPin1 = 2;
const int leftPin2 = 1;


void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize Dabble with a Bluetooth name (please change this to something unique)
  Dabble.begin("Robot");

  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);
}

void loop() {
  // Process Dabble inputs
  Dabble.processInput();

  // Stop motors by default
  stopMotors();

  // Gamepad directional controls
  if (GamePad.isUpPressed()) {
    moveForward(255);
  } 
  else if (GamePad.isDownPressed()) {
    moveBackward(255);
  } 
  else if (GamePad.isLeftPressed()) {
    turnLeft(255);
  } 
  else if (GamePad.isRightPressed()) {
    turnRight(255);
  }
  else {
    // Joystick controls (extenstion implement yourself)
    float x_axis = GamePad.getXaxisData();
    float y_axis = GamePad.getYaxisData();
  }
}

// Functions to control the motors
void moveForward() {
  Serial.println("Moving Forward");
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
}

void moveBackward() {
  Serial.println("Moving Backward");
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, HIGH);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
}

void turnRight() {
  Serial.println("Turning Right");
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, HIGH);
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
}

void turnLeft() {
  Serial.println("Turning Left");
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, HIGH);
}

void stopMotors() {
  Serial.println("Stopping Motors");
  digitalWrite(right1Pin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
}