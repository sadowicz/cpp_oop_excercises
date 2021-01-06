#include <QtTest>

// add necessary includes here
#include "utils.h"

class AccelerationTest : public QObject
{
    Q_OBJECT

public:
    AccelerationTest();
    ~AccelerationTest();

private slots:
    void accelerationIsCreateable();
    void getMethodIsUsable();
    void getMethodTrowsExceptionWhenNoThirdValue();
    void getMethodReturnsAccelerationWhenThreeValuesNotified();
    void getMethodReturnsAccelerationWhenMoreThanThreeValuesNotified();

};

AccelerationTest::AccelerationTest() {}

AccelerationTest::~AccelerationTest() {}

void AccelerationTest::accelerationIsCreateable()
{
    Acceleration acceleration{};
}

void AccelerationTest::getMethodIsUsable()
{
    Displacement displacement{};
    Acceleration acceleration{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));

    displacement.set(12);
    displacement.set(14.5);
    displacement.set(16);

    acceleration.get();
}

void AccelerationTest::getMethodTrowsExceptionWhenNoThirdValue()
{
    Displacement displacement{};
    Acceleration acceleration{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));

    QVERIFY_EXCEPTION_THROWN(acceleration.get(), std::logic_error);

    displacement.set(23.4);

    QVERIFY_EXCEPTION_THROWN(acceleration.get(), std::logic_error);

    displacement.set(34.7);

    QVERIFY_EXCEPTION_THROWN(acceleration.get(), std::logic_error);
}

void AccelerationTest::getMethodReturnsAccelerationWhenThreeValuesNotified()
{
    Displacement displacement{};
    Acceleration acceleration{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));

    displacement.set(21);
    displacement.set(34);
    displacement.set(50.5);

    QCOMPARE(acceleration.get(), 3.5f);
}

void AccelerationTest::getMethodReturnsAccelerationWhenMoreThanThreeValuesNotified()
{
    Displacement displacement{};
    Acceleration acceleration{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));

    displacement.set(8.5);
    displacement.set(10);
    displacement.set(5.5);
    displacement.set(4.4);

    QCOMPARE(acceleration.get(), 3.4f);
}


QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
