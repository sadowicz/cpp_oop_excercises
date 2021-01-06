#include <QtTest>

// add necessary includes here
#include "utils.h"

class SpeedTest : public QObject
{
    Q_OBJECT

public:
    SpeedTest();
    ~SpeedTest();

private slots:
    void speedIsCreateable();
    void getMethodIsUsable();
    void getMethodTrowsExceptionWhenNoSecondValue();
    void getMethodReturnsSpeedWhenTwoValuesNotified();
    void getMethodReturnsSpeedWhenMoreThanTwoValuesNotified();
};

SpeedTest::SpeedTest() {}

SpeedTest::~SpeedTest() {}

void SpeedTest::speedIsCreateable()
{
    Speed speed{};
}

void SpeedTest::getMethodIsUsable()
{
    Displacement displacement{};
    Speed speed{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    displacement.set(12);
    displacement.set(71.1);

    speed.get();
}

void SpeedTest::getMethodTrowsExceptionWhenNoSecondValue()
{
    Displacement displacement{};
    Speed speed{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    QVERIFY_EXCEPTION_THROWN(speed.get(), std::logic_error);

    displacement.set(43.8);

    QVERIFY_EXCEPTION_THROWN(speed.get(), std::logic_error);
}

void SpeedTest::getMethodReturnsSpeedWhenTwoValuesNotified()
{
    Displacement displacement{};
    Speed speed{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    displacement.set(17.9);
    displacement.set(71.1);

    QCOMPARE(speed.get(), 53.2f);
}

void SpeedTest::getMethodReturnsSpeedWhenMoreThanTwoValuesNotified()
{
    Displacement displacement{};
    Speed speed{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    displacement.set(17.9);
    displacement.set(71.1);
    displacement.set(50);

    QCOMPARE(speed.get(), -21.1f);
}

QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"
