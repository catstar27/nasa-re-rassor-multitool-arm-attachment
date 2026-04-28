#ifndef MAGNET_H
#define MAGNET_H

class Magnet{
  /*
  Class for the magnets of the tool changer
  Has functionality to allow two magnets to change states simultaneously
  */
  private:
    bool on = false;
    int pin = 0;
  public:
    bool is_on(); // Returns true if the magnet is on, false otherwise
    void set_state(bool); // Sets the state of this magnet
    void set_simultaneously(Magnet*, bool); // Sets the state of this magnet and another at the same time
    Magnet(int); // Constructs a magnet with given pin
};
#endif