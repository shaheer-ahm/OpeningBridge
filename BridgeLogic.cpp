#include "BridgeLogic.h"
#include <Arduino.h>

void BridgeLogic::init() {
  pinMode(motorPin, OUTPUT);
  stop(); // Ensure motor is off
}

void BridgeLogic::raise() {
  digitalWrite(motorPin, HIGH); 
  delay(7000);                  // raise duration
  stop();                       
  openState = true;
}

void BridgeLogic::lower() {
    digitalWrite(motorPin, HIGH); 
    delay(7000);                  // lower duration
    stop();
    openState = false;
}

void BridgeLogic::stop() {
  digitalWrite(motorPin, LOW); // Stop motor
}

bool BridgeLogic::isOpen() {
  return openState;
}

void BridgeLogic::setOpen(bool state) {
  openState = state;
}
