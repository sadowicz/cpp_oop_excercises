#include "observer/Acceleration.h"

float observer::Acceleration::get() const {

    float acceleration = 0;

    if(hasThirdValue)
        acceleration = (thirdValue - secondValue) - (secondValue - firstValue);

    return acceleration;
}

void observer::Acceleration::notify(float value) {

    if(!hasFirstValue) {

        firstValue = value;
        hasFirstValue = true;
    }
    else if(!hasSecondValue) {

        secondValue = value;
        hasSecondValue = true;
    }
    else if(!hasThirdValue) {

        thirdValue = value;
        hasThirdValue = true;
    }
    else {

        firstValue = secondValue;
        secondValue = thirdValue;
        thirdValue = value;
    }
}

