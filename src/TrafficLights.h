#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H

#include <Arduino.h>

class TrafficLights {
  public:
    void init();
    void setDefaultState();
    void boatApproaching();
    void boatPasses();
    void resetState();

  private:
    const int carRed = 7;
    const int carYellow = 4;
    const int carGreen = 3;
    const int boatRed = 2;
    const int boatGreen = 8;
};

#endif
