#ifndef BRIDGELOGIC_H
#define BRIDGELOGIC_H

#include <Arduino.h>

class BridgeLogic {
  public:
    BridgeLogic();
    void init();
    void raise();
    void lower();
    void stop(); 
    bool isOpen();
    void setOpen(bool state);

  private:
    const int motorPin = 9; 
    bool openState = false; // Bridge starts closed
};

#endif
