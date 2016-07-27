#include <Servo.h>
#define launchMotors 12
#define feedServoPin 11
Servo feedServo;
void setup() {
  setupMotors();
  powerLaunchMotors();
  closeFeed(120); //close feed to prevent projectiles from escaping prematurely
  delay(10000); //wait for the motors to accelerate before engaging the feed servos
}

void loop() {
  feedSingle();
  delay(1000);
}
