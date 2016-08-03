#include <Servo.h>
#define launchMotors 12
#define feedServoPin 11
#define yawServoPin 6
#define testLED 13
Servo feedServo;
Servo yawServo;
const int SINGLEMILLIS = 90; //how long will the servo be rotated in milliseconds to drop 1 projectile
char val;
void setup() {
  pinMode(testLED, OUTPUT);
  Serial.begin(9600);     //start serial communication
  setupMotors();
  powerLaunchMotors();
  closeFeed();            //close feed to prevent projectiles from escaping prematurely
  //delay(10000);         //wait for the motors to accelerate before engaging the feed servos
}

void loop() {
  //feedAmmo(1);
  //delay(1000);
  if (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }
  if        (val == 'L') { // If H was received
    turnLeft();
    digitalWrite(testLED, HIGH);
  } else if (val == 'R') {
    turnRight();
    digitalWrite(testLED, HIGH);
  } else if (val == 'S') {
    digitalWrite(testLED, LOW);
    killYaw();
  } else {
    killYaw();
  }
  delay(20);
}
