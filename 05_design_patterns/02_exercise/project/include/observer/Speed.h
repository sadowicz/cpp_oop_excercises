#pragma once

#include "Observer.h"

namespace observer {

    class Speed : public observer::Observer {

    public:
        float get();
        void notify(float value) override;

    private:
        bool hasFirstValue;
        bool hasSecondValue;
        bool hasThirdValue;

        float firstValue;
        float secondValue;
        float thirdValue;

    };
}