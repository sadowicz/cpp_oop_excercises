#pragma once

#include "TimeImpl.h"
#include "SpaceImpl.h"
#include "ObserverImpl.h"

class Universe {
public:

    Universe(Time &time, Space &space, Observer &observer);

    void create();
    void simulate(long years);

private:
    Time &time;
    Space &space;
    Observer &observer;
};
