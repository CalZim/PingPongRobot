//sets up motors
void setupMotors(){
  pinMode(launchMotors, OUTPUT);
  feedServo.attach(feedServoPin);
  yawServo.attach(yawServoPin);
}

//Turns on launching motors
void powerLaunchMotors(){
  digitalWrite(launchMotors, HIGH);
}


//feeds x projectiles to the launch motors
void feedAmmo(int ammount){
  //should turn a tiny bit less than 90 degrees
  openFeed();
  delay(SINGLEMILLIS*ammount);
  closeFeed();
}


