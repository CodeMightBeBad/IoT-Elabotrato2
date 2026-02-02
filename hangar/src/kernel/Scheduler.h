#ifndef HANGAR_SCHEDULER_H
#define HANGAR_SCHEDULER_H

#include "Task.h"

#define MAX_TASKS 50

class Scheduler {
    int basePeriod = 0;
    int nTasks = 0;
    Task* tasks[MAX_TASKS] = {};

public:
    void init(int setPeriod);
    virtual bool addTask(Task* task);
    virtual void schedule();

    virtual ~Scheduler() = default;
};

#endif
