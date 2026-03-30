#ifndef UIController_h
#define UIController_h

#include <Arduino.h>

class UIController {
public:
  UIController(uint8_t emsPin = A5, uint8_t ledPin1 = 2, uint8_t ledPin2 = 3);

  void begin();
  void StaticLED(uint8_t mode);
  bool getEMSState();

private:
  uint8_t _emsPin;
  uint8_t _ledPin1;
  uint8_t _ledPin2;
};

#endif