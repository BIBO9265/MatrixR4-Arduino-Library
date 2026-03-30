#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <Arduino.h>

class PIDController {
private:
  float kp, ki, kd;
  float integral;
  float prevError;
  float outlim;
  unsigned long time_prev;

public:
  PIDController(float _kp, float _ki, float _kd, float _outlim);
  void setPID(float _kp, float _ki, float _kd, float _outlim);
  void initPID();
  int PIDUpdate(int err);
};

#endif