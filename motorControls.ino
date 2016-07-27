//sets up motors
void setupMotors(){
  pinMode(launchMotors, OUTPUT);
  feedServo.attach(feedServoPin);
}

//Turns on launching motors
void powerLaunchMotors(){
  digitalWrite(launchMotors, HIGH);
}


//feed one projectile to the launch motors
void feedSingle(){
  openFeed(FEEDANGLE);
  closeFeed(FEEDANGLE);
}

//opens the feed servo for the inputed milliseconds
void feedMulti(int millisOpen){
  openFeed(FEEDANGLE);
  delay(millisOpen);
  closeFeed(FEEDANGLE);
}
