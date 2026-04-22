#include "coordinate.h"

bool Coordinate::operator!=(Coordinate other){
  return !(x == other.x && y == other.y && z == other.z);
}

bool Coordinate::operator==(Coordinate other){
  return (x == other.x && y == other.y && z == other.z);
}