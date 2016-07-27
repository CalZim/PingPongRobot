//allows projectiles to be fed into the launching motors
void openFeed(int angle) {
  for (int pos = 0; pos <= angle; pos += 1) {
    feedServo.write(pos);
    delay(2);
  }
}
//blocks projectiles from being fed into the launching motors
void closeFeed(int angle) {
  for (int pos = angle; pos >= 0; pos -= 1) { 
    feedServo.write(pos);
    delay(2);
  }
}

