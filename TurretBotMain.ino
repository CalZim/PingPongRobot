#include <Servo.h>
#define launchMotors 12
#define feedServoPin 11

Servo feedServo;

const int SINGLEMILLIS = 110; //how long will the servo be rotated in milliseconds to drop 1 projectile

void setup() {
  setupMotors();
  powerLaunchMotors();
  closeFeed(); //close feed to prevent projectiles from escaping prematurely
  //delay(10000); //wait for the motors to accelerate before engaging the feed servos
}

void loop() {
  feedAmmo(1);
  delay(1000);
}
