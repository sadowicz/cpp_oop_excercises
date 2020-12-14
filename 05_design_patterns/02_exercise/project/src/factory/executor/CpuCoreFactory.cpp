#include "factory/executor/CpuCoreFactory.h"

factory::executor::CpuCoreFactory::CpuCoreFactory(int threads) : threads{ threads } {}

std::shared_ptr<factory::executor::Core> factory::executor::CpuCoreFactory::create(std::string equation) {

    if(equation == "anisotropic")
        return std::make_shared<AnisotropicCpuCore>( threads );

    if(equation == "elastic")
        return std::make_shared<ElasticCpuCore>( threads );

    if(equation == "acoustic")
        return std::make_shared<AcousticCpuCore>( threads );

    throw std::runtime_error{ "Unsupported Cpu core equation: " + equation };
}