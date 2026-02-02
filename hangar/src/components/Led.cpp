#include <Arduino.h>
#include "Led.h"

Led::Led(const int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Led::switchOn() const {
    digitalWrite(pin, HIGH);
}

void Led::switchOff() const {
    digitalWrite(pin, LOW);
}
