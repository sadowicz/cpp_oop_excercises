#pragma once

#include <iostream>
#include "Core.h"

namespace factory {

    namespace executor {

        class AcousticCudaCore : public Core {

        public:
            explicit AcousticCudaCore(int gpuId);
            void execute() override;

        private:
            int gpuId;
        };
    }
}