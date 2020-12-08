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

TEST(Observer_Speed, GetIsUsable) {

    observer::Displacement displacement;
    observer::Speed speed;

    displacement.registerObserver(&speed);
    displacement.set(1);
    displacement.set(2);

    speed.get();
}

TEST(Observer_Speed, GetThrowsExceptionWhenNoSecondValue) {

    observer::Displacement displacement;
    observer::Speed speed;

    displacement.registerObserver(&speed);

    EXPECT_THROW(speed.get(), std::logic_error);

    displacement.set(1);

    EXPECT_THROW(speed.get(), std::logic_error);
}

TEST(Observer_Speed, NotifiesNoValuesWhenNotRegistered) {

    observer::Displacement displacement;
    observer::Speed speed;

    displacement.set(1);
    displacement.set(2);

    EXPECT_THROW(speed.get(), std::logic_error);
}

TEST(Observer_Speed, GetReturnsSpeedWhenTwoValuesNotified) {

    observer::Displacement displacement;
    observer::Speed speed;

    displacement.registerObserver(&speed);

    displacement.set(1);
    displacement.set(3);

    EXPECT_EQ(2, speed.get());
}

TEST(Observer_Speed, GetReturnsSpeedWhenMoreThanTwoValuesNotified) {

    observer::Displacement displacement;
    observer::Speed speed;

    displacement.registerObserver(&speed);

    displacement.set(1);
    displacement.set(3);
    displacement.set(4);

    EXPECT_EQ(1, speed.get());
}

TEST(Observer_Acceleration, GetIsUsable) {

    observer::Displacement displacement;
    observer::Acceleration acceleration;

    displacement.registerObserver(&acceleration);
    displacement.set(1);
    displacement.set(2);
    displacement.set(3);

    acceleration.get();
}

TEST(Observer_Acceleration, GetThrowsExceptionWhenNoThirdValue) {

    observer::Displacement displacement;
    observer::Acceleration acceleration;

    displacement.registerObserver(&acceleration);

    EXPECT_THROW(acceleration.get(), std::logic_error);

    displacement.set(1);

    EXPECT_THROW(acceleration.get(), std::logic_error);

    displacement.set(2);

    EXPECT_THROW(acceleration.get(), std::logic_error);
}

TEST(Observer_Acceleration, NotifiesNoValuesWhenNotRegistered) {

    observer::Displacement displacement;
    observer::Acceleration acceleration;

    displacement.set(1);
    displacement.set(2);
    displacement.set(3);

    EXPECT_THROW(acceleration.get(), std::logic_error);
}

TEST(Observer_Acceleration, GetReturnsAccelerationWhenThreeValuesNotified) {

    observer::Displacement displacement;
    observer::Acceleration acceleration;

    displacement.registerObserver(&acceleration);

    displacement.set(1);
    displacement.set(2);
    displacement.set(5);

    EXPECT_EQ(2, acceleration.get());
}

TEST(Observer_Acceleration, GetReturnsAccelerationWhenMoreThanThreeValuesNotified) {

    observer::Displacement displacement;
    observer::Acceleration acceleration;

    displacement.registerObserver(&acceleration);

    displacement.set(1);
    displacement.set(3);
    displacement.set(4);
    displacement.set(8);

    EXPECT_EQ(3, acceleration.get());
}