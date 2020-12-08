#include "observer/Speed.h"

float observer::Speed::get() {

    float speed = 0;

    if(hasThirdValue)
        speed = thirdValue - secondValue;
    else if(hasSecondValue)
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

