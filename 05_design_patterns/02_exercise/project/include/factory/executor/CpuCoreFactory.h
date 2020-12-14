#pragma once

#include "CoreFactory.h"

#include "AnisotropicCpuCore.h"
#include "ElasticCpuCore.h"
#include "AcousticCpuCore.h"

namespace factory {

    namespace executor {

        class CpuCoreFactory : public CoreFactory {

        public:
            explicit CpuCoreFactory(int threads);
            std::shared_ptr<Core> create(std::string equation) override;

        private:
            int threads;
        };
    }
}