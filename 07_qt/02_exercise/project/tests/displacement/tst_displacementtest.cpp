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
    void displacementIsCreateable();
    void canSetDisplacementValue();

};

DisplacementTest::DisplacementTest() {}

DisplacementTest::~DisplacementTest() {}

void DisplacementTest::displacementIsCreateable()
{
    Displacement displacement{};
}

void DisplacementTest::canSetDisplacementValue()
{
    Displacement displacement{};

    displacement.set(11.7);
}

QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"
