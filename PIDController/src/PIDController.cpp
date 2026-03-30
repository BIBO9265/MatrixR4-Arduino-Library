#include "PIDController.h"

PIDController::PIDController(float _kp, float _ki, float _kd, float _outlim) {
  kp = _kp;
  ki = _ki;
  kd = _kd;
  outlim = _outlim;
  integral = 0.0f;
  prevError = 0.0f;
  time_prev = millis();
}

void PIDController::setPID(float _kp, float _ki, float _kd, float _outlim) {
  kp = _kp;
  ki = _ki;
  kd = _kd;
  outlim = _outlim;
}

void PIDController::initPID() {
  integral = 0.0f;
  prevError = 0.0f;
  time_prev = millis();
}

int PIDController::PIDUpdate(int err) {
  unsigned long now = millis();
  float dt = (now - time_prev) / 1000.0f;

  if (dt <= 0.0f) {
    dt = 0.001f;
  }

  integral = constrain(integral + err * dt, -55, 55);

  float derivative = (err - prevError) / dt;

  float u = kp * err + ki * integral + kd * derivative;

  prevError = err;
  time_prev = now;

  return (int)constrain(u, -outlim, outlim);
}