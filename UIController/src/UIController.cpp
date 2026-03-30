#include "UIController.h"

UIController::UIController(uint8_t emsPin, uint8_t ledPin1, uint8_t ledPin2) {
  _emsPin = emsPin;
  _ledPin1 = ledPin1;
  _ledPin2 = ledPin2;
}

void UIController::begin() {
  pinMode(_emsPin, INPUT_PULLUP);
  pinMode(_ledPin1, OUTPUT);
  pinMode(_ledPin2, OUTPUT);
}

void UIController::StaticLED(uint8_t mode) {
  switch (mode) {
    case 0:
      digitalWrite(_ledPin1, LOW);
      digitalWrite(_ledPin2, LOW);
      break;

    case 1:   // R
      digitalWrite(_ledPin1, HIGH);
      digitalWrite(_ledPin2, LOW);
      break;

    case 2:   // G
      digitalWrite(_ledPin1, LOW);
      digitalWrite(_ledPin2, HIGH);
      break;

    case 3:   // Y
      digitalWrite(_ledPin1, HIGH);
      digitalWrite(_ledPin2, HIGH);
      break;

    default:
      digitalWrite(_ledPin1, LOW);
      digitalWrite(_ledPin2, LOW);
      break;
  }
}

bool UIController::getEMSState() {
  return digitalRead(_emsPin);
}