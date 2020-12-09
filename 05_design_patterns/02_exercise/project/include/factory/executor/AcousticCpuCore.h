#pragma once

#include <iostream>
#include "Core.h"

namespace factory {

    namespace executor {

        class AcousticCpuCore : public Core {

        public:
            explicit AcousticCpuCore(int threads);
            void execute() override;

        private:
            int threads;
        };
    }
}