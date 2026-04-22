#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
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