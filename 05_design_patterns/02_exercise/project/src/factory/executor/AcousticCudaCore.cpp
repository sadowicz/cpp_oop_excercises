#include "factory/executor/AcousticCudaCore.h"

factory::executor::AcousticCudaCore::AcousticCudaCore(int gpuId) : gpuId{gpuId} {}

void factory::executor::AcousticCudaCore::execute() {

    std::cout << "factory::executor::AcousticCudaCore{ gpuId: " << gpuId << " }" << std::endl;
}