#include <QCoreApplication>
#include <QDebug>

#include "utils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Displacement displacement{};
    Speed speed{};
    Acceleration acceleration{};

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));

    displacement.set(10);
    qDebug() << "Displacement set to: " << 10 <<endl;

    displacement.set(11);
    qDebug() << "Displacement set to: " << 11 <<endl
             << "Speed: " << speed.get() << endl;

    displacement.set(13);
    qDebug() << "Displacement set to: " << 13 <<endl
             << "Speed: " << speed.get() << endl
             << "Acceleration: " << acceleration.get() << endl;

    return a.exec();
}
