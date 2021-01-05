#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    float get();

private:
    bool hasFirstValue{};
    bool hasSecondValue{};
    float firstValue{};
    float secondValue{};

signals:
public slots:

    void notify(float value);
};

#endif // SPEED_H
