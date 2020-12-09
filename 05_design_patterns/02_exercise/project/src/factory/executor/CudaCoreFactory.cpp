#include "factory/executor/CudaCoreFactory.h"

factory::executor::CudaCoreFactory::CudaCoreFactory(int gpuId) : gpuId{ gpuId } {}

std::shared_ptr<factory::executor::Core> factory::executor::CudaCoreFactory::create(std::string equation) {

    if(equation == "anisotropic")
        return std::make_shared<AnisotropicCudaCore>( gpuId );

    if(equation == "elastic")
        return std::make_shared<ElasticCudaCore>( gpuId );

    if(equation == "acoustic")
        return std::make_shared<AcousticCudaCore>( gpuId );

    throw std::runtime_error{ "Unsupported Cuda core equation: " + equation };
}