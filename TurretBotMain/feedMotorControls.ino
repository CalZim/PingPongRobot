//allows projectiles to be fed into the launching motors

//continues servos are written like  so:
// 90 = off
// smaller than 90 = reverse
// greater than 90 = forward
// 
void openFeed() {
  feedServo.write(180);
}
//blocks projectiles from being fed into the launching motors
void closeFeed() {
  feedServo.write(85); //should be reverse, but is more like a breaking system so that balls don't leave whilst closed
}
