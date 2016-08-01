#include <Servo.h>
#define launchMotors 12
#define feedServoPin 11
#define yawServoPin 6
Servo feedServo;
Servo yawServo;
const int SINGLEMILLIS = 90; //how long will the servo be rotated in milliseconds to drop 1 projectile

void setup() {
  Serial.begin(9600);     //start serial communication
  setupMotors();
  powerLaunchMotors();
  closeFeed();            //close feed to prevent projectiles from escaping prematurely
  //delay(10000);         //wait for the motors to accelerate before engaging the feed servos
}

void loop() {
  killYaw();
  //feedAmmo(1);
  delay(1000);
}
