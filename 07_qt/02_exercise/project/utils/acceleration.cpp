#include "acceleration.h"

float Acceleration::get()
{
    float acceleration;

    if(hasThirdValue)
        acceleration = (thirdValue - secondValue) - (secondValue - firstValue);
    else
        throw std::logic_error{ "Acceleration::get : Not enough values too calculate acceleration" };

    return acceleration;
}

void Acceleration::notify(float value)
{
    if(!hasFirstValue)
    {

        firstValue = value;
        hasFirstValue = true;
    }
    else if(!hasSecondValue)
    {

        secondValue = value;
        hasSecondValue = true;
    }
    else if(!hasThirdValue)
    {

        thirdValue = value;
        hasThirdValue = true;
    }
    else
    {

        firstValue = secondValue;
        secondValue = thirdValue;
        thirdValue = value;
    }
}
