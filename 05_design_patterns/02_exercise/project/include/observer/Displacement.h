#pragma once

#include "Observable.h"

namespace observer {

    class Displacement : public observer::Observable {

    public:
        void set(float value);

    private:
        float value;
    };
}