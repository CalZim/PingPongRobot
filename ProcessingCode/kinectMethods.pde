void drawLimb(int userId, int jointType1, int jointType2)
{
  PVector jointPos1 = new PVector();
  PVector jointPos2 = new PVector();
  float  confidence;

  // draw the joint position
  confidence = context.getJointPositionSkeleton(userId, jointType1, jointPos1);
  confidence = context.getJointPositionSkeleton(userId, jointType2, jointPos2);

  stroke(255, 0, 0, confidence * 200 + 55);
  line(jointPos1.x, jointPos1.y, jointPos1.z, 
  jointPos2.x, jointPos2.y, jointPos2.z);

  drawJointOrientation(userId, jointType1, jointPos1, 50);
}
void drawJointOrientation(int userId, int jointType, PVector pos, float length)
{
  // draw the joint orientation  
  PMatrix3D  orientation = new PMatrix3D();
  float confidence = context.getJointOrientationSkeleton(userId, jointType, orientation);
  if (confidence < 0.001f) 
    // nothing to draw, orientation data is useless
    return;

  pushMatrix();
  translate(pos.x, pos.y, pos.z);

  // set the local coordsys
  applyMatrix(orientation);

  // coordsys lines are 100mm long
  // x - r
  stroke(255, 0, 0, confidence * 200 + 55);
  line(0, 0, 0, 
  length, 0, 0);
  // y - g
  stroke(0, 255, 0, confidence * 200 + 55);
  line(0, 0, 0, 
  0, length, 0);
  // z - b    
  stroke(0, 0, 255, confidence * 200 + 55);
  line(0, 0, 0, 
  0, 0, length);
  popMatrix();
}
void getBodyDirection(int userId, PVector centerPoint, PVector dir)
{
  PVector jointL = new PVector();
  PVector jointH = new PVector();
  PVector jointR = new PVector();
  float  confidence;

  // draw the joint position
  confidence = context.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_LEFT_SHOULDER, jointL);
  confidence = context.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_HEAD, jointH);
  confidence = context.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_RIGHT_SHOULDER, jointR);

  // take the neck as the center point
  confidence = context.getJointPositionSkeleton(userId, SimpleOpenNI.SKEL_NECK, centerPoint);

  /*  // manually calc the centerPoint
   PVector shoulderDist = PVector.sub(jointL,jointR);
   centerPoint.set(PVector.mult(shoulderDist,.5));
   centerPoint.add(jointR);
   */

  PVector up = PVector.sub(jointH, centerPoint);
  PVector left = PVector.sub(jointR, centerPoint);

  dir.set(up.cross(left));
  dir.normalize();
}
