#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT
public:
    void set(float value);

private:
    float value{};

signals:
    void sendVal(float value);

};

#endif // DISPLACEMENT_H
