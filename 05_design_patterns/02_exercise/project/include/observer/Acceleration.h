#pragma once

#include <stdexcept>
#include "Observer.h"

namespace observer {

    class Acceleration : public observer::Observer {

    public:
        float get() const;
        void notify(float value) override;

    private:
        bool hasFirstValue{};
        bool hasSecondValue{};
        bool hasThirdValue{};

        float firstValue{};
        float secondValue{};
        float thirdValue{};
    };
}