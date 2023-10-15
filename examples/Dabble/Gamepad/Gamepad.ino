#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <ICRS_101.h>

void setup() {
  Serial.begin(115200);
  Dabble.begin("MyEsp32");

  pinMode(MOTOR1_EN, OUTPUT);
  pinMode(MOTOR2_EN, OUTPUT);
  pinMode(MOTOR1_DIR, OUTPUT);
  pinMode(MOTOR2_DIR, OUTPUT);
}

const float invRoot2 = sqrt(2) / 2;

void loop() {
  Dabble.processInput();             

  if (GamePad.isUpPressed())
  {
    digitalWrite(MOTOR1_DIR, HIGH);
    digitalWrite(MOTOR2_DIR, HIGH);
    analogWrite(MOTOR1_EN, 255); 
    analogWrite(MOTOR2_EN, 255); 
  }
  else if (GamePad.isDownPressed())
  {
    digitalWrite(MOTOR1_DIR, LOW);
    digitalWrite(MOTOR2_DIR, LOW);
    analogWrite(MOTOR1_EN, 255); 
    analogWrite(MOTOR2_EN, 255);
  }
  else if (GamePad.isLeftPressed())
  {
    digitalWrite(MOTOR1_DIR, HIGH);
    digitalWrite(MOTOR2_DIR, LOW);
    analogWrite(MOTOR1_EN, 255); 
    analogWrite(MOTOR2_EN, 255);
  }
  else if (GamePad.isRightPressed())
  {    
    digitalWrite(MOTOR1_DIR, LOW);
    digitalWrite(MOTOR2_DIR, HIGH);

    analogWrite(MOTOR1_EN, 255); 
    analogWrite(MOTOR2_EN, 255);
  }
  else 
  {
    int angle = GamePad.getAngle();
    int power = GamePad.getRadius();

    int left = 0;
    int right = 0;

    if (power != 0)
    {
      float r = (angle + 315) % 360 - 180;
      right = floor((abs(r) - 90)/ 90 * 255 * power / 7);   
      
      float l = (angle + 45) % 360 - 180;
      left = - floor((abs(l) - 90)/ 90 * 255 * power / 7);   
    }
    
    analogWriteMotors(MOTOR1_EN, left); 
    analogWriteMotors(MOTOR2_EN, right);
  }

}

void analogWriteMotors(int motor_pin, int value) 
{
  if(motor_pin != MOTOR1_EN && motor_pin != MOTOR2_EN)
  {
    return;
  }

  analogWrite(motor_pin, abs(value)); 
  bool direction = value >= 0;
  switch(motor_pin)
  {
    case MOTOR1_EN:
      digitalWrite(MOTOR1_DIR, direction);
      break;
    case MOTOR2_EN:
      digitalWrite(MOTOR2_DIR, direction);
      break;
  }

}