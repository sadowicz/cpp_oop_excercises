#include <QtTest>

// add necessary includes here
#include "utils.h"

class DisplacementTest : public QObject
{
    Q_OBJECT

public:
    DisplacementTest();
    ~DisplacementTest();

private slots:
    void test_case1();

};

DisplacementTest::DisplacementTest()
{

}

DisplacementTest::~DisplacementTest()
{

}

void DisplacementTest::test_case1()
{

}

QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"
