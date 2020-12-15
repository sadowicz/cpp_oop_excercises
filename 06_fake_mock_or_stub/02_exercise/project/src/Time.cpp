#include "Time.h"

#include <chrono>
#include <thread>

void Time::create(bool endless) {
    Time::endless = endless;
    year = 0;
}

long long Time::now() const {
    return year;
}

void Time::flow() {
    std::this_thread::sleep_for(std::chrono::hours(365*24));
    ++year;
}
