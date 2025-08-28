#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class Sensors {
    public:
    void init();
    long readOne();
    long readTwo();

  private:
    const int trigOnePin = 5;
    const int echoOnePin = 6;
    const int trigTwoPin = // TODO;
    const int echoTwoPin = // TODO ;
    long readDistance(int trig, int echo);
};

#endif
