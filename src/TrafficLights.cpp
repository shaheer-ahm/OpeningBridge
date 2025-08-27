#include "TrafficLights.h"
#include <Arduino.h>

void TrafficLights::init() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(boatRed, OUTPUT);
  pinMode(boatGreen, OUTPUT);
}

void TrafficLights::setDefaultState() {
  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, LOW);
  digitalWrite(boatGreen, LOW);
  digitalWrite(boatRed, HIGH);
}

void TrafficLights::boatApproaching() {
  unsigned long flashStart = millis();
  bool state = true;
  unsigned long warningDuration = 5000;

  // Step 1: Flash Boat RED for 5s (warning)
  while (millis() - flashStart < warningDuration) {
    state = !state;
    digitalWrite(boatRed, state);
    delay(250);
  }

  // Step 2: Car GREEN → YELLOW for 2.5s, keep flashing boat red
  flashStart = millis();
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  while (millis() - flashStart < 2500) {
    state = !state;
    digitalWrite(boatRed, state);
    delay(250);
  }

  // Step 3: Car YELLOW → RED, keep flashing boat red for 5s
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  flashStart = millis();
  while (millis() - flashStart < 10000) {
    state = !state;
    digitalWrite(boatRed, state);
    delay(250);
  }

  // Step 4: Boat RED → GREEN (let boat cross)
  digitalWrite(boatRed, LOW);
  digitalWrite(boatGreen, HIGH);
  delay(5000);
}

void TrafficLights::boatPasses() {
  // Warn boats to stop again (flash red for 5s after crossing)
  unsigned long flashStart = millis();
  bool state = true;
  digitalWrite(boatGreen, LOW);

  while (millis() - flashStart < 5000) {
    state = !state;
    digitalWrite(boatRed, state);
    delay(250);
  }
}

void TrafficLights::resetState() {
  digitalWrite(boatGreen, LOW);
  digitalWrite(boatRed, HIGH);
  digitalWrite(carRed, LOW);
  digitalWrite(carGreen, HIGH);

  delay(3000); // optional cooldown
}
