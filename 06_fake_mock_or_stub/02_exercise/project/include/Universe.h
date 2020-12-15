#pragma once

#include "Time.h"
#include "SpaceImpl.h"
#include "Observer.h"

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
