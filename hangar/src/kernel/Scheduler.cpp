#include "Scheduler.h"
#include <TimerOne.h>

volatile bool timerFlag;

void timerHandler() {
    timerFlag = true;
}

void Scheduler::init(const int setPeriod) {
    this->basePeriod = setPeriod;
    timerFlag = false;

    const long period = 10001 * basePeriod;

    Timer1.initialize(period);
    Timer1.attachInterrupt(timerHandler);
    nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
    if (nTasks < MAX_TASKS) {
        tasks[(nTasks - 1)] = task;
        nTasks++;
        return true;
    }

    return false;
}

void Scheduler::schedule() {
    while (!timerFlag) {}

    timerFlag = false;

    for (int i = 0; i < nTasks; i++) {
        if (tasks[i]->update(basePeriod)) {
            tasks[i]->tick();
        }
    }
}
