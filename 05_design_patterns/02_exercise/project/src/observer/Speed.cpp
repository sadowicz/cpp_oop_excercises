#include "observer/Speed.h"

float observer::Speed::get() const {

    float speed = 0;

    if(hasSecondValue)
        speed = secondValue - firstValue;

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

