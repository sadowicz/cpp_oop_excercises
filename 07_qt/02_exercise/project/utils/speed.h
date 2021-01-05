#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed
{
    Q_OBJECT
public:
    float get();

private:
    bool hasFirstValue{};
    bool hasSecondValue{};
    float firstValue{};
    float secondValue{};
};

#endif // SPEED_H
