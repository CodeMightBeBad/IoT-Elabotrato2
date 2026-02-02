#ifndef HANGAR_TASK_H
#define HANGAR_TASK_H

class Task {
    int myPeriod = 0;
    int timeElapsed = 0;

public:
    /* Task object destructor */
    virtual ~Task() = default;

    virtual void init(const int period) {
        myPeriod = period;
        timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool update(const int basePeriod) {
        timeElapsed += basePeriod;

        if (timeElapsed >= myPeriod) {
            timeElapsed = 0;
            return true;
        }

        return false;
    }
};

#endif
