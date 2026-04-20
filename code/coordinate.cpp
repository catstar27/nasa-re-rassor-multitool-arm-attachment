#include "coordinate.h"

bool Coordinate::operator!=(Coordinate other){
  return !(x == other.x && y == other.y && z == other.z);
}

bool Coordinate::operator==(Coordinate other){
  return (x == other.x && y == other.y && z == other.z);
}

Coordinate::Coordinate(){
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Coordinate::Coordinate(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
}