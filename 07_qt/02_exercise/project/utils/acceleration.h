#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
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

signals:
public slots:

    void notify(float value);
};

#endif // ACCELERATION_H
