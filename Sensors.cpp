#include "Sensors.h"
#include <Arduino.h>

void Sensors::init() {
  pinMode(trigOnePin, OUTPUT);
  pinMode(echoOnePin, INPUT);
  pinMode(trigTwoPin, OUTPUT);
  pinMode(echoTwoPin, INPUT);

    // Make sure triggers start LOW
  digitalWrite(trigOnePin, LOW);
  digitalWrite(trigTwoPin, LOW);
  delay(50); // allow sensors to settle
}

long Sensors::readDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

long Sensors::readOne() { 
  return readDistance(trigOnePin, echoOnePin); 
}
long Sensors::readTwo() {
   return readDistance(trigTwoPin, echoTwoPin); 
}
