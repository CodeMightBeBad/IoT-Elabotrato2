#include "Screen.h"
#include <LiquidCrystal_I2C.h>

#define ADDR 0X27
#define COLS 20
#define ROWS 4

LiquidCrystal_I2C lcd(ADDR, COLS, ROWS);

Screen::Screen() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(1, 1);
}

void Screen::writeMessage(const String &newMessage) {
    this->message = newMessage;
    this->refresh();
}

void Screen::refresh() const {
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print(message);
    lcd.flush();
}
