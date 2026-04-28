#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
  /*
  Basic coordinate class with support for some operators
  Has a no-arg constructor which initializes to (0,0,0)
  Has a constructor that takes three values for the coordinates
  */
  public:
    double x = 0;
    double y = 0;
    double z = 0;
    bool operator!=(Coordinate);
    bool operator==(Coordinate);
    Coordinate();
    Coordinate(double, double, double);
};
#endif