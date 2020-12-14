#pragma once

#include <iostream>
#include "Core.h"

namespace factory {

    namespace executor {

        class AnisotropicCpuCore : public Core {

        public:
            explicit AnisotropicCpuCore(int threads);
            void execute() override;

        private:
            int threads;
        };
    }
}