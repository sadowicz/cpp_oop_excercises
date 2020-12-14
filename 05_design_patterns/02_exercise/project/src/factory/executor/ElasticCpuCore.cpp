#include "factory/executor/ElasticCpuCore.h"

factory::executor::ElasticCpuCore::ElasticCpuCore(int threads) : threads{threads} {}

void factory::executor::ElasticCpuCore::execute() {

    std::cout << "factory::executor::ElasticCpuCore{ threads: " << threads << " }" << std::endl;
}