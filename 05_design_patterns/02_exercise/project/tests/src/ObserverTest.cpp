#include <gtest/gtest.h>

#include "observer/Displacement.h"
#include "observer/Speed.h"
#include "observer/Acceleration.h"

TEST(Observer_Displacement, IsCreateable) {

    observer::Displacement displacement;
}

TEST(Observer_Speed, IsCreateable) {

    observer::Speed speed;
}

TEST(Observer_Acceleration, IsCreateable) {

    observer::Acceleration acceleration;
}

TEST(Observer_Displacement, CanRegisterObserver) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);
}

TEST(Observer_Displacement, CanUnregisterObserver) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.unregisterObserver(&speed);
    displacement.unregisterObserver(&acceleration);
}

TEST(Observer_Displacement, CanSetDisplacementValue) {

    observer::Displacement displacement;

    displacement.set(21);
}