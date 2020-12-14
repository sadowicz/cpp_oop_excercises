#include "factory/executor/AnisotropicCudaCore.h"

factory::executor::AnisotropicCudaCore::AnisotropicCudaCore(int gpuId) : gpuId{gpuId} {}

void factory::executor::AnisotropicCudaCore::execute() {

    std::cout << "factory::executor::AnisotropicCudaCore{ gpuId: " << gpuId << " }" << std::endl;
}