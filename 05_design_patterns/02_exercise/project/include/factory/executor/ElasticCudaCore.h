#pragma once

#include <iostream>
#include "Core.h"

namespace factory {

    namespace executor {

        class ElasticCudaCore : public Core {

        public:
            explicit ElasticCudaCore(int gpuId);
            void execute() override;

        private:
            int gpuId;
        };
    }
}