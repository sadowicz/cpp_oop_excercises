#include "factory/executor/ElasticCudaCore.h"

factory::executor::ElasticCudaCore::ElasticCudaCore(int gpuId) : gpuId{gpuId} {}

void factory::executor::ElasticCudaCore::execute() {

    std::cout << "factory::executor::ElasticCudaCore{ gpuId: " << gpuId << " }" << std::endl;
}