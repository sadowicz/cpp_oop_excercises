#pragma once

#include <stdexcept>
#include "Observer.h"

namespace observer {

    class Speed : public observer::Observer {

    public:
        float get() const;
        void notify(float value) override;

    private:
        bool hasFirstValue;
        bool hasSecondValue;

        float firstValue;
        float secondValue;
    };
}