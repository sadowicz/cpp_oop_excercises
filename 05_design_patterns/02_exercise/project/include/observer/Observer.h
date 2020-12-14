#pragma once

namespace observer {

    class Observer {

    public:
        virtual void notify(float value) = 0;
    };
}