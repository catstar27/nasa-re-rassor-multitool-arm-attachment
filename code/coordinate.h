#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate{
  public:
    float x = 0;
    float y = 0;
    float z = 0;
    bool operator!=(Coordinate);
    bool operator==(Coordinate);
};
#endif