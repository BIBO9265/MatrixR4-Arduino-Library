#ifndef ACCCONTROLLER_H
#define ACCCONTROLLER_H

#include <Arduino.h>

class ACCController {
private:
  int k;
  int h;
  float a;
  int vmax;
  int vmin;
  int acc_dist;
  int dist;

public:
  ACCController();
  void setACC(int maxSpeed, int minSpeed, int accelDistance, int totalDistance);
  int accUpdate(int x, int mode);
};

#endif