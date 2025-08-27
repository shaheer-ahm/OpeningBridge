#include "BridgeLogic.h"
#include "TrafficLights.h"
#include "Sensors.h"

BridgeLogic bridge;
TrafficLights lights;
Sensors sensor;

void setup() {
  Serial.begin(9600);
  bridge.init();
  lights.init();
  sensor.init();

  lights.setDefaultState(); // Cars green, boats red
}

void loop() {
  long distOne = sensor.readOne();
  long distTwo = sensor.readTwo();

  // Only trigger if bridge is not already open
  if (!bridge.isOpen() && ( (distOne > 0 && distOne <= 10) || (distTwo > 0 && distTwo <= 10) )) {
    bridge.setOpen(true);

    lights.boatApproaching();
    bridge.raise();
    lights.boatPasses();
    bridge.lower();
    lights.resetState();

    bridge.setOpen(false);
  } else {
    lights.setDefaultState();
  }

  delay(200);
}