#include "ACCController.h"

ACCController::ACCController() {
  k = 0;
  h = 0;
  a = 0.0f;
  vmax = 0;
  vmin = 0;
  acc_dist = 0;
  dist = 0;
}

void ACCController::setACC(int maxSpeed, int minSpeed, int accelDistance, int totalDistance) {
  vmax = maxSpeed;
  vmin = minSpeed;
  acc_dist = accelDistance;
  dist = totalDistance;

  k = vmin;

  if (acc_dist <= 0) {
    a = 0.0f;
  } else {
    a = (vmax - vmin) / float(acc_dist * acc_dist);
  }

  h = -dist;
}

int ACCController::accUpdate(int x, int mode) {
  x = abs(x);

  float qf1 = a * x * x + k;
  float qf2 = a * (x + h) * (x + h) + k;

  float v = 0.0f;

  if (mode == 0) {
    v = min(qf1, qf2);
  } else if (mode == 1) {
    v = qf2;
  } else {
    v = qf1;
  }

  return constrain((int)v, vmin, vmax);
}