#include "observer/Displacement.h"

void observer::Displacement::set(float value) {

    this->value = value;
    notifyObservers(this->value);
}
