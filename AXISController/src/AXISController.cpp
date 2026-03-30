#include "AXISController.h"

AXISController::AXISController() {
}

void AXISController::begin() {
  MiniR4.begin();
  MiniR4.PWR.setBattCell(2);
  MiniR4.MXMotorCtrl.begin(true, false, false, false);
  MiniR4.MXMotorCtrl.MC1.M3.setReverse(false);
  MiniR4.MXMotorCtrl.MC1.M3.setPPR(360);
  pinMode(A3, INPUT);
  pinMode(A1, INPUT);
  reset();
}

void AXISController::EMSoff() {
  if (EMS.getEMSState()) {
    MiniR4.MXMotorCtrl.loop();
    MiniR4.RC1.setAngle(90);
    EMS.StaticLED(1);
    while (true) {
      delay(1000);
    }
  }
}

void AXISController::reset() {
  MiniR4.MXMotorCtrl.loop();
  MiniR4.MXMotorCtrl.MC1.M3.resetCounter();
  MiniR4.MXMotorCtrl.MC1.M3.setBrake(true);
}

void AXISController::AxisYdist(int speed, int dist) {
  while ((abs(MiniR4.MXMotorCtrl.MC1.M3.getDegreesFast()) < abs(dist) || speed > 0) && (!digitalRead(A3) || speed < 0) && abs(MiniR4.MXMotorCtrl.MC1.M3.getDegreesFast()) < 2250) {
    EMSoff();
    MiniR4.MXMotorCtrl.loop();
    MiniR4.MXMotorCtrl.MC1.M3.setPower(speed);
  }

  if (digitalRead(A3)) {
    reset();
  }

  MiniR4.MXMotorCtrl.loop();
  MiniR4.MXMotorCtrl.MC1.M3.setBrake(true);
  MiniR4.MXMotorCtrl.MC1.M3.setPower(0);
}

void AXISController::AxisYTouch(int speed) {
  while (!digitalRead(A3) && abs(MiniR4.MXMotorCtrl.MC1.M3.getDegreesFast()) < 2250) {
    EMSoff();
    MiniR4.MXMotorCtrl.loop();
    MiniR4.MXMotorCtrl.MC1.M3.setPower(abs(speed));
  }

  reset();

  MiniR4.MXMotorCtrl.loop();
  MiniR4.MXMotorCtrl.MC1.M3.setBrake(true);
  MiniR4.MXMotorCtrl.MC1.M3.setPower(0);
}

void AXISController::AxisXTouch() {
  while (!digitalRead(A1)) {
    EMSoff();
    MiniR4.RC1.setAngle(75);
  }
  MiniR4.RC1.setAngle(90);
}

void AXISController::AxisXTime(int speed, int time) {
  speed = map(speed, -100, 100, 180, 0);
  unsigned long time_priv = millis();
  while (millis() - time_priv < (unsigned long)time && (!digitalRead(A1) || speed > 90)) {
    EMSoff();
    MiniR4.RC1.setAngle(speed);
  }
  MiniR4.RC1.setAngle(90);
}

void AXISController::AxisZdist(int angle) {
  MiniR4.RC3.setAngle(angle);
}

void AXISController::AxisCatchdist(int angle) {
  MiniR4.RC2.setAngle(angle);
}