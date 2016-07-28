//sets up motors
void setupMotors(){
  pinMode(launchMotors, OUTPUT);
  feedServo.attach(feedServoPin);
}

//Turns on launching motors
void powerLaunchMotors(){
  digitalWrite(launchMotors, HIGH);
}


//feeds x projectiles to the launch motors
void feedAmmo(int ammount){
  //should turn a bit less than 90 degrees at ammount = 1
  openFeed();
  delay(SINGLEMILLIS*ammount);
  closeFeed();
}


