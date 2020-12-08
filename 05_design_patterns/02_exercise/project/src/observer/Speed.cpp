#include "observer/Speed.h"

float observer::Speed::get() const {

    float speed;

    if(hasSecondValue)
        speed = secondValue - firstValue;
    else
        throw std::logic_error{ "Acceleration::get : Not enough values too calculate acceleration" };

    return speed;
}

void observer::Speed::notify(float value) {

    if(!hasFirstValue) {

        firstValue = value;
        hasFirstValue = true;
    }
    else if(!hasSecondValue) {

        secondValue = value;
        hasSecondValue = true;
    }
    else {

        firstValue = secondValue;
        secondValue = value;
    }
}

