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
    void test_case1();

};

AccelerationTest::AccelerationTest()
{

}

AccelerationTest::~AccelerationTest()
{

}

void AccelerationTest::test_case1()
{

}

QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
