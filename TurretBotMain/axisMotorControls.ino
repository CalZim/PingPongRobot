void turnLeft(){
  yawServo.write(180);
}
void turnRight(){
  yawServo.write(0);
}
void killYaw(){
  yawServo.write(90);
}

