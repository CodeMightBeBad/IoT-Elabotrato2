#ifndef HANGAR_LED_H
#define HANGAR_LED_H

class Led {
public:
    explicit Led(int pin);

    void switchOn() const;
    void switchOff() const;

private:
    int pin;
};

#endif