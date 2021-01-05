#include "displacement.h"

void Displacement::set(float value)
{
    this->value = value;
    emit sendVal(this->value);
}
