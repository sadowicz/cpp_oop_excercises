#pragma once

#include "CoreFactory.h"

namespace factory {

    namespace executor {

        class Demo {

        public:
            explicit Demo(std::shared_ptr<CoreFactory> factory);
            void run(std::string equation);

        private:
            std::shared_ptr<CoreFactory> factory;
        };
    }
}