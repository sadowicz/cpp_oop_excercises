#include <observer/Observable.h>

void observer::Observable::registerObserver(Observer *observer) {

    observers.insert(observer);
}

void observer::Observable::unregisterObserver(observer::Observer *observer) {

    observers.erase(observer);
}

void observer::Observable::notifyObservers(float value) {

    for(Observer* observer : observers)
        observer->notify(value);
}

