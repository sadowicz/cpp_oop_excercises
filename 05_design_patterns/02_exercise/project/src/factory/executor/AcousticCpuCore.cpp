#include "factory/executor/AcousticCpuCore.h"

factory::executor::AcousticCpuCore::AcousticCpuCore(int threads) : threads{threads} {}

void factory::executor::AcousticCpuCore::execute() {

    std::cout << "factory::executor::AcousticCpuCore{ threads: " << threads << " }" << std::endl;
}