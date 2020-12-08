#pragma once

#include <set>
#include "observer/Observer.h"

namespace observer {

    class Observable {

    public:
        void registerObserver(Observer* observer);
        void unregisterObserver(Observer* observer);

    protected:
        void notifyObservers(float value);

    private:
        std::set<Observer*> observers;
    };
}