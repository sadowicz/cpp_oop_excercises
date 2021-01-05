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
    void test_case1();

};

SpeedTest::SpeedTest()
{

}

SpeedTest::~SpeedTest()
{

}

void SpeedTest::test_case1()
{

}

QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"
