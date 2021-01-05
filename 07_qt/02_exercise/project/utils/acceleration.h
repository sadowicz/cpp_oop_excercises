#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration
{
    Q_OBJECT
public:
    float get();

private:
        bool hasFirstValue{};
        bool hasSecondValue{};
        bool hasThirdValue{};

        float firstValue{};
        float secondValue{};
        float thirdValue{};
};

#endif // ACCELERATION_H
