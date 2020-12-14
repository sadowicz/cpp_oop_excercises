#pragma once

#include "CoreFactory.h"

#include "AnisotropicCudaCore.h"
#include "ElasticCudaCore.h"
#include "AcousticCudaCore.h"

namespace factory {

    namespace executor {

        class CudaCoreFactory : public CoreFactory {

        public:
            explicit CudaCoreFactory(int gpuId);
            std::shared_ptr<Core> create(std::string equation) override;

        private:
            int gpuId;
        };
    }
}