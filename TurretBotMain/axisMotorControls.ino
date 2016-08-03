int yawAngle = 0;
void turnLeft(){
  yawAngle+=1;
  if(yawAngle>180)
    yawAngle = 180;
  
  yawServo.write(yawAngle);
}
void turnRight(){
 
  yawAngle-=1;
  yawServo.write(yawAngle);
    if(yawAngle<0)
    yawAngle = 0;
  
}
void killYaw(){
}
/*void turnLeft(){
  //yawServo.write(80);
  //delay(20);
  yawServo.write(180);
  //delay(20);
}
void turnRight(){
  //yawServo.write(100);
  //delay(20);
  yawServo.write(0);
  //(20);
}
void killYaw(){
  yawServo.write(90);
}*/
