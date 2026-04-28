#include "magnet.h"
#include <Arduino.h>

bool Magnet::is_on(){
  return on;
}

void Magnet::set_state(bool new_state){
  digitalWrite(pin, (new_state) ? HIGH:LOW);
}

void Magnet::set_simultaneously(Magnet* other, bool new_state){
  digitalWrite(pin, (new_state) ? HIGH:LOW);
  digitalWrite(other->pin, (new_state) ? HIGH:LOW);
}

Magnet::Magnet(int pin){
  this->pin = pin;
}