#pragma once

#include <iostream>
#include "Core.h"

namespace factory {

    namespace executor {

        class ElasticCpuCore : public Core {

        public:
            explicit ElasticCpuCore(int threads);
            void execute() override;

        private:
            int threads;
        };
    }
}