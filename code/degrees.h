#ifndef DEGREES_H
#define DEGREES_H

class Degrees{
  /*
  Basic class with a list of degrees for each motor other than the tool motor; primarily for IK use
  */
  public:
    double swivel_degree = 0.0;
    double shoulder_degree = 0.0;
    double elbow_degree = 0.0;
    double wrist_degree = 0.0;
};
#endif