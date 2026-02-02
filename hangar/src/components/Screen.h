#ifndef HANGAR_SCREEN_H
#define HANGAR_SCREEN_H

#include <Arduino.h>

class Screen {
public:
    explicit  Screen();
    void writeMessage(const String &newMessage);

private:
    void refresh() const;
    String message;
};

#endif